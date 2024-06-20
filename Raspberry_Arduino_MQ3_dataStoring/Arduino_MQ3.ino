void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read sensor data
  int sensorValue = analogRead(A0);
  float voltage = (sensorValue*5)1023;

  // Send data over serial
  Serial.println(voltage);

  // Wait a bit before sending the next data
  delay(1000);
}