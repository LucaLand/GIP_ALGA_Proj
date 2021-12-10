int timerCount = 0, temp=0, timeLightMinutes=0, timeLightHours=0, timeLightSeconds=0;
bool enableMotor = false, luce = false, ledOn = false;
long int previusIstantLux = 0,previusIstant = 0, timeLux = 0;
const int intervalRead = 3000;

void setup()
{
    Serial.begin(9600);       // Inizializzazione della serial monitor
  // RGB
   setupRGB();
  // Modulo Luce
  setupModLux();
  //Modulo Sonda
  setupSonda();
  //Motor
  myMotorSetup();
  //LCD
  setupLCD();
}

void loop() {
  delay(10);

  //Touch e led
  ledOn = modLux2();
  
  long int nowIstant, interval;
  nowIstant = millis();
  if(nowIstant - previusIstant >= intervalRead){
    previusIstant = nowIstant;
    if(timerCount % 3000 == 0){
      Serial.println("Esecuzione ogni 3 secodi");
      temp = sondaTemp();
      if(illuminata() || ledOn)
        luce = true;
      else
        luce = false;
      }
  }
  
  //Motore
  if(enableMotor)
    stepMotor();
  
  //Contatore tempo luce
  tempoLuce();

  //LCD Schermo visualizzazione
  LCDPrintInfo(temp, timeLightHours, timeLightMinutes, timeLightSeconds);  
}


void tempoLuce(){
  
  long int nowIstant, interval;
  nowIstant = millis();
  interval = nowIstant - previusIstantLux;
  previusIstantLux = nowIstant;
  
  if(luce)
    timeLux = timeLux + interval;
    
  if((timeLux/1000) >= 1){
    timeLightSeconds = timeLightSeconds + timeLux/1000;
    timeLux = 0;
  }
  if(timeLightSeconds >= 60){
    timeLightMinutes++;
    timeLightSeconds = 0;
  }
  if(timeLightMinutes >= 60 && timeLightMinutes != 0){
    timeLightHours++;
    timeLightMinutes = 0;
  }

  /*
  Serial.print("\nTEMPO DI LUCE: ");
  Serial.print(timeLux);
  Serial.print("- h:");
  Serial.print(timeLightHours);
  Serial.print("- min:");
  Serial.print(timeLightMinutes);
  Serial.print("- sec:");
  Serial.println(timeLightSeconds);
  */
}


void(* resetFunc) (void) = 0;

void Reset(){
  LCDPrintReset();
  lampeggio();
  resetFunc();
}
