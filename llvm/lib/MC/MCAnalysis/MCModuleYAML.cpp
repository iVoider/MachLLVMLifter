//===- MCModuleYAML.cpp - MCModule YAMLIO implementation ------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines classes for handling the YAML representation of MCModule.
//
//===----------------------------------------------------------------------===//

#include "llvm/MC/MCAnalysis/MCModuleYAML.h"
#include "llvm/ADT/StringMap.h"
#include "llvm/MC/MCAnalysis/MCFunction.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/ObjectYAML/YAML.h"
#include "llvm/Support/Allocator.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/MathExtras.h"
#include "llvm/Support/YAMLTraits.h"
#include <vector>

namespace llvm {

namespace {

// This class is used to map opcode and register names to enum values.
//
// There are at least 3 obvious ways to do this:
// 1- Generate an MII/MRI method using a tablegen StringMatcher
// 2- Write an MII/MRI method using std::lower_bound and the assumption that
//    the enums are sorted (starting at a fixed value).
// 3- Do the matching manually as is done here.
//
// Why 3?
// 1- A StringMatcher function for thousands of entries would incur
//    a non-negligible binary size overhead.
// 2- The lower_bound comparators would be somewhat involved and aren't
//    obviously reusable (see LessRecordRegister in llvm/TableGen/Record.h)
// 3- This isn't actually something useful outside tests (but the same argument
//    can be made against having {MII,MRI}::getName).
//
// If this becomes useful outside this specific situation, feel free to do
// the Right Thing (tm) and move the functionality to MII/MRI.
//
class InstrRegInfoHolder {
  typedef StringMap<unsigned, BumpPtrAllocator> EnumValByNameTy;
  EnumValByNameTy InstEnumValueByName;
  EnumValByNameTy RegEnumValueByName;

public:
  const MCInstrInfo &MII;
  const MCRegisterInfo &MRI;
  InstrRegInfoHolder(const MCInstrInfo &MII, const MCRegisterInfo &MRI)
      : InstEnumValueByName(NextPowerOf2(MII.getNumOpcodes())),
        RegEnumValueByName(NextPowerOf2(MRI.getNumRegs())), MII(MII), MRI(MRI) {
    for (int i = 0, e = MII.getNumOpcodes(); i != e; ++i)
      InstEnumValueByName[MII.getName(i)] = i;
    for (int i = 0, e = MRI.getNumRegs(); i != e; ++i)
      RegEnumValueByName[MRI.getName(i)] = i;
  }

  bool matchRegister(StringRef Name, unsigned &Reg) {
    EnumValByNameTy::const_iterator It = RegEnumValueByName.find(Name);
    if (It == RegEnumValueByName.end())
      return false;
    Reg = It->getValue();
    return true;
  }
  bool matchOpcode(StringRef Name, unsigned &Opc) {
    EnumValByNameTy::const_iterator It = InstEnumValueByName.find(Name);
    if (It == InstEnumValueByName.end())
      return false;
    Opc = It->getValue();
    return true;
  }
};

} // end unnamed namespace

namespace MCModuleYAML {

LLVM_YAML_STRONG_TYPEDEF(unsigned, OpcodeEnum)

struct Operand {
  MCOperand MCOp;
};

struct Inst {
  OpcodeEnum Opcode;
  std::vector<Operand> Operands;
  uint64_t Size;
};

struct BasicBlock {
  yaml::Hex64 Address;
  uint64_t SizeInBytes;
  uint64_t InstCount;

  std::vector<Inst> Insts;
  std::vector<yaml::Hex64> Preds;
  std::vector<yaml::Hex64> Succs;
};

struct Function {
  StringRef Name;
  std::vector<BasicBlock> BasicBlocks;
};

struct Module {
  std::vector<Function> Functions;
};

} // end namespace MCModuleYAML
} // end namespace llvm

LLVM_YAML_DECLARE_MAPPING_TRAITS(llvm::MCModuleYAML::Operand)
LLVM_YAML_IS_FLOW_SEQUENCE_VECTOR(llvm::MCModuleYAML::Operand)
LLVM_YAML_IS_SEQUENCE_VECTOR(llvm::MCModuleYAML::Inst)
LLVM_YAML_IS_SEQUENCE_VECTOR(llvm::MCModuleYAML::BasicBlock)
LLVM_YAML_IS_SEQUENCE_VECTOR(llvm::MCModuleYAML::Function)
LLVM_YAML_DECLARE_MAPPING_TRAITS(llvm::MCModuleYAML::OpcodeEnum)

namespace llvm {

namespace yaml {

template <> struct MappingTraits<MCModuleYAML::Inst> {
  static void mapping(IO &IO, MCModuleYAML::Inst &I);
};

template <> struct MappingTraits<MCModuleYAML::BasicBlock> {
  static void mapping(IO &IO, MCModuleYAML::BasicBlock &BB);
};

template <> struct MappingTraits<MCModuleYAML::Function> {
  static void mapping(IO &IO, MCModuleYAML::Function &Fn);
};

template <> struct MappingTraits<MCModuleYAML::Module> {
  static void mapping(IO &IO, MCModuleYAML::Module &M);
};

template <> struct ScalarTraits<MCModuleYAML::Operand> {
  static void output(const MCModuleYAML::Operand &, void *,
                     llvm::raw_ostream &);
  static StringRef input(StringRef, void *, MCModuleYAML::Operand &);
  static bool mustQuote(StringRef) { return false; }
};

template <> struct ScalarTraits<MCModuleYAML::OpcodeEnum> {
  static void output(const MCModuleYAML::OpcodeEnum &, void *,
                     llvm::raw_ostream &);
  static StringRef input(StringRef, void *, MCModuleYAML::OpcodeEnum &);
  static bool mustQuote(StringRef) { return false; }
};

void MappingTraits<MCModuleYAML::Inst>::mapping(IO &IO, MCModuleYAML::Inst &I) {

  sizeof(I.Opcode);
  IO.mapRequired("Inst", I.Opcode);
  IO.mapRequired("Size", I.Size);
  IO.mapRequired("Ops", I.Operands);
}

void
MappingTraits<MCModuleYAML::BasicBlock>::mapping(IO &IO,
                                                 MCModuleYAML::BasicBlock &BB) {
  IO.mapRequired("Address", BB.Address);
  IO.mapRequired("Preds", BB.Preds);
  IO.mapRequired("Succs", BB.Succs);
  IO.mapRequired("SizeInBytes", BB.SizeInBytes);
  IO.mapRequired("InstCount", BB.InstCount);
  IO.mapRequired("Instructions", BB.Insts);
}

void MappingTraits<MCModuleYAML::Function>::mapping(IO &IO,
                                                    MCModuleYAML::Function &F) {
  IO.mapRequired("Name", F.Name);
  IO.mapRequired("BasicBlocks", F.BasicBlocks);
}

void MappingTraits<MCModuleYAML::Module>::mapping(IO &IO,
                                                  MCModuleYAML::Module &M) {
  IO.mapOptional("Functions", M.Functions);
}

void
ScalarTraits<MCModuleYAML::Operand>::output(const MCModuleYAML::Operand &Val,
                                            void *Ctx, raw_ostream &Out) {
  InstrRegInfoHolder *IRI = (InstrRegInfoHolder *)Ctx;

  // FIXME: Doesn't support FPImm and expr/inst, but do these make sense?
  if (Val.MCOp.isImm())
    Out << "I" << Val.MCOp.getImm();
  else if (Val.MCOp.isReg())
    Out << "R" << IRI->MRI.getName(Val.MCOp.getReg());
  else
    llvm_unreachable("Trying to output invalid MCOperand!");
}

StringRef
ScalarTraits<MCModuleYAML::Operand>::input(StringRef Scalar, void *Ctx,
                                           MCModuleYAML::Operand &Val) {
  InstrRegInfoHolder *IRI = (InstrRegInfoHolder *)Ctx;
  char Type = 0;
  if (Scalar.size() >= 1)
    Type = Scalar.front();
  if (Type != 'R' && Type != 'I')
    return "Operand must start with 'R' (register) or 'I' (immediate).";
  if (Type == 'R') {
    unsigned Reg;
    if (!IRI->matchRegister(Scalar.substr(1), Reg))
      return "Invalid register name.";
    Val.MCOp = MCOperand::createReg(Reg);
  } else if (Type == 'I') {
    int64_t RIVal;
    if (Scalar.substr(1).getAsInteger(10, RIVal))
      return "Invalid immediate value.";
    Val.MCOp = MCOperand::createImm(RIVal);
  } else {
    Val.MCOp = MCOperand();
  }
  return StringRef();
}

void ScalarTraits<MCModuleYAML::OpcodeEnum>::output(
    const MCModuleYAML::OpcodeEnum &Val, void *Ctx, raw_ostream &Out) {
  InstrRegInfoHolder *IRI = (InstrRegInfoHolder *)Ctx;
  Out << IRI->MII.getName(Val);
}

StringRef
ScalarTraits<MCModuleYAML::OpcodeEnum>::input(StringRef Scalar, void *Ctx,
                                              MCModuleYAML::OpcodeEnum &Val) {
  InstrRegInfoHolder *IRI = (InstrRegInfoHolder *)Ctx;
  unsigned Opc;
  if (!IRI->matchOpcode(Scalar, Opc))
    return "Invalid instruction opcode.";
  Val = Opc;
  return "";
}

} // end namespace yaml

namespace {

class MCModule2YAML {
  const MCModule &MCM;
  MCModuleYAML::Module YAMLModule;
  void dumpFunction(const MCFunction &MCF);
  void dumpBasicBlock(const MCBasicBlock *MCBB);

public:
  MCModule2YAML(const MCModule &MCM);
  MCModuleYAML::Module &getYAMLModule();
};

class YAML2MCModule {
  MCModule &MCM;

public:
  YAML2MCModule(MCModule &MCM);
  StringRef parse(const MCModuleYAML::Module &YAMLModule);
};

} // end unnamed namespace

MCModule2YAML::MCModule2YAML(const MCModule &MCM) : MCM(MCM), YAMLModule() {
  for (MCModule::const_func_iterator FI = MCM.func_begin(), FE = MCM.func_end();
       FI != FE; ++FI)
    dumpFunction(**FI);
}

void MCModule2YAML::dumpFunction(const MCFunction &MCF) {
  YAMLModule.Functions.resize(YAMLModule.Functions.size() + 1);
  MCModuleYAML::Function &F = YAMLModule.Functions.back();
  F.Name = MCF.getName();
  for (MCFunction::const_iterator BBI = MCF.begin(), BBE = MCF.end();
       BBI != BBE; ++BBI) {
    const MCBasicBlock &MCBB = **BBI;
    F.BasicBlocks.resize(F.BasicBlocks.size() + 1);
    MCModuleYAML::BasicBlock &BB = F.BasicBlocks.back();
    BB.Address = MCBB.getStartAddr();
    BB.SizeInBytes = MCBB.getSizeInBytes();

    for (MCBasicBlock::const_iterator I = MCBB.begin(), E = MCBB.end();
         I != E; ++I) {
      const MCDecodedInst &MCDI = *I;
      BB.Insts.push_back(MCModuleYAML::Inst());
      BB.Insts.back().Opcode = MCDI.Inst.getOpcode();
      BB.Insts.back().Size = MCDI.Size;
      const unsigned OpCount = MCDI.Inst.getNumOperands();
      BB.Insts.back().Operands.resize(OpCount);
      for (unsigned oi = 0; oi != OpCount; ++oi)
        BB.Insts.back().Operands[oi].MCOp = MCDI.Inst.getOperand(oi);
      ++BB.InstCount;
    }

    for (MCBasicBlock::pred_const_iterator PI = MCBB.pred_begin(),
                                           PE = MCBB.pred_end();
         PI != PE; ++PI)
      BB.Preds.push_back((*PI)->getStartAddr());
    // FIXME: Should we keep them sorted in MCBasicBlock?
    std::sort(BB.Preds.begin(), BB.Preds.end());
    for (MCBasicBlock::succ_const_iterator SI = MCBB.succ_begin(),
                                           SE = MCBB.succ_end();
         SI != SE; ++SI)
      BB.Succs.push_back((*SI)->getStartAddr());
    std::sort(BB.Succs.begin(), BB.Succs.end());
  }
}

MCModuleYAML::Module &MCModule2YAML::getYAMLModule() { return YAMLModule; }

YAML2MCModule::YAML2MCModule(MCModule &MCM) : MCM(MCM) {}

StringRef YAML2MCModule::parse(const MCModuleYAML::Module &YAMLModule) {
  typedef std::vector<MCModuleYAML::Inst>::const_iterator InstIt;
  typedef std::vector<MCModuleYAML::Operand>::const_iterator OpIt;
  typedef std::vector<MCModuleYAML::Function>::const_iterator FuncIt;
  typedef std::vector<MCModuleYAML::BasicBlock>::const_iterator BBIt;
  typedef std::vector<yaml::Hex64>::const_iterator AddrIt;
  for (FuncIt FI = YAMLModule.Functions.begin(),
              FE = YAMLModule.Functions.end();
       FI != FE; ++FI) {
    MCFunction *MCFN = nullptr;
    for (BBIt BBI = FI->BasicBlocks.begin(), BBE = FI->BasicBlocks.end();
         BBI != BBE; ++BBI) {
      if (!MCFN)
        MCFN = MCM.createFunction(FI->Name, BBI->Address);
      MCBasicBlock *MCBB = &MCFN->createBlock(BBI->Address);
      for (InstIt II = BBI->Insts.begin(), IE = BBI->Insts.end(); II != IE;
           ++II) {
        MCInst MI;
        MI.setOpcode(II->Opcode);
        for (OpIt OI = II->Operands.begin(), OE = II->Operands.end(); OI != OE;
             ++OI)
          MI.addOperand(OI->MCOp);
        MCBB->addInst(MI, II->Size);
      }
    }
    for (BBIt BBI = FI->BasicBlocks.begin(), BBE = FI->BasicBlocks.end();
         BBI != BBE; ++BBI) {
      MCBasicBlock *MCBB = MCFN->find(BBI->Address);
      if (!MCBB)
        return "Couldn't find matching basic block in function.";
      for (AddrIt PI = BBI->Preds.begin(), PE = BBI->Preds.end(); PI != PE;
           ++PI) {
        MCBasicBlock *Pred = MCFN->find(*PI);
        if (!Pred)
          return "Couldn't find predecessor basic block.";
        MCBB->addPredecessor(Pred);
      }
      for (AddrIt SI = BBI->Succs.begin(), SE = BBI->Succs.end(); SI != SE;
           ++SI) {
        MCBasicBlock *Succ = MCFN->find(*SI);
        if (!Succ)
          return "Couldn't find predecessor basic block.";
        MCBB->addSuccessor(Succ);
      }
    }
  }
  return "";
}

StringRef mcmodule2yaml(raw_ostream &OS, const MCModule &MCM,
                        const MCInstrInfo &MII, const MCRegisterInfo &MRI) {
  MCModule2YAML Dumper(MCM);
  InstrRegInfoHolder IRI(MII, MRI);
  yaml::Output YOut(OS, (void *)&IRI);
  YOut << Dumper.getYAMLModule();
  return "";
}

StringRef yaml2mcmodule(std::unique_ptr<MCModule> &MCM, StringRef YamlContent,
                        const MCInstrInfo &MII, const MCRegisterInfo &MRI) {
  MCM.reset(new MCModule);
  YAML2MCModule Parser(*MCM);
  MCModuleYAML::Module YAMLModule;
  InstrRegInfoHolder IRI(MII, MRI);
  yaml::Input YIn(YamlContent, (void *)&IRI);
  YIn >> YAMLModule;
  if (std::error_code ec = YIn.error())
    return ec.message();
  StringRef err = Parser.parse(YAMLModule);
  if (!err.empty())
    return err;
  return "";
}

} // end namespace llvm
