int r = 2;
int g = 3;
int b = 4;
int pass[4];
int countPass = sizeof(pass)/2;
int count = 0;
int t = 0;
int button[12] = { 930, 970, 985, 995, 1000, 1006, 500, 650, 750, 800, 840, 850 };

void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  
  //Input Password
  int in1 = analogRead(A0);   // 1-6
  int in2 = analogRead(A3);   // 7-0, Reset, Clear
  Serial.println("Input1: ");
  Serial.println(in1);
  Serial.println("PASS: ");
  Serial.println( countPass );
  /*
  Serial.println("Input2: ");
  Serial.println(in2);
  */
  delay(250);
  
  analogWrite(r, LOW);
  analogWrite(g, LOW);
  analogWrite(b, LOW);

  //Input 1
  if( in1 < 1020 ){
    if( count < countPass ){
      // 1 - 6
      if( 1023 > in1 && in1 >= button[5] ){
        pass[count] = 5;
        analogWrite(r, LOW);
        analogWrite(g, HIGH);
        analogWrite(b, LOW);
        Serial.println("PUSH: 5 ");
      }else if( button[5] > in1 && in1 >= button[4] ){
        pass[count] = 4;
        analogWrite(r, LOW);
        analogWrite(g, HIGH);
        analogWrite(b, LOW);
        Serial.println("PUSH: 4 ");
      }else if( button[4] > in1 && in1 >= button[3] ){
        pass[count] = 3;
        analogWrite(r, LOW);
        analogWrite(g, HIGH);
        analogWrite(b, LOW);
        Serial.println("PUSH: 3 ");
      }else if( button[3] > in1 && in1 >= button[2] ){
        pass[count] = 2;
        analogWrite(r, LOW);
        analogWrite(g, HIGH);
        analogWrite(b, LOW);
        Serial.println("PUSH: 2");
      }else if( button[2] > in1 && in1 >= button[1] ){
        pass[count] = 1;
        analogWrite(r, LOW);
        analogWrite(g, HIGH);
        analogWrite(b, LOW);
        Serial.println("PUSH: 1 ");
      }else if( button[1] > in1 && in1 >= button[0] ){
        pass[count] = 0;
        analogWrite(r, LOW);
        analogWrite(g, HIGH);
        analogWrite(b, LOW);
        Serial.println("PUSH: 0 ");        
      }
      delay(1000);
      Serial.println(pass[count]);
      count++;
      // 7 - 0
      
      analogWrite(r, LOW);
      analogWrite(g, LOW);
      analogWrite(b, LOW);

      //Show Password
      if( count == countPass ){
        for(int i=0; i< countPass; i++){
          Serial.println("Pass: ");
          Serial.println(pass[i]);      
        }  
      }

      //Check Password      
      if(pass[0] == 0){
        t++;
      }
      if(pass[1] == 1){
        t++;
      }
      if(pass[2] == 2){
        t++;
      }
      if(pass[3] == 3){
        t++;
      }

      //Password Correct
      if( t == countPass ){   
        analogWrite(r, HIGH);
        analogWrite(g, HIGH);
        analogWrite(b, HIGH); 
      }
      delay(1000); 
    } 
  }   
}
