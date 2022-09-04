
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
    if (let == '#') {break;}
    data+=let; 
    Serial.println(data);
    
   }
    
   if(data == "*forward") 
  {
    //Move both Motors forward
    digitalWrite(MotorAip1,HIGH);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 200);
    analogWrite (enB, 200);
  }

  else if(data == "*backward")  
  {
    //Move both Motors backward
     digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,HIGH);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
    analogWrite (enA, 200);
    analogWrite (enB, 200);
  }

  else if(data == "*left")
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

  else if(data == "*right")
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
  else if(data == "*stop")
  {
    //Move both Motors right 
    digitalWrite(MotorAip1,HIGH);     
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 0);
    analogWrite (enB, 0);
    delay(100);
     
  }
  else {}
  delay(100);
  data="";
   
}
