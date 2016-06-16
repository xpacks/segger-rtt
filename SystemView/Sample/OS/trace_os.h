/*********************************************************************
*               SEGGER MICROCONTROLLER GmbH & Co. KG                 *
*       Solutions for real time microcontroller applications         *
**********************************************************************
*                                                                    *
*       (c) 2015 - 2016  SEGGER Microcontroller GmbH & Co. KG        *
*                                                                    *
*       www.segger.com     Support: support@segger.com               *
*                                                                    *
**********************************************************************
*                                                                    *
*       SEGGER SystemView * Real-time application analysis           *
*                                                                    *
**********************************************************************
*                                                                    *
* All rights reserved.                                               *
*                                                                    *
* * This software may in its unmodified form be freely redistributed *
*   in source form.                                                  *
* * The source code may be modified, provided the source code        *
*   retains the above copyright notice, this list of conditions and  *
*   the following disclaimer.                                        *
* * Modified versions of this software in source or linkable form    *
*   may not be distributed without prior consent of SEGGER.          *
*                                                                    *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS "AS IS" AND     *
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  *
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A        *
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL               *
* SEGGER Microcontroller BE LIABLE FOR ANY DIRECT, INDIRECT,         *
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES           *
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS    *
* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS            *
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,       *
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING          *
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS *
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.       *
*                                                                    *
**********************************************************************
*                                                                    *
*       SystemView version: V2.34                                    *
*                                                                    *
**********************************************************************
-------------------------- END-OF-HEADER -----------------------------

File    : trace_os.h
Purpose : Interface header for Micrium uC/OS-III and SystemView.
*/
#include "SEGGER_SYSVIEW.h"
#include "os.h"
#include "trace_cfg.h"


/*
*********************************************************************************************************
*                                            uC/Trace Macros
*********************************************************************************************************
*/

#if TRACE_CFG_EN > 0
#define  TRACE_INIT()                                      SEGGER_SYSVIEW_Conf()
#define  TRACE_START()                                     SEGGER_SYSVIEW_Start()
#define  TRACE_STOP()                                      SEGGER_SYSVIEW_Stop()
#else
#define  TRACE_INIT()
#define  TRACE_START()
#define  TRACE_STOP()
#endif

/*
*********************************************************************************************************
*                                       uC/Trace Kernel-Related Macros
*********************************************************************************************************
*/

#if TRACE_CFG_EN > 0
#define  TRACE_OS_TASK_CREATE(p_tcb)                if (p_tcb != 0) {                                                   \
                                                      SEGGER_SYSVIEW_OnTaskCreate((U32)p_tcb);                          \
                                                      SYSVIEW_AddTask((U32)p_tcb,                                       \
                                                                      &(p_tcb->NamePtr[0]),                             \
                                                                      p_tcb->Prio,                                      \
                                                                      p_tcb->StkBasePtr,                                \
                                                                      p_tcb->StkSize                                    \
                                                                      );                                                \
                                                    }

#define  TRACE_OS_TASK_READY(p_tcb)                 SYSVIEW_TaskReady((U32)p_tcb)
#define  TRACE_OS_TASK_SWITCHED_IN(p_tcb)           SYSVIEW_TaskSwitchedIn((U32)p_tcb)
#define  TRACE_OS_TASK_DLY(dly_ticks)
#define  TRACE_OS_TASK_SUSPEND(p_tcb)               SYSVIEW_TaskSuspend((U32)p_tcb)
#define  TRACE_OS_TASK_RESUME(p_tcb)                SYSVIEW_TaskReady((U32)p_tcb)

#define  TRACE_OS_ISR_BEGIN(isr_id)                 SEGGER_SYSVIEW_RecordEnterISR()
#define  TRACE_OS_ISR_END()                         SEGGER_SYSVIEW_RecordExitISR()
#define  TRACE_OS_ISR_END_TO_SCHEDULER()            SEGGER_SYSVIEW_RecordExitISRToScheduler()


#define  TRACE_OS_TICK_INCREMENT(OSTickCtr)

#define  TRACE_OS_TASK_CREATE_FAILED(p_tcb)
#define  TRACE_OS_TASK_DEL(p_tcb)

#define  TRACE_OS_ISR_REGISTER(isr_id, isr_name, isr_prio)

#define  TRACE_OS_TASK_MSG_Q_CREATE(p_msg_q, p_name)
#define  TRACE_OS_TASK_MSG_Q_POST(p_msg_q)
#define  TRACE_OS_TASK_MSG_Q_POST_FAILED(p_msg_q)
#define  TRACE_OS_TASK_MSG_Q_PEND(p_msg_q)
#define  TRACE_OS_TASK_MSG_Q_PEND_FAILED(p_msg_q)
#define  TRACE_OS_TASK_MSG_Q_PEND_BLOCK(p_msg_q)

#define  TRACE_OS_TASK_SEM_CREATE(p_tcb, p_name)
#define  TRACE_OS_TASK_SEM_POST(p_tcb)
#define  TRACE_OS_TASK_SEM_POST_FAILED(p_tcb)
#define  TRACE_OS_TASK_SEM_PEND(p_tcb)
#define  TRACE_OS_TASK_SEM_PEND_FAILED(p_tcb)
#define  TRACE_OS_TASK_SEM_PEND_BLOCK(p_tcb)

#define  TRACE_OS_MUTEX_CREATE(p_mutex, p_name)
#define  TRACE_OS_MUTEX_DEL(p_mutex)
#define  TRACE_OS_MUTEX_POST(p_mutex)
#define  TRACE_OS_MUTEX_POST_FAILED(p_mutex)
#define  TRACE_OS_MUTEX_PEND(p_mutex)
#define  TRACE_OS_MUTEX_PEND_FAILED(p_mutex)
#define  TRACE_OS_MUTEX_PEND_BLOCK(p_mutex)

#define  TRACE_OS_MUTEX_TASK_PRIO_INHERIT(p_tcb, prio)
#define  TRACE_OS_MUTEX_TASK_PRIO_DISINHERIT(p_tcb, prio)

#define  TRACE_OS_SEM_CREATE(p_sem, p_name)
#define  TRACE_OS_SEM_DEL(p_sem)
#define  TRACE_OS_SEM_POST(p_sem)
#define  TRACE_OS_SEM_POST_FAILED(p_sem)
#define  TRACE_OS_SEM_PEND(p_sem)
#define  TRACE_OS_SEM_PEND_FAILED(p_sem)
#define  TRACE_OS_SEM_PEND_BLOCK(p_sem)

#define  TRACE_OS_Q_CREATE(p_q, p_name)
#define  TRACE_OS_Q_DEL(p_q)
#define  TRACE_OS_Q_POST(p_q)
#define  TRACE_OS_Q_POST_FAILED(p_q)
#define  TRACE_OS_Q_PEND(p_q)
#define  TRACE_OS_Q_PEND_FAILED(p_q)
#define  TRACE_OS_Q_PEND_BLOCK(p_q)

#define  TRACE_OS_FLAG_CREATE(p_grp, p_name)
#define  TRACE_OS_FLAG_DEL(p_grp)
#define  TRACE_OS_FLAG_POST(p_grp)
#define  TRACE_OS_FLAG_POST_FAILED(p_grp)
#define  TRACE_OS_FLAG_PEND(p_grp)
#define  TRACE_OS_FLAG_PEND_FAILED(p_grp)
#define  TRACE_OS_FLAG_PEND_BLOCK(p_grp)

#define  TRACE_OS_MEM_CREATE(p_mem, p_name)
#define  TRACE_OS_MEM_PUT(p_mem)
#define  TRACE_OS_MEM_PUT_FAILED(p_mem)
#define  TRACE_OS_MEM_GET(p_mem)
#define  TRACE_OS_MEM_GET_FAILED(p_mem)

#else

#define  TRACE_OS_TICK_INCREMENT(OSTickCtr)

#define  TRACE_OS_TASK_CREATE(p_tcb)
#define  TRACE_OS_TASK_CREATE_FAILED(p_tcb)
#define  TRACE_OS_TASK_DEL(p_tcb)
#define  TRACE_OS_TASK_READY(p_tcb)
#define  TRACE_OS_TASK_SWITCHED_IN(p_tcb)
#define  TRACE_OS_TASK_DLY(dly_ticks)
#define  TRACE_OS_TASK_SUSPEND(p_tcb)
#define  TRACE_OS_TASK_RESUME(p_tcb)

#define  TRACE_OS_ISR_REGISTER(isr_id, isr_name, isr_prio)
#define  TRACE_OS_ISR_BEGIN(isr_id)
#define  TRACE_OS_ISR_END()
#define  TRACE_OS_ISR_END_TO_SCHEDULER()

#define  TRACE_OS_TASK_MSG_Q_CREATE(p_msg_q, p_name)
#define  TRACE_OS_TASK_MSG_Q_POST(p_msg_q)
#define  TRACE_OS_TASK_MSG_Q_POST_FAILED(p_msg_q)
#define  TRACE_OS_TASK_MSG_Q_PEND(p_msg_q)
#define  TRACE_OS_TASK_MSG_Q_PEND_FAILED(p_msg_q)
#define  TRACE_OS_TASK_MSG_Q_PEND_BLOCK(p_msg_q)

#define  TRACE_OS_TASK_SEM_CREATE(p_tcb, p_name)
#define  TRACE_OS_TASK_SEM_POST(p_tcb)
#define  TRACE_OS_TASK_SEM_POST_FAILED(p_tcb)
#define  TRACE_OS_TASK_SEM_PEND(p_tcb)
#define  TRACE_OS_TASK_SEM_PEND_FAILED(p_tcb)
#define  TRACE_OS_TASK_SEM_PEND_BLOCK(p_tcb)

#define  TRACE_OS_MUTEX_CREATE(p_mutex, p_name)
#define  TRACE_OS_MUTEX_DEL(p_mutex)
#define  TRACE_OS_MUTEX_POST(p_mutex)
#define  TRACE_OS_MUTEX_POST_FAILED(p_mutex)
#define  TRACE_OS_MUTEX_PEND(p_mutex)
#define  TRACE_OS_MUTEX_PEND_FAILED(p_mutex)
#define  TRACE_OS_MUTEX_PEND_BLOCK(p_mutex)

#define  TRACE_OS_MUTEX_TASK_PRIO_INHERIT(p_tcb, prio)
#define  TRACE_OS_MUTEX_TASK_PRIO_DISINHERIT(p_tcb, prio)

#define  TRACE_OS_SEM_CREATE(p_sem, p_name)
#define  TRACE_OS_SEM_DEL(p_sem)
#define  TRACE_OS_SEM_POST(p_sem)
#define  TRACE_OS_SEM_POST_FAILED(p_sem)
#define  TRACE_OS_SEM_PEND(p_sem)
#define  TRACE_OS_SEM_PEND_FAILED(p_sem)
#define  TRACE_OS_SEM_PEND_BLOCK(p_sem)

#define  TRACE_OS_Q_CREATE(p_q, p_name)
#define  TRACE_OS_Q_DEL(p_q)
#define  TRACE_OS_Q_POST(p_q)
#define  TRACE_OS_Q_POST_FAILED(p_q)
#define  TRACE_OS_Q_PEND(p_q)
#define  TRACE_OS_Q_PEND_FAILED(p_q)
#define  TRACE_OS_Q_PEND_BLOCK(p_q)

#define  TRACE_OS_FLAG_CREATE(p_grp, p_name)
#define  TRACE_OS_FLAG_DEL(p_grp)
#define  TRACE_OS_FLAG_POST(p_grp)
#define  TRACE_OS_FLAG_POST_FAILED(p_grp)
#define  TRACE_OS_FLAG_PEND(p_grp)
#define  TRACE_OS_FLAG_PEND_FAILED(p_grp)
#define  TRACE_OS_FLAG_PEND_BLOCK(p_grp)

#define  TRACE_OS_MEM_CREATE(p_mem, p_name)
#define  TRACE_OS_MEM_PUT(p_mem)
#define  TRACE_OS_MEM_PUT_FAILED(p_mem)
#define  TRACE_OS_MEM_GET(p_mem)
#define  TRACE_OS_MEM_GET_FAILED(p_mem)

#endif


/*********************************************************************
*
*       API functions
*
**********************************************************************
*/
#ifdef __cplusplus
extern "C" {
#endif
void SYSVIEW_TaskReady      (U32 TaskID);
void SYSVIEW_TaskSwitchedIn (U32 TaskID);
void SYSVIEW_TaskSuspend    (U32 TaskID);
void SYSVIEW_AddTask        (U32 TaskID, const char* NamePtr, OS_PRIO Prio, CPU_STK* StkBasePtr, CPU_STK_SIZE StkSize);
void SYSVIEW_UpdateTask     (U32 TaskID, const char* NamePtr, OS_PRIO Prio, CPU_STK* StkBasePtr, CPU_STK_SIZE StkSize);
void SYSVIEW_SendTaskInfo   (U32 TaskID, const char* sName, unsigned Prio, U32 StackBase, unsigned StackSize);
void SYSVIEW_RecordU32x4    (unsigned Id, U32 Para0, U32 Para1, U32 Para2, U32 Para3);
void SYSVIEW_RecordU32x5    (unsigned Id, U32 Para0, U32 Para1, U32 Para2, U32 Para3, U32 Para4);

#ifdef __cplusplus
}
#endif