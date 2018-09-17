//Name:         arduinoSmartCity
//Description:  Testbench simulating a smart city using Arduino, LDR Light sensors, traffic lights LEDs, CO2 sensr
//Author:       David Velasquez
//Date:         12/09/2018

//Library definition
#include <Wire.h> //Library required for I2C comms (LCD)
#include <LiquidCrystal_I2C.h>  //Library for LCD display via I2C
#include <math.h> //Mathematics library for pow function (CO2 computation)

//I/O pin labeling
#define LDR1 0 //LDR Light sensor from traffic light 1 connected in pin A0
#define LDR2 1  //LDR Light sensor from traffic light 2 connected in pin A1
#define CO2 3  //CO2 sensor connected in pin A3
#define P1 37  //Traffic light 1 button connected in pin 37
#define P2 36  //Traffic light 2 button connected in pin 36
#define CNY1 35 //Infrared sensor 1 in traffic light 1 connected in pin 35
#define CNY2 34 //Infrared sensor 2 in traffic light 1 connected in pin 34
#define CNY3 33 //Infrared sensor 3 in traffic light 1 connected in pin 33
#define CNY4 32 //Infrared sensor 4 in traffic light 2 connected in pin 32
#define CNY5 31 //Infrared sensor 5 in traffic light 2 connected in pin 31
#define CNY6 30 //Infrared sensor 6 in traffic light 2 connected in pin 30
#define LR1 22 //Red traffic light 1 connected in pin 22
#define LY1 23 //Yellow traffic light 1 connected in pin 23
#define LG1 24 //Green traffic light 1 connected in pin 24
#define LR2 25 //Red traffic light 2 connected in pin 25
#define LG2 26 //Green traffic light 2 connected in pin 26
#define LY2 27 //Yellow traffic light 2 connected in pin 27


//Constant definitions
//->CO2
const float DC_GAIN = 8.5;  //define the DC gain of amplifier CO2 sensor
//const float ZERO_POINT_VOLTAGE = 0.4329; //define the output of the sensor in volts when the concentration of CO2 is 400PPM
const float ZERO_POINT_VOLTAGE = 0.265; //define the output of the sensor in volts when the concentration of CO2 is 400PPM
const float REACTION_VOLTAGE = 0.059;   //define the “voltage drop” of the sensor when move the sensor from air into 1000ppm CO2
const float CO2Curve[3] = {2.602, ZERO_POINT_VOLTAGE, (REACTION_VOLTAGE / (2.602 - 3))}; //Line curve with 2 points

//Variable definitions
char comm = '\0'; //Command to test an actuator or sensor

//Library definitions
LiquidCrystal_I2C lcd(0x27, 16, 2); //Set the LCD address to 0x27 for a 16 chars and 2 line display

//Subroutines and functions
void testAnalogSenAct(char in) {
  switch (in) {
    case 'A':
      Serial.println("LDR1: " + String(analogRead(LDR1)));
      break;
    case 'B':
      Serial.println("LDR2: " + String(analogRead(LDR2)));
      break;
    case 'C':
      float volts = analogRead(CO2) * 5.0 / 1023.0;  //Convert CO2 ADC to volts
      if ((volts / DC_GAIN) >= ZERO_POINT_VOLTAGE) {
        Serial.println("Error reading CO2");
      }
      else {
        Serial.println("CO2: " + String(pow(10, ((volts / DC_GAIN) - CO2Curve[1]) / CO2Curve[2] + CO2Curve[0])));
      }
      break;
    case 'D':
      Serial.println("Testing Traffic Light 1");
      Serial.println("Turning ON LR1");
      digitalWrite(LR1, HIGH);
      delay(1000);
      digitalWrite(LR1, LOW);
      Serial.println("Turning ON LY1");
      digitalWrite(LY1, HIGH);
      delay(1000);
      digitalWrite(LY1, LOW);
      Serial.println("Turning ON LG1");
      digitalWrite(LG1, HIGH);
      delay(1000);
      digitalWrite(LG1, LOW);
      break;
    case 'E':
      Serial.println("Testing Traffic Light 2");
      Serial.println("Turning ON LR2");
      digitalWrite(LR2, HIGH);
      delay(1000);
      digitalWrite(LR2, LOW);
      Serial.println("Turning ON LY2");
      digitalWrite(LY2, HIGH);
      delay(1000);
      digitalWrite(LY2, LOW);
      Serial.println("Turning ON LG2");
      digitalWrite(LG2, HIGH);
      delay(1000);
      digitalWrite(LG2, LOW);
      break;
    case 'F':
      Serial.println("Testing LCD");
      lcd.setCursor(0, 0);
      lcd.print("Hello World1");
      lcd.setCursor(0, 1);
      lcd.print("Hello World2");
      break;
  }
}

void readComm() {
  if (Serial.available() > 0) {
    comm = Serial.read();
    testAnalogSenAct(comm);
    comm = '\0';
  }
}

void checkDigitalIn() { //Subroutine to check all digital inputs
  if (digitalRead(P1) == HIGH) {
    Serial.println("P1: ON");
    delay(300); //Debouncing for buttons using delay of 300 ms
    while (digitalRead(P1) == HIGH) {} //Debouncing
  }
  if (digitalRead(P2) == HIGH) {
    Serial.println("P2: ON");
    delay(300); //Debouncing for buttons using delay of 300 ms
    while (digitalRead(P2) == HIGH) {} //Debouncing
  }
  if (digitalRead(CNY1) == HIGH) {
    Serial.println("CNY1: ON");
    delay(300); //Debouncing for buttons using delay of 300 ms
    while (digitalRead(CNY1) == HIGH) {} //Debouncing
  }
  if (digitalRead(CNY2) == HIGH) {
    Serial.println("CNY2: ON");
    delay(300); //Debouncing for buttons using delay of 300 ms
    while (digitalRead(CNY2) == HIGH) {} //Debouncing
  }
  if (digitalRead(CNY3) == HIGH) {
    Serial.println("CNY3: ON");
    delay(300); //Debouncing for buttons using delay of 300 ms
    while (digitalRead(CNY3) == HIGH) {} //Debouncing
  }
  if (digitalRead(CNY4) == HIGH) {
    Serial.println("CNY4: ON");
    delay(300); //Debouncing for buttons using delay of 300 ms
    while (digitalRead(CNY4) == HIGH) {} //Debouncing
  }
  if (digitalRead(CNY4) == HIGH) {
    Serial.println("CNY4: ON");
    delay(300); //Debouncing for buttons using delay of 300 ms
    while (digitalRead(CNY4) == HIGH) {} //Debouncing
  }
  if (digitalRead(CNY5) == HIGH) {
    Serial.println("CNY5: ON");
    delay(300); //Debouncing for buttons using delay of 300 ms
    while (digitalRead(CNY5) == HIGH) {} //Debouncing
  }
  if (digitalRead(CNY6) == HIGH) {
    Serial.println("CNY6: ON");
    delay(300); //Debouncing for buttons using delay of 300 ms
    while (digitalRead(CNY6) == HIGH) {} //Debouncing
  }
}

//Configuration
void setup() {
  //Pin config
  pinMode(P1, INPUT); //Traffic light 1 button as Input
  pinMode(P2, INPUT); //Traffic light 2 button as Input
  pinMode(CNY1, INPUT); //Infrared sensor 1 in traffic light 1 as Input
  pinMode(CNY2, INPUT); //Infrared sensor 2 in traffic light 1 as Input
  pinMode(CNY3, INPUT); //Infrared sensor 3 in traffic light 1 as Input
  pinMode(CNY4, INPUT); //Infrared sensor 4 in traffic light 2 as Input
  pinMode(CNY5, INPUT); //Infrared sensor 5 in traffic light 2 as Input
  pinMode(CNY6, INPUT); //Infrared sensor 6 in traffic light 2 as Input
  pinMode(LR1, OUTPUT); //Red traffic light 1 as Output
  pinMode(LY1, OUTPUT); //Yellow traffic light 1 as Output
  pinMode(LG1, OUTPUT); //Green traffic light 1 as Output
  pinMode(LR2, OUTPUT); //Red traffic light 2 as Output
  pinMode(LY2, OUTPUT); //Yellow traffic light 2 as Output
  pinMode(LG2, OUTPUT); //Green traffic light 2 as Output

  //Output cleaning
  digitalWrite(LR1, LOW); //Turn Off Red traffic light 1
  digitalWrite(LY1, LOW); //Turn Off Yellow traffic light 1
  digitalWrite(LG1, LOW); //Turn Off Green traffic light 1
  digitalWrite(LR2, LOW); //Turn Off Red traffic light 2
  digitalWrite(LY2, LOW); //Turn Off Yellow traffic light 2
  digitalWrite(LG2, LOW); //Turn Off Green traffic light 2

  //Communications
  Serial.begin(9600); //Start Serial communications with computer via Serial0 (TX0 RX0) at 9600 bauds
  lcd.begin();  //Start communications with LCD display
  lcd.backlight();  //Turn on LCD backlight
}

void loop() {
  readComm(); //Wait for command from Serial to test
  checkDigitalIn(); //Check if any digital input is activated
}
