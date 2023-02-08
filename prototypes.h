#ifndef proto
#define proto
 
//QUELQUES VARIABLES GLOBALES DU PROGRAMME 
//variable pour la temperature et l'humidity
float tempe, humidy;
bool state_buz= false, state_redLed = false;
unsigned long temp_lcd, temp_RedLed, temp_buzzer;

//FONCTIONS POUR LA LECTURE DU CAPTEUR DHT22
byte readDHT(byte pin, float* temperature, float* humidity);

 //FONCTIONS POUR LE CONTROL DE tempe,humid,leds, etc...
void control_temperature();
void control_humidity();
void control_leds_T();
void control_buzzer();
void affichage();

#endif //prototype
