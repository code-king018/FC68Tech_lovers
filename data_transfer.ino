int sensorValue;
#define RELAY 7
#define LDR A0
void setup() {
  // put your setup code here, to run once:
pinMode(LDR,INPUT);
pinMode(RELAY,OUTPUT);
sensorValue = analogRead(A0);
Serial.begin(9600);//LDR Module
Serial.println(sensorValue);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RELAY,HIGH); 
//  int reading = analogRead(LDR);
  int bits[32];
  int check = 0;
  char pass[32] = "11101110100010100010111010001010"; //encoded version of giri using the morse code detection 
if(analogRead(LDR) > sensorValue + 10)
{
  delay(100);
    for (int i = 0; i < 32; i++) {
      if (analogRead(LDR) > sensorValue + 10) { 
        bits[i] = 1;
      }
      else {
        bits[i] = 0;
      }
      delay(100);
    }

    for (int i = 0; i < 32; i++) {
      Serial.print(bits[i]);
    }
//       if()
    Serial.println("");
    //checking 
    for(int i = 0; i<32 ;i++)
    {
      if(bits[i]== pass[i]-'0')
      check = 1;
      else{
      check = 0;
      break;
      }
    }
    if(check == 1)
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
