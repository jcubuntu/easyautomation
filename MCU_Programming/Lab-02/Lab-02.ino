void setup() {
  pinMode(13,OUTPUT);     //กำหนดให้ขา 13 ทำงานใน Mode OUTPUT  
}

void loop() {
  analogWrite(13,100);    // สั่งงานให้ขา 13 จ่ายสัญญาน PWM ระดับ 100 
  delay(1000);            // นับเวลา 1 วินาที
  digitalWrite(13,255);   // สั่งงานให้ขา 13 จ่ายสัญญาน PWM ระดับ 255 
  delay(1000);            // นับเวลา 1 วินาที
}
