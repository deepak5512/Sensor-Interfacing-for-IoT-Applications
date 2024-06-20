#include <SoftwareSerial.h>
#include <DHT.h>
#define DHTPIN 7
#define DHTTYPE DHT11

SoftwareSerial ESP8266(2, 3); // Rx,  Tx

DHT dht(DHTPIN, DHTTYPE);
  
long writingTimer = 17; 
long startTime = 0;
long waitTime = 0;

// const int sensor=A0; // Assigning analog pin A1 to variable 'sensor'
float tempc;  //variable to store temperature in degree Celsius
float humi;
// float vout;  //temporary variable to hold sensor reading
unsigned char check_connection=0;
unsigned char times_check=0;
boolean error;

String myAPIkey = "1MZ91RTGQ9Q9HACS";  //Your Write API Key from Thingsspeak

void setup()
{
  Serial.begin(9600); 
  ESP8266.begin(9600); 
  startTime = millis(); 
  delay(2000);
  Serial.println("Connecting to Wifi");
  while(check_connection==0)
  {
    Serial.print(".");
    ESP8266.print("AT+CWJAP=\"Deepak\",\"alkx6599\"\r\n");
    ESP8266.setTimeout(5000);
    if(ESP8266.find("WIFI CONNECTED\r\n")==1)
    {
      Serial.println("WIFI CONNECTED");
      dht.begin();
      break;
    }
    times_check++;
    if(times_check>3) 
    {
      times_check=0;
      Serial.println("Trying to Reconnect..");
    }
  }
}

void loop()
{
  waitTime = millis()-startTime;   
  if (waitTime > (writingTimer*1000)) 
  {
    delay(2000);
    // vout=analogRead(sensor);
    // vout=(vout*500)/1023;
    // tempc=vout; // Storing value in Degree Celsius
    // read humidity
    humi  = dht.readHumidity();
    // read temperature as Celsius
    tempc = dht.readTemperature();
    // read temperature as Fahrenheit
    float tempF = dht.readTemperature(true);
    if (isnan(humi) || isnan(tempc) || isnan(tempF)) {
      Serial.println("Failed to read from DHT sensor!");
    } else {
      Serial.print("Humidity:");
      Serial.print(humi);
      Serial.print(", ");
      // Serial.println("%");

      // Serial.println("  |  "); 

      Serial.print("Temperature:");
      Serial.print(tempc);
      Serial.println();
      // Serial.println("°C ~ ");
      // Serial.println(tempF);
      // Serial.println("°F");
    }
    writeThingSpeak();
    startTime = millis();  
  }
}

void writeThingSpeak(void)
{
  startThingSpeakCmd();
  // preparacao da string GET
  String getStr = "GET /update?api_key=";
  getStr += myAPIkey;
  getStr +="&field1=";
  getStr += String(tempc);
  getStr +="&field2=";
  getStr += String(humi);
  getStr += "\r\n\r\n";
  GetThingspeakcmd(getStr); 
}

void startThingSpeakCmd(void)
{
  ESP8266.flush();
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "184.106.153.149"; // api.thingspeak.com IP address
  cmd += "\",80";
  ESP8266.println(cmd);
  Serial.print("Start Commands: ");
  Serial.println(cmd);

  if(ESP8266.find("Error"))
  {
    Serial.println("AT+CIPSTART error");
    return;
  }
}

String GetThingspeakcmd(String getStr)
{
  String cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());
  ESP8266.println(cmd);
  Serial.println(cmd);

  if(ESP8266.find(">"))
  {
    ESP8266.print(getStr);
    Serial.println(getStr);
    delay(500);
    String messageBody = "";
    while (ESP8266.available()) 
    {
      String line = ESP8266.readStringUntil('\n');
      if (line.length() == 1) 
      { 
        messageBody = ESP8266.readStringUntil('\n');
      }
    }
    Serial.print("MessageBody received: ");
    Serial.println(messageBody);
    return messageBody;
  }
  else
  {
    ESP8266.println("AT+CIPCLOSE");     
    Serial.println("AT+CIPCLOSE"); 
  } 
}
