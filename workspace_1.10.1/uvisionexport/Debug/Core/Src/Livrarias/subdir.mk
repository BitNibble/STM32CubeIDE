################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Livrarias/74hc595.c \
../Core/Src/Livrarias/explode.c \
../Core/Src/Livrarias/function.c \
../Core/Src/Livrarias/lcd.c \
../Core/Src/Livrarias/stm32446mapping.c \
../Core/Src/Livrarias/test.c 

OBJS += \
./Core/Src/Livrarias/74hc595.o \
./Core/Src/Livrarias/explode.o \
./Core/Src/Livrarias/function.o \
./Core/Src/Livrarias/lcd.o \
./Core/Src/Livrarias/stm32446mapping.o \
./Core/Src/Livrarias/test.o 

C_DEPS += \
./Core/Src/Livrarias/74hc595.d \
./Core/Src/Livrarias/explode.d \
./Core/Src/Livrarias/function.d \
./Core/Src/Livrarias/lcd.d \
./Core/Src/Livrarias/stm32446mapping.d \
./Core/Src/Livrarias/test.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Livrarias/%.o Core/Src/Livrarias/%.su: ../Core/Src/Livrarias/%.c Core/Src/Livrarias/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/uvisionexport/User Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Livrarias

clean-Core-2f-Src-2f-Livrarias:
	-$(RM) ./Core/Src/Livrarias/74hc595.d ./Core/Src/Livrarias/74hc595.o ./Core/Src/Livrarias/74hc595.su ./Core/Src/Livrarias/explode.d ./Core/Src/Livrarias/explode.o ./Core/Src/Livrarias/explode.su ./Core/Src/Livrarias/function.d ./Core/Src/Livrarias/function.o ./Core/Src/Livrarias/function.su ./Core/Src/Livrarias/lcd.d ./Core/Src/Livrarias/lcd.o ./Core/Src/Livrarias/lcd.su ./Core/Src/Livrarias/stm32446mapping.d ./Core/Src/Livrarias/stm32446mapping.o ./Core/Src/Livrarias/stm32446mapping.su ./Core/Src/Livrarias/test.d ./Core/Src/Livrarias/test.o ./Core/Src/Livrarias/test.su

.PHONY: clean-Core-2f-Src-2f-Livrarias

