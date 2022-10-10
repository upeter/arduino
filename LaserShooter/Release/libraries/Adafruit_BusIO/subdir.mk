################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2/Adafruit_BusIO_Register.cpp \
/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2/Adafruit_I2CDevice.cpp \
/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2/Adafruit_SPIDevice.cpp 

LINK_OBJ += \
./libraries/Adafruit_BusIO/Adafruit_BusIO_Register.cpp.o \
./libraries/Adafruit_BusIO/Adafruit_I2CDevice.cpp.o \
./libraries/Adafruit_BusIO/Adafruit_SPIDevice.cpp.o 

CPP_DEPS += \
./libraries/Adafruit_BusIO/Adafruit_BusIO_Register.cpp.d \
./libraries/Adafruit_BusIO/Adafruit_I2CDevice.cpp.d \
./libraries/Adafruit_BusIO/Adafruit_SPIDevice.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/Adafruit_BusIO/Adafruit_BusIO_Register.cpp.o: /Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2/Adafruit_BusIO_Register.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/cores/arduino" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/variants/mega" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/Wire/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_SSD1306/2.5.7" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_GFX_Library/1.11.3" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/SPI/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/List/2.1.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Vector/1.2.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/Adafruit_BusIO/Adafruit_I2CDevice.cpp.o: /Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2/Adafruit_I2CDevice.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/cores/arduino" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/variants/mega" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/Wire/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_SSD1306/2.5.7" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_GFX_Library/1.11.3" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/SPI/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/List/2.1.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Vector/1.2.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/Adafruit_BusIO/Adafruit_SPIDevice.cpp.o: /Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2/Adafruit_SPIDevice.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/cores/arduino" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/variants/mega" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/Wire/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_SSD1306/2.5.7" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_GFX_Library/1.11.3" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/SPI/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/List/2.1.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Vector/1.2.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


