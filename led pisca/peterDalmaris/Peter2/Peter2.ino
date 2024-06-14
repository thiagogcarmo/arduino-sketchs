/*  04.010 - ESP32 Digital out blink LED example
 * 
 * This sketch shows you how to toggle the state of an LED using an ESP32.
 * 
 * This sketch was written by Peter Dalmaris using information from the 
 * ESP32 datasheet and examples.
 * 
 * 
 * Components
 * ----------
 *  - ESP32 Dev Kit v4
 *  - LED
 *  - 320 Ohm resistor
 *  
 *  IDE
 *  ---
 *  Arduino IDE with ESP32 Arduino Code 
 *  (https://github.com/espressif/arduino-esp32)
 *  
 *  
 *  Libraries
 *  ---------
 *  - None
 *  - 
 *
 * Connections
 * -----------
 *  
 *  ESP32 Dev Kit |     LED
 *  ------------------------------
 *        GND      |       Cathode
 *        GPIO32   |       Anode via resistor
 *     
 *  It is possible to use any other GPIO that can be configured as an output.
 *  This excludes GPIO 34, 35, 36, 37, 38, 39.
 *  
 *  Other information
 *  -----------------
 *  
 *  1. ESP32 Datasheet: https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf
 *  
 *  Created on March 14 2019 by Peter Dalmaris
 * 
 */
 

const byte LED1_GPIO = 32;
const byte LED2_GPIO = 33;
const byte LED3_GPIO = 26;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED1_GPIO, OUTPUT);
  pinMode(LED2_GPIO, OUTPUT);
  pinMode(LED3_GPIO, OUTPUT);


  
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED1_GPIO, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED2_GPIO, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED3_GPIO, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED1_GPIO, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED2_GPIO, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED3_GPIO, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
   digitalWrite(LED1_GPIO, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED2_GPIO, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED3_GPIO, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
}
