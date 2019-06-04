
#include "morse.h"

//SPA: Se declara el String que se quiere traducir, el pin del led and el pin del altavoz.
//EN: We declare the String that we want to translate, the LED pin number and the speaker pin number.
//String str1 = "HOLA MUNDO";
String str2 = "HELLO WORLD";
int pinLed = 13;
int pinSpkr = 8; 

void setup() 
{
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, LOW);
  Serial.begin(9600);
}

void loop() 
{
  //SPA: Esta funcion de morse.h necesita la cadena de carácteres y el pin del led. Se reproduce el mensaje cada 5 segundos.
  //EN: This function needs the name of the character string and the led pin. The message in morse displays every 5 seconds.
  morseTraductor(str2, pinLed, pinSpkr); 
  delay(5000);
}
