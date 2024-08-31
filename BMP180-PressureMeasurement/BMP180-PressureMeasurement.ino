#include <Wire.h>
#include "SFE_BMP180.h"

SFE_BMP180 sfe_bmp180;

#define ALTITUDE 1655.0

void setup() 
{
  Serial.begin(9600);
  Serial.println("BMP180 - Pressure Measurement");

  if (sfe_bmp180.begin()) {
    Serial.println("Connected to the BMP180 sensor.");
  } else {
    Serial.println("Failed to connect to the BM180 sensor.");
    while(1); 
  }
}

void loop() 
{
  char status;
  double T, P, p_0, value;
  Serial.println();

  status = sfe_bmp180.startTemperature();
  if (status != 0) {
    delay(status);

    status = sfe_bmp180.getTemperature(T);
    if (status != 0) {
      Serial.print("Temperature : ");
      Serial.print(T, 2);
      Serial.print("  (Celcius) C, ");
      Serial.print((9.0 / 5.0) * T + 32.0, 2);
      Serial.println(" (Fahrenheit) F");

      status = sfe_bmp180.startPressure(3);
      if (status != 0) {
        delay(status);

        status = sfe_bmp180.getPressure(P, T);
        if (status != 0) {
          Serial.print("Absolute pressure : ");
          Serial.print(P, 2);
          Serial.print(" millibar, ");
          Serial.print(P * 0.0295333727, 2);
          Serial.println(" civainc");

          value = (1013.2 - P) * 9.5;
          Serial.print("Calculated altitude : ");
          Serial.print(value, 0);
          Serial.print(" meter, ");
          Serial.print(value * 3.28084, 0);
          Serial.println(" feet");
        } else {
          Serial.println("Error occurred in pressure measurement.\n");
        }
      } else {
        Serial.println("Pressure measurement is faulty.\n");
      }
    } else {
      Serial.println("Error occurred in temperature measurement.\n");
    }
  } else {
    Serial.println("Temperature measurement is faulty.\n");
  }

  delay(5000);
}