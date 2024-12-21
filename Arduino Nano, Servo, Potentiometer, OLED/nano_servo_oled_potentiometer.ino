#include <Servo.h>
#include "ssd1306.h"
#define OLED_I2C_ADDRESS 0x3c

Servo myServo;

void setup() {
  myServo.attach(9);
  Serial.begin(115200);

  pinMode(A0, INPUT); 

  ssd1306_128x64_i2c_init();
  ssd1306_clearScreen(); // Clear the screen initially
  ssd1306_setFixedFont(ssd1306xled_font6x8); // Set font for text
}

void loop() {
  int sensorValue = analogRead(A0);
  int angle = map(sensorValue, 0, 1023, 0, 180); 
  myServo.write(angle);

  // Display the angle directly
  char buffer[16];
  sprintf(buffer, "Angle: %d  ", angle); // Add extra spaces to overwrite old values
  ssd1306_printFixedN(5, 5, buffer, STYLE_NORMAL, 1); // Print text at (0,0)

  Serial.println(angle); // Print to Serial Monitor
  delay(50); // Smooth delay
}
