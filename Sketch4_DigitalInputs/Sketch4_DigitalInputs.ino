/*
Digital Inputs: Operate with binary states (1 and 0).
  -High Input: Signal above 3V. (connecting the wire to 5V)
  -Low Input: Signal below 1.5V. (connecting the wire to GROUND)

Floating State: Occurs when a pin is not connected to a defined voltage, causing random fluctuations due to electrical noise.
*/

int inputPin = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(inputPin));
  delay(100);
}
