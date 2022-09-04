
// motor one
String data;
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
  pinMode(MotorAip1,OUTPUT);
  pinMode(MotorAip2,OUTPUT);
  pinMode(MotorBip1,OUTPUT);
  pinMode(MotorBip2,OUTPUT);
}
void loop() 
{
  // put your main code here, to run repeatedly:
 while(Serial.available()>0)
   {
    char let = Serial.read();
    Serial.println(let);
    
   if(let == 'F') 
  {
    //Move both Motors forward
    digitalWrite(MotorAip1,HIGH);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 200);
    analogWrite (enB, 200);
  }

  else if(let == 'G')  
  {
    //Move both Motors backward
     digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,HIGH);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
    analogWrite (enA, 200);
    analogWrite (enB, 200);
  }

  else if(let == 'L')
  {
    //Move both Motors left
    digitalWrite(MotorAip1,LOW); 
    digitalWrite(MotorAip2,HIGH);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 0);
   analogWrite (enB, 200);
   delay(100);

  }

  else if(let == 'R')
  {
    //Move both Motors right 
    digitalWrite(MotorAip1,HIGH);     
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
    analogWrite (enA, 200);
    analogWrite (enB, 0);
    delay(100);
     
  }

  else if(let == 'Q')
  {
    //Move both Motors left-up
    digitalWrite(MotorAip1,HIGH);     
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 100);
    analogWrite (enB, 200);
    delay(100);
  }
  else if(let == 'E')
  {   //Move both Motors right-up
     digitalWrite(MotorAip1,HIGH);     
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 200);
    analogWrite (enB, 100);
    delay(100);
  }
  else if(let == 'Z')
  {
    //Move both Motors left-down
    digitalWrite(MotorAip1,LOW);     
    digitalWrite(MotorAip2,HIGH);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
    analogWrite (enA, 200);
    analogWrite (enB, 100);
    delay(100);
  }
  else if(let == 'C')
  {
    //Move both Motors right-down
     digitalWrite(MotorAip1,LOW);     
    digitalWrite(MotorAip2,HIGH);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
    analogWrite (enA, 100);
    analogWrite (enB, 200);
    delay(100);
  }
  else if(let == 'S')
  {
    //stop both Motors
    analogWrite (enA, 0);
    analogWrite (enB, 0);
    delay(100);
  }
  else {}
  delay(100);
   }
}
