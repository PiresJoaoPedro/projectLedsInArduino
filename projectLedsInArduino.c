#include <IRremote.h>

#define RECV_PIN 2

#define LED1 8
#define LED2 9
#define LED3 10

#define TECLA_1 0xEF10BF00
#define TECLA_2 0xEE11BF00
#define TECLA_3 0xED12BF00

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();

}

void loop() {
    if (irrecv.decode()){
    unsigned long codigoRecebido = irrecv.decodedIRData.decodedRawData;
    
    Serial.println(codigoRecebido,HEX);
    delay(100);
    
    switch(codigoRecebido)
    {
    	case TECLA_1:
        digitalWrite(LED1,!digitalRead(LED1));
          
        break;
      
        case TECLA_2:
        digitalWrite(LED2,!digitalRead(LED2));
      
        break;
          
        case TECLA_3:
      	digitalWrite(LED3,!digitalRead(LED3));
      
        break;
    }
    
    irrecv.resume();
  }
}
