#include "timer_test.h"
#include "hal_timer.h"
#include "hal_gpio.h"
#include "std_type.h"
/* Local variable -----------------------------------------*/
#define TIMER_TEST_ID HAL_TIM_CH0
void timer_debug(void* params);

static hal_gpio_t Led1 = {
    .port       = GPIO_PORTF,
    .pin        = GPIO_PIN3,
    .direction  = GPIO_DIR_OUT,
};

static hal_timer_t time_test = 
{
  .chid             = TIMER_TEST_ID,
  .period           = 1000000,
  .mode             = AUTO_RELOAD,
  .callback_handler = timer_debug,
  .params           = NULL
};

void timer_test_start()
{
  hal_gpio_init(&Led1);
  hal_timer_init(&time_test);
  hal_timer_start(TIMER_TEST_ID);
}

void timer_debug(void* params)
{
    static bool flag = false;

    if(flag)
    {
        hal_gpio_set_high(&Led1);
    }
    else
    {
        hal_gpio_set_low(&Led1);
    }
    flag ^= true;
}