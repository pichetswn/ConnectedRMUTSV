//Add Library
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//Explicit
int myDelayTime = 1000;
int myOutput = D0;
int intIndex = 0;
int intSwitch = 0;

//การกำหนดค่าคงที่
//String wifiSSID = "MastreEWTC_2.4G";
#define wifiSSID "MastreEWTC_2.4G"
#define wifiPassword "12345abcde"


#define firebaseHost "rmutsvnodemcu-42a01.firebaseio.com"
#define firebaseKey "ztgDIjsGC8KYnXaqlA9XtjEeO1DGNkHzxT0zdjCL"



void setup() {
  
//  การทำหนดช่องทางในการ Monitore
  Serial.begin(9600);
  
//การกำหนดข้อมูลเกี่ยวกับการเชื่อมต่อ wifi
 WiFi.mode(WIFI_STA);
 WiFi.begin(wifiSSID,wifiPassword);
 Serial.println("Start Find WiFi");

 while (WiFi.status() != WL_CONNECTED) {

//  ถ้า Condition True จะทำงานที่นี่
 
  Serial.print("#");
  delay(myDelayTime);
  
  }

//  ถ้ามาทำงานตรงนี้คือ Conneted WiFi ได้แล้ว
  Serial.println();
  Serial.println("Sucess Connected WiFi");
  Serial.println(WiFi.localIP());

//ส่วนของการเชื่อมต่อ Firebase
  Firebase.begin(firebaseHost,firebaseKey);
  
 
} //setup

void loop() {
//  Serial.println("Hello Pichet SWN");
//  delay(2000);

//Check Connected Firebase
  Firebase.setInt("myTimes",intIndex);
  if(Firebase.failed()) 
    {
    
//      เมื่อไรก็ตามที่ไม่สามารถเข้า Firebase
        Serial.print("Cannot Connected Firebase : ");
        Serial.println(Firebase.error());
        return;
    }

        Serial.print("Success Connected Firebase Times ==> ");
        Serial.println(Firebase.getInt("myTimes"));

        intIndex = Firebase.getInt("myTimes");

        intIndex++;
        intSwitch = Firebase.getInt("Switch");

        if(intSwitch == 1)
          {
//            for myOutput
              digitalWrite(myOutput,LOW); // turn the LED on (HIGH is the voltage level
          }
          else
          {
            digitalWrite(myOutput,HIGH);
          }
          
        delay(myDelayTime);

  

} //loop
