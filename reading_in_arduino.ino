 #include <SoftwareSerial.h>

// Create a software serial object to represent the connection between the ESP8266-01 and the Arduino Uno
SoftwareSerial esp8266(6,7); // RX, TX
#define RELAY_1_PIN 9
#define RELAY_2_PIN 10
#define RELAY_3_PIN 11
#define RELAY_4_PIN 12
char reading,value;

void setup() {
  // Initialize the serial communication panel of the connected PC

  // Initialize the software serial connection between the ESP8266-01 and the Arduino Uno
  esp8266.begin(19200);

  //set the relay pins to output mode
  pinMode(RELAY_1_PIN,OUTPUT);
  pinMode(RELAY_2_PIN,OUTPUT);
  pinMode(RELAY_3_PIN,OUTPUT);
  pinMode(RELAY_4_PIN,OUTPUT);
  digitalWrite(RELAY_1_PIN,HIGH); // turn off both relays before starting the loop
  digitalWrite(RELAY_2_PIN,HIGH);
  digitalWrite(RELAY_3_PIN,HIGH);
  digitalWrite(RELAY_4_PIN,HIGH);
}

// LOW LEVEL ACTIVATED RELAYS, if the appliance is ON , the relay input must be LOW
void loop() {

  if (esp8266.available()) 
 {
  reading=esp8266.read();

// LOOK FOR THE SPECIAL CHARACTER
  if (reading=='%'){
    reading=esp8266.read();

      delay(10);
    // check the state of RELAY 1
    if(reading=='a')
    {
      value=esp8266.read();
      if(value=='1'){
      digitalWrite(RELAY_1_PIN,LOW);
      }
      else if (value=='0'){
      digitalWrite(RELAY_1_PIN,HIGH);
      }
    }
  
     // check the state of RELAY 2
    else if (reading=='b')
    {
      value=esp8266.read();
      if(value=='1'){
      digitalWrite(RELAY_2_PIN,LOW);
      }
      else if (value=='0'){
      digitalWrite(RELAY_2_PIN,HIGH);
      }
    }
      // check the state of RELAY 3
     else if(reading=='c')
      {
        value=esp8266.read();
        if(value=='1'){
        digitalWrite(RELAY_3_PIN,LOW);
        }
        else if (value=='0'){
        digitalWrite(RELAY_3_PIN,HIGH);
        }
      }
            // check the state of RELAY 4
     else if(reading=='d')
      {
        value=esp8266.read();
        if(value=='1'){
        digitalWrite(RELAY_4_PIN,LOW);
        }
        else if (value=='0'){
        digitalWrite(RELAY_4_PIN,HIGH);
        }
      }

  }
 }
  delay(20);
}
