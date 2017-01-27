int emotion = 7; //1 for angry;2 for happy; 3 for sad; 4 for fear; 5 for disgust; 6 for Love; 7 for suprise

#include <FastLED.h>

#include <Wire.h>
#include <Adafruit_MPL115A2.h>
Adafruit_MPL115A2 mpl115a2;
float pressureKPA1 = 0, temperatureC1 = 0;
float pressureKPA2 = 0, temperatureC2 = 0;

//#define TEMPERATURE_1 HighPressureSodium
//#define TEMPERATURE_2 Candle
//#define TEMPERATURE_3 ClearBlueSky

#define LED_PIN     4 //Data for LED
// Information about the LED strip itself
#define NUM_LEDS    2
#define CHIPSET     WS2812
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
#define BRIGHTNESS  64

// int buttonstate = 0;
void setup()
{
  delay( 3000 ); // power-up safety delay
  // It's important to set the color correction for your LED strip here,
  // so that colors can be more accurately rendered through the 'temperature' profiles
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalSMD5050 );
  FastLED.setBrightness( BRIGHTNESS );
  
  mpl115a2.begin(); // Initiate Pressure sensors

 // pinMode(11, INPUT);//PUSH BUTTON
  pinMode(7, OUTPUT);//RESET SENSOR
  pinMode(8, OUTPUT);//RESET SENSOR
  
  pinMode(5, OUTPUT);// RIGHT_DOWN
  pinMode(6, OUTPUT);// RIGHT_UPPER
  pinMode(9, OUTPUT);//LEFT_DOWN
  pinMode(10, OUTPUT);//LEFT_UPPER

  Serial.begin(9600);
}
int i;
void loop()
{
  //Pressure sensor 1
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
  
  //Pressure sensor 2
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
  
  //buttonstate = digitalRead(11);
  

  
 if (Serial.available()) {
     emotion = Serial.read()-48;
     Serial.println(emotion);
  /*** 
  
  
  There should be a function to change the 'emotion' value state when Android calls the method in emotion class 
  
  
  ***/
   
  }
  
    switch(emotion)   //*************anger***************************
    {
      case 1:
      {
        Serial.println("Angry");
        
       
        for (i = 0; i < 150; i++)
        {
          leds[0] = CRGB::Red; 
          leds[1] = CRGB::Red; 
          FastLED.show();
          digitalWrite(9, LOW); // LEFT_DOWN
          digitalWrite(5, LOW); // RIGHT_DOWN
          digitalWrite(10, HIGH); //LEFT_UPPER
          digitalWrite(6, HIGH); // RIGHT_UPPER
          delay(20);
         
        }
        for (i = 0; i < 30; i++)
        {
          leds[0] = CRGB::Black;
          leds[1] = CRGB::Black;
          FastLED.show();
          digitalWrite(9, HIGH);
          digitalWrite(5, HIGH);
          digitalWrite(10, LOW);
          digitalWrite(6, LOW);
          delay(20);
         
        }
        for (i = 0; i < 150; i++)
        {
          leds[0] = CRGB::Red; 
          leds[1] = CRGB::Red; 
          FastLED.show();
          digitalWrite(9, LOW); // LEFT_DOWN
          digitalWrite(5, HIGH); // RIGHT_DOWN
          digitalWrite(10, HIGH); //LEFT_UPPER
          digitalWrite(6, LOW); // RIGHT_UPPER
          delay(20);
         
        }
        for (i = 0; i < 150; i++)
        {
           leds[0] = CRGB::Black;
          leds[1] = CRGB::Black;
          FastLED.show();
          digitalWrite(9, HIGH);
          digitalWrite(5, LOW);
          digitalWrite(10, LOW);
          digitalWrite(6, HIGH);
          delay(20);
         
        }
      }break;
      
      case 2: // *************Happy*********************
      {
        Serial.println("Happy");
        
        for (i = 0; i < 10; i++)
        {
          leds[0] = CRGB::Yellow; 
          leds[1] = CRGB::Yellow; 
          FastLED.show();
          digitalWrite(9, HIGH);
          digitalWrite(5, HIGH);
          digitalWrite(10, LOW);
          digitalWrite(6, LOW);
          delay(20);
          
        }
        for (i = 0; i < 10; i++)
        {
          leds[0] = CRGB::Black; 
          leds[1] = CRGB::Black; 
          FastLED.show();
          digitalWrite(9, LOW);
          digitalWrite(5, LOW);
          digitalWrite(10, HIGH);
          digitalWrite(6, HIGH);
          delay(20);
     
        }

      }break;
        
      case 3:  //*****************Sad***************************
      {
        Serial.println("Sad");
        leds[0] = CRGB::Blue; 
        leds[1] = CRGB::Blue;
        FastLED.show();
        for (i = 0; i < 200; i++)
        {
          digitalWrite(9, HIGH);
          digitalWrite(5, HIGH);
          digitalWrite(10, LOW);
          digitalWrite(6, LOW);
          delay(20);
          
        }
         for (i = 0; i < 5; i++)
        {
          digitalWrite(9, LOW);
          digitalWrite(5, LOW);
          digitalWrite(10, HIGH);
          digitalWrite(6, HIGH);
          delay(20);
          
        }
       
      }break;
      
      case 4: //*************Fear*********************
      {
        Serial.println("Fear");
      
        for (i = 0; i < 2; i++)
        {
            leds[0] = CRGB::DarkBlue; 
        leds[1] = CRGB::DarkBlue; // add dimming + blink 
        FastLED.show();
          digitalWrite(9, HIGH);
          digitalWrite(5, HIGH);
          digitalWrite(10, LOW);
          digitalWrite(6, LOW);
          delay(20);
          
        }
        for (i = 0; i < 5; i++)
        {
          leds[0] = CRGB::Black; 
           leds[1] = CRGB::Black;
           FastLED.show();
          digitalWrite(9, LOW);
          digitalWrite(5, LOW);
          digitalWrite(10, HIGH);
          digitalWrite(6, HIGH);
          delay(20);
     
        }
      }break;

      case 5:  //************disgust***********
      {
        Serial.println("Disgust");
        leds[0] = CRGB::Green;
        leds[1] = CRGB::Green; 
        FastLED.show();
         for (i = 0; i < 200; i++)
        {
          digitalWrite(9, HIGH);
          digitalWrite(5, HIGH);
          digitalWrite(10, LOW);
          digitalWrite(6, LOW);
          delay(20);
          
        }
        for (i = 0; i < 50; i++)
        {
          digitalWrite(9, LOW);
          digitalWrite(5, LOW);
          digitalWrite(10, HIGH);
          digitalWrite(6, HIGH);
          delay(20);
         
        }
        
        
      }break;

       case 6: //************suprise***********
      {
        Serial.println("Suprise");
         leds[0] = CRGB::White; 
         leds[1] = CRGB::White; // add blink 
         FastLED.show();  
        for (i = 0; i < 200; i++)
        {
          

          digitalWrite(9, LOW);
          digitalWrite(5, LOW);
          digitalWrite(10, HIGH);
          digitalWrite(6, HIGH);
          delay(20);
          
        }
        for (i = 0; i < 10; i++)
        {
          digitalWrite(9, HIGH);
          digitalWrite(5, HIGH);
          digitalWrite(10, LOW);
          digitalWrite(6, LOW);
          delay(20);
         
        }
        
      }break;

       default: // **************** steady state ********************
      {
        digitalWrite(9, LOW);
        digitalWrite(5, LOW);
        digitalWrite(10, LOW);
        digitalWrite(6, LOW);
      }
        
    }

}


