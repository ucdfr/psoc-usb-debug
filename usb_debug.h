#ifndef USB_DEBUG_H
#define USB_DEBUG_H

#include <project.h>
#include <stdio.h>

void usb_init();
void usb_put_str(const char* string, unsigned str_len);
void usb_put_uint(unsigned long number);
void usb_put_int(long number);
void usb_put_float(float number);

#endif
