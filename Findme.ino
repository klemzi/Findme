/*
 *
     TEAM IOTRON 
  Findme Device Code 
    NaijaHacks 2019 
 * 
 */
#include "Adafruit_FONA.h"

// standard pins for the shield, adjust as necessary
#define FONA_RX 2
#define FONA_TX 3
#define FONA_RST 4

#define button 3

// We default to using software serial. If you want to use hardware serial
// (because softserial isnt supported) comment out the following three lines 
// and uncomment the HardwareSerial line
#include <SoftwareSerial.h>
SoftwareSerial fonaSS = SoftwareSerial(FONA_TX, FONA_RX);
SoftwareSerial *fonaSerial = &fonaSS;

// Hardware serial is also possible!
//  HardwareSerial *fonaSerial = &Serial1;

Adafruit_FONA fona = Adafruit_FONA(FONA_RST);

// Have a FONA 3G? use this object type instead
//Adafruit_FONA_3G fona = Adafruit_FONA_3G(FONA_RST);
String TriggerCase = "";
unsigned long intervals = 0;
float latitude, longitude;
void setup() {

  while (! Serial);
  pinMode(button, INPUT);
  Serial.begin(115200);
  Serial.println(F("Adafruit FONA 808 & 3G GPS demo"));
  Serial.println(F("Initializing FONA... (May take a few seconds)"));

  fonaSerial->begin(4800);
  if (! fona.begin(*fonaSerial)) {
    Serial.println(F("Couldn't find FONA"));
    while(1);
  }
  Serial.println(F("FONA is OK"));
  // Try to enable GPRS
  

  Serial.println(F("Enabling GPS..."));
 // fona.enableGPS(true);
}
bool debounce(int delayTime){
  if (digitalRead(button)){
    delay(delayTime);
    if (digitalRead(button))
      return true;
  }
  return false;
}

boolean FindmeLocation(){
   boolean con = false;
   boolean retry = false;
   if ((fona.type() == FONA3G_A) || (fona.type() == FONA3G_E))
    return;
    Serial.println(F("Checking for Cell network..."));
  top:
  if (fona.getNetworkStatus() == 1) {
    // network & GPRS? Great! Print out the GSM location to compare
    unsigned long previous = millis();
    while (millis() - previous < fixtime){
      boolean gsmloc_success = fona.getGSMLoc(&latitude, &longitude);
      if (gsmloc_success){
        con = true;
        break;
      }
    }
    // this disables the gprs connection, then reconnects then tries to get location
    // one last time
    if (!start && !con){
      Serial.println(F("Disabling GPRS"));
      fona.enableGPRS(false);
      Serial.println(F("Enabling GPRS"));
      if (!fona.enableGPRS(true))
        Serial.println(F("Failed to turn GPRS on"));
      start = true;
      goto top;
    }
    if (!con)
      return con;
   }
   fona.enableGPRS(false);
   return con;
}


void loop() {
  delay(2000);
  if 

}
