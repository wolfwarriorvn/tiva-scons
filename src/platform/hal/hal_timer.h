#ifndef __HAL_TIMER_H__
#define __HAL_TIMER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "std_type.h"

typedef enum hal_timer_channel
{
  HAL_TIM_CH0 = 0,
  HAL_TIM_CH1,
  HAL_TIM_CH2,
  HAL_TIM_CH3,
  HAL_TIM_CH4,
  HAL_TIM_CH5,

  HAL_TIM_CHMAX
} hal_timer_channel_t;

typedef enum hal_timer_return 
{
  HAL_TIM_OK,
  HAL_TIM_NULL_PTR,
  HAL_TIM_INVALID_CHANNEL,
  HAL_TIM_UNKNOWN_ERROR
} hal_timer_return_t;

typedef enum hal_timer_mode
{
  ONE_SHOT,
  AUTO_RELOAD
} hal_timer_mode_t;

typedef struct hal_timer
{
  hal_timer_channel_t chid;
  uint32_t      period;
  hal_timer_mode_t mode;
  void (*callback_handler)(void *params);
  void *params;
} hal_timer_t;

// typedef void (*handler_t)(void);

hal_timer_return_t hal_timer_init(hal_timer_t *tim);

void hal_timer_start(hal_timer_channel_t chid);

#ifdef __cplusplus
}
#endif

#endif /* __HAL_TIMER_H__ */