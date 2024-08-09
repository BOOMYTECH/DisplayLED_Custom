#ifndef BTDisplay_h
#define BTDisplay_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>   // Neopixel Library

class BTDisplay {
  public:

    int pinControllo;
    byte digit_Brightness;             // Brightness
    unsigned int digit_Color;          // HSV Digit Color
    byte digit_Active;                 // Active Digit
    unsigned int  tot_LedPerDigit;     // led in a single digit
    unsigned int  tot_Digits;          // Total Digits
    String _a,_b,_c,_d,_e,_f,_g,_dp,_dp2;
 
    void ShowSeg( String segment, bool is_ON);
    void show();
    void digit_ALL_off(); // Turn off all leds

    void init(Adafruit_NeoPixel &pixel, int xtotLedPerDigit, int xtotDigits);
    void setBrightness(byte value);
    void setDigitColor(unsigned int value);
    void setDigitActive(byte value);
    
    void segment_a(bool is_ON);
    void segment_b(bool is_ON);
    void segment_c(bool is_ON);
    void segment_d(bool is_ON);
    void segment_e(bool is_ON);
    void segment_f(bool is_ON);
    void segment_g(bool is_ON);
    void segment_dp(bool is_ON);
    void segment_dp2(bool is_ON);

    void digit_0();
    void digit_1();
    void digit_2();
    void digit_3();
    void digit_4();
    void digit_5();
    void digit_6();
    void digit_7();
    void digit_8();
    void digit_9();
    void digit_null();
    void digit__();
    void digit_A(); 
    void digit_b(); 
    void digit_C();
    void digit_d(); 
    void digit_E();
    void digit_F(); 
    void digit_H();
    void digit(String str_digit); // show number passed in str_digit

  private:
  
};

#endif
