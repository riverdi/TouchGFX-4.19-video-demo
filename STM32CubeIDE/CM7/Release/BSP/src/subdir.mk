################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSP/src/bsp_button.c \
../BSP/src/bsp_display.c \
../BSP/src/bsp_flash.c \
../BSP/src/bsp_led.c \
../BSP/src/bsp_print.c \
../BSP/src/bsp_ribus.c \
../BSP/src/bsp_sdcard.c 

C_DEPS += \
./BSP/src/bsp_button.d \
./BSP/src/bsp_display.d \
./BSP/src/bsp_flash.d \
./BSP/src/bsp_led.d \
./BSP/src/bsp_print.d \
./BSP/src/bsp_ribus.d \
./BSP/src/bsp_sdcard.d 

OBJS += \
./BSP/src/bsp_button.o \
./BSP/src/bsp_display.o \
./BSP/src/bsp_flash.o \
./BSP/src/bsp_led.o \
./BSP/src/bsp_print.o \
./BSP/src/bsp_ribus.o \
./BSP/src/bsp_sdcard.o 


# Each subdirectory must supply rules for building sources it contributes
BSP/src/%.o BSP/src/%.su: ../BSP/src/%.c BSP/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H747xx -c -I../../../CM7/Core/Inc -I../../../CM7/FATFS/Target -I../../../CM7/FATFS/App -I../../../CM7/LIBJPEG/App -I../../../CM7/LIBJPEG/Target -I../../../CM7/TouchGFX/App -I../../../CM7/TouchGFX/target/generated -I../../../CM7/TouchGFX/target -I../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../../Utilities/JPEG -I../../../Middlewares/Third_Party/FatFs/src -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Middlewares/Third_Party/LibJPEG/include -I../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../Drivers/CMSIS/Include -I../../CM7/../../CM7/Middlewares/ST/touchgfx/framework/include -I../../CM7/../../CM7/TouchGFX/generated/fonts/include -I../../CM7/../../CM7/TouchGFX/generated/gui_generated/include -I../../CM7/../../CM7/TouchGFX/generated/images/include -I../../CM7/../../CM7/TouchGFX/generated/texts/include -I../../CM7/../../CM7/TouchGFX/generated/videos/include -I../../CM7/../../CM7/TouchGFX/gui/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSP-2f-src

clean-BSP-2f-src:
	-$(RM) ./BSP/src/bsp_button.d ./BSP/src/bsp_button.o ./BSP/src/bsp_button.su ./BSP/src/bsp_display.d ./BSP/src/bsp_display.o ./BSP/src/bsp_display.su ./BSP/src/bsp_flash.d ./BSP/src/bsp_flash.o ./BSP/src/bsp_flash.su ./BSP/src/bsp_led.d ./BSP/src/bsp_led.o ./BSP/src/bsp_led.su ./BSP/src/bsp_print.d ./BSP/src/bsp_print.o ./BSP/src/bsp_print.su ./BSP/src/bsp_ribus.d ./BSP/src/bsp_ribus.o ./BSP/src/bsp_ribus.su ./BSP/src/bsp_sdcard.d ./BSP/src/bsp_sdcard.o ./BSP/src/bsp_sdcard.su

.PHONY: clean-BSP-2f-src

