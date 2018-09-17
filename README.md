# Smart City Arduino
![alt text](https://raw.githubusercontent.com/tidusdavid/smart-city-arduino-eafit/master/Resources/Architecture.png)
![alt text](https://raw.githubusercontent.com/tidusdavid/smart-city-arduino-eafit/master/Resources/Device.png)

This project simulates a smart city with some traffic lights, light sensors, proximity sensors for cars and a CO2 sensor.

## Testing
Upload Arduino Codes/arduinoSmartCity/arduinoSmartCity.ino code to Arduino MEGA. Edit header pins to match the device pins. Open Serial Monitor and activate each digital input (each digital sensor) using your hands. If the sensor is OK, you will see a message in the Serial monitor indicating which sensor was activated. In order to test Analog Sensors and Actuators, send the following commands through the Serial Monitor:
A: Tests LDR1 Sensor
B: Tests LDR2 Sensor
C: Test CO2 Sensor
D: Tests Traffic Light 1 (LR1, LY1 and LG1)
E: Tests Traffic Light 2 (LR2, LY2 and LG2)
F: Tests LCD
