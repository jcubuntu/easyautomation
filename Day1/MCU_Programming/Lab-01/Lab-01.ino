void setup() {
  pinMode(13,OUTPUT);     //กำหนดให้ขา 13 ทำงานใน Mode OUTPUT  
}

void loop() {
  digitalWrite(13,HIGH);  // สั่งงานให้ขา 13 จ่ายกระแสไฟฟ้า หรือ Output เป็น 1  
  delay(1000);            // นับเวลา 1 วินาที
  digitalWrite(13,LOW);   // สั่งงานให้ขา 13 หยุดจ่ายกระแสไฟฟ้า หรือ Output เป็น 0 
  delay(1000);            // นับเวลา 1 วินาที
}
