
#define pinVRx A0
#define pinVRy A1


void setup() {
  // put your setup code here, to run once:
  pinMode(pinVRx, INPUT);
  pinMode(pinVRy, INPUT);

  Serial.begin(38400);

}

void loop() {
  // put your main code here, to run repeatedly:
  int valorVRx = analogRead(pinVRx);
  int valorVRy = analogRead(pinVRy);

  //Serial.print("\n   Valor VRX: ");
  //Serial.print(valorVRx);
  //Serial.print("   Valor VRy: ");
  //Serial.print(valorVRy);

  if(valorVRx <= 50){
    //Serial.print("\nF");
    Serial.write('F');//Frente
    delay(20);
  }else if(valorVRx >=1000){
   // Serial.print("\n T");//Volta
    Serial.write('T');
    delay(20);
  }else if(valorVRy <= 100){
    //Serial.print("\nD");//Direita
    Serial.write('D');
    delay(20);
  }else if(valorVRy >=1000){
   // Serial.print("\nE");//esquerda
    Serial.write('E');
    delay(20);
  }else{
   Serial.write('A');
    delay(20);
  }
  
  
  
  
  
}

  
