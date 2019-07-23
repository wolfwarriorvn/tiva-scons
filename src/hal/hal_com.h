#ifndef __HALCOM_H__
#define __HALCOM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "std_type.h"

typedef enum hal_com_return
{
  COM_OK,
  COM_TIMEOUT,
  COM_UNKNOWN_ERROR
} hal_com_return_t;

typedef enum hal_com_name
{
  COM0,
  COM_MAX_IDX
} hal_com_name_t;

typedef enum hal_com_baudrate
{
  COM_BAUD_9600 = 9600,
  COM_BAUD_19200 = 19200,
  COM_BAUD_38400 = 38400,
  COM_BAUD_57600 = 57600,
  COM_BAUD_115200 = 115200,
  COM_BAUD_921600 = 921600 
} hal_com_baudrate_t;

typedef struct hal_com
{
  hal_com_name_t      port_name;
  hal_com_baudrate_t  baudrate;
  void    (*com_irq_rx_cb)(void);
  void    (*com_irq_tx_cb)(void);
  uint8_t *data;
} hal_com_t;

void hal_com_init(hal_com_t *com);

hal_com_return_t hal_com_sendbyte(hal_com_t *com);

hal_com_return_t hal_com_readbyte(hal_com_t *com);


#ifdef __cplusplus
}
#endif
#endif /* __HALCOM_H__ */