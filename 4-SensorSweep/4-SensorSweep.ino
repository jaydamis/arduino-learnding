#include <Servo.h>

const int SERVOPIN=4;
Servo myservo;

int pos = 0;
void setup()
{
  myservo.attach(SERVOPIN);
}

void loop()
{
  for(pos=0;pos<=180;pos++){
    myservo.write(pos);
    delay(50);
  }
      delay(1000);
  for(pos;pos>0;pos--){
    myservo.write(pos);
  delay(50);
  }
      delay(1000);
//myservo.write(30);
//delay(5000);
//myservo.write(90);
//delay(5000);
}
