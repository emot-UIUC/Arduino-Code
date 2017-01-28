const int ANGRY = 1;
const int HAPPY = 2;
const int SAD = 3;
const int FEAR = 4;
const int DISGUST = 5;
const int SUPRISE = 6;
const int RANDOM = 7;
const int NO_MOTION = 0; 

#define RIGHT_BOTTOM 5
#define RIGHT_UPPER 6
#define LEFT_BOTTOM 9
#define LEFT_UPPER 10

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
  
  pinMode(RIGHT_BOTTOM, OUTPUT);
  pinMode(RIGHT_UPPER, OUTPUT);
  pinMode(LEFT_BOTTOM, OUTPUT);
  pinMode(LEFT_UPPER, OUTPUT);

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
     state = Serial.read()-48;
     Serial.println(state);
  /*** 
  
  
  There should be a function to change the 'emotion' value state when Android calls the method in emotion class 
  
  
  ***/
   
  }
  
    switch(state)   //*************anger***************************
    {
      case ANGRY:
      {
        Serial.println("Angry");
        
          leds[0] = CRGB::Red; 
          leds[1] = CRGB::Red; 
          FastLED.show();
          leftUp();
          rightUp();
          delay(2000);
          
          leds[0] = CRGB::Black; 
          leds[1] = CRGB::Black; 
          FastLED.show();
          leftDown();
          rightDown();
          delay(220);
          
       }

        

      break;
      
      case HAPPY: // *************Happy*********************
      {
        Serial.println("Happy");
          
          leds[0] = CRGB::Yellow; 
          leds[1] = CRGB::Yellow; 
          FastLED.show();
          leftDown();
          rightDown();
          delay(200);
       
          leftUp();
          rightUp();
          delay(200);
     
       

      }break;
        
      case SAD:  //*****************Sad***************************
      {
        Serial.println("Sad");
       
          leds[0] = CRGB::Blue; 
          leds[1] = CRGB::Blue; 
          FastLED.show();
          leftDown();
          rightDown();
          delay(4000);
      
          leftUp();
          rightUp();
          delay(100);
          
       
       
      }break;
      
      case FEAR: //*************Fear*********************
      {
        Serial.println("Fear");
        
         leds[0] = CRGB::Black; 
         leds[1] = CRGB::Black; 
         FastLED.show();
         leftUp();
         rightUp();
         delay(40);
        
         leds[0] = CRGB::DarkBlue; 
         leds[1] = CRGB::DarkBlue; 
         FastLED.show();
         leftDown();
         rightDown();
         delay(100);
     
      }break;

      case DISGUST:  //************disgust***********
      {
        Serial.println("Disgust");
      
          leds[0] = CRGB::Green;
          leds[1] = CRGB::Green; 
          FastLED.show();
          leftDown();
          rightDown();
          delay(4000);
          
          leftUp();
          rightUp();
          delay(1000);
         
      }break;

       case SUPRISE: //************suprise***********
      {
          Serial.println("Suprise");
          leds[0] = CRGB::White; 
          leds[1] = CRGB::White; 
          FastLED.show();  
        
          leftUp();
          rightUp();
          delay(4000);

          leds[0] = CRGB::Black; 
          leds[1] = CRGB::Black; // add blink 
          FastLED.show();  
          leftDown();
          rightDown();
          delay(200);
         
      }break;

       case RANDOM: // **************** Random Motion ********************
      {
          leftUp();
          rightUp();
          delay(1000);
         
          leftDown();
          rightDown();
          delay(600);
   
          leftSteady();
          rightSteady();
          delay(2500);
      
          leftUp();
          rightDown();
          delay(1600);
    
          leftDown();
          rightUp();
          delay(1600);
        
      }break;
      
      case NO_MOTION:
      {
           leftSteady();
           rightSteady();
        
      }break;
     }
        

}

void leftUp(){

          digitalWrite(LEFT_BOTTOM, LOW);
          digitalWrite(LEFT_UPPER, HIGH);
}

void leftDown(){
  
          digitalWrite(LEFT_BOTTOM, HIGH);
          digitalWrite(LEFT_UPPER, LOW);
         
}

void leftSteady(){
          digitalWrite(LEFT_BOTTOM, LOW);
          digitalWrite(LEFT_UPPER, LOW);
}

void rightUp(){
        digitalWrite(RIGHT_UPPER, HIGH);
        digitalWrite(RIGHT_BOTTOM, LOW);
}

void rightDown(){
  
        digitalWrite(RIGHT_UPPER, LOW);
        digitalWrite(RIGHT_BOTTOM, HIGH);
}

void rightSteady(){
  
          digitalWrite(RIGHT_BOTTOM, LOW);
          digitalWrite(RIGHT_UPPER, LOW);
}
          

