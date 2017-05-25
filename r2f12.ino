
#include "Keyboard.h"

void setup() {                
  // inicializa a porta 4 como porta de saída / escrita.
  pinMode(13, OUTPUT); 
  // escreve o estado da porta 4 como LOW / desligado
  digitalWrite(13, LOW); 
  // inicializa a porta 4 como porta de entrada / leitura.
  pinMode(7, INPUT); 

}
void loop(){
   int buttonState = 0;// variável para armazenar a leitura da porta
  // le o estado da porta digital 7
  buttonState = digitalRead(7);

  // checa se o interruptor esta fechado
  // se ele estiver, o buttonState vai ser HIGH:
  if (buttonState == HIGH) {     
    // liga o LED   
    //Serial.println("OK!");
    digitalWrite(13, HIGH);  
    Keyboard.write(KEY_F12);
  } 
  else {
    // desliga o LED
    digitalWrite(13, LOW); 
  }
}
