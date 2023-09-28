/*
  Library Repository : https://github.com/ckalpha/MQ135
  Author : Damrongwit Nusuk
  Email : jack@racksync.com
  Website : http://www.racksync.com
*/

#include "MQ135.h"
#define ANALOGPIN A0    //  Define Analog PIN on Arduino Board
#define RZERO 390.2    //  Define RZERO Calibration Value
MQ135 gasSensor = MQ135(ANALOGPIN);

void setup()
{
  Serial.begin(9600);

}

void loop() {


  float ppm = gasSensor.getPPM();
  Serial.print("CO2 ppm value : ");
  Serial.println(ppm);
  delay(500);
}
