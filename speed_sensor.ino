// Pin connected to the speed sensor output
const int sensorPin = 3;
volatile int pulseCount = 0;

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  
  // Attach an interrupt to the sensor pin
  attachInterrupt(digitalPinToInterrupt(sensorPin), countPulse, RISING);
}

void loop() {
  // Disable interrupts to safely read pulseCount
  noInterrupts();
  int pulses = pulseCount;
  pulseCount = 0; // Reset pulse count after reading
  interrupts();
  
  // Print the pulse count
  Serial.println(pulses);
  
  // Example delay, adjust based on your specific needs
  delay(1000);
}

void countPulse() {
  pulseCount++;
}
