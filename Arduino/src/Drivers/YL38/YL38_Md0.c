#include "YL38_Int.h"

ERROR_T YL38_CheckNullpointer(const void* pvoid)
{
	ERROR_T ERROR_Value = E_NULL;

	if (pvoid != NULL)
	{
		ERROR_Value = E_OK;
	}
	else
	{
		ERROR_Value = E_NULL; 
	}

	return ERROR_Value;
}

ERROR_T YL38_InitDriver(BYTE_T BYTE_ArduinoAnalogPort, 
                       BYTE_T BYTE_RemapLow,
                       BYTE_T BYTE_RemapHigh)
{
    ERROR_T E_Value = E_NULL;

    _BYTE_ArduinoAnalogPort = BYTE_ArduinoAnalogPort;
    _BYTE_RemapLow = BYTE_RemapLow;
    _BYTE_RemapHigh = BYTE_RemapHigh;

    E_Value = E_OK;

    return E_Value;
}

// https://www.ardumotive.com/soil-hygrometer-module-en.html
ERROR_T YL38_ReadValue(UINT32_T* pUINT32_ReadValue)
{
    INT32_T INT32_RawReadValue = 0;
    
    ERROR_T E_Value = E_NULL;

    E_Value = YL38_CheckNullpointer(pUINT32_ReadValue);

    INT32_RawReadValue = analogRead(_BYTE_ArduinoAnalogPort);
    INT32_RawReadValue = constrain(INT32_RawReadValue, YL38_RAW_ANALOGREAD_LOW, YL38_RAW_ANALOGREAD_HIGH);
    
    ERROR_Check(E_Value, YL38_Map(INT32_RawReadValue,YL38_RAW_ANALOGREAD_LOW, YL38_RAW_ANALOGREAD_HIGH, _BYTE_RemapHigh, _BYTE_RemapLow, pUINT32_ReadValue));
    
    return E_Value;

    
}


ERROR_T YL38_Map(INT32_T INT32_Value, INT32_T INT32_InMin, INT32_T INT32_InMax, INT32_T INT32_OutMin, INT32_T INT32_OutMax, INT32_T* INT32_MappedValue) {
  
  *INT32_MappedValue =  (INT32_Value - INT32_InMin) * (INT32_OutMax - INT32_OutMin) / (INT32_InMax - INT32_InMin) + INT32_OutMin;
  return E_OK;
}