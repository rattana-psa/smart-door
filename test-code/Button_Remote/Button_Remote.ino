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
    switch(results.value)
    {
      case 0x4040807F :       
        
        Serial.println("PUSH: 1 "); break;
        
      case 0x404040BF :       
        Serial.println("PUSH: 2 "); break;
        
      case 0x4040C03F : 
        Serial.println("PUSH: 3 "); break;
        
      case 0x404020DF : 
        Serial.println("PUSH: 4 "); break;
        
      case 0x4040A05F : 
        Serial.println("PUSH: 5 "); break;
        
      case 0x4040609F : 
        Serial.println("PUSH: 6 "); break;
        
      case 0x4040E01F : 
        Serial.println("PUSH: 7 "); break;
        
      case 0x404010EF : 
        Serial.println("PUSH: 8 "); break;
        
      case 0x4040906F : 
        Serial.println("PUSH: 9 "); break;
        
      case 0x404000FF : 
        Serial.println("PUSH: 0 "); break;
        
      case 0x404050AF : 
        Serial.println("PUSH: POWER "); break;
        
      case 0x40409867 : 
        Serial.println("PUSH: MUTE "); break;
        
      case 0x40406897 : 
        Serial.println("PUSH: MENU "); break;
        
      case 0x4040F807 : 
        Serial.println("PUSH: EXIT "); break;
        
      case 0x4040B04F : 
        Serial.println("PUSH: OK "); break;
        
      case 0x4040D02F : 
        Serial.println("PUSH: UP "); break;
        
      case 0x4040708F : 
        Serial.println("PUSH: DOWN "); break;
        
      case 0x40408877 : 
        Serial.println("PUSH: LEFT "); break;
        
      case 0x404008F7 : 
        Serial.println("PUSH: RIGHT "); break;
        
      case 0xFFFFFFFF: 
        Serial.println("*****"); break;
        
      default: 
        Serial.println("Other Button ");
      
    }    
    irrecv.resume();
  }
}
