#include <WiFi.h>
#include "time.h"

const char* ssid       = "ALPHA TANGO";
const char* password   = "maris2318";

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 0;
const int   daylightOffset_sec = 10800;//3600You need to adjust the UTC offset for your timezone in milliseconds. Refer the list of UTC time offsets. Here are some examples for different timezones:
                                        //For UTC -5.00 : -5 * 60 * 60 : -18000
                                        //For UTC +1.00 : 1 * 60 * 60 : 3600
                                        //For UTC +0.00 : 0 * 60 * 60 : 0
                                        //https://lastminuteengineers.com/esp32-ntp-server-date-time-tutorial/

void printLocalTime()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

void setup()
{
  Serial.begin(115200);
  
  //connect to WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println(" CONNECTED");
  
  //init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();

  //disconnect WiFi as it's no longer needed
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

void loop()
{
  delay(1000);
  printLocalTime();
}
