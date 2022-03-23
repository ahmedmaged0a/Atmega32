################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LED_Pre/LED_Config.c \
../HAL/LED_Pre/LED_Priviliges.c 

OBJS += \
./HAL/LED_Pre/LED_Config.o \
./HAL/LED_Pre/LED_Priviliges.o 

C_DEPS += \
./HAL/LED_Pre/LED_Config.d \
./HAL/LED_Pre/LED_Priviliges.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LED_Pre/%.o: ../HAL/LED_Pre/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=2000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


