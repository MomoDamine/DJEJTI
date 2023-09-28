#include <dht.h>
dht DHT;
#define DHT11_PIN 7

double Temp ;
double Humd ;
int chk ;
void setup(){
  Serial.begin(9600);
}

void loop()
{
  
  chk = DHT.read11(DHT11_PIN);
  Temp = DHT.temperature ;
  Humd = DHT.humidity ; 
 
  if(Temp>15 & Temp <60)
  {
  Serial.print("Temperature = ");
  Serial.println(Temp);
  }
  if(Humd<100)
  {
  Serial.print("Humidity = ");
  Serial.println(Humd);
  }
  
}

