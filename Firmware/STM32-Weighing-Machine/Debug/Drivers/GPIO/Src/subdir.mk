################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/GPIO/Src/gpio.c 

OBJS += \
./Drivers/GPIO/Src/gpio.o 

C_DEPS += \
./Drivers/GPIO/Src/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/GPIO/Src/%.o Drivers/GPIO/Src/%.su Drivers/GPIO/Src/%.cyclo: ../Drivers/GPIO/Src/%.c Drivers/GPIO/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/Manisha Daigavhane/software/workspace/Github_Repositories/stm32-project-02-weighing-machine/Firmware/STM32-Weighing-Machine/Drivers/GPIO/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-GPIO-2f-Src

clean-Drivers-2f-GPIO-2f-Src:
	-$(RM) ./Drivers/GPIO/Src/gpio.cyclo ./Drivers/GPIO/Src/gpio.d ./Drivers/GPIO/Src/gpio.o ./Drivers/GPIO/Src/gpio.su

.PHONY: clean-Drivers-2f-GPIO-2f-Src

