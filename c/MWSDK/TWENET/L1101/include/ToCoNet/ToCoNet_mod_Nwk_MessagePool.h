/****************************************************************************
 * (C) Tokyo Cosmos Electric, Inc. (TOCOS) - 2013 all rights reserved.
 *
 * Condition to use:
 *   - The full or part of source code is limited to use for TWE (TOCOS
 *     Wireless Engine) as compiled and flash programmed.
 *   - The full or part of source code is prohibited to distribute without
 *     permission from TOCOS.
 *
 ****************************************************************************/

/*! @file  ToCoNet_mod_MessagePool ToCoNet.h
    @author seigo13
    @defgroup grp_ToCoNet_mod_MessagePool ToCoNet モジュール - メッセージプール
      EndDevice 向けにメッセージを Parent, Router に格納保持する
 */

#ifndef TOCONET_MOD_MESSAGE_POOL_H_
#define TOCONET_MOD_MESSAGE_POOL_H_

#include <jendefs.h>


/** @ingroup grp_ToCoNet_mod_MessagePool
 * メッセージプールの最大スロット数
 */
#define TOCONET_MOD_MESSAGE_POOL_MAX_ENTITY 8
/** @ingroup grp_ToCoNet_mod_MessagePool
 * メッセージプールのメッセージ長の最大
 */
#define TOCONET_MOD_MESSAGE_POOL_MAX_MESSAGE 64

/** @ingroup grp_ToCoNet_mod_MessagePool
 * メッセージプール設定構造体
 */
typedef struct {
} tsToCoNet_MsgPl_Config;

/** @ingroup grp_ToCoNet_mod_MessagePool
 * メッセージプールのデータ要求があったときの要求元とデータスロット。
 * - E_EVENT_TOCONET_NWK_MESSAGE_POOL_REQUEST 応答時のパラメータ。
 */
typedef struct {
	uint32 u32Addr; //!< 要求元のアドレス
	uint8 u8Slot; //!< 要求スロット
} tsToCoNet_MsgPl_Request;

/** @ingroup grp_ToCoNet_mod_MessagePool
 * メッセージプール管理構造体
 */
typedef struct {
	uint8 au8Message[TOCONET_MOD_MESSAGE_POOL_MAX_MESSAGE]; //!< メッセージ内容
	uint32 u32TickGot; //!< メッセージ受信時刻
	uint16 u16Life_s; //!< メッセージに寿命(未使用)
	uint8 u8MessageLen; //!< メッセージ長(0はデータ無し、1〜TOCONET_MOD_MESSAGE_POOL_MAX_MESSAGE)
	uint8 u8Slot; //!< メッセージのスロット(0〜TOCONET_MOD_MESSAGE_POOL_MAX_ENTITY-1)
	uint8 u8LqiRecv; //!< メッセージ取得時の LQI (EndDevice のみ)
	bool_t bGotData; //!< 構造体に値が入っていれば TRUE
} tsToCoNet_MsgPl_Entity;

/** @ingroup grp_ToCoNet_mod_MessagePool
 * メッセージプール管理構造体
 */
typedef struct {
	tsToCoNet_MsgPl_Config sConf; //!< 設定構造体(未使用)
	tsToCoNet_MsgPl_Entity asEnt[TOCONET_MOD_MESSAGE_POOL_MAX_ENTITY]; //!< データエントリ
} tsToCoNet_MsgPl_Context;

#endif /* TOCONET_MOD_MESSAGE_POOL_H_ */
