#define dirA1   4
#define dirA2   5
#define PWMA    6
#define dirB1   7
#define dirB2   8
#define PWMB    9

void setup() {
  Serial.begin(115200);
  pinMode(dirA1,OUTPUT);
  pinMode(dirA2,OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(dirB1,OUTPUT);
  pinMode(dirB2,OUTPUT);
  pinMode(PWMB,OUTPUT);
}

void loop() {
  
}
