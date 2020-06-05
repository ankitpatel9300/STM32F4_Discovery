################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third-Party/FreeRTOS/org/Source/portable/MemMang/heap_4.c 

OBJS += \
./Third-Party/FreeRTOS/org/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./Third-Party/FreeRTOS/org/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Third-Party/FreeRTOS/org/Source/portable/MemMang/%.o: ../Third-Party/FreeRTOS/org/Source/portable/MemMang/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407G_DISC1 -DDEBUG -DSTM32F40XX -DUSE_STDPERIPH_DRIVER -I"/home/ankit/workspace/RTOS_workspace/STM32_FreeRTOS_LED_and_Button/Third-Party/FreeRTOS/org/Source/include" -I"/home/ankit/workspace/RTOS_workspace/STM32_FreeRTOS_LED_and_Button/Third-Party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F" -I"/home/ankit/workspace/RTOS_workspace/STM32_FreeRTOS_LED_and_Button/StdPeriph_Driver/inc" -I"/home/ankit/workspace/RTOS_workspace/STM32_FreeRTOS_LED_and_Button/Third-Party/FreeRTOS/org" -I"/home/ankit/workspace/RTOS_workspace/STM32_FreeRTOS_LED_and_Button/Config" -I"/home/ankit/workspace/RTOS_workspace/STM32_FreeRTOS_LED_and_Button/inc" -I"/home/ankit/workspace/RTOS_workspace/STM32_FreeRTOS_LED_and_Button/CMSIS/device" -I"/home/ankit/workspace/RTOS_workspace/STM32_FreeRTOS_LED_and_Button/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


