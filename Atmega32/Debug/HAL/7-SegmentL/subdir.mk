################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/7-SegmentL/7-Seg_Config.c \
../HAL/7-SegmentL/7-Seg_Program.c 

OBJS += \
./HAL/7-SegmentL/7-Seg_Config.o \
./HAL/7-SegmentL/7-Seg_Program.o 

C_DEPS += \
./HAL/7-SegmentL/7-Seg_Config.d \
./HAL/7-SegmentL/7-Seg_Program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/7-SegmentL/%.o: ../HAL/7-SegmentL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=2000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


