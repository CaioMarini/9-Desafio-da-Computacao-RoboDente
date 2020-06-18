#include <Ultrasonic.h>//bibliotec do sensor ultrassonico
#include <Servo.h>//biblioteca do servo motor
#define enA 9
#define in1 4
#define in2 5
#define enB 10
#define in3 6
#define in4 7
const int led = 53;
char recebido;


//Sensor Ultrassonico
#define pinptrigger 22 //pino usado para disparar os pulsos do sensor
#define pinecho 24//pino usado para ler a saida do sensor
Ultrasonic ultrasonic(pinptrigger, pinecho);

//Servo
Servo serUm;
int posUm = 0;

Servo serDois;
int posDois = 0;


int motorSpeedA = 0;
int motorSpeedB = 0;

//Buzzer
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

const int buzzerPin = 26;
int counter = 0;
int const ledPin1 =28;
int const ledPin2 = 30;

void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(38400);
  //pinMode(led,OUTPUT);
  //pinMode(buzzerPin,OUTPUT);

  //CARRO
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(led, OUTPUT);

  serUm.attach(32); //pino que liga o servo no arduino
  serUm.write(0);//Inicia o servo na posição 0

   serDois.attach(34); //pino que liga o servo no arduino
  serDois.write(0);//Inicia o servo na posição 0

  
  //delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  float cmMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  
 


  if(Serial.available() > 0){
    recebido = Serial.read();
    Serial.write(recebido);
  }

if(cmMsec > 25){
  switch (recebido){
    case 'F':
      frente(); 
      break;
    case 'T':
      tras(); 
      break;
    case 'D':
       direita();
       break;
     case 'E':
        esquerda();
        break;
      case 'A':
        motorSpeedA = 0;
        motorSpeedB = 0;
        break;
      case 'O':
        digitalWrite(led, HIGH);       
              //Play first section
              firstSection();             
              //Play second section
              secondSection();            
              beep(f, 250);  
              beep(gS, 500);  
              beep(f, 350);  
              beep(a, 125);
              beep(cH, 500);
              beep(a, 375);  
              beep(cH, 125);
              beep(eH, 650);             
              delay(500);             
              //Repeat second section
              secondSection();
             beep(f, 250);  
              beep(gS, 500);  
              beep(f, 375);  
              beep(cH, 125);
              beep(a, 500);  
              beep(f, 375);  
              beep(cH, 125);
              beep(a, 650);  
          
         //delay(25);
          digitalWrite(led, LOW);
          break;
      case 'W':
        posUm +=5;
        posDois +=5;
        serUm.write(posUm); 
        serDois.write(posDois);
        if(posUm >=181|| posDois>=181){
          posUm = 180;
          posDois =180;
        }
        break;
      case 'S':
      posUm -= 5;
      posDois -=5;
      serUm.write(posUm);
      serDois.write(posDois);
      if(posUm >= 0|| posDois >=0){
        posUm = 0;
        posDois = 0;
      }
       break;
  }
}else{
        motorSpeedA = 0;
        motorSpeedB = 0;
}

  /*
  if(cmMsec >25){
    if(recebido == 'F'){
     frente();   
     //digitalWrite(led, HIGH);  
    }else if (recebido == 'T'){
      tras();   
    }else if(recebido == 'D'){
      direita();
      //digitalWrite(led, HIGH); 
    }else if(recebido == 'E'){
      esquerda();
      
    }else if(recebido == 'A'){
       motorSpeedA = 0;
       motorSpeedB = 0;
       //digitalWrite(led, LOW); 
    }
  }else{
       motorSpeedA = 0;
       motorSpeedB = 0;
  }

*/
/*
  if(recebido == 'F'){
   //Colocar motor A para RÈ
     digitalWrite(in1, HIGH);
     digitalWrite(in2, LOW);
    //Colocar motor B para RE 
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    motorSpeedA = 255;
    motorSpeedB = 255;
    
  }else if (recebido == 'T'){
    // Set Motor A forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Set Motor B forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    motorSpeedA = 255;
    motorSpeedB = 255;  
    
  }else if(recebido == 'D'){
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
      motorSpeedA = 0;
    motorSpeedB = 255;
  }else if(recebido == 'E'){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
      motorSpeedA = 255;
    motorSpeedB = 0;
  }else if(recebido == 'A'){
     motorSpeedA = 0;
    motorSpeedB = 0;
  }
  */


  
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B




}//fim loop






void frente(){
//Colocar motor A para RÈ
   // Set Motor A forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B forward
    digitalWrite(in3, LOW);
    digitalWrite(in4,HIGH);
    motorSpeedA = 255;
    motorSpeedB = 255;
}
void tras(){
  // Set Motor A forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Set Motor B forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    motorSpeedA = 255;
    motorSpeedB = 255;  
}
void direita(){
  digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
      motorSpeedA = 0;
    motorSpeedB = 250;
}
void esquerda(){
  digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
      motorSpeedA = 255;
    motorSpeedB = 0;
}



void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);
 
  if(counter % 2 == 0)
  {
    digitalWrite(ledPin1, HIGH);
    delay(duration);
    digitalWrite(ledPin1, LOW);
  }else
  {
    digitalWrite(ledPin2, HIGH);
    delay(duration);
    digitalWrite(ledPin2, LOW);
  }
  //Stop tone on buzzerPin
  noTone(buzzerPin);
 
  delay(50);
 
  //Increment counter
  counter++;
}
 
void firstSection()
{
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
 
  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
}
 
void secondSection()
{
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);    
  beep(fSH, 250);
 
  delay(325);
 
  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);  
  beep(cSH, 175);  
  beep(cH, 125);  
  beep(b, 125);  
  beep(cH, 250);  
 
  delay(350);
}
