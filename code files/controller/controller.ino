#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH    128 
#define SCREEN_HEIGHT    64 
#define OLED_RESET       -1 
#define SCREEN_ADDRESS 0x3C 

int ADC1           = A0; // pin connected to 1st potentiometer
int ADC2           = A1; // pin connected to 2nd potentiometer
int ADC3           = A2; // pin connected to 3rd potentiometer
int BUTTON         = A6; // pin connected to button
int BUZZER         =  4; // pin connected to MOSFET that controls the piezo-buzzer
int LED_R          =  7; // pin connected to red indicator led
int LED_Y          =  6; // pin connected to yellow indicator led
int LED_G          =  5; // pin connected to green indicator led
int MOTOR          =  8; // pin connected to MOSFET that controls the vibration motor
int pulse_high_MIN =  0; // time in seconds
int pulse_high_MAX = 20; // time in seconds
int pulse_low_MIN  =  0; // time in seconds
int pulse_low_MAX  = 20; // time in seconds
int TIME_MIN       =  0; // time in minutes
int TIME_MAX       = 60; // time in minutes

int etcher_mode, pulse_high_time, pulse_low_time, etching_time, button_trigger, i;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // put your setup code here, to run once:
  pinMode(ADC1, INPUT);
  pinMode(ADC2, INPUT);
  pinMode(ADC3, INPUT);
  pinMode(BUTTON, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_Y, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(MOTOR, OUTPUT);
  Serial.begin(9600);
  etcher_mode = false;
  digitalWrite(BUZZER, LOW);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.display();
  delay(2000);

//  testdrawstyles();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(etcher_mode == false){
    digitalWrite(LED_Y, HIGH);                                                                
    digitalWrite(LED_G, LOW);
    digitalWrite(BUZZER, LOW);
    
    pulse_high_time = int((float(analogRead(ADC1))/1020.0)*(pulse_high_MAX - pulse_high_MIN)) + pulse_high_MIN;
    pulse_low_time = int((float(analogRead(ADC2))/1020.0)*(pulse_low_MAX - pulse_low_MIN)) + pulse_low_MIN;
    etching_time = int((float(analogRead(ADC3))/1020.0)*(TIME_MAX - TIME_MIN) + TIME_MIN)*60;
    
    Serial.print("pulse high time: ");
    Serial.print(pulse_high_time);
    Serial.print(" | pulse low time: ");
    Serial.print(pulse_low_time);
    Serial.print(" | etching time: ");
    Serial.println(etching_time);
    Serial.print("RAW ADC VALUES : ");
    Serial.print(analogRead(ADC1));
    Serial.print(" | ");
    Serial.print(analogRead(ADC2));
    Serial.print(" | ");
    Serial.println(analogRead(ADC3));
    Serial.println("");
    
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(0, 0);
    display.println("PCB ETCHER");
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE); 
    display.println("---------------------");
    display.print(" PULSE H TIME: ");
    if(pulse_high_time < 10){
      display.print("0");
    }
    display.print(pulse_high_time);
    display.println(" s");
    display.print(" PULSE L TIME: ");
    if(pulse_low_time < 10){
      display.print("0");
    }
    display.print(pulse_low_time);
    display.println(" s");
    display.print("    ETCH TIME: ");
    if(etching_time/60 < 10){
      display.print("0");
    }
    display.print(etching_time/60);
    display.println(" m");
    display.display();

    button_trigger = analogRead(BUTTON);
    if(button_trigger > 512){
      while(analogRead(BUTTON) > 512){}
      delay(50);
      etcher_mode = true;
      Serial.println("Button pressed...going into etching mode");
    }    
  }
  else{
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_Y, LOW);
    while(etching_time > 0){
//      if(button_trigger > 512){
//        while(analogRead(BUTTON) > 512){}
//        delay(50);
//        etcher_mode = false;
//        break;
//        Serial.println("Button pressed...going into setup mode");
//      }  
      Serial.println(etching_time);
      digitalWrite(MOTOR, HIGH); 
      for(i = 0; i < pulse_high_time; i++){
        etching_time = etching_time - 1;
        display.clearDisplay();
        display.setTextSize(2);
        display.setTextColor(SSD1306_WHITE); 
        display.setCursor(0, 0);
        display.print("TIME ");
        if(etching_time/60 < 10){
          display.print("0");
        }
        display.print(etching_time/60);
        display.print(":");
        if(etching_time%60 < 10){
          display.print("0");
        }
        display.print(etching_time%60);
//        display.println(" m");
        display.println();
        display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE); 
        display.println("");
        display.setTextSize(2);
        display.setTextColor(SSD1306_WHITE); 
        display.println("ETCHING IN");
        display.print(" PROGRESS");
        display.display();
        delay(1000);  
      }
      digitalWrite(MOTOR, LOW);
      for(i = 0; i < pulse_low_time; i++){
        etching_time = etching_time - 1;
        display.clearDisplay();
        display.setTextSize(2);
        display.setTextColor(SSD1306_WHITE); 
        display.setCursor(0, 0);
        display.print("TIME ");
        if(etching_time/60 < 10){
          display.print("0");
        }
        display.print(etching_time/60);
        display.print(":");
        if(etching_time%60 < 10){
          display.print("0");
        }
        display.print(etching_time%60);
//        display.println(" m");
        display.println();
        display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE); 
        display.println("");
        display.setTextSize(2);
        display.setTextColor(SSD1306_WHITE); 
        display.println("ETCHING IN");
        display.print(" PROGRESS");
        display.display();
        delay(1000);  
      }
      
    }
    digitalWrite(BUZZER, HIGH);
    while(analogRead(BUTTON) < 512){}
    while(analogRead(BUTTON) > 512){}
    digitalWrite(BUZZER, LOW);
    etcher_mode = false;
  }
}
