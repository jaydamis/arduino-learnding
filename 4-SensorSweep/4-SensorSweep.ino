#include <Servo.h>

const int SERVOPIN=3;
Servo myservo;

int pos = 0;
void setup()
{
  myservo.attach(SERVOPIN);
}

void loop()
{
  for(pos=0;pos<=1000;pos++){
    myservo.write(pos);
    delay(50);
  }
      delay(10000);
  for(pos;pos>0;pos--){
    myservo.write(pos);
  delay(50);
  }
      delay(10000);
//myservo.write(30);
//delay(5000);
//myservo.write(90);
//delay(5000);
}
