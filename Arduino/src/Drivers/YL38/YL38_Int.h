#ifndef _YL38_INT_H
#define _YL38_INT_H


#include "YL38_Ext.h"
#include <Arduino.h>

#define YL38_RAW_ANALOGREAD_LOW 50
#define YL38_RAW_ANALOGREAD_HIGH 1023

BYTE_T _BYTE_ArduinoAnalogPort;
BYTE_T _BYTE_RemapLow;
BYTE_T _BYTE_RemapHigh ;

ERROR_T YL38_CheckNullpointer(const void* pvoid);
ERROR_T YL38_Map(INT32_T INT32_Value, INT32_T INT32_InMin, INT32_T INT32_InMax, INT32_T INT32_OutMin, INT32_T INT32_OutMax, INT32_T* INT32_MappedValue);

#endif