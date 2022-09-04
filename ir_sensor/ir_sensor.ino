
void setup(){
//  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(11,INPUT);
//  pinMode(7,INPUT); 
  Serial.begin(9600); 
}

void loop(){
  int out=digitalRead(11);
  Serial.println(out);
}
