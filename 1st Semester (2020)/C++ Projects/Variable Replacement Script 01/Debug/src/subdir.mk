################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Variable\ Replacement\ Script\ 01.cpp 

OBJS += \
./src/Variable\ Replacement\ Script\ 01.o 

CPP_DEPS += \
./src/Variable\ Replacement\ Script\ 01.d 


# Each subdirectory must supply rules for building sources it contributes
src/Variable\ Replacement\ Script\ 01.o: ../src/Variable\ Replacement\ Script\ 01.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Variable Replacement Script 01.d" -MT"src/Variable\ Replacement\ Script\ 01.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


