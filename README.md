psoc-usb-debug
==============

Quick USB serial print functions for debugging the PSoC.


How to Use
----------

1. Include a new USBUART module into your project and call it USBUART_DEBUG.

2. Put the usb_debug.h and usb_debug.c into your working directory.

3. #include the usb_debug.h in the files where you want to use the printing
functions.

4. Call usb_init() once before using the functions.

If you use Windows, install the driver containing the included .inf file. Look
for a serial device in the Hardware Manager and take note of its name.

The USB serial speed is 115200 baud by default.

main.c is an example program that prints with all the functions about once per
second.


Functions
---------

###usb_init()

Initializes USB. Note that this will enable global interrupts.

###usb_put_str(string, str_len)

Prints a string to serial. Best used with sprintf().

###usb_put_uint(number)

Prints an unsigned integer to serial, followed by a line break.

###usb_put_int(number)

Prints a signed integer to serial, followed by a line break.

###usb_put_float(number)

Prints a float to serial, followed by a line break. This will only print up to 5
places after the decimal point. This uses a quick method turning floats into
printable characters, so there may be rounding issues. For a more accurate print,
use sprintf with floats enabled with the usb_put_str function.
