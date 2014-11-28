#include "usb_debug.h"


void usb_init()
{
	CyGlobalIntEnable;
	USBUART_DEBUG_Start(0, USBUART_DEBUG_3V_OPERATION);
} // usb_init()



void usb_put_str(const char* string, unsigned str_len)
{
	if(USBUART_DEBUG_GetConfiguration())
	{
		USBUART_DEBUG_CDC_Init(); // USB Initialization

		while(!USBUART_DEBUG_CDCIsReady());
		USBUART_DEBUG_PutData((uint8_t*)string, (uint32_t)str_len);
	} // if connected properly
} // usb_send()



void usb_put_uint(unsigned long number)
{
	int str_len;
	char string[16];

	str_len = sprintf(string, "%lu\r\n", (unsigned long)number);
	usb_put_str(string, str_len);
} // usb_put_num()



void usb_put_int(long number)
{
	int str_len;
	char string[16];

	str_len = sprintf(string, "%ld\r\n", (long)number);
	usb_put_str(string, str_len);
} // usb_put_num()



void usb_put_float(float number)
{
	char string[16];
	int str_len, ones, frac, i;

	ones = (int)number;
	str_len = sprintf(string, "%d", ones);
	number -= ones;

	string[str_len++] = '.';

	for(i=0; i<5; i++)
	{
		number *= 10;
		frac = (int)number;
		number -= frac;
		string[str_len++] = '0' + frac;
	} // for 5 digits

	string[str_len++] = '\r';
	string[str_len++] = '\n';

	usb_put_str(string, str_len);
} // usb_put_num()
