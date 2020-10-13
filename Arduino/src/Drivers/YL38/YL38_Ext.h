#ifndef _YL38_EXT_H
#define _YL38_EXT_H

#include "../../STD_Lib/TYPE/TYPE_Def.h"

#ifdef __cplusplus
extern "C" {
#endif

ERROR_T YL38_InitDriver(BYTE_T BYTE_ArduinoAnalogPort, 
                       BYTE_T BYTE_RemapLow,
                       BYTE_T BYTE_RemapHigh);

ERROR_T YL38_ReadValue(UINT32_T* pUINT32_ReadValue);


#ifdef __cplusplus
}
#endif


#endif


