################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/Wire/src/utility/twi.c 

C_DEPS += \
./libraries/Wire/src/utility/twi.c.d 

LINK_OBJ += \
./libraries/Wire/src/utility/twi.c.o 


# Each subdirectory must supply rules for building sources it contributes
libraries/Wire/src/utility/twi.c.o: /Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/Wire/src/utility/twi.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/cores/arduino" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/variants/mega" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/Wire/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_SSD1306/2.5.7" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_GFX_Library/1.11.3" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/SPI/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/List/2.1.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Vector/1.2.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


