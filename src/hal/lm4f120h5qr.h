#ifndef __LM4F120H5QR_H__
#define __LM4F120H5QR_H__

/** @addtogroup Peripheral_memory_map
  * @{
  */
#define GPIOA_BASE      (0x40004000)
#define GPIOB_BASE      (0x40005000)
#define GPIOC_BASE      (0x40006000)
#define GPIOD_BASE      (0x40007000)
#define GPIOE_BASE      (0x40024000)
#define GPIOF_BASE      (0x40025000)

#define UART0_BASE      (0x4000C000)  // UART0


/* Define UART Control register */
#define UART_CTL_UARTEN_MASK        (0x1U)
// #define UART_CTL_SIREN_MASK         (0x2U)
// #define UART_CTL_SIRLP_MASK         (0x4U)
// #define UART_CTL_SIRLP_MASK         (0x8U)
// #define UART_CTL_SMART_MASK         (0x10U)
// #define UART_CTL_EOT_MASK           (0x20U)
// #define UART_CTL_HSE_MASK           (0x40U)
// #define UART_CTL_LIN_MASK           (0x80U)

/* Define UART Line Control */
#define UART_LCRH_WLEN_8        0x00000060  // 8 bit data
#define UART_LCRH_STOP_ONE      0x00000000  // One stop bit
#define UART_LCRH_PAR_NONE      0x00000000  // No parity

#define UART_FR_TXFF_MASK       0x00000020  // UART Transmit FIFO Full

#endif /* __LM4F120H5QR_H__ */