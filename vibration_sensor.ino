// Pin connected to the vibration sensor output
const int sensorPin = 2;

void setup() {
  // Initialize the sensor pin as an input
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(sensorPin);
  
  // Print the sensor value to the serial monitor
  Serial.println(sensorValue);
  
  // Short delay between readings
  delay(100);
}
