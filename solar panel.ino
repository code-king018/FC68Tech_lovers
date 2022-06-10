int sensorValue;

#define LDR A0
int count = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(LDR,INPUT);
sensorValue = analogRead(A0);
Serial.begin(9600);//LDR Module
Serial.println(sensorValue);
}

void loop() {
  // put your main code here, to run repeatedly:
  int bits1[256];
  int bits2[256];
  int bits3[256];
  if(analogRead(LDR) > sensorValue + 50){
    delay(10);
  for(int i = 0;i<256;i++){
  delay(10);
  if(analogRead(LDR) > sensorValue + 50)
  bits1[i] = 1;
  else
  bits1[i] = 0;
  }
  Serial.println("The 256 bit data for 50 Hz Frequency light is :");
  for(int i=0;i<256;i++){
    Serial.print(bits1[i]);
  }
  }  
  if(analogRead(LDR) > sensorValue + 50){
    delay(10);
  for(int i = 0;i<256;i++){
  delay(10);
  if(analogRead(LDR) > sensorValue + 50)
  bits2[i] = 1;
  else
  bits2[i] = 0;
  }
  Serial.println("The 256 bit data for 50 Hz Frequency light is :");
  for(int i=0;i<256;i++){
    Serial.print(bits2[i]);
  }
  }
  if(analogRead(LDR) > sensorValue + 50){
    delay(10);
  for(int i = 0;i<256;i++){
  delay(10);
  if(analogRead(LDR) > sensorValue + 50)
  bits3[i] = 1;
  else
  bits3[i] = 0;
  }
  Serial.println("The 256 bit data for 50 Hz Frequency light is :");
  for(int i=0;i<256;i++){
    Serial.print(bits3[i]);
  }
  } 
}
