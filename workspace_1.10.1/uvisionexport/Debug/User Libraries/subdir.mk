################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/User\ Libraries/74hc595.c \
C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/User\ Libraries/explode.c \
C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/User\ Libraries/function.c \
C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/User\ Libraries/lcd.c \
C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/User\ Libraries/stm32446mapping.c \
C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/User\ Libraries/test.c 

OBJS += \
./User\ Libraries/74hc595.o \
./User\ Libraries/explode.o \
./User\ Libraries/function.o \
./User\ Libraries/lcd.o \
./User\ Libraries/stm32446mapping.o \
./User\ Libraries/test.o 

C_DEPS += \
./User\ Libraries/74hc595.d \
./User\ Libraries/explode.d \
./User\ Libraries/function.d \
./User\ Libraries/lcd.d \
./User\ Libraries/stm32446mapping.d \
./User\ Libraries/test.d 


# Each subdirectory must supply rules for building sources it contributes
User\ Libraries/74hc595.o: C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/User\ Libraries/74hc595.c User\ Libraries/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/User Libraries" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User Libraries/74hc595.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
User\ Libraries/explode.o: C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/User\ Libraries/explode.c User\ Libraries/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/User Libraries" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User Libraries/explode.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
User\ Libraries/function.o: C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/User\ Libraries/function.c User\ Libraries/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/User Libraries" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User Libraries/function.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
User\ Libraries/lcd.o: C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/User\ Libraries/lcd.c User\ Libraries/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/User Libraries" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User Libraries/lcd.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
User\ Libraries/stm32446mapping.o: C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/User\ Libraries/stm32446mapping.c User\ Libraries/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/User Libraries" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User Libraries/stm32446mapping.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
User\ Libraries/test.o: C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/User\ Libraries/test.c User\ Libraries/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/sergi/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I"C:/Users/sergi/Documents/STM32CubeIDE/workspace_1.10.1/User Libraries" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User Libraries/test.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-20-Libraries

clean-User-20-Libraries:
	-$(RM) ./User\ Libraries/74hc595.d ./User\ Libraries/74hc595.o ./User\ Libraries/74hc595.su ./User\ Libraries/explode.d ./User\ Libraries/explode.o ./User\ Libraries/explode.su ./User\ Libraries/function.d ./User\ Libraries/function.o ./User\ Libraries/function.su ./User\ Libraries/lcd.d ./User\ Libraries/lcd.o ./User\ Libraries/lcd.su ./User\ Libraries/stm32446mapping.d ./User\ Libraries/stm32446mapping.o ./User\ Libraries/stm32446mapping.su ./User\ Libraries/test.d ./User\ Libraries/test.o ./User\ Libraries/test.su

.PHONY: clean-User-20-Libraries

