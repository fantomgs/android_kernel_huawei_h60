/******************************************************************************

                  版权所有 (C), 2001-2011, 华为技术有限公司

 ******************************************************************************
  文 件 名   : om_msghook.h
  版 本 号   : 初稿
  作    者   : 苏庄銮 59026
  生成日期   : 2011年5月31日
  最近修改   :
  功能描述   : om_msghook.c 的头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2011年5月31日
    作    者   : 苏庄銮 59026
    修改内容   : 创建文件

******************************************************************************/

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"
#include "om_comm.h"


#ifndef __OM_MSGHOOK_H__
#define __OM_MSGHOOK_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  2 宏定义
*****************************************************************************/
#define OM_MSGHOOK_TENTH_SECOND_PER20MS                     (200)               /* 每20ms中0.1ms的个数 */

/* 获取层间消息钩取使能标志 */
#define OM_MSGHOOK_GetMsgHookEnable()                       \
                    (g_stOmMsghook.uhwVosMsgHookEnable)

/*****************************************************************************
  3 枚举定义
*****************************************************************************/


/*****************************************************************************
  4 消息头定义
*****************************************************************************/


/*****************************************************************************
  5 消息定义
*****************************************************************************/

/*****************************************************************************
  6 STRUCT定义
*****************************************************************************/
/*****************************************************************************
 实体名称  : OM_MSGHOOK_STRU
 功能描述  : 可维可测模块总体控制结构
 *****************************************************************************/
typedef struct
{
    OM_SWITCH_ENUM_UINT16               uhwVosMsgHookEnable;
    VOS_UINT16                          uhwReserved;
}OM_MSGHOOK_STRU;

/*****************************************************************************
  7 UNION定义
*****************************************************************************/


/*****************************************************************************
  8 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  9 全局变量声明
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/

extern VOS_UINT32 OM_MSGHOOK_DefaultCfg(CODEC_MSG_HOOK_CONFIG_STRU *pstMsgHookCfg);
extern VOS_VOID OM_MSGHOOK_Init(VOS_VOID);
extern VOS_VOID OM_MSGHOOK_SetMsgHookEnable(VOS_UINT16 uhwEnable);
extern VOS_UINT32 OM_MSGHOOK_MsgCfgMsgHookReq(VOS_VOID *pvOsaMsg);
extern VOS_VOID OM_MSGHOOK_VosMsgHook(VOS_VOID *pvOsaMsg);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of om_msghook.h */
