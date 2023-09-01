#ifndef UNITY_CONFIG_H
#define UNITY_CONFIG_H

#ifdef TARGET
    #include "processor_selection.h"

    void support_init_uart(void);
	void support_uart_putchar(char data);
	void support_disable_uart(void);

	//Redirect Unity default output's to TARGET's uart methods
    #define UNITY_OUTPUT_START() support_init_uart() //Helper function to init UART
	#define UNITY_OUTPUT_CHAR(a) support_uart_putchar(a) //Helper function to forward char via UART
	#define UNITY_OUTPUT_COMPLETE() support_disable_uart() //Helper function to inform that test has ended

#endif

#endif
