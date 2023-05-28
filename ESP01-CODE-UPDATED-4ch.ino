#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
const char ssid[] = "Mustafa's Phone";  // your network SSID (name)
const char pass[] = "02331570707";   // your network password         
WiFiClient  client;

//---------Channel Details---------//
unsigned long channelNumber = 1977416;            // Channel ID
const char * myReadAPIKey = "25F2V1JYX4A25K0G"; // Read API Key
const int FieldNumber1 = 1;  // The field you wish to read
const int FieldNumber2 = 2;  // The field you wish to read
const int FieldNumber3 = 3;  // The field you wish to read
const int FieldNumber4 = 4;  // The field you wish to read
long statusCode;



void setup()
{
  Serial.begin(19200);
  WiFi.mode(WIFI_OFF);
  delay(1000);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop()
{
  //----------------- Network -----------------//
  if (WiFi.status() != WL_CONNECTED)
  {
    while (WiFi.status() != WL_CONNECTED)
    {
      Serial.println("connecting to Wi-Fi ..");
      WiFi.mode(WIFI_OFF);
      delay(1000);
      WiFi.mode(WIFI_STA);
      WiFi.begin(ssid,pass);
      delay(5000);
    }
  }

  //---------------- Field 1 ----------------//
  long a = ThingSpeak.readLongField(channelNumber, FieldNumber1, myReadAPIKey);
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200)
  {
    Serial.print("%a");
    Serial.println(a);
  }
  else
  {
    Serial.println("NO");
  }
  delay(100);
  //-------------- End of Field 1 -------------//

  //---------------- Field 2 ----------------//
  long b = ThingSpeak.readLongField(channelNumber, FieldNumber2, myReadAPIKey);
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200)
  {
    Serial.print("%b");
    Serial.println(b);
  }
  else
  {
    Serial.println("NO");
  }
  delay(100);
  //-------------- End of Field 2 -------------//

    //---------------- Field 3 ----------------//
  long c = ThingSpeak.readLongField(channelNumber, FieldNumber3, myReadAPIKey);
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200)
  {
    Serial.print("%c");
    Serial.println(c);
  }
  else
  {
    Serial.println("NO");
  }
  delay(100);
  //-------------- End of Field 3 -------------//

    //---------------- Field 4 ----------------//
  long d = ThingSpeak.readLongField(channelNumber, FieldNumber4, myReadAPIKey);
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200)
  {
    Serial.print("%d");
    Serial.println(d);
  }
  else
  {
    Serial.println("NO");
  }
  delay(100);
  //-------------- End of Field 4 -------------//
}
