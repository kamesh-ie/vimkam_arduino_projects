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
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(MotorAip1,OUTPUT);
  pinMode(MotorAip2,OUTPUT);
  pinMode(MotorBip1,OUTPUT);
  pinMode(MotorBip2,OUTPUT);
}
void loop() 
{

    //Move both the Motors
    digitalWrite(MotorAip1,HIGH);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 200);
    analogWrite (enB, 200);

}
