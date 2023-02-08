#include <Wire.h>
#include "dht.h"
#include "lcd.h"

  // Composants connectes sur l'arduino
#define DHT_PIN 4
// leds pour le control de la temperature
#define RED_LED_T 3
#define GREEN_LED_T 2
//AUTRES
#define BUZZER 6
#define RELAIS_RES 5

bool state_buz= true;
bool state_Led = true;

void setup() {
  lcd_tempe.init(); // initialisation de l'afficheur
  Wire.begin(); //initialisation de la voie i2c
  Serial.begin(9600);
  pinMode(RED_LED_T , OUTPUT);
  pinMode(GREEN_LED_T, OUTPUT);
  
  pinMode(BUZZER, OUTPUT);
  pinMode(RELAIS_RES , OUTPUT);
  digitalWrite(RELAIS_RES, LOW);
  
  lcd_tempe.backlight();
  // setup a time in 
  temp_lcd = millis();
  temp_RedLed = millis();
  temp_buzzer = millis();
 }

void loop() {
if((millis()- temp_lcd) >= 1000){
      readDHT( DHT_PIN, &tempe, &humidy ); // mise ajour de la temperature
      affichage();
      temp_lcd = millis();
 }
  control_temperature();
  control_leds();
  control_buzzer();
}


void control_temperature(){
  
  if(tempe <= 37.55){
   digitalWrite(RELAIS_RES, HIGH);
  }

  if(tempe > 37.8){
   digitalWrite(RELAIS_RES, LOW);
  }
}


void control_leds(){

  if((tempe > 36) && (tempe < 38.5)){
    digitalWrite(RED_LED_T, LOW);
    digitalWrite(GREEN_LED_T, HIGH);
  }

  else{
    digitalWrite(GREEN_LED_T, LOW);
    if((millis()- temp_RedLed) >= 1500){
      digitalWrite(RED_LED_T, state_Led);      
      temp_RedLed = millis();
      state_Led = !state_Led;
    }
  }
}

void control_buzzer(){
  if(tempe > 38.4 || tempe < 30){
    if((millis()-temp_buzzer) >= 1500){
      digitalWrite(BUZZER, state_buz);      
      temp_buzzer = millis();
      state_buz = !state_buz;
    }  }

  else{ 
      digitalWrite(BUZZER, LOW);
  }
}
