# Usart-Spi bridge

Demo of a bridge between USART and SPI interfaces for Nucleo-F429ZI board using FREERTOS

## Prerequisites
- arm-gcc toolchain (download from https://developer.arm.com/downloads/-/gnu-rm)
- OpenOCD (On debian: ```sudo apt install openocd```)

it is recommended to use vscode to run, debug and flash firmware.

## How to Run 
- check ```armToolchainPath``` and ```configFiles``` paths in ./vscode/launch.json
- run Debug Firmware configuration (F5)
OR
- ```make``` to build binary ```*.elf```
- flash manually

## Description

This project has 4 rtos tasks. Two tasks are serving USART3 and SPI1. Another two tasks are for test purpose: they send the messages emulating the connected devices from USART2 and SPI4 interdaces. 



## Discliamer
This solution does not pretend to be the optimal, it does use HAL and pays no attention to perfomance and power consumption.