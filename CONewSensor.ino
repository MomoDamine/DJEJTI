int gas_sensor = A0; //Sensor pin
float R0 = 14.7; //Sensor Resistance in fresh air from previous code


void setup() {
  Serial.begin(9600); //Baud rate

}

void loop() {
  float sensor_volt; //Define variable for sensor voltage
  float RS_gas; //Define variable for sensor resistance
  float ratio; //Define variable for ratio
  float sensorValue = analogRead(gas_sensor); //Read analog values of sensor
  sensor_volt = sensorValue * (5.0 / 1023.0); //Convert analog values to voltage
  RS_gas = ((5.0 * 10.0) / sensor_volt) - 10.0; //Get value of RS in a gas
  ratio = RS_gas / R0; // Get ratio RS_gas/RS_air

  double powe = pow(ratio, -4.0241);
  double ppm = 662.9382 * powe;
  Serial.print("ratio = ");
  Serial.println(ratio);
  Serial.print("CO = ");
  Serial.println(ppm);

  delay(500);
}

