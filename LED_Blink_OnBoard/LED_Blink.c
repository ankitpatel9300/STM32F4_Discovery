#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIO_LED;

void Delay(__IO uint32_t nCount)
{
	while(nCount--)
	{

	}
}
int main(void)
{
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD , ENABLE) ;

  GPIO_LED.GPIO_Pin = GPIO_Pin_All ;
  //GPIO_LED.GPIO_Pin = GPIO_Pin_13 ;
  //GPIO_LED.GPIO_Pin = GPIO_Pin_14 ;
  //GPIO_LED.GPIO_Pin = GPIO_Pin_15 ;
  GPIO_LED.GPIO_Mode = GPIO_Mode_OUT ;
  GPIO_LED.GPIO_OType = GPIO_OType_PP;
  GPIO_LED.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(GPIOD , &GPIO_LED);

  while(1)
  {
  GPIO_WriteBit (GPIOD , GPIO_Pin_12 , Bit_SET) ;
  Delay (12800000);
  GPIO_WriteBit (GPIOD , GPIO_Pin_12 , Bit_RESET) ;
  Delay (12800000);

  GPIO_WriteBit (GPIOD , GPIO_Pin_13 , Bit_SET) ;
    Delay (12800000);
    GPIO_WriteBit (GPIOD , GPIO_Pin_13 , Bit_RESET) ;
    Delay (12800000);

    GPIO_WriteBit (GPIOD , GPIO_Pin_14 , Bit_SET) ;
      Delay (12800000);
      GPIO_WriteBit (GPIOD , GPIO_Pin_14 , Bit_RESET) ;
      Delay (12800000);

      GPIO_WriteBit (GPIOD , GPIO_Pin_15 , Bit_SET) ;
        Delay (12800000);
        GPIO_WriteBit (GPIOD , GPIO_Pin_15 , Bit_RESET) ;
        Delay (12800000);
  }

  return 0;
}
