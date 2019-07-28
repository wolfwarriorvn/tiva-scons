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


#define TIMER0_BASE             0x40030000  // Timer0
#define TIMER1_BASE             0x40031000  // Timer1
#define TIMER2_BASE             0x40032000  // Timer2
#define TIMER3_BASE             0x40033000  // Timer3
#define TIMER4_BASE             0x40034000  // Timer4
#define TIMER5_BASE             0x40035000  // Timer5

#define TIMER_CTL_TBPWML        0x00004000  // GPTM Timer B PWM Output Level
#define TIMER_CTL_TBOTE         0x00002000  // GPTM Timer B Output Trigger
                                            // Enable
#define TIMER_CTL_TBEVENT_M     0x00000C00  // GPTM Timer B Event Mode
#define TIMER_CTL_TBEVENT_POS   0x00000000  // Positive edge
#define TIMER_CTL_TBEVENT_NEG   0x00000400  // Negative edge
#define TIMER_CTL_TBEVENT_BOTH  0x00000C00  // Both edges
#define TIMER_CTL_TBSTALL       0x00000200  // GPTM Timer B Stall Enable
#define TIMER_CTL_TBEN          0x00000100  // GPTM Timer B Enable
#define TIMER_CTL_TAPWML        0x00000040  // GPTM Timer A PWM Output Level
#define TIMER_CTL_TAOTE         0x00000020  // GPTM Timer A Output Trigger
                                            // Enable
#define TIMER_CTL_RTCEN         0x00000010  // GPTM RTC Stall Enable
#define TIMER_CTL_TAEVENT_M     0x0000000C  // GPTM Timer A Event Mode
#define TIMER_CTL_TAEVENT_POS   0x00000000  // Positive edge
#define TIMER_CTL_TAEVENT_NEG   0x00000004  // Negative edge
#define TIMER_CTL_TAEVENT_BOTH  0x0000000C  // Both edges
#define TIMER_CTL_TASTALL       0x00000002  // GPTM Timer A Stall Enable
#define TIMER_CTL_TAEN          0x00000001  // GPTM Timer A Enable


#endif /* __LM4F120H5QR_H__ */