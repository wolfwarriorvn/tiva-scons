#include "hal_com.h"
#include "lm4f120h5qr.h"

#define CLOCK_50MHZ   50000000



typedef struct uart_reg
{
  __IO uint32_t DR            ; /* Data */
  __IO uint32_t RSR            ; /* Receive status */
  __I  uint32_t Rvsd1[4]       ; /* Resevered */
  __I  uint32_t FR             ; /* Flag */
  __IO uint32_t ILPR           ; /* IrDA Low-Power Register */
  __I  uint32_t Rvsd6          ;
  __IO uint32_t IBRD           ; /* Integer Baud-Rate Divisor */
  __IO uint32_t FBRD           ; /* Fraction Baud-Rate Divisor */
  __IO uint32_t LCRH           ; /* Line Control */
  __IO uint32_t CTR            ; /* Control */
  __IO uint32_t IFLS           ; /* Interrupt FIFO Level Select */
  __IO uint32_t IM             ; /* Interrupt Mask */
  __I  uint32_t RIS            ; /* Raw Interrupt Status */
  __I  uint32_t MIS            ; /* Masked Interrupt Status */
  __IO uint32_t ICR            ; /* Interrupt Clear */
  __IO uint32_t DMACTL         ; /* DMA Control */
  __I  uint32_t Rsvd2[17]      ; 
  __IO uint32_t LCTL           ; /* LIN Control */
  __I  uint32_t LSS            ; /* LIN Snap Shot */
  __I  uint32_t LTIM           ; /* LIN Timer */
  __I  uint32_t Rsvd3[2]       ;
  __IO uint32_t _9BITADDR       ; /* 9-Bit Self Address */
  __IO uint32_t _9BITAMASK      ; /* 9-Bit Self Address Mask */
  __I  uint32_t Rsvd4[965]      ;
  __I  uint32_t PP             ; /* Periperal Properties */
  __I  uint32_t Rsvd5          ;
  __I  uint32_t CC             ; /* Clock Configuration */
  __I  uint32_t Rsvd6          ;
  __I  uint32_t PeriphID4      ; /* Periperal Identification 4 */
  __I  uint32_t PeriphID5      ; /* Periperal Identification 5 */
  __I  uint32_t PeriphID6      ; /* Periperal Identification 6 */
  __I  uint32_t PeriphID7      ; /* Periperal Identification 7 */
  __I  uint32_t PeriphID0      ; /* Periperal Identification 0 */
  __I  uint32_t PeriphID1      ; /* Periperal Identification 1 */
  __I  uint32_t PeriphID2      ; /* Periperal Identification 2 */
  __I  uint32_t PeriphID3      ; /* Periperal Identification 3 */
  __I  uint32_t PCellID0       ; /* Periperal Identification 0 */
  __I  uint32_t PCellID1       ; /* PrimeCell Identification 1 */
  __I  uint32_t PCellID2       ; /* PrimeCell Identification 2 */
  __I  uint32_t PCellID3       ; /* PrimeCell Identification 3 */
} uart_reg_t;

typedef struct uart_config
{
  uart_reg_t  *handler;
  void (*uart_irq_handler)(void);
  void (*rx_irq_cb)(void);
  void (*tx_irq_cb)(void);
} uart_config_t;

static uart_config_t uart_configs[COM_MAX_IDX] = 
{
  /* COM1 */
  {
    .handler = (uart_reg_t *)UART0_BASE,
    .uart_irq_handler = NULL_PTR,
    .rx_irq_cb = NULL_PTR,
    .tx_irq_cb = NULL_PTR
  }
};

void hal_com_init(hal_com_t *com)
{
  uart_reg_t *uart = uart_configs[com->port_name].handler;
  // Enable port gpio
  // set tx,rx
  // set baurate

  /* Disable UART */
  uart->CTR &= ~UART_CTL_UARTEN_MASK;

  uint32_t baurate_div = ((8 * CLOCK_50MHZ / com->baudrate) + 1) / 2;
  uart->IBRD = baurate_div / 64;
  uart->FBRD = baurate_div % 64;

  /* Set parity, data lenght, number of stop bit */
  uart->LCRH = UART_LCRH_WLEN_8 | UART_LCRH_STOP_ONE | UART_LCRH_PAR_NONE;

  // /* Clear the flags register */
  // uart->FR = 0;

  /* Start the UART. */
  uart->CTR |= UART_CTL_UARTEN_MASK;
}

hal_com_return_t hal_com_sendbyte(hal_com_t *com)
{
  uart_reg_t *uart = uart_configs[com->port_name].handler;

  /* Wait until a new byte can fit into the FIFO */
  while(uart->FR & UART_FR_TXFF_MASK)
  {
  }

  /* Send the char */
  uart->DR = *(com->data);
}

hal_com_return_t hal_com_readbyte(hal_com_t *com)
{
  //TODO: implement read 
}



