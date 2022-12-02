#include "AArch64InstrSema.h"

#include "llvm/Support/raw_ostream.h"
#include "llvm/ADT/StringExtras.h"
#include "../AArch64.h"
#include "llvm/Support/Debug.h"

using namespace llvm;

#define DEBUG_TYPE "dc-sema"

void AArch64InstrSema::printInstruction() {
    uint64_t  Address = CurrentInst->Address;
    LLVM_DEBUG(CurrentInst->Inst.dump());
    switch (CurrentInst->Inst.getOpcode()) {
        default: {
            llvm_unreachable("unknown opcode");
        }
        case AArch64::PHI: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " PHI\n");
            break;
        }
        case AArch64::INLINEASM: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " INLINEASM\n");
            break;
        }
        case AArch64::CFI_INSTRUCTION: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CFI_INSTRUCTION\n");
            break;
        }
        case AArch64::EH_LABEL: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " EH_LABEL\n");
            break;
        }
        case AArch64::GC_LABEL: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " GC_LABEL\n");
            break;
        }
        case AArch64::KILL: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " KILL\n");
            break;
        }
        case AArch64::EXTRACT_SUBREG: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " EXTRACT_SUBREG\n");
            break;
        }
        case AArch64::INSERT_SUBREG: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " INSERT_SUBREG\n");
            break;
        }
        case AArch64::IMPLICIT_DEF: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " IMPLICIT_DEF\n");
            break;
        }
        case AArch64::SUBREG_TO_REG: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBREG_TO_REG\n");
            break;
        }
        case AArch64::COPY_TO_REGCLASS: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " COPY_TO_REGCLASS\n");
            break;
        }
        case AArch64::DBG_VALUE: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DBG_VALUE\n");
            break;
        }
        case AArch64::REG_SEQUENCE: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " REG_SEQUENCE\n");
            break;
        }
        case AArch64::COPY: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " COPY\n");
            break;
        }
        case AArch64::BUNDLE: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BUNDLE\n");
            break;
        }
        case AArch64::LIFETIME_START: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LIFETIME_START\n");
            break;
        }
        case AArch64::LIFETIME_END: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LIFETIME_END\n");
            break;
        }
        case AArch64::STACKMAP: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STACKMAP\n");
            break;
        }
        case AArch64::PATCHPOINT: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " PATCHPOINT\n");
            break;
        }
        case AArch64::LOAD_STACK_GUARD: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LOAD_STACK_GUARD\n");
            break;
        }
        case AArch64::STATEPOINT: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STATEPOINT\n");
            break;
        }
        case AArch64::LOCAL_ESCAPE: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LOCAL_ESCAPE\n");
            break;
        }
        case AArch64::FAULTING_LOAD_OP: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FAULTING_LOAD_OP\n");
            break;
        }
        case AArch64::ABSv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ABSv16i8\n");
            break;
        }
        case AArch64::ABSv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ABSv1i64\n");
            break;
        }
        case AArch64::ABSv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ABSv2i32\n");
            break;
        }
        case AArch64::ABSv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ABSv2i64\n");
            break;
        }
        case AArch64::ABSv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ABSv4i16\n");
            break;
        }
        case AArch64::ABSv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ABSv4i32\n");
            break;
        }
        case AArch64::ABSv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ABSv8i16\n");
            break;
        }
        case AArch64::ABSv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ABSv8i8\n");
            break;
        }
        case AArch64::ADCSWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADCSWr\n");
            break;
        }
        case AArch64::ADCSXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADCSXr\n");
            break;
        }
        case AArch64::ADCWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADCWr\n");
            break;
        }
        case AArch64::ADCXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADCXr\n");
            break;
        }
        case AArch64::ADDHNv2i64_v2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDHNv2i64_v2i32\n");
            break;
        }
        case AArch64::ADDHNv2i64_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDHNv2i64_v4i32\n");
            break;
        }
        case AArch64::ADDHNv4i32_v4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDHNv4i32_v4i16\n");
            break;
        }
        case AArch64::ADDHNv4i32_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDHNv4i32_v8i16\n");
            break;
        }
        case AArch64::ADDHNv8i16_v16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDHNv8i16_v16i8\n");
            break;
        }
        case AArch64::ADDHNv8i16_v8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDHNv8i16_v8i8\n");
            break;
        }
        case AArch64::ADDPv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDPv16i8\n");
            break;
        }
        case AArch64::ADDPv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDPv2i32\n");
            break;
        }
        case AArch64::ADDPv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDPv2i64\n");
            break;
        }
        case AArch64::ADDPv2i64p: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDPv2i64p\n");
            break;
        }
        case AArch64::ADDPv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDPv4i16\n");
            break;
        }
        case AArch64::ADDPv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDPv4i32\n");
            break;
        }
        case AArch64::ADDPv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDPv8i16\n");
            break;
        }
        case AArch64::ADDPv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDPv8i8\n");
            break;
        }
        case AArch64::ADDSWri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDSWri\n");
            break;
        }
        case AArch64::ADDSWrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDSWrr\n");
            break;
        }
        case AArch64::ADDSWrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDSWrs\n");
            break;
        }
        case AArch64::ADDSWrx: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDSWrx\n");
            break;
        }
        case AArch64::ADDSXri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDSXri\n");
            break;
        }
        case AArch64::ADDSXrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDSXrr\n");
            break;
        }
        case AArch64::ADDSXrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDSXrs\n");
            break;
        }
        case AArch64::ADDSXrx: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDSXrx\n");
            break;
        }
        case AArch64::ADDSXrx64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDSXrx64\n");
            break;
        }
        case AArch64::ADDVv16i8v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDVv16i8v\n");
            break;
        }
        case AArch64::ADDVv4i16v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDVv4i16v\n");
            break;
        }
        case AArch64::ADDVv4i32v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDVv4i32v\n");
            break;
        }
        case AArch64::ADDVv8i16v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDVv8i16v\n");
            break;
        }
        case AArch64::ADDVv8i8v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDVv8i8v\n");
            break;
        }
        case AArch64::ADDWri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDWri\n");
            break;
        }
        case AArch64::ADDWrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDWrr\n");
            break;
        }
        case AArch64::ADDWrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDWrs\n");
            break;
        }
        case AArch64::ADDWrx: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDWrx\n");
            break;
        }
        case AArch64::ADDXri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDXri\n");
            break;
        }
        case AArch64::ADDXrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDXrr\n");
            break;
        }
        case AArch64::ADDXrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDXrs\n");
            break;
        }
        case AArch64::ADDXrx: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDXrx\n");
            break;
        }
        case AArch64::ADDXrx64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDXrx64\n");
            break;
        }
        case AArch64::ADDv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDv16i8\n");
            break;
        }
        case AArch64::ADDv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDv1i64\n");
            break;
        }
        case AArch64::ADDv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDv2i32\n");
            break;
        }
        case AArch64::ADDv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDv2i64\n");
            break;
        }
        case AArch64::ADDv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDv4i16\n");
            break;
        }
        case AArch64::ADDv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDv4i32\n");
            break;
        }
        case AArch64::ADDv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDv8i16\n");
            break;
        }
        case AArch64::ADDv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADDv8i8\n");
            break;
        }
        case AArch64::ADJCALLSTACKDOWN: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADJCALLSTACKDOWN\n");
            break;
        }
        case AArch64::ADJCALLSTACKUP: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADJCALLSTACKUP\n");
            break;
        }
        case AArch64::ADR: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADR\n");
            break;
        }
        case AArch64::ADRP: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ADRP\n");
            break;
        }
        case AArch64::AESDrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " AESDrr\n");
            break;
        }
        case AArch64::AESErr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " AESErr\n");
            break;
        }
        case AArch64::AESIMCrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " AESIMCrr\n");
            break;
        }
        case AArch64::AESMCrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " AESMCrr\n");
            break;
        }
        case AArch64::ANDSWri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ANDSWri\n");
            break;
        }
        case AArch64::ANDSWrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ANDSWrr\n");
            break;
        }
        case AArch64::ANDSWrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ANDSWrs\n");
            break;
        }
        case AArch64::ANDSXri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ANDSXri\n");
            break;
        }
        case AArch64::ANDSXrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ANDSXrr\n");
            break;
        }
        case AArch64::ANDSXrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ANDSXrs\n");
            break;
        }
        case AArch64::ANDWri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ANDWri\n");
            break;
        }
        case AArch64::ANDWrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ANDWrr\n");
            break;
        }
        case AArch64::ANDWrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ANDWrs\n");
            break;
        }
        case AArch64::ANDXri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ANDXri\n");
            break;
        }
        case AArch64::ANDXrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ANDXrr\n");
            break;
        }
        case AArch64::ANDXrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ANDXrs\n");
            break;
        }
        case AArch64::ANDv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ANDv16i8\n");
            break;
        }
        case AArch64::ANDv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ANDv8i8\n");
            break;
        }
        case AArch64::ASRVWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ASRVWr\n");
            break;
        }
        case AArch64::ASRVXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ASRVXr\n");
            break;
        }
        case AArch64::B: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " B\n");
            break;
        }
        case AArch64::BFMWri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BFMWri\n");
            break;
        }
        case AArch64::BFMXri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BFMXri\n");
            break;
        }
        case AArch64::BICSWrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BICSWrr\n");
            break;
        }
        case AArch64::BICSWrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BICSWrs\n");
            break;
        }
        case AArch64::BICSXrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BICSXrr\n");
            break;
        }
        case AArch64::BICSXrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BICSXrs\n");
            break;
        }
        case AArch64::BICWrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BICWrr\n");
            break;
        }
        case AArch64::BICWrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BICWrs\n");
            break;
        }
        case AArch64::BICXrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BICXrr\n");
            break;
        }
        case AArch64::BICXrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BICXrs\n");
            break;
        }
        case AArch64::BICv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BICv16i8\n");
            break;
        }
        case AArch64::BICv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BICv2i32\n");
            break;
        }
        case AArch64::BICv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BICv4i16\n");
            break;
        }
        case AArch64::BICv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BICv4i32\n");
            break;
        }
        case AArch64::BICv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BICv8i16\n");
            break;
        }
        case AArch64::BICv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BICv8i8\n");
            break;
        }
        case AArch64::BIFv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BIFv16i8\n");
            break;
        }
        case AArch64::BIFv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BIFv8i8\n");
            break;
        }
        case AArch64::BITv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BITv16i8\n");
            break;
        }
        case AArch64::BITv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BITv8i8\n");
            break;
        }
        case AArch64::BL: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BL\n");
            break;
        }
        case AArch64::BLR: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BLR\n");
            break;
        }
        case AArch64::BR: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BR\n");
            break;
        }
        case AArch64::BRK: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BRK\n");
            break;
        }
        case AArch64::BSLv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BSLv16i8\n");
            break;
        }
        case AArch64::BSLv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " BSLv8i8\n");
            break;
        }
        case AArch64::Bcc: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " Bcc\n");
            break;
        }
        case AArch64::CASALb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASALb\n");
            break;
        }
        case AArch64::CASALd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASALd\n");
            break;
        }
        case AArch64::CASALh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASALh\n");
            break;
        }
        case AArch64::CASALs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASALs\n");
            break;
        }
        case AArch64::CASAb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASAb\n");
            break;
        }
        case AArch64::CASAd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASAd\n");
            break;
        }
        case AArch64::CASAh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASAh\n");
            break;
        }
        case AArch64::CASAs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASAs\n");
            break;
        }
        case AArch64::CASLb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASLb\n");
            break;
        }
        case AArch64::CASLd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASLd\n");
            break;
        }
        case AArch64::CASLh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASLh\n");
            break;
        }
        case AArch64::CASLs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASLs\n");
            break;
        }
//        case AArch64::CASPALd: {
//            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASPALd\n");
//            break;
//        }
//        case AArch64::CASPALs: {
//            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASPALs\n");
//            break;
//        }
//        case AArch64::CASPAd: {
//            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASPAd\n");
//            break;
//        }
//        case AArch64::CASPAs: {
//            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASPAs\n");
//            break;//        }
//        case AArch64::CASPLd: {
//            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASPLd\n");
//            break;
//        }
//        case AArch64::CASPLs: {
//            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASPLs\n");
//            break;
//        }
//        case AArch64::CASPd: {
//            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASPd\n");
//            break;
//        }
//        case AArch64::CASPs: {
//            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASPs\n");
//            break;
//        }
        case AArch64::CASb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASb\n");
            break;
        }
        case AArch64::CASd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASd\n");
            break;
        }
        case AArch64::CASh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASh\n");
            break;
        }
        case AArch64::CASs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CASs\n");
            break;
        }
        case AArch64::CBNZW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CBNZW\n");
            break;
        }
        case AArch64::CBNZX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CBNZX\n");
            break;
        }
        case AArch64::CBZW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CBZW\n");
            break;
        }
        case AArch64::CBZX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CBZX\n");
            break;
        }
        case AArch64::CCMNWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CCMNWi\n");
            break;
        }
        case AArch64::CCMNWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CCMNWr\n");
            break;
        }
        case AArch64::CCMNXi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CCMNXi\n");
            break;
        }
        case AArch64::CCMNXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CCMNXr\n");
            break;
        }
        case AArch64::CCMPWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CCMPWi\n");
            break;
        }
        case AArch64::CCMPWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CCMPWr\n");
            break;
        }
        case AArch64::CCMPXi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CCMPXi\n");
            break;
        }
        case AArch64::CCMPXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CCMPXr\n");
            break;
        }
        case AArch64::CLREX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CLREX\n");
            break;
        }
        case AArch64::CLSWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CLSWr\n");
            break;
        }
        case AArch64::CLSXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CLSXr\n");
            break;
        }
        case AArch64::CLSv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CLSv16i8\n");
            break;
        }
        case AArch64::CLSv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CLSv2i32\n");
            break;
        }
        case AArch64::CLSv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CLSv4i16\n");
            break;
        }
        case AArch64::CLSv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CLSv4i32\n");
            break;
        }
        case AArch64::CLSv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CLSv8i16\n");
            break;
        }
        case AArch64::CLSv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CLSv8i8\n");
            break;
        }
        case AArch64::CLZWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CLZWr\n");
            break;
        }
        case AArch64::CLZXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CLZXr\n");
            break;
        }
        case AArch64::CLZv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CLZv16i8\n");
            break;
        }
        case AArch64::CLZv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CLZv2i32\n");
            break;
        }
        case AArch64::CLZv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CLZv4i16\n");
            break;
        }
        case AArch64::CLZv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CLZv4i32\n");
            break;
        }
        case AArch64::CLZv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CLZv8i16\n");
            break;
        }
        case AArch64::CLZv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CLZv8i8\n");
            break;
        }
        case AArch64::CMEQv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMEQv16i8\n");
            break;
        }
        case AArch64::CMEQv16i8rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMEQv16i8rz\n");
            break;
        }
        case AArch64::CMEQv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMEQv1i64\n");
            break;
        }
        case AArch64::CMEQv1i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMEQv1i64rz\n");
            break;
        }
        case AArch64::CMEQv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMEQv2i32\n");
            break;
        }
        case AArch64::CMEQv2i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMEQv2i32rz\n");
            break;
        }
        case AArch64::CMEQv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMEQv2i64\n");
            break;
        }
        case AArch64::CMEQv2i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMEQv2i64rz\n");
            break;
        }
        case AArch64::CMEQv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMEQv4i16\n");
            break;
        }
        case AArch64::CMEQv4i16rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMEQv4i16rz\n");
            break;
        }
        case AArch64::CMEQv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMEQv4i32\n");
            break;
        }
        case AArch64::CMEQv4i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMEQv4i32rz\n");
            break;
        }
        case AArch64::CMEQv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMEQv8i16\n");
            break;
        }
        case AArch64::CMEQv8i16rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMEQv8i16rz\n");
            break;
        }
        case AArch64::CMEQv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMEQv8i8\n");
            break;
        }
        case AArch64::CMEQv8i8rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMEQv8i8rz\n");
            break;
        }
        case AArch64::CMGEv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGEv16i8\n");
            break;
        }
        case AArch64::CMGEv16i8rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGEv16i8rz\n");
            break;
        }
        case AArch64::CMGEv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGEv1i64\n");
            break;
        }
        case AArch64::CMGEv1i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGEv1i64rz\n");
            break;
        }
        case AArch64::CMGEv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGEv2i32\n");
            break;
        }
        case AArch64::CMGEv2i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGEv2i32rz\n");
            break;
        }
        case AArch64::CMGEv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGEv2i64\n");
            break;
        }
        case AArch64::CMGEv2i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGEv2i64rz\n");
            break;
        }
        case AArch64::CMGEv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGEv4i16\n");
            break;
        }
        case AArch64::CMGEv4i16rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGEv4i16rz\n");
            break;
        }
        case AArch64::CMGEv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGEv4i32\n");
            break;
        }
        case AArch64::CMGEv4i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGEv4i32rz\n");
            break;
        }
        case AArch64::CMGEv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGEv8i16\n");
            break;
        }
        case AArch64::CMGEv8i16rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGEv8i16rz\n");
            break;
        }
        case AArch64::CMGEv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGEv8i8\n");
            break;
        }
        case AArch64::CMGEv8i8rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGEv8i8rz\n");
            break;
        }
        case AArch64::CMGTv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGTv16i8\n");
            break;
        }
        case AArch64::CMGTv16i8rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGTv16i8rz\n");
            break;
        }
        case AArch64::CMGTv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGTv1i64\n");
            break;
        }
        case AArch64::CMGTv1i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGTv1i64rz\n");
            break;
        }
        case AArch64::CMGTv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGTv2i32\n");
            break;
        }
        case AArch64::CMGTv2i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGTv2i32rz\n");
            break;
        }
        case AArch64::CMGTv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGTv2i64\n");
            break;
        }
        case AArch64::CMGTv2i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGTv2i64rz\n");
            break;
        }
        case AArch64::CMGTv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGTv4i16\n");
            break;
        }
        case AArch64::CMGTv4i16rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGTv4i16rz\n");
            break;
        }
        case AArch64::CMGTv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGTv4i32\n");
            break;
        }
        case AArch64::CMGTv4i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGTv4i32rz\n");
            break;
        }
        case AArch64::CMGTv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGTv8i16\n");
            break;
        }
        case AArch64::CMGTv8i16rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGTv8i16rz\n");
            break;
        }
        case AArch64::CMGTv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGTv8i8\n");
            break;
        }
        case AArch64::CMGTv8i8rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMGTv8i8rz\n");
            break;
        }
        case AArch64::CMHIv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMHIv16i8\n");
            break;
        }
        case AArch64::CMHIv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMHIv1i64\n");
            break;
        }
        case AArch64::CMHIv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMHIv2i32\n");
            break;
        }
        case AArch64::CMHIv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMHIv2i64\n");
            break;
        }
        case AArch64::CMHIv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMHIv4i16\n");
            break;
        }
        case AArch64::CMHIv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMHIv4i32\n");
            break;
        }
        case AArch64::CMHIv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMHIv8i16\n");
            break;
        }
        case AArch64::CMHIv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMHIv8i8\n");
            break;
        }
        case AArch64::CMHSv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMHSv16i8\n");
            break;
        }
        case AArch64::CMHSv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMHSv1i64\n");
            break;
        }
        case AArch64::CMHSv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMHSv2i32\n");
            break;
        }
        case AArch64::CMHSv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMHSv2i64\n");
            break;
        }
        case AArch64::CMHSv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMHSv4i16\n");
            break;
        }
        case AArch64::CMHSv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMHSv4i32\n");
            break;
        }
        case AArch64::CMHSv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMHSv8i16\n");
            break;
        }
        case AArch64::CMHSv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMHSv8i8\n");
            break;
        }
        case AArch64::CMLEv16i8rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMLEv16i8rz\n");
            break;
        }
        case AArch64::CMLEv1i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMLEv1i64rz\n");
            break;
        }
        case AArch64::CMLEv2i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMLEv2i32rz\n");
            break;
        }
        case AArch64::CMLEv2i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMLEv2i64rz\n");
            break;
        }
        case AArch64::CMLEv4i16rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMLEv4i16rz\n");
            break;
        }
        case AArch64::CMLEv4i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMLEv4i32rz\n");
            break;
        }
        case AArch64::CMLEv8i16rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMLEv8i16rz\n");
            break;
        }
        case AArch64::CMLEv8i8rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMLEv8i8rz\n");
            break;
        }
        case AArch64::CMLTv16i8rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMLTv16i8rz\n");
            break;
        }
        case AArch64::CMLTv1i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMLTv1i64rz\n");
            break;
        }
        case AArch64::CMLTv2i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMLTv2i32rz\n");
            break;
        }
        case AArch64::CMLTv2i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMLTv2i64rz\n");
            break;
        }
        case AArch64::CMLTv4i16rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMLTv4i16rz\n");
            break;
        }
        case AArch64::CMLTv4i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMLTv4i32rz\n");
            break;
        }
        case AArch64::CMLTv8i16rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMLTv8i16rz\n");
            break;
        }
        case AArch64::CMLTv8i8rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMLTv8i8rz\n");
            break;
        }
        case AArch64::CMTSTv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMTSTv16i8\n");
            break;
        }
        case AArch64::CMTSTv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMTSTv1i64\n");
            break;
        }
        case AArch64::CMTSTv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMTSTv2i32\n");
            break;
        }
        case AArch64::CMTSTv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMTSTv2i64\n");
            break;
        }
        case AArch64::CMTSTv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMTSTv4i16\n");
            break;
        }
        case AArch64::CMTSTv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMTSTv4i32\n");
            break;
        }
        case AArch64::CMTSTv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMTSTv8i16\n");
            break;
        }
        case AArch64::CMTSTv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CMTSTv8i8\n");
            break;
        }
        case AArch64::CNTv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CNTv16i8\n");
            break;
        }
        case AArch64::CNTv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CNTv8i8\n");
            break;
        }
        case AArch64::CPYi16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CPYi16\n");
            break;
        }
        case AArch64::CPYi32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CPYi32\n");
            break;
        }
        case AArch64::CPYi64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CPYi64\n");
            break;
        }
        case AArch64::CPYi8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CPYi8\n");
            break;
        }
        case AArch64::CRC32Brr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CRC32Brr\n");
            break;
        }
        case AArch64::CRC32CBrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CRC32CBrr\n");
            break;
        }
        case AArch64::CRC32CHrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CRC32CHrr\n");
            break;
        }
        case AArch64::CRC32CWrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CRC32CWrr\n");
            break;
        }
        case AArch64::CRC32CXrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CRC32CXrr\n");
            break;
        }
        case AArch64::CRC32Hrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CRC32Hrr\n");
            break;
        }
        case AArch64::CRC32Wrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CRC32Wrr\n");
            break;
        }
        case AArch64::CRC32Xrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CRC32Xrr\n");
            break;
        }
        case AArch64::CSELWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CSELWr\n");
            break;
        }
        case AArch64::CSELXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CSELXr\n");
            break;
        }
        case AArch64::CSINCWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CSINCWr\n");
            break;
        }
        case AArch64::CSINCXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CSINCXr\n");
            break;
        }
        case AArch64::CSINVWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CSINVWr\n");
            break;
        }
        case AArch64::CSINVXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CSINVXr\n");
            break;
        }
        case AArch64::CSNEGWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CSNEGWr\n");
            break;
        }
        case AArch64::CSNEGXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " CSNEGXr\n");
            break;
        }
        case AArch64::DCPS1: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DCPS1\n");
            break;
        }
        case AArch64::DCPS2: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DCPS2\n");
            break;
        }
        case AArch64::DCPS3: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DCPS3\n");
            break;
        }
        case AArch64::DMB: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DMB\n");
            break;
        }
        case AArch64::DRPS: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DRPS\n");
            break;
        }
        case AArch64::DSB: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DSB\n");
            break;
        }
        case AArch64::DUPv16i8gpr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DUPv16i8gpr\n");
            break;
        }
        case AArch64::DUPv16i8lane: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DUPv16i8lane\n");
            break;
        }
        case AArch64::DUPv2i32gpr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DUPv2i32gpr\n");
            break;
        }
        case AArch64::DUPv2i32lane: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DUPv2i32lane\n");
            break;
        }
        case AArch64::DUPv2i64gpr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DUPv2i64gpr\n");
            break;
        }
        case AArch64::DUPv2i64lane: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DUPv2i64lane\n");
            break;
        }
        case AArch64::DUPv4i16gpr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DUPv4i16gpr\n");
            break;
        }
        case AArch64::DUPv4i16lane: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DUPv4i16lane\n");
            break;
        }
        case AArch64::DUPv4i32gpr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DUPv4i32gpr\n");
            break;
        }
        case AArch64::DUPv4i32lane: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DUPv4i32lane\n");
            break;
        }
        case AArch64::DUPv8i16gpr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DUPv8i16gpr\n");
            break;
        }
        case AArch64::DUPv8i16lane: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DUPv8i16lane\n");
            break;
        }
        case AArch64::DUPv8i8gpr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DUPv8i8gpr\n");
            break;
        }
        case AArch64::DUPv8i8lane: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " DUPv8i8lane\n");
            break;
        }
        case AArch64::EONWrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " EONWrr\n");
            break;
        }
        case AArch64::EONWrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " EONWrs\n");
            break;
        }
        case AArch64::EONXrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " EONXrr\n");
            break;
        }
        case AArch64::EONXrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " EONXrs\n");
            break;
        }
        case AArch64::EORWri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " EORWri\n");
            break;
        }
        case AArch64::EORWrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " EORWrr\n");
            break;
        }
        case AArch64::EORWrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " EORWrs\n");
            break;
        }
        case AArch64::EORXri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " EORXri\n");
            break;
        }
        case AArch64::EORXrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " EORXrr\n");
            break;
        }
        case AArch64::EORXrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " EORXrs\n");
            break;
        }
        case AArch64::EORv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " EORv16i8\n");
            break;
        }
        case AArch64::EORv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " EORv8i8\n");
            break;
        }
        case AArch64::ERET: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ERET\n");
            break;
        }
        case AArch64::EXTRWrri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " EXTRWrri\n");
            break;
        }
        case AArch64::EXTRXrri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " EXTRXrri\n");
            break;
        }
        case AArch64::EXTv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " EXTv16i8\n");
            break;
        }
        case AArch64::EXTv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " EXTv8i8\n");
            break;
        }
        case AArch64::F128CSEL: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " F128CSEL\n");
            break;
        }
        case AArch64::FABD32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FABD32\n");
            break;
        }
        case AArch64::FABD64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FABD64\n");
            break;
        }
        case AArch64::FABDv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FABDv2f32\n");
            break;
        }
        case AArch64::FABDv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FABDv2f64\n");
            break;
        }
        case AArch64::FABDv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FABDv4f32\n");
            break;
        }
        case AArch64::FABSDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FABSDr\n");
            break;
        }
        case AArch64::FABSSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FABSSr\n");
            break;
        }
        case AArch64::FABSv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FABSv2f32\n");
            break;
        }
        case AArch64::FABSv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FABSv2f64\n");
            break;
        }
        case AArch64::FABSv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FABSv4f32\n");
            break;
        }
        case AArch64::FACGE32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FACGE32\n");
            break;
        }
        case AArch64::FACGE64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FACGE64\n");
            break;
        }
        case AArch64::FACGEv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FACGEv2f32\n");
            break;
        }
        case AArch64::FACGEv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FACGEv2f64\n");
            break;
        }
        case AArch64::FACGEv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FACGEv4f32\n");
            break;
        }
        case AArch64::FACGT32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FACGT32\n");
            break;
        }
        case AArch64::FACGT64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FACGT64\n");
            break;
        }
        case AArch64::FACGTv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FACGTv2f32\n");
            break;
        }
        case AArch64::FACGTv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FACGTv2f64\n");
            break;
        }
        case AArch64::FACGTv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FACGTv4f32\n");
            break;
        }
        case AArch64::FADDDrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FADDDrr\n");
            break;
        }
        case AArch64::FADDPv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FADDPv2f32\n");
            break;
        }
        case AArch64::FADDPv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FADDPv2f64\n");
            break;
        }
        case AArch64::FADDPv2i32p: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FADDPv2i32p\n");
            break;
        }
        case AArch64::FADDPv2i64p: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FADDPv2i64p\n");
            break;
        }
        case AArch64::FADDPv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FADDPv4f32\n");
            break;
        }
        case AArch64::FADDSrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FADDSrr\n");
            break;
        }
        case AArch64::FADDv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FADDv2f32\n");
            break;
        }
        case AArch64::FADDv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FADDv2f64\n");
            break;
        }
        case AArch64::FADDv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FADDv4f32\n");
            break;
        }
        case AArch64::FCCMPDrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCCMPDrr\n");
            break;
        }
        case AArch64::FCCMPEDrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCCMPEDrr\n");
            break;
        }
        case AArch64::FCCMPESrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCCMPESrr\n");
            break;
        }
        case AArch64::FCCMPSrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCCMPSrr\n");
            break;
        }
        case AArch64::FCMEQ32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMEQ32\n");
            break;
        }
        case AArch64::FCMEQ64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMEQ64\n");
            break;
        }
        case AArch64::FCMEQv1i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMEQv1i32rz\n");
            break;
        }
        case AArch64::FCMEQv1i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMEQv1i64rz\n");
            break;
        }
        case AArch64::FCMEQv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMEQv2f32\n");
            break;
        }
        case AArch64::FCMEQv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMEQv2f64\n");
            break;
        }
        case AArch64::FCMEQv2i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMEQv2i32rz\n");
            break;
        }
        case AArch64::FCMEQv2i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMEQv2i64rz\n");
            break;
        }
        case AArch64::FCMEQv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMEQv4f32\n");
            break;
        }
        case AArch64::FCMEQv4i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMEQv4i32rz\n");
            break;
        }
        case AArch64::FCMGE32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGE32\n");
            break;
        }
        case AArch64::FCMGE64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGE64\n");
            break;
        }
        case AArch64::FCMGEv1i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGEv1i32rz\n");
            break;
        }
        case AArch64::FCMGEv1i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGEv1i64rz\n");
            break;
        }
        case AArch64::FCMGEv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGEv2f32\n");
            break;
        }
        case AArch64::FCMGEv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGEv2f64\n");
            break;
        }
        case AArch64::FCMGEv2i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGEv2i32rz\n");
            break;
        }
        case AArch64::FCMGEv2i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGEv2i64rz\n");
            break;
        }
        case AArch64::FCMGEv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGEv4f32\n");
            break;
        }
        case AArch64::FCMGEv4i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGEv4i32rz\n");
            break;
        }
        case AArch64::FCMGT32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGT32\n");
            break;
        }
        case AArch64::FCMGT64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGT64\n");
            break;
        }
        case AArch64::FCMGTv1i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGTv1i32rz\n");
            break;
        }
        case AArch64::FCMGTv1i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGTv1i64rz\n");
            break;
        }
        case AArch64::FCMGTv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGTv2f32\n");
            break;
        }
        case AArch64::FCMGTv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGTv2f64\n");
            break;
        }
        case AArch64::FCMGTv2i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGTv2i32rz\n");
            break;
        }
        case AArch64::FCMGTv2i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGTv2i64rz\n");
            break;
        }
        case AArch64::FCMGTv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGTv4f32\n");
            break;
        }
        case AArch64::FCMGTv4i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMGTv4i32rz\n");
            break;
        }
        case AArch64::FCMLEv1i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMLEv1i32rz\n");
            break;
        }
        case AArch64::FCMLEv1i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMLEv1i64rz\n");
            break;
        }
        case AArch64::FCMLEv2i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMLEv2i32rz\n");
            break;
        }
        case AArch64::FCMLEv2i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMLEv2i64rz\n");
            break;
        }
        case AArch64::FCMLEv4i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMLEv4i32rz\n");
            break;
        }
        case AArch64::FCMLTv1i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMLTv1i32rz\n");
            break;
        }
        case AArch64::FCMLTv1i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMLTv1i64rz\n");
            break;
        }
        case AArch64::FCMLTv2i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMLTv2i32rz\n");
            break;
        }
        case AArch64::FCMLTv2i64rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMLTv2i64rz\n");
            break;
        }
        case AArch64::FCMLTv4i32rz: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMLTv4i32rz\n");
            break;
        }
        case AArch64::FCMPDri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMPDri\n");
            break;
        }
        case AArch64::FCMPDrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMPDrr\n");
            break;
        }
        case AArch64::FCMPEDri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMPEDri\n");
            break;
        }
        case AArch64::FCMPEDrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMPEDrr\n");
            break;
        }
        case AArch64::FCMPESri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMPESri\n");
            break;
        }
        case AArch64::FCMPESrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMPESrr\n");
            break;
        }
        case AArch64::FCMPSri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMPSri\n");
            break;
        }
        case AArch64::FCMPSrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCMPSrr\n");
            break;
        }
        case AArch64::FCSELDrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCSELDrrr\n");
            break;
        }
        case AArch64::FCSELSrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCSELSrrr\n");
            break;
        }
        case AArch64::FCVTASUWDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTASUWDr\n");
            break;
        }
        case AArch64::FCVTASUWSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTASUWSr\n");
            break;
        }
        case AArch64::FCVTASUXDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTASUXDr\n");
            break;
        }
        case AArch64::FCVTASUXSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTASUXSr\n");
            break;
        }
        case AArch64::FCVTASv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTASv1i32\n");
            break;
        }
        case AArch64::FCVTASv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTASv1i64\n");
            break;
        }
        case AArch64::FCVTASv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTASv2f32\n");
            break;
        }
        case AArch64::FCVTASv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTASv2f64\n");
            break;
        }
        case AArch64::FCVTASv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTASv4f32\n");
            break;
        }
        case AArch64::FCVTAUUWDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTAUUWDr\n");
            break;
        }
        case AArch64::FCVTAUUWSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTAUUWSr\n");
            break;
        }
        case AArch64::FCVTAUUXDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTAUUXDr\n");
            break;
        }
        case AArch64::FCVTAUUXSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTAUUXSr\n");
            break;
        }
        case AArch64::FCVTAUv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTAUv1i32\n");
            break;
        }
        case AArch64::FCVTAUv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTAUv1i64\n");
            break;
        }
        case AArch64::FCVTAUv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTAUv2f32\n");
            break;
        }
        case AArch64::FCVTAUv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTAUv2f64\n");
            break;
        }
        case AArch64::FCVTAUv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTAUv4f32\n");
            break;
        }
        case AArch64::FCVTDHr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTDHr\n");
            break;
        }
        case AArch64::FCVTDSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTDSr\n");
            break;
        }
        case AArch64::FCVTHDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTHDr\n");
            break;
        }
        case AArch64::FCVTHSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTHSr\n");
            break;
        }
        case AArch64::FCVTLv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTLv2i32\n");
            break;
        }
        case AArch64::FCVTLv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTLv4i16\n");
            break;
        }
        case AArch64::FCVTLv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTLv4i32\n");
            break;
        }
        case AArch64::FCVTLv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTLv8i16\n");
            break;
        }
        case AArch64::FCVTMSUWDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTMSUWDr\n");
            break;
        }
        case AArch64::FCVTMSUWSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTMSUWSr\n");
            break;
        }
        case AArch64::FCVTMSUXDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTMSUXDr\n");
            break;
        }
        case AArch64::FCVTMSUXSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTMSUXSr\n");
            break;
        }
        case AArch64::FCVTMSv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTMSv1i32\n");
            break;
        }
        case AArch64::FCVTMSv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTMSv1i64\n");
            break;
        }
        case AArch64::FCVTMSv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTMSv2f32\n");
            break;
        }
        case AArch64::FCVTMSv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTMSv2f64\n");
            break;
        }
        case AArch64::FCVTMSv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTMSv4f32\n");
            break;
        }
        case AArch64::FCVTMUUWDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTMUUWDr\n");
            break;
        }
        case AArch64::FCVTMUUWSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTMUUWSr\n");
            break;
        }
        case AArch64::FCVTMUUXDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTMUUXDr\n");
            break;
        }
        case AArch64::FCVTMUUXSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTMUUXSr\n");
            break;
        }
        case AArch64::FCVTMUv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTMUv1i32\n");
            break;
        }
        case AArch64::FCVTMUv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTMUv1i64\n");
            break;
        }
        case AArch64::FCVTMUv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTMUv2f32\n");
            break;
        }
        case AArch64::FCVTMUv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTMUv2f64\n");
            break;
        }
        case AArch64::FCVTMUv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTMUv4f32\n");
            break;
        }
        case AArch64::FCVTNSUWDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNSUWDr\n");
            break;
        }
        case AArch64::FCVTNSUWSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNSUWSr\n");
            break;
        }
        case AArch64::FCVTNSUXDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNSUXDr\n");
            break;
        }
        case AArch64::FCVTNSUXSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNSUXSr\n");
            break;
        }
        case AArch64::FCVTNSv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNSv1i32\n");
            break;
        }
        case AArch64::FCVTNSv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNSv1i64\n");
            break;
        }
        case AArch64::FCVTNSv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNSv2f32\n");
            break;
        }
        case AArch64::FCVTNSv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNSv2f64\n");
            break;
        }
        case AArch64::FCVTNSv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNSv4f32\n");
            break;
        }
        case AArch64::FCVTNUUWDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNUUWDr\n");
            break;
        }
        case AArch64::FCVTNUUWSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNUUWSr\n");
            break;
        }
        case AArch64::FCVTNUUXDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNUUXDr\n");
            break;
        }
        case AArch64::FCVTNUUXSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNUUXSr\n");
            break;
        }
        case AArch64::FCVTNUv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNUv1i32\n");
            break;
        }
        case AArch64::FCVTNUv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNUv1i64\n");
            break;
        }
        case AArch64::FCVTNUv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNUv2f32\n");
            break;
        }
        case AArch64::FCVTNUv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNUv2f64\n");
            break;
        }
        case AArch64::FCVTNUv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNUv4f32\n");
            break;
        }
        case AArch64::FCVTNv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNv2i32\n");
            break;
        }
        case AArch64::FCVTNv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNv4i16\n");
            break;
        }
        case AArch64::FCVTNv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNv4i32\n");
            break;
        }
        case AArch64::FCVTNv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTNv8i16\n");
            break;
        }
        case AArch64::FCVTPSUWDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTPSUWDr\n");
            break;
        }
        case AArch64::FCVTPSUWSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTPSUWSr\n");
            break;
        }
        case AArch64::FCVTPSUXDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTPSUXDr\n");
            break;
        }
        case AArch64::FCVTPSUXSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTPSUXSr\n");
            break;
        }
        case AArch64::FCVTPSv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTPSv1i32\n");
            break;
        }
        case AArch64::FCVTPSv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTPSv1i64\n");
            break;
        }
        case AArch64::FCVTPSv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTPSv2f32\n");
            break;
        }
        case AArch64::FCVTPSv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTPSv2f64\n");
            break;
        }
        case AArch64::FCVTPSv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTPSv4f32\n");
            break;
        }
        case AArch64::FCVTPUUWDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTPUUWDr\n");
            break;
        }
        case AArch64::FCVTPUUWSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTPUUWSr\n");
            break;
        }
        case AArch64::FCVTPUUXDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTPUUXDr\n");
            break;
        }
        case AArch64::FCVTPUUXSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTPUUXSr\n");
            break;
        }
        case AArch64::FCVTPUv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTPUv1i32\n");
            break;
        }
        case AArch64::FCVTPUv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTPUv1i64\n");
            break;
        }
        case AArch64::FCVTPUv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTPUv2f32\n");
            break;
        }
        case AArch64::FCVTPUv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTPUv2f64\n");
            break;
        }
        case AArch64::FCVTPUv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTPUv4f32\n");
            break;
        }
        case AArch64::FCVTSDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTSDr\n");
            break;
        }
        case AArch64::FCVTSHr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTSHr\n");
            break;
        }
        case AArch64::FCVTXNv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTXNv1i64\n");
            break;
        }
        case AArch64::FCVTXNv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTXNv2f32\n");
            break;
        }
        case AArch64::FCVTXNv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTXNv4f32\n");
            break;
        }
        case AArch64::FCVTZSSWDri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZSSWDri\n");
            break;
        }
        case AArch64::FCVTZSSWSri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZSSWSri\n");
            break;
        }
        case AArch64::FCVTZSSXDri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZSSXDri\n");
            break;
        }
        case AArch64::FCVTZSSXSri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZSSXSri\n");
            break;
        }
        case AArch64::FCVTZSUWDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZSUWDr\n");
            break;
        }
        case AArch64::FCVTZSUWSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZSUWSr\n");
            break;
        }
        case AArch64::FCVTZSUXDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZSUXDr\n");
            break;
        }
        case AArch64::FCVTZSUXSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZSUXSr\n");
            break;
        }
        case AArch64::FCVTZS_IntSWDri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZS_IntSWDri\n");
            break;
        }
        case AArch64::FCVTZS_IntSWSri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZS_IntSWSri\n");
            break;
        }
        case AArch64::FCVTZS_IntSXDri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZS_IntSXDri\n");
            break;
        }
        case AArch64::FCVTZS_IntSXSri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZS_IntSXSri\n");
            break;
        }
        case AArch64::FCVTZS_IntUWDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZS_IntUWDr\n");
            break;
        }
        case AArch64::FCVTZS_IntUWSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZS_IntUWSr\n");
            break;
        }
        case AArch64::FCVTZS_IntUXDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZS_IntUXDr\n");
            break;
        }
        case AArch64::FCVTZS_IntUXSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZS_IntUXSr\n");
            break;
        }
        case AArch64::FCVTZS_Intv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZS_Intv2f32\n");
            break;
        }
        case AArch64::FCVTZS_Intv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZS_Intv2f64\n");
            break;
        }
        case AArch64::FCVTZS_Intv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZS_Intv4f32\n");
            break;
        }
        case AArch64::FCVTZSd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZSd\n");
            break;
        }
        case AArch64::FCVTZSs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZSs\n");
            break;
        }
        case AArch64::FCVTZSv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZSv1i32\n");
            break;
        }
        case AArch64::FCVTZSv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZSv1i64\n");
            break;
        }
        case AArch64::FCVTZSv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZSv2f32\n");
            break;
        }
        case AArch64::FCVTZSv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZSv2f64\n");
            break;
        }
        case AArch64::FCVTZSv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZSv2i32_shift\n");
            break;
        }
        case AArch64::FCVTZSv2i64_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZSv2i64_shift\n");
            break;
        }
        case AArch64::FCVTZSv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZSv4f32\n");
            break;
        }
        case AArch64::FCVTZSv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZSv4i32_shift\n");
            break;
        }
        case AArch64::FCVTZUSWDri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZUSWDri\n");
            break;
        }
        case AArch64::FCVTZUSWSri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZUSWSri\n");
            break;
        }
        case AArch64::FCVTZUSXDri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZUSXDri\n");
            break;
        }
        case AArch64::FCVTZUSXSri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZUSXSri\n");
            break;
        }
        case AArch64::FCVTZUUWDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZUUWDr\n");
            break;
        }
        case AArch64::FCVTZUUWSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZUUWSr\n");
            break;
        }
        case AArch64::FCVTZUUXDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZUUXDr\n");
            break;
        }
        case AArch64::FCVTZUUXSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZUUXSr\n");
            break;
        }
        case AArch64::FCVTZU_IntSWDri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZU_IntSWDri\n");
            break;
        }
        case AArch64::FCVTZU_IntSWSri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZU_IntSWSri\n");
            break;
        }
        case AArch64::FCVTZU_IntSXDri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZU_IntSXDri\n");
            break;
        }
        case AArch64::FCVTZU_IntSXSri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZU_IntSXSri\n");
            break;
        }
        case AArch64::FCVTZU_IntUWDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZU_IntUWDr\n");
            break;
        }
        case AArch64::FCVTZU_IntUWSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZU_IntUWSr\n");
            break;
        }
        case AArch64::FCVTZU_IntUXDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZU_IntUXDr\n");
            break;
        }
        case AArch64::FCVTZU_IntUXSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZU_IntUXSr\n");
            break;
        }
        case AArch64::FCVTZU_Intv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZU_Intv2f32\n");
            break;
        }
        case AArch64::FCVTZU_Intv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZU_Intv2f64\n");
            break;
        }
        case AArch64::FCVTZU_Intv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZU_Intv4f32\n");
            break;
        }
        case AArch64::FCVTZUd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZUd\n");
            break;
        }
        case AArch64::FCVTZUs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZUs\n");
            break;
        }
        case AArch64::FCVTZUv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZUv1i32\n");
            break;
        }
        case AArch64::FCVTZUv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZUv1i64\n");
            break;
        }
        case AArch64::FCVTZUv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZUv2f32\n");
            break;
        }
        case AArch64::FCVTZUv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZUv2f64\n");
            break;
        }
        case AArch64::FCVTZUv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZUv2i32_shift\n");
            break;
        }
        case AArch64::FCVTZUv2i64_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZUv2i64_shift\n");
            break;
        }
        case AArch64::FCVTZUv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZUv4f32\n");
            break;
        }
        case AArch64::FCVTZUv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FCVTZUv4i32_shift\n");
            break;
        }
        case AArch64::FDIVDrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FDIVDrr\n");
            break;
        }
        case AArch64::FDIVSrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FDIVSrr\n");
            break;
        }
        case AArch64::FDIVv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FDIVv2f32\n");
            break;
        }
        case AArch64::FDIVv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FDIVv2f64\n");
            break;
        }
        case AArch64::FDIVv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FDIVv4f32\n");
            break;
        }
        case AArch64::FMADDDrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMADDDrrr\n");
            break;
        }
        case AArch64::FMADDSrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMADDSrrr\n");
            break;
        }
        case AArch64::FMAXDrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXDrr\n");
            break;
        }
        case AArch64::FMAXNMDrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXNMDrr\n");
            break;
        }
        case AArch64::FMAXNMPv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXNMPv2f32\n");
            break;
        }
        case AArch64::FMAXNMPv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXNMPv2f64\n");
            break;
        }
        case AArch64::FMAXNMPv2i32p: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXNMPv2i32p\n");
            break;
        }
        case AArch64::FMAXNMPv2i64p: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXNMPv2i64p\n");
            break;
        }
        case AArch64::FMAXNMPv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXNMPv4f32\n");
            break;
        }
        case AArch64::FMAXNMSrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXNMSrr\n");
            break;
        }
        case AArch64::FMAXNMVv4i32v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXNMVv4i32v\n");
            break;
        }
        case AArch64::FMAXNMv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXNMv2f32\n");
            break;
        }
        case AArch64::FMAXNMv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXNMv2f64\n");
            break;
        }
        case AArch64::FMAXNMv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXNMv4f32\n");
            break;
        }
        case AArch64::FMAXPv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXPv2f32\n");
            break;
        }
        case AArch64::FMAXPv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXPv2f64\n");
            break;
        }
        case AArch64::FMAXPv2i32p: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXPv2i32p\n");
            break;
        }
        case AArch64::FMAXPv2i64p: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXPv2i64p\n");
            break;
        }
        case AArch64::FMAXPv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXPv4f32\n");
            break;
        }
        case AArch64::FMAXSrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXSrr\n");
            break;
        }
        case AArch64::FMAXVv4i32v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXVv4i32v\n");
            break;
        }
        case AArch64::FMAXv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXv2f32\n");
            break;
        }
        case AArch64::FMAXv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXv2f64\n");
            break;
        }
        case AArch64::FMAXv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMAXv4f32\n");
            break;
        }
        case AArch64::FMINDrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINDrr\n");
            break;
        }
        case AArch64::FMINNMDrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINNMDrr\n");
            break;
        }
        case AArch64::FMINNMPv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINNMPv2f32\n");
            break;
        }
        case AArch64::FMINNMPv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINNMPv2f64\n");
            break;
        }
        case AArch64::FMINNMPv2i32p: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINNMPv2i32p\n");
            break;
        }
        case AArch64::FMINNMPv2i64p: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINNMPv2i64p\n");
            break;
        }
        case AArch64::FMINNMPv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINNMPv4f32\n");
            break;
        }
        case AArch64::FMINNMSrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINNMSrr\n");
            break;
        }
        case AArch64::FMINNMVv4i32v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINNMVv4i32v\n");
            break;
        }
        case AArch64::FMINNMv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINNMv2f32\n");
            break;
        }
        case AArch64::FMINNMv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINNMv2f64\n");
            break;
        }
        case AArch64::FMINNMv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINNMv4f32\n");
            break;
        }
        case AArch64::FMINPv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINPv2f32\n");
            break;
        }
        case AArch64::FMINPv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINPv2f64\n");
            break;
        }
        case AArch64::FMINPv2i32p: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINPv2i32p\n");
            break;
        }
        case AArch64::FMINPv2i64p: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINPv2i64p\n");
            break;
        }
        case AArch64::FMINPv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINPv4f32\n");
            break;
        }
        case AArch64::FMINSrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINSrr\n");
            break;
        }
        case AArch64::FMINVv4i32v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINVv4i32v\n");
            break;
        }
        case AArch64::FMINv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINv2f32\n");
            break;
        }
        case AArch64::FMINv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINv2f64\n");
            break;
        }
        case AArch64::FMINv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMINv4f32\n");
            break;
        }
        case AArch64::FMLAv1i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMLAv1i32_indexed\n");
            break;
        }
        case AArch64::FMLAv1i64_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMLAv1i64_indexed\n");
            break;
        }
        case AArch64::FMLAv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMLAv2f32\n");
            break;
        }
        case AArch64::FMLAv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMLAv2f64\n");
            break;
        }
        case AArch64::FMLAv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMLAv2i32_indexed\n");
            break;
        }
        case AArch64::FMLAv2i64_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMLAv2i64_indexed\n");
            break;
        }
        case AArch64::FMLAv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMLAv4f32\n");
            break;
        }
        case AArch64::FMLAv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMLAv4i32_indexed\n");
            break;
        }
        case AArch64::FMLSv1i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMLSv1i32_indexed\n");
            break;
        }
        case AArch64::FMLSv1i64_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMLSv1i64_indexed\n");
            break;
        }
        case AArch64::FMLSv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMLSv2f32\n");
            break;
        }
        case AArch64::FMLSv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMLSv2f64\n");
            break;
        }
        case AArch64::FMLSv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMLSv2i32_indexed\n");
            break;
        }
        case AArch64::FMLSv2i64_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMLSv2i64_indexed\n");
            break;
        }
        case AArch64::FMLSv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMLSv4f32\n");
            break;
        }
        case AArch64::FMLSv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMLSv4i32_indexed\n");
            break;
        }
        case AArch64::FMOVD0: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMOVD0\n");
            break;
        }
        case AArch64::FMOVDXHighr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMOVDXHighr\n");
            break;
        }
        case AArch64::FMOVDXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMOVDXr\n");
            break;
        }
        case AArch64::FMOVDi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMOVDi\n");
            break;
        }
        case AArch64::FMOVDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMOVDr\n");
            break;
        }
        case AArch64::FMOVS0: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMOVS0\n");
            break;
        }
        case AArch64::FMOVSWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMOVSWr\n");
            break;
        }
        case AArch64::FMOVSi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMOVSi\n");
            break;
        }
        case AArch64::FMOVSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMOVSr\n");
            break;
        }
        case AArch64::FMOVWSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMOVWSr\n");
            break;
        }
        case AArch64::FMOVXDHighr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMOVXDHighr\n");
            break;
        }
        case AArch64::FMOVXDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMOVXDr\n");
            break;
        }
        case AArch64::FMOVv2f32_ns: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMOVv2f32_ns\n");
            break;
        }
        case AArch64::FMOVv2f64_ns: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMOVv2f64_ns\n");
            break;
        }
        case AArch64::FMOVv4f32_ns: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMOVv4f32_ns\n");
            break;
        }
        case AArch64::FMSUBDrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMSUBDrrr\n");
            break;
        }
        case AArch64::FMSUBSrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMSUBSrrr\n");
            break;
        }
        case AArch64::FMULDrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULDrr\n");
            break;
        }
        case AArch64::FMULSrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULSrr\n");
            break;
        }
        case AArch64::FMULX32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULX32\n");
            break;
        }
        case AArch64::FMULX64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULX64\n");
            break;
        }
        case AArch64::FMULXv1i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULXv1i32_indexed\n");
            break;
        }
        case AArch64::FMULXv1i64_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULXv1i64_indexed\n");
            break;
        }
        case AArch64::FMULXv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULXv2f32\n");
            break;
        }
        case AArch64::FMULXv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULXv2f64\n");
            break;
        }
        case AArch64::FMULXv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULXv2i32_indexed\n");
            break;
        }
        case AArch64::FMULXv2i64_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULXv2i64_indexed\n");
            break;
        }
        case AArch64::FMULXv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULXv4f32\n");
            break;
        }
        case AArch64::FMULXv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULXv4i32_indexed\n");
            break;
        }
        case AArch64::FMULv1i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULv1i32_indexed\n");
            break;
        }
        case AArch64::FMULv1i64_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULv1i64_indexed\n");
            break;
        }
        case AArch64::FMULv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULv2f32\n");
            break;
        }
        case AArch64::FMULv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULv2f64\n");
            break;
        }
        case AArch64::FMULv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULv2i32_indexed\n");
            break;
        }
        case AArch64::FMULv2i64_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULv2i64_indexed\n");
            break;
        }
        case AArch64::FMULv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULv4f32\n");
            break;
        }
        case AArch64::FMULv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FMULv4i32_indexed\n");
            break;
        }
        case AArch64::FNEGDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FNEGDr\n");
            break;
        }
        case AArch64::FNEGSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FNEGSr\n");
            break;
        }
        case AArch64::FNEGv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FNEGv2f32\n");
            break;
        }
        case AArch64::FNEGv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FNEGv2f64\n");
            break;
        }
        case AArch64::FNEGv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FNEGv4f32\n");
            break;
        }
        case AArch64::FNMADDDrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FNMADDDrrr\n");
            break;
        }
        case AArch64::FNMADDSrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FNMADDSrrr\n");
            break;
        }
        case AArch64::FNMSUBDrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FNMSUBDrrr\n");
            break;
        }
        case AArch64::FNMSUBSrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FNMSUBSrrr\n");
            break;
        }
        case AArch64::FNMULDrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FNMULDrr\n");
            break;
        }
        case AArch64::FNMULSrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FNMULSrr\n");
            break;
        }
        case AArch64::FRECPEv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRECPEv1i32\n");
            break;
        }
        case AArch64::FRECPEv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRECPEv1i64\n");
            break;
        }
        case AArch64::FRECPEv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRECPEv2f32\n");
            break;
        }
        case AArch64::FRECPEv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRECPEv2f64\n");
            break;
        }
        case AArch64::FRECPEv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRECPEv4f32\n");
            break;
        }
        case AArch64::FRECPS32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRECPS32\n");
            break;
        }
        case AArch64::FRECPS64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRECPS64\n");
            break;
        }
        case AArch64::FRECPSv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRECPSv2f32\n");
            break;
        }
        case AArch64::FRECPSv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRECPSv2f64\n");
            break;
        }
        case AArch64::FRECPSv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRECPSv4f32\n");
            break;
        }
        case AArch64::FRECPXv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRECPXv1i32\n");
            break;
        }
        case AArch64::FRECPXv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRECPXv1i64\n");
            break;
        }
        case AArch64::FRINTADr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTADr\n");
            break;
        }
        case AArch64::FRINTASr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTASr\n");
            break;
        }
        case AArch64::FRINTAv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTAv2f32\n");
            break;
        }
        case AArch64::FRINTAv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTAv2f64\n");
            break;
        }
        case AArch64::FRINTAv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTAv4f32\n");
            break;
        }
        case AArch64::FRINTIDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTIDr\n");
            break;
        }
        case AArch64::FRINTISr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTISr\n");
            break;
        }
        case AArch64::FRINTIv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTIv2f32\n");
            break;
        }
        case AArch64::FRINTIv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTIv2f64\n");
            break;
        }
        case AArch64::FRINTIv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTIv4f32\n");
            break;
        }
        case AArch64::FRINTMDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTMDr\n");
            break;
        }
        case AArch64::FRINTMSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTMSr\n");
            break;
        }
        case AArch64::FRINTMv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTMv2f32\n");
            break;
        }
        case AArch64::FRINTMv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTMv2f64\n");
            break;
        }
        case AArch64::FRINTMv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTMv4f32\n");
            break;
        }
        case AArch64::FRINTNDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTNDr\n");
            break;
        }
        case AArch64::FRINTNSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTNSr\n");
            break;
        }
        case AArch64::FRINTNv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTNv2f32\n");
            break;
        }
        case AArch64::FRINTNv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTNv2f64\n");
            break;
        }
        case AArch64::FRINTNv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTNv4f32\n");
            break;
        }
        case AArch64::FRINTPDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTPDr\n");
            break;
        }
        case AArch64::FRINTPSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTPSr\n");
            break;
        }
        case AArch64::FRINTPv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTPv2f32\n");
            break;
        }
        case AArch64::FRINTPv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTPv2f64\n");
            break;
        }
        case AArch64::FRINTPv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTPv4f32\n");
            break;
        }
        case AArch64::FRINTXDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTXDr\n");
            break;
        }
        case AArch64::FRINTXSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTXSr\n");
            break;
        }
        case AArch64::FRINTXv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTXv2f32\n");
            break;
        }
        case AArch64::FRINTXv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTXv2f64\n");
            break;
        }
        case AArch64::FRINTXv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTXv4f32\n");
            break;
        }
        case AArch64::FRINTZDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTZDr\n");
            break;
        }
        case AArch64::FRINTZSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTZSr\n");
            break;
        }
        case AArch64::FRINTZv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTZv2f32\n");
            break;
        }
        case AArch64::FRINTZv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTZv2f64\n");
            break;
        }
        case AArch64::FRINTZv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRINTZv4f32\n");
            break;
        }
        case AArch64::FRSQRTEv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRSQRTEv1i32\n");
            break;
        }
        case AArch64::FRSQRTEv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRSQRTEv1i64\n");
            break;
        }
        case AArch64::FRSQRTEv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRSQRTEv2f32\n");
            break;
        }
        case AArch64::FRSQRTEv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRSQRTEv2f64\n");
            break;
        }
        case AArch64::FRSQRTEv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRSQRTEv4f32\n");
            break;
        }
        case AArch64::FRSQRTS32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRSQRTS32\n");
            break;
        }
        case AArch64::FRSQRTS64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRSQRTS64\n");
            break;
        }
        case AArch64::FRSQRTSv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRSQRTSv2f32\n");
            break;
        }
        case AArch64::FRSQRTSv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRSQRTSv2f64\n");
            break;
        }
        case AArch64::FRSQRTSv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FRSQRTSv4f32\n");
            break;
        }
        case AArch64::FSQRTDr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FSQRTDr\n");
            break;
        }
        case AArch64::FSQRTSr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FSQRTSr\n");
            break;
        }
        case AArch64::FSQRTv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FSQRTv2f32\n");
            break;
        }
        case AArch64::FSQRTv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FSQRTv2f64\n");
            break;
        }
        case AArch64::FSQRTv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FSQRTv4f32\n");
            break;
        }
        case AArch64::FSUBDrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FSUBDrr\n");
            break;
        }
        case AArch64::FSUBSrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FSUBSrr\n");
            break;
        }
        case AArch64::FSUBv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FSUBv2f32\n");
            break;
        }
        case AArch64::FSUBv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FSUBv2f64\n");
            break;
        }
        case AArch64::FSUBv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " FSUBv4f32\n");
            break;
        }
        case AArch64::HINT: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " HINT\n");
            break;
        }
        case AArch64::HLT: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " HLT\n");
            break;
        }
        case AArch64::HVC: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " HVC\n");
            break;
        }
        case AArch64::INSvi16gpr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " INSvi16gpr\n");
            break;
        }
        case AArch64::INSvi16lane: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " INSvi16lane\n");
            break;
        }
        case AArch64::INSvi32gpr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " INSvi32gpr\n");
            break;
        }
        case AArch64::INSvi32lane: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " INSvi32lane\n");
            break;
        }
        case AArch64::INSvi64gpr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " INSvi64gpr\n");
            break;
        }
        case AArch64::INSvi64lane: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " INSvi64lane\n");
            break;
        }
        case AArch64::INSvi8gpr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " INSvi8gpr\n");
            break;
        }
        case AArch64::INSvi8lane: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " INSvi8lane\n");
            break;
        }
        case AArch64::ISB: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ISB\n");
            break;
        }
        case AArch64::LD1Fourv16b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Fourv16b\n");
            break;
        }
        case AArch64::LD1Fourv16b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Fourv16b_POST\n");
            break;
        }
        case AArch64::LD1Fourv1d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Fourv1d\n");
            break;
        }
        case AArch64::LD1Fourv1d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Fourv1d_POST\n");
            break;
        }
        case AArch64::LD1Fourv2d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Fourv2d\n");
            break;
        }
        case AArch64::LD1Fourv2d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Fourv2d_POST\n");
            break;
        }
        case AArch64::LD1Fourv2s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Fourv2s\n");
            break;
        }
        case AArch64::LD1Fourv2s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Fourv2s_POST\n");
            break;
        }
        case AArch64::LD1Fourv4h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Fourv4h\n");
            break;
        }
        case AArch64::LD1Fourv4h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Fourv4h_POST\n");
            break;
        }
        case AArch64::LD1Fourv4s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Fourv4s\n");
            break;
        }
        case AArch64::LD1Fourv4s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Fourv4s_POST\n");
            break;
        }
        case AArch64::LD1Fourv8b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Fourv8b\n");
            break;
        }
        case AArch64::LD1Fourv8b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Fourv8b_POST\n");
            break;
        }
        case AArch64::LD1Fourv8h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Fourv8h\n");
            break;
        }
        case AArch64::LD1Fourv8h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Fourv8h_POST\n");
            break;
        }
        case AArch64::LD1Onev16b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Onev16b\n");
            break;
        }
        case AArch64::LD1Onev16b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Onev16b_POST\n");
            break;
        }
        case AArch64::LD1Onev1d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Onev1d\n");
            break;
        }
        case AArch64::LD1Onev1d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Onev1d_POST\n");
            break;
        }
        case AArch64::LD1Onev2d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Onev2d\n");
            break;
        }
        case AArch64::LD1Onev2d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Onev2d_POST\n");
            break;
        }
        case AArch64::LD1Onev2s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Onev2s\n");
            break;
        }
        case AArch64::LD1Onev2s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Onev2s_POST\n");
            break;
        }
        case AArch64::LD1Onev4h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Onev4h\n");
            break;
        }
        case AArch64::LD1Onev4h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Onev4h_POST\n");
            break;
        }
        case AArch64::LD1Onev4s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Onev4s\n");
            break;
        }
        case AArch64::LD1Onev4s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Onev4s_POST\n");
            break;
        }
        case AArch64::LD1Onev8b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Onev8b\n");
            break;
        }
        case AArch64::LD1Onev8b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Onev8b_POST\n");
            break;
        }
        case AArch64::LD1Onev8h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Onev8h\n");
            break;
        }
        case AArch64::LD1Onev8h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Onev8h_POST\n");
            break;
        }
        case AArch64::LD1Rv16b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Rv16b\n");
            break;
        }
        case AArch64::LD1Rv16b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Rv16b_POST\n");
            break;
        }
        case AArch64::LD1Rv1d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Rv1d\n");
            break;
        }
        case AArch64::LD1Rv1d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Rv1d_POST\n");
            break;
        }
        case AArch64::LD1Rv2d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Rv2d\n");
            break;
        }
        case AArch64::LD1Rv2d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Rv2d_POST\n");
            break;
        }
        case AArch64::LD1Rv2s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Rv2s\n");
            break;
        }
        case AArch64::LD1Rv2s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Rv2s_POST\n");
            break;
        }
        case AArch64::LD1Rv4h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Rv4h\n");
            break;
        }
        case AArch64::LD1Rv4h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Rv4h_POST\n");
            break;
        }
        case AArch64::LD1Rv4s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Rv4s\n");
            break;
        }
        case AArch64::LD1Rv4s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Rv4s_POST\n");
            break;
        }
        case AArch64::LD1Rv8b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Rv8b\n");
            break;
        }
        case AArch64::LD1Rv8b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Rv8b_POST\n");
            break;
        }
        case AArch64::LD1Rv8h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Rv8h\n");
            break;
        }
        case AArch64::LD1Rv8h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Rv8h_POST\n");
            break;
        }
        case AArch64::LD1Threev16b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Threev16b\n");
            break;
        }
        case AArch64::LD1Threev16b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Threev16b_POST\n");
            break;
        }
        case AArch64::LD1Threev1d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Threev1d\n");
            break;
        }
        case AArch64::LD1Threev1d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Threev1d_POST\n");
            break;
        }
        case AArch64::LD1Threev2d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Threev2d\n");
            break;
        }
        case AArch64::LD1Threev2d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Threev2d_POST\n");
            break;
        }
        case AArch64::LD1Threev2s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Threev2s\n");
            break;
        }
        case AArch64::LD1Threev2s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Threev2s_POST\n");
            break;
        }
        case AArch64::LD1Threev4h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Threev4h\n");
            break;
        }
        case AArch64::LD1Threev4h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Threev4h_POST\n");
            break;
        }
        case AArch64::LD1Threev4s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Threev4s\n");
            break;
        }
        case AArch64::LD1Threev4s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Threev4s_POST\n");
            break;
        }
        case AArch64::LD1Threev8b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Threev8b\n");
            break;
        }
        case AArch64::LD1Threev8b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Threev8b_POST\n");
            break;
        }
        case AArch64::LD1Threev8h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Threev8h\n");
            break;
        }
        case AArch64::LD1Threev8h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Threev8h_POST\n");
            break;
        }
        case AArch64::LD1Twov16b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Twov16b\n");
            break;
        }
        case AArch64::LD1Twov16b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Twov16b_POST\n");
            break;
        }
        case AArch64::LD1Twov1d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Twov1d\n");
            break;
        }
        case AArch64::LD1Twov1d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Twov1d_POST\n");
            break;
        }
        case AArch64::LD1Twov2d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Twov2d\n");
            break;
        }
        case AArch64::LD1Twov2d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Twov2d_POST\n");
            break;
        }
        case AArch64::LD1Twov2s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Twov2s\n");
            break;
        }
        case AArch64::LD1Twov2s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Twov2s_POST\n");
            break;
        }
        case AArch64::LD1Twov4h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Twov4h\n");
            break;
        }
        case AArch64::LD1Twov4h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Twov4h_POST\n");
            break;
        }
        case AArch64::LD1Twov4s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Twov4s\n");
            break;
        }
        case AArch64::LD1Twov4s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Twov4s_POST\n");
            break;
        }
        case AArch64::LD1Twov8b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Twov8b\n");
            break;
        }
        case AArch64::LD1Twov8b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Twov8b_POST\n");
            break;
        }
        case AArch64::LD1Twov8h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Twov8h\n");
            break;
        }
        case AArch64::LD1Twov8h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1Twov8h_POST\n");
            break;
        }
        case AArch64::LD1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1i16\n");
            break;
        }
        case AArch64::LD1i16_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1i16_POST\n");
            break;
        }
        case AArch64::LD1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1i32\n");
            break;
        }
        case AArch64::LD1i32_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1i32_POST\n");
            break;
        }
        case AArch64::LD1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1i64\n");
            break;
        }
        case AArch64::LD1i64_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1i64_POST\n");
            break;
        }
        case AArch64::LD1i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1i8\n");
            break;
        }
        case AArch64::LD1i8_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD1i8_POST\n");
            break;
        }
        case AArch64::LD2Rv16b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Rv16b\n");
            break;
        }
        case AArch64::LD2Rv16b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Rv16b_POST\n");
            break;
        }
        case AArch64::LD2Rv1d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Rv1d\n");
            break;
        }
        case AArch64::LD2Rv1d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Rv1d_POST\n");
            break;
        }
        case AArch64::LD2Rv2d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Rv2d\n");
            break;
        }
        case AArch64::LD2Rv2d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Rv2d_POST\n");
            break;
        }
        case AArch64::LD2Rv2s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Rv2s\n");
            break;
        }
        case AArch64::LD2Rv2s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Rv2s_POST\n");
            break;
        }
        case AArch64::LD2Rv4h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Rv4h\n");
            break;
        }
        case AArch64::LD2Rv4h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Rv4h_POST\n");
            break;
        }
        case AArch64::LD2Rv4s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Rv4s\n");
            break;
        }
        case AArch64::LD2Rv4s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Rv4s_POST\n");
            break;
        }
        case AArch64::LD2Rv8b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Rv8b\n");
            break;
        }
        case AArch64::LD2Rv8b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Rv8b_POST\n");
            break;
        }
        case AArch64::LD2Rv8h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Rv8h\n");
            break;
        }
        case AArch64::LD2Rv8h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Rv8h_POST\n");
            break;
        }
        case AArch64::LD2Twov16b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Twov16b\n");
            break;
        }
        case AArch64::LD2Twov16b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Twov16b_POST\n");
            break;
        }
        case AArch64::LD2Twov2d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Twov2d\n");
            break;
        }
        case AArch64::LD2Twov2d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Twov2d_POST\n");
            break;
        }
        case AArch64::LD2Twov2s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Twov2s\n");
            break;
        }
        case AArch64::LD2Twov2s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Twov2s_POST\n");
            break;
        }
        case AArch64::LD2Twov4h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Twov4h\n");
            break;
        }
        case AArch64::LD2Twov4h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Twov4h_POST\n");
            break;
        }
        case AArch64::LD2Twov4s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Twov4s\n");
            break;
        }
        case AArch64::LD2Twov4s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Twov4s_POST\n");
            break;
        }
        case AArch64::LD2Twov8b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Twov8b\n");
            break;
        }
        case AArch64::LD2Twov8b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Twov8b_POST\n");
            break;
        }
        case AArch64::LD2Twov8h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Twov8h\n");
            break;
        }
        case AArch64::LD2Twov8h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2Twov8h_POST\n");
            break;
        }
        case AArch64::LD2i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2i16\n");
            break;
        }
        case AArch64::LD2i16_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2i16_POST\n");
            break;
        }
        case AArch64::LD2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2i32\n");
            break;
        }
        case AArch64::LD2i32_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2i32_POST\n");
            break;
        }
        case AArch64::LD2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2i64\n");
            break;
        }
        case AArch64::LD2i64_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2i64_POST\n");
            break;
        }
        case AArch64::LD2i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2i8\n");
            break;
        }
        case AArch64::LD2i8_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD2i8_POST\n");
            break;
        }
        case AArch64::LD3Rv16b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Rv16b\n");
            break;
        }
        case AArch64::LD3Rv16b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Rv16b_POST\n");
            break;
        }
        case AArch64::LD3Rv1d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Rv1d\n");
            break;
        }
        case AArch64::LD3Rv1d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Rv1d_POST\n");
            break;
        }
        case AArch64::LD3Rv2d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Rv2d\n");
            break;
        }
        case AArch64::LD3Rv2d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Rv2d_POST\n");
            break;
        }
        case AArch64::LD3Rv2s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Rv2s\n");
            break;
        }
        case AArch64::LD3Rv2s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Rv2s_POST\n");
            break;
        }
        case AArch64::LD3Rv4h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Rv4h\n");
            break;
        }
        case AArch64::LD3Rv4h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Rv4h_POST\n");
            break;
        }
        case AArch64::LD3Rv4s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Rv4s\n");
            break;
        }
        case AArch64::LD3Rv4s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Rv4s_POST\n");
            break;
        }
        case AArch64::LD3Rv8b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Rv8b\n");
            break;
        }
        case AArch64::LD3Rv8b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Rv8b_POST\n");
            break;
        }
        case AArch64::LD3Rv8h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Rv8h\n");
            break;
        }
        case AArch64::LD3Rv8h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Rv8h_POST\n");
            break;
        }
        case AArch64::LD3Threev16b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Threev16b\n");
            break;
        }
        case AArch64::LD3Threev16b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Threev16b_POST\n");
            break;
        }
        case AArch64::LD3Threev2d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Threev2d\n");
            break;
        }
        case AArch64::LD3Threev2d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Threev2d_POST\n");
            break;
        }
        case AArch64::LD3Threev2s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Threev2s\n");
            break;
        }
        case AArch64::LD3Threev2s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Threev2s_POST\n");
            break;
        }
        case AArch64::LD3Threev4h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Threev4h\n");
            break;
        }
        case AArch64::LD3Threev4h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Threev4h_POST\n");
            break;
        }
        case AArch64::LD3Threev4s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Threev4s\n");
            break;
        }
        case AArch64::LD3Threev4s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Threev4s_POST\n");
            break;
        }
        case AArch64::LD3Threev8b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Threev8b\n");
            break;
        }
        case AArch64::LD3Threev8b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Threev8b_POST\n");
            break;
        }
        case AArch64::LD3Threev8h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Threev8h\n");
            break;
        }
        case AArch64::LD3Threev8h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3Threev8h_POST\n");
            break;
        }
        case AArch64::LD3i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3i16\n");
            break;
        }
        case AArch64::LD3i16_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3i16_POST\n");
            break;
        }
        case AArch64::LD3i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3i32\n");
            break;
        }
        case AArch64::LD3i32_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3i32_POST\n");
            break;
        }
        case AArch64::LD3i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3i64\n");
            break;
        }
        case AArch64::LD3i64_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3i64_POST\n");
            break;
        }
        case AArch64::LD3i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3i8\n");
            break;
        }
        case AArch64::LD3i8_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD3i8_POST\n");
            break;
        }
        case AArch64::LD4Fourv16b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Fourv16b\n");
            break;
        }
        case AArch64::LD4Fourv16b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Fourv16b_POST\n");
            break;
        }
        case AArch64::LD4Fourv2d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Fourv2d\n");
            break;
        }
        case AArch64::LD4Fourv2d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Fourv2d_POST\n");
            break;
        }
        case AArch64::LD4Fourv2s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Fourv2s\n");
            break;
        }
        case AArch64::LD4Fourv2s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Fourv2s_POST\n");
            break;
        }
        case AArch64::LD4Fourv4h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Fourv4h\n");
            break;
        }
        case AArch64::LD4Fourv4h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Fourv4h_POST\n");
            break;
        }
        case AArch64::LD4Fourv4s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Fourv4s\n");
            break;
        }
        case AArch64::LD4Fourv4s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Fourv4s_POST\n");
            break;
        }
        case AArch64::LD4Fourv8b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Fourv8b\n");
            break;
        }
        case AArch64::LD4Fourv8b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Fourv8b_POST\n");
            break;
        }
        case AArch64::LD4Fourv8h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Fourv8h\n");
            break;
        }
        case AArch64::LD4Fourv8h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Fourv8h_POST\n");
            break;
        }
        case AArch64::LD4Rv16b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Rv16b\n");
            break;
        }
        case AArch64::LD4Rv16b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Rv16b_POST\n");
            break;
        }
        case AArch64::LD4Rv1d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Rv1d\n");
            break;
        }
        case AArch64::LD4Rv1d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Rv1d_POST\n");
            break;
        }
        case AArch64::LD4Rv2d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Rv2d\n");
            break;
        }
        case AArch64::LD4Rv2d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Rv2d_POST\n");
            break;
        }
        case AArch64::LD4Rv2s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Rv2s\n");
            break;
        }
        case AArch64::LD4Rv2s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Rv2s_POST\n");
            break;
        }
        case AArch64::LD4Rv4h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Rv4h\n");
            break;
        }
        case AArch64::LD4Rv4h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Rv4h_POST\n");
            break;
        }
        case AArch64::LD4Rv4s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Rv4s\n");
            break;
        }
        case AArch64::LD4Rv4s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Rv4s_POST\n");
            break;
        }
        case AArch64::LD4Rv8b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Rv8b\n");
            break;
        }
        case AArch64::LD4Rv8b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Rv8b_POST\n");
            break;
        }
        case AArch64::LD4Rv8h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Rv8h\n");
            break;
        }
        case AArch64::LD4Rv8h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4Rv8h_POST\n");
            break;
        }
        case AArch64::LD4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4i16\n");
            break;
        }
        case AArch64::LD4i16_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4i16_POST\n");
            break;
        }
        case AArch64::LD4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4i32\n");
            break;
        }
        case AArch64::LD4i32_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4i32_POST\n");
            break;
        }
        case AArch64::LD4i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4i64\n");
            break;
        }
        case AArch64::LD4i64_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4i64_POST\n");
            break;
        }
        case AArch64::LD4i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4i8\n");
            break;
        }
        case AArch64::LD4i8_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LD4i8_POST\n");
            break;
        }
        case AArch64::LDADDALb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDADDALb\n");
            break;
        }
        case AArch64::LDADDALd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDADDALd\n");
            break;
        }
        case AArch64::LDADDALh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDADDALh\n");
            break;
        }
        case AArch64::LDADDALs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDADDALs\n");
            break;
        }
        case AArch64::LDADDAb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDADDAb\n");
            break;
        }
        case AArch64::LDADDAd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDADDAd\n");
            break;
        }
        case AArch64::LDADDAh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDADDAh\n");
            break;
        }
        case AArch64::LDADDAs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDADDAs\n");
            break;
        }
        case AArch64::LDADDLb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDADDLb\n");
            break;
        }
        case AArch64::LDADDLd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDADDLd\n");
            break;
        }
        case AArch64::LDADDLh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDADDLh\n");
            break;
        }
        case AArch64::LDADDLs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDADDLs\n");
            break;
        }
        case AArch64::LDADDb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDADDb\n");
            break;
        }
        case AArch64::LDADDd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDADDd\n");
            break;
        }
        case AArch64::LDADDh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDADDh\n");
            break;
        }
        case AArch64::LDADDs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDADDs\n");
            break;
        }
        case AArch64::LDARB: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDARB\n");
            break;
        }
        case AArch64::LDARH: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDARH\n");
            break;
        }
        case AArch64::LDARW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDARW\n");
            break;
        }
        case AArch64::LDARX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDARX\n");
            break;
        }
        case AArch64::LDAXPW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDAXPW\n");
            break;
        }
        case AArch64::LDAXPX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDAXPX\n");
            break;
        }
        case AArch64::LDAXRB: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDAXRB\n");
            break;
        }
        case AArch64::LDAXRH: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDAXRH\n");
            break;
        }
        case AArch64::LDAXRW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDAXRW\n");
            break;
        }
        case AArch64::LDAXRX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDAXRX\n");
            break;
        }
        case AArch64::LDCLRALb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDCLRALb\n");
            break;
        }
        case AArch64::LDCLRALd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDCLRALd\n");
            break;
        }
        case AArch64::LDCLRALh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDCLRALh\n");
            break;
        }
        case AArch64::LDCLRALs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDCLRALs\n");
            break;
        }
        case AArch64::LDCLRAb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDCLRAb\n");
            break;
        }
        case AArch64::LDCLRAd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDCLRAd\n");
            break;
        }
        case AArch64::LDCLRAh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDCLRAh\n");
            break;
        }
        case AArch64::LDCLRAs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDCLRAs\n");
            break;
        }
        case AArch64::LDCLRLb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDCLRLb\n");
            break;
        }
        case AArch64::LDCLRLd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDCLRLd\n");
            break;
        }
        case AArch64::LDCLRLh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDCLRLh\n");
            break;
        }
        case AArch64::LDCLRLs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDCLRLs\n");
            break;
        }
        case AArch64::LDCLRb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDCLRb\n");
            break;
        }
        case AArch64::LDCLRd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDCLRd\n");
            break;
        }
        case AArch64::LDCLRh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDCLRh\n");
            break;
        }
        case AArch64::LDCLRs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDCLRs\n");
            break;
        }
        case AArch64::LDEORALb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDEORALb\n");
            break;
        }
        case AArch64::LDEORALd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDEORALd\n");
            break;
        }
        case AArch64::LDEORALh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDEORALh\n");
            break;
        }
        case AArch64::LDEORALs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDEORALs\n");
            break;
        }
        case AArch64::LDEORAb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDEORAb\n");
            break;
        }
        case AArch64::LDEORAd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDEORAd\n");
            break;
        }
        case AArch64::LDEORAh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDEORAh\n");
            break;
        }
        case AArch64::LDEORAs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDEORAs\n");
            break;
        }
        case AArch64::LDEORLb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDEORLb\n");
            break;
        }
        case AArch64::LDEORLd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDEORLd\n");
            break;
        }
        case AArch64::LDEORLh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDEORLh\n");
            break;
        }
        case AArch64::LDEORLs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDEORLs\n");
            break;
        }
        case AArch64::LDEORb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDEORb\n");
            break;
        }
        case AArch64::LDEORd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDEORd\n");
            break;
        }
        case AArch64::LDEORh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDEORh\n");
            break;
        }
        case AArch64::LDEORs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDEORs\n");
            break;
        }
        case AArch64::LDLARB: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDLARB\n");
            break;
        }
        case AArch64::LDLARH: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDLARH\n");
            break;
        }
        case AArch64::LDLARW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDLARW\n");
            break;
        }
        case AArch64::LDLARX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDLARX\n");
            break;
        }
        case AArch64::LDNPDi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDNPDi\n");
            break;
        }
        case AArch64::LDNPQi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDNPQi\n");
            break;
        }
        case AArch64::LDNPSi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDNPSi\n");
            break;
        }
        case AArch64::LDNPWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDNPWi\n");
            break;
        }
        case AArch64::LDNPXi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDNPXi\n");
            break;
        }
        case AArch64::LDPDi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDPDi\n");
            break;
        }
        case AArch64::LDPDpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDPDpost\n");
            break;
        }
        case AArch64::LDPDpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDPDpre\n");
            break;
        }
        case AArch64::LDPQi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDPQi\n");
            break;
        }
        case AArch64::LDPQpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDPQpost\n");
            break;
        }
        case AArch64::LDPQpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDPQpre\n");
            break;
        }
        case AArch64::LDPSWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDPSWi\n");
            break;
        }
        case AArch64::LDPSWpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDPSWpost\n");
            break;
        }
        case AArch64::LDPSWpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDPSWpre\n");
            break;
        }
        case AArch64::LDPSi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDPSi\n");
            break;
        }
        case AArch64::LDPSpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDPSpost\n");
            break;
        }
        case AArch64::LDPSpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDPSpre\n");
            break;
        }
        case AArch64::LDPWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDPWi\n");
            break;
        }
        case AArch64::LDPWpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDPWpost\n");
            break;
        }
        case AArch64::LDPWpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDPWpre\n");
            break;
        }
        case AArch64::LDPXi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDPXi\n");
            break;
        }
        case AArch64::LDPXpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDPXpost\n");
            break;
        }
        case AArch64::LDPXpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDPXpre\n");
            break;
        }
        case AArch64::LDRBBpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRBBpost\n");
            break;
        }
        case AArch64::LDRBBpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRBBpre\n");
            break;
        }
        case AArch64::LDRBBroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRBBroW\n");
            break;
        }
        case AArch64::LDRBBroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRBBroX\n");
            break;
        }
        case AArch64::LDRBBui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRBBui\n");
            break;
        }
        case AArch64::LDRBpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRBpost\n");
            break;
        }
        case AArch64::LDRBpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRBpre\n");
            break;
        }
        case AArch64::LDRBroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRBroW\n");
            break;
        }
        case AArch64::LDRBroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRBroX\n");
            break;
        }
        case AArch64::LDRBui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRBui\n");
            break;
        }
        case AArch64::LDRDl: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRDl\n");
            break;
        }
        case AArch64::LDRDpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRDpost\n");
            break;
        }
        case AArch64::LDRDpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRDpre\n");
            break;
        }
        case AArch64::LDRDroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRDroW\n");
            break;
        }
        case AArch64::LDRDroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRDroX\n");
            break;
        }
        case AArch64::LDRDui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRDui\n");
            break;
        }
        case AArch64::LDRHHpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRHHpost\n");
            break;
        }
        case AArch64::LDRHHpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRHHpre\n");
            break;
        }
        case AArch64::LDRHHroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRHHroW\n");
            break;
        }
        case AArch64::LDRHHroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRHHroX\n");
            break;
        }
        case AArch64::LDRHHui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRHHui\n");
            break;
        }
        case AArch64::LDRHpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRHpost\n");
            break;
        }
        case AArch64::LDRHpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRHpre\n");
            break;
        }
        case AArch64::LDRHroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRHroW\n");
            break;
        }
        case AArch64::LDRHroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRHroX\n");
            break;
        }
        case AArch64::LDRHui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRHui\n");
            break;
        }
        case AArch64::LDRQl: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRQl\n");
            break;
        }
        case AArch64::LDRQpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRQpost\n");
            break;
        }
        case AArch64::LDRQpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRQpre\n");
            break;
        }
        case AArch64::LDRQroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRQroW\n");
            break;
        }
        case AArch64::LDRQroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRQroX\n");
            break;
        }
        case AArch64::LDRQui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRQui\n");
            break;
        }
        case AArch64::LDRSBWpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSBWpost\n");
            break;
        }
        case AArch64::LDRSBWpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSBWpre\n");
            break;
        }
        case AArch64::LDRSBWroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSBWroW\n");
            break;
        }
        case AArch64::LDRSBWroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSBWroX\n");
            break;
        }
        case AArch64::LDRSBWui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSBWui\n");
            break;
        }
        case AArch64::LDRSBXpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSBXpost\n");
            break;
        }
        case AArch64::LDRSBXpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSBXpre\n");
            break;
        }
        case AArch64::LDRSBXroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSBXroW\n");
            break;
        }
        case AArch64::LDRSBXroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSBXroX\n");
            break;
        }
        case AArch64::LDRSBXui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSBXui\n");
            break;
        }
        case AArch64::LDRSHWpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSHWpost\n");
            break;
        }
        case AArch64::LDRSHWpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSHWpre\n");
            break;
        }
        case AArch64::LDRSHWroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSHWroW\n");
            break;
        }
        case AArch64::LDRSHWroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSHWroX\n");
            break;
        }
        case AArch64::LDRSHWui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSHWui\n");
            break;
        }
        case AArch64::LDRSHXpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSHXpost\n");
            break;
        }
        case AArch64::LDRSHXpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSHXpre\n");
            break;
        }
        case AArch64::LDRSHXroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSHXroW\n");
            break;
        }
        case AArch64::LDRSHXroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSHXroX\n");
            break;
        }
        case AArch64::LDRSHXui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSHXui\n");
            break;
        }
        case AArch64::LDRSWl: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSWl\n");
            break;
        }
        case AArch64::LDRSWpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSWpost\n");
            break;
        }
        case AArch64::LDRSWpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSWpre\n");
            break;
        }
        case AArch64::LDRSWroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSWroW\n");
            break;
        }
        case AArch64::LDRSWroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSWroX\n");
            break;
        }
        case AArch64::LDRSWui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSWui\n");
            break;
        }
        case AArch64::LDRSl: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSl\n");
            break;
        }
        case AArch64::LDRSpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSpost\n");
            break;
        }
        case AArch64::LDRSpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSpre\n");
            break;
        }
        case AArch64::LDRSroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSroW\n");
            break;
        }
        case AArch64::LDRSroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSroX\n");
            break;
        }
        case AArch64::LDRSui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRSui\n");
            break;
        }
        case AArch64::LDRWl: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRWl\n");
            break;
        }
        case AArch64::LDRWpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRWpost\n");
            break;
        }
        case AArch64::LDRWpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRWpre\n");
            break;
        }
        case AArch64::LDRWroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRWroW\n");
            break;
        }
        case AArch64::LDRWroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRWroX\n");
            break;
        }
        case AArch64::LDRWui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRWui\n");
            break;
        }
        case AArch64::LDRXl: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRXl\n");
            break;
        }
        case AArch64::LDRXpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRXpost\n");
            break;
        }
        case AArch64::LDRXpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRXpre\n");
            break;
        }
        case AArch64::LDRXroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRXroW\n");
            break;
        }
        case AArch64::LDRXroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRXroX\n");
            break;
        }
        case AArch64::LDRXui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDRXui\n");
            break;
        }
        case AArch64::LDSETALb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSETALb\n");
            break;
        }
        case AArch64::LDSETALd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSETALd\n");
            break;
        }
        case AArch64::LDSETALh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSETALh\n");
            break;
        }
        case AArch64::LDSETALs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSETALs\n");
            break;
        }
        case AArch64::LDSETAb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSETAb\n");
            break;
        }
        case AArch64::LDSETAd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSETAd\n");
            break;
        }
        case AArch64::LDSETAh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSETAh\n");
            break;
        }
        case AArch64::LDSETAs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSETAs\n");
            break;
        }
        case AArch64::LDSETLb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSETLb\n");
            break;
        }
        case AArch64::LDSETLd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSETLd\n");
            break;
        }
        case AArch64::LDSETLh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSETLh\n");
            break;
        }
        case AArch64::LDSETLs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSETLs\n");
            break;
        }
        case AArch64::LDSETb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSETb\n");
            break;
        }
        case AArch64::LDSETd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSETd\n");
            break;
        }
        case AArch64::LDSETh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSETh\n");
            break;
        }
        case AArch64::LDSETs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSETs\n");
            break;
        }
        case AArch64::LDSMAXALb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMAXALb\n");
            break;
        }
        case AArch64::LDSMAXALd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMAXALd\n");
            break;
        }
        case AArch64::LDSMAXALh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMAXALh\n");
            break;
        }
        case AArch64::LDSMAXALs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMAXALs\n");
            break;
        }
        case AArch64::LDSMAXAb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMAXAb\n");
            break;
        }
        case AArch64::LDSMAXAd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMAXAd\n");
            break;
        }
        case AArch64::LDSMAXAh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMAXAh\n");
            break;
        }
        case AArch64::LDSMAXAs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMAXAs\n");
            break;
        }
        case AArch64::LDSMAXLb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMAXLb\n");
            break;
        }
        case AArch64::LDSMAXLd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMAXLd\n");
            break;
        }
        case AArch64::LDSMAXLh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMAXLh\n");
            break;
        }
        case AArch64::LDSMAXLs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMAXLs\n");
            break;
        }
        case AArch64::LDSMAXb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMAXb\n");
            break;
        }
        case AArch64::LDSMAXd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMAXd\n");
            break;
        }
        case AArch64::LDSMAXh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMAXh\n");
            break;
        }
        case AArch64::LDSMAXs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMAXs\n");
            break;
        }
        case AArch64::LDSMINALb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMINALb\n");
            break;
        }
        case AArch64::LDSMINALd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMINALd\n");
            break;
        }
        case AArch64::LDSMINALh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMINALh\n");
            break;
        }
        case AArch64::LDSMINALs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMINALs\n");
            break;
        }
        case AArch64::LDSMINAb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMINAb\n");
            break;
        }
        case AArch64::LDSMINAd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMINAd\n");
            break;
        }
        case AArch64::LDSMINAh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMINAh\n");
            break;
        }
        case AArch64::LDSMINAs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMINAs\n");
            break;
        }
        case AArch64::LDSMINLb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMINLb\n");
            break;
        }
        case AArch64::LDSMINLd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMINLd\n");
            break;
        }
        case AArch64::LDSMINLh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMINLh\n");
            break;
        }
        case AArch64::LDSMINLs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMINLs\n");
            break;
        }
        case AArch64::LDSMINb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMINb\n");
            break;
        }
        case AArch64::LDSMINd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMINd\n");
            break;
        }
        case AArch64::LDSMINh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMINh\n");
            break;
        }
        case AArch64::LDSMINs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDSMINs\n");
            break;
        }
        case AArch64::LDTRBi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDTRBi\n");
            break;
        }
        case AArch64::LDTRHi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDTRHi\n");
            break;
        }
        case AArch64::LDTRSBWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDTRSBWi\n");
            break;
        }
        case AArch64::LDTRSBXi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDTRSBXi\n");
            break;
        }
        case AArch64::LDTRSHWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDTRSHWi\n");
            break;
        }
        case AArch64::LDTRSHXi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDTRSHXi\n");
            break;
        }
        case AArch64::LDTRSWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDTRSWi\n");
            break;
        }
        case AArch64::LDTRWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDTRWi\n");
            break;
        }
        case AArch64::LDTRXi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDTRXi\n");
            break;
        }
        case AArch64::LDUMAXALb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMAXALb\n");
            break;
        }
        case AArch64::LDUMAXALd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMAXALd\n");
            break;
        }
        case AArch64::LDUMAXALh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMAXALh\n");
            break;
        }
        case AArch64::LDUMAXALs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMAXALs\n");
            break;
        }
        case AArch64::LDUMAXAb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMAXAb\n");
            break;
        }
        case AArch64::LDUMAXAd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMAXAd\n");
            break;
        }
        case AArch64::LDUMAXAh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMAXAh\n");
            break;
        }
        case AArch64::LDUMAXAs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMAXAs\n");
            break;
        }
        case AArch64::LDUMAXLb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMAXLb\n");
            break;
        }
        case AArch64::LDUMAXLd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMAXLd\n");
            break;
        }
        case AArch64::LDUMAXLh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMAXLh\n");
            break;
        }
        case AArch64::LDUMAXLs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMAXLs\n");
            break;
        }
        case AArch64::LDUMAXb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMAXb\n");
            break;
        }
        case AArch64::LDUMAXd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMAXd\n");
            break;
        }
        case AArch64::LDUMAXh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMAXh\n");
            break;
        }
        case AArch64::LDUMAXs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMAXs\n");
            break;
        }
        case AArch64::LDUMINALb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMINALb\n");
            break;
        }
        case AArch64::LDUMINALd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMINALd\n");
            break;
        }
        case AArch64::LDUMINALh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMINALh\n");
            break;
        }
        case AArch64::LDUMINALs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMINALs\n");
            break;
        }
        case AArch64::LDUMINAb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMINAb\n");
            break;
        }
        case AArch64::LDUMINAd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMINAd\n");
            break;
        }
        case AArch64::LDUMINAh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMINAh\n");
            break;
        }
        case AArch64::LDUMINAs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMINAs\n");
            break;
        }
        case AArch64::LDUMINLb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMINLb\n");
            break;
        }
        case AArch64::LDUMINLd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMINLd\n");
            break;
        }
        case AArch64::LDUMINLh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMINLh\n");
            break;
        }
        case AArch64::LDUMINLs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMINLs\n");
            break;
        }
        case AArch64::LDUMINb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMINb\n");
            break;
        }
        case AArch64::LDUMINd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMINd\n");
            break;
        }
        case AArch64::LDUMINh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMINh\n");
            break;
        }
        case AArch64::LDUMINs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDUMINs\n");
            break;
        }
        case AArch64::LDURBBi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDURBBi\n");
            break;
        }
        case AArch64::LDURBi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDURBi\n");
            break;
        }
        case AArch64::LDURDi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDURDi\n");
            break;
        }
        case AArch64::LDURHHi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDURHHi\n");
            break;
        }
        case AArch64::LDURHi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDURHi\n");
            break;
        }
        case AArch64::LDURQi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDURQi\n");
            break;
        }
        case AArch64::LDURSBWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDURSBWi\n");
            break;
        }
        case AArch64::LDURSBXi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDURSBXi\n");
            break;
        }
        case AArch64::LDURSHWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDURSHWi\n");
            break;
        }
        case AArch64::LDURSHXi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDURSHXi\n");
            break;
        }
        case AArch64::LDURSWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDURSWi\n");
            break;
        }
        case AArch64::LDURSi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDURSi\n");
            break;
        }
        case AArch64::LDURWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDURWi\n");
            break;
        }
        case AArch64::LDURXi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDURXi\n");
            break;
        }
        case AArch64::LDXPW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDXPW\n");
            break;
        }
        case AArch64::LDXPX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDXPX\n");
            break;
        }
        case AArch64::LDXRB: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDXRB\n");
            break;
        }
        case AArch64::LDXRH: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDXRH\n");
            break;
        }
        case AArch64::LDXRW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDXRW\n");
            break;
        }
        case AArch64::LDXRX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LDXRX\n");
            break;
        }
        case AArch64::LOADgot: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LOADgot\n");
            break;
        }
        case AArch64::LSLVWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LSLVWr\n");
            break;
        }
        case AArch64::LSLVXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LSLVXr\n");
            break;
        }
        case AArch64::LSRVWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LSRVWr\n");
            break;
        }
        case AArch64::LSRVXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " LSRVXr\n");
            break;
        }
        case AArch64::MADDWrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MADDWrrr\n");
            break;
        }
        case AArch64::MADDXrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MADDXrrr\n");
            break;
        }
        case AArch64::MLAv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLAv16i8\n");
            break;
        }
        case AArch64::MLAv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLAv2i32\n");
            break;
        }
        case AArch64::MLAv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLAv2i32_indexed\n");
            break;
        }
        case AArch64::MLAv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLAv4i16\n");
            break;
        }
        case AArch64::MLAv4i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLAv4i16_indexed\n");
            break;
        }
        case AArch64::MLAv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLAv4i32\n");
            break;
        }
        case AArch64::MLAv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLAv4i32_indexed\n");
            break;
        }
        case AArch64::MLAv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLAv8i16\n");
            break;
        }
        case AArch64::MLAv8i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLAv8i16_indexed\n");
            break;
        }
        case AArch64::MLAv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLAv8i8\n");
            break;
        }
        case AArch64::MLSv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLSv16i8\n");
            break;
        }
        case AArch64::MLSv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLSv2i32\n");
            break;
        }
        case AArch64::MLSv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLSv2i32_indexed\n");
            break;
        }
        case AArch64::MLSv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLSv4i16\n");
            break;
        }
        case AArch64::MLSv4i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLSv4i16_indexed\n");
            break;
        }
        case AArch64::MLSv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLSv4i32\n");
            break;
        }
        case AArch64::MLSv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLSv4i32_indexed\n");
            break;
        }
        case AArch64::MLSv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLSv8i16\n");
            break;
        }
        case AArch64::MLSv8i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLSv8i16_indexed\n");
            break;
        }
        case AArch64::MLSv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MLSv8i8\n");
            break;
        }
        case AArch64::MOVID: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVID\n");
            break;
        }
        case AArch64::MOVIv16b_ns: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVIv16b_ns\n");
            break;
        }
        case AArch64::MOVIv2d_ns: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVIv2d_ns\n");
            break;
        }
        case AArch64::MOVIv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVIv2i32\n");
            break;
        }
        case AArch64::MOVIv2s_msl: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVIv2s_msl\n");
            break;
        }
        case AArch64::MOVIv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVIv4i16\n");
            break;
        }
        case AArch64::MOVIv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVIv4i32\n");
            break;
        }
        case AArch64::MOVIv4s_msl: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVIv4s_msl\n");
            break;
        }
        case AArch64::MOVIv8b_ns: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVIv8b_ns\n");
            break;
        }
        case AArch64::MOVIv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVIv8i16\n");
            break;
        }
        case AArch64::MOVKWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVKWi\n");
            break;
        }
        case AArch64::MOVKXi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVKXi\n");
            break;
        }
        case AArch64::MOVNWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVNWi\n");
            break;
        }
        case AArch64::MOVNXi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVNXi\n");
            break;
        }
        case AArch64::MOVZWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVZWi\n");
            break;
        }
        case AArch64::MOVZXi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVZXi\n");
            break;
        }
        case AArch64::MOVaddr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVaddr\n");
            break;
        }
        case AArch64::MOVaddrBA: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVaddrBA\n");
            break;
        }
        case AArch64::MOVaddrCP: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVaddrCP\n");
            break;
        }
        case AArch64::MOVaddrEXT: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVaddrEXT\n");
            break;
        }
        case AArch64::MOVaddrJT: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVaddrJT\n");
            break;
        }
        case AArch64::MOVaddrTLS: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVaddrTLS\n");
            break;
        }
        case AArch64::MOVi32imm: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVi32imm\n");
            break;
        }
        case AArch64::MOVi64imm: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MOVi64imm\n");
            break;
        }
        case AArch64::MRS: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MRS\n");
            break;
        }
        case AArch64::MSR: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MSR\n");
            break;
        }
        case AArch64::MSRpstate: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MSRpstate\n");
            break;
        }
        case AArch64::MSUBWrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MSUBWrrr\n");
            break;
        }
        case AArch64::MSUBXrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MSUBXrrr\n");
            break;
        }
        case AArch64::MULv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MULv16i8\n");
            break;
        }
        case AArch64::MULv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MULv2i32\n");
            break;
        }
        case AArch64::MULv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MULv2i32_indexed\n");
            break;
        }
        case AArch64::MULv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MULv4i16\n");
            break;
        }
        case AArch64::MULv4i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MULv4i16_indexed\n");
            break;
        }
        case AArch64::MULv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MULv4i32\n");
            break;
        }
        case AArch64::MULv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MULv4i32_indexed\n");
            break;
        }
        case AArch64::MULv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MULv8i16\n");
            break;
        }
        case AArch64::MULv8i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MULv8i16_indexed\n");
            break;
        }
        case AArch64::MULv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MULv8i8\n");
            break;
        }
        case AArch64::MVNIv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MVNIv2i32\n");
            break;
        }
        case AArch64::MVNIv2s_msl: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MVNIv2s_msl\n");
            break;
        }
        case AArch64::MVNIv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MVNIv4i16\n");
            break;
        }
        case AArch64::MVNIv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MVNIv4i32\n");
            break;
        }
        case AArch64::MVNIv4s_msl: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MVNIv4s_msl\n");
            break;
        }
        case AArch64::MVNIv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " MVNIv8i16\n");
            break;
        }
        case AArch64::NEGv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " NEGv16i8\n");
            break;
        }
        case AArch64::NEGv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " NEGv1i64\n");
            break;
        }
        case AArch64::NEGv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " NEGv2i32\n");
            break;
        }
        case AArch64::NEGv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " NEGv2i64\n");
            break;
        }
        case AArch64::NEGv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " NEGv4i16\n");
            break;
        }
        case AArch64::NEGv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " NEGv4i32\n");
            break;
        }
        case AArch64::NEGv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " NEGv8i16\n");
            break;
        }
        case AArch64::NEGv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " NEGv8i8\n");
            break;
        }
        case AArch64::NOTv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " NOTv16i8\n");
            break;
        }
        case AArch64::NOTv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " NOTv8i8\n");
            break;
        }
        case AArch64::ORNWrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ORNWrr\n");
            break;
        }
        case AArch64::ORNWrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ORNWrs\n");
            break;
        }
        case AArch64::ORNXrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ORNXrr\n");
            break;
        }
        case AArch64::ORNXrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ORNXrs\n");
            break;
        }
        case AArch64::ORNv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ORNv16i8\n");
            break;
        }
        case AArch64::ORNv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ORNv8i8\n");
            break;
        }
        case AArch64::ORRWri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ORRWri\n");
            break;
        }
        case AArch64::ORRWrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ORRWrr\n");
            break;
        }
        case AArch64::ORRWrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ORRWrs\n");
            break;
        }
        case AArch64::ORRXri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ORRXri\n");
            break;
        }
        case AArch64::ORRXrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ORRXrr\n");
            break;
        }
        case AArch64::ORRXrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ORRXrs\n");
            break;
        }
        case AArch64::ORRv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ORRv16i8\n");
            break;
        }
        case AArch64::ORRv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ORRv2i32\n");
            break;
        }
        case AArch64::ORRv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ORRv4i16\n");
            break;
        }
        case AArch64::ORRv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ORRv4i32\n");
            break;
        }
        case AArch64::ORRv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ORRv8i16\n");
            break;
        }
        case AArch64::ORRv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ORRv8i8\n");
            break;
        }
        case AArch64::PMULLv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " PMULLv16i8\n");
            break;
        }
        case AArch64::PMULLv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " PMULLv1i64\n");
            break;
        }
        case AArch64::PMULLv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " PMULLv2i64\n");
            break;
        }
        case AArch64::PMULLv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " PMULLv8i8\n");
            break;
        }
        case AArch64::PMULv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " PMULv16i8\n");
            break;
        }
        case AArch64::PMULv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " PMULv8i8\n");
            break;
        }
        case AArch64::PRFMl: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " PRFMl\n");
            break;
        }
        case AArch64::PRFMroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " PRFMroW\n");
            break;
        }
        case AArch64::PRFMroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " PRFMroX\n");
            break;
        }
        case AArch64::PRFMui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " PRFMui\n");
            break;
        }
        case AArch64::PRFUMi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " PRFUMi\n");
            break;
        }
        case AArch64::RADDHNv2i64_v2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RADDHNv2i64_v2i32\n");
            break;
        }
        case AArch64::RADDHNv2i64_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RADDHNv2i64_v4i32\n");
            break;
        }
        case AArch64::RADDHNv4i32_v4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RADDHNv4i32_v4i16\n");
            break;
        }
        case AArch64::RADDHNv4i32_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RADDHNv4i32_v8i16\n");
            break;
        }
        case AArch64::RADDHNv8i16_v16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RADDHNv8i16_v16i8\n");
            break;
        }
        case AArch64::RADDHNv8i16_v8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RADDHNv8i16_v8i8\n");
            break;
        }
        case AArch64::RBITWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RBITWr\n");
            break;
        }
        case AArch64::RBITXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RBITXr\n");
            break;
        }
        case AArch64::RBITv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RBITv16i8\n");
            break;
        }
        case AArch64::RBITv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RBITv8i8\n");
            break;
        }
        case AArch64::RET: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RET\n");
            break;
        }
        case AArch64::RET_ReallyLR: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RET_ReallyLR\n");
            break;
        }
        case AArch64::REV16Wr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " REV16Wr\n");
            break;
        }
        case AArch64::REV16Xr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " REV16Xr\n");
            break;
        }
        case AArch64::REV16v16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " REV16v16i8\n");
            break;
        }
        case AArch64::REV16v8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " REV16v8i8\n");
            break;
        }
        case AArch64::REV32Xr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " REV32Xr\n");
            break;
        }
        case AArch64::REV32v16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " REV32v16i8\n");
            break;
        }
        case AArch64::REV32v4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " REV32v4i16\n");
            break;
        }
        case AArch64::REV32v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " REV32v8i16\n");
            break;
        }
        case AArch64::REV32v8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " REV32v8i8\n");
            break;
        }
        case AArch64::REV64v16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " REV64v16i8\n");
            break;
        }
        case AArch64::REV64v2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " REV64v2i32\n");
            break;
        }
        case AArch64::REV64v4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " REV64v4i16\n");
            break;
        }
        case AArch64::REV64v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " REV64v4i32\n");
            break;
        }
        case AArch64::REV64v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " REV64v8i16\n");
            break;
        }
        case AArch64::REV64v8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " REV64v8i8\n");
            break;
        }
        case AArch64::REVWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " REVWr\n");
            break;
        }
        case AArch64::REVXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " REVXr\n");
            break;
        }
        case AArch64::RORVWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RORVWr\n");
            break;
        }
        case AArch64::RORVXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RORVXr\n");
            break;
        }
        case AArch64::RSHRNv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RSHRNv16i8_shift\n");
            break;
        }
        case AArch64::RSHRNv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RSHRNv2i32_shift\n");
            break;
        }
        case AArch64::RSHRNv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RSHRNv4i16_shift\n");
            break;
        }
        case AArch64::RSHRNv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RSHRNv4i32_shift\n");
            break;
        }
        case AArch64::RSHRNv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RSHRNv8i16_shift\n");
            break;
        }
        case AArch64::RSHRNv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RSHRNv8i8_shift\n");
            break;
        }
        case AArch64::RSUBHNv2i64_v2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RSUBHNv2i64_v2i32\n");
            break;
        }
        case AArch64::RSUBHNv2i64_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RSUBHNv2i64_v4i32\n");
            break;
        }
        case AArch64::RSUBHNv4i32_v4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RSUBHNv4i32_v4i16\n");
            break;
        }
        case AArch64::RSUBHNv4i32_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RSUBHNv4i32_v8i16\n");
            break;
        }
        case AArch64::RSUBHNv8i16_v16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RSUBHNv8i16_v16i8\n");
            break;
        }
        case AArch64::RSUBHNv8i16_v8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " RSUBHNv8i16_v8i8\n");
            break;
        }
        case AArch64::SABALv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABALv16i8_v8i16\n");
            break;
        }
        case AArch64::SABALv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABALv2i32_v2i64\n");
            break;
        }
        case AArch64::SABALv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABALv4i16_v4i32\n");
            break;
        }
        case AArch64::SABALv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABALv4i32_v2i64\n");
            break;
        }
        case AArch64::SABALv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABALv8i16_v4i32\n");
            break;
        }
        case AArch64::SABALv8i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABALv8i8_v8i16\n");
            break;
        }
        case AArch64::SABAv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABAv16i8\n");
            break;
        }
        case AArch64::SABAv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABAv2i32\n");
            break;
        }
        case AArch64::SABAv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABAv4i16\n");
            break;
        }
        case AArch64::SABAv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABAv4i32\n");
            break;
        }
        case AArch64::SABAv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABAv8i16\n");
            break;
        }
        case AArch64::SABAv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABAv8i8\n");
            break;
        }
        case AArch64::SABDLv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABDLv16i8_v8i16\n");
            break;
        }
        case AArch64::SABDLv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABDLv2i32_v2i64\n");
            break;
        }
        case AArch64::SABDLv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABDLv4i16_v4i32\n");
            break;
        }
        case AArch64::SABDLv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABDLv4i32_v2i64\n");
            break;
        }
        case AArch64::SABDLv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABDLv8i16_v4i32\n");
            break;
        }
        case AArch64::SABDLv8i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABDLv8i8_v8i16\n");
            break;
        }
        case AArch64::SABDv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABDv16i8\n");
            break;
        }
        case AArch64::SABDv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABDv2i32\n");
            break;
        }
        case AArch64::SABDv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABDv4i16\n");
            break;
        }
        case AArch64::SABDv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABDv4i32\n");
            break;
        }
        case AArch64::SABDv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABDv8i16\n");
            break;
        }
        case AArch64::SABDv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SABDv8i8\n");
            break;
        }
        case AArch64::SADALPv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADALPv16i8_v8i16\n");
            break;
        }
        case AArch64::SADALPv2i32_v1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADALPv2i32_v1i64\n");
            break;
        }
        case AArch64::SADALPv4i16_v2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADALPv4i16_v2i32\n");
            break;
        }
        case AArch64::SADALPv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADALPv4i32_v2i64\n");
            break;
        }
        case AArch64::SADALPv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADALPv8i16_v4i32\n");
            break;
        }
        case AArch64::SADALPv8i8_v4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADALPv8i8_v4i16\n");
            break;
        }
        case AArch64::SADDLPv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDLPv16i8_v8i16\n");
            break;
        }
        case AArch64::SADDLPv2i32_v1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDLPv2i32_v1i64\n");
            break;
        }
        case AArch64::SADDLPv4i16_v2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDLPv4i16_v2i32\n");
            break;
        }
        case AArch64::SADDLPv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDLPv4i32_v2i64\n");
            break;
        }
        case AArch64::SADDLPv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDLPv8i16_v4i32\n");
            break;
        }
        case AArch64::SADDLPv8i8_v4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDLPv8i8_v4i16\n");
            break;
        }
        case AArch64::SADDLVv16i8v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDLVv16i8v\n");
            break;
        }
        case AArch64::SADDLVv4i16v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDLVv4i16v\n");
            break;
        }
        case AArch64::SADDLVv4i32v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDLVv4i32v\n");
            break;
        }
        case AArch64::SADDLVv8i16v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDLVv8i16v\n");
            break;
        }
        case AArch64::SADDLVv8i8v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDLVv8i8v\n");
            break;
        }
        case AArch64::SADDLv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDLv16i8_v8i16\n");
            break;
        }
        case AArch64::SADDLv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDLv2i32_v2i64\n");
            break;
        }
        case AArch64::SADDLv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDLv4i16_v4i32\n");
            break;
        }
        case AArch64::SADDLv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDLv4i32_v2i64\n");
            break;
        }
        case AArch64::SADDLv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDLv8i16_v4i32\n");
            break;
        }
        case AArch64::SADDLv8i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDLv8i8_v8i16\n");
            break;
        }
        case AArch64::SADDWv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDWv16i8_v8i16\n");
            break;
        }
        case AArch64::SADDWv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDWv2i32_v2i64\n");
            break;
        }
        case AArch64::SADDWv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDWv4i16_v4i32\n");
            break;
        }
        case AArch64::SADDWv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDWv4i32_v2i64\n");
            break;
        }
        case AArch64::SADDWv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDWv8i16_v4i32\n");
            break;
        }
        case AArch64::SADDWv8i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SADDWv8i8_v8i16\n");
            break;
        }
        case AArch64::SBCSWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SBCSWr\n");
            break;
        }
        case AArch64::SBCSXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SBCSXr\n");
            break;
        }
        case AArch64::SBCWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SBCWr\n");
            break;
        }
        case AArch64::SBCXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SBCXr\n");
            break;
        }
        case AArch64::SBFMWri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SBFMWri\n");
            break;
        }
        case AArch64::SBFMXri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SBFMXri\n");
            break;
        }
        case AArch64::SCVTFSWDri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SCVTFSWDri\n");
            break;
        }
        case AArch64::SCVTFSWSri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SCVTFSWSri\n");
            break;
        }
        case AArch64::SCVTFSXDri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SCVTFSXDri\n");
            break;
        }
        case AArch64::SCVTFSXSri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SCVTFSXSri\n");
            break;
        }
        case AArch64::SCVTFUWDri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SCVTFUWDri\n");
            break;
        }
        case AArch64::SCVTFUWSri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SCVTFUWSri\n");
            break;
        }
        case AArch64::SCVTFUXDri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SCVTFUXDri\n");
            break;
        }
        case AArch64::SCVTFUXSri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SCVTFUXSri\n");
            break;
        }
        case AArch64::SCVTFd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SCVTFd\n");
            break;
        }
        case AArch64::SCVTFs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SCVTFs\n");
            break;
        }
        case AArch64::SCVTFv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SCVTFv1i32\n");
            break;
        }
        case AArch64::SCVTFv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SCVTFv1i64\n");
            break;
        }
        case AArch64::SCVTFv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SCVTFv2f32\n");
            break;
        }
        case AArch64::SCVTFv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SCVTFv2f64\n");
            break;
        }
        case AArch64::SCVTFv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SCVTFv2i32_shift\n");
            break;
        }
        case AArch64::SCVTFv2i64_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SCVTFv2i64_shift\n");
            break;
        }
        case AArch64::SCVTFv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SCVTFv4f32\n");
            break;
        }
        case AArch64::SCVTFv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SCVTFv4i32_shift\n");
            break;
        }
        case AArch64::SDIVWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SDIVWr\n");
            break;
        }
        case AArch64::SDIVXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SDIVXr\n");
            break;
        }
        case AArch64::SDIV_IntWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SDIV_IntWr\n");
            break;
        }
        case AArch64::SDIV_IntXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SDIV_IntXr\n");
            break;
        }
        case AArch64::SHA1Crrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHA1Crrr\n");
            break;
        }
        case AArch64::SHA1Hrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHA1Hrr\n");
            break;
        }
        case AArch64::SHA1Mrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHA1Mrrr\n");
            break;
        }
        case AArch64::SHA1Prrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHA1Prrr\n");
            break;
        }
        case AArch64::SHA1SU0rrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHA1SU0rrr\n");
            break;
        }
        case AArch64::SHA1SU1rr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHA1SU1rr\n");
            break;
        }
        case AArch64::SHA256H2rrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHA256H2rrr\n");
            break;
        }
        case AArch64::SHA256Hrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHA256Hrrr\n");
            break;
        }
        case AArch64::SHA256SU0rr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHA256SU0rr\n");
            break;
        }
        case AArch64::SHA256SU1rrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHA256SU1rrr\n");
            break;
        }
        case AArch64::SHADDv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHADDv16i8\n");
            break;
        }
        case AArch64::SHADDv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHADDv2i32\n");
            break;
        }
        case AArch64::SHADDv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHADDv4i16\n");
            break;
        }
        case AArch64::SHADDv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHADDv4i32\n");
            break;
        }
        case AArch64::SHADDv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHADDv8i16\n");
            break;
        }
        case AArch64::SHADDv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHADDv8i8\n");
            break;
        }
        case AArch64::SHLLv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHLLv16i8\n");
            break;
        }
        case AArch64::SHLLv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHLLv2i32\n");
            break;
        }
        case AArch64::SHLLv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHLLv4i16\n");
            break;
        }
        case AArch64::SHLLv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHLLv4i32\n");
            break;
        }
        case AArch64::SHLLv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHLLv8i16\n");
            break;
        }
        case AArch64::SHLLv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHLLv8i8\n");
            break;
        }
        case AArch64::SHLd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHLd\n");
            break;
        }
        case AArch64::SHLv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHLv16i8_shift\n");
            break;
        }
        case AArch64::SHLv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHLv2i32_shift\n");
            break;
        }
        case AArch64::SHLv2i64_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHLv2i64_shift\n");
            break;
        }
        case AArch64::SHLv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHLv4i16_shift\n");
            break;
        }
        case AArch64::SHLv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHLv4i32_shift\n");
            break;
        }
        case AArch64::SHLv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHLv8i16_shift\n");
            break;
        }
        case AArch64::SHLv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHLv8i8_shift\n");
            break;
        }
        case AArch64::SHRNv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHRNv16i8_shift\n");
            break;
        }
        case AArch64::SHRNv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHRNv2i32_shift\n");
            break;
        }
        case AArch64::SHRNv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHRNv4i16_shift\n");
            break;
        }
        case AArch64::SHRNv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHRNv4i32_shift\n");
            break;
        }
        case AArch64::SHRNv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHRNv8i16_shift\n");
            break;
        }
        case AArch64::SHRNv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHRNv8i8_shift\n");
            break;
        }
        case AArch64::SHSUBv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHSUBv16i8\n");
            break;
        }
        case AArch64::SHSUBv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHSUBv2i32\n");
            break;
        }
        case AArch64::SHSUBv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHSUBv4i16\n");
            break;
        }
        case AArch64::SHSUBv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHSUBv4i32\n");
            break;
        }
        case AArch64::SHSUBv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHSUBv8i16\n");
            break;
        }
        case AArch64::SHSUBv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SHSUBv8i8\n");
            break;
        }
        case AArch64::SLId: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SLId\n");
            break;
        }
        case AArch64::SLIv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SLIv16i8_shift\n");
            break;
        }
        case AArch64::SLIv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SLIv2i32_shift\n");
            break;
        }
        case AArch64::SLIv2i64_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SLIv2i64_shift\n");
            break;
        }
        case AArch64::SLIv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SLIv4i16_shift\n");
            break;
        }
        case AArch64::SLIv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SLIv4i32_shift\n");
            break;
        }
        case AArch64::SLIv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SLIv8i16_shift\n");
            break;
        }
        case AArch64::SLIv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SLIv8i8_shift\n");
            break;
        }
        case AArch64::SMADDLrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMADDLrrr\n");
            break;
        }
        case AArch64::SMAXPv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMAXPv16i8\n");
            break;
        }
        case AArch64::SMAXPv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMAXPv2i32\n");
            break;
        }
        case AArch64::SMAXPv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMAXPv4i16\n");
            break;
        }
        case AArch64::SMAXPv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMAXPv4i32\n");
            break;
        }
        case AArch64::SMAXPv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMAXPv8i16\n");
            break;
        }
        case AArch64::SMAXPv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMAXPv8i8\n");
            break;
        }
        case AArch64::SMAXVv16i8v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMAXVv16i8v\n");
            break;
        }
        case AArch64::SMAXVv4i16v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMAXVv4i16v\n");
            break;
        }
        case AArch64::SMAXVv4i32v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMAXVv4i32v\n");
            break;
        }
        case AArch64::SMAXVv8i16v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMAXVv8i16v\n");
            break;
        }
        case AArch64::SMAXVv8i8v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMAXVv8i8v\n");
            break;
        }
        case AArch64::SMAXv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMAXv16i8\n");
            break;
        }
        case AArch64::SMAXv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMAXv2i32\n");
            break;
        }
        case AArch64::SMAXv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMAXv4i16\n");
            break;
        }
        case AArch64::SMAXv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMAXv4i32\n");
            break;
        }
        case AArch64::SMAXv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMAXv8i16\n");
            break;
        }
        case AArch64::SMAXv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMAXv8i8\n");
            break;
        }
        case AArch64::SMC: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMC\n");
            break;
        }
        case AArch64::SMINPv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMINPv16i8\n");
            break;
        }
        case AArch64::SMINPv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMINPv2i32\n");
            break;
        }
        case AArch64::SMINPv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMINPv4i16\n");
            break;
        }
        case AArch64::SMINPv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMINPv4i32\n");
            break;
        }
        case AArch64::SMINPv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMINPv8i16\n");
            break;
        }
        case AArch64::SMINPv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMINPv8i8\n");
            break;
        }
        case AArch64::SMINVv16i8v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMINVv16i8v\n");
            break;
        }
        case AArch64::SMINVv4i16v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMINVv4i16v\n");
            break;
        }
        case AArch64::SMINVv4i32v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMINVv4i32v\n");
            break;
        }
        case AArch64::SMINVv8i16v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMINVv8i16v\n");
            break;
        }
        case AArch64::SMINVv8i8v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMINVv8i8v\n");
            break;
        }
        case AArch64::SMINv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMINv16i8\n");
            break;
        }
        case AArch64::SMINv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMINv2i32\n");
            break;
        }
        case AArch64::SMINv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMINv4i16\n");
            break;
        }
        case AArch64::SMINv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMINv4i32\n");
            break;
        }
        case AArch64::SMINv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMINv8i16\n");
            break;
        }
        case AArch64::SMINv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMINv8i8\n");
            break;
        }
        case AArch64::SMLALv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLALv16i8_v8i16\n");
            break;
        }
        case AArch64::SMLALv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLALv2i32_indexed\n");
            break;
        }
        case AArch64::SMLALv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLALv2i32_v2i64\n");
            break;
        }
        case AArch64::SMLALv4i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLALv4i16_indexed\n");
            break;
        }
        case AArch64::SMLALv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLALv4i16_v4i32\n");
            break;
        }
        case AArch64::SMLALv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLALv4i32_indexed\n");
            break;
        }
        case AArch64::SMLALv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLALv4i32_v2i64\n");
            break;
        }
        case AArch64::SMLALv8i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLALv8i16_indexed\n");
            break;
        }
        case AArch64::SMLALv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLALv8i16_v4i32\n");
            break;
        }
        case AArch64::SMLALv8i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLALv8i8_v8i16\n");
            break;
        }
        case AArch64::SMLSLv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLSLv16i8_v8i16\n");
            break;
        }
        case AArch64::SMLSLv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLSLv2i32_indexed\n");
            break;
        }
        case AArch64::SMLSLv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLSLv2i32_v2i64\n");
            break;
        }
        case AArch64::SMLSLv4i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLSLv4i16_indexed\n");
            break;
        }
        case AArch64::SMLSLv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLSLv4i16_v4i32\n");
            break;
        }
        case AArch64::SMLSLv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLSLv4i32_indexed\n");
            break;
        }
        case AArch64::SMLSLv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLSLv4i32_v2i64\n");
            break;
        }
        case AArch64::SMLSLv8i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLSLv8i16_indexed\n");
            break;
        }
        case AArch64::SMLSLv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLSLv8i16_v4i32\n");
            break;
        }
        case AArch64::SMLSLv8i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMLSLv8i8_v8i16\n");
            break;
        }
        case AArch64::SMOVvi16to32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMOVvi16to32\n");
            break;
        }
        case AArch64::SMOVvi16to64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMOVvi16to64\n");
            break;
        }
        case AArch64::SMOVvi32to64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMOVvi32to64\n");
            break;
        }
        case AArch64::SMOVvi8to32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMOVvi8to32\n");
            break;
        }
        case AArch64::SMOVvi8to64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMOVvi8to64\n");
            break;
        }
        case AArch64::SMSUBLrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMSUBLrrr\n");
            break;
        }
        case AArch64::SMULHrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMULHrr\n");
            break;
        }
        case AArch64::SMULLv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMULLv16i8_v8i16\n");
            break;
        }
        case AArch64::SMULLv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMULLv2i32_indexed\n");
            break;
        }
        case AArch64::SMULLv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMULLv2i32_v2i64\n");
            break;
        }
        case AArch64::SMULLv4i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMULLv4i16_indexed\n");
            break;
        }
        case AArch64::SMULLv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMULLv4i16_v4i32\n");
            break;
        }
        case AArch64::SMULLv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMULLv4i32_indexed\n");
            break;
        }
        case AArch64::SMULLv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMULLv4i32_v2i64\n");
            break;
        }
        case AArch64::SMULLv8i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMULLv8i16_indexed\n");
            break;
        }
        case AArch64::SMULLv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMULLv8i16_v4i32\n");
            break;
        }
        case AArch64::SMULLv8i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SMULLv8i8_v8i16\n");
            break;
        }
        case AArch64::SQABSv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQABSv16i8\n");
            break;
        }
        case AArch64::SQABSv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQABSv1i16\n");
            break;
        }
        case AArch64::SQABSv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQABSv1i32\n");
            break;
        }
        case AArch64::SQABSv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQABSv1i64\n");
            break;
        }
        case AArch64::SQABSv1i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQABSv1i8\n");
            break;
        }
        case AArch64::SQABSv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQABSv2i32\n");
            break;
        }
        case AArch64::SQABSv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQABSv2i64\n");
            break;
        }
        case AArch64::SQABSv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQABSv4i16\n");
            break;
        }
        case AArch64::SQABSv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQABSv4i32\n");
            break;
        }
        case AArch64::SQABSv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQABSv8i16\n");
            break;
        }
        case AArch64::SQABSv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQABSv8i8\n");
            break;
        }
        case AArch64::SQADDv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQADDv16i8\n");
            break;
        }
        case AArch64::SQADDv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQADDv1i16\n");
            break;
        }
        case AArch64::SQADDv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQADDv1i32\n");
            break;
        }
        case AArch64::SQADDv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQADDv1i64\n");
            break;
        }
        case AArch64::SQADDv1i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQADDv1i8\n");
            break;
        }
        case AArch64::SQADDv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQADDv2i32\n");
            break;
        }
        case AArch64::SQADDv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQADDv2i64\n");
            break;
        }
        case AArch64::SQADDv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQADDv4i16\n");
            break;
        }
        case AArch64::SQADDv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQADDv4i32\n");
            break;
        }
        case AArch64::SQADDv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQADDv8i16\n");
            break;
        }
        case AArch64::SQADDv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQADDv8i8\n");
            break;
        }
        case AArch64::SQDMLALi16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLALi16\n");
            break;
        }
        case AArch64::SQDMLALi32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLALi32\n");
            break;
        }
        case AArch64::SQDMLALv1i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLALv1i32_indexed\n");
            break;
        }
        case AArch64::SQDMLALv1i64_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLALv1i64_indexed\n");
            break;
        }
        case AArch64::SQDMLALv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLALv2i32_indexed\n");
            break;
        }
        case AArch64::SQDMLALv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLALv2i32_v2i64\n");
            break;
        }
        case AArch64::SQDMLALv4i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLALv4i16_indexed\n");
            break;
        }
        case AArch64::SQDMLALv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLALv4i16_v4i32\n");
            break;
        }
        case AArch64::SQDMLALv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLALv4i32_indexed\n");
            break;
        }
        case AArch64::SQDMLALv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLALv4i32_v2i64\n");
            break;
        }
        case AArch64::SQDMLALv8i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLALv8i16_indexed\n");
            break;
        }
        case AArch64::SQDMLALv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLALv8i16_v4i32\n");
            break;
        }
        case AArch64::SQDMLSLi16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLSLi16\n");
            break;
        }
        case AArch64::SQDMLSLi32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLSLi32\n");
            break;
        }
        case AArch64::SQDMLSLv1i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLSLv1i32_indexed\n");
            break;
        }
        case AArch64::SQDMLSLv1i64_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLSLv1i64_indexed\n");
            break;
        }
        case AArch64::SQDMLSLv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLSLv2i32_indexed\n");
            break;
        }
        case AArch64::SQDMLSLv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLSLv2i32_v2i64\n");
            break;
        }
        case AArch64::SQDMLSLv4i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLSLv4i16_indexed\n");
            break;
        }
        case AArch64::SQDMLSLv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLSLv4i16_v4i32\n");
            break;
        }
        case AArch64::SQDMLSLv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLSLv4i32_indexed\n");
            break;
        }
        case AArch64::SQDMLSLv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLSLv4i32_v2i64\n");
            break;
        }
        case AArch64::SQDMLSLv8i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLSLv8i16_indexed\n");
            break;
        }
        case AArch64::SQDMLSLv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMLSLv8i16_v4i32\n");
            break;
        }
        case AArch64::SQDMULHv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULHv1i16\n");
            break;
        }
        case AArch64::SQDMULHv1i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULHv1i16_indexed\n");
            break;
        }
        case AArch64::SQDMULHv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULHv1i32\n");
            break;
        }
        case AArch64::SQDMULHv1i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULHv1i32_indexed\n");
            break;
        }
        case AArch64::SQDMULHv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULHv2i32\n");
            break;
        }
        case AArch64::SQDMULHv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULHv2i32_indexed\n");
            break;
        }
        case AArch64::SQDMULHv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULHv4i16\n");
            break;
        }
        case AArch64::SQDMULHv4i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULHv4i16_indexed\n");
            break;
        }
        case AArch64::SQDMULHv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULHv4i32\n");
            break;
        }
        case AArch64::SQDMULHv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULHv4i32_indexed\n");
            break;
        }
        case AArch64::SQDMULHv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULHv8i16\n");
            break;
        }
        case AArch64::SQDMULHv8i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULHv8i16_indexed\n");
            break;
        }
        case AArch64::SQDMULLi16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULLi16\n");
            break;
        }
        case AArch64::SQDMULLi32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULLi32\n");
            break;
        }
        case AArch64::SQDMULLv1i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULLv1i32_indexed\n");
            break;
        }
        case AArch64::SQDMULLv1i64_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULLv1i64_indexed\n");
            break;
        }
        case AArch64::SQDMULLv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULLv2i32_indexed\n");
            break;
        }
        case AArch64::SQDMULLv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULLv2i32_v2i64\n");
            break;
        }
        case AArch64::SQDMULLv4i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULLv4i16_indexed\n");
            break;
        }
        case AArch64::SQDMULLv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULLv4i16_v4i32\n");
            break;
        }
        case AArch64::SQDMULLv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULLv4i32_indexed\n");
            break;
        }
        case AArch64::SQDMULLv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULLv4i32_v2i64\n");
            break;
        }
        case AArch64::SQDMULLv8i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULLv8i16_indexed\n");
            break;
        }
        case AArch64::SQDMULLv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQDMULLv8i16_v4i32\n");
            break;
        }
        case AArch64::SQNEGv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQNEGv16i8\n");
            break;
        }
        case AArch64::SQNEGv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQNEGv1i16\n");
            break;
        }
        case AArch64::SQNEGv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQNEGv1i32\n");
            break;
        }
        case AArch64::SQNEGv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQNEGv1i64\n");
            break;
        }
        case AArch64::SQNEGv1i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQNEGv1i8\n");
            break;
        }
        case AArch64::SQNEGv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQNEGv2i32\n");
            break;
        }
        case AArch64::SQNEGv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQNEGv2i64\n");
            break;
        }
        case AArch64::SQNEGv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQNEGv4i16\n");
            break;
        }
        case AArch64::SQNEGv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQNEGv4i32\n");
            break;
        }
        case AArch64::SQNEGv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQNEGv8i16\n");
            break;
        }
        case AArch64::SQNEGv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQNEGv8i8\n");
            break;
        }
        case AArch64::SQRDMLAHi16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLAHi16_indexed\n");
            break;
        }
        case AArch64::SQRDMLAHi32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLAHi32_indexed\n");
            break;
        }
        case AArch64::SQRDMLAHv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLAHv1i16\n");
            break;
        }
        case AArch64::SQRDMLAHv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLAHv1i32\n");
            break;
        }
        case AArch64::SQRDMLAHv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLAHv2i32\n");
            break;
        }
        case AArch64::SQRDMLAHv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLAHv2i32_indexed\n");
            break;
        }
        case AArch64::SQRDMLAHv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLAHv4i16\n");
            break;
        }
        case AArch64::SQRDMLAHv4i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLAHv4i16_indexed\n");
            break;
        }
        case AArch64::SQRDMLAHv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLAHv4i32\n");
            break;
        }
        case AArch64::SQRDMLAHv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLAHv4i32_indexed\n");
            break;
        }
        case AArch64::SQRDMLAHv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLAHv8i16\n");
            break;
        }
        case AArch64::SQRDMLAHv8i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLAHv8i16_indexed\n");
            break;
        }
        case AArch64::SQRDMLSHi16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLSHi16_indexed\n");
            break;
        }
        case AArch64::SQRDMLSHi32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLSHi32_indexed\n");
            break;
        }
        case AArch64::SQRDMLSHv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLSHv1i16\n");
            break;
        }
        case AArch64::SQRDMLSHv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLSHv1i32\n");
            break;
        }
        case AArch64::SQRDMLSHv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLSHv2i32\n");
            break;
        }
        case AArch64::SQRDMLSHv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLSHv2i32_indexed\n");
            break;
        }
        case AArch64::SQRDMLSHv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLSHv4i16\n");
            break;
        }
        case AArch64::SQRDMLSHv4i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLSHv4i16_indexed\n");
            break;
        }
        case AArch64::SQRDMLSHv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLSHv4i32\n");
            break;
        }
        case AArch64::SQRDMLSHv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLSHv4i32_indexed\n");
            break;
        }
        case AArch64::SQRDMLSHv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLSHv8i16\n");
            break;
        }
        case AArch64::SQRDMLSHv8i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMLSHv8i16_indexed\n");
            break;
        }
        case AArch64::SQRDMULHv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMULHv1i16\n");
            break;
        }
        case AArch64::SQRDMULHv1i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMULHv1i16_indexed\n");
            break;
        }
        case AArch64::SQRDMULHv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMULHv1i32\n");
            break;
        }
        case AArch64::SQRDMULHv1i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMULHv1i32_indexed\n");
            break;
        }
        case AArch64::SQRDMULHv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMULHv2i32\n");
            break;
        }
        case AArch64::SQRDMULHv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMULHv2i32_indexed\n");
            break;
        }
        case AArch64::SQRDMULHv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMULHv4i16\n");
            break;
        }
        case AArch64::SQRDMULHv4i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMULHv4i16_indexed\n");
            break;
        }
        case AArch64::SQRDMULHv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMULHv4i32\n");
            break;
        }
        case AArch64::SQRDMULHv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMULHv4i32_indexed\n");
            break;
        }
        case AArch64::SQRDMULHv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMULHv8i16\n");
            break;
        }
        case AArch64::SQRDMULHv8i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRDMULHv8i16_indexed\n");
            break;
        }
        case AArch64::SQRSHLv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHLv16i8\n");
            break;
        }
        case AArch64::SQRSHLv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHLv1i16\n");
            break;
        }
        case AArch64::SQRSHLv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHLv1i32\n");
            break;
        }
        case AArch64::SQRSHLv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHLv1i64\n");
            break;
        }
        case AArch64::SQRSHLv1i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHLv1i8\n");
            break;
        }
        case AArch64::SQRSHLv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHLv2i32\n");
            break;
        }
        case AArch64::SQRSHLv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHLv2i64\n");
            break;
        }
        case AArch64::SQRSHLv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHLv4i16\n");
            break;
        }
        case AArch64::SQRSHLv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHLv4i32\n");
            break;
        }
        case AArch64::SQRSHLv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHLv8i16\n");
            break;
        }
        case AArch64::SQRSHLv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHLv8i8\n");
            break;
        }
        case AArch64::SQRSHRNb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHRNb\n");
            break;
        }
        case AArch64::SQRSHRNh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHRNh\n");
            break;
        }
        case AArch64::SQRSHRNs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHRNs\n");
            break;
        }
        case AArch64::SQRSHRNv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHRNv16i8_shift\n");
            break;
        }
        case AArch64::SQRSHRNv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHRNv2i32_shift\n");
            break;
        }
        case AArch64::SQRSHRNv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHRNv4i16_shift\n");
            break;
        }
        case AArch64::SQRSHRNv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHRNv4i32_shift\n");
            break;
        }
        case AArch64::SQRSHRNv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHRNv8i16_shift\n");
            break;
        }
        case AArch64::SQRSHRNv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHRNv8i8_shift\n");
            break;
        }
        case AArch64::SQRSHRUNb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHRUNb\n");
            break;
        }
        case AArch64::SQRSHRUNh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHRUNh\n");
            break;
        }
        case AArch64::SQRSHRUNs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHRUNs\n");
            break;
        }
        case AArch64::SQRSHRUNv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHRUNv16i8_shift\n");
            break;
        }
        case AArch64::SQRSHRUNv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHRUNv2i32_shift\n");
            break;
        }
        case AArch64::SQRSHRUNv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHRUNv4i16_shift\n");
            break;
        }
        case AArch64::SQRSHRUNv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHRUNv4i32_shift\n");
            break;
        }
        case AArch64::SQRSHRUNv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHRUNv8i16_shift\n");
            break;
        }
        case AArch64::SQRSHRUNv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQRSHRUNv8i8_shift\n");
            break;
        }
        case AArch64::SQSHLUb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLUb\n");
            break;
        }
        case AArch64::SQSHLUd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLUd\n");
            break;
        }
        case AArch64::SQSHLUh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLUh\n");
            break;
        }
        case AArch64::SQSHLUs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLUs\n");
            break;
        }
        case AArch64::SQSHLUv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLUv16i8_shift\n");
            break;
        }
        case AArch64::SQSHLUv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLUv2i32_shift\n");
            break;
        }
        case AArch64::SQSHLUv2i64_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLUv2i64_shift\n");
            break;
        }
        case AArch64::SQSHLUv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLUv4i16_shift\n");
            break;
        }
        case AArch64::SQSHLUv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLUv4i32_shift\n");
            break;
        }
        case AArch64::SQSHLUv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLUv8i16_shift\n");
            break;
        }
        case AArch64::SQSHLUv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLUv8i8_shift\n");
            break;
        }
        case AArch64::SQSHLb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLb\n");
            break;
        }
        case AArch64::SQSHLd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLd\n");
            break;
        }
        case AArch64::SQSHLh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLh\n");
            break;
        }
        case AArch64::SQSHLs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLs\n");
            break;
        }
        case AArch64::SQSHLv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLv16i8\n");
            break;
        }
        case AArch64::SQSHLv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLv16i8_shift\n");
            break;
        }
        case AArch64::SQSHLv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLv1i16\n");
            break;
        }
        case AArch64::SQSHLv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLv1i32\n");
            break;
        }
        case AArch64::SQSHLv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLv1i64\n");
            break;
        }
        case AArch64::SQSHLv1i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLv1i8\n");
            break;
        }
        case AArch64::SQSHLv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLv2i32\n");
            break;
        }
        case AArch64::SQSHLv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLv2i32_shift\n");
            break;
        }
        case AArch64::SQSHLv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLv2i64\n");
            break;
        }
        case AArch64::SQSHLv2i64_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLv2i64_shift\n");
            break;
        }
        case AArch64::SQSHLv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLv4i16\n");
            break;
        }
        case AArch64::SQSHLv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLv4i16_shift\n");
            break;
        }
        case AArch64::SQSHLv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLv4i32\n");
            break;
        }
        case AArch64::SQSHLv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLv4i32_shift\n");
            break;
        }
        case AArch64::SQSHLv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLv8i16\n");
            break;
        }
        case AArch64::SQSHLv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLv8i16_shift\n");
            break;
        }
        case AArch64::SQSHLv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLv8i8\n");
            break;
        }
        case AArch64::SQSHLv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHLv8i8_shift\n");
            break;
        }
        case AArch64::SQSHRNb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHRNb\n");
            break;
        }
        case AArch64::SQSHRNh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHRNh\n");
            break;
        }
        case AArch64::SQSHRNs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHRNs\n");
            break;
        }
        case AArch64::SQSHRNv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHRNv16i8_shift\n");
            break;
        }
        case AArch64::SQSHRNv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHRNv2i32_shift\n");
            break;
        }
        case AArch64::SQSHRNv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHRNv4i16_shift\n");
            break;
        }
        case AArch64::SQSHRNv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHRNv4i32_shift\n");
            break;
        }
        case AArch64::SQSHRNv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHRNv8i16_shift\n");
            break;
        }
        case AArch64::SQSHRNv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHRNv8i8_shift\n");
            break;
        }
        case AArch64::SQSHRUNb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHRUNb\n");
            break;
        }
        case AArch64::SQSHRUNh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHRUNh\n");
            break;
        }
        case AArch64::SQSHRUNs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHRUNs\n");
            break;
        }
        case AArch64::SQSHRUNv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHRUNv16i8_shift\n");
            break;
        }
        case AArch64::SQSHRUNv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHRUNv2i32_shift\n");
            break;
        }
        case AArch64::SQSHRUNv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHRUNv4i16_shift\n");
            break;
        }
        case AArch64::SQSHRUNv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHRUNv4i32_shift\n");
            break;
        }
        case AArch64::SQSHRUNv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHRUNv8i16_shift\n");
            break;
        }
        case AArch64::SQSHRUNv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSHRUNv8i8_shift\n");
            break;
        }
        case AArch64::SQSUBv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSUBv16i8\n");
            break;
        }
        case AArch64::SQSUBv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSUBv1i16\n");
            break;
        }
        case AArch64::SQSUBv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSUBv1i32\n");
            break;
        }
        case AArch64::SQSUBv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSUBv1i64\n");
            break;
        }
        case AArch64::SQSUBv1i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSUBv1i8\n");
            break;
        }
        case AArch64::SQSUBv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSUBv2i32\n");
            break;
        }
        case AArch64::SQSUBv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSUBv2i64\n");
            break;
        }
        case AArch64::SQSUBv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSUBv4i16\n");
            break;
        }
        case AArch64::SQSUBv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSUBv4i32\n");
            break;
        }
        case AArch64::SQSUBv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSUBv8i16\n");
            break;
        }
        case AArch64::SQSUBv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQSUBv8i8\n");
            break;
        }
        case AArch64::SQXTNv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQXTNv16i8\n");
            break;
        }
        case AArch64::SQXTNv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQXTNv1i16\n");
            break;
        }
        case AArch64::SQXTNv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQXTNv1i32\n");
            break;
        }
        case AArch64::SQXTNv1i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQXTNv1i8\n");
            break;
        }
        case AArch64::SQXTNv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQXTNv2i32\n");
            break;
        }
        case AArch64::SQXTNv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQXTNv4i16\n");
            break;
        }
        case AArch64::SQXTNv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQXTNv4i32\n");
            break;
        }
        case AArch64::SQXTNv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQXTNv8i16\n");
            break;
        }
        case AArch64::SQXTNv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQXTNv8i8\n");
            break;
        }
        case AArch64::SQXTUNv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQXTUNv16i8\n");
            break;
        }
        case AArch64::SQXTUNv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQXTUNv1i16\n");
            break;
        }
        case AArch64::SQXTUNv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQXTUNv1i32\n");
            break;
        }
        case AArch64::SQXTUNv1i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQXTUNv1i8\n");
            break;
        }
        case AArch64::SQXTUNv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQXTUNv2i32\n");
            break;
        }
        case AArch64::SQXTUNv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQXTUNv4i16\n");
            break;
        }
        case AArch64::SQXTUNv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQXTUNv4i32\n");
            break;
        }
        case AArch64::SQXTUNv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQXTUNv8i16\n");
            break;
        }
        case AArch64::SQXTUNv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SQXTUNv8i8\n");
            break;
        }
        case AArch64::SRHADDv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRHADDv16i8\n");
            break;
        }
        case AArch64::SRHADDv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRHADDv2i32\n");
            break;
        }
        case AArch64::SRHADDv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRHADDv4i16\n");
            break;
        }
        case AArch64::SRHADDv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRHADDv4i32\n");
            break;
        }
        case AArch64::SRHADDv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRHADDv8i16\n");
            break;
        }
        case AArch64::SRHADDv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRHADDv8i8\n");
            break;
        }
        case AArch64::SRId: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRId\n");
            break;
        }
        case AArch64::SRIv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRIv16i8_shift\n");
            break;
        }
        case AArch64::SRIv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRIv2i32_shift\n");
            break;
        }
        case AArch64::SRIv2i64_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRIv2i64_shift\n");
            break;
        }
        case AArch64::SRIv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRIv4i16_shift\n");
            break;
        }
        case AArch64::SRIv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRIv4i32_shift\n");
            break;
        }
        case AArch64::SRIv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRIv8i16_shift\n");
            break;
        }
        case AArch64::SRIv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRIv8i8_shift\n");
            break;
        }
        case AArch64::SRSHLv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSHLv16i8\n");
            break;
        }
        case AArch64::SRSHLv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSHLv1i64\n");
            break;
        }
        case AArch64::SRSHLv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSHLv2i32\n");
            break;
        }
        case AArch64::SRSHLv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSHLv2i64\n");
            break;
        }
        case AArch64::SRSHLv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSHLv4i16\n");
            break;
        }
        case AArch64::SRSHLv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSHLv4i32\n");
            break;
        }
        case AArch64::SRSHLv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSHLv8i16\n");
            break;
        }
        case AArch64::SRSHLv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSHLv8i8\n");
            break;
        }
        case AArch64::SRSHRd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSHRd\n");
            break;
        }
        case AArch64::SRSHRv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSHRv16i8_shift\n");
            break;
        }
        case AArch64::SRSHRv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSHRv2i32_shift\n");
            break;
        }
        case AArch64::SRSHRv2i64_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSHRv2i64_shift\n");
            break;
        }
        case AArch64::SRSHRv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSHRv4i16_shift\n");
            break;
        }
        case AArch64::SRSHRv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSHRv4i32_shift\n");
            break;
        }
        case AArch64::SRSHRv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSHRv8i16_shift\n");
            break;
        }
        case AArch64::SRSHRv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSHRv8i8_shift\n");
            break;
        }
        case AArch64::SRSRAd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSRAd\n");
            break;
        }
        case AArch64::SRSRAv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSRAv16i8_shift\n");
            break;
        }
        case AArch64::SRSRAv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSRAv2i32_shift\n");
            break;
        }
        case AArch64::SRSRAv2i64_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSRAv2i64_shift\n");
            break;
        }
        case AArch64::SRSRAv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSRAv4i16_shift\n");
            break;
        }
        case AArch64::SRSRAv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSRAv4i32_shift\n");
            break;
        }
        case AArch64::SRSRAv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSRAv8i16_shift\n");
            break;
        }
        case AArch64::SRSRAv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SRSRAv8i8_shift\n");
            break;
        }
        case AArch64::SSHLLv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHLLv16i8_shift\n");
            break;
        }
        case AArch64::SSHLLv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHLLv2i32_shift\n");
            break;
        }
        case AArch64::SSHLLv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHLLv4i16_shift\n");
            break;
        }
        case AArch64::SSHLLv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHLLv4i32_shift\n");
            break;
        }
        case AArch64::SSHLLv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHLLv8i16_shift\n");
            break;
        }
        case AArch64::SSHLLv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHLLv8i8_shift\n");
            break;
        }
        case AArch64::SSHLv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHLv16i8\n");
            break;
        }
        case AArch64::SSHLv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHLv1i64\n");
            break;
        }
        case AArch64::SSHLv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHLv2i32\n");
            break;
        }
        case AArch64::SSHLv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHLv2i64\n");
            break;
        }
        case AArch64::SSHLv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHLv4i16\n");
            break;
        }
        case AArch64::SSHLv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHLv4i32\n");
            break;
        }
        case AArch64::SSHLv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHLv8i16\n");
            break;
        }
        case AArch64::SSHLv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHLv8i8\n");
            break;
        }
        case AArch64::SSHRd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHRd\n");
            break;
        }
        case AArch64::SSHRv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHRv16i8_shift\n");
            break;
        }
        case AArch64::SSHRv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHRv2i32_shift\n");
            break;
        }
        case AArch64::SSHRv2i64_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHRv2i64_shift\n");
            break;
        }
        case AArch64::SSHRv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHRv4i16_shift\n");
            break;
        }
        case AArch64::SSHRv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHRv4i32_shift\n");
            break;
        }
        case AArch64::SSHRv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHRv8i16_shift\n");
            break;
        }
        case AArch64::SSHRv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSHRv8i8_shift\n");
            break;
        }
        case AArch64::SSRAd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSRAd\n");
            break;
        }
        case AArch64::SSRAv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSRAv16i8_shift\n");
            break;
        }
        case AArch64::SSRAv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSRAv2i32_shift\n");
            break;
        }
        case AArch64::SSRAv2i64_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSRAv2i64_shift\n");
            break;
        }
        case AArch64::SSRAv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSRAv4i16_shift\n");
            break;
        }
        case AArch64::SSRAv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSRAv4i32_shift\n");
            break;
        }
        case AArch64::SSRAv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSRAv8i16_shift\n");
            break;
        }
        case AArch64::SSRAv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSRAv8i8_shift\n");
            break;
        }
        case AArch64::SSUBLv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSUBLv16i8_v8i16\n");
            break;
        }
        case AArch64::SSUBLv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSUBLv2i32_v2i64\n");
            break;
        }
        case AArch64::SSUBLv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSUBLv4i16_v4i32\n");
            break;
        }
        case AArch64::SSUBLv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSUBLv4i32_v2i64\n");
            break;
        }
        case AArch64::SSUBLv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSUBLv8i16_v4i32\n");
            break;
        }
        case AArch64::SSUBLv8i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSUBLv8i8_v8i16\n");
            break;
        }
        case AArch64::SSUBWv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSUBWv16i8_v8i16\n");
            break;
        }
        case AArch64::SSUBWv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSUBWv2i32_v2i64\n");
            break;
        }
        case AArch64::SSUBWv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSUBWv4i16_v4i32\n");
            break;
        }
        case AArch64::SSUBWv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSUBWv4i32_v2i64\n");
            break;
        }
        case AArch64::SSUBWv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSUBWv8i16_v4i32\n");
            break;
        }
        case AArch64::SSUBWv8i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SSUBWv8i8_v8i16\n");
            break;
        }
        case AArch64::ST1Fourv16b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Fourv16b\n");
            break;
        }
        case AArch64::ST1Fourv16b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Fourv16b_POST\n");
            break;
        }
        case AArch64::ST1Fourv1d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Fourv1d\n");
            break;
        }
        case AArch64::ST1Fourv1d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Fourv1d_POST\n");
            break;
        }
        case AArch64::ST1Fourv2d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Fourv2d\n");
            break;
        }
        case AArch64::ST1Fourv2d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Fourv2d_POST\n");
            break;
        }
        case AArch64::ST1Fourv2s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Fourv2s\n");
            break;
        }
        case AArch64::ST1Fourv2s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Fourv2s_POST\n");
            break;
        }
        case AArch64::ST1Fourv4h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Fourv4h\n");
            break;
        }
        case AArch64::ST1Fourv4h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Fourv4h_POST\n");
            break;
        }
        case AArch64::ST1Fourv4s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Fourv4s\n");
            break;
        }
        case AArch64::ST1Fourv4s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Fourv4s_POST\n");
            break;
        }
        case AArch64::ST1Fourv8b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Fourv8b\n");
            break;
        }
        case AArch64::ST1Fourv8b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Fourv8b_POST\n");
            break;
        }
        case AArch64::ST1Fourv8h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Fourv8h\n");
            break;
        }
        case AArch64::ST1Fourv8h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Fourv8h_POST\n");
            break;
        }
        case AArch64::ST1Onev16b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Onev16b\n");
            break;
        }
        case AArch64::ST1Onev16b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Onev16b_POST\n");
            break;
        }
        case AArch64::ST1Onev1d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Onev1d\n");
            break;
        }
        case AArch64::ST1Onev1d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Onev1d_POST\n");
            break;
        }
        case AArch64::ST1Onev2d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Onev2d\n");
            break;
        }
        case AArch64::ST1Onev2d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Onev2d_POST\n");
            break;
        }
        case AArch64::ST1Onev2s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Onev2s\n");
            break;
        }
        case AArch64::ST1Onev2s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Onev2s_POST\n");
            break;
        }
        case AArch64::ST1Onev4h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Onev4h\n");
            break;
        }
        case AArch64::ST1Onev4h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Onev4h_POST\n");
            break;
        }
        case AArch64::ST1Onev4s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Onev4s\n");
            break;
        }
        case AArch64::ST1Onev4s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Onev4s_POST\n");
            break;
        }
        case AArch64::ST1Onev8b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Onev8b\n");
            break;
        }
        case AArch64::ST1Onev8b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Onev8b_POST\n");
            break;
        }
        case AArch64::ST1Onev8h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Onev8h\n");
            break;
        }
        case AArch64::ST1Onev8h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Onev8h_POST\n");
            break;
        }
        case AArch64::ST1Threev16b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Threev16b\n");
            break;
        }
        case AArch64::ST1Threev16b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Threev16b_POST\n");
            break;
        }
        case AArch64::ST1Threev1d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Threev1d\n");
            break;
        }
        case AArch64::ST1Threev1d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Threev1d_POST\n");
            break;
        }
        case AArch64::ST1Threev2d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Threev2d\n");
            break;
        }
        case AArch64::ST1Threev2d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Threev2d_POST\n");
            break;
        }
        case AArch64::ST1Threev2s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Threev2s\n");
            break;
        }
        case AArch64::ST1Threev2s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Threev2s_POST\n");
            break;
        }
        case AArch64::ST1Threev4h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Threev4h\n");
            break;
        }
        case AArch64::ST1Threev4h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Threev4h_POST\n");
            break;
        }
        case AArch64::ST1Threev4s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Threev4s\n");
            break;
        }
        case AArch64::ST1Threev4s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Threev4s_POST\n");
            break;
        }
        case AArch64::ST1Threev8b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Threev8b\n");
            break;
        }
        case AArch64::ST1Threev8b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Threev8b_POST\n");
            break;
        }
        case AArch64::ST1Threev8h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Threev8h\n");
            break;
        }
        case AArch64::ST1Threev8h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Threev8h_POST\n");
            break;
        }
        case AArch64::ST1Twov16b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Twov16b\n");
            break;
        }
        case AArch64::ST1Twov16b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Twov16b_POST\n");
            break;
        }
        case AArch64::ST1Twov1d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Twov1d\n");
            break;
        }
        case AArch64::ST1Twov1d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Twov1d_POST\n");
            break;
        }
        case AArch64::ST1Twov2d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Twov2d\n");
            break;
        }
        case AArch64::ST1Twov2d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Twov2d_POST\n");
            break;
        }
        case AArch64::ST1Twov2s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Twov2s\n");
            break;
        }
        case AArch64::ST1Twov2s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Twov2s_POST\n");
            break;
        }
        case AArch64::ST1Twov4h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Twov4h\n");
            break;
        }
        case AArch64::ST1Twov4h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Twov4h_POST\n");
            break;
        }
        case AArch64::ST1Twov4s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Twov4s\n");
            break;
        }
        case AArch64::ST1Twov4s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Twov4s_POST\n");
            break;
        }
        case AArch64::ST1Twov8b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Twov8b\n");
            break;
        }
        case AArch64::ST1Twov8b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Twov8b_POST\n");
            break;
        }
        case AArch64::ST1Twov8h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Twov8h\n");
            break;
        }
        case AArch64::ST1Twov8h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1Twov8h_POST\n");
            break;
        }
        case AArch64::ST1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1i16\n");
            break;
        }
        case AArch64::ST1i16_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1i16_POST\n");
            break;
        }
        case AArch64::ST1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1i32\n");
            break;
        }
        case AArch64::ST1i32_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1i32_POST\n");
            break;
        }
        case AArch64::ST1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1i64\n");
            break;
        }
        case AArch64::ST1i64_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1i64_POST\n");
            break;
        }
        case AArch64::ST1i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1i8\n");
            break;
        }
        case AArch64::ST1i8_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST1i8_POST\n");
            break;
        }
        case AArch64::ST2Twov16b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2Twov16b\n");
            break;
        }
        case AArch64::ST2Twov16b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2Twov16b_POST\n");
            break;
        }
        case AArch64::ST2Twov2d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2Twov2d\n");
            break;
        }
        case AArch64::ST2Twov2d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2Twov2d_POST\n");
            break;
        }
        case AArch64::ST2Twov2s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2Twov2s\n");
            break;
        }
        case AArch64::ST2Twov2s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2Twov2s_POST\n");
            break;
        }
        case AArch64::ST2Twov4h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2Twov4h\n");
            break;
        }
        case AArch64::ST2Twov4h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2Twov4h_POST\n");
            break;
        }
        case AArch64::ST2Twov4s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2Twov4s\n");
            break;
        }
        case AArch64::ST2Twov4s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2Twov4s_POST\n");
            break;
        }
        case AArch64::ST2Twov8b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2Twov8b\n");
            break;
        }
        case AArch64::ST2Twov8b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2Twov8b_POST\n");
            break;
        }
        case AArch64::ST2Twov8h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2Twov8h\n");
            break;
        }
        case AArch64::ST2Twov8h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2Twov8h_POST\n");
            break;
        }
        case AArch64::ST2i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2i16\n");
            break;
        }
        case AArch64::ST2i16_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2i16_POST\n");
            break;
        }
        case AArch64::ST2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2i32\n");
            break;
        }
        case AArch64::ST2i32_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2i32_POST\n");
            break;
        }
        case AArch64::ST2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2i64\n");
            break;
        }
        case AArch64::ST2i64_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2i64_POST\n");
            break;
        }
        case AArch64::ST2i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2i8\n");
            break;
        }
        case AArch64::ST2i8_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST2i8_POST\n");
            break;
        }
        case AArch64::ST3Threev16b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3Threev16b\n");
            break;
        }
        case AArch64::ST3Threev16b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3Threev16b_POST\n");
            break;
        }
        case AArch64::ST3Threev2d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3Threev2d\n");
            break;
        }
        case AArch64::ST3Threev2d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3Threev2d_POST\n");
            break;
        }
        case AArch64::ST3Threev2s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3Threev2s\n");
            break;
        }
        case AArch64::ST3Threev2s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3Threev2s_POST\n");
            break;
        }
        case AArch64::ST3Threev4h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3Threev4h\n");
            break;
        }
        case AArch64::ST3Threev4h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3Threev4h_POST\n");
            break;
        }
        case AArch64::ST3Threev4s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3Threev4s\n");
            break;
        }
        case AArch64::ST3Threev4s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3Threev4s_POST\n");
            break;
        }
        case AArch64::ST3Threev8b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3Threev8b\n");
            break;
        }
        case AArch64::ST3Threev8b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3Threev8b_POST\n");
            break;
        }
        case AArch64::ST3Threev8h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3Threev8h\n");
            break;
        }
        case AArch64::ST3Threev8h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3Threev8h_POST\n");
            break;
        }
        case AArch64::ST3i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3i16\n");
            break;
        }
        case AArch64::ST3i16_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3i16_POST\n");
            break;
        }
        case AArch64::ST3i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3i32\n");
            break;
        }
        case AArch64::ST3i32_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3i32_POST\n");
            break;
        }
        case AArch64::ST3i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3i64\n");
            break;
        }
        case AArch64::ST3i64_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3i64_POST\n");
            break;
        }
        case AArch64::ST3i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3i8\n");
            break;
        }
        case AArch64::ST3i8_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST3i8_POST\n");
            break;
        }
        case AArch64::ST4Fourv16b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4Fourv16b\n");
            break;
        }
        case AArch64::ST4Fourv16b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4Fourv16b_POST\n");
            break;
        }
        case AArch64::ST4Fourv2d: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4Fourv2d\n");
            break;
        }
        case AArch64::ST4Fourv2d_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4Fourv2d_POST\n");
            break;
        }
        case AArch64::ST4Fourv2s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4Fourv2s\n");
            break;
        }
        case AArch64::ST4Fourv2s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4Fourv2s_POST\n");
            break;
        }
        case AArch64::ST4Fourv4h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4Fourv4h\n");
            break;
        }
        case AArch64::ST4Fourv4h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4Fourv4h_POST\n");
            break;
        }
        case AArch64::ST4Fourv4s: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4Fourv4s\n");
            break;
        }
        case AArch64::ST4Fourv4s_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4Fourv4s_POST\n");
            break;
        }
        case AArch64::ST4Fourv8b: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4Fourv8b\n");
            break;
        }
        case AArch64::ST4Fourv8b_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4Fourv8b_POST\n");
            break;
        }
        case AArch64::ST4Fourv8h: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4Fourv8h\n");
            break;
        }
        case AArch64::ST4Fourv8h_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4Fourv8h_POST\n");
            break;
        }
        case AArch64::ST4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4i16\n");
            break;
        }
        case AArch64::ST4i16_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4i16_POST\n");
            break;
        }
        case AArch64::ST4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4i32\n");
            break;
        }
        case AArch64::ST4i32_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4i32_POST\n");
            break;
        }
        case AArch64::ST4i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4i64\n");
            break;
        }
        case AArch64::ST4i64_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4i64_POST\n");
            break;
        }
        case AArch64::ST4i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4i8\n");
            break;
        }
        case AArch64::ST4i8_POST: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ST4i8_POST\n");
            break;
        }
        case AArch64::STLLRB: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STLLRB\n");
            break;
        }
        case AArch64::STLLRH: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STLLRH\n");
            break;
        }
        case AArch64::STLLRW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STLLRW\n");
            break;
        }
        case AArch64::STLLRX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STLLRX\n");
            break;
        }
        case AArch64::STLRB: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STLRB\n");
            break;
        }
        case AArch64::STLRH: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STLRH\n");
            break;
        }
        case AArch64::STLRW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STLRW\n");
            break;
        }
        case AArch64::STLRX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STLRX\n");
            break;
        }
        case AArch64::STLXPW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STLXPW\n");
            break;
        }
        case AArch64::STLXPX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STLXPX\n");
            break;
        }
        case AArch64::STLXRB: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STLXRB\n");
            break;
        }
        case AArch64::STLXRH: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STLXRH\n");
            break;
        }
        case AArch64::STLXRW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STLXRW\n");
            break;
        }
        case AArch64::STLXRX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STLXRX\n");
            break;
        }
        case AArch64::STNPDi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STNPDi\n");
            break;
        }
        case AArch64::STNPQi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STNPQi\n");
            break;
        }
        case AArch64::STNPSi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STNPSi\n");
            break;
        }
        case AArch64::STNPWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STNPWi\n");
            break;
        }
        case AArch64::STNPXi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STNPXi\n");
            break;
        }
        case AArch64::STPDi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STPDi\n");
            break;
        }
        case AArch64::STPDpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STPDpost\n");
            break;
        }
        case AArch64::STPDpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STPDpre\n");
            break;
        }
        case AArch64::STPQi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STPQi\n");
            break;
        }
        case AArch64::STPQpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STPQpost\n");
            break;
        }
        case AArch64::STPQpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STPQpre\n");
            break;
        }
        case AArch64::STPSi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STPSi\n");
            break;
        }
        case AArch64::STPSpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STPSpost\n");
            break;
        }
        case AArch64::STPSpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STPSpre\n");
            break;
        }
        case AArch64::STPWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STPWi\n");
            break;
        }
        case AArch64::STPWpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STPWpost\n");
            break;
        }
        case AArch64::STPWpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STPWpre\n");
            break;
        }
        case AArch64::STPXi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STPXi\n");
            break;
        }
        case AArch64::STPXpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STPXpost\n");
            break;
        }
        case AArch64::STPXpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STPXpre\n");
            break;
        }
        case AArch64::STRBBpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRBBpost\n");
            break;
        }
        case AArch64::STRBBpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRBBpre\n");
            break;
        }
        case AArch64::STRBBroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRBBroW\n");
            break;
        }
        case AArch64::STRBBroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRBBroX\n");
            break;
        }
        case AArch64::STRBBui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRBBui\n");
            break;
        }
        case AArch64::STRBpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRBpost\n");
            break;
        }
        case AArch64::STRBpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRBpre\n");
            break;
        }
        case AArch64::STRBroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRBroW\n");
            break;
        }
        case AArch64::STRBroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRBroX\n");
            break;
        }
        case AArch64::STRBui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRBui\n");
            break;
        }
        case AArch64::STRDpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRDpost\n");
            break;
        }
        case AArch64::STRDpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRDpre\n");
            break;
        }
        case AArch64::STRDroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRDroW\n");
            break;
        }
        case AArch64::STRDroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRDroX\n");
            break;
        }
        case AArch64::STRDui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRDui\n");
            break;
        }
        case AArch64::STRHHpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRHHpost\n");
            break;
        }
        case AArch64::STRHHpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRHHpre\n");
            break;
        }
        case AArch64::STRHHroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRHHroW\n");
            break;
        }
        case AArch64::STRHHroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRHHroX\n");
            break;
        }
        case AArch64::STRHHui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRHHui\n");
            break;
        }
        case AArch64::STRHpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRHpost\n");
            break;
        }
        case AArch64::STRHpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRHpre\n");
            break;
        }
        case AArch64::STRHroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRHroW\n");
            break;
        }
        case AArch64::STRHroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRHroX\n");
            break;
        }
        case AArch64::STRHui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRHui\n");
            break;
        }
        case AArch64::STRQpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRQpost\n");
            break;
        }
        case AArch64::STRQpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRQpre\n");
            break;
        }
        case AArch64::STRQroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRQroW\n");
            break;
        }
        case AArch64::STRQroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRQroX\n");
            break;
        }
        case AArch64::STRQui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRQui\n");
            break;
        }
        case AArch64::STRSpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRSpost\n");
            break;
        }
        case AArch64::STRSpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRSpre\n");
            break;
        }
        case AArch64::STRSroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRSroW\n");
            break;
        }
        case AArch64::STRSroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRSroX\n");
            break;
        }
        case AArch64::STRSui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRSui\n");
            break;
        }
        case AArch64::STRWpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRWpost\n");
            break;
        }
        case AArch64::STRWpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRWpre\n");
            break;
        }
        case AArch64::STRWroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRWroW\n");
            break;
        }
        case AArch64::STRWroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRWroX\n");
            break;
        }
        case AArch64::STRWui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRWui\n");
            break;
        }
        case AArch64::STRXpost: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRXpost\n");
            break;
        }
        case AArch64::STRXpre: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRXpre\n");
            break;
        }
        case AArch64::STRXroW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRXroW\n");
            break;
        }
        case AArch64::STRXroX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRXroX\n");
            break;
        }
        case AArch64::STRXui: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STRXui\n");
            break;
        }
        case AArch64::STTRBi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STTRBi\n");
            break;
        }
        case AArch64::STTRHi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STTRHi\n");
            break;
        }
        case AArch64::STTRWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STTRWi\n");
            break;
        }
        case AArch64::STTRXi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STTRXi\n");
            break;
        }
        case AArch64::STURBBi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STURBBi\n");
            break;
        }
        case AArch64::STURBi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STURBi\n");
            break;
        }
        case AArch64::STURDi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STURDi\n");
            break;
        }
        case AArch64::STURHHi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STURHHi\n");
            break;
        }
        case AArch64::STURHi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STURHi\n");
            break;
        }
        case AArch64::STURQi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STURQi\n");
            break;
        }
        case AArch64::STURSi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STURSi\n");
            break;
        }
        case AArch64::STURWi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STURWi\n");
            break;
        }
        case AArch64::STURXi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STURXi\n");
            break;
        }
        case AArch64::STXPW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STXPW\n");
            break;
        }
        case AArch64::STXPX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STXPX\n");
            break;
        }
        case AArch64::STXRB: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STXRB\n");
            break;
        }
        case AArch64::STXRH: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STXRH\n");
            break;
        }
        case AArch64::STXRW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STXRW\n");
            break;
        }
        case AArch64::STXRX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " STXRX\n");
            break;
        }
        case AArch64::SUBHNv2i64_v2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBHNv2i64_v2i32\n");
            break;
        }
        case AArch64::SUBHNv2i64_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBHNv2i64_v4i32\n");
            break;
        }
        case AArch64::SUBHNv4i32_v4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBHNv4i32_v4i16\n");
            break;
        }
        case AArch64::SUBHNv4i32_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBHNv4i32_v8i16\n");
            break;
        }
        case AArch64::SUBHNv8i16_v16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBHNv8i16_v16i8\n");
            break;
        }
        case AArch64::SUBHNv8i16_v8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBHNv8i16_v8i8\n");
            break;
        }
        case AArch64::SUBSWri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBSWri\n");
            break;
        }
        case AArch64::SUBSWrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBSWrr\n");
            break;
        }
        case AArch64::SUBSWrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBSWrs\n");
            break;
        }
        case AArch64::SUBSWrx: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBSWrx\n");
            break;
        }
        case AArch64::SUBSXri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBSXri\n");
            break;
        }
        case AArch64::SUBSXrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBSXrr\n");
            break;
        }
        case AArch64::SUBSXrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBSXrs\n");
            break;
        }
        case AArch64::SUBSXrx: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBSXrx\n");
            break;
        }
        case AArch64::SUBSXrx64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBSXrx64\n");
            break;
        }
        case AArch64::SUBWri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBWri\n");
            break;
        }
        case AArch64::SUBWrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBWrr\n");
            break;
        }
        case AArch64::SUBWrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBWrs\n");
            break;
        }
        case AArch64::SUBWrx: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBWrx\n");
            break;
        }
        case AArch64::SUBXri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBXri\n");
            break;
        }
        case AArch64::SUBXrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBXrr\n");
            break;
        }
        case AArch64::SUBXrs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBXrs\n");
            break;
        }
        case AArch64::SUBXrx: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBXrx\n");
            break;
        }
        case AArch64::SUBXrx64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBXrx64\n");
            break;
        }
        case AArch64::SUBv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBv16i8\n");
            break;
        }
        case AArch64::SUBv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBv1i64\n");
            break;
        }
        case AArch64::SUBv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBv2i32\n");
            break;
        }
        case AArch64::SUBv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBv2i64\n");
            break;
        }
        case AArch64::SUBv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBv4i16\n");
            break;
        }
        case AArch64::SUBv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBv4i32\n");
            break;
        }
        case AArch64::SUBv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBv8i16\n");
            break;
        }
        case AArch64::SUBv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUBv8i8\n");
            break;
        }
        case AArch64::SUQADDv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUQADDv16i8\n");
            break;
        }
        case AArch64::SUQADDv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUQADDv1i16\n");
            break;
        }
        case AArch64::SUQADDv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUQADDv1i32\n");
            break;
        }
        case AArch64::SUQADDv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUQADDv1i64\n");
            break;
        }
        case AArch64::SUQADDv1i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUQADDv1i8\n");
            break;
        }
        case AArch64::SUQADDv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUQADDv2i32\n");
            break;
        }
        case AArch64::SUQADDv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUQADDv2i64\n");
            break;
        }
        case AArch64::SUQADDv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUQADDv4i16\n");
            break;
        }
        case AArch64::SUQADDv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUQADDv4i32\n");
            break;
        }
        case AArch64::SUQADDv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUQADDv8i16\n");
            break;
        }
        case AArch64::SUQADDv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SUQADDv8i8\n");
            break;
        }
        case AArch64::SVC: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SVC\n");
            break;
        }
        case AArch64::SWPALb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SWPALb\n");
            break;
        }
        case AArch64::SWPALd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SWPALd\n");
            break;
        }
        case AArch64::SWPALh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SWPALh\n");
            break;
        }
        case AArch64::SWPALs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SWPALs\n");
            break;
        }
        case AArch64::SWPAb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SWPAb\n");
            break;
        }
        case AArch64::SWPAd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SWPAd\n");
            break;
        }
        case AArch64::SWPAh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SWPAh\n");
            break;
        }
        case AArch64::SWPAs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SWPAs\n");
            break;
        }
        case AArch64::SWPLb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SWPLb\n");
            break;
        }
        case AArch64::SWPLd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SWPLd\n");
            break;
        }
        case AArch64::SWPLh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SWPLh\n");
            break;
        }
        case AArch64::SWPLs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SWPLs\n");
            break;
        }
        case AArch64::SWPb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SWPb\n");
            break;
        }
        case AArch64::SWPd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SWPd\n");
            break;
        }
        case AArch64::SWPh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SWPh\n");
            break;
        }
        case AArch64::SWPs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SWPs\n");
            break;
        }
        case AArch64::SYSLxt: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SYSLxt\n");
            break;
        }
        case AArch64::SYSxt: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " SYSxt\n");
            break;
        }
        case AArch64::TBLv16i8Four: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBLv16i8Four\n");
            break;
        }
        case AArch64::TBLv16i8One: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBLv16i8One\n");
            break;
        }
        case AArch64::TBLv16i8Three: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBLv16i8Three\n");
            break;
        }
        case AArch64::TBLv16i8Two: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBLv16i8Two\n");
            break;
        }
        case AArch64::TBLv8i8Four: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBLv8i8Four\n");
            break;
        }
        case AArch64::TBLv8i8One: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBLv8i8One\n");
            break;
        }
        case AArch64::TBLv8i8Three: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBLv8i8Three\n");
            break;
        }
        case AArch64::TBLv8i8Two: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBLv8i8Two\n");
            break;
        }
        case AArch64::TBNZW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBNZW\n");
            break;
        }
        case AArch64::TBNZX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBNZX\n");
            break;
        }
        case AArch64::TBXv16i8Four: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBXv16i8Four\n");
            break;
        }
        case AArch64::TBXv16i8One: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBXv16i8One\n");
            break;
        }
        case AArch64::TBXv16i8Three: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBXv16i8Three\n");
            break;
        }
        case AArch64::TBXv16i8Two: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBXv16i8Two\n");
            break;
        }
        case AArch64::TBXv8i8Four: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBXv8i8Four\n");
            break;
        }
        case AArch64::TBXv8i8One: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBXv8i8One\n");
            break;
        }
        case AArch64::TBXv8i8Three: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBXv8i8Three\n");
            break;
        }
        case AArch64::TBXv8i8Two: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBXv8i8Two\n");
            break;
        }
        case AArch64::TBZW: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBZW\n");
            break;
        }
        case AArch64::TBZX: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TBZX\n");
            break;
        }
        case AArch64::TCRETURNdi: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TCRETURNdi\n");
            break;
        }
        case AArch64::TCRETURNri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TCRETURNri\n");
            break;
        }
        case AArch64::TLSDESCCALL: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TLSDESCCALL\n");
            break;
        }
        case AArch64::TLSDESC_CALLSEQ: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TLSDESC_CALLSEQ\n");
            break;
        }
        case AArch64::TRN1v16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TRN1v16i8\n");
            break;
        }
        case AArch64::TRN1v2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TRN1v2i32\n");
            break;
        }
        case AArch64::TRN1v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TRN1v2i64\n");
            break;
        }
        case AArch64::TRN1v4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TRN1v4i16\n");
            break;
        }
        case AArch64::TRN1v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TRN1v4i32\n");
            break;
        }
        case AArch64::TRN1v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TRN1v8i16\n");
            break;
        }
        case AArch64::TRN1v8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TRN1v8i8\n");
            break;
        }
        case AArch64::TRN2v16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TRN2v16i8\n");
            break;
        }
        case AArch64::TRN2v2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TRN2v2i32\n");
            break;
        }
        case AArch64::TRN2v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TRN2v2i64\n");
            break;
        }
        case AArch64::TRN2v4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TRN2v4i16\n");
            break;
        }
        case AArch64::TRN2v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TRN2v4i32\n");
            break;
        }
        case AArch64::TRN2v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TRN2v8i16\n");
            break;
        }
        case AArch64::TRN2v8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " TRN2v8i8\n");
            break;
        }
        case AArch64::UABALv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABALv16i8_v8i16\n");
            break;
        }
        case AArch64::UABALv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABALv2i32_v2i64\n");
            break;
        }
        case AArch64::UABALv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABALv4i16_v4i32\n");
            break;
        }
        case AArch64::UABALv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABALv4i32_v2i64\n");
            break;
        }
        case AArch64::UABALv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABALv8i16_v4i32\n");
            break;
        }
        case AArch64::UABALv8i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABALv8i8_v8i16\n");
            break;
        }
        case AArch64::UABAv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABAv16i8\n");
            break;
        }
        case AArch64::UABAv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABAv2i32\n");
            break;
        }
        case AArch64::UABAv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABAv4i16\n");
            break;
        }
        case AArch64::UABAv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABAv4i32\n");
            break;
        }
        case AArch64::UABAv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABAv8i16\n");
            break;
        }
        case AArch64::UABAv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABAv8i8\n");
            break;
        }
        case AArch64::UABDLv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABDLv16i8_v8i16\n");
            break;
        }
        case AArch64::UABDLv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABDLv2i32_v2i64\n");
            break;
        }
        case AArch64::UABDLv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABDLv4i16_v4i32\n");
            break;
        }
        case AArch64::UABDLv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABDLv4i32_v2i64\n");
            break;
        }
        case AArch64::UABDLv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABDLv8i16_v4i32\n");
            break;
        }
        case AArch64::UABDLv8i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABDLv8i8_v8i16\n");
            break;
        }
        case AArch64::UABDv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABDv16i8\n");
            break;
        }
        case AArch64::UABDv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABDv2i32\n");
            break;
        }
        case AArch64::UABDv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABDv4i16\n");
            break;
        }
        case AArch64::UABDv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABDv4i32\n");
            break;
        }
        case AArch64::UABDv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABDv8i16\n");
            break;
        }
        case AArch64::UABDv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UABDv8i8\n");
            break;
        }
        case AArch64::UADALPv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADALPv16i8_v8i16\n");
            break;
        }
        case AArch64::UADALPv2i32_v1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADALPv2i32_v1i64\n");
            break;
        }
        case AArch64::UADALPv4i16_v2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADALPv4i16_v2i32\n");
            break;
        }
        case AArch64::UADALPv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADALPv4i32_v2i64\n");
            break;
        }
        case AArch64::UADALPv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADALPv8i16_v4i32\n");
            break;
        }
        case AArch64::UADALPv8i8_v4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADALPv8i8_v4i16\n");
            break;
        }
        case AArch64::UADDLPv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDLPv16i8_v8i16\n");
            break;
        }
        case AArch64::UADDLPv2i32_v1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDLPv2i32_v1i64\n");
            break;
        }
        case AArch64::UADDLPv4i16_v2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDLPv4i16_v2i32\n");
            break;
        }
        case AArch64::UADDLPv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDLPv4i32_v2i64\n");
            break;
        }
        case AArch64::UADDLPv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDLPv8i16_v4i32\n");
            break;
        }
        case AArch64::UADDLPv8i8_v4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDLPv8i8_v4i16\n");
            break;
        }
        case AArch64::UADDLVv16i8v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDLVv16i8v\n");
            break;
        }
        case AArch64::UADDLVv4i16v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDLVv4i16v\n");
            break;
        }
        case AArch64::UADDLVv4i32v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDLVv4i32v\n");
            break;
        }
        case AArch64::UADDLVv8i16v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDLVv8i16v\n");
            break;
        }
        case AArch64::UADDLVv8i8v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDLVv8i8v\n");
            break;
        }
        case AArch64::UADDLv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDLv16i8_v8i16\n");
            break;
        }
        case AArch64::UADDLv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDLv2i32_v2i64\n");
            break;
        }
        case AArch64::UADDLv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDLv4i16_v4i32\n");
            break;
        }
        case AArch64::UADDLv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDLv4i32_v2i64\n");
            break;
        }
        case AArch64::UADDLv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDLv8i16_v4i32\n");
            break;
        }
        case AArch64::UADDLv8i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDLv8i8_v8i16\n");
            break;
        }
        case AArch64::UADDWv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDWv16i8_v8i16\n");
            break;
        }
        case AArch64::UADDWv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDWv2i32_v2i64\n");
            break;
        }
        case AArch64::UADDWv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDWv4i16_v4i32\n");
            break;
        }
        case AArch64::UADDWv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDWv4i32_v2i64\n");
            break;
        }
        case AArch64::UADDWv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDWv8i16_v4i32\n");
            break;
        }
        case AArch64::UADDWv8i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UADDWv8i8_v8i16\n");
            break;
        }
        case AArch64::UBFMWri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UBFMWri\n");
            break;
        }
        case AArch64::UBFMXri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UBFMXri\n");
            break;
        }
        case AArch64::UCVTFSWDri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UCVTFSWDri\n");
            break;
        }
        case AArch64::UCVTFSWSri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UCVTFSWSri\n");
            break;
        }
        case AArch64::UCVTFSXDri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UCVTFSXDri\n");
            break;
        }
        case AArch64::UCVTFSXSri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UCVTFSXSri\n");
            break;
        }
        case AArch64::UCVTFUWDri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UCVTFUWDri\n");
            break;
        }
        case AArch64::UCVTFUWSri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UCVTFUWSri\n");
            break;
        }
        case AArch64::UCVTFUXDri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UCVTFUXDri\n");
            break;
        }
        case AArch64::UCVTFUXSri: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UCVTFUXSri\n");
            break;
        }
        case AArch64::UCVTFd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UCVTFd\n");
            break;
        }
        case AArch64::UCVTFs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UCVTFs\n");
            break;
        }
        case AArch64::UCVTFv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UCVTFv1i32\n");
            break;
        }
        case AArch64::UCVTFv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UCVTFv1i64\n");
            break;
        }
        case AArch64::UCVTFv2f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UCVTFv2f32\n");
            break;
        }
        case AArch64::UCVTFv2f64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UCVTFv2f64\n");
            break;
        }
        case AArch64::UCVTFv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UCVTFv2i32_shift\n");
            break;
        }
        case AArch64::UCVTFv2i64_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UCVTFv2i64_shift\n");
            break;
        }
        case AArch64::UCVTFv4f32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UCVTFv4f32\n");
            break;
        }
        case AArch64::UCVTFv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UCVTFv4i32_shift\n");
            break;
        }
        case AArch64::UDIVWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UDIVWr\n");
            break;
        }
        case AArch64::UDIVXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UDIVXr\n");
            break;
        }
        case AArch64::UDIV_IntWr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UDIV_IntWr\n");
            break;
        }
        case AArch64::UDIV_IntXr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UDIV_IntXr\n");
            break;
        }
        case AArch64::UHADDv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UHADDv16i8\n");
            break;
        }
        case AArch64::UHADDv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UHADDv2i32\n");
            break;
        }
        case AArch64::UHADDv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UHADDv4i16\n");
            break;
        }
        case AArch64::UHADDv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UHADDv4i32\n");
            break;
        }
        case AArch64::UHADDv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UHADDv8i16\n");
            break;
        }
        case AArch64::UHADDv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UHADDv8i8\n");
            break;
        }
        case AArch64::UHSUBv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UHSUBv16i8\n");
            break;
        }
        case AArch64::UHSUBv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UHSUBv2i32\n");
            break;
        }
        case AArch64::UHSUBv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UHSUBv4i16\n");
            break;
        }
        case AArch64::UHSUBv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UHSUBv4i32\n");
            break;
        }
        case AArch64::UHSUBv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UHSUBv8i16\n");
            break;
        }
        case AArch64::UHSUBv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UHSUBv8i8\n");
            break;
        }
        case AArch64::UMADDLrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMADDLrrr\n");
            break;
        }
        case AArch64::UMAXPv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMAXPv16i8\n");
            break;
        }
        case AArch64::UMAXPv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMAXPv2i32\n");
            break;
        }
        case AArch64::UMAXPv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMAXPv4i16\n");
            break;
        }
        case AArch64::UMAXPv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMAXPv4i32\n");
            break;
        }
        case AArch64::UMAXPv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMAXPv8i16\n");
            break;
        }
        case AArch64::UMAXPv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMAXPv8i8\n");
            break;
        }
        case AArch64::UMAXVv16i8v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMAXVv16i8v\n");
            break;
        }
        case AArch64::UMAXVv4i16v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMAXVv4i16v\n");
            break;
        }
        case AArch64::UMAXVv4i32v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMAXVv4i32v\n");
            break;
        }
        case AArch64::UMAXVv8i16v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMAXVv8i16v\n");
            break;
        }
        case AArch64::UMAXVv8i8v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMAXVv8i8v\n");
            break;
        }
        case AArch64::UMAXv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMAXv16i8\n");
            break;
        }
        case AArch64::UMAXv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMAXv2i32\n");
            break;
        }
        case AArch64::UMAXv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMAXv4i16\n");
            break;
        }
        case AArch64::UMAXv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMAXv4i32\n");
            break;
        }
        case AArch64::UMAXv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMAXv8i16\n");
            break;
        }
        case AArch64::UMAXv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMAXv8i8\n");
            break;
        }
        case AArch64::UMINPv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMINPv16i8\n");
            break;
        }
        case AArch64::UMINPv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMINPv2i32\n");
            break;
        }
        case AArch64::UMINPv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMINPv4i16\n");
            break;
        }
        case AArch64::UMINPv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMINPv4i32\n");
            break;
        }
        case AArch64::UMINPv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMINPv8i16\n");
            break;
        }
        case AArch64::UMINPv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMINPv8i8\n");
            break;
        }
        case AArch64::UMINVv16i8v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMINVv16i8v\n");
            break;
        }
        case AArch64::UMINVv4i16v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMINVv4i16v\n");
            break;
        }
        case AArch64::UMINVv4i32v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMINVv4i32v\n");
            break;
        }
        case AArch64::UMINVv8i16v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMINVv8i16v\n");
            break;
        }
        case AArch64::UMINVv8i8v: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMINVv8i8v\n");
            break;
        }
        case AArch64::UMINv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMINv16i8\n");
            break;
        }
        case AArch64::UMINv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMINv2i32\n");
            break;
        }
        case AArch64::UMINv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMINv4i16\n");
            break;
        }
        case AArch64::UMINv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMINv4i32\n");
            break;
        }
        case AArch64::UMINv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMINv8i16\n");
            break;
        }
        case AArch64::UMINv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMINv8i8\n");
            break;
        }
        case AArch64::UMLALv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLALv16i8_v8i16\n");
            break;
        }
        case AArch64::UMLALv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLALv2i32_indexed\n");
            break;
        }
        case AArch64::UMLALv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLALv2i32_v2i64\n");
            break;
        }
        case AArch64::UMLALv4i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLALv4i16_indexed\n");
            break;
        }
        case AArch64::UMLALv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLALv4i16_v4i32\n");
            break;
        }
        case AArch64::UMLALv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLALv4i32_indexed\n");
            break;
        }
        case AArch64::UMLALv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLALv4i32_v2i64\n");
            break;
        }
        case AArch64::UMLALv8i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLALv8i16_indexed\n");
            break;
        }
        case AArch64::UMLALv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLALv8i16_v4i32\n");
            break;
        }
        case AArch64::UMLALv8i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLALv8i8_v8i16\n");
            break;
        }
        case AArch64::UMLSLv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLSLv16i8_v8i16\n");
            break;
        }
        case AArch64::UMLSLv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLSLv2i32_indexed\n");
            break;
        }
        case AArch64::UMLSLv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLSLv2i32_v2i64\n");
            break;
        }
        case AArch64::UMLSLv4i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLSLv4i16_indexed\n");
            break;
        }
        case AArch64::UMLSLv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLSLv4i16_v4i32\n");
            break;
        }
        case AArch64::UMLSLv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLSLv4i32_indexed\n");
            break;
        }
        case AArch64::UMLSLv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLSLv4i32_v2i64\n");
            break;
        }
        case AArch64::UMLSLv8i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLSLv8i16_indexed\n");
            break;
        }
        case AArch64::UMLSLv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLSLv8i16_v4i32\n");
            break;
        }
        case AArch64::UMLSLv8i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMLSLv8i8_v8i16\n");
            break;
        }
        case AArch64::UMOVvi16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMOVvi16\n");
            break;
        }
        case AArch64::UMOVvi32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMOVvi32\n");
            break;
        }
        case AArch64::UMOVvi64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMOVvi64\n");
            break;
        }
        case AArch64::UMOVvi8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMOVvi8\n");
            break;
        }
        case AArch64::UMSUBLrrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMSUBLrrr\n");
            break;
        }
        case AArch64::UMULHrr: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMULHrr\n");
            break;
        }
        case AArch64::UMULLv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMULLv16i8_v8i16\n");
            break;
        }
        case AArch64::UMULLv2i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMULLv2i32_indexed\n");
            break;
        }
        case AArch64::UMULLv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMULLv2i32_v2i64\n");
            break;
        }
        case AArch64::UMULLv4i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMULLv4i16_indexed\n");
            break;
        }
        case AArch64::UMULLv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMULLv4i16_v4i32\n");
            break;
        }
        case AArch64::UMULLv4i32_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMULLv4i32_indexed\n");
            break;
        }
        case AArch64::UMULLv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMULLv4i32_v2i64\n");
            break;
        }
        case AArch64::UMULLv8i16_indexed: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMULLv8i16_indexed\n");
            break;
        }
        case AArch64::UMULLv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMULLv8i16_v4i32\n");
            break;
        }
        case AArch64::UMULLv8i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UMULLv8i8_v8i16\n");
            break;
        }
        case AArch64::UQADDv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQADDv16i8\n");
            break;
        }
        case AArch64::UQADDv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQADDv1i16\n");
            break;
        }
        case AArch64::UQADDv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQADDv1i32\n");
            break;
        }
        case AArch64::UQADDv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQADDv1i64\n");
            break;
        }
        case AArch64::UQADDv1i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQADDv1i8\n");
            break;
        }
        case AArch64::UQADDv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQADDv2i32\n");
            break;
        }
        case AArch64::UQADDv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQADDv2i64\n");
            break;
        }
        case AArch64::UQADDv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQADDv4i16\n");
            break;
        }
        case AArch64::UQADDv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQADDv4i32\n");
            break;
        }
        case AArch64::UQADDv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQADDv8i16\n");
            break;
        }
        case AArch64::UQADDv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQADDv8i8\n");
            break;
        }
        case AArch64::UQRSHLv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHLv16i8\n");
            break;
        }
        case AArch64::UQRSHLv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHLv1i16\n");
            break;
        }
        case AArch64::UQRSHLv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHLv1i32\n");
            break;
        }
        case AArch64::UQRSHLv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHLv1i64\n");
            break;
        }
        case AArch64::UQRSHLv1i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHLv1i8\n");
            break;
        }
        case AArch64::UQRSHLv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHLv2i32\n");
            break;
        }
        case AArch64::UQRSHLv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHLv2i64\n");
            break;
        }
        case AArch64::UQRSHLv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHLv4i16\n");
            break;
        }
        case AArch64::UQRSHLv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHLv4i32\n");
            break;
        }
        case AArch64::UQRSHLv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHLv8i16\n");
            break;
        }
        case AArch64::UQRSHLv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHLv8i8\n");
            break;
        }
        case AArch64::UQRSHRNb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHRNb\n");
            break;
        }
        case AArch64::UQRSHRNh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHRNh\n");
            break;
        }
        case AArch64::UQRSHRNs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHRNs\n");
            break;
        }
        case AArch64::UQRSHRNv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHRNv16i8_shift\n");
            break;
        }
        case AArch64::UQRSHRNv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHRNv2i32_shift\n");
            break;
        }
        case AArch64::UQRSHRNv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHRNv4i16_shift\n");
            break;
        }
        case AArch64::UQRSHRNv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHRNv4i32_shift\n");
            break;
        }
        case AArch64::UQRSHRNv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHRNv8i16_shift\n");
            break;
        }
        case AArch64::UQRSHRNv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQRSHRNv8i8_shift\n");
            break;
        }
        case AArch64::UQSHLb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLb\n");
            break;
        }
        case AArch64::UQSHLd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLd\n");
            break;
        }
        case AArch64::UQSHLh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLh\n");
            break;
        }
        case AArch64::UQSHLs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLs\n");
            break;
        }
        case AArch64::UQSHLv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLv16i8\n");
            break;
        }
        case AArch64::UQSHLv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLv16i8_shift\n");
            break;
        }
        case AArch64::UQSHLv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLv1i16\n");
            break;
        }
        case AArch64::UQSHLv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLv1i32\n");
            break;
        }
        case AArch64::UQSHLv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLv1i64\n");
            break;
        }
        case AArch64::UQSHLv1i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLv1i8\n");
            break;
        }
        case AArch64::UQSHLv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLv2i32\n");
            break;
        }
        case AArch64::UQSHLv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLv2i32_shift\n");
            break;
        }
        case AArch64::UQSHLv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLv2i64\n");
            break;
        }
        case AArch64::UQSHLv2i64_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLv2i64_shift\n");
            break;
        }
        case AArch64::UQSHLv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLv4i16\n");
            break;
        }
        case AArch64::UQSHLv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLv4i16_shift\n");
            break;
        }
        case AArch64::UQSHLv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLv4i32\n");
            break;
        }
        case AArch64::UQSHLv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLv4i32_shift\n");
            break;
        }
        case AArch64::UQSHLv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLv8i16\n");
            break;
        }
        case AArch64::UQSHLv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLv8i16_shift\n");
            break;
        }
        case AArch64::UQSHLv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLv8i8\n");
            break;
        }
        case AArch64::UQSHLv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHLv8i8_shift\n");
            break;
        }
        case AArch64::UQSHRNb: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHRNb\n");
            break;
        }
        case AArch64::UQSHRNh: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHRNh\n");
            break;
        }
        case AArch64::UQSHRNs: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHRNs\n");
            break;
        }
        case AArch64::UQSHRNv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHRNv16i8_shift\n");
            break;
        }
        case AArch64::UQSHRNv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHRNv2i32_shift\n");
            break;
        }
        case AArch64::UQSHRNv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHRNv4i16_shift\n");
            break;
        }
        case AArch64::UQSHRNv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHRNv4i32_shift\n");
            break;
        }
        case AArch64::UQSHRNv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHRNv8i16_shift\n");
            break;
        }
        case AArch64::UQSHRNv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSHRNv8i8_shift\n");
            break;
        }
        case AArch64::UQSUBv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSUBv16i8\n");
            break;
        }
        case AArch64::UQSUBv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSUBv1i16\n");
            break;
        }
        case AArch64::UQSUBv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSUBv1i32\n");
            break;
        }
        case AArch64::UQSUBv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSUBv1i64\n");
            break;
        }
        case AArch64::UQSUBv1i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSUBv1i8\n");
            break;
        }
        case AArch64::UQSUBv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSUBv2i32\n");
            break;
        }
        case AArch64::UQSUBv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSUBv2i64\n");
            break;
        }
        case AArch64::UQSUBv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSUBv4i16\n");
            break;
        }
        case AArch64::UQSUBv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSUBv4i32\n");
            break;
        }
        case AArch64::UQSUBv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSUBv8i16\n");
            break;
        }
        case AArch64::UQSUBv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQSUBv8i8\n");
            break;
        }
        case AArch64::UQXTNv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQXTNv16i8\n");
            break;
        }
        case AArch64::UQXTNv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQXTNv1i16\n");
            break;
        }
        case AArch64::UQXTNv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQXTNv1i32\n");
            break;
        }
        case AArch64::UQXTNv1i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQXTNv1i8\n");
            break;
        }
        case AArch64::UQXTNv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQXTNv2i32\n");
            break;
        }
        case AArch64::UQXTNv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQXTNv4i16\n");
            break;
        }
        case AArch64::UQXTNv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQXTNv4i32\n");
            break;
        }
        case AArch64::UQXTNv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQXTNv8i16\n");
            break;
        }
        case AArch64::UQXTNv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UQXTNv8i8\n");
            break;
        }
        case AArch64::URECPEv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URECPEv2i32\n");
            break;
        }
        case AArch64::URECPEv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URECPEv4i32\n");
            break;
        }
        case AArch64::URHADDv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URHADDv16i8\n");
            break;
        }
        case AArch64::URHADDv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URHADDv2i32\n");
            break;
        }
        case AArch64::URHADDv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URHADDv4i16\n");
            break;
        }
        case AArch64::URHADDv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URHADDv4i32\n");
            break;
        }
        case AArch64::URHADDv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URHADDv8i16\n");
            break;
        }
        case AArch64::URHADDv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URHADDv8i8\n");
            break;
        }
        case AArch64::URSHLv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSHLv16i8\n");
            break;
        }
        case AArch64::URSHLv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSHLv1i64\n");
            break;
        }
        case AArch64::URSHLv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSHLv2i32\n");
            break;
        }
        case AArch64::URSHLv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSHLv2i64\n");
            break;
        }
        case AArch64::URSHLv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSHLv4i16\n");
            break;
        }
        case AArch64::URSHLv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSHLv4i32\n");
            break;
        }
        case AArch64::URSHLv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSHLv8i16\n");
            break;
        }
        case AArch64::URSHLv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSHLv8i8\n");
            break;
        }
        case AArch64::URSHRd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSHRd\n");
            break;
        }
        case AArch64::URSHRv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSHRv16i8_shift\n");
            break;
        }
        case AArch64::URSHRv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSHRv2i32_shift\n");
            break;
        }
        case AArch64::URSHRv2i64_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSHRv2i64_shift\n");
            break;
        }
        case AArch64::URSHRv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSHRv4i16_shift\n");
            break;
        }
        case AArch64::URSHRv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSHRv4i32_shift\n");
            break;
        }
        case AArch64::URSHRv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSHRv8i16_shift\n");
            break;
        }
        case AArch64::URSHRv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSHRv8i8_shift\n");
            break;
        }
        case AArch64::URSQRTEv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSQRTEv2i32\n");
            break;
        }
        case AArch64::URSQRTEv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSQRTEv4i32\n");
            break;
        }
        case AArch64::URSRAd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSRAd\n");
            break;
        }
        case AArch64::URSRAv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSRAv16i8_shift\n");
            break;
        }
        case AArch64::URSRAv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSRAv2i32_shift\n");
            break;
        }
        case AArch64::URSRAv2i64_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSRAv2i64_shift\n");
            break;
        }
        case AArch64::URSRAv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSRAv4i16_shift\n");
            break;
        }
        case AArch64::URSRAv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSRAv4i32_shift\n");
            break;
        }
        case AArch64::URSRAv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSRAv8i16_shift\n");
            break;
        }
        case AArch64::URSRAv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " URSRAv8i8_shift\n");
            break;
        }
        case AArch64::USHLLv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHLLv16i8_shift\n");
            break;
        }
        case AArch64::USHLLv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHLLv2i32_shift\n");
            break;
        }
        case AArch64::USHLLv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHLLv4i16_shift\n");
            break;
        }
        case AArch64::USHLLv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHLLv4i32_shift\n");
            break;
        }
        case AArch64::USHLLv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHLLv8i16_shift\n");
            break;
        }
        case AArch64::USHLLv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHLLv8i8_shift\n");
            break;
        }
        case AArch64::USHLv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHLv16i8\n");
            break;
        }
        case AArch64::USHLv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHLv1i64\n");
            break;
        }
        case AArch64::USHLv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHLv2i32\n");
            break;
        }
        case AArch64::USHLv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHLv2i64\n");
            break;
        }
        case AArch64::USHLv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHLv4i16\n");
            break;
        }
        case AArch64::USHLv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHLv4i32\n");
            break;
        }
        case AArch64::USHLv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHLv8i16\n");
            break;
        }
        case AArch64::USHLv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHLv8i8\n");
            break;
        }
        case AArch64::USHRd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHRd\n");
            break;
        }
        case AArch64::USHRv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHRv16i8_shift\n");
            break;
        }
        case AArch64::USHRv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHRv2i32_shift\n");
            break;
        }
        case AArch64::USHRv2i64_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHRv2i64_shift\n");
            break;
        }
        case AArch64::USHRv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHRv4i16_shift\n");
            break;
        }
        case AArch64::USHRv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHRv4i32_shift\n");
            break;
        }
        case AArch64::USHRv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHRv8i16_shift\n");
            break;
        }
        case AArch64::USHRv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USHRv8i8_shift\n");
            break;
        }
        case AArch64::USQADDv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USQADDv16i8\n");
            break;
        }
        case AArch64::USQADDv1i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USQADDv1i16\n");
            break;
        }
        case AArch64::USQADDv1i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USQADDv1i32\n");
            break;
        }
        case AArch64::USQADDv1i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USQADDv1i64\n");
            break;
        }
        case AArch64::USQADDv1i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USQADDv1i8\n");
            break;
        }
        case AArch64::USQADDv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USQADDv2i32\n");
            break;
        }
        case AArch64::USQADDv2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USQADDv2i64\n");
            break;
        }
        case AArch64::USQADDv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USQADDv4i16\n");
            break;
        }
        case AArch64::USQADDv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USQADDv4i32\n");
            break;
        }
        case AArch64::USQADDv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USQADDv8i16\n");
            break;
        }
        case AArch64::USQADDv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USQADDv8i8\n");
            break;
        }
        case AArch64::USRAd: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USRAd\n");
            break;
        }
        case AArch64::USRAv16i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USRAv16i8_shift\n");
            break;
        }
        case AArch64::USRAv2i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USRAv2i32_shift\n");
            break;
        }
        case AArch64::USRAv2i64_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USRAv2i64_shift\n");
            break;
        }
        case AArch64::USRAv4i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USRAv4i16_shift\n");
            break;
        }
        case AArch64::USRAv4i32_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USRAv4i32_shift\n");
            break;
        }
        case AArch64::USRAv8i16_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USRAv8i16_shift\n");
            break;
        }
        case AArch64::USRAv8i8_shift: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USRAv8i8_shift\n");
            break;
        }
        case AArch64::USUBLv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USUBLv16i8_v8i16\n");
            break;
        }
        case AArch64::USUBLv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USUBLv2i32_v2i64\n");
            break;
        }
        case AArch64::USUBLv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USUBLv4i16_v4i32\n");
            break;
        }
        case AArch64::USUBLv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USUBLv4i32_v2i64\n");
            break;
        }
        case AArch64::USUBLv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USUBLv8i16_v4i32\n");
            break;
        }
        case AArch64::USUBLv8i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USUBLv8i8_v8i16\n");
            break;
        }
        case AArch64::USUBWv16i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USUBWv16i8_v8i16\n");
            break;
        }
        case AArch64::USUBWv2i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USUBWv2i32_v2i64\n");
            break;
        }
        case AArch64::USUBWv4i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USUBWv4i16_v4i32\n");
            break;
        }
        case AArch64::USUBWv4i32_v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USUBWv4i32_v2i64\n");
            break;
        }
        case AArch64::USUBWv8i16_v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USUBWv8i16_v4i32\n");
            break;
        }
        case AArch64::USUBWv8i8_v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " USUBWv8i8_v8i16\n");
            break;
        }
        case AArch64::UZP1v16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UZP1v16i8\n");
            break;
        }
        case AArch64::UZP1v2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UZP1v2i32\n");
            break;
        }
        case AArch64::UZP1v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UZP1v2i64\n");
            break;
        }
        case AArch64::UZP1v4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UZP1v4i16\n");
            break;
        }
        case AArch64::UZP1v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UZP1v4i32\n");
            break;
        }
        case AArch64::UZP1v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UZP1v8i16\n");
            break;
        }
        case AArch64::UZP1v8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UZP1v8i8\n");
            break;
        }
        case AArch64::UZP2v16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UZP2v16i8\n");
            break;
        }
        case AArch64::UZP2v2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UZP2v2i32\n");
            break;
        }
        case AArch64::UZP2v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UZP2v2i64\n");
            break;
        }
        case AArch64::UZP2v4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UZP2v4i16\n");
            break;
        }
        case AArch64::UZP2v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UZP2v4i32\n");
            break;
        }
        case AArch64::UZP2v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UZP2v8i16\n");
            break;
        }
        case AArch64::UZP2v8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " UZP2v8i8\n");
            break;
        }
        case AArch64::XTNv16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " XTNv16i8\n");
            break;
        }
        case AArch64::XTNv2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " XTNv2i32\n");
            break;
        }
        case AArch64::XTNv4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " XTNv4i16\n");
            break;
        }
        case AArch64::XTNv4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " XTNv4i32\n");
            break;
        }
        case AArch64::XTNv8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " XTNv8i16\n");
            break;
        }
        case AArch64::XTNv8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " XTNv8i8\n");
            break;
        }
        case AArch64::ZIP1v16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ZIP1v16i8\n");
            break;
        }
        case AArch64::ZIP1v2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ZIP1v2i32\n");
            break;
        }
        case AArch64::ZIP1v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ZIP1v2i64\n");
            break;
        }
        case AArch64::ZIP1v4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ZIP1v4i16\n");
            break;
        }
        case AArch64::ZIP1v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ZIP1v4i32\n");
            break;
        }
        case AArch64::ZIP1v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ZIP1v8i16\n");
            break;
        }
        case AArch64::ZIP1v8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ZIP1v8i8\n");
            break;
        }
        case AArch64::ZIP2v16i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ZIP2v16i8\n");
            break;
        }
        case AArch64::ZIP2v2i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ZIP2v2i32\n");
            break;
        }
        case AArch64::ZIP2v2i64: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ZIP2v2i64\n");
            break;
        }
        case AArch64::ZIP2v4i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ZIP2v4i16\n");
            break;
        }
        case AArch64::ZIP2v4i32: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ZIP2v4i32\n");
            break;
        }
        case AArch64::ZIP2v8i16: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ZIP2v8i16\n");
            break;
        }
        case AArch64::ZIP2v8i8: {
            LLVM_DEBUG(errs() << "0x" << utohexstr(Address) << " ZIP2v8i8\n");
            break;
        }
    }
}
