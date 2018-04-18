/****************************************************************************
 * (C) Tokyo Cosmos Electric, Inc. (TOCOS) - 2012 all rights reserved.
 *
 * Condition to use:
 *   - The full or part of source code is limited to use for TWE (TOCOS
 *     Wireless Engine) as compiled and flash programmed.
 *   - The full or part of source code is prohibited to distribute without
 *     permission from TOCOS.
 *
 ****************************************************************************/


#ifndef SERINPUTMGR_H_
#define SERINPUTMGR_H_

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/

#include "jendefs.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define SERCMD_SYNC_1 0xA5
#define SERCMD_SYNC_2 0x5A

#define SERCMD_TIMEOUT_ms 1000
// #define SERCMD_MAXPAYLOAD 128

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
/******************
 * Serial Command Handling
 */
typedef enum {
	E_SERCMD_EMPTY = 0,
	E_SERCMD_READSYNC,
	E_SERCMD_READLEN,
	E_SERCMD_READLEN2,
	E_SERCMD_READPAYLOAD,
	E_SERCMD_READCRC,
	E_SERCMD_PLUS1,
	E_SERCMD_PLUS2,
	E_SERCMD_COMPLETE = 0x80,
	E_SERCMD_ERROR,
	E_SERCMD_CRCERROR,
	E_SERCMD_VERBOSE
} teSerCmd;

typedef struct {
	uint32 u32timestamp;
	uint16 u16len; // command length
	uint16 u16pos;
	uint8 u8state;
	uint8 u8xor; // xor8 check

	uint16 u16maxlen;
	uint8 *au8data;
} tsSerCmd;


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
uint8 u8ParseSerCmd(tsSerCmd *pCmd, uint8 u8byte);
extern uint8 bSerCmd_VerboseMode;

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#endif /* SERINPUTMGR_H_ */

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/
