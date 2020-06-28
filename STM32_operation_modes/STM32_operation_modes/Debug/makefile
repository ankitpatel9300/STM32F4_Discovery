################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32_operation_modes.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32_operation_modes.list \

OBJCOPY_HEX += \
STM32_operation_modes.hex \

OBJCOPY_BIN += \
STM32_operation_modes.bin \


# All Target
all: STM32_operation_modes.elf secondary-outputs

# Tool invocations
STM32_operation_modes.elf: $(OBJS) $(USER_OBJS) /home/ankit/STM32CubeIDE/workspace_1.3.0/STM32_operation_modes/STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "STM32_operation_modes.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/home/ankit/STM32CubeIDE/workspace_1.3.0/STM32_operation_modes/STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM32_operation_modes.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32_operation_modes.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32_operation_modes.list"
	@echo 'Finished building: $@'
	@echo ' '

STM32_operation_modes.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "STM32_operation_modes.hex"
	@echo 'Finished building: $@'
	@echo ' '

STM32_operation_modes.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "STM32_operation_modes.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
