// Variable to store the potentiometer value
int sensorValue;

void setup() {
  // Initialize serial communication at 9600 bps
  Serial.begin(9600);
  
  // Print a startup message to the serial monitor
  Serial.println("Sketch started - Reading potentiometer values");
}

void loop() {
  // Read the input on analog pin 0
  sensorValue = analogRead(A0);

  // Print the value to the serial monitor
  Serial.print("Current value = ");
  Serial.println(sensorValue);
  
  // Wait for 1 second before the next reading
  delay(1000);
}
