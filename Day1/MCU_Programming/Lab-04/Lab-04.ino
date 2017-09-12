void setup() {
  Serial.begin(115200);
  pinMode(10,INPUT);
}

void loop() {
  int data;
  data = digitalRead(10);
  Serial.print("Pin Value 10 : ");
  Serial.println(data);
  delay(1000);
}
