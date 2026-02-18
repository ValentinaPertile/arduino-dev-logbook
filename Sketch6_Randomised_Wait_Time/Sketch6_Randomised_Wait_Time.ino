int LED1 = 12;
int greenLED = 11;
int yellowLED = 10;
int redLED = 9;
int LED2 = 8;

int buzzer = 7;

int button1 = 3;
int button2 = 2;

bool buttonPressed = 0;


void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(LED2, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  randomSeed(analogRead(A0)); //since A0 is not connected to anything, it is "floating" and gives a random number
}

void loop() {

  digitalWrite(greenLED, 1);
  digitalWrite(buzzer, 1);
  delay(100);
  digitalWrite(buzzer, 0);
  delay(900);
  digitalWrite(greenLED, 0);

  digitalWrite(yellowLED, 1);
  digitalWrite(buzzer, 1);
  delay(100);
  digitalWrite(buzzer, 0);
  delay(900);
  digitalWrite(yellowLED, 0);

  digitalWrite(redLED, 1);
  digitalWrite(buzzer, 1);
  delay(100);
  digitalWrite(buzzer, 0);

  //false start
  long waitTime = random(900,4001);
  long startTime = millis();

  while (millis() - startTime < waitTime) {
    if (digitalRead(button1) == 0){
      falseStart(1);
      return;
    }

    if (digitalRead(button2) == 0){
      falseStart(2);
      return;
    }
  }

  digitalWrite(redLED, 0);


  //main game
  while(buttonPressed == 0){

    digitalWrite(LED1, 1);
    digitalWrite(LED2, 1);
    if (digitalRead(button1) == 0) {
      buttonPressed = 1;
      digitalWrite(LED2, 0);
    } else if (digitalRead(button2) == 0) {
      buttonPressed = 1;
      digitalWrite(LED1, 0);
    }
  }

  digitalWrite(buzzer, 1);
  delay(500);
  digitalWrite(buzzer, 0);
  delay(1500);
  digitalWrite(LED1, 0);
  digitalWrite(LED2, 0);
  buttonPressed = 0;
}


//False start function
void falseStart(int player){

  if (player == 1){
    for(int i=0; i<3; i++){
      digitalWrite(LED1, 1);
      digitalWrite(buzzer, 1);
      delay(100);

      digitalWrite(buzzer,0);
      digitalWrite(LED1, 0);
      delay(100);
    }
    digitalWrite(LED2, 1); // gana jugador 2
    digitalWrite(buzzer, 1);
    delay(500);
    digitalWrite(buzzer, 0);
    delay(1500);
  }

  if (player == 2){
    for(int i=0; i<3; i++){
      digitalWrite(LED2, 1);
      digitalWrite(buzzer, 1);
      delay(100);

      digitalWrite(buzzer,0);
      digitalWrite(LED2, 0);
      delay(100);
    }
    digitalWrite(LED1, 1);
    digitalWrite(buzzer, 1);
    delay(500);
    digitalWrite(buzzer, 0);
    delay(1500);
  }

  delay(1500);

  digitalWrite(LED1, 0);
  digitalWrite(LED2, 0);

  digitalWrite(redLED, 0);


}



