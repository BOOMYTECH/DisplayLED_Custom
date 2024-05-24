### Manage Custom 7 segment Display using leds
Using this library for Arduino, you will be able to manage a 7-segment display created using LEDs or WS2812 LED strips. If you have built a 7-segment display for example with LED strips, you can define a series of strings that contain the sequence of LEDs for each segment and then use the functions of this library to easily view the digits on the display or the individual segments that compose it



![](https://github.com/BOOMYTECH/DisplayLED_Custom/blob/main/img/display_draw_s.jpg)


HOW TO USE:
-----------

// Assign object library
BTDisplay disp;

 // .init(a,b,c)
 //    a = number of digit (eg. 8=one digit, 888=three digit
 //    b = signal pin of microcontroller
 //    c = total number of leds in one digit
 disp.init(2, D3, 22); // (TotDisplays, Pin, TotLedPerDisplay)

 // Init segment display schema
 //   each segment need sequence led number separated by comma
 disp._a = "3,4,5";
 disp._b = "0,1,2";
 disp._c = "12,13,14";
 disp._d = "16,17,18";
 disp._e = "19,20,21";
 disp._f = "6,7,8";
 disp._g = "9,10,11";
 disp._dp = "15";
 
 disp.digit_Brightness = 50; // leds brightness (0:255)
 disp.digit_Color = 3000;    // leds color in HSV format https://it.wikipedia.org/wiki/Hue_Saturation_Brightness
 disp.digit_Active =  1;     // Active digit. Next actions will be done only on active digit (0:x)
 
 FUNCTIONS:
 -------------
 disp.digit_ALL_off(); // light off all digits
 
 disp.ShowSeg(disp._a,1); // show/hide specific segment
 // 1st param: segment
 // 2nd param: 0 = led off
 //            1 = led on
 
 // .digit("x") (0:9 null)
 //    Show specific number of digit_Active
 disp.digit("9");
 
 pls watch this video: https://youtu.be/Mb3xCe2Co3A to see how this Stream Deck has been created.
