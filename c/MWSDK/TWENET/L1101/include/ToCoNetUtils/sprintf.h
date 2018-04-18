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


#ifndef SPRINTF_H_
#define SPRINTF_H_

#include <jendefs.h>
#include "fprintf.h"

PUBLIC void SPRINTF_vInit32();
PUBLIC void SPRINTF_vInit64();
PUBLIC void SPRINTF_vInit128();
PUBLIC void SPRINTF_vInit256();
PUBLIC void SPRINTF_vInit512();
PUBLIC void SPRINTF_vInit1024();

PUBLIC void SPRINTF_vRewind();
PUBLIC uint8* SPRINTF_pu8GetBuff();
PUBLIC uint16 SPRINTF_u16Length();

PUBLIC uint32 u32string2hex(uint8 *p, uint8 u8len);
PUBLIC uint32 u32string2dec(uint8 *p, uint8 u8len);

extern tsFILE *SPRINTF_Stream;

#endif /* SPRINTF_H_ */
