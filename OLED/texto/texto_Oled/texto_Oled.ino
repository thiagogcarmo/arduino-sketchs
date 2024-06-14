#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);//inicia o display com endereco padrao
  display.clearDisplay();//limpa a tela


  display.setTextColor(WHITE);//define o texto para branco (no display ficara azul)

  display.setTextSize(1);//define o tamanho do texto
  display.println("O estado de São Paulo aplicou hoje a primeira vacina contra a covid-19 em crianças de 5 a 11 anos em evento organizado pelo governador João Doria (PSDB) no Hospital das Clínicas, na região central da cidade de São Paulo. O início oficial da campanha, no entanto, está previsto para segunda-feira (17). A primeira vacina aplicada foi em Davi Seremramiwe Xavante, de 8 anos, que é indígena da etnia xavante e realiza tratamento médico para uma doença motora rara em São Paulo. Outras 14 crianças com comorbidade também receberam suas primeiras doses no mesmo local.... - Veja mais em https://noticias.uol.com.br/saude/ultimas-noticias/redacao/2022/01/14/governo-de-sao-paulo-comeca-hoje-a-vacinar-criancas-contra-covid-19.htm?cmpid=copiaecola");//escreve na tela a mensagem

//  display.setTextSize(3);
//  display.println("2018");
  display.display();//mostra as alteracoes no display, sem isso nao ira mostrar nada!!
  delay(5000);
  display.clearDisplay();
}

void loop()
{
  for (int8_t i = 0; i < 64; i++)
  {
    display.drawLine(0, 0, 128, i, WHITE);//desenha uma linha
    display.display();//mostra na tela
    delay(1);
  }

  for (int8_t i = 63; i > -1; i--)
  {
    display.drawLine(0, 0, 128, i, BLACK);
    display.display();
    delay(1);
  }
}
