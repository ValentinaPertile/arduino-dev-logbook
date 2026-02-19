int LED1 = 12;
int greenLED = 11;
int yellowLED = 10;
int redLED = 9;
int LED2 = 8;

int buzzer = 7;

int button1 = 3;
int button2 = 2;

// Game variables
int score1 = 0;
int score2 = 0;

bool roundFinished = false;

// Function prototypes
bool startSequence();
void waitForReaction();
void announceWinner(int player, unsigned long reactionTime);
void falseStart(int player);

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(LED2, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  Serial.begin(9600);

  randomSeed(analogRead(A0));
}

void loop() {

  // Check if someone won best of five
  if (score1 == 3 || score2 == 3) {

    if (score1 == 3) {
      Serial.println("PLAYER 1 WINS BEST OF FIVE");
    } else {
      Serial.println("PLAYER 2 WINS BEST OF FIVE");
    }

    Serial.println("---------------------------");
    delay(3000);

    score1 = 0;
    score2 = 0;
  }

  if (startSequence()) {
    waitForReaction();
  }
}

// -------------------- Start Sequence --------------------

bool startSequence() {

  digitalWrite(greenLED, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(900);
  digitalWrite(greenLED, LOW);

  digitalWrite(yellowLED, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(900);
  digitalWrite(yellowLED, LOW);

  digitalWrite(redLED, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);

  long waitTime = random(900, 4001);
  unsigned long startTime = millis();

  while (millis() - startTime < waitTime) {

    if (digitalRead(button1) == LOW) {
      score2++;              // Player 2 wins immediately
      falseStart(1);
      announceWinner(2, 0);
      return false;
    }

    if (digitalRead(button2) == LOW) {
      score1++;              // Player 1 wins immediately
      falseStart(2);
      announceWinner(1, 0);
      return false;
    }
  }

  digitalWrite(redLED, LOW);
  return true;
}

// -------------------- Main Game --------------------

void waitForReaction() {

  roundFinished = false;

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);

  unsigned long reactionStart = millis();

  while (!roundFinished) {

    if (digitalRead(button1) == LOW) {

      unsigned long reactionTime = millis() - reactionStart;
      score1++;
      roundFinished = true;

      digitalWrite(LED2, LOW);
      announceWinner(1, reactionTime);
    }

    else if (digitalRead(button2) == LOW) {

      unsigned long reactionTime = millis() - reactionStart;
      score2++;
      roundFinished = true;

      digitalWrite(LED1, LOW);
      announceWinner(2, reactionTime);
    }
  }

  delay(1500);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
}

// -------------------- Announce Winner --------------------

void announceWinner(int player, unsigned long reactionTime) {

  tone(buzzer, 2000, 300);

  Serial.print("PLAYER ");
  Serial.print(player);
  Serial.println(" WINS THE ROUND");

  if (reactionTime > 0) {
    Serial.print("Reaction time: ");
    Serial.print(reactionTime);
    Serial.println(" ms");
  } else {
    Serial.println("Win by opponent false start");
  }

  Serial.print("Score -> P1: ");
  Serial.print(score1);
  Serial.print(" | P2: ");
  Serial.println(score2);

  Serial.println("---------------------------");
}

// -------------------- False Start --------------------

void falseStart(int player){

  if (player == 1){
    for(int i=0; i<3; i++){
      digitalWrite(LED1, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(100);

      digitalWrite(buzzer,LOW);
      digitalWrite(LED1, LOW);
      delay(100);
    }
    digitalWrite(LED2, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(1500);
  }

  if (player == 2){
    for(int i=0; i<3; i++){
      digitalWrite(LED2, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(100);

      digitalWrite(buzzer,LOW);
      digitalWrite(LED2, LOW);
      delay(100);
    }
    digitalWrite(LED1, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(1500);
  }

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(redLED, LOW);
}
