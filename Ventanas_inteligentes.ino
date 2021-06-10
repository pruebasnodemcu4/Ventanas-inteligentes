#include <Servo.h>

Servo servo_1;
Servo servo_2;

int lluvia = 8;
int valor;
int luminosidad;
int lectura; 
float temp;
int frio = 2;
int aceptable = 4;
int calor = 5;
int ventana = 7;
int rele = 9;
int siono = 10;
int movimiento = 11;


void setup() {
  servo_1.attach (3);
  servo_1.write (0);
  servo_2.attach (6);
  servo_2.write (0);
  delay(500);
  Serial.begin (9600);
  pinMode (frio, OUTPUT);
  pinMode (aceptable, OUTPUT);
  pinMode (calor, OUTPUT);
  pinMode (rele, OUTPUT);
  pinMode (ventana, INPUT_PULLUP);
  pinMode (lluvia, INPUT_PULLUP);
  pinMode (siono, INPUT_PULLUP);
  pinMode (movimiento, INPUT);
  digitalWrite (frio, LOW);
  digitalWrite (aceptable, LOW);
  digitalWrite (calor, LOW);
  delay (2000);
}

void loop(){
 valor = analogRead (A4);
 lectura = analogRead (A3);
 luminosidad = map(valor, 969, 49, 0, 100);
 Serial.print("Valor: ");
 Serial.print(valor);
 Serial.print ("  Luminosidad: ");
 Serial.print (luminosidad);
 Serial.print ("%");
 temp = map(lectura, 0, 1023, -5000, 45000);
 temp = temp/100.00;
 Serial.print(" Lectura: ");
 Serial.print(lectura);
 Serial.print ("  Temperatura: ");
 Serial.print (temp);
 Serial.print ("C");
 Serial.println ();
 v_abierta();
 v_cerrada();
  if(temp <= 50 && temp >= 41){
    digitalWrite (calor, HIGH);
     }else{
    digitalWrite (calor, LOW);}
  if(temp <= 40 && temp >= 16 ){
    digitalWrite (aceptable, HIGH);
     }else{
    digitalWrite (aceptable, LOW);}
  if(temp <= 15 && temp >= 0){
    digitalWrite (frio, HIGH);
     }else{
    digitalWrite (frio, LOW);} 
  if(digitalRead(siono) == false){
    servo_1.write (90);
    servo_2.write (90);}
    delay(500);
}
  
void v_cerrada(){
  /*if(temp <=50 && temp >= 41 && digitalRead(ventana) == false){
    servo_1.write (90);
    servo_2.write (90);}
  if(temp <=15 && temp >= 0 && digitalRead(ventana) == false){
    servo_1.write (90);
    servo_2.write (90);}
  if(temp <=40 && temp >= 16 && digitalRead(ventana) == false){
    servo_1.write (90);
    servo_2.write (90);}*/
}
  
  
void v_abierta(){
  
  if(valor <=968 && valor >= 216 && digitalRead(ventana) == true){
    servo_1.write (0);
    servo_2.write (0);}
  /*if(temp <=15 && temp >= 0 && digitalRead(ventana) == true){
    servo_1.write (0);
    servo_2.write (0);}
  delay(100);*/
  if(temp <=50 && temp >= 41 && digitalRead(ventana) == true && digitalRead(movimiento) == true){
    servo_1.write (0);
    servo_2.write (0);
    digitalWrite (rele, HIGH);}
  if(temp <=10 && temp >= 0 && digitalRead(ventana) == true){
    servo_1.write (0);
    servo_2.write (0);}
  if( digitalRead(ventana) == true && digitalRead(lluvia) == true){
    servo_1.write (0);
    servo_2.write (0);}
}
  
    

 
