#include <Colorduino.h>

#define BUTTON_LEFT_PIN 2
#define BUTTON_RIGHT_PIN 5

PixelRGB COLOR_BLACK = {0, 0, 0};
PixelRGB COLOR_RED = {255, 0, 0};
PixelRGB COLOR_GREEN = {0, 255, 0};
PixelRGB COLOR_BLUE = {0, 0, 255};

PixelRGB pic_winner[ColorduinoScreenWidth][ColorduinoScreenHeight] = {
  {COLOR_BLACK, COLOR_BLACK, COLOR_GREEN, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_GREEN, COLOR_BLACK}, 
  {COLOR_BLACK, COLOR_GREEN, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_GREEN, COLOR_GREEN}, 
  {COLOR_GREEN, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_GREEN, COLOR_BLACK}, 
  {COLOR_GREEN, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_GREEN, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK}, 
  {COLOR_GREEN, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_GREEN, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK}, 
  {COLOR_GREEN, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_GREEN, COLOR_BLACK}, 
  {COLOR_BLACK, COLOR_GREEN, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_GREEN, COLOR_GREEN}, 
  {COLOR_BLACK, COLOR_BLACK, COLOR_GREEN, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_GREEN, COLOR_BLACK},
};

PixelRGB pic_loser[ColorduinoScreenWidth][ColorduinoScreenHeight] = {
  {COLOR_RED, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_RED, COLOR_BLACK}, 
  {COLOR_BLACK, COLOR_RED, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_RED, COLOR_RED}, 
  {COLOR_BLACK, COLOR_BLACK, COLOR_RED, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_RED, COLOR_BLACK}, 
  {COLOR_BLACK, COLOR_BLACK, COLOR_RED, COLOR_BLACK, COLOR_RED, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK}, 
  {COLOR_BLACK, COLOR_BLACK, COLOR_RED, COLOR_BLACK, COLOR_RED, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK}, 
  {COLOR_BLACK, COLOR_BLACK, COLOR_RED, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_RED, COLOR_BLACK}, 
  {COLOR_BLACK, COLOR_RED, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_RED, COLOR_RED}, 
  {COLOR_RED, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, COLOR_RED, COLOR_BLACK}, 
};

void displayPixelRGBData(PixelRGB pic[ColorduinoScreenWidth][ColorduinoScreenHeight])
{
  int w, h, p;
  for(w = 0; w < ColorduinoScreenWidth; w++){
    for(h = 0; h < ColorduinoScreenHeight; h++){
      Colorduino.SetPixel(w, h, pic[w][h].r, pic[w][h].g, pic[w][h].b);
    }
  }
  Colorduino.FlipPage();
}

void setup()
{
  pinMode(BUTTON_LEFT_PIN, INPUT);
  pinMode(BUTTON_RIGHT_PIN, INPUT);
  
  Serial.begin(57600);
  
  Colorduino.Init();
  // R, G, B, value is between 0~63
  unsigned char whiteBalVal[3] = {36,63,63};
  Colorduino.SetWhiteBal(whiteBalVal);
}

void loop()
{
  int button_left_status = digitalRead(BUTTON_LEFT_PIN);
  int button_right_status = digitalRead(BUTTON_RIGHT_PIN);
  if(button_left_status == HIGH){
    Serial.println("Left button pressed");
  }
  if(button_right_status == HIGH){
    Serial.println("Right button pressed");
  }
  
  displayPixelRGBData(pic_loser);
  delay(1000);
  displayPixelRGBData(pic_winner);
  delay(1000);
}

