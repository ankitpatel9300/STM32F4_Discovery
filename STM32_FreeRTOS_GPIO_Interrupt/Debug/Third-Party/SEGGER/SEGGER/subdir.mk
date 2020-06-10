################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third-Party/SEGGER/SEGGER/SEGGER_RTT.c \
../Third-Party/SEGGER/SEGGER/SEGGER_SYSVIEW.c 

OBJS += \
./Third-Party/SEGGER/SEGGER/SEGGER_RTT.o \
./Third-Party/SEGGER/SEGGER/SEGGER_SYSVIEW.o 

C_DEPS += \
./Third-Party/SEGGER/SEGGER/SEGGER_RTT.d \
./Third-Party/SEGGER/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
Third-Party/SEGGER/SEGGER/%.o: ../Third-Party/SEGGER/SEGGER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407G_DISC1 -DDEBUG -DSTM32F40XX -DUSE_STDPERIPH_DRIVER -I"/home/ankit/workspace/RTOS_workspace/STM32_FreeRTOS_GPIO_Interrupt/StdPeriph_Driver/inc" -I"/home/ankit/workspace/RTOS_workspace/STM32_FreeRTOS_GPIO_Interrupt/Third-Party/SEGGER/Config" -I"/home/ankit/workspace/RTOS_workspace/STM32_FreeRTOS_GPIO_Interrupt/Third-Party/SEGGER/OS" -I"/home/ankit/workspace/RTOS_workspace/STM32_FreeRTOS_GPIO_Interrupt/Third-Party/SEGGER/SEGGER" -I"/home/ankit/workspace/RTOS_workspace/STM32_FreeRTOS_GPIO_Interrupt/Config" -I"/home/ankit/workspace/RTOS_workspace/STM32_FreeRTOS_GPIO_Interrupt/Third-Party/FreeRTOS/org/Source/include" -I"/home/ankit/workspace/RTOS_workspace/STM32_FreeRTOS_GPIO_Interrupt/Third-Party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F" -I"/home/ankit/workspace/RTOS_workspace/STM32_FreeRTOS_GPIO_Interrupt/inc" -I"/home/ankit/workspace/RTOS_workspace/STM32_FreeRTOS_GPIO_Interrupt/CMSIS/device" -I"/home/ankit/workspace/RTOS_workspace/STM32_FreeRTOS_GPIO_Interrupt/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


