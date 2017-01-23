int emotion = 3; //1 for angry;2 for happy; 3 for sad;

#include <FastLED.h>

#include <Wire.h>
#include <Adafruit_MPL115A2.h>
Adafruit_MPL115A2 mpl115a2;
float pressureKPA1 = 0, temperatureC1 = 0;
float pressureKPA2 = 0, temperatureC2 = 0;

#define TEMPERATURE_1 HighPressureSodium
#define TEMPERATURE_2 Candle
#define TEMPERATURE_3 ClearBlueSky
// How many seconds to show each temperature before switching
#define DISPLAYTIME 20
// How many seconds to show black between switches
#define BLACKTIME   3
#define LED_PIN     4
// Information about the LED strip itself
#define NUM_LEDS    2
#define CHIPSET     WS2812
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
#define BRIGHTNESS  64

int buttonstate = 0;
void setup()
{
  delay( 3000 ); // power-up safety delay
  // It's important to set the color correction for your LED strip here,
  // so that colors can be more accurately rendered through the 'temperature' profiles
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalSMD5050 );
  FastLED.setBrightness( BRIGHTNESS );
  mpl115a2.begin();

  pinMode(11, INPUT);//PUSH BUTTON
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);//
  pinMode(7, OUTPUT);//RESET SENSOR
  pinMode(8, OUTPUT);//RESET SENSOR
  pinMode(9, OUTPUT);//
  pinMode(10, OUTPUT);//

  Serial.begin(9600);
}
int i;
void loop()
{

  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  pressureKPA1 = mpl115a2.getPressure();

  Serial.print("Pressure A (kPa): ");
  Serial.print(pressureKPA1, 4);
  Serial.println(" kPa");
  temperatureC1 = mpl115a2.getTemperature();
  Serial.print("Temp A (*C): ");
  Serial.print(temperatureC1, 1);
  Serial.println(" *C");

  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  pressureKPA2 = mpl115a2.getPressure();
  Serial.print("Pressure B (kPa): ");
  Serial.print(pressureKPA2, 4);
  Serial.println(" kPa");
  temperatureC2 = mpl115a2.getTemperature();
  Serial.print("Temp B (*C): ");
  Serial.print(temperatureC2, 1);
  Serial.println(" *C");
  buttonstate = digitalRead(11);
  if (buttonstate == HIGH)
  {
    //*************angry***************************
    if (emotion == 1)
    {
      FastLED.setTemperature( TEMPERATURE_1 ); // first temperature
      leds[0] = TEMPERATURE_1;
      leds[1] = TEMPERATURE_1;
      FastLED.show();
      for (i = 0; i < 150; i++)
      {
        digitalWrite(9, LOW); // LEFT_DOWN
        digitalWrite(5, LOW); // RIGHT_DOWN
        digitalWrite(10, HIGH); //LEFT_UPPER
        digitalWrite(6, HIGH); // RIGHT_UPPER
        delay(20);
        digitalWrite(9, LOW);
        digitalWrite(5, LOW);
        digitalWrite(10, LOW);
        digitalWrite(6, LOW);
        delay(0);
      }
      for (i = 0; i < 30; i++)
      {
        digitalWrite(9, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(6, LOW);
        delay(20);
        digitalWrite(9, LOW);
        digitalWrite(5, LOW);
        digitalWrite(10, LOW);
        digitalWrite(6, LOW);
        delay(0);
      }
    }
    else if (emotion == 2)
    { //*************Happy*********************
      FastLED.setTemperature( TEMPERATURE_2 ); // first temperature
      leds[0] = TEMPERATURE_2;
      leds[1] = TEMPERATURE_2;
      FastLED.show();
      for (i = 0; i < 10; i++)
      {
        digitalWrite(9, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(6, LOW);
        delay(20);
        digitalWrite(9, LOW);
        digitalWrite(5, LOW);
        digitalWrite(10, LOW);
        digitalWrite(6, LOW);
        delay(0);
      }
      for (i = 0; i < 10; i++)
      {
        digitalWrite(9, LOW);
        digitalWrite(5, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(6, HIGH);
        delay(20);
        digitalWrite(9, LOW);
        digitalWrite(5, LOW);
        digitalWrite(10, LOW);
        digitalWrite(6, LOW);
        delay(0);
      }
    }
    else if (emotion == 3)    //*****************Sad***************************
    {
      FastLED.setTemperature( TEMPERATURE_3 ); // first temperature
      leds[0] = TEMPERATURE_3;
      leds[1] = TEMPERATURE_3;
      FastLED.show();
      for (i = 0; i < 200; i++)
      {
        digitalWrite(9, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(6, LOW);
        delay(20);
        digitalWrite(9, LOW);
        digitalWrite(5, LOW);
        digitalWrite(10, LOW);
        digitalWrite(6, LOW);
        delay(0);
      }
      for (i = 0; i < 50; i++)
      {
        digitalWrite(9, LOW);
        digitalWrite(5, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(6, HIGH);
        delay(20);
        digitalWrite(9, LOW);
        digitalWrite(5, LOW);
        digitalWrite(10, LOW);
        digitalWrite(6, LOW);
        delay(0);
      }
    }
  }
  else
  {
    digitalWrite(9, LOW);
    digitalWrite(5, LOW);
    digitalWrite(10, LOW);
    digitalWrite(6, LOW);
  }

}

