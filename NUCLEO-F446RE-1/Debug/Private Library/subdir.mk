################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Private\ Library/explode.c \
../Private\ Library/function.c \
../Private\ Library/hx711.c \
../Private\ Library/stm32411mapping.c \
../Private\ Library/stm32446mapping.c 

OBJS += \
./Private\ Library/explode.o \
./Private\ Library/function.o \
./Private\ Library/hx711.o \
./Private\ Library/stm32411mapping.o \
./Private\ Library/stm32446mapping.o 

C_DEPS += \
./Private\ Library/explode.d \
./Private\ Library/function.d \
./Private\ Library/hx711.d \
./Private\ Library/stm32411mapping.d \
./Private\ Library/stm32446mapping.d 


# Each subdirectory must supply rules for building sources it contributes
Private\ Library/explode.o: ../Private\ Library/explode.c Private\ Library/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/Git/Stm32/NUCLEO-F446RE-1/Private Library" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Private Library/explode.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Private\ Library/function.o: ../Private\ Library/function.c Private\ Library/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/Git/Stm32/NUCLEO-F446RE-1/Private Library" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Private Library/function.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Private\ Library/hx711.o: ../Private\ Library/hx711.c Private\ Library/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/Git/Stm32/NUCLEO-F446RE-1/Private Library" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Private Library/hx711.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Private\ Library/stm32411mapping.o: ../Private\ Library/stm32411mapping.c Private\ Library/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/Git/Stm32/NUCLEO-F446RE-1/Private Library" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Private Library/stm32411mapping.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Private\ Library/stm32446mapping.o: ../Private\ Library/stm32446mapping.c Private\ Library/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/Git/Stm32/NUCLEO-F446RE-1/Private Library" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Private Library/stm32446mapping.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Private-20-Library

clean-Private-20-Library:
	-$(RM) ./Private\ Library/explode.d ./Private\ Library/explode.o ./Private\ Library/explode.su ./Private\ Library/function.d ./Private\ Library/function.o ./Private\ Library/function.su ./Private\ Library/hx711.d ./Private\ Library/hx711.o ./Private\ Library/hx711.su ./Private\ Library/stm32411mapping.d ./Private\ Library/stm32411mapping.o ./Private\ Library/stm32411mapping.su ./Private\ Library/stm32446mapping.d ./Private\ Library/stm32446mapping.o ./Private\ Library/stm32446mapping.su

.PHONY: clean-Private-20-Library

