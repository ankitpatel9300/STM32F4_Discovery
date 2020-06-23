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
inline_asmCode.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
inline_asmCode.list \

OBJCOPY_BIN += \
inline_asmCode.bin \


# All Target
all: inline_asmCode.elf secondary-outputs

# Tool invocations
inline_asmCode.elf: $(OBJS) $(USER_OBJS) /home/ankit/STM32CubeIDE/workspace_1.3.0/inline_asmCode/STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "inline_asmCode.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/home/ankit/STM32CubeIDE/workspace_1.3.0/inline_asmCode/STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="inline_asmCode.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

inline_asmCode.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "inline_asmCode.list"
	@echo 'Finished building: $@'
	@echo ' '

inline_asmCode.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "inline_asmCode.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
