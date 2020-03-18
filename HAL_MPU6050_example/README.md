STM32 CubeIDE 1.3 example
=================
This is my example for basic usage on MPU6050.
The project is implemented on stm32f746g-disco, but should work on other STM32 with minor modifications.

Some functions are implemented. 

1. [ GPIO / LED / Button ]

- Green LED on Pin i1
- Red LED on Pin b4
- Pushbutton(not debounced!) on Pin i11

2. [USB CDC Printing]

- Include "usb_print.h" and in the graphical config tool (.ioc file)
- configure USB_otg as USB_CDC device_only and
- Middleware > usb_device as Communications Device Class 

- On PC grab a serial terminal of your choice like RealTerm or CuteCom
- Connect to the new USB Comport

3. [I2C]

MPU6050 on I2C1 via HAL Drivers and MPU6050 Driver from Jeff Rowberg
https://github.com/jrowberg/i2cdevlib
The example prints x-Axis values to USB CDC
