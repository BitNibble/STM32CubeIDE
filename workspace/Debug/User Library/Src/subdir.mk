################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/sergi/Documents/GitHub\ 2022/STM32CubeIDE/User\ Library/Src/74hc595.c \
C:/Users/sergi/Documents/GitHub\ 2022/STM32CubeIDE/User\ Library/Src/circbuffer.c \
C:/Users/sergi/Documents/GitHub\ 2022/STM32CubeIDE/User\ Library/Src/explode.c \
C:/Users/sergi/Documents/GitHub\ 2022/STM32CubeIDE/User\ Library/Src/function.c \
C:/Users/sergi/Documents/GitHub\ 2022/STM32CubeIDE/User\ Library/Src/lcd.c \
C:/Users/sergi/Documents/GitHub\ 2022/STM32CubeIDE/User\ Library/Src/stm32446mapping.c \
C:/Users/sergi/Documents/GitHub\ 2022/STM32CubeIDE/User\ Library/Src/test.c 

OBJS += \
./User\ Library/Src/74hc595.o \
./User\ Library/Src/circbuffer.o \
./User\ Library/Src/explode.o \
./User\ Library/Src/function.o \
./User\ Library/Src/lcd.o \
./User\ Library/Src/stm32446mapping.o \
./User\ Library/Src/test.o 

C_DEPS += \
./User\ Library/Src/74hc595.d \
./User\ Library/Src/circbuffer.d \
./User\ Library/Src/explode.d \
./User\ Library/Src/function.d \
./User\ Library/Src/lcd.d \
./User\ Library/Src/stm32446mapping.d \
./User\ Library/Src/test.d 


# Each subdirectory must supply rules for building sources it contributes
User\ Library/Src/74hc595.o: C:/Users/sergi/Documents/GitHub\ 2022/STM32CubeIDE/User\ Library/Src/74hc595.c User\ Library/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/GitHub 2022/STM32CubeIDE/User Library/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User Library/Src/74hc595.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
User\ Library/Src/circbuffer.o: C:/Users/sergi/Documents/GitHub\ 2022/STM32CubeIDE/User\ Library/Src/circbuffer.c User\ Library/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/GitHub 2022/STM32CubeIDE/User Library/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User Library/Src/circbuffer.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
User\ Library/Src/explode.o: C:/Users/sergi/Documents/GitHub\ 2022/STM32CubeIDE/User\ Library/Src/explode.c User\ Library/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/GitHub 2022/STM32CubeIDE/User Library/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User Library/Src/explode.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
User\ Library/Src/function.o: C:/Users/sergi/Documents/GitHub\ 2022/STM32CubeIDE/User\ Library/Src/function.c User\ Library/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/GitHub 2022/STM32CubeIDE/User Library/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User Library/Src/function.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
User\ Library/Src/lcd.o: C:/Users/sergi/Documents/GitHub\ 2022/STM32CubeIDE/User\ Library/Src/lcd.c User\ Library/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/GitHub 2022/STM32CubeIDE/User Library/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User Library/Src/lcd.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
User\ Library/Src/stm32446mapping.o: C:/Users/sergi/Documents/GitHub\ 2022/STM32CubeIDE/User\ Library/Src/stm32446mapping.c User\ Library/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/GitHub 2022/STM32CubeIDE/User Library/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User Library/Src/stm32446mapping.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
User\ Library/Src/test.o: C:/Users/sergi/Documents/GitHub\ 2022/STM32CubeIDE/User\ Library/Src/test.c User\ Library/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/GitHub 2022/STM32CubeIDE/User Library/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User Library/Src/test.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-20-Library-2f-Src

clean-User-20-Library-2f-Src:
	-$(RM) ./User\ Library/Src/74hc595.d ./User\ Library/Src/74hc595.o ./User\ Library/Src/74hc595.su ./User\ Library/Src/circbuffer.d ./User\ Library/Src/circbuffer.o ./User\ Library/Src/circbuffer.su ./User\ Library/Src/explode.d ./User\ Library/Src/explode.o ./User\ Library/Src/explode.su ./User\ Library/Src/function.d ./User\ Library/Src/function.o ./User\ Library/Src/function.su ./User\ Library/Src/lcd.d ./User\ Library/Src/lcd.o ./User\ Library/Src/lcd.su ./User\ Library/Src/stm32446mapping.d ./User\ Library/Src/stm32446mapping.o ./User\ Library/Src/stm32446mapping.su ./User\ Library/Src/test.d ./User\ Library/Src/test.o ./User\ Library/Src/test.su

.PHONY: clean-User-20-Library-2f-Src

