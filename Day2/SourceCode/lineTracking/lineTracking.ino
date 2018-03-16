#define Trig 		2
#define Echo 		3

#define dirA2   4
#define dirA1		5
#define PWMA		6

#define dirB1		7
#define dirB2		8
#define PWMB		9

#define sideLeft 	  digitalRead(10)
#define centerLeft 	digitalRead(11)
#define centerRight digitalRead(12)
#define sideRight 	digitalRead(13)

#define switch1	  	digitalRead(14)

#define BLACK 1
#define WHITE 0

unsigned int sonarChk(int Trig_pin,int Echo_pin)
{
  unsigned int distance_cm;
  long  duration;
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  duration = pulseIn(Echo_pin,HIGH,23200);
  if (duration==0)
  {
    duration=23200;
  }
  if (duration==23200)
  {
    distance_cm = 400 ;
  }
  else
  {
    distance_cm = (duration /29) >> 1 ;
  }
  return distance_cm;
}

void testSonar(){
	while(1){
		Serial.println((int)sonarChk(Trig,Echo));
		delay(1000);
	}
}

void testSensor(){
	while(1){
	    Serial.print(sideLeft); Serial.print("   ");
	    Serial.print(centerLeft); Serial.print("   ");
	    Serial.print(centerRight); Serial.print("   ");
	    Serial.print(sideRight); Serial.print("\n");
	    delay(1000);
	}
}

void motor(char ch, int pow)
{

  if (pow >= -255 && pow <= 255)
  {
    if (ch == 1 && pow > 0)
    {
      digitalWrite(dirA1, LOW);
      digitalWrite(dirA2, HIGH);
      analogWrite(PWMA, pow);
    }
    else if (ch == 1 && pow < 0)
    {
      digitalWrite(dirA1, HIGH);
      digitalWrite(dirA2, LOW);
      analogWrite(PWMA, -pow);
    }
    else if (ch == 2 && pow > 0)
    {
      digitalWrite(dirB1, LOW);
      digitalWrite(dirB2, HIGH);
      analogWrite(PWMB, pow);
    }
    else if (ch == 2 && pow < 0)
    {
      digitalWrite(dirB1, HIGH);
      digitalWrite(dirB2, LOW);
      analogWrite(PWMB, -pow);
    }
    else if (ch == 1 && pow == 0)
    {
      digitalWrite(dirA1, HIGH);
      digitalWrite(dirA2, HIGH);
      analogWrite(PWMA, pow);
    }
    else if (ch == 2 && pow == 0)
    {
      digitalWrite(dirB1, HIGH);
      digitalWrite(dirB2, HIGH);
      analogWrite(PWMB, pow);
    }
  }
}

void motorControl(int leftSpeed,int rightSpeed){
	motor(1,leftSpeed);
	motor(2,rightSpeed);
}
void setup()
{
	for (int i = 4; i <= 9; i++){
		pinMode(i,OUTPUT);
	}
	for (int i = 10; i <= 13; i++){
		pinMode(i,INPUT);
	}
	pinMode(2,OUTPUT);
	pinMode(3,INPUT);
	pinMode(14,INPUT_PULLUP);
	Serial.begin(115200);
}

void lineTracking(int trackSpeed, int diffSpeed){
  if (centerLeft==0 && centerRight==0) motorControl(trackSpeed,trackSpeed);
  else if (centerLeft==1 && centerRight==0) motorControl(trackSpeed-diffSpeed,trackSpeed);
  else if (centerLeft==0 && centerRight==1) motorControl(trackSpeed,trackSpeed-diffSpeed);
  else if (centerLeft==1 && denterRight==1) motorControl(trackSpeed,trackSpeed);
}

void loop()
{

}
