#ifndef __HAL_GPIO__
#define __HAL_GPIO__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Exported typedef ----------------------------------------------------------*/

typedef enum hal_gpio_port
{
  GPIO_PORTA = 0,
  GPIO_PORTB, 
  GPIO_PORTC,
  GPIO_PORTD,
  GPIO_PORTE,
  GPIO_PORTF,
  GPIO_PORT_MAX_IDX
} hal_gpio_port_t;

typedef enum hal_gpio_pin
{
  GPIO_PIN0 = 0,
  GPIO_PIN1,
  GPIO_PIN2,
  GPIO_PIN3,
  GPIO_PIN4,
  GPIO_PIN5,
  GPIO_PIN6,
  GPIO_PIN7,
  GPIO_PIN_MAX_IDX
} hal_gpio_pin_t;

typedef enum hal_gpio_dir
{
  GPIO_DIR_IN = 0,
  GPIO_DIR_OUT,
  GPIO_DIR_MODEHW
} hal_gpio_dir_t;

typedef enum hal_gpio_level
{
  GPIO_LEVEL_LOW = 0,
  GPIO_LEVEL_HIGH
} hal_gpio_level_t;

typedef enum hal_gpio_exti_type
{
  GPIO_EXTI_FALLING_EDGE = 0,
  GPIO_EXTI_RISING_EDGE
} hal_gpio_exti_type_t;

typedef struct hal_gpio
{
  hal_gpio_port_t   port;
  hal_gpio_pin_t    pin;
  hal_gpio_dir_t    direction;
} hal_gpio_t;

typedef struct hal_gpip_exti
{
  hal_gpio_pin_t  pin;
  hal_gpio_exti_type_t int_type;
  void (*irq_handler)(void);
} hal_gpio_exti_t;

void hal_gpio_init(hal_gpio_t *gpio);

void hal_gpio_set_high(hal_gpio_t *gpio);

void hal_gpio_set_low(hal_gpio_t *gpio);

#ifdef __cplusplus
}
#endif

#endif /* __HAL_GPIO__ */