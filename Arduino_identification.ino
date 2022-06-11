#define LDR A0
#include<math.h>
int public_key = 7;
int sensorValue;
 void setup() {
  // put your setup code here, to run once:
 pinMode(LDR,INPUT);
 Serial.begin(9600);
 sensorValue = analogRead(LDR);
 Serial.println(sensorValue);
}

void loop() {
  // put your main code here, to run repeatedly:
  int bits[16];
  if(analogRead(LDR) > sensorValue + 150){
    for(int i=0;i<16;i++){
      delay(100);
    if(analogRead(LDR) > sensorValue + 150){
      bits[i] = 1;
    }
    else
    bits[i] = 0;
  }
   for(int i=0;i<16;i++){
    Serial.print(bits[i]);
    
 }
 int ans = 0;
 for(int i = 0;i<16;i++){
  ans+=pow(2,bits[i]);
 }
 Serial.println("The decrypted no is :");
 Serial.println(ans);
 int res = (ans + public_key)/2;
 Serial.println("The original message is");
 Serial.println(res); 
 } 
}
