################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
MIE.lss \

FLASH_IMAGE += \
MIE.hex \

EEPROM_IMAGE += \
MIE.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: MIE.elf secondary-outputs

# Tool invocations
MIE.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,MIE.map -mmcu=atmega16 -o "MIE.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

MIE.lss: MIE.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S MIE.elf  >"MIE.lss"
	@echo 'Finished building: $@'
	@echo ' '

MIE.hex: MIE.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex MIE.elf  "MIE.hex"
	@echo 'Finished building: $@'
	@echo ' '

MIE.eep: MIE.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex MIE.elf  "MIE.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: MIE.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 MIE.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) MIE.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
