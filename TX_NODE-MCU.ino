//Transmitter NODE MCU Code
//Pin D1 with A4 of Nano
//Pin D2 with A5 of Nano
//https://www.electronicwings.com/nodemcu/nodemcu-i2c-with-arduino-ide
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
                          
#define FIREBASE_HOST "smart-e-bike-8e856.firebaseio.com"                     //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "ba4qyfKBYBJTKQag2xGuUTJkQIRD3pgMkZ3OKtVz" //Your Firebase Database Secret goes here

#define WIFI_SSID "KD"                                               //WiFi SSID to which you want NodeMCU to connect
#define WIFI_PASSWORD "kdoshi@1810"                                      //Password of your wifi network 
 
  

// Declare the Firebase Data object in the global scope
FirebaseData firebaseData;

// Declare global variable to store value
int val=0;
String str="hello";

int noofscooter=2;
String bike_status[2]={"Inactive-1","Inactive-1"};


String path1="/Admin Id/016/vehicle/vehicle Id/001/status";
String path2="/Admin Id/016/vehicle/vehicle Id/002/status";

void fetchdata(){
  if(Firebase.get(firebaseData, path1))
  {
    
      Serial.print("data = ");
      Serial.println(firebaseData.stringData());
      if(firebaseData.stringData()=="Active")
      {
         Wire.beginTransmission(8); /* begin with device address 8 */
         Wire.write("Active1");  /* sends hello string */
         // Wire.write(*bike_status1[0]);
         Wire.endTransmission();    /* stop transmitting */
      }
      else
      {
        Wire.beginTransmission(8); /* begin with device address 8 */
        Wire.write("Inactive1");  /* sends hello string */
       // Wire.write(*bike_status1[0]);
        Wire.endTransmission();    /* stop transmitting */
      }
      delay(500);
  }else{
    Serial.print("Error in get, ");
    Serial.println(firebaseData.errorReason());
  }

  if(Firebase.get(firebaseData, path2))
  {
    
      Serial.print("data = ");
      Serial.println(firebaseData.stringData());
      if(firebaseData.stringData()=="Active")
      {
        Wire.beginTransmission(8); /* begin with device address 8 */
         Wire.write("Active2");  /* sends hello string */
         Wire.endTransmission();    /* stop transmitting */
      }
      else
      {
        Wire.beginTransmission(8); /* begin with device address 8 */
        Wire.write("Inactive2");  /* sends hello string */
       
        Wire.endTransmission();    /* stop transmitting */
      }
      delay(500);
  }else{
    Serial.print("Error in get, ");
    Serial.println(firebaseData.errorReason());
  }

}

void setup() { 
  Serial.begin(9600); /* begin serial for debug */
  Wire.begin(D1, D2); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */



  Serial.println("Serial communication started\n\n");  
           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   // connect to firebase

  Firebase.reconnectWiFi(true);
  delay(1000);
 
}

void loop() {
  fetchdata();
 
 
  /*Wire.beginTransmission(8); // begin with device address 8 
  Wire.write(*bike_status1[1]); 
  Wire.endTransmission();*/    // stop transmitting

   /*Wire.requestFrom(8, 13); // request & read data of size 13 from slave 
  while(Wire.available()){
      char c = Wire.read();
    Serial.print(c);
  }
 Serial.println();*/
 delay(500);
}
