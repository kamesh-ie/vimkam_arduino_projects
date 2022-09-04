
void setup(){
  for(int i =0;i<14;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(A5,OUTPUT);

}

void loop(){
  digitalWrite(A5,HIGH);
 for(int i=0;i<14;i++){
  digitalWrite(i,HIGH);
 }
  for(int i=0;i<14;i++){
  digitalWrite(i,LOW);
  delay(200);
 }
 
 
}
