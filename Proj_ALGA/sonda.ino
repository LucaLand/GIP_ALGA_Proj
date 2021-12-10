#include <DS18B20.h>

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS A1 // Pin Arduino a cui colleghiamo il pin DQ del sensore

const int sogliaTempMin = 27; // Accende il LED su scheda se si superano i 25°C

OneWire oneWire(ONE_WIRE_BUS); // Imposta la connessione OneWire

DallasTemperature sensore(&oneWire); // Dichiarazione dell'oggetto sensore

void setupSonda(void)
{
  sensore.begin();          // Inizializzazione del sensore
  //pinMode(pinLed, OUTPUT);  // pinLed definito come OUTPUT

  // Stampa del messaggio di avvio
  Serial.println("Temperatura rilevata dal sensore DS18B20");
  Serial.println("----------------------------------------");
}

int sondaTemp()
{
  sensore.requestTemperatures(); // richiesta lettura temperatura
  // Restituzione della temperatura letta
  // in gradi Celsius

  // temperatura in Celsius
  float celsius = sensore.getTempCByIndex(0);
  
  // Visualizzazione delle letture 
  // della temperatura sulla Serial monitor
  
  Serial.print("TEMPERATURA SONDA : ");
  Serial.print(celsius);
  Serial.println("C°");

  // se la temperatura è oltre la soglia
  // viene accesso il LED su scheda
  // altrimenti rimane spento
  
  if (celsius < sogliaTempMin) {
    colore(255,0,0);
  } else {
    colore(0,255,0);
  }

  return celsius;
}
