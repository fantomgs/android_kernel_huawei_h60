
#ifndef __MMLMMINTERFACE_H__
#define __MMLMMINTERFACE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*****************************************************************************
  #pragma pack(*)    设置字节对齐方式
*****************************************************************************/
#include "LPSCommon.h"


#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(4)
#else
#pragma pack(push, 4)
#endif

/*****************************************************************************
  2 Macro
*****************************************************************************/

#define MM_LMM_EMERGENCY_NUM_MAX_LEN            (46)
#define MM_LMM_EMERGENCY_NUM_LIST_MAX_RECORDS   (16)
#define MM_LMM_CK_LEN                           16
#define MM_LMM_IK_LEN                           16

/*****************************************************************************
  3 Massage Declare
*****************************************************************************/


/*****************************************************************************
  4 Enum
*****************************************************************************/
enum MM_LMM_MSG_ID_ENUM
{
    /* MM发给LMM的消息原语 */
    ID_MM_LMM_CSFB_SERVICE_START_NOTIFY = 0x01+PS_MSG_ID_MM_TO_LMM_BASE,        /* _H2ASN_MsgChoice MM_LMM_CSFB_SERVICE_START_NOTIFY_STRU */
    ID_MM_LMM_CSFB_SERVICE_ABORT_NOTIFY = 0x02+PS_MSG_ID_MM_TO_LMM_BASE,        /* _H2ASN_MsgChoice MM_LMM_CSFB_SERVICE_ABORT_NOTIFY_STRU */
    ID_MM_LMM_HO_SECU_INFO_REQ          = 0x03+PS_MSG_ID_MM_TO_LMM_BASE,        /* _H2ASN_MsgChoice MM_LMM_HO_SECU_INFO_REQ_STRU */
    ID_MM_LMM_SRVCC_STATUS_NOTIFY              = 0x04+PS_MSG_ID_MM_TO_LMM_BASE,        /* _H2ASN_MsgChoice MM_LMM_SRVCC_STATUS_NOTIFY_STRU*/

    /* LMM发送给MM的消息原语*/
    ID_LMM_MM_COMBINED_START_NOTIFY_REQ = 0x01+PS_MSG_ID_LMM_TO_MM_BASE,        /* _H2ASN_MsgChoice LMM_MM_COMBINED_START_NOTIFY_REQ_STRU */
    ID_LMM_MM_CSFB_SERVICE_END_IND      = 0x02+PS_MSG_ID_LMM_TO_MM_BASE,        /* _H2ASN_MsgChoice LMM_MM_CSFB_SERVICE_END_IND_STRU */
    ID_LMM_MM_CSFB_SERVICE_PAGING_IND   = 0x03+PS_MSG_ID_LMM_TO_MM_BASE,        /* _H2ASN_MsgChoice LMM_MM_CSFB_SERVICE_PAGING_IND_STRU */
    ID_LMM_MM_INFO_CHANGE_NOTIFY        = 0x04+PS_MSG_ID_LMM_TO_MM_BASE,        /* _H2ASN_MsgChoice LMM_MM_INFO_CHANGE_NOTIFY_STRU */
    ID_LMM_MM_HO_SECU_INFO_CNF          = 0x05+PS_MSG_ID_LMM_TO_MM_BASE,        /* _H2ASN_MsgChoice LMM_MM_HO_SECU_INFO_CNF_STRU */

    ID_MM_LMM_MSG_ID_ENUM_BUTT
};
typedef VOS_UINT32 MM_LMM_MSG_ID_ENUM_UINT32;

/*****************************************************************************
 枚举名    : MM_LMM_COMBINED_TYPE_ENUM
 协议表格  :
 ASN.1描述 :
 枚举说明  : 联合流程类型
*****************************************************************************/
enum MM_LMM_COMBINED_TYPE_ENUM
{
    MM_LMM_COMBINED_ATTACH              = 0,
    MM_LMM_COMBINED_TAU                 = 1,
    MM_LMM_COMBINED_DETACH              = 2,

    MM_LMM_COMBINED_TYPE_BUTT
};
typedef VOS_UINT32 MM_LMM_COMBINED_TYPE_ENUM_UINT32;

/*****************************************************************************
 枚举名    : MM_LMM_CSFB_SERVICE_TYPE_ENUM
 协议表格  :
 ASN.1描述 :
 枚举说明  : CSFB类型
*****************************************************************************/
enum    MM_LMM_CSFB_SERVICE_TYPE_ENUM
{
    MM_LMM_CSFB_SERVICE_MO_NORMAL       = 0,
    MM_LMM_CSFB_SERVICE_MO_EMERGENCY    = 1,
    MM_LMM_CSFB_SERVICE_MT_NORMAL       = 2,

    MM_LMM_CSFB_SERVICE_BUTT
};
typedef VOS_UINT32 MM_LMM_CSFB_SERVICE_TYPE_ENUM_UINT32;

/*****************************************************************************
 枚举名    : MM_LMM_CSFB_SERVICE_RSLT_ENUM
 协议表格  :
 ASN.1描述 :
 枚举说明  : SERVICE的结果类型
*****************************************************************************/
enum   MM_LMM_CSFB_SERVICE_RSLT_ENUM
{
    MM_LMM_CSFB_SERVICE_RSLT_FAILURE            = 0,    /*除网侧拒绝外的失败*/
    MM_LMM_CSFB_SERVICE_RSLT_CN_REJ     ,               /*网侧拒绝*/
    MM_LMM_CSFB_SERVICE_RSLT_AUTH_REJ,
    MM_LMM_CSFB_SERVICE_RSLT_T3417EXT_TIME_OUT,

    MM_LMM_CSFB_SERVICE_RSLT_BUTT
};
typedef VOS_UINT32 MM_LMM_CSFB_SERVICE_RSLT_ENUM_UINT32;

/*****************************************************************************
 枚举名    : LMM_MM_PAGING_IND_UE_ID_ENUM
 协议表格  :
 ASN.1描述 :
 枚举说明  : PAGING IND的enPagingUeId取值
*****************************************************************************/
enum   LMM_MM_PAGING_IND_UE_ID_ENUM
{
    LMM_MM_PAGING_IND_UE_ID_IMSI                    = 0,
    LMM_MM_PAGING_IND_UE_ID_S_TMSI                  = 1,
    LMM_MM_PAGING_IND_UE_ID_TMSI                    = 2,

    LMM_MM_PAGING_IND_UE_ID_BUTT
};
typedef VOS_UINT32 LMM_MM_PAGING_IND_UE_ID_ENUM_UINT32;

/*****************************************************************************
 枚举名    : LMM_MM_NW_IMS_VOICE_ENUM
 协议表格  :
 ASN.1描述 :
 枚举说明  : 网侧是否支持IMS VOICE枚举
*****************************************************************************/
enum LMM_MM_NW_IMS_VOICE_ENUM
{
    LMM_MM_NW_IMS_VOICE_NOT_SUPPORTED   = 0,
    LMM_MM_NW_IMS_VOICE_SUPPORTED        = 1,

    LMM_MM_NW_IMS_VOICE_BUTT
};
typedef VOS_UINT32 LMM_MM_NW_IMS_VOICE_ENUM_UINT32;

/*****************************************************************************
 枚举名    : LMM_MM_NW_EMC_BS_ENUM
 协议表格  :
 ASN.1描述 :
 枚举说明  : 网侧是否支持紧急呼枚举
*****************************************************************************/
enum LMM_MM_NW_EMC_BS_ENUM
{
    LMM_MM_NW_EMC_BS_NOT_SUPPORTED      = 0,
    LMM_MM_NW_EMC_BS_SUPPORTED           = 1,

    LMM_MM_NW_EMC_BS_BUTT
};
typedef VOS_UINT32 LMM_MM_NW_EMC_BS_ENUM_UINT32;

/*****************************************************************************
 枚举名    : MM_LMM_SECU_INFO_RSLT_ENUM
 协议表格  :
 ASN.1描述 :
 枚举说明  : 获取L下CS安全上下文的结果枚举
*****************************************************************************/
enum  MM_LMM_SECU_INFO_RSLT_ENUM
{
    MM_LMM_SECU_INFO_RSLT_SUCC         = 0,
    MM_LMM_SECU_INFO_RSLT_FAIL_EIA0,
    MM_LMM_SECU_INFO_RSLT_FAIL_OTHERS,
    MM_LMM_SECU_INFO_RSLT_BUTT
};
typedef VOS_UINT32 MM_LMM_SECU_INFO_RSLT_ENUM_UINT32;


/*****************************************************************************
 枚举名    : MM_LMM_SRVCC_STATUS_ENUM_UINT32
 协议表格  :
 ASN.1描述 :
 枚举说明  : 获取SRVCC的状态
*****************************************************************************/
enum  MM_LMM_SRVCC_STATUS_ENUM
{
    MM_LMM_SRVCC_STATUS_START         = 0,
    MM_LMM_SRVCC_STATUS_SUCC,
    MM_LMM_SRVCC_STATUS_FAIL,

    MM_LMM_SRVCC_STATUS_BUTT
};
typedef VOS_UINT32 MM_LMM_SRVCC_STATUS_ENUM_UINT32;



/*****************************************************************************
  5 STRUCT
*****************************************************************************/

/*****************************************************************************
结构名    :LMM_MM_COMBINED_START_NOTIFY_REQ_STRU
协议表格  :
ASN.1描述 :
结构说明  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    MM_LMM_MSG_ID_ENUM_UINT32           ulMsgId;            /*_H2ASN_Skip*/
    VOS_UINT32                          ulOpId;

    MM_LMM_COMBINED_TYPE_ENUM_UINT32    enCombinedType;     /* 联合流程类型 */
} LMM_MM_COMBINED_START_NOTIFY_REQ_STRU;



/*****************************************************************************
 结构名    : MM_LMM_CSFB_SERVICE_START_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : MM通知LMM启动CSFB流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    MM_LMM_MSG_ID_ENUM_UINT32           ulMsgId;            /*_H2ASN_Skip*/
    VOS_UINT32                          ulOpId;
    MM_LMM_CSFB_SERVICE_TYPE_ENUM_UINT32  enCsfbSrvType;
} MM_LMM_CSFB_SERVICE_START_NOTIFY_STRU;

/*****************************************************************************
 结构名    : MM_LMM_CSFB_SERVICE_ABORT_NOTIFY_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : MM通知LMM终止CSFB流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    MM_LMM_MSG_ID_ENUM_UINT32           ulMsgId;            /*_H2ASN_Skip*/
    VOS_UINT32                          ulOpId;
} MM_LMM_CSFB_SERVICE_ABORT_NOTIFY_STRU;

/*****************************************************************************
 结构名    : LMM_MM_CSFB_SERVICE_END_IND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LMM通知MM， CSFB流程异常终止
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    MM_LMM_MSG_ID_ENUM_UINT32           ulMsgId;            /*_H2ASN_Skip*/
    VOS_UINT32                          ulOpId;
    MM_LMM_CSFB_SERVICE_RSLT_ENUM_UINT32  enCsfbSrvRslt;
} LMM_MM_CSFB_SERVICE_END_IND_STRU;


/*****************************************************************************
 结构名    : LMM_MM_CSFB_SERVICE_PAGING_IND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LMM通知MM启动MT CSFB流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    MM_LMM_MSG_ID_ENUM_UINT32           ulMsgId;            /*_H2ASN_Skip*/
    VOS_UINT32                          ulOpId;

    VOS_UINT32                          bitOpSsCodeValue: 1;
    VOS_UINT32                          bitOpCli        : 1;
    VOS_UINT32                          bitSpare        : 30;

    VOS_UINT8                           ucSsCodeValue;
    VOS_UINT8                           ucCliLength;       /* 1~12*/
    VOS_UINT8                           aucRes[2];
    VOS_UINT8                           aucCliValue[12];

    LMM_MM_PAGING_IND_UE_ID_ENUM_UINT32    enPagingUeId;
} LMM_MM_CSFB_SERVICE_PAGING_IND_STRU;

/*****************************************************************************
结构名    :LMM_MM_EMERGENCY_NUM_STRU
协议表格  :
ASN.1描述 :
结构说明  :紧急呼号码结构
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucCategory;
    VOS_UINT8                           ucEmcNumLen;/*紧急呼号码长度，即aucEmcNum的有效长度*/
    VOS_UINT8                           aucEmcNum[MM_LMM_EMERGENCY_NUM_MAX_LEN];
} LMM_MM_EMERGENCY_NUM_STRU;

/*****************************************************************************
结构名    :LMM_MM_INFO_CHANGE_NOTIFY_STRU
协议表格  :
ASN.1描述 :
结构说明  :LMM_MM_INFO_CHANGE_NOTIFY消息结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    MM_LMM_MSG_ID_ENUM_UINT32           ulMsgId;            /*_H2ASN_Skip*/
    VOS_UINT32                          ulOpId;

    VOS_UINT32                          bitOpEmcNumList : 1;
    VOS_UINT32                          bitOpImsVoPS    : 1;
    VOS_UINT32                          bitOpEmcBS      : 1;
    VOS_UINT32                          bitSpare        : 29;

    VOS_UINT8                           ucEmergencyNumAmount;
    VOS_UINT8                           aucReserved[3];
    LMM_MM_EMERGENCY_NUM_STRU           astEmergencyNumList[MM_LMM_EMERGENCY_NUM_LIST_MAX_RECORDS];

    LMM_MM_NW_IMS_VOICE_ENUM_UINT32     enNwImsVoPS;
    LMM_MM_NW_EMC_BS_ENUM_UINT32        enNwEmcBS;
} LMM_MM_INFO_CHANGE_NOTIFY_STRU;


/*****************************************************************************
结构名    :MM_LMM_HO_SECU_INFO_REQ_STRU
协议表格  :
ASN.1描述 :
结构说明  :MM_LMM_HO_SECU_INFO_REQ消息结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    MM_LMM_MSG_ID_ENUM_UINT32           ulMsgId;            /*_H2ASN_Skip*/
    VOS_UINT32                          ulOpId;

    VOS_UINT8                           aucRsv[4];  /*预留*/
}MM_LMM_HO_SECU_INFO_REQ_STRU;

/*****************************************************************************
 结构名称: MM_LMM_SRVCC_STATUS_NOTIFY_STRU
 协议表格:
 ASN.1 描述:
 结构说明:
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    MMC_LMM_MSG_ID_ENUM_UINT32          ulMsgId;            /*_H2ASN_Skip*/
    VOS_UINT32                          ulOpId;
    MM_LMM_SRVCC_STATUS_ENUM_UINT32     enSrvccStatus;
} MM_LMM_SRVCC_STATUS_NOTIFY_STRU;


/*****************************************************************************
结构名    :MM_LMM_GU_SECU_CONTEXT_STRU
协议表格  :
ASN.1描述 :
结构说明  :LMM映射到GU的安全上下文结构
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulKSI;
    VOS_UINT8                           aucCk[MM_LMM_CK_LEN];
    VOS_UINT8                           aucIk[MM_LMM_IK_LEN];
}MM_LMM_GU_SECU_CONTEXT_STRU;


/*****************************************************************************
结构名    :LMM_MM_HO_SECU_INFO_CNF_STRU
协议表格  :
ASN.1描述 :
结构说明  :ID_LMM_MM_HO_SECU_INFO_CNF消息结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    MM_LMM_MSG_ID_ENUM_UINT32           ulMsgId;            /*_H2ASN_Skip*/
    VOS_UINT32                          ulOpId;

    VOS_UINT32                          bitOpSecuCntxt  : 1;
    VOS_UINT32                          bitSpare        : 31;

    MM_LMM_SECU_INFO_RSLT_ENUM_UINT32   enRslt;
    MM_LMM_GU_SECU_CONTEXT_STRU         stHoSecuCntxt;
}LMM_MM_HO_SECU_INFO_CNF_STRU;


typedef struct
{
    MM_LMM_MSG_ID_ENUM_UINT32           ulMsgId;            /*_H2ASN_MsgChoice_Export MM_LMM_MSG_ID_ENUM_UINT32*/
    VOS_UINT8                           aucMsg[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          MM_LMM_MSG_ID_ENUM_UINT32
    ****************************************************************************/
}MM_LMM_INTERFACE_MSG_DATA;
/*_H2ASN_Length UINT32*/


typedef struct
{
    VOS_MSG_HEADER
    MM_LMM_INTERFACE_MSG_DATA            stMsgData;
} MmLmmInterface_MSG;







/*****************************************************************************
  6 UNION
*****************************************************************************/


/*****************************************************************************
  7 Extern Global Variable
*****************************************************************************/

/*****************************************************************************
  8 Fuction Extern
*****************************************************************************/





/*****************************************************************************
  9 OTHERS
*****************************************************************************/










#if (VOS_OS_VER != VOS_WIN32)
#pragma pack()
#else
#pragma pack(pop)
#endif



#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of MmLmmInterface.h */




