#include <Mouse.h>

#include <Keyboard.h>

#include <SPI.h>
#include <MFRC522.h>


#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   
int UID1[4]={0x75,0xDA,0xE7,0x2B};// 카드형
int UID2[4]={0x23,0x68,0x13,0xA3};// 키홀더형


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);      
  Mouse.begin();
  Keyboard.begin();
  SPI.begin();              //SPI 초기화
  mfrc522.PCD_Init();            //MFRC522 초기화
  pinMode(7,OUTPUT);
  
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent())       //새로운 카드 대기    
    return;
  if ( ! mfrc522.PICC_ReadCardSerial())         // 카드 읽어오기
    return; 
  mfrc522.PCD_DumpVersionToSerial();   //PCD의 세부정보 표시 - MFRC522 카드 세부정보 표시
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));  //카드의 정보(UID,SAK,Type)를 시리얼로 전송합니다.
bool check=true;
if(mfrc522.uid.uidByte[0]==UID1[0]){
  for(int i=0;i<4;i++){
    if(mfrc522.uid.uidByte[i]!=UID1[i]){check=false;}
  }
}
else if(mfrc522.uid.uidByte[0]==UID2[0]){
    for(int i=0;i<4;i++){
      if(mfrc522.uid.uidByte[i]!=UID2[i]){check=false;}
    }
}
else{ check= false;}

if(check==true){
  digitalWrite(7,HIGH);
      Mouse.click(MOUSE_LEFT);
      delay(200);
      Keyboard.print("password");
      delay(100);
      Keyboard.write(KEY_RETURN);
      digitalWrite(7,LOW);
  }
  
 
}
