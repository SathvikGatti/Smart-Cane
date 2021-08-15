#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "project1-1e686.firebaseio.com"
#define FIREBASE_AUTH "aqPVFPrRt9ZTLjk0WjKffdQD0eANB720nrrm2i6a"
#define WIFI_SSID "wifi"
#define WIFI_PASSWORD "9972611578"
int trig1=D0;
int echo1 =D1;
int SP=D2;
int Buzz=D4;
int Standby=D5;
int echo2=D6;
int trig2=D7;
int smoke=A0;
void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(SP, INPUT);
  pinMode(Buzz, OUTPUT);
  pinMode(Standby, INPUT);
  pinMode(echo2,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(smoke,INPUT);
}

void loop() {
  Serial.print("Standby mode:");
  Serial.println(digitalRead(Standby));
  if(digitalRead(Standby)==1)
  {
  while(digitalRead(Standby)==1)
  {
    delay(500);
  }
  }
  
  USC_1();
  USC_2();
  Dsmoke();
  //Serial.print("Emergency:");
  //Serial.println(digitalRead(SP));
  if (digitalRead(SP) == HIGH)
  {
    Firebase.set("PUSHBUTTON", 1);
    for (int i = 1; i <= 5; i++)
    {
      digitalWrite(Buzz, HIGH);
      delay(50);
      digitalWrite(Buzz, LOW);
      delay(20);
    }
  }
  else
  {
    Firebase.set("PUSHBUTTON", 0);
    digitalWrite(Buzz, LOW);
  }
  Serial.println("***********************************************************");
  
}
void USC_1()
{
  int distance1;
  int duration1;
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  duration1 = pulseIn(echo1, HIGH);
  distance1 = duration1 / 58.2;
 // Serial.print("DISTANCE1 : ");
 // Serial.println(distance1);
  Firebase.set("distance", distance1);
}
void USC_2()
{
  int distance2;
  int duration2;
   digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  duration2 = pulseIn(echo2, HIGH);
  distance2 = duration2/58.2;
  Firebase.set("distance2", distance2);
 // Serial.print("Distance2 : ");
 // Serial.println(distance2);
}
void smoke()
{
  int smokeLive=analogRead(smoke);
  if(smokeLive<=300) Firebase.set("SMOKE", 1);
  else Firebase.set("SMOKE",0);
}
