// Pin connected to the temperature sensor output
const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // Print the voltage
  Serial.println(voltage);
  
  delay(1000); // Delay a bit before reading again
}
