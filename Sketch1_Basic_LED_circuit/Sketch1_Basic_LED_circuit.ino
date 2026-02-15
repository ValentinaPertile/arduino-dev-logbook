/*
The system utilizes a digital output pin to send a 5V signal, which is regulated by a 220Ω resistor 
(identified by its Red-Red-Black-Black bands) to ensure the current stays within the safe operating limit 
of 20mA for the red LED.
*/

void setup()
{
  pinMode(11, OUTPUT); //Led output
}

void loop()
{
  digitalWrite(11, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(11, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}