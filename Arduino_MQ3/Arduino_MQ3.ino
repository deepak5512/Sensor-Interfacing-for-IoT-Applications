#define SENSOR_ANALOG_PIN A0 // Analog pin connected to MQ-3 sensor

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  float sensorValue = analogRead(SENSOR_ANALOG_PIN); // Read sensor value
  float voltage = sensorValue * (5.0 / 1023.0); // Convert sensor value to voltage (assuming 5V Arduino)
  
  Serial.print("Voltage:");
  Serial.println(voltage);
  
  delay(1000); // Delay for stability
}