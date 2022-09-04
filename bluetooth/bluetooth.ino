String data;
void setup() {
Serial.begin(9600);
 pinMode(9, OUTPUT); // put your setup code here, to run once:
 }
 
void loop() {
  data = "";
  // put your main code here, to run repeatedly:
 while(Serial.available()>0)
   {
    char let = Serial.read();
    data+=let;
    }
    if(data != ""){
      Serial.println(data);
    }
   delay(50);
}
