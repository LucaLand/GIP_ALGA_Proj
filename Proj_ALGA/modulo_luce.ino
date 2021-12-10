

#define touchButtonPin A2
#define ledPin A5

// Variables
int ledState = LOW;
bool singleTouch = false, boolLedState = false;

//reset variables time
long int iTC = 0;
const int intervalReset = 4000;


void setupModLux() {
  pinMode(ledPin, OUTPUT);
  pinMode(touchButtonPin, INPUT);
  digitalWrite(ledPin, ledState);
}

bool modLux2() {
  if(digitalRead(touchButtonPin)== HIGH){ 
    if (!singleTouch){
      Serial.print("Touch!\n");      
      iTC = millis();
      
      if (ledState == LOW) {
        ledState = HIGH;
        boolLedState = true;
        Serial.print("On\n");
      } else {
        ledState = LOW;
        boolLedState = false;
        Serial.print("Off\n");
      }
      // set the LED with the ledState of the variable:
      singleTouch = true;
      digitalWrite(ledPin, ledState);
    }else{
      long int nowIstant, interval;
      nowIstant = millis();
      if(nowIstant - iTC >= intervalReset){
        Reset();
      }
    }
  }else{
    singleTouch = false;
    iTC = 0;
  }
    return boolLedState;
}


/*void modLux() {
  // Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
//unsigned long previousMillis = 0;        // will store last time LED was updated
  
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  //unsigned long currentMillis = millis();
  //if(digitalRead(touchButtonPin)== HIGH){
    
    if (currentMillis - previousMillis >= interval) {
      // save the last time you blinked the LED
      previousMillis = currentMillis;
  
      // if the LED is off turn it on and vice-versa:
      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }
  
      // set the LED with the ledState of the variable:
      digitalWrite(ledPin, ledState);
    }
  }
}*/
