
#include "app_task.h"


static  void  App_TaskStart (void *p_arg);


static  OS_TCB        App_TaskfirstTCB;
static  CPU_STK_SIZE  App_TaskfirstStk[APP_CFG_TASK_START_STK_SIZE];

void  app_task_first_init (OS_ERR  *p_err)
{
	OSTaskCreate((OS_TCB	 *)&App_TaskfirstTCB,		    /* Create the start task				    */
		     (CPU_CHAR	 *)"app_task_first",
		     (OS_TASK_PTR ) App_TaskStart,
		     (void	 *) (void*)"app_task_first",
		     (OS_PRIO	  ) APP_CFG_TASK_START_PRIO,
		     (CPU_STK	 *)&App_TaskfirstStk[0],
		     (CPU_STK	  )(APP_CFG_TASK_START_STK_SIZE / 10u),
		     (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE,
		     (OS_MSG_QTY  ) 0,
		     (OS_TICK	  ) 0,
		     (void	 *) 0,
		     (OS_OPT	  )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
		     (OS_ERR	 *)&p_err);
}


static  OS_TCB        App_TasksecendTCB;
static  CPU_STK_SIZE  App_TasksecendStk[APP_CFG_TASK_START_STK_SIZE];
void  app_task_secend_init (OS_ERR  *p_err)
{
	OSTaskCreate((OS_TCB	 *)&App_TasksecendTCB,		    /* Create the start task				    */
		     (CPU_CHAR	 *)"app_task_secend",
		     (OS_TASK_PTR ) App_TaskStart,
		     (void	 *) (void*)"app_task_secend",
		     (OS_PRIO	  ) APP_CFG_TASK_START_PRIO,
		     (CPU_STK	 *)&App_TasksecendStk[0],
		     (CPU_STK	  )(APP_CFG_TASK_START_STK_SIZE / 10u),
		     (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE,
		     (OS_MSG_QTY  ) 0,
		     (OS_TICK	  ) 0,
		     (void	 *) 0,
		     (OS_OPT	  )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
		     (OS_ERR	 *)&p_err);
}

static  void  App_TaskStart (void *p_arg)
{
	OS_ERR	    os_err;
	

	while (DEF_TRUE) {					    /* Task body, always written as an infinite loop.	    */
	    printf("uCOS-III %s is running.\n",(char*)p_arg);
	    OSTimeDlyHMSM(0u, 0u, 1u, 0u,
			  OS_OPT_TIME_HMSM_STRICT,
			  &os_err);
	}
}

