/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "FreeRTOS.h"
#include "task.h"
#include "stm32f4xx.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
			
#define TRUE 1
#define FALSE 0
#define PRESSED TRUE
#define NOT_PRESSED FALSE
// function prototype
static void prvSetupHardware(void) ;
static void prvSetupUART2(void) ;
void printmsg(char *msg);
void prvSetupGPIO(void);

//Task prototypes
void vLED_Task (void *pvParameters);
void vButton_Task(void *pvParameters);

//Global Variables
uint8_t button_status_flag =NOT_PRESSED;

int main(void)
{
	    //1. Reset the RCC clock configuration to he default reset state.
		//HSI ON, OLL oFF,HSE OFF, System Clock=16Mhz, CPU Clock=16MHz
		RCC_DeInit();

		//2. Update the SystemCoreClock variable
		SystemCoreClockUpdate();

		prvSetupHardware();

		//3.Create LED and Button tasks
		xTaskCreate(vLED_Task ,"LED_TaSk",configMINIMAL_STACK_SIZE,NULL,1,NULL);
		xTaskCreate(vButton_Task ,"Button_Task",configMINIMAL_STACK_SIZE,NULL,1,NULL);

		//4. Start the scheduler
		vTaskStartScheduler();

		for(;;);
}

void vLED_Task (void *pvParameters)
{
	while(1)
	{
		if(button_status_flag== PRESSED)
		      {
		    	  //turn-ON the LED
		    	  GPIO_WriteBit(GPIOD,GPIO_Pin_12,Bit_SET) ;
		      }
		      else
		      {
		    	  //Turn-OFF the LED
		    	  GPIO_WriteBit(GPIOD,GPIO_Pin_12,Bit_RESET) ;
		      }
	}
}
void vButton_Task(void *pvParameters)
{
	while(1)
	{
      if (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) )
      {
    	  //User Button is pressed on Discovery Board
    	  button_status_flag= PRESSED ;
      }
      else
      {
    	  //User Button is not pressed on Discovery Board
    	  button_status_flag= NOT_PRESSED ;
      }
	}
}

static void prvSetupHardware(void)
{
	// Setup LED and Button GPIO
	prvSetupGPIO();

	// Setup UART2
	prvSetupUART2();
}

void printmsg(char *msg)
{
	for(uint32_t i=0; i< strlen(msg); i++)
	{
		while( USART_GetFlagStatus(USART2 ,USART_FLAG_TXE)!= SET );
		USART_SendData(USART2 , msg[i]) ;

	}
}
static void prvSetupUART2(void)
{
	    GPIO_InitTypeDef gpio_uart_pins;
		USART_InitTypeDef uart2_init ;

	   //1.Enable the UART2 and GPIOA peripheral clock
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE) ;
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA , ENABLE) ;

	   // Setting PA2-USART Tx and PA3-USART Rx

	   //2. Alternate function of MCU pins to behave as USART2
		// zeroing each and every member element of the structure
		memset(&gpio_uart_pins,0,sizeof(gpio_uart_pins) ) ;
		gpio_uart_pins.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 ;
		gpio_uart_pins.GPIO_Mode =GPIO_Mode_AF;
		gpio_uart_pins.GPIO_PuPd = GPIO_PuPd_UP ;
		GPIO_Init( GPIOA, &gpio_uart_pins) ;

		//3.AF Mode settings for pins
	    GPIO_PinAFConfig(GPIOA ,GPIO_PinSource2 ,GPIO_AF_USART2)  ; //PA2
	    GPIO_PinAFConfig(GPIOA ,GPIO_PinSource3 ,GPIO_AF_USART2)  ; //PA3

	    //4. UART parameter initializations
	    // zeroing each and every member element of the structure
	    memset(&uart2_init,0,sizeof(uart2_init) ) ;
	    uart2_init.USART_BaudRate =115200 ;
	    uart2_init.USART_HardwareFlowControl = USART_HardwareFlowControl_None ;
	    uart2_init.USART_Mode =  USART_Mode_Rx | USART_Mode_Tx ;
	    uart2_init.USART_Parity =USART_Parity_No ;
	    uart2_init.USART_StopBits =USART_StopBits_1 ;
	    uart2_init.USART_WordLength= USART_WordLength_8b ;
	    USART_Init(USART2 ,&uart2_init) ;

	    //Enable the USART2 peripheral
	    USART_Cmd(USART2 ,ENABLE) ;

}

void prvSetupGPIO(void)
{
    //Board Specific function- STM32F407-Disc1
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA , ENABLE) ;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD , ENABLE) ;

	GPIO_InitTypeDef led_init, button_init ;

	led_init.GPIO_Mode = GPIO_Mode_OUT;
	led_init.GPIO_OType =GPIO_OType_PP ;
	led_init.GPIO_Pin = GPIO_Pin_12;
	led_init.GPIO_Speed = GPIO_Low_Speed ;
    led_init.GPIO_PuPd = GPIO_PuPd_NOPULL ;
    GPIO_Init(GPIOD, &led_init);

    button_init.GPIO_Mode =GPIO_Mode_IN ;
    button_init.GPIO_OType =GPIO_OType_PP ;
    button_init.GPIO_Pin= GPIO_Pin_0 ;
    button_init.GPIO_Speed= GPIO_Low_Speed ;
    button_init.GPIO_PuPd =GPIO_PuPd_NOPULL ;
    GPIO_Init(GPIOA, &button_init);



}
