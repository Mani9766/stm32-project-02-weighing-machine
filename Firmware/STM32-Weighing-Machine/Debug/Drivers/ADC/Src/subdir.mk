################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/ADC/Src/adc.c 

OBJS += \
./Drivers/ADC/Src/adc.o 

C_DEPS += \
./Drivers/ADC/Src/adc.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/ADC/Src/%.o Drivers/ADC/Src/%.su Drivers/ADC/Src/%.cyclo: ../Drivers/ADC/Src/%.c Drivers/ADC/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/Manisha Daigavhane/software/workspace/Github_Repositories/stm32-project-02-weighing-machine/Firmware/STM32-Weighing-Machine/Drivers/ADC/Inc" -I"D:/Manisha Daigavhane/software/workspace/Github_Repositories/stm32-project-02-weighing-machine/Firmware/STM32-Weighing-Machine/Drivers/GPIO/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-ADC-2f-Src

clean-Drivers-2f-ADC-2f-Src:
	-$(RM) ./Drivers/ADC/Src/adc.cyclo ./Drivers/ADC/Src/adc.d ./Drivers/ADC/Src/adc.o ./Drivers/ADC/Src/adc.su

.PHONY: clean-Drivers-2f-ADC-2f-Src

