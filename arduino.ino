
void setup(){
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT); 
}

void loop(){
  for(iint i=9;i<13;i++){
    digitalWrite(i,HIGH);
    delay(500);
  }
}
