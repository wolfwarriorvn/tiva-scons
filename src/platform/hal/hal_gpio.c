#include "hal_gpio.h"
#include "std_type.h"
#include "lm4f120h5qr.h"
#include "log.h"

// typdedef struct 
// {
//   __IO uint32_t test;
// };
typedef struct hal_gpio_reg
{
  __IO  uint32_t DATA         ;/* Data */
  __IO  uint32_t PIN_MASK[255]   ; /* Reserved */
  __IO  uint32_t DIR          ;/* Direction */
  __IO  uint32_t IS           ;/* Interrupt Sencse */
  __IO  uint32_t IBE          ;/* Interrupt Both Edges */
  __IO  uint32_t IEV          ;/* Interrupt Event */
  __IO  uint32_t IM           ;/* Interrupt Mask */
  __I   uint32_t RIS          ;/* Raw Interrupt Status */
  __I   uint32_t MIS          ;/* Masked Interrupt Status */
  __IO  uint32_t ICR          ;/* Interrupt Clear */
  __IO  uint32_t AFSEL        ;/* Alternate Function Select */
  __I   uint32_t Rsvd2[55]    ;
  __IO  uint32_t DR2R         ;/* 2-mA Drive Select */
  __IO  uint32_t DR4R         ;/* 4-mA Drive Select */
  __IO  uint32_t DR8R         ;/* 8-mA Drive Select */
  __IO  uint32_t ODR          ;/* Opent Drain Select */
  __IO  uint32_t PUR          ;/* Pull-Up Select */
  __IO  uint32_t PDR          ;/* Pull-Down Select */
  __IO  uint32_t SLR          ;/* Slew Rate Control Select */
  __IO  uint32_t DEN          ;/* Digital Enable */
  __IO  uint32_t LOCK         ;/* Lock */
  __IO  uint32_t CR           ;/* Commit */
  __IO  uint32_t AMSEL        ;/* Analog Mode Select */
  __IO  uint32_t PCTL         ;/* Port Control */
  __IO  uint32_t ADCCTL       ;/* ADC Control */
  __IO  uint32_t DMACTL       ;/* DMA Conrtol */
  __I   uint32_t Rsvd3[678]   ;
  __I   uint32_t PeriphID4    ;/* Peripheral Identification 4 */
  __I   uint32_t PeriphID5    ;/* Peripheral Identification 5 */
  __I   uint32_t PeriphID6    ;/* Peripheral Identification 6 */
  __I   uint32_t PeriphID7    ;/* Peripheral Identification 7 */
  __I   uint32_t PeriphID0    ;/* Peripheral Identification 0 */
  __I   uint32_t PeriphID1    ;/* Peripheral Identification 1 */
  __I   uint32_t PeriphID2    ;/* Peripheral Identification 2 */
  __I   uint32_t PeriphID3    ;/* Peripheral Identification 3 */
  __I   uint32_t CellID0      ;/* PrimeCell Identification 0 */
  __I   uint32_t CellID1      ;/* PrimeCell Identification 1 */
  __I   uint32_t CellID2      ;/* PrimeCell Identification 2 */
  __I   uint32_t CellID3      ;/* PrimeCell Identification 3 */
} hal_gpio_reg_t;

static hal_gpio_reg_t *const gpio_bases[] = {
  (hal_gpio_reg_t *)GPIOA_BASE,
  (hal_gpio_reg_t *)GPIOB_BASE,
  (hal_gpio_reg_t *)GPIOC_BASE,
  (hal_gpio_reg_t *)GPIOD_BASE,
  (hal_gpio_reg_t *)GPIOE_BASE,
  (hal_gpio_reg_t *)GPIOF_BASE
};

void hal_gpio_init(hal_gpio_t *gpio)
{
  hal_gpio_reg_t *gpio_reg = gpio_bases[gpio->port];
  //set push-pull operation

  gpio_reg->DIR = (gpio->direction & 1) ?
                  gpio_reg->DIR | (1 << gpio->pin) :
                  gpio_reg->DIR & ~(1 << gpio->pin);

  // //  Set the output drive strength
  gpio_reg->DEN |= (1 << gpio->pin);
  gpio_reg->DR2R |= (1 << gpio->pin);

  gpio_reg->ODR &= ~(1 << gpio->pin);
  gpio_reg->AFSEL &= ~(1 << gpio->pin);
  gpio_reg->PUR &= ~(1 << gpio->pin);
  gpio_reg->PDR &= ~(1 << gpio->pin);
  gpio_reg->DR4R &= ~(1 << gpio->pin);
  gpio_reg->DR8R &= ~(1 << gpio->pin);
  gpio_reg->SLR &= ~(1 << gpio->pin);
  gpio_reg->AMSEL &= ~(1 << gpio->pin);
}

void hal_gpio_set_high(hal_gpio_t *gpio)
{
  hal_gpio_reg_t *gpio_reg = gpio_bases[gpio->port];
  gpio_reg->PIN_MASK[(1 << gpio->pin) - 1] = 1 << gpio->pin;
}

void hal_gpio_set_low(hal_gpio_t *gpio)
{
  hal_gpio_reg_t *gpio_reg = gpio_bases[gpio->port];
  gpio_reg->PIN_MASK[(1 << gpio->pin) - 1] = ~(1 << gpio->pin);
}