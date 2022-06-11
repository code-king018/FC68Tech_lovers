#define LDR A0 //A0 is analog receiver
#define THRESHOLD 800  // for the solar panel the value is THRESHOLD is 150
#define RELAY 7  
int pass1[32];
int sensorValue;
#include<string.h>

void setup(){
  pinMode(LDR,INPUT); 
  pinMode(RELAY,OUTPUT);
  sensorValue = analogRead(A0);
  Serial.begin(9600);//LDR Module
  Serial.println(sensorValue);
}
//
void loop() {
  digitalWrite(RELAY,HIGH); 
  int reading = analogRead(LDR);
  char bits[32];
  int check;
  int check1 = 0;
  int compare;
  char pass[32] = "11101110100010100010111010001010"; //encoded message for giri using the morse code giri
//  static char pass1[32]; 
  if (reading > THRESHOLD ) {
    delay(100);
    for (int i = 0; i < 32; i++) {
      if (analogRead(LDR) > THRESHOLD) { 
        bits[i] = '1';
      }
      else {
        bits[i] = '0';
      }
      delay(100);
    }
   
   for (int i = 0; i < 32; i++) {
      Serial.print(bits[i]);
    }
    
  char passchange[32] = "10111011101000101110001010100010"; //32 bit code for changing the password - morse code for "pase" in light pattern in the app 
  for(int i = 0;i<32;i++)
  {
    if(passchange[i]==bits[i])
    compare = 1;
    else{
    compare = 0;
    break;
    }
  }
  Serial.println(compare);
   if(compare == 1)
   {
     Serial.println("change the password\n");
     for(;;){
     if (analogRead(LDR) > THRESHOLD ) {
      delay(100);
    for (int i = 0; i < 32; i++) {
      if (analogRead(LDR) > THRESHOLD) { 
        bits[i] = '1';
      }
      else {
        bits[i] = '0';
      }
      delay(100);
    }
    break;
   }
  }
   Serial.println("your password has changed!");
    for(int i = 0;i < 32;i++)
    {
      pass1[i] = bits[i]-'0';
    }
    for(int i = 0; i < 32; i++) {
      Serial.print(pass1[i]);
    }
   }
   
    //checking 
   for(int i = 0;i<32;i++)
  {
    if(pass[i]==bits[i])
    check = 1;
    else{
    check = 0;
    break;
    }
  }
  for(int i = 0;i<32;i++)
  {
    if(pass1[i]==bits[i]-'0')
    check1 = 1;
    else{
    check1 = 0;
    break;
    }
  }
    // changed password "pu" - 101110111010001010111000000000000
    Serial.println(check);
    Serial.println(check1);
    if(check == 1 || check1 == 1)
  {
    digitalWrite(RELAY,LOW);
    delay(5000);
    digitalWrite(RELAY,HIGH);
  }
  else
  {
     digitalWrite(RELAY,HIGH);
  }
  }
  }
