#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


#define BLYNK_TEMPLATE_ID "TMPL3R7us97-X"
#define BLYNK_TEMPLATE_NAME "espFlush"
#define BLYNK_AUTH_TOKEN "QKmIZ-GgVbcxaO4_gp2kyYqEhS7mLz5c"
//toilet wala code

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "laptop";
char pass[] = "12345678";



int command_flush = D0, occupied_input = D4;

// This function creates the timer object. It's part of Blynk library 
BlynkTimer timer;
void myTimer() 
{
  // This function describes what will happen with each timer tick
  // e.g. writing sensor value to datastream V1


  //wait feature a min this wont work since arduino outputs 5V while nodeMCU works on 3.3V!!!!!!!!!!!!!!!!!!!!!
  // imp I forgot to put digitalRead() before!!!!
  if(digitalRead(occupied_input)==HIGH){
    Blynk.virtualWrite(V1, 1); //1 means high means LED is on in the espFlush device
    Serial.println("Occupied");
  }
  else{
    Blynk.virtualWrite(V1, 0);
    Serial.println("Occupied else");
  }

}





BLYNK_WRITE(V0) 
{
  if(param.asInt()==1){
    digitalWrite(command_flush, HIGH);
    delay(1000);
    digitalWrite(command_flush, LOW);
  }
}

void setup() {
  // Debug console
  Serial.begin(9600);
  pinMode(command_flush, OUTPUT);
  pinMode(occupied_input, INPUT);



  // Setup WiFi network
  WiFi.begin(ssid, pass);

  // Setup Blynk
  Blynk.config(BLYNK_AUTH_TOKEN);
  while (Blynk.connect() == false) {
   Serial.print(".");
  }

  // Setting interval to send data to Blynk Cloud to 1000ms. 
  // It means that data will be sent every second
  timer.setInterval(100L, myTimer); 


}



void loop() {

  Blynk.run();
  //wait feature a min this wont work since arduino outputs 5V while nodeMCU works on 3.3V!!!!!!!!!!!!!!!!!!!!!
  timer.run();
  
}
