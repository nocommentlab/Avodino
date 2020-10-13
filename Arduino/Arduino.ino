#include "src/STD_Lib/TYPE/TYPE_Def.h"
#include "src/Drivers/YL38/YL38_Ext.h"


ERROR_T E_Value = E_NULL;

// https://stackoverflow.com/questions/54334295/error-undefined-reference-when-a-library-is-included-to-arduino-code-from-direct
void setup() {

  
  Serial.begin(9600);

  // Init the YL38 Hygrometer Sensor
  E_Value = YL38_InitDriver((BYTE_T)A0, 0, 100);
  
}

void loop() {

  UINT32_T UINT32_YL38ReadValue = 0;

  ERROR_Check(E_Value, YL38_ReadValue(&UINT32_YL38ReadValue));
  
  Serial.print(UINT32_YL38ReadValue);

  delay(1000);

}
