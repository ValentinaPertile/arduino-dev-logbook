// Variable to store the potentiometer value
int potValue;

// LED pin definitions
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Print startup message to the serial monitor
  Serial.println("Sketch started - Potentiometer values");

  // Set LED pins as outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  // Read value from analog pin A0
  potValue = analogRead(A0);

  // Print value to the serial monitor
  Serial.print("The value is = ");
  Serial.println(potValue);

  // Logic to turn on LEDs based on the potentiometer range
  if (potValue >= 0 && potValue <= 255) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
  } 
  
  else if (potValue >= 256 && potValue <= 511) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
  }

  else if (potValue >= 512 && potValue <= 767) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
  }

  else if (potValue >= 768 && potValue <= 1023) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
   }
}