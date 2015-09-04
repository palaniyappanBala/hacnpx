#ifndef CAPSTONE_SYSTEMZ_H
#define CAPSTONE_SYSTEMZ_H

/* Capstone Disassembly Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2014 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "platform.h"

#ifdef _MSC_VER
#pragma warning(disable:4201)
#endif

//> Enums corresponding to SystemZ condition codes
typedef enum sysz_cc {
	SYSZ_CC_INVALID = 0,	// invalid CC (default)

	SYSZ_CC_O,
	SYSZ_CC_H,
	SYSZ_CC_NLE,
	SYSZ_CC_L,
	SYSZ_CC_NHE,
	SYSZ_CC_LH,
	SYSZ_CC_NE,
	SYSZ_CC_E,
	SYSZ_CC_NLH,
	SYSZ_CC_HE,
	SYSZ_CC_NL,
	SYSZ_CC_LE,
	SYSZ_CC_NH,
	SYSZ_CC_NO,
} sysz_cc;

//> Operand type for instruction's operands
typedef enum sysz_op_type {
	SYSZ_OP_INVALID = 0, // = CS_OP_INVALID (Uninitialized).
	SYSZ_OP_REG, // = CS_OP_REG (Register operand).
	SYSZ_OP_IMM, // = CS_OP_IMM (Immediate operand).
	SYSZ_OP_MEM, // = CS_OP_MEM (Memory operand).
	SYSZ_OP_ACREG = 64,	// Access register operand.
} sysz_op_type;

// Instruction's operand referring to memory
// This is associated with SYSZ_OP_MEM operand type above
typedef struct sysz_op_mem {
	uint8_t base;	// base register
	uint8_t index;	// index register
	uint64_t length;	// BDLAddr operand
	int64_t disp;	// displacement/offset value
} sysz_op_mem;

// Instruction operand
typedef struct cs_sysz_op {
	sysz_op_type type;	// operand type
	union {
		unsigned int reg;	// register value for REG operand
		int64_t imm;		// immediate value for IMM operand
		sysz_op_mem mem;		// base/disp value for MEM operand
	};
} cs_sysz_op;

// Instruction structure
typedef struct cs_sysz {
	sysz_cc cc;		// Code condition
	// Number of operands of this instruction,
	// or 0 when instruction has no operand.
	uint8_t op_count;
	cs_sysz_op operands[6]; // operands for this instruction.
} cs_sysz;

//> SystemZ registers
typedef enum sysz_reg {
	SYSZ_REG_INVALID = 0,

	SYSZ_REG_0,
	SYSZ_REG_1,
	SYSZ_REG_2,
	SYSZ_REG_3,
	SYSZ_REG_4,
	SYSZ_REG_5,
	SYSZ_REG_6,
	SYSZ_REG_7,
	SYSZ_REG_8,
	SYSZ_REG_9,
	SYSZ_REG_10,
	SYSZ_REG_11,
	SYSZ_REG_12,
	SYSZ_REG_13,
	SYSZ_REG_14,
	SYSZ_REG_15,
	SYSZ_REG_CC,
	SYSZ_REG_F0,
	SYSZ_REG_F1,
	SYSZ_REG_F2,
	SYSZ_REG_F3,
	SYSZ_REG_F4,
	SYSZ_REG_F5,
	SYSZ_REG_F6,
	SYSZ_REG_F7,
	SYSZ_REG_F8,
	SYSZ_REG_F9,
	SYSZ_REG_F10,
	SYSZ_REG_F11,
	SYSZ_REG_F12,
	SYSZ_REG_F13,
	SYSZ_REG_F14,
	SYSZ_REG_F15,

	SYSZ_REG_R0L,

	SYSZ_REG_ENDING,
} sysz_reg;

//> SystemZ instruction
typedef enum sysz_insn {
	SYSZ_INS_INVALID = 0,

	SYSZ_INS_A,
	SYSZ_INS_ADB,
	SYSZ_INS_ADBR,
	SYSZ_INS_AEB,
	SYSZ_INS_AEBR,
	SYSZ_INS_AFI,
	SYSZ_INS_AG,
	SYSZ_INS_AGF,
	SYSZ_INS_AGFI,
	SYSZ_INS_AGFR,
	SYSZ_INS_AGHI,
	SYSZ_INS_AGHIK,
	SYSZ_INS_AGR,
	SYSZ_INS_AGRK,
	SYSZ_INS_AGSI,
	SYSZ_INS_AH,
	SYSZ_INS_AHI,
	SYSZ_INS_AHIK,
	SYSZ_INS_AHY,
	SYSZ_INS_AIH,
	SYSZ_INS_AL,
	SYSZ_INS_ALC,
	SYSZ_INS_ALCG,
	SYSZ_INS_ALCGR,
	SYSZ_INS_ALCR,
	SYSZ_INS_ALFI,
	SYSZ_INS_ALG,
	SYSZ_INS_ALGF,
	SYSZ_INS_ALGFI,
	SYSZ_INS_ALGFR,
	SYSZ_INS_ALGHSIK,
	SYSZ_INS_ALGR,
	SYSZ_INS_ALGRK,
	SYSZ_INS_ALHSIK,
	SYSZ_INS_ALR,
	SYSZ_INS_ALRK,
	SYSZ_INS_ALY,
	SYSZ_INS_AR,
	SYSZ_INS_ARK,
	SYSZ_INS_ASI,
	SYSZ_INS_AXBR,
	SYSZ_INS_AY,
	SYSZ_INS_BCR,
	SYSZ_INS_BRC,
	SYSZ_INS_BRCL,
	SYSZ_INS_CGIJ,
	SYSZ_INS_CGRJ,
	SYSZ_INS_CIJ,
	SYSZ_INS_CLGIJ,
	SYSZ_INS_CLGRJ,
	SYSZ_INS_CLIJ,
	SYSZ_INS_CLRJ,
	SYSZ_INS_CRJ,
	SYSZ_INS_BER,
	SYSZ_INS_JE,
	SYSZ_INS_JGE,
	SYSZ_INS_LOCE,
	SYSZ_INS_LOCGE,
	SYSZ_INS_LOCGRE,
	SYSZ_INS_LOCRE,
	SYSZ_INS_STOCE,
	SYSZ_INS_STOCGE,
	SYSZ_INS_BHR,
	SYSZ_INS_BHER,
	SYSZ_INS_JHE,
	SYSZ_INS_JGHE,
	SYSZ_INS_LOCHE,
	SYSZ_INS_LOCGHE,
	SYSZ_INS_LOCGRHE,
	SYSZ_INS_LOCRHE,
	SYSZ_INS_STOCHE,
	SYSZ_INS_STOCGHE,
	SYSZ_INS_JH,
	SYSZ_INS_JGH,
	SYSZ_INS_LOCH,
	SYSZ_INS_LOCGH,
	SYSZ_INS_LOCGRH,
	SYSZ_INS_LOCRH,
	SYSZ_INS_STOCH,
	SYSZ_INS_STOCGH,
	SYSZ_INS_CGIJNLH,
	SYSZ_INS_CGRJNLH,
	SYSZ_INS_CIJNLH,
	SYSZ_INS_CLGIJNLH,
	SYSZ_INS_CLGRJNLH,
	SYSZ_INS_CLIJNLH,
	SYSZ_INS_CLRJNLH,
	SYSZ_INS_CRJNLH,
	SYSZ_INS_CGIJE,
	SYSZ_INS_CGRJE,
	SYSZ_INS_CIJE,
	SYSZ_INS_CLGIJE,
	SYSZ_INS_CLGRJE,
	SYSZ_INS_CLIJE,
	SYSZ_INS_CLRJE,
	SYSZ_INS_CRJE,
	SYSZ_INS_CGIJNLE,
	SYSZ_INS_CGRJNLE,
	SYSZ_INS_CIJNLE,
	SYSZ_INS_CLGIJNLE,
	SYSZ_INS_CLGRJNLE,
	SYSZ_INS_CLIJNLE,
	SYSZ_INS_CLRJNLE,
	SYSZ_INS_CRJNLE,
	SYSZ_INS_CGIJH,
	SYSZ_INS_CGRJH,
	SYSZ_INS_CIJH,
	SYSZ_INS_CLGIJH,
	SYSZ_INS_CLGRJH,
	SYSZ_INS_CLIJH,
	SYSZ_INS_CLRJH,
	SYSZ_INS_CRJH,
	SYSZ_INS_CGIJNL,
	SYSZ_INS_CGRJNL,
	SYSZ_INS_CIJNL,
	SYSZ_INS_CLGIJNL,
	SYSZ_INS_CLGRJNL,
	SYSZ_INS_CLIJNL,
	SYSZ_INS_CLRJNL,
	SYSZ_INS_CRJNL,
	SYSZ_INS_CGIJHE,
	SYSZ_INS_CGRJHE,
	SYSZ_INS_CIJHE,
	SYSZ_INS_CLGIJHE,
	SYSZ_INS_CLGRJHE,
	SYSZ_INS_CLIJHE,
	SYSZ_INS_CLRJHE,
	SYSZ_INS_CRJHE,
	SYSZ_INS_CGIJNHE,
	SYSZ_INS_CGRJNHE,
	SYSZ_INS_CIJNHE,
	SYSZ_INS_CLGIJNHE,
	SYSZ_INS_CLGRJNHE,
	SYSZ_INS_CLIJNHE,
	SYSZ_INS_CLRJNHE,
	SYSZ_INS_CRJNHE,
	SYSZ_INS_CGIJL,
	SYSZ_INS_CGRJL,
	SYSZ_INS_CIJL,
	SYSZ_INS_CLGIJL,
	SYSZ_INS_CLGRJL,
	SYSZ_INS_CLIJL,
	SYSZ_INS_CLRJL,
	SYSZ_INS_CRJL,
	SYSZ_INS_CGIJNH,
	SYSZ_INS_CGRJNH,
	SYSZ_INS_CIJNH,
	SYSZ_INS_CLGIJNH,
	SYSZ_INS_CLGRJNH,
	SYSZ_INS_CLIJNH,
	SYSZ_INS_CLRJNH,
	SYSZ_INS_CRJNH,
	SYSZ_INS_CGIJLE,
	SYSZ_INS_CGRJLE,
	SYSZ_INS_CIJLE,
	SYSZ_INS_CLGIJLE,
	SYSZ_INS_CLGRJLE,
	SYSZ_INS_CLIJLE,
	SYSZ_INS_CLRJLE,
	SYSZ_INS_CRJLE,
	SYSZ_INS_CGIJNE,
	SYSZ_INS_CGRJNE,
	SYSZ_INS_CIJNE,
	SYSZ_INS_CLGIJNE,
	SYSZ_INS_CLGRJNE,
	SYSZ_INS_CLIJNE,
	SYSZ_INS_CLRJNE,
	SYSZ_INS_CRJNE,
	SYSZ_INS_CGIJLH,
	SYSZ_INS_CGRJLH,
	SYSZ_INS_CIJLH,
	SYSZ_INS_CLGIJLH,
	SYSZ_INS_CLGRJLH,
	SYSZ_INS_CLIJLH,
	SYSZ_INS_CLRJLH,
	SYSZ_INS_CRJLH,
	SYSZ_INS_BLR,
	SYSZ_INS_BLER,
	SYSZ_INS_JLE,
	SYSZ_INS_JGLE,
	SYSZ_INS_LOCLE,
	SYSZ_INS_LOCGLE,
	SYSZ_INS_LOCGRLE,
	SYSZ_INS_LOCRLE,
	SYSZ_INS_STOCLE,
	SYSZ_INS_STOCGLE,
	SYSZ_INS_BLHR,
	SYSZ_INS_JLH,
	SYSZ_INS_JGLH,
	SYSZ_INS_LOCLH,
	SYSZ_INS_LOCGLH,
	SYSZ_INS_LOCGRLH,
	SYSZ_INS_LOCRLH,
	SYSZ_INS_STOCLH,
	SYSZ_INS_STOCGLH,
	SYSZ_INS_JL,
	SYSZ_INS_JGL,
	SYSZ_INS_LOCL,
	SYSZ_INS_LOCGL,
	SYSZ_INS_LOCGRL,
	SYSZ_INS_LOCRL,
	SYSZ_INS_LOC,
	SYSZ_INS_LOCG,
	SYSZ_INS_LOCGR,
	SYSZ_INS_LOCR,
	SYSZ_INS_STOCL,
	SYSZ_INS_STOCGL,
	SYSZ_INS_BNER,
	SYSZ_INS_JNE,
	SYSZ_INS_JGNE,
	SYSZ_INS_LOCNE,
	SYSZ_INS_LOCGNE,
	SYSZ_INS_LOCGRNE,
	SYSZ_INS_LOCRNE,
	SYSZ_INS_STOCNE,
	SYSZ_INS_STOCGNE,
	SYSZ_INS_BNHR,
	SYSZ_INS_BNHER,
	SYSZ_INS_JNHE,
	SYSZ_INS_JGNHE,
	SYSZ_INS_LOCNHE,
	SYSZ_INS_LOCGNHE,
	SYSZ_INS_LOCGRNHE,
	SYSZ_INS_LOCRNHE,
	SYSZ_INS_STOCNHE,
	SYSZ_INS_STOCGNHE,
	SYSZ_INS_JNH,
	SYSZ_INS_JGNH,
	SYSZ_INS_LOCNH,
	SYSZ_INS_LOCGNH,
	SYSZ_INS_LOCGRNH,
	SYSZ_INS_LOCRNH,
	SYSZ_INS_STOCNH,
	SYSZ_INS_STOCGNH,
	SYSZ_INS_BNLR,
	SYSZ_INS_BNLER,
	SYSZ_INS_JNLE,
	SYSZ_INS_JGNLE,
	SYSZ_INS_LOCNLE,
	SYSZ_INS_LOCGNLE,
	SYSZ_INS_LOCGRNLE,
	SYSZ_INS_LOCRNLE,
	SYSZ_INS_STOCNLE,
	SYSZ_INS_STOCGNLE,
	SYSZ_INS_BNLHR,
	SYSZ_INS_JNLH,
	SYSZ_INS_JGNLH,
	SYSZ_INS_LOCNLH,
	SYSZ_INS_LOCGNLH,
	SYSZ_INS_LOCGRNLH,
	SYSZ_INS_LOCRNLH,
	SYSZ_INS_STOCNLH,
	SYSZ_INS_STOCGNLH,
	SYSZ_INS_JNL,
	SYSZ_INS_JGNL,
	SYSZ_INS_LOCNL,
	SYSZ_INS_LOCGNL,
	SYSZ_INS_LOCGRNL,
	SYSZ_INS_LOCRNL,
	SYSZ_INS_STOCNL,
	SYSZ_INS_STOCGNL,
	SYSZ_INS_BNOR,
	SYSZ_INS_JNO,
	SYSZ_INS_JGNO,
	SYSZ_INS_LOCNO,
	SYSZ_INS_LOCGNO,
	SYSZ_INS_LOCGRNO,
	SYSZ_INS_LOCRNO,
	SYSZ_INS_STOCNO,
	SYSZ_INS_STOCGNO,
	SYSZ_INS_BOR,
	SYSZ_INS_JO,
	SYSZ_INS_JGO,
	SYSZ_INS_LOCO,
	SYSZ_INS_LOCGO,
	SYSZ_INS_LOCGRO,
	SYSZ_INS_LOCRO,
	SYSZ_INS_STOCO,
	SYSZ_INS_STOCGO,
	SYSZ_INS_STOC,
	SYSZ_INS_STOCG,
	SYSZ_INS_BASR,
	SYSZ_INS_BR,
	SYSZ_INS_BRAS,
	SYSZ_INS_BRASL,
	SYSZ_INS_J,
	SYSZ_INS_JG,
	SYSZ_INS_BRCT,
	SYSZ_INS_BRCTG,
	SYSZ_INS_C,
	SYSZ_INS_CDB,
	SYSZ_INS_CDBR,
	SYSZ_INS_CDFBR,
	SYSZ_INS_CDGBR,
	SYSZ_INS_CDLFBR,
	SYSZ_INS_CDLGBR,
	SYSZ_INS_CEB,
	SYSZ_INS_CEBR,
	SYSZ_INS_CEFBR,
	SYSZ_INS_CEGBR,
	SYSZ_INS_CELFBR,
	SYSZ_INS_CELGBR,
	SYSZ_INS_CFDBR,
	SYSZ_INS_CFEBR,
	SYSZ_INS_CFI,
	SYSZ_INS_CFXBR,
	SYSZ_INS_CG,
	SYSZ_INS_CGDBR,
	SYSZ_INS_CGEBR,
	SYSZ_INS_CGF,
	SYSZ_INS_CGFI,
	SYSZ_INS_CGFR,
	SYSZ_INS_CGFRL,
	SYSZ_INS_CGH,
	SYSZ_INS_CGHI,
	SYSZ_INS_CGHRL,
	SYSZ_INS_CGHSI,
	SYSZ_INS_CGR,
	SYSZ_INS_CGRL,
	SYSZ_INS_CGXBR,
	SYSZ_INS_CH,
	SYSZ_INS_CHF,
	SYSZ_INS_CHHSI,
	SYSZ_INS_CHI,
	SYSZ_INS_CHRL,
	SYSZ_INS_CHSI,
	SYSZ_INS_CHY,
	SYSZ_INS_CIH,
	SYSZ_INS_CL,
	SYSZ_INS_CLC,
	SYSZ_INS_CLFDBR,
	SYSZ_INS_CLFEBR,
	SYSZ_INS_CLFHSI,
	SYSZ_INS_CLFI,
	SYSZ_INS_CLFXBR,
	SYSZ_INS_CLG,
	SYSZ_INS_CLGDBR,
	SYSZ_INS_CLGEBR,
	SYSZ_INS_CLGF,
	SYSZ_INS_CLGFI,
	SYSZ_INS_CLGFR,
	SYSZ_INS_CLGFRL,
	SYSZ_INS_CLGHRL,
	SYSZ_INS_CLGHSI,
	SYSZ_INS_CLGR,
	SYSZ_INS_CLGRL,
	SYSZ_INS_CLGXBR,
	SYSZ_INS_CLHF,
	SYSZ_INS_CLHHSI,
	SYSZ_INS_CLHRL,
	SYSZ_INS_CLI,
	SYSZ_INS_CLIH,
	SYSZ_INS_CLIY,
	SYSZ_INS_CLR,
	SYSZ_INS_CLRL,
	SYSZ_INS_CLST,
	SYSZ_INS_CLY,
	SYSZ_INS_CPSDR,
	SYSZ_INS_CR,
	SYSZ_INS_CRL,
	SYSZ_INS_CS,
	SYSZ_INS_CSG,
	SYSZ_INS_CSY,
	SYSZ_INS_CXBR,
	SYSZ_INS_CXFBR,
	SYSZ_INS_CXGBR,
	SYSZ_INS_CXLFBR,
	SYSZ_INS_CXLGBR,
	SYSZ_INS_CY,
	SYSZ_INS_DDB,
	SYSZ_INS_DDBR,
	SYSZ_INS_DEB,
	SYSZ_INS_DEBR,
	SYSZ_INS_DL,
	SYSZ_INS_DLG,
	SYSZ_INS_DLGR,
	SYSZ_INS_DLR,
	SYSZ_INS_DSG,
	SYSZ_INS_DSGF,
	SYSZ_INS_DSGFR,
	SYSZ_INS_DSGR,
	SYSZ_INS_DXBR,
	SYSZ_INS_EAR,
	SYSZ_INS_FIDBR,
	SYSZ_INS_FIDBRA,
	SYSZ_INS_FIEBR,
	SYSZ_INS_FIEBRA,
	SYSZ_INS_FIXBR,
	SYSZ_INS_FIXBRA,
	SYSZ_INS_FLOGR,
	SYSZ_INS_IC,
	SYSZ_INS_ICY,
	SYSZ_INS_IIHF,
	SYSZ_INS_IIHH,
	SYSZ_INS_IIHL,
	SYSZ_INS_IILF,
	SYSZ_INS_IILH,
	SYSZ_INS_IILL,
	SYSZ_INS_IPM,
	SYSZ_INS_L,
	SYSZ_INS_LA,
	SYSZ_INS_LAA,
	SYSZ_INS_LAAG,
	SYSZ_INS_LAAL,
	SYSZ_INS_LAALG,
	SYSZ_INS_LAN,
	SYSZ_INS_LANG,
	SYSZ_INS_LAO,
	SYSZ_INS_LAOG,
	SYSZ_INS_LARL,
	SYSZ_INS_LAX,
	SYSZ_INS_LAXG,
	SYSZ_INS_LAY,
	SYSZ_INS_LB,
	SYSZ_INS_LBH,
	SYSZ_INS_LBR,
	SYSZ_INS_LCDBR,
	SYSZ_INS_LCEBR,
	SYSZ_INS_LCGFR,
	SYSZ_INS_LCGR,
	SYSZ_INS_LCR,
	SYSZ_INS_LCXBR,
	SYSZ_INS_LD,
	SYSZ_INS_LDEB,
	SYSZ_INS_LDEBR,
	SYSZ_INS_LDGR,
	SYSZ_INS_LDR,
	SYSZ_INS_LDXBR,
	SYSZ_INS_LDXBRA,
	SYSZ_INS_LDY,
	SYSZ_INS_LE,
	SYSZ_INS_LEDBR,
	SYSZ_INS_LEDBRA,
	SYSZ_INS_LER,
	SYSZ_INS_LEXBR,
	SYSZ_INS_LEXBRA,
	SYSZ_INS_LEY,
	SYSZ_INS_LFH,
	SYSZ_INS_LG,
	SYSZ_INS_LGB,
	SYSZ_INS_LGBR,
	SYSZ_INS_LGDR,
	SYSZ_INS_LGF,
	SYSZ_INS_LGFI,
	SYSZ_INS_LGFR,
	SYSZ_INS_LGFRL,
	SYSZ_INS_LGH,
	SYSZ_INS_LGHI,
	SYSZ_INS_LGHR,
	SYSZ_INS_LGHRL,
	SYSZ_INS_LGR,
	SYSZ_INS_LGRL,
	SYSZ_INS_LH,
	SYSZ_INS_LHH,
	SYSZ_INS_LHI,
	SYSZ_INS_LHR,
	SYSZ_INS_LHRL,
	SYSZ_INS_LHY,
	SYSZ_INS_LLC,
	SYSZ_INS_LLCH,
	SYSZ_INS_LLCR,
	SYSZ_INS_LLGC,
	SYSZ_INS_LLGCR,
	SYSZ_INS_LLGF,
	SYSZ_INS_LLGFR,
	SYSZ_INS_LLGFRL,
	SYSZ_INS_LLGH,
	SYSZ_INS_LLGHR,
	SYSZ_INS_LLGHRL,
	SYSZ_INS_LLH,
	SYSZ_INS_LLHH,
	SYSZ_INS_LLHR,
	SYSZ_INS_LLHRL,
	SYSZ_INS_LLIHF,
	SYSZ_INS_LLIHH,
	SYSZ_INS_LLIHL,
	SYSZ_INS_LLILF,
	SYSZ_INS_LLILH,
	SYSZ_INS_LLILL,
	SYSZ_INS_LMG,
	SYSZ_INS_LNDBR,
	SYSZ_INS_LNEBR,
	SYSZ_INS_LNGFR,
	SYSZ_INS_LNGR,
	SYSZ_INS_LNR,
	SYSZ_INS_LNXBR,
	SYSZ_INS_LPDBR,
	SYSZ_INS_LPEBR,
	SYSZ_INS_LPGFR,
	SYSZ_INS_LPGR,
	SYSZ_INS_LPR,
	SYSZ_INS_LPXBR,
	SYSZ_INS_LR,
	SYSZ_INS_LRL,
	SYSZ_INS_LRV,
	SYSZ_INS_LRVG,
	SYSZ_INS_LRVGR,
	SYSZ_INS_LRVR,
	SYSZ_INS_LT,
	SYSZ_INS_LTDBR,
	SYSZ_INS_LTEBR,
	SYSZ_INS_LTG,
	SYSZ_INS_LTGF,
	SYSZ_INS_LTGFR,
	SYSZ_INS_LTGR,
	SYSZ_INS_LTR,
	SYSZ_INS_LTXBR,
	SYSZ_INS_LXDB,
	SYSZ_INS_LXDBR,
	SYSZ_INS_LXEB,
	SYSZ_INS_LXEBR,
	SYSZ_INS_LXR,
	SYSZ_INS_LY,
	SYSZ_INS_LZDR,
	SYSZ_INS_LZER,
	SYSZ_INS_LZXR,
	SYSZ_INS_MADB,
	SYSZ_INS_MADBR,
	SYSZ_INS_MAEB,
	SYSZ_INS_MAEBR,
	SYSZ_INS_MDB,
	SYSZ_INS_MDBR,
	SYSZ_INS_MDEB,
	SYSZ_INS_MDEBR,
	SYSZ_INS_MEEB,
	SYSZ_INS_MEEBR,
	SYSZ_INS_MGHI,
	SYSZ_INS_MH,
	SYSZ_INS_MHI,
	SYSZ_INS_MHY,
	SYSZ_INS_MLG,
	SYSZ_INS_MLGR,
	SYSZ_INS_MS,
	SYSZ_INS_MSDB,
	SYSZ_INS_MSDBR,
	SYSZ_INS_MSEB,
	SYSZ_INS_MSEBR,
	SYSZ_INS_MSFI,
	SYSZ_INS_MSG,
	SYSZ_INS_MSGF,
	SYSZ_INS_MSGFI,
	SYSZ_INS_MSGFR,
	SYSZ_INS_MSGR,
	SYSZ_INS_MSR,
	SYSZ_INS_MSY,
	SYSZ_INS_MVC,
	SYSZ_INS_MVGHI,
	SYSZ_INS_MVHHI,
	SYSZ_INS_MVHI,
	SYSZ_INS_MVI,
	SYSZ_INS_MVIY,
	SYSZ_INS_MVST,
	SYSZ_INS_MXBR,
	SYSZ_INS_MXDB,
	SYSZ_INS_MXDBR,
	SYSZ_INS_N,
	SYSZ_INS_NC,
	SYSZ_INS_NG,
	SYSZ_INS_NGR,
	SYSZ_INS_NGRK,
	SYSZ_INS_NI,
	SYSZ_INS_NIHF,
	SYSZ_INS_NIHH,
	SYSZ_INS_NIHL,
	SYSZ_INS_NILF,
	SYSZ_INS_NILH,
	SYSZ_INS_NILL,
	SYSZ_INS_NIY,
	SYSZ_INS_NR,
	SYSZ_INS_NRK,
	SYSZ_INS_NY,
	SYSZ_INS_O,
	SYSZ_INS_OC,
	SYSZ_INS_OG,
	SYSZ_INS_OGR,
	SYSZ_INS_OGRK,
	SYSZ_INS_OI,
	SYSZ_INS_OIHF,
	SYSZ_INS_OIHH,
	SYSZ_INS_OIHL,
	SYSZ_INS_OILF,
	SYSZ_INS_OILH,
	SYSZ_INS_OILL,
	SYSZ_INS_OIY,
	SYSZ_INS_OR,
	SYSZ_INS_ORK,
	SYSZ_INS_OY,
	SYSZ_INS_PFD,
	SYSZ_INS_PFDRL,
	SYSZ_INS_RISBG,
	SYSZ_INS_RISBHG,
	SYSZ_INS_RISBLG,
	SYSZ_INS_RLL,
	SYSZ_INS_RLLG,
	SYSZ_INS_RNSBG,
	SYSZ_INS_ROSBG,
	SYSZ_INS_RXSBG,
	SYSZ_INS_S,
	SYSZ_INS_SDB,
	SYSZ_INS_SDBR,
	SYSZ_INS_SEB,
	SYSZ_INS_SEBR,
	SYSZ_INS_SG,
	SYSZ_INS_SGF,
	SYSZ_INS_SGFR,
	SYSZ_INS_SGR,
	SYSZ_INS_SGRK,
	SYSZ_INS_SH,
	SYSZ_INS_SHY,
	SYSZ_INS_SL,
	SYSZ_INS_SLB,
	SYSZ_INS_SLBG,
	SYSZ_INS_SLBR,
	SYSZ_INS_SLFI,
	SYSZ_INS_SLG,
	SYSZ_INS_SLBGR,
	SYSZ_INS_SLGF,
	SYSZ_INS_SLGFI,
	SYSZ_INS_SLGFR,
	SYSZ_INS_SLGR,
	SYSZ_INS_SLGRK,
	SYSZ_INS_SLL,
	SYSZ_INS_SLLG,
	SYSZ_INS_SLLK,
	SYSZ_INS_SLR,
	SYSZ_INS_SLRK,
	SYSZ_INS_SLY,
	SYSZ_INS_SQDB,
	SYSZ_INS_SQDBR,
	SYSZ_INS_SQEB,
	SYSZ_INS_SQEBR,
	SYSZ_INS_SQXBR,
	SYSZ_INS_SR,
	SYSZ_INS_SRA,
	SYSZ_INS_SRAG,
	SYSZ_INS_SRAK,
	SYSZ_INS_SRK,
	SYSZ_INS_SRL,
	SYSZ_INS_SRLG,
	SYSZ_INS_SRLK,
	SYSZ_INS_SRST,
	SYSZ_INS_ST,
	SYSZ_INS_STC,
	SYSZ_INS_STCH,
	SYSZ_INS_STCY,
	SYSZ_INS_STD,
	SYSZ_INS_STDY,
	SYSZ_INS_STE,
	SYSZ_INS_STEY,
	SYSZ_INS_STFH,
	SYSZ_INS_STG,
	SYSZ_INS_STGRL,
	SYSZ_INS_STH,
	SYSZ_INS_STHH,
	SYSZ_INS_STHRL,
	SYSZ_INS_STHY,
	SYSZ_INS_STMG,
	SYSZ_INS_STRL,
	SYSZ_INS_STRV,
	SYSZ_INS_STRVG,
	SYSZ_INS_STY,
	SYSZ_INS_SXBR,
	SYSZ_INS_SY,
	SYSZ_INS_TM,
	SYSZ_INS_TMHH,
	SYSZ_INS_TMHL,
	SYSZ_INS_TMLH,
	SYSZ_INS_TMLL,
	SYSZ_INS_TMY,
	SYSZ_INS_X,
	SYSZ_INS_XC,
	SYSZ_INS_XG,
	SYSZ_INS_XGR,
	SYSZ_INS_XGRK,
	SYSZ_INS_XI,
	SYSZ_INS_XIHF,
	SYSZ_INS_XILF,
	SYSZ_INS_XIY,
	SYSZ_INS_XR,
	SYSZ_INS_XRK,
	SYSZ_INS_XY,

	SYSZ_INS_ENDING,   // <-- mark the end of the list of instructions
} sysz_insn;

//> Group of SystemZ instructions
typedef enum sysz_insn_group {
	SYSZ_GRP_INVALID = 0, // = CS_GRP_INVALID

	//> Generic groups
	// all jump instructions (conditional+direct+indirect jumps)
	SYSZ_GRP_JUMP,	// = CS_GRP_JUMP

	//> Architecture-specific groups
	SYSZ_GRP_DISTINCTOPS = 128,
	SYSZ_GRP_FPEXTENSION,
	SYSZ_GRP_HIGHWORD,
	SYSZ_GRP_INTERLOCKEDACCESS1,
	SYSZ_GRP_LOADSTOREONCOND,

	SYSZ_GRP_ENDING,   // <-- mark the end of the list of groups
} sysz_insn_group;

#ifdef __cplusplus
}
#endif

#endif
