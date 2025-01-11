/*
  created 29 Dec. 2008
  by Tom Igoe
  modified  10 Jan. 2025
  by Yolie Reyes ID # 001234614


  The original example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInOutSerial
*/

const int Zin = A0;    // Analog input pin that the sensor is attached to
const int Zload = A1;  // Analog input pin that the sensor is attached to
const int iBatt = A2;  // Analog input pin that the sensor is attached to

void setup() {
  Serial.begin(9600); // Initialize serial communications at 9600 bps
}

void loop() {
  int sensorValueZin = analogRead(Zin);     // Read the sensor value from pin A0
  int sensorValueZload = analogRead(Zload); // Read the sensor value from pin A1
  int sensorValueiBatt = analogRead(iBatt); // Read the sensor value from pin A2
  
                                            // Send CSV formatted output to serial
  Serial.print(sensorValueZin);
  Serial.print(",");
  Serial.print(sensorValueZload);
  Serial.print(",");
  Serial.println(sensorValueiBatt);

                                            // wait 10 milliseconds before the next loop for the analog-to-digital
                                            // converter to settle after the last reading:
  delay(10);                                // WE NEED 100 [Hz] sampling frequency, which is five times the Nyquist rate for the 10 [Hz] signal! 
                                            // 1 [ms] = 1000 [Hz] & 10 [ms] = 100 [Hz]
}