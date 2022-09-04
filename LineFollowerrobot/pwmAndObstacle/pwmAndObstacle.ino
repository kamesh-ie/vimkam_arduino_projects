#define echoPin 12 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 11

long duration; // variable for the duration of sound wave travel
int distance;

// Black Line Follower 
int IR1=8;      //Right sensor
int IR2=9;    //left Sensor
// motor one
int enA = 5;    //Right motor
int MotorAip1=2;
int MotorAip2=3;
// motor two
int enB = 6;    //Left motor
int MotorBip1=4;
int MotorBip2=7;


void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(MotorAip1,OUTPUT);
  pinMode(MotorAip2,OUTPUT);
  pinMode(MotorBip1,OUTPUT);
  pinMode(MotorBip2,OUTPUT);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
 
}
void loop() 
{
  digitalWrite(13,HIGH);
  int obj_dist = distance_func();
  Serial.println(obj_dist);
   if(obj_dist < 15){
    analogWrite (enA, 0);
    analogWrite (enB, 0);
   }
   else if(digitalRead(IR1)==HIGH && digitalRead(IR2)==HIGH) //IR will not glow on black line
  {
    //Stop both Motors
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
   analogWrite (enA, 0);
   analogWrite (enB, 0);
  }

  else if(digitalRead(IR1)==LOW && digitalRead(IR2)==LOW)  //IR not on black line
  {
    //Move both the Motors
    digitalWrite(MotorAip1,HIGH);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 200);
    analogWrite (enB, 200);
  }

  else if(digitalRead(IR1)==LOW && digitalRead(IR2)==HIGH)
  {
    //Tilt robot towards left by stopping the left wheel and moving the right one
    digitalWrite(MotorAip1,HIGH);     
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
    analogWrite (enA, 200);
    analogWrite (enB, 0);
   delay(100);
  }

  else if(digitalRead(IR1)==HIGH && digitalRead(IR2)==LOW)
  {
    //Tilt robot towards right by stopping the right wheel and moving the left one
     digitalWrite(MotorAip1,LOW);     // If I want to turn right then the speed of the right wheel should be less than that of the left wheel, here, let a be the right wheel
    digitalWrite(MotorAip2,HIGH);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 0);
   analogWrite (enB, 200);
   delay(100);
  }

  else
  {
    //Stop both the motors
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 0);
   analogWrite (enB, 0);
  }
}

int distance_func(){
   // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
//  Serial.println(duration);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  return distance;
}
