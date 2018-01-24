//Add Library
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//Explicit

//การกำหนดค่าคงที่
//String wifiSSID = "MastreEWTC_2.4G";
#define wifiSSID "MastreEWTC_2.4G"
#define wifiPassword "12345abcde"


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
  delay(500);
  
  }

//  ถ้ามาทำงานตรงนี้คือ Conneted WiFi ได้แล้ว
  Serial.println();
  Serial.println("Sucess Connected WiFi");
  Serial.println(WiFi.localIP());

} //setup

void loop() {
//  Serial.println("Hello Pichet SWN");
//  delay(2000);

  

} //loop
