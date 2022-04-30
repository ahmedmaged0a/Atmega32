################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/switch/Switch_Config.c \
../HAL/switch/Switch_Program.c 

OBJS += \
./HAL/switch/Switch_Config.o \
./HAL/switch/Switch_Program.o 

C_DEPS += \
./HAL/switch/Switch_Config.d \
./HAL/switch/Switch_Program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/switch/%.o: ../HAL/switch/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=2000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


