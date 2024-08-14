/*
 * 
 * Author : EREN MERT YİĞİT
 * 14.08.2024
 * 
 * Nextion 8048t070 display with DH21 AM2301
 * 
 * 
 * 
 */

#include <dht.h>
dht DHT;
//Constants
#define DHT21_PIN 2     //(AM2302) - what pin we're connected to

//Variables
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
    Serial.begin(9600); //COMMUNİCCATİON START
}

void loop()
{
    int chk = DHT.read21(DHT21_PIN);
    //Read data and store it to variables hum and temp
    hum = DHT.humidity;
    temp= DHT.temperature;

    delay(2000);

     /* Send tempreture reading as number n0 to the display */
  Serial.print("n0.val=");
  Serial.print((uint8_t)temp);
  
  Serial.write(0xff);        //Have to print 0xff 0xff 0xff in a string to nextion to get the data.
  Serial.write(0xff);
  Serial.write(0xff);
  
    /* Send humidty reading as number n0 to the display */
  Serial.print("n1.val=");
  Serial.print((uint8_t)hum);

  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  

  /*Display HOT! Musn't fly in this high tempreture error after 38 Degree */
  if(temp>38)
 {
  //Changes numbers and texts colors according to state
  Serial.print("n0.pco=63488");
  Serial.write(0xff);  
  Serial.write(0xff);  
  Serial.write(0xff);

  Serial.print("t0.txt=");
  Serial.print("\"");
  Serial.print("Hot! Musnt Fly");
  Serial.print("\"");
  Serial.write(0xff);  
  Serial.write(0xff);  
  Serial.write(0xff);

  Serial.print("t0.pco=63488");
  Serial.write(0xff);  
  Serial.write(0xff);  
  Serial.write(0xff);

  Serial.print("n1.pco=63488");
  Serial.write(0xff);  
  Serial.write(0xff);  
  Serial.write(0xff);
 }
 else
 {

  Serial.print("n0.pco=1024");
  Serial.write(0xff);  
  Serial.write(0xff);  
  Serial.write(0xff);
  
  Serial.print("t0.txt=");
  Serial.print("\"");
  Serial.print("Good to Fly");
  Serial.print("\"");
  Serial.write(0xff);  
  Serial.write(0xff);  
  Serial.write(0xff);

  Serial.print("n1.pco=63488");
  Serial.write(0xff);  
  Serial.write(0xff);  
  Serial.write(0xff);

  Serial.print("t0.pco=1024");
  Serial.write(0xff);  
  Serial.write(0xff);  
  Serial.write(0xff);
 }
 
if(hum > 90)
{
  Serial.print("n1.pco=63488");
  Serial.write(0xff);  
  Serial.write(0xff);  
  Serial.write(0xff);
}
else
{
  Serial.print("n1.pco=1024");
  Serial.write(0xff);  
  Serial.write(0xff);  
  Serial.write(0xff);  
}
  Serial.println("");
  delay(500);

//Refresh the value datas every cycle to update on the screen
  Serial.print("ref n0");
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);

  Serial.print("ref n1");
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}
