#include "MQ135.h"
#define RZERO 390.2    //  Define RZERO Calibration Value
int gas_sensor = A0; //Sensor pin
MQ135 gasSensor = MQ135(gas_sensor);
String Data = "";
float m = -0.263; //Slope
float b = 0.42; //Y-Intercept
float R0NH3 = 11.72; //Sensor Resistance in fresh air from previous code
float sensor_voltNh3Co2; //Define variable for sensor voltage
float RS_gasNh3Co2; //Define variable for sensor resistance
float ratioNh3Co2; //Define variable for ratio
float sensorValueNh3Co2;
double ppm_logNh3Co2;
double NH3ppm ;
float ppmCO2;
double percentage;
float R0Co = 14.7; //Sensor Resistance in fresh air from previous code
float sensor_voltCo; //Define variable for sensor voltage
float RS_gasCo; //Define variable for sensor resistance
float ratioCo; //Define variable for ratio
float sensorValueCo;
double poweCo;
double ppmCo;

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
  pinMode(gas_sensor, INPUT); //Set gas sensor as input
}

void loop() {
  Data = "";

  sensorValueNh3Co2 = analogRead(gas_sensor);
  sensor_voltNh3Co2 = sensorValueNh3Co2 * (5.0 / 1023.0);
  RS_gasNh3Co2 = ((5.0 * 10.0) / sensor_voltNh3Co2) - 10.0;
  ratioNh3Co2 = RS_gasNh3Co2 / R0NH3;

  ppm_logNh3Co2 = (log10(ratioNh3Co2) - b) / m;
  NH3ppm = pow(10, ppm_logNh3Co2);
  percentage = NH3ppm / 1000; //Conversion en percentage
  ppmCO2 = gasSensor.getPPM();


  sensorValueCo = analogRead(gas_sensor); //Read analog values of sensor
  sensor_voltCo = sensorValueCo * (5.0 / 1023.0); //Convert analog values to voltage
  RS_gasCo = ((5.0 * 10.0) / sensor_voltCo) - 10.0; //Get value of RS in a gas
  ratioCo = RS_gasCo / R0Co; // Get ratio RS_gas/RS_air

  poweCo = pow(ratioCo, -4.0241);
  ppmCo = 662.9382 * poweCo;


  Data = Data + "#";
  Data = Data + NH3ppm;
  Data = Data + "#";
  Data = Data + ppmCO2;
  Data = Data + "#";
  Data = Data + ppmCo;
  Data = Data + "#";


  Serial.println(Data); //Write the serial data
  delay(100);

}
