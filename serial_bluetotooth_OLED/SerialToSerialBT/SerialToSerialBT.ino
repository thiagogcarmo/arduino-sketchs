//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

//#define SCREEN_WIDTH 128 // OLED display width, in pixels
//#define SCREEN_HEIGHT 64 // OLED display height, in pixels
//
//#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
//#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//bluetooth
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif


BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
//    String frase = (SerialBT.read());
//
//  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);//inicia o display com endereco padrao
//  display.clearDisplay();//limpa a tela
//
//
//  display.setTextColor(WHITE);//define o texto para branco (no display ficara azul)
//  int ascii_code_received = SerialBT.read();
//  display.setTextSize(1);//define o tamanho do texto
//  display.println(char(ascii_code_received));//escreve na tela a mensagem
//
////  display.setTextSize(3);
////  display.println("2018");
//  display.display();//mostra as alteracoes no display, sem isso nao ira mostrar nada!!
//  delay(20);
//  display.clearDisplay();
  }
}
