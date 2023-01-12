################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/STemWin_HelloWorld/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery.c \
C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/STemWin_HelloWorld/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_io.c \
C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/STemWin_HelloWorld/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_lcd.c \
C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/STemWin_HelloWorld/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_sdram.c \
C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/STemWin_HelloWorld/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_ts.c 

OBJS += \
./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery.o \
./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_io.o \
./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_lcd.o \
./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_sdram.o \
./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_ts.o 

C_DEPS += \
./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery.d \
./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_io.d \
./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_lcd.d \
./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_sdram.d \
./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_ts.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery.o: C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/STemWin_HelloWorld/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery.c Drivers/BSP/STM324x9I_DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/buttons/Drivers/BSP/Components" -I"C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/buttons/Drivers/BSP/STM324x9I_DISCO" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_io.o: C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/STemWin_HelloWorld/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_io.c Drivers/BSP/STM324x9I_DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/buttons/Drivers/BSP/Components" -I"C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/buttons/Drivers/BSP/STM324x9I_DISCO" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_lcd.o: C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/STemWin_HelloWorld/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_lcd.c Drivers/BSP/STM324x9I_DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/buttons/Drivers/BSP/Components" -I"C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/buttons/Drivers/BSP/STM324x9I_DISCO" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_sdram.o: C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/STemWin_HelloWorld/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_sdram.c Drivers/BSP/STM324x9I_DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/buttons/Drivers/BSP/Components" -I"C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/buttons/Drivers/BSP/STM324x9I_DISCO" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_ts.o: C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/STemWin_HelloWorld/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_ts.c Drivers/BSP/STM324x9I_DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/buttons/Drivers/BSP/Components" -I"C:/Users/Korisnik/STM32CubeIDE/workspace_1.11.0/buttons/Drivers/BSP/STM324x9I_DISCO" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM324x9I_DISCO

clean-Drivers-2f-BSP-2f-STM324x9I_DISCO:
	-$(RM) ./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery.d ./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery.o ./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery.su ./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_io.d ./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_io.o ./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_io.su ./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_lcd.d ./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_lcd.o ./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_lcd.su ./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_sdram.d ./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_sdram.o ./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_sdram.su ./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_ts.d ./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_ts.o ./Drivers/BSP/STM324x9I_DISCO/stm32f429i_discovery_ts.su

.PHONY: clean-Drivers-2f-BSP-2f-STM324x9I_DISCO

