################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/nt35510/nt35510.c 

OBJS += \
./Drivers/BSP/Components/nt35510/nt35510.o 

C_DEPS += \
./Drivers/BSP/Components/nt35510/nt35510.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/nt35510/%.o: ../Drivers/BSP/Components/nt35510/%.c Drivers/BSP/Components/nt35510/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components -I../Drivers/BSP/STM32F429I-Discovery -I../Utilities -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-nt35510

clean-Drivers-2f-BSP-2f-Components-2f-nt35510:
	-$(RM) ./Drivers/BSP/Components/nt35510/nt35510.d ./Drivers/BSP/Components/nt35510/nt35510.o

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-nt35510

