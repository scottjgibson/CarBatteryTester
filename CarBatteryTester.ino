
//Pin A0 - Current reading (across 0.1 ohm resistor)
//Pin A1 - Battery Voltage (use a 1/4 voltage divider)


void setup() {
  Serial.begin(9600);
  
  //Pin 13 is connected to a relay coil (via an external fet)
  // it is used for disconnecting the battery should the voltage drop below 10.5V
  pinMode(13, OUTPUT); 
  
  //Energize the relay
  digitalWrite(13, HIGH);
}


void loop() {
  //Current in amps is 10 times the read value because I am using a 
  //0.1ohm resistor
  int current = analogRead(A0)*10;
  
  //Voltage is 4 times the read value due to the external resistor divider
  //measure your voltage divider and adjust as needed.
  int voltage = analogRead(A1)*4;


  Serial.print(current);
  Serial.print(",");
  Serial.println(voltage);
  
  if (voltage < 10.5)
  {
    digitalWrite(13, LOW);
  }
  
  delay(10);
}
