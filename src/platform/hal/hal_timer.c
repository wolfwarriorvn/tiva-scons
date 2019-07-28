#include "hal_timer.h"
#include "lm4f120h5qr.h"
#include "assert.h"
#include "board_config.h"
// driverlib
#include "driverlib/interrupt.h"
#include "inc/tm4c123gh6pm.h"
#include "driverlib/timer.h"
#include "driverlib/sysctl.h"


/* Private define -------------------------------------------------------*/

/* Define for TMAR register */
#define TIMER_ONSHOT 0x220
#define TIMER_PERIODIC 0x222
typedef struct timer_reg
{
  __IO uint32_t CFG;          /* Configuration */
  __IO uint32_t TAMR;         /* Timer A Mode */
  __IO uint32_t TBMR;         /* Timer B Mode */
  __IO uint32_t CTR;          /* Control */
  __IO uint32_t SYNC;         /* Synchronize */
  __I  uint32_t Rvsd1;        /* Reversed */
  __IO uint32_t IMR;          /* Interrupt Mask */
  __I  uint32_t RIS;          /* Raw Interrupt Status */
  __I  uint32_t MIS;          /* Master Interrupt Status */
  __IO uint32_t ICR;          /* Interrupt Clear */
  __IO uint32_t TAIL;         /* Timer A Interval Load */
  __IO uint32_t TBIL;         /* Timer B Interval Load */
  __IO uint32_t TAMATCHR;     /* Timer A Match */
  __IO uint32_t TBMATCHR;     /* Timer B */
  __IO uint32_t TAPR;         /* Timer A Prescale */
  __IO uint32_t TBPR;         /* Timer B Prescale */
  __IO uint32_t TAPRMR;       /* Timer A Prescale Match */
  __IO uint32_t TBPRMR;       /* Timer B Prescale Match */
  __I  uint32_t TAR;          /* Timer A */
  __I  uint32_t TBR;          /* Timer B */
  __IO uint32_t TAV;          /* Timer A Value */
  __IO uint32_t TBV;          /* Timer B Value */
  __I uint32_t RTCPRD;       /* RTC Predevide */
  __I uint32_t TAPS;         /* Timer A Prescale Snapshot */
  __I uint32_t TBPS;         /* Timer B Prescale Snapshot */
  __I uint32_t TAPV;         /* Timer A Prescale Value */
  __I uint32_t TBPV;         /* Timer B Prescale Value */
} timer_reg_t;

#define TIMER0    (timer_reg_t *)TIMER0_BASE
#define TIMER1    (timer_reg_t *)TIMER1_BASE
#define TIMER2    (timer_reg_t *)TIMER2_BASE
#define TIMER3    (timer_reg_t *)TIMER3_BASE
#define TIMER4    (timer_reg_t *)TIMER4_BASE
#define TIMER5    (timer_reg_t *)TIMER5_BASE

#define HW_TIMER_CLK_MHZ      (HW_TIMER_CLK_HZ / 1000000)
typedef struct timer_config
{
	timer_reg_t		*handle;							/* Timer handle */
	void			(*callback_handler)(void *params);	/* Interrupt handler */
	hal_timer_mode_t mode;								/* Timer Mode */
	void			*params;
} timer_config_t;

static timer_config_t timer_configs[] = 
{
  {
    .handle = TIMER0,
    .callback_handler = NULL_PTR,
    .mode = ONE_SHOT,
    .params = NULL_PTR
  },
  {
    .handle = TIMER1,
    .callback_handler = NULL_PTR,
    .mode = ONE_SHOT,
    .params = NULL_PTR
  }
};

/* Interrupt handler */
// static void Timer0_IntHandler(void);
// static void Timer1_IntHandler(void);
// static void Timer2_IntHandler(void);
// static void Timer3_IntHandler(void);
// static void Timer4_IntHandler(void);
// static void Timer5_IntHandler(void);

/* Private function prototypes */
static void timer_irq_handler(hal_timer_channel_t chid);

hal_timer_return_t hal_timer_init(hal_timer_t *tim)
{
  timer_reg_t *timer = timer_configs[tim->chid].handle;

  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);

  /* Disable the selected timer */
  timer->CTR &= ~(TIMER_CTL_TAEN | TIMER_CTL_TBEN);
  timer->CFG = 0;

  /* Set Interrupt handler */
  timer_configs[tim->chid].callback_handler = tim->callback_handler;

  /* Set the mode  */
  timer_configs[tim->chid].mode = tim->mode;
  
  /* Set the callback params */
  timer_configs[tim->chid].params = tim->params; 

  /* Set the timer period */
  timer->TAIL = HW_TIMER_CLK_MHZ * tim->period;

  /* GPTM Timer n Mode Register   */
  timer->TAMR = (tim->mode) ? TIMER_PERIODIC : TIMER_ONSHOT;

  // /* Interrupt register */
  switch (tim->chid)
  {
  case HAL_TIM_CH0:
    IntEnable(INT_TIMER0A);
    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    IntMasterEnable();
    break;
  default:
    assert(0);
    break;
  }
}

void hal_timer_start(hal_timer_channel_t chid)
{
  TimerEnable(TIMER0_BASE, TIMER_A);
}

void Timer0_IntHandler(void)
{
  // logs("come here!");
  timer_irq_handler(HAL_TIM_CH0);
}

void Timer1_IntHandler(void)
{
  timer_irq_handler(HAL_TIM_CH1);
}

void Timer2_IntHandler(void)
{
  timer_irq_handler(HAL_TIM_CH2);
}

void Timer3_IntHandler(void)
{
  timer_irq_handler(HAL_TIM_CH3);
}

void Timer4_IntHandler(void)
{
  timer_irq_handler(HAL_TIM_CH4);
}

void Timer5_IntHandler(void)
{
  timer_irq_handler(HAL_TIM_CH5);
}

static void timer_irq_handler(hal_timer_channel_t chid)
{
  // Clear timer
  TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
  // timer_reg_t *timer = timer_configs[chid].handle;
  void *params = timer_configs[chid].params;

  if(NULL_PTR != timer_configs[chid].callback_handler)
  {
    /* Call back funtion to upper */
    (*(timer_configs[chid].callback_handler))(params);
  }
}

