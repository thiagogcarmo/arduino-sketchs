/*
 WiFi Web Server LED Blink

 A simple web server that lets you blink an LED via the web.
 This sketch will print the IP address of your WiFi Shield (once connected)
 to the Serial monitor. From there, you can open that address in a web browser
 to turn on and off the LED on pin 5.

 If the IP address of your shield is yourAddress:
 http://yourAddress/H turns the LED on
 http://yourAddress/L turns it off

 This example is written for a network using WPA encryption. For
 WEP or WPA, change the Wifi.begin() call accordingly.

 Circuit:
 * WiFi shield attached
 * LED attached to pin 5

 created for arduino 25 Nov 2012
 by Tom Igoe

ported for sparkfun esp32 
31.01.2017 by Jan Hendrik Berlin
 
 */

#include <WiFi.h>

const char* ssid     = "ALPHA TANGO";
const char* password = "maris2318";

WiFiServer server(80);

void setup()
{
    Serial.begin(115200);
    pinMode(33, OUTPUT);      // set the LED pin mode

    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();

}

int value = 0;

void loop(){
 WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("ola! Aqui voce controla sua casa");
            client.print("<br>");
            client.print("<html>");
            client.print("<head>");
            client.print("<title)>Curso HTML5 Essencial</title>");
            client.print("<style>");
            client.print("                figure {float:right; margin-left:15px; border:1px solid #999; padding:3px; margin-bottom:10px;}");
            client.print(" figcaption { background: #ddd; font-family: sans-serif; font-size: 11px; padding: 3px;}");
            client.print("        </style>");
            client.print("    </head>");
            client.print("    <body>");
            client.print("        <h1>Cafe Fontenebleu</h1>");
            client.print("        <h2>Um ambiente agrad&aacute;vel</h2>");
            client.print("        <h3>Prato do dia</h3>");
            client.print("<p>Cafe Fontenebleu's visionary chef leads the way in a culinary revolution. Proclaimed by many to be the best chef in the world today, Chef Bienni blends earthy seasonal flavors and bold ingredients to create exquisite contemporary cuisine. </p> <p>The name Cafe Fontenebleu comes from our first restaurant, located in a historic building on Fontenebleu Street in San Francisco, where we opened the doors in 1985. We've replicated the elegant interior, exceptional service, and world-class cuisine in our restaurants around the country.</p> <p>Come dine with us tonight </p> <p>Cafe Fontenebleu features a magical combination of excellent cuisine and musical entertainment. The finest pasta, seafood, veal and certified Angus steaks are served to you by the most talented waiters anywhere. Nightly entertainment features favorites from Broadway musical theatre, Grand Opera, and Neapolitan folk songs performed by our talented musical staff. Cafe Fontenebleu offers the largest selection of Italian wines in California, and is the proud recipient of numerous awards from Wine Tasting Magazine. We were selected as one of Southern California Magazine's top 200 restaurants for the last 8 years!</p> <p>Cafe Fontenebleu restaurant is music to your ears, be it an intimate dinner for 2 or a banquet for up to 200.</p>");
            client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 5 on.<br>");
            client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 5 off.<br>");
            client.print("</html>");
            client.print("</body>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(33, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(33, LOW);                // GET /L turns the LED off
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
