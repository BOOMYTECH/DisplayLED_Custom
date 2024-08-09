// --------------------------------------------------------------
//
//                       B O O M Y  T E C H  
//
//                       7 SEGMENT LED DISPLAY
//
// YouTube: https://www.youtube.com/@boomytech7504
//
// YouTubwe: https://youtu.be/Mb3xCe2Co3A
// GitHub: https://github.com/BOOMYTECH/DisplayLED_Custom
//
// EMail: boomytech@gmail.com
//
// --------------------------------------------------------------
// Segment sequence:
//
//    aaaaa
//   f     b
//   f     b
//    ggggg
//   e     c
//   e     c
//    ddddd
//           dp
// --------------------------------------------------------------
#include <Adafruit_NeoPixel.h>
#include "Arduino.h"
#include "BTDisplay.h"

Adafruit_NeoPixel Pixel;

// USER DEFINE PARAMETERS (must be defined in source file)
// --------------------------------------------
byte          digit_Brightness = 255;   // Brightness
unsigned int  digit_Color      = 3000;  // HSV Digit Color
byte          digit_Active;             // Active Digit


// LED SCHEMA DEFINED BY USER  (must be defined in source file)
// --------------------------------------------
//String _a,_b,_c,_d,_e,_f,_g,_dp,_dp2;

//eg.
//disp._a = "3,4,5";
//disp._b = "0,1,2";
//disp._c = "12,13,14";
//disp._d = "16,17,18";
//disp._e = "19,20,21";
//disp._f = "6,7,8";
//disp._g = "9,10,11";
//disp._dp = "15";
//disp_dp2 = "16";
// --------------------------------------------

// ----------------------------------------
// INIT
// ----------------------------------------
void BTDisplay::init(Adafruit_NeoPixel &pixel, int xtotLedPerDigit, int xtotDigits) {
  tot_LedPerDigit = xtotLedPerDigit;
  tot_Digits = xtotDigits;
  Pixel = pixel;  
}

void BTDisplay::show() {
  Pixel.show();
}

// ----------------------------------------
// // SWITCH-ON/OFF A SINGLE SEGMENT 
// ----------------------------------------
void BTDisplay::ShowSeg( String segment, bool is_ON) {
 int pointer=0;
 int nextPointer=-1;
 int Number;
 do {
    pointer=nextPointer+1;
    nextPointer = segment.indexOf(",",pointer);
    Number = segment.substring(pointer, nextPointer).toInt();   
    Pixel.setPixelColor(Number+(digit_Active * tot_LedPerDigit), Pixel.ColorHSV(digit_Color, 255, is_ON ? digit_Brightness : 0 ));
    Pixel.show();
 } while  (nextPointer > 0);
}


// ----------------------------------------
// // SWITCH-ON SEGMENTS TO COMPOSE DIGIT
// ----------------------------------------
void BTDisplay::digit_1() { ShowSeg(_a,0); ShowSeg(_b,1); ShowSeg(_c,1); ShowSeg(_d,0); ShowSeg(_e,0); ShowSeg(_f,0); ShowSeg(_g,0);}
void BTDisplay::digit_2() { ShowSeg(_a,1); ShowSeg(_b,1); ShowSeg(_c,0); ShowSeg(_d,1); ShowSeg(_e,1); ShowSeg(_f,0); ShowSeg(_g,1);}
void BTDisplay::digit_3() { ShowSeg(_a,1); ShowSeg(_b,1); ShowSeg(_c,1); ShowSeg(_d,1); ShowSeg(_e,0); ShowSeg(_f,0); ShowSeg(_g,1);}
void BTDisplay::digit_4() { ShowSeg(_a,0); ShowSeg(_b,1); ShowSeg(_c,1); ShowSeg(_d,0); ShowSeg(_e,0); ShowSeg(_f,1); ShowSeg(_g,1);}
void BTDisplay::digit_5() { ShowSeg(_a,1); ShowSeg(_b,0); ShowSeg(_c,1); ShowSeg(_d,1); ShowSeg(_e,0); ShowSeg(_f,1); ShowSeg(_g,1);}
void BTDisplay::digit_6() { ShowSeg(_a,1); ShowSeg(_b,0); ShowSeg(_c,1); ShowSeg(_d,1); ShowSeg(_e,1); ShowSeg(_f,1); ShowSeg(_g,1);}
void BTDisplay::digit_7() { ShowSeg(_a,1); ShowSeg(_b,1); ShowSeg(_c,1); ShowSeg(_d,0); ShowSeg(_e,0); ShowSeg(_f,0); ShowSeg(_g,0);}
void BTDisplay::digit_8() { ShowSeg(_a,1); ShowSeg(_b,1); ShowSeg(_c,1); ShowSeg(_d,1); ShowSeg(_e,1); ShowSeg(_f,1); ShowSeg(_g,1);}
void BTDisplay::digit_9() { ShowSeg(_a,1); ShowSeg(_b,1); ShowSeg(_c,1); ShowSeg(_d,1); ShowSeg(_e,0); ShowSeg(_f,1); ShowSeg(_g,1);}
void BTDisplay::digit_0() { ShowSeg(_a,1); ShowSeg(_b,1); ShowSeg(_c,1); ShowSeg(_d,1); ShowSeg(_e,1); ShowSeg(_f,1); ShowSeg(_g,0);}
void BTDisplay::digit__() { ShowSeg(_a,0); ShowSeg(_b,0); ShowSeg(_c,0); ShowSeg(_d,0); ShowSeg(_e,0); ShowSeg(_f,0); ShowSeg(_g,1);}
void BTDisplay::digit_A() { ShowSeg(_a,1); ShowSeg(_b,1); ShowSeg(_c,1); ShowSeg(_d,0); ShowSeg(_e,1); ShowSeg(_f,1); ShowSeg(_g,1);}
void BTDisplay::digit_b() { ShowSeg(_a,0); ShowSeg(_b,0); ShowSeg(_c,1); ShowSeg(_d,1); ShowSeg(_e,1); ShowSeg(_f,1); ShowSeg(_g,1);}
void BTDisplay::digit_C() { ShowSeg(_a,1); ShowSeg(_b,0); ShowSeg(_c,0); ShowSeg(_d,1); ShowSeg(_e,1); ShowSeg(_f,1); ShowSeg(_g,0);}
void BTDisplay::digit_d() { ShowSeg(_a,0); ShowSeg(_b,1); ShowSeg(_c,1); ShowSeg(_d,1); ShowSeg(_e,1); ShowSeg(_f,0); ShowSeg(_g,1);}
void BTDisplay::digit_E() { ShowSeg(_a,1); ShowSeg(_b,0); ShowSeg(_c,0); ShowSeg(_d,1); ShowSeg(_e,1); ShowSeg(_f,1); ShowSeg(_g,1);}
void BTDisplay::digit_F() { ShowSeg(_a,1); ShowSeg(_b,0); ShowSeg(_c,0); ShowSeg(_d,0); ShowSeg(_e,1); ShowSeg(_f,1); ShowSeg(_g,1);}
void BTDisplay::digit_H() { ShowSeg(_a,0); ShowSeg(_b,1); ShowSeg(_c,1); ShowSeg(_d,0); ShowSeg(_e,1); ShowSeg(_f,1); ShowSeg(_g,1);}
void BTDisplay::digit_null() { ShowSeg(_a,0); ShowSeg(_b,0); ShowSeg(_c,0); ShowSeg(_d,0); ShowSeg(_e,0); ShowSeg(_f,0); ShowSeg(_g,0);}


// ----------------------------------------
// SHOW RIGHT NUMBER ON SELECTED DIGIT (--display_Number--)
// ----------------------------------------
void BTDisplay::digit(String str_digit) {
  if (str_digit == "") digit_null();
  if (str_digit == "0") digit_0();
  if (str_digit == "1") digit_1();
  if (str_digit == "2") digit_2();
  if (str_digit == "3") digit_3();
  if (str_digit == "4") digit_4();
  if (str_digit == "5") digit_5();
  if (str_digit == "6") digit_6();
  if (str_digit == "7") digit_7();
  if (str_digit == "8") digit_8();
  if (str_digit == "9") digit_9();
  if (str_digit == "-") digit__();
  if (str_digit == "A") digit_A();
  if (str_digit == "b") digit_b();
  if (str_digit == "C") digit_C();
  if (str_digit == "d") digit_d();
  if (str_digit == "E") digit_E();
  if (str_digit == "F") digit_F();
  if (str_digit == "H") digit_H();
  
}

// SWITCH OFF ALL SEGMENTS
void BTDisplay::digit_ALL_off() { 
  for (int i=0; i <= (tot_LedPerDigit * tot_Digits); i++) {
    Pixel.setPixelColor(i, Pixel.ColorHSV(0,0,0)); 
  }
}
