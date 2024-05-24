### Manage Custom 7 segment Display using leds
Using this library for Arduino, you will be able to manage a 7-segment display created using LEDs or WS2812 LED strips. If you have built a 7-segment display for example with LED strips, you can define a series of strings that contain the sequence of LEDs for each segment and then use the functions of this library to easily view the digits on the display or the individual segments that compose it



![](https://github.com/BOOMYTECH/DisplayLED_Custom/blob/main/img/display_draw_s.jpg)


HOW TO USE:
-----------

// Assign object library<br>
BTDisplay disp;

 // .init(a,b,c)<br>
 //    a = number of digit (eg. 8=one digit, 888=three digit<br>
 //    b = signal pin of microcontroller<br>
 //    c = total number of leds in one digit<br>
 disp.init(2, D3, 22); // (TotDisplays, Pin, TotLedPerDisplay)<br>

 // Init segment display schema<br>
 //   each segment need sequence led number separated by comma<br>
 disp._a = "3,4,5";<br>
 disp._b = "0,1,2";<br>
 disp._c = "12,13,14";<br>
 disp._d = "16,17,18";<br>
 disp._e = "19,20,21";<br>
 disp._f = "6,7,8";<br>
 disp._g = "9,10,11";<br>
 disp._dp = "15";<br>
 
 disp.digit_Brightness = 50; // leds brightness (0:255)<br>
 disp.digit_Color = 3000;    // leds color in HSV format https://it.wikipedia.org/wiki/Hue_Saturation_Brightness<br>
 disp.digit_Active =  1;     // Active digit. Next actions will be done only on active digit (0:x)<br>
 
 FUNCTIONS:
 -------------
 disp.digit_ALL_off(); // light off all digits<br>
 
 disp.ShowSeg(disp._a,1); // show/hide specific segment<br>
 // 1st param: segment<br>
 // 2nd param: 0 = led off<br>
 //            1 = led on<br>
 
 // .digit("x") (0:9 null)<br>
 //    Show specific number of digit_Active<br>
 disp.digit("9");<br>
 
 pls watch this video: https://youtu.be/Mb3xCe2Co3A to see how this Stream Deck has been created.
 ![](https://github.com/BOOMYTECH/DisplayLED_Custom/blob/main/img/1_s.jpg)
 ![](https://github.com/BOOMYTECH/DisplayLED_Custom/blob/main/img/2_s.jpg)
