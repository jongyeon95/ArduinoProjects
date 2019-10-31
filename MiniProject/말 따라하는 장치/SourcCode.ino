
int Sound=0;
void setup() {
  pinMode(3,OUTPUT);//paly pin
  pinMode(4,OUTPUT);//rec pin
}


void loop() {
  // put your main code here, to run repeatedly:
 
  digitalWrite(4,LOW);//rec pin
  digitalWrite(3,LOW);//paly pin
  
   Sound=analogRead(A1);
      Serial.println(Sound);
      if(Sound!=60){
       digitalWrite(4,HIGH);//rec on
       delay(4000);
       digitalWrite(4,LOW);////rec off
       delay(100);
       digitalWrite(3,HIGH);//paly on
       delay(4000);
       digitalWrite(3,LOW); //paly off     
       }      
       delay(200);
   
}
