char mystr; //Initialized variable to store recieved data
String Data; 
void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
}

void loop() {
  mystr ="";
  Data = "" ;
  if (Serial.available()>0)
  {
  mystr = Serial.read(); //Read the serial data and store in var
  Data += mystr ;
  Data.trim();
  }
  Serial.print(Data);
  
  
  
  
}
