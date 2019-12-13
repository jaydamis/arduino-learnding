#include <Servo.h>

#define trigPin 2
#define echoPin 3
const int SERVOPIN=4;
    
Servo myservo;
long duration;
int distance;

int pos = 0;
void setup()
{
  myservo.attach(SERVOPIN);
  // Define inputs and outputs:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
}

void loop()
{
  for(pos=0;pos<=180;pos++){
    myservo.write(pos);
      for(int i=0;i<3;i++){
      Serial.print(pos);
      Serial.print(", ");
      reportDistance();      
    }

    delay(50);
  }
  for(pos;pos>0;pos--){
        myservo.write(pos);
      for(int i=0;i<3;i++){
      Serial.print(pos);
      Serial.print(", ");
      reportDistance();      
    }
  delay(50);
  }
}

void reportDistance(){
  // Clear the trigPin by setting it LOW:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance:
  distance= duration*0.034/2;
  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  //Serial.print("Distance = ");
  Serial.println(distance);
  //Serial.println(" cm");
  
  delay(50);
}
