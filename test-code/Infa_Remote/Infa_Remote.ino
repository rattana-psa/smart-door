#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>


int RECV = 11;
IRrecv irrecv(RECV);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  
}

void loop() {
  if(irrecv.decode(&results))
  {
    digitalWrite(13, HIGH);
    switch(results.decode_type)
    {
      case NEC: Serial.print("NEC: "); break;
      case SONY: Serial.print("SONY: "); break;
      case SHARP : Serial.print("SHARP: "); break;
      case PANASONIC: Serial.print("PANASONIC: "); break;
      case JVC: Serial.print("JVC: "); break;
      case SANYO: Serial.print("SANYO: "); break;
      case MITSUBISHI: Serial.print("MITSUBISHI: "); break;
      case RC5: Serial.print("RC5: "); break;
      case RC6: Serial.print("RC6: "); break;
      case DENON: Serial.print("DENON: "); break;
      case SAMSUNG: Serial.print("SAMSUNG: "); break;
      case LG: Serial.print("LG: "); break;
      case UNKNOWN: Serial.print("UNKNOWN: "); break;
      
    }
    Serial.println(results.value, HEX); 
    irrecv.resume();
  }
}
