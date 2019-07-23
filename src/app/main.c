#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "debug.h"

#include "hal_gpio.h"
#include "hal_com.h"
#include "log.h"
#include "assert.h"

int main(void) {
	
	SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
      //TODO: Remove tivalib and implement it in gpio.c
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);



    log_init();
    log_print("Hello Embedded!!!");

    hal_gpio_t Led1 = {
        .port       = GPIO_PORTF,
        .pin        = GPIO_PIN3,
        .direction  = GPIO_DIR_OUT,
    };
    hal_gpio_init(&Led1);

    logs("Debug");

    while(1)
    {
        // GPIOPinWrite(
        hal_gpio_set_high(&Led1);
        // hal_gpio_set_high(&Led2);
        // hal_gpio_set_high(&Led1);
        SysCtlDelay(2000000);
        hal_gpio_set_low(&Led1);
        SysCtlDelay(2000000);
    }

}
