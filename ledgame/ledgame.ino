int Led1Pin = 11; //The pin of the first LED.
int Led2Pin = 10; //The pin of the second LED.
int Led3Pin = 9; //etc.
int Led4Pin = 8;
int Led5Pin = 4;

int Button = 2; //The pin of the button.

unsigned long timestep;
unsigned long starttime;
unsigned long nowtime;

int Level = 1;

void setup() {
  pinMode(Led1Pin, OUTPUT);
  pinMode(Led2Pin, OUTPUT); // Yellow
  pinMode(Led3Pin, OUTPUT); //Green
  pinMode(Led4Pin, OUTPUT); //Yellow
  pinMode(Led5Pin, OUTPUT);
  pinMode(Button, INPUT);

  digitalWrite(Led1Pin, HIGH);
  digitalWrite(Led2Pin, HIGH);
  digitalWrite(Led3Pin, HIGH);
  digitalWrite(Led4Pin, HIGH);
  digitalWrite(Led5Pin, HIGH);
  delay(2000);
  digitalWrite(Led1Pin, LOW);
  digitalWrite(Led2Pin, LOW);
  digitalWrite(Led3Pin, LOW);
  digitalWrite(Led4Pin, LOW);
  digitalWrite(Led5Pin, LOW);
  starttime = millis();
}

void loop() {

  int ButtonState;
  ButtonState = digitalRead(Button);
  timestep = 2000/Level;
  nowtime = millis();

    if ((nowtime-starttime < timestep*1) && (nowtime-starttime >= timestep*0)){
    
      digitalWrite(Led1Pin, HIGH);
      digitalWrite(Led2Pin, LOW);
      digitalWrite(Led3Pin, LOW);
      digitalWrite(Led4Pin, LOW);
      digitalWrite(Led5Pin, LOW);

        if (ButtonState == LOW){
        Level = 1;
        delay(250);
        starttime = millis(); //Resets game to level 1 if red LED is hit.
      }
    }

    else if ((nowtime-starttime < timestep*2) && (nowtime-starttime >= timestep*1)){

      digitalWrite(Led1Pin, LOW);
      digitalWrite(Led2Pin, HIGH);
      digitalWrite(Led3Pin, LOW);
      digitalWrite(Led4Pin, LOW);
      digitalWrite(Led5Pin, LOW);

      if (ButtonState == LOW){
        delay(250);
        starttime = millis(); //Resets the game at the same level when a yellow LED is hit.
      }
    }

    else if ((nowtime-starttime  < timestep*3) && (nowtime-starttime >= timestep*2)){

      digitalWrite(Led1Pin, LOW);
      digitalWrite(Led2Pin, LOW);
      digitalWrite(Led3Pin, HIGH);
      digitalWrite(Led4Pin, LOW);
      digitalWrite(Led5Pin, LOW);

      if (ButtonState == LOW){
        Level = Level + 1;
        delay(250);
        starttime = millis(); //Starts a new level when green LED is hit.
          
          if (Level == 10) {

            delay(250);
            digitalWrite(Led1Pin, LOW);
            digitalWrite(Led2Pin, HIGH);
            digitalWrite(Led3Pin, LOW);
            digitalWrite(Led4Pin, HIGH);
            digitalWrite(Led5Pin, LOW);
          }
      }
  }

    else if((nowtime-starttime < timestep*4) && (nowtime-starttime >= timestep*3)){

      digitalWrite(Led1Pin, LOW);
      digitalWrite(Led2Pin, LOW);
      digitalWrite(Led3Pin, LOW);
      digitalWrite(Led4Pin, HIGH);
      digitalWrite(Led5Pin, LOW);

      if (ButtonState == LOW){
        delay(250);
        starttime = millis(); //Resets the game at the same level when a yellow LED is hit.
      }
  }

    else if ((nowtime-starttime < timestep*5) && (nowtime-starttime >= timestep*4)){

      digitalWrite(Led1Pin, LOW);
      digitalWrite(Led2Pin, LOW);
      digitalWrite(Led3Pin, LOW);
      digitalWrite(Led4Pin, LOW);
      digitalWrite(Led5Pin, HIGH);

      if (ButtonState == LOW){
        Level = 1;
        delay(250);
        starttime = millis(); //Resets game to level 1 if red LED is hit.
      }
  }

  else if ((nowtime-starttime < timestep*6) && (nowtime-starttime >= timestep*5)){

      digitalWrite(Led1Pin, LOW);
      digitalWrite(Led2Pin, LOW);
      digitalWrite(Led3Pin, LOW);
      digitalWrite(Led4Pin, HIGH);
      digitalWrite(Led5Pin, LOW);

      if (ButtonState == LOW){
        delay(250);
        starttime = millis(); //Resets the game at the same level when a yellow LED is hit.
      }
  }

  else if ((nowtime-starttime < timestep*7) && (nowtime-starttime >= timestep*6)){

      digitalWrite(Led1Pin, LOW);
      digitalWrite(Led2Pin, LOW);
      digitalWrite(Led3Pin, HIGH);
      digitalWrite(Led4Pin, LOW);
      digitalWrite(Led5Pin, LOW);

        if (ButtonState == LOW){
          Level = Level + 1;
          delay(250);
          starttime = millis(); //Starts a new level when green LED is hit.

          if (Level == 10) {

            delay(250);
            digitalWrite(Led1Pin, LOW);
            digitalWrite(Led2Pin, HIGH);
            digitalWrite(Led3Pin, LOW);
            digitalWrite(Led4Pin, HIGH);
            digitalWrite(Led5Pin, LOW);
          }
        }
  }

  else if ((nowtime-starttime < timestep*8) && (nowtime-starttime >= timestep*7)){

     digitalWrite(Led1Pin, LOW);
     digitalWrite(Led2Pin, HIGH);
     digitalWrite(Led3Pin, LOW);
     digitalWrite(Led4Pin, LOW);
     digitalWrite(Led5Pin, LOW);

        if (ButtonState == LOW){
          delay(250);
          starttime = millis(); //Resets the game at the same level when a yellow LED is hit.
        }
  }

  else if ((nowtime-starttime < timestep*9) && (nowtime-starttime >= timestep*8)){

     digitalWrite(Led1Pin, HIGH);
     digitalWrite(Led2Pin, LOW);
     digitalWrite(Led3Pin, LOW);
     digitalWrite(Led4Pin, LOW);
     digitalWrite(Led5Pin, LOW);

        if (ButtonState == LOW){
          Level = 1;
          delay(250);
          starttime = millis(); //Resets game to level 1 if red LED is hit.
        }
  }

  else if (nowtime-starttime >= timestep*9){
    starttime = millis();
  }
}
