#include "secrets.h"
#include <WiFi.h>
#include <HTTPClient.h>
 
const char* ssid = SID; //From secrets.h
const char* password = PWD; 
 
void setup() {

  //Delay needed before calling the WiFi.begin
  delay(4000);   
 
  WiFi.begin(ssid, password); 
  
  //Check for the connection
  while (WiFi.status() != WL_CONNECTED) { 
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
}
 
void loop() {
 
 //Check WiFi connection status
 if(WiFi.status()== WL_CONNECTED){   
 
   HTTPClient http; 

   String url = URL;
   url += Irms;
 
   http.begin(url);  //Specify destination for HTTP request
   http.addHeader("Content-Type", "application/json");             //Specify content-type header
 
   int httpResponseCode = http.PUT("POSTING from ESP32");   //Send the actual POST request
 
   if(httpResponseCode>0){
 
    String response = http.getString();                       //Get the response to the request

    Serial.println(Irms); 
    Serial.println(httpResponseCode);   //Print return code
    Serial.println(response);           //Print request answer
 
   }else{
 
    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);
 
   }
 
   http.end();  //Free resources
 
 }else{
 
    Serial.println("Error in WiFi connection");   
 
 }
 
  delay(10000);  //Send a request every 10 seconds
 
}
