/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Some macros
#define TRUE 1
#define FALSE 0
#define AVAILABLE TRUE
#define NOT_AVAILABLE FALSE

// Global variable declaration
uint8_t UART_ACCESS_KEY = AVAILABLE ;
char usr_msg[250]={0} ;

TaskHandle_t xTaskHandle1= NULL ;
TaskHandle_t xTaskHandle2= NULL ;

// function prototype
static void prvSetupHardware(void) ;
void vTask1_handler (void *pvParameters);
void vTask2_handler (void *pvParameters);
static void prvSetupUART2(void) ;
void printmsg(char *msg);



// used for semi-hosting
#ifdef USE_SEMIHOSTING
extern void initialise_monitor_handles();
#endif

int main(void)
{
	// used for semi-hosting
      #ifdef USE_SEMIHOSTING
	         initialise_monitor_handles();
	         printf("This is HelloWorld example\n");
      #endif

	//1. Reset the RCC clock configuration to he default reset state.
	//HSI ON, OLL oFF,HSE OFF, System Clock=16Mhz, CPU Clock=16MHz
	RCC_DeInit();

	//2. Update the SystemCoreClock variable
	SystemCoreClockUpdate();

	prvSetupHardware();

	sprintf(usr_msg," I am UART , How are you doing user?\r\n ");
	printmsg(usr_msg) ;

	//3. Create 2 tasks, task-1 and task-2
	xTaskCreate( vTask1_handler,"Task-1",configMINIMAL_STACK_SIZE,NULL,2,&xTaskHandle1 ) ;

	xTaskCreate( vTask2_handler,"Task-2",configMINIMAL_STACK_SIZE,NULL,2,&xTaskHandle2 ) ;

    vTaskStartScheduler();
	for(;;);
}

void vTask1_handler (void *pvParameters)
{
    while(1)
    {
    	if(UART_ACCESS_KEY == AVAILABLE)
    	{
    	 UART_ACCESS_KEY= NOT_AVAILABLE ;
         printmsg("Hello from Task-1, printing on UART\r\n") ;
         UART_ACCESS_KEY= AVAILABLE ;
         taskYIELD();
    	}
    }
}

void vTask2_handler (void *pvParameters)
{
    while(1)
    {
    	if(UART_ACCESS_KEY == AVAILABLE)
    	  {
    	  UART_ACCESS_KEY= NOT_AVAILABLE ;
    	  printmsg("Hello from Task-2, printing on UART\r\n") ;
    	  UART_ACCESS_KEY= AVAILABLE ;
    	  taskYIELD();
    	  }
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

static void prvSetupHardware(void)
{
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




