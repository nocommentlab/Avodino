#ifndef _TYPE_DEF_H
#define _TYPE_DEF_H

#ifndef _CHAR_T
   typedef char                  CHAR_T; 
#define _CHAR_T   
#endif

#ifndef _BYTE_T
   typedef unsigned char         BYTE_T; 
#define _BYTE_T   
#endif

#ifndef _INT32_T
   typedef signed long          INT32_T; 
#define _INT32_T   
#endif

#ifndef _UINT32_T
   typedef unsigned long       UINT32_T; 
#define _UINT32_T   
#endif

#ifndef _ERROR_T
   typedef unsigned long       ERROR_T; 
#define _ERROR_T
#endif

#ifndef NULL
   #define NULL (0) 
#endif

#ifndef E_NULL
   #define E_NULL                                    (ERROR_T)   -1 
#endif
#ifndef E_OK
   #define E_OK                                      (ERROR_T) 0x00 
#endif

#define ERROR_Check(ERROR_Value, ERROR_Function)if ((ERROR_Value) == E_OK){ (ERROR_Value) = (ERROR_Function);}

#endif