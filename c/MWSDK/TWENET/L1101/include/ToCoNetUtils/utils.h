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
/*
 * Utils.h
 *
 *  Created on: 2012/02/11
 *      Author: seigo13
 */

#ifndef UTILS_H_
#define UTILS_H_

/****************************************************************************
 * MACROs
 ***************************************************************************/ //
/* CPU_VOLT CONVERSION 16bit->8bit (to save payload)
 *	(i:  0~170)1950+i*5 -> 1.95~2.80V
 *	(i:171~255)2800+(i-170)*10 -> 2.81~3.65V
 */
#define ENCODE_VOLT(m) \
	(m < 1950 ? 0 : (m > 3650 ? 255 : (m <= 2802 ? ((m-1950+2)/5) : ((m-2800-5)/10+171)) ))
#define DECODE_VOLT(i) \
	(i <= 170 ? (1950+i*5) : (2800+(i-170)*10) )

/* convert ticks by 1.024ms to ms */
#define CONV_1024TICK_TO_MS(c) \
	((c) + \
	 (((c) / 1000L) * 24L) + \
	 (((c) % 1000L) * 24L / 1000L))

/* MACROS for put/get bytes data for packet's payload */
// get data from *p, then move 'p' to the next.
#define OCTET(c) { c = *p; p++; }
#define LE_DWORD(c) { c = (uint32)(*p) | ((uint32)(*(p+1))<< 8) | ((uint32)(*(p+2)) << 16) | ((uint32)(*(p+3)) << 24); p+=4; }
#define LE_WORD(c) { c = (uint16)(*p) | ((uint16)(*(p+1)) << 8); p+=2; }
#define BE_DWORD(c) { c = (uint32)*(p+3) | ((uint32)*(p+2) << 8) | ((uint32)*(p+1) << 16) | ((uint32)*(p) << 24); p+=4; }
#define BE_WORD(c) { c = (uint16)*(p+1) | ((uint16)*p << 8); p+=2; }

#define G_OCTET() (*p++)
#define G_BE_WORD() (p+=2, ((uint16)*(p-1) | ((uint16)*(p-2) << 8)))
#define G_BE_DWORD() (p+=4, ((uint32)*(p-1) | ((uint32)*(p-2) << 8) | ((uint32)*(p-3) << 16) | ((uint32)*(p-4) << 24)))

// set data into *q, then move 'q' to the next
//   the system runs under `little endian'.
#define S_OCTET(c) { *q = c; q++; }
#define S_LE_WORD(c) { \
	*q = ((c)&0xff); q++; \
	*q = ((c)>>8)&0xff; q++; \
	}
#define S_BE_WORD(c) { \
	*q = ((c)>>8)&0xff; q++; \
	*q = ((c)&0xff); q++; \
	}
#define S_LE_DWORD(c) { \
	*q = ((c)&0xff); q++; \
	*q = ((c)>>8)&0xff; q++; \
	*q = ((c)>>16)&0xff; q++; \
	*q = ((c)>>24)&0xff; q++; \
	}
#define S_BE_DWORD(c) { \
	*q = ((c)>>24)&0xff; q++; \
	*q = ((c)>>16)&0xff; q++; \
	*q = ((c)>>8)&0xff; q++; \
	*q = ((c)&0xff); q++; \
	}

// 64bit mac address
#define MAC_EXT_ADDR_TO_64BIT(ext) ((uint64)(ext.u32L) | (((uint64)(ext.u32H)) << 32))

// IO settings
#define vPortSetHi(c) vAHI_DioSetOutput(1UL << (c), 0)
#define vPortSetLo(c) vAHI_DioSetOutput(0, 1UL << (c))
#define vPortSet_TrueAsLo(c, s)  vAHI_DioSetOutput((s) ? 0 : 1UL << (c), s ? 1UL << (c) : 0)
#define vPortAsInput(c) vAHI_DioSetDirection(1UL << (c), 0)
#define vPortAsOutput(c) vAHI_DioSetDirection(0, 1UL << (c))
#define bPortRead(c) ((u32AHI_DioReadInput() & (1UL<<(c))) ? FALSE : TRUE) // Lo as True
#define u32PortReadBitmap() (u32AHI_DioReadInput())
#define bPortCheckBitmap(bitmap, c) ((bitmap & (1UL<<(c))) ? FALSE : TRUE)
#define vPortDisablePullup(c) vAHI_DioSetPullup(0x0, 1UL << (c))

#if defined(JN514x)
#define PORT_KIT_SW1 9
#define PORT_KIT_SW2 10
#define PORT_KIT_SW3 11
#define PORT_KIT_SW4 20
#define PORT_KIT_LED1 16
#define PORT_KIT_LED2 17
#define PORT_KIT_LED3 18
#define PORT_KIT_LED4 19
#elif defined(JN516x)
#define PORT_KIT_SW1 2
#define PORT_KIT_SW2 3
#define PORT_KIT_SW3 10
#define PORT_KIT_SW4 9
#define PORT_KIT_LED1 17
#define PORT_KIT_LED2 13
#define PORT_KIT_LED3 12
#define PORT_KIT_LED4 11
#endif
#define PORT_KIT_SW1_MASK (1UL << PORT_KIT_SW1)
#define PORT_KIT_SW2_MASK (1UL << PORT_KIT_SW2)
#define PORT_KIT_SW3_MASK (1UL << PORT_KIT_SW3)
#define PORT_KIT_SW4_MASK (1UL << PORT_KIT_SW4)
#define PORT_KIT_SW_ALL2_MASK (PORT_KIT_SW1_MASK | PORT_KIT_SW2_MASK)
#define PORT_KIT_SW_ALL4_MASK (PORT_KIT_SW1_MASK | PORT_KIT_SW2_MASK | PORT_KIT_SW3_MASK | PORT_KIT_SW4_MASK)

#define PORT_KIT_LED1_MASK (1UL << PORT_KIT_LED1)
#define PORT_KIT_LED2_MASK (1UL << PORT_KIT_LED2)
#define PORT_KIT_LED3_MASK (1UL << PORT_KIT_LED3)
#define PORT_KIT_LED4_MASK (1UL << PORT_KIT_LED4)
#define PORT_KIT_LED_ALL2_MASK (PORT_KIT_LED1_MASK | PORT_KIT_LED2_MASK)
#define PORT_KIT_LED_ALL4_MASK (PORT_KIT_LED1_MASK | PORT_KIT_LED2_MASK | PORT_KIT_LED3_MASK | PORT_KIT_LED4_MASK)

// for switch clause
#define _C if(1)

// UART related
#define WAIT_UART_OUTPUT(P) SERIAL_vFlush(P)
#define LB "\r\n"

// IO clock (on JN514x, IO runs at 16Mhz regardless of CPU clock.
#define u32IO_FREQ_HZ 16000000UL

// TIME COMPARE
#define u32TimeDiff(ref, now) (now - ref < 0x7FFFFFFF ? now - ref : )

// Timer context for vTimerXXX, vTickTimerXXX
typedef struct _tsTimerContext {
	uint8 u8PreScale; //!< pre scale value (for vTimerXXX)
	uint8 u8Device; //!< device (for vTimerXXX)
	uint8 u8AHI_TIMER_X; // E_AHI_TIMER0 ... 2
	bool_t bStarted; //!< flag if timer is running or not.

	uint16 u16Hz; //!< frequency
	uint16 u16ct_total; //!< 計算された１周期のカウント数

	uint16 u16duty; //!< PWM のDUTY比 0:0% 1024:100%
	bool_t bPWMout; //!< TRUE ならPWM出力
	bool_t bDisableInt; //!< TRUE なら割り込み無し

	uint32 u32reg; //!< TIMER のレジスタアドレス

	void (*pvHandler)(uint32, uint32); // event handler
} tsTimerContext;

/****************************************************************************
 * Prototype Declaration
 ***************************************************************************/ //
void vTimerConfig(tsTimerContext *psTC);
void vTimerStart(tsTimerContext *psTC);
void vTimerStop(tsTimerContext *psTC);
void vTimerDisable(tsTimerContext *psTC);
void vTimerChangeHz(tsTimerContext *psTC);
void vTimerChangeHzEx(tsTimerContext *psTC, uint32 u32mHz);
void vTimerChangeDuty(tsTimerContext *psTC);
void vTimerChangeDutySync(tsTimerContext *psTC, uint16 u16CtSyncThes, uint32 (*pCallBack)(uint32));

void vAnalogueConfig(void);
void vAnalogueDisable(void);

void vWait(uint32 c);

#endif /* UTILS_H_ */
