################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_prog.c \
../DIO_prog.c \
../LM_prog.c \
../MAPPING.c \
../Timer_Program.c \
../main.c 

OBJS += \
./ADC_prog.o \
./DIO_prog.o \
./LM_prog.o \
./MAPPING.o \
./Timer_Program.o \
./main.o 

C_DEPS += \
./ADC_prog.d \
./DIO_prog.d \
./LM_prog.d \
./MAPPING.d \
./Timer_Program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


