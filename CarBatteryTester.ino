//Pin A0 - Current reading (across 0.1 ohm resistor)
//Pin A1 - Battery Voltage 

//My divider is a 10k and 4.7k resitor;  4.7k / (10k+4.7k)
//The value hear was measured with the circuit hooked up for greater accuracy
#define DIVIDER_RATIO 4.5

//Current Sense Resistor value; I used a 0.1ohm resistor (what I had onhand)
// Make sure you wont exceed the maximum input voltage on the arduino (5V)
#define CS_RESISTOR_VALUE 0.1

void setup() {
  Serial.begin(9600);
  
  //Pin 13 is connected to a relay coil (via an external fet)
  // it is used for disconnecting the battery should the voltage drop below 10.5V
  pinMode(13, OUTPUT); 
  
  //Energize the relay
  digitalWrite(13, HIGH);
}


void loop() {
  //I = V/R
  //The map is needed because the ADC reads 0-1024 for the range 0-5V
  int current = map(analogRead(A0), 0, 1024, 0, 5) / RESISTOR_VALUE;
  
  //Voltage is 4 times the read value due to the external resistor divider
  //measure your voltage divider and adjust as needed.
  int voltage = analogRead(A1)*DIVIDER_RATIO;


  Serial.print(current);
  Serial.print(",");
  Serial.println(voltage);
  
  if (voltage < 10.5)
  {
    digitalWrite(13, LOW);
  }
  
  delay(10);
}
