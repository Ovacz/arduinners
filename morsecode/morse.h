/* SPA: Traduccion del alfabeto en morse. El punto 92ms, la raya 276
   el espacio entre elementos de la misma letra equivale a un
   punto. El espacio entre letras equivale a tres puntos. El
   espacio entre palabras equivale a 5 puntos. Lo haremos igual
   a 4 puntos (368ms), ya que después de cada carácter metemos 92ms.
   Tiempos para una transmision de W = 13wpm (palabras por minuto), basándonos en
   una palabra de 50 puntos (PARIS) por lo que T = 1200/W.
   

   EN: Translation of the alphabet into morse. Point 92ms, line 276
   the space between elements of the same letter equals a
   point. The space between letters equals three points. The
   Space between words equals 5 points. (We will do equal to
   4 points (368ms), because after each character we add 92ms.
   The time is for a trasmision of W = 13wpm (words per minute), based on
   a word of 50 dots (PARIS), so T = 1200/W.

   Wikipedia article: https://en.wikipedia.org/wiki/Morse_code
*/

//SPA: Se define un String con el abecedario, iniciando por el carácter un espacio.
//EN: We define a String with te alphabet, starting with a space character.

const String abc = " ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

//SPA: Se declara ahora un array de dimensión 1x37 de arrays de tipo entero con dimension 1x5.
//En definitiva una "matriz" de enteros de dimension 37x5. Donde cada entero representa una raya,
//un punto, o es un 0 para completar las dimensiones requeridas.
//EN: We declare now an array with 1x37 dimension of int type arrays with 1x5 dimension.
//So we declare a 37x5 dimension matrix of integers. Where each integer represents a dot or a dash,
//filling the array with 0s if it is required.

const int mabc[][5] = {{368,0,0,0,0}, {92,276,0,0,0}, {276,92,92,92,0}, {276,92,276,92,0}, {276,92,92,0,0},\
{92}, {92,92,276,92,0}, {276,276,92,0,0}, {92,92,92,92,0},{92,92,0,0,0}, {92,276,276,276,0}, {276,92,276,0,0},\
{92,276,92,92,0}, {276,276,0,0,0}, {276,92,0,0,0}, {276,276,276,0,0}, {92,276,276,92,0}, {276,276,92,276,0},\
{92,276,92,0,0}, {92,92,92,0,0}, {276,0,0,0,0}, {92,92,276,0,0}, {92,92,92,276,0}, {92,276,276,0,0}, {276,92,92,276,0},\
{276,92,276,276}, {276,276,92,92}, {92,276,276,276,276}, {92,92,276,276,276}, {92,92,92,276,276}, {92,92,92,92,276},\
{92,92,92,92,92}, {276,92,92,92,92}, {276,276,92,92,92}, {276,276,276,92,92}, {276,276,276,276,92}, {276,276,276,276,276}};

//SPA: Se genera ahora la función morsetraductor, que recorrerá la matriz y se encargará de encender
//y apagar el LED. También se muestran los caracteres traducidos por el monitor para debuguear.
//EN: We generate now the morsetraductor function, this will travel through the array and change the
//LED status according to the values. The translated characters are displayed on the monitor for debugging.
void morseTraductor(String str, int led, int speaker)
{
  int hightime = 0;
  int strlength = str.length();
  for (int i = 0; i < strlength; i++)
  {
    char c = str.charAt(i);
    Serial.print(" c = "); Serial.print(c); Serial.print(" => ");
    int j = abc.indexOf(c);
    for (int k = 0; k < 5; k++)
    {
      hightime = mabc[j][k];
      if (hightime == 0)
      {
        break;
      }
      else
      {
        Serial.print(mabc[j][k]); Serial.print(" ");
        digitalWrite(led, HIGH); tone(speaker, 500, hightime);
        delay (hightime); 
        digitalWrite(led, LOW);
        delay (92);
      }
    }
    delay(276);
    Serial.println();
  }
}
