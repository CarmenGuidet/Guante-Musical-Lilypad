// Autora= Carmen Guidet Gomez
//Fecha de creacion = 04/08/2018
//Ultima modificacion = 05/08/2018
//Proyecto = Guante musical con LilyPad 
int pulgar =4; //el sensor de luz del pulgar esta en el pin 4
int indice =6; //el sensor de luz del indice esta en el pin 6
int corazon = 8; //el sensor de luz del corazon esta en el pin 8
int anular = 10; //el sensor de luz del anular esta en el pin 10
int menique = 11; //el sensor de luz del menique esta en el pin 11
int jack = 3;// los altavoces o el puerto jack esta en el pin 3

void setup(){
  //indicamos que los sensores son de salida
  
  pinMode(pulgar,INPUT);
  pinMode(indice,INPUT);
  pinMode(corazon,INPUT);
  pinMode(anular,INPUT);
  pinMode(menique,INPUT);
  
  //indicams que los altavoces o puerto jack son de salida
  pinMode(jack, OUTPUT);
}
void loop(){
  //Definimos resultado a 0
int resultado = 0; 
  //hacemos una nueva variable de la lectura digital de los sensores de los dedos 
int int_pulgar=digitalRead(pulgar);
int int_indice=digitalRead(indice);
int int_corazon=digitalRead(corazon);
int int_anular=digitalRead(anular);
int int_menique=digitalRead(menique);
  
  /**********************************
   * Ahora usaremos un algoritmo donde a cada dedo le definiremos una potencia de 10 
   * si no recibe el dedo luz, esto nos ayudara a la lectura de los dedos.
   * Esto nos deda 2^5 posibilidades es decir 32 posibilidades
   * Pero a fechas de hoy solo programare con la iteracion de dos dedos es decir 
   * 16 combinaciones posibles.
   * Estas combinacines las eligire con switch y case, donde cada concinacion sera una
   * nota musical.
   **********************************/

  if (int_menique == LOW)
    resultado += 1;
  if (int_anular == LOW)
    resultado += 10;
  if (int_corazon == LOW)
    resultado += 100;
  if (int_indice == LOW)
    resultado += 1000;
  if (int_pulgar == LOW)
    resultado += 10000;

  switch(resultado)
  {
    /*
     * Esta ordenado con forme a la escala musical 
     * Suponemos que el pulgar es Do
     */
    case 10000://el pulgar (P) es LOW
      tone(jack,262);//suena la nota C4(do)
      delay(1000); //espera un segundo es decir 1000ms
      noTone(3);//deja de sonar la nota
      break;
    case 1000://el indice (I) es LOW
      tone(jack,294);//suena la nota D4(re)
      delay(1000); 
      noTone(3);
      break;
    case 100://el corazon (C) es LOW
      tone(jack,330);//suena la nota E4(mi)
      delay(1000); 
      noTone(3);
      break;
    case 10://el anular (A) es LOW
      tone(jack,349);//suena la nota F4(fa)
      delay(1000); 
      noTone(3);
      break;
    case 1:// el menique( M) es LOW
      tone(jack,392);//suena la nota G4(sol)
      delay(1000); 
      noTone(3);
      break;
    case 11000: // P & I
      tone(jack,440);//suena la nota A4 (la)
      delay(1000); 
      noTone(3);
      break;
    case 10100: // C & P
      tone(jack,494);//suena la nota B4(si)
      delay(1000); 
      noTone(3);
      break;
   /*****
    * Empieza una nueva escala 
    ****/
    case 10010://A & P 
      tone(jack,523);//suena la nota C5 do
      delay(1000); 
      noTone(3);
      break;
    case 10001://M & P son LOW
      tone(jack,587);//suena la nota D5 re 
      delay(1000); 
      noTone(3);
      break;
    case 1100://C & I
      tone(jack,659);//suena la nota E5 mi 
      delay(1000); 
      noTone(3);
      break;
    case 1010://A & I
      tone(jack,698);//suena la nota F5 fa
      delay(1000); 
      noTone(3);
      break;
    case 1001:// M & I son LOW
      tone(jack,784);//suena la nota G5 sol
      delay(1000); 
      noTone(3);
      break;
    case 110://A & C 
      tone(jack,880);//suena la nota A5 la 
      delay(1000); 
      noTone(3);
      break;
    case 101:// M & C son LOW
      tone(jack,988);//suena la nota B5 si
      delay(1000); 
      noTone(3);
      break;
    /***
     * Nueva escala 
     */
    case 11://M & A son LOW
      tone(jack,1047);//suena la nota C6 do
      delay(1000); 
      noTone(3);
      break;

    default:// No ha ocurrido ninguna de las anteriores combinaciones 
      noTone(jack);// No suena nada 
      break;
  }
}
