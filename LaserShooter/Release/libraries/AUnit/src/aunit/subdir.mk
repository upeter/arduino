################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/Assertion.cpp \
/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/Compare.cpp \
/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/FCString.cpp \
/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/MetaAssertion.cpp \
/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/Printer.cpp \
/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/Test.cpp \
/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/TestAgain.cpp \
/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/TestOnce.cpp \
/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/TestRunner.cpp \
/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/print64.cpp \
/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/string_util.cpp 

LINK_OBJ += \
./libraries/AUnit/src/aunit/Assertion.cpp.o \
./libraries/AUnit/src/aunit/Compare.cpp.o \
./libraries/AUnit/src/aunit/FCString.cpp.o \
./libraries/AUnit/src/aunit/MetaAssertion.cpp.o \
./libraries/AUnit/src/aunit/Printer.cpp.o \
./libraries/AUnit/src/aunit/Test.cpp.o \
./libraries/AUnit/src/aunit/TestAgain.cpp.o \
./libraries/AUnit/src/aunit/TestOnce.cpp.o \
./libraries/AUnit/src/aunit/TestRunner.cpp.o \
./libraries/AUnit/src/aunit/print64.cpp.o \
./libraries/AUnit/src/aunit/string_util.cpp.o 

CPP_DEPS += \
./libraries/AUnit/src/aunit/Assertion.cpp.d \
./libraries/AUnit/src/aunit/Compare.cpp.d \
./libraries/AUnit/src/aunit/FCString.cpp.d \
./libraries/AUnit/src/aunit/MetaAssertion.cpp.d \
./libraries/AUnit/src/aunit/Printer.cpp.d \
./libraries/AUnit/src/aunit/Test.cpp.d \
./libraries/AUnit/src/aunit/TestAgain.cpp.d \
./libraries/AUnit/src/aunit/TestOnce.cpp.d \
./libraries/AUnit/src/aunit/TestRunner.cpp.d \
./libraries/AUnit/src/aunit/print64.cpp.d \
./libraries/AUnit/src/aunit/string_util.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/AUnit/src/aunit/Assertion.cpp.o: /Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/Assertion.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/cores/arduino" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/variants/mega" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/Wire/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_SSD1306/2.5.7" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_GFX_Library/1.11.3" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/SPI/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/List/2.1.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Vector/1.2.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/AUnit/src/aunit/Compare.cpp.o: /Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/Compare.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/cores/arduino" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/variants/mega" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/Wire/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_SSD1306/2.5.7" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_GFX_Library/1.11.3" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/SPI/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/List/2.1.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Vector/1.2.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/AUnit/src/aunit/FCString.cpp.o: /Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/FCString.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/cores/arduino" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/variants/mega" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/Wire/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_SSD1306/2.5.7" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_GFX_Library/1.11.3" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/SPI/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/List/2.1.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Vector/1.2.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/AUnit/src/aunit/MetaAssertion.cpp.o: /Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/MetaAssertion.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/cores/arduino" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/variants/mega" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/Wire/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_SSD1306/2.5.7" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_GFX_Library/1.11.3" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/SPI/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/List/2.1.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Vector/1.2.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/AUnit/src/aunit/Printer.cpp.o: /Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/Printer.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/cores/arduino" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/variants/mega" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/Wire/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_SSD1306/2.5.7" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_GFX_Library/1.11.3" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/SPI/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/List/2.1.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Vector/1.2.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/AUnit/src/aunit/Test.cpp.o: /Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/Test.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/cores/arduino" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/variants/mega" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/Wire/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_SSD1306/2.5.7" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_GFX_Library/1.11.3" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/SPI/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/List/2.1.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Vector/1.2.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/AUnit/src/aunit/TestAgain.cpp.o: /Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/TestAgain.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/cores/arduino" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/variants/mega" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/Wire/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_SSD1306/2.5.7" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_GFX_Library/1.11.3" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/SPI/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/List/2.1.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Vector/1.2.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/AUnit/src/aunit/TestOnce.cpp.o: /Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/TestOnce.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/cores/arduino" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/variants/mega" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/Wire/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_SSD1306/2.5.7" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_GFX_Library/1.11.3" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/SPI/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/List/2.1.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Vector/1.2.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/AUnit/src/aunit/TestRunner.cpp.o: /Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/TestRunner.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/cores/arduino" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/variants/mega" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/Wire/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_SSD1306/2.5.7" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_GFX_Library/1.11.3" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/SPI/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/List/2.1.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Vector/1.2.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/AUnit/src/aunit/print64.cpp.o: /Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/print64.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/cores/arduino" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/variants/mega" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/Wire/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_SSD1306/2.5.7" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_GFX_Library/1.11.3" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/SPI/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/List/2.1.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Vector/1.2.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/AUnit/src/aunit/string_util.cpp.o: /Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src/aunit/string_util.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/cores/arduino" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/variants/mega" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/Wire/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_SSD1306/2.5.7" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_GFX_Library/1.11.3" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/AUnit/1.6.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.5/libraries/SPI/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BusIO/1.13.2" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/List/2.1.1/src" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Vector/1.2.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


