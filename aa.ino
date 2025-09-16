//Include the library files
#include "FirebaseESP8266.h"  // Install Firebase ESP8266 library
#include <ESP8266WiFi.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define ssid  "Keah"
#define password  "744788fhjb"
#define firebase_host  "home-automation-system-dee72-default-rtdb.firebaseio.com"//firebase-project.firebaseio.com
#define firebase_auth "df4tHGlRylgNgRDwkzyKlRSL0aSMRfWVPVEfXEJu" //firebase-secret

//Define component pin
#define ldr A0
const int relay = 16;

FirebaseData firebaseData;
FirebaseData doorData;
FirebaseData bulbData;
FirebaseJson json;
Servo curtainServo; //curtain
LiquidCrystal_I2C lcd(0x27, 20, 4);
DHT dht(D3, DHT22);

void setup(){
  Serial.begin(9600); // serial communication
  lcd.begin();
  dht.begin();
  pinMode(ldr,INPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  curtainServo.attach(13); //D7
  curtainServo.write(0);

  //Connect NodeMCU to a WiFi
  WiFi.begin(ssid, password);
  //Replace SSID with the SSID of our router and p@ssword with the router password.
  while (WiFi.status()!= WL_CONNECTED){
    delay(1000);
    Serial.println("Connecting to WiFi...");  
  }
  Serial.println("Connected to WiFi!");
  //Connect to Firebase
  Firebase.begin(firebase_host, firebase_auth);
  Firebase.reconnectWiFi(true);
  Serial.println("Connected to Firebase!");
  Serial.println("----------------------");
  Serial.println("Home Automation System");
  Serial.println("----------------------");
}


void loop(){

  //door
  Firebase.getString(doorData, "/IOT/door");
  Firebase.getString(bulbData, "/IOT/bulb");
      if(doorData.stringData() == "0"){
        Serial.println("Door Locked");
        lcd.setCursor(4, 3);
        lcd.print("Door Locked");
        //doorServo.write(0);
      }
      else if (doorData.stringData() == "1"){
        Serial.println("Door Unlock");
        lcd.setCursor(4, 3);
        lcd.print("Door Unlock");
      }
 
  //bulb
      if(bulbData.stringData() == "0"){
          Serial.println("Bulb Off");
          digitalWrite(relay, HIGH);
      }
      else if (bulbData.stringData() == "1"){
          Serial.println("Bulb On");
          digitalWrite(relay, LOW);
      }
  

  //ldr
  int ldrval=analogRead(ldr);
  Serial.print("LI: ");  
  Serial.print(ldrval);  
  Serial.println("lux");
  Firebase.setInt(firebaseData, "/IOT/light", ldrval);
  lcd.setCursor(0,1);
  lcd.print("LI: ");
  lcd.print(ldrval);
  lcd.print("lux");
  if(ldrval <= 800){  //dark
    Serial.println("It's DARK,curtain is close");
    curtainServo.write(180);
    Firebase.setString(firebaseData, "/IOT/curtain", "CLOSED");
    lcd.setCursor(0, 2);
    lcd.print("DARK,curtain close");
    digitalWrite(relay, LOW); // Turn the relay on (bulb)
    Firebase.setString(firebaseData, "/IOT/bulb", "1");
  }
  else if(ldrval > 800){  //bright
    Serial.println("It's BRIGHT,curtain is open");
    curtainServo.write(0);
    Firebase.setString(firebaseData, "/IOT/curtain", "OPEN");
    lcd.setCursor(0, 2);
    lcd.print("BRIGHT,curtain open");
    digitalWrite(relay, HIGH); // Turn the relay off (bulb)
    Firebase.setString(firebaseData, "/IOT/bulb", "0");
  }

  // dht22
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Humidity: ");  
  Serial.print(h);  
  Serial.println("%");
  Firebase.setInt(firebaseData, "/IOT/humidity", h);
  lcd.setCursor(0, 0);
  lcd.print("H: ");
  lcd.print(h);
  lcd.print("%");
  Serial.print("Temperature: ");  
  Serial.print(t);  
  Serial.println("*C");
  Firebase.setInt(firebaseData, "/IOT/temperature", t);
  lcd.setCursor(10,0);
  lcd.print("T: ");
  lcd.print(t);
  lcd.print("*C");

}
