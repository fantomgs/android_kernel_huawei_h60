


/*****************************************************************************
  1 Include HeadFile
*****************************************************************************/
#include  "NasERabmTimerMsgProc.h"
#include  "NasERabmRrcMsgProc.h"
#include  "NasERabmCdsMsgProc.h"

/*lint -e767*/
#define    THIS_FILE_ID        PS_FILE_ID_NASRABMTIMERMSGPROC_C
/*lint +e767*/

/*****************************************************************************
  1.1 Cplusplus Announce
*****************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif
/*****************************************************************************
  2 Declare the Global Variable
*****************************************************************************/


/*****************************************************************************
  3 Function
*****************************************************************************/

/*lint -e960*/
VOS_VOID NAS_ERABM_WaitEpsbActTimerExpire( NAS_ERABM_TIMER_NAME_ENUM_UINT8 enTimerName )
{
    (VOS_VOID)enTimerName;

    /*打印进入该函数*/
    NAS_ERABM_INFO_LOG("NAS_ERABM_WaitEpsbActTimerExpire is entered.");

    if (NAS_ERABM_WAIT_EPSB_ACT_MSG == NAS_ERABM_GetWaitEpsbActSign())
    {
        /* 向ESM发承载状态消息 */
        NAS_ERABM_InformEsmBearerStatus();

        /*清除等待EPS承载激活标识*/
        NAS_ERABM_SetWaitEpsBActSign(NAS_ERABM_NOT_WAIT_EPSB_ACT_MSG);

        /*通知后台NAS_ERABM_RB_WAIT_EPSB_ACT_TIMER定时器超时*/
        NAS_ERABM_NORM_LOG("NAS_ERABM_WaitEpsbActTimerExpire: NAS_ERABM_RB_WAIT_EPSB_ACT_TIMER expire!");
    }
}
VOS_VOID NAS_ERABM_WaitRbReestTimerExpier
(
    NAS_ERABM_TIMER_NAME_ENUM_UINT8 enTimerName,
    VOS_UINT32                      ulTimerPara
)
{
    NAS_ERABM_START_TIMER_STRU           *pstTimerInfo       = VOS_NULL_PTR;

    pstTimerInfo = NAS_ERABM_GetRbTimer(enTimerName);

    if ( VOS_NULL_PTR == pstTimerInfo )
    {
        NAS_ERABM_WARN_LOG("NAS_ERABM_WaitRbReestTimerExpier: pstStateTimer NULL.");
        return ;
    }

    /*更新定时器超时次数*/
    pstTimerInfo->ucExpireTimes++;
    /*lint -e961*/
    NAS_ERABM_LOG1("NAS_ERABM_WaitRbReestTimerExpier:data pending = ",NAS_ERABM_GetUpDataPending());
    /*lint +e961*/
    /* 若超时次数在9次以内，并且承载没有对应的DRB，
       则向EMM发送EMM_ERABM_REEST_REQ消息，请求建链，并重新启动
       定时器，否则不再启动定时器，且释放缓存消息*/
    if (( pstTimerInfo->ucExpireTimes < TI_NAS_ERABM_WAIT_RB_REEST_TIMER_MAX_EXP_NUM)
        &&(NAS_ERABM_SUCCESS== NAS_ERABM_IsAllActtiveBearerWithoutDrb())
        &&(NAS_ERABM_SERVICE_STATE_INIT == NAS_ERABM_GetEmmSrState()) )
    {
        NAS_ERABM_INFO_LOG("NAS_ERABM_EMM_RB_ReestTimerExpire:INFO:Expire times less than 9!");
		/* lihong00150010 emergency tau&service begin */
        NAS_ERABM_SndRabmEmmReestReq(ulTimerPara);
        NAS_ERABM_TimerStart(   NAS_ERABM_WAIT_RB_REEST_LENGTH,
                                NAS_ERABM_WAIT_RB_REEST_TIMER,
                                ulTimerPara);
		/* lihong00150010 emergency tau&service end */
    }
    else
    {
        NAS_ERABM_INFO_LOG("NAS_ERABM_EMM_RB_ReestTimerExpire:INFO:Expire times is 9!");

        /*更新定时器超时次数*/
        pstTimerInfo->ucExpireTimes = 0;

        /*SERVICE流程停止*/
        NAS_ERABM_SetEmmSrState(NAS_ERABM_SERVICE_STATE_TERMIN);

        /* 通知L2释放缓存的数据包 */
        /*APPITF_FreeAllofRabmBuf();*/

        /* 通知CDS释放缓存的数据包 */
        NAS_ERABM_SndErabmCdsFreeBuffDataInd();

        /* 清除上行数据阻塞标志*/
        NAS_ERABM_SetUpDataPending(EMM_ERABM_NO_UP_DATA_PENDING);
    }
}


/*****************************************************************************
 Function Name   : NAS_ERABM_WaitRbResumeTimerExpier
 Description     : DRB挂起定时器超时处理
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.sunbing      2010-12-29  Draft Enact

*****************************************************************************/
VOS_VOID  NAS_ERABM_WaitRbResumeTimerExpier( NAS_ERABM_TIMER_NAME_ENUM_UINT8 enTimerName )
{
    VOS_UINT32                          ulEpsbId = NAS_ERABM_NULL;

    (VOS_VOID)enTimerName;

    NAS_ERABM_INFO_LOG("NAS_ERABM_WaitRbResumeTimerExpier is entered.");

    /*RRC链路异常，通知EMM释放链路*/
    NAS_ERABM_SndRabmEmmRelReq();

    /* 释放所有RB */
    for (ulEpsbId = NAS_ERABM_MIN_EPSB_ID; ulEpsbId<= NAS_ERABM_MAX_EPSB_ID; ulEpsbId++)
    {
        NAS_ERABM_RcvRbRelease(ulEpsbId);
    }

    /* 通知L2释放缓存的数据包 */
    /*APPITF_FreeAllofRabmBuf();*/

    /* 通知CDS释放缓存的数据包 */
    NAS_ERABM_SndErabmCdsFreeBuffDataInd();

    /* 清除上行数据阻塞标志*/
    NAS_ERABM_SetUpDataPending(EMM_ERABM_NO_UP_DATA_PENDING);

}


VOS_VOID  NAS_ERABM_WaitTcFreeBufferTimer( NAS_ERABM_TIMER_NAME_ENUM_UINT8 enTimerName )
{
    (VOS_VOID)enTimerName;

    /*APPITF_FreeAllofRabmBuf();*/

    /* 通知CDS释放缓存的数据包 */
    NAS_ERABM_SndErabmCdsFreeBuffDataInd();

    NAS_ERABM_SetUpDataPending(EMM_ERABM_NO_UP_DATA_PENDING);

    return;
}


VOS_VOID   NAS_ERABM_TimerMsgDistr(const VOS_VOID *pRcvMsg )
{

    VOS_UINT32                           ulTimerIndex  = 0;
    NAS_ERABM_START_TIMER_STRU           *pstTimerInfo = VOS_NULL_PTR;

    /*打印进入该函数*/
    NAS_ERABM_INFO_LOG("NAS_ERABM_TimerMsgDistr is entered.");

    ulTimerIndex = PS_GET_REL_TIMER_NAME(pRcvMsg);

    pstTimerInfo = NAS_ERABM_GetRbTimer(ulTimerIndex);

    if ( VOS_NULL_PTR == pstTimerInfo )
    {
        NAS_ERABM_WARN_LOG("NAS_ERABM_TimerMsgDistr: pstStateTimer NULL.");
        return ;
    }

    if (PS_GET_REL_TIMER_NAME(pRcvMsg) == pstTimerInfo->enName)
    {
        switch (pstTimerInfo->enName)
        {
            case NAS_ERABM_WAIT_EPSB_ACT_TIMER:
                NAS_ERABM_WaitEpsbActTimerExpire(NAS_ERABM_WAIT_EPSB_ACT_TIMER);
                break;

            case NAS_ERABM_WAIT_RB_REEST_TIMER:
				/* lihong00150010 emergency tau&service begin */
                NAS_ERABM_WaitRbReestTimerExpier(NAS_ERABM_WAIT_RB_REEST_TIMER,PS_GET_REL_TIMER_PARA(pRcvMsg));
                break;
				/* lihong00150010 emergency tau&service end */
            case NAS_ERABM_WAIT_RB_RESUME_TIMER:
                NAS_ERABM_WaitRbResumeTimerExpier(NAS_ERABM_WAIT_RB_RESUME_TIMER);
                break;

            case NAS_ERABM_WAIT_TC_FREE_BUFFER_TIMER:
                NAS_ERABM_WaitTcFreeBufferTimer(NAS_ERABM_WAIT_TC_FREE_BUFFER_TIMER);
                break;

            default:
                NAS_ERABM_WARN_LOG("NAS_ERABM_TimerMsgDistr:RB TimerExpire: unreasonable Timer expire");
                break;
        }
    }
    else
    {
        NAS_ERABM_WARN_LOG("NAS_ERABM_TimerMsgDistr: RBSETUP Timer Expire info err!");
    }
}
/*lint +e960*/


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

