
#define enA 9
#define in1 4
#define in2 5
#define enB 10
#define in3 6
#define in4 7
const int led = 53;
char recebido;
int counter = 0;

//Sensor Ultrassonico
int PinTrigger = 22; //pino usado para disparar os pulsos do sensor
int PinEcho = 24;//pino usado para ler a saida do sensor
float TempoEcho =0;
const float VelocidadeSom_mpors = 340;//em metros por segundo
const float VelocidadeSom_mporus = 0.000340; // em metros por microsegundo


//Carro



int motorSpeedA = 0;
int motorSpeedB = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  pinMode(led,OUTPUT);
  //pinMode(buzzerPin,OUTPUT);

  //CARRO
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(PinTrigger, OUTPUT);
  digitalWrite(PinTrigger, LOW);
  pinMode(PinEcho,INPUT);
  
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:

  DisparaPulsoUltrassonico();
  
 TempoEcho = pulseIn(PinEcho, HIGH);


  if(Serial.available() > 0){
    recebido = Serial.read();
  }
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

if((CalculaDistancia(TempoEcho)*100) >= 20){
  if(recebido == 'F'){
   frente();   
  }else if (recebido == 'T'){
    tras();   
  }else if(recebido == 'D'){
    direita();
  }else if(recebido == 'E'){
    esquerda();
  }else if(recebido == 'A'){
     motorSpeedA = 0;
     motorSpeedB = 0;
  }
}else{
   motorSpeedA = 0;
     motorSpeedB = 0;
}
  
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B


 
/*
  if(recebido == 'F'){   
    liga();
  }else if(recebido == 'T'){
    digitalWrite(led,LOW);
    Serial.print("Ola");
  }else if(recebido = 'a'){
    digitalWrite(led,LOW);
  }
*/


}//fim loop


void DisparaPulsoUltrassonico(){
  digitalWrite(PinTrigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(PinTrigger, LOW);
}

float CalculaDistancia(float tempo_us){
  return ((tempo_us*VelocidadeSom_mporus)/2);
}





void frente(){
//Colocar motor A para RÈ
     digitalWrite(in1, HIGH);
     digitalWrite(in2, LOW);
    //Colocar motor B para RE 
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
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
    motorSpeedB = 255;
}
void esquerda(){
  digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
      motorSpeedA = 255;
    motorSpeedB = 0;
}
