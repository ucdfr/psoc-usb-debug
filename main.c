#include <project.h>
#include <stdio.h>
#include "usb_debug.h"


int main()
{
	char string[16];
	unsigned length;

	usb_init();

	for(;;)
	{
		length = sprintf(string, "\r\nI AM PSoC!!!\r\n");
		usb_put_str(string, length);

		usb_put_uint(12345);
		usb_put_int(-12345);
		usb_put_float(1234.56789);
		CyDelay(1000);
	}

	return 0;
} // main()
