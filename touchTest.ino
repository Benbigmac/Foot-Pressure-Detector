/* FSR testing sketch. 
 
Connect one end of FSR to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground
Connect LED from pin 11 through a resistor to ground 
 
For more information see www.ladyada.net/learn/sensors/fsr.html */
 
int fsrAnalogPin = 0; // FSR is connected to analog 0
int fsrAnalogPin1 = 1; // FSR is connected to analog 0
int fsrAnalogPin2 = 2; // FSR is connected to analog 0
int fsrAnalogPin3 = 3; // FSR is connected to analog 0
int LEDpin = 10;      // connect green LED to pin 11 (PWM pin)
int LEDpin1 = 11;      // connect Red LED to pin 11 (PWM pin)
int LEDpin2 = 12;      // connect Blue LED to pin 11 (PWM pin)
int LEDpin3 = 13;      // connect Yellow LED to pin 11 (PWM pin)
int fsrReading0;      // the analog reading from the FSR resistor 
int fsrReading1;  
int fsrReading2;  
int fsrReading3;  
int LEDbrightness0;
int LEDbrightness1;
int LEDbrightness2;
int LEDbrightness3;
 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(LEDpin, OUTPUT);
  pinMode(LEDpin1, OUTPUT);
  pinMode(LEDpin2, OUTPUT);
  pinMode(LEDpin3, OUTPUT);
  Serial.println("Now this looks like a job for me");
  Serial.println("| Input 1 | Input 2 | Input 3 | Input 4 |");
}
 
void loop(void) {
  fsrReading0 = analogRead(fsrAnalogPin);
  fsrReading1 = analogRead(fsrAnalogPin1);
  fsrReading2 = analogRead(fsrAnalogPin2);
  fsrReading3 = analogRead(fsrAnalogPin3);
 // Serial.print("Analog reading = ");
  Serial.print("| ");
  Serial.print(fsrReading0);
  Serial.print( " | ");
  Serial.print(fsrReading1);
   Serial.print(" | ");
   Serial.print(fsrReading2);
   Serial.print(" | ");
   Serial.print(fsrReading3);
   Serial.println(" |");
 // Serial.println(fsrReading0);
 
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!
  LEDbrightness0 = map(fsrReading0, 0, 1023, 0, 255);
  LEDbrightness1 = map(fsrReading1, 0, 1023, 0, 255);
  LEDbrightness2 = map(fsrReading2, 0, 1023, 0, 255);
  LEDbrightness3 = map(fsrReading3, 0, 1023, 0, 255);
  // LED gets brighter the harder you press
  analogWrite(LEDpin, LEDbrightness0);
  analogWrite(LEDpin1, LEDbrightness1);
  analogWrite(LEDpin2, LEDbrightness2);
  analogWrite(LEDpin3, LEDbrightness3);
 
  delay(100);
}
