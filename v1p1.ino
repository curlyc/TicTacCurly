//OLD VERSION
// fixed the bug granting the computer player an extra turn
// added press b in gameplay to reset game (if playing againced computer 
// that was for testing purposes but i liked it so i kept it
// cleaned up a few things here or there
#include "Arduboy2.h"
Arduboy2 ab;
int gamestate = 0;
int players = 0;
int turn = 1;
int loc = 0;
int xloc = 7;
int yloc = 7;
int a1 = 0;
int a2 = 0;
int a3 = 0;
int b1 = 0;
int b2 = 0;
int b3 = 0;
int c1 = 0;
int c2 = 0;
int c3 = 0;
int xwins = 0;
int owins = 0;
int ties = 0;
int emove = 0;
const unsigned char player[] PROGMEM  = {
0x3, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x3, 0x3, 0x2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2, 0x3, 
};
const unsigned char titles[] PROGMEM  = {
0x00, 0x00, 0x3c, 0xc4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x98, 0x88, 0xe8, 0x18, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18, 0x4, 0x84, 0x84, 0x8, 0x8, 0x8, 0x10, 0x90, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x8, 0x8, 0x8, 0x8, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x20, 0x20, 0xe0, 0x00, 0x00, 0x80, 0x70, 0x10, 0x10, 0x90, 0x10, 0x30, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x90, 0x88, 0x88, 0x90, 0x90, 0x10, 0xa0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3, 0x1, 0x1, 0x2, 0x2, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x4, 0x4, 0x2, 0x2, 0x2, 0x2, 0x3, 0x00, 0x00, 0x00, 0x7e, 0x82, 0x2, 0x2, 0xe, 0xf0, 0x00, 0x00, 0xf8, 0x7, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x81, 0x81, 0x42, 0x42, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6, 0x1c, 0x62, 0x42, 0x22, 0x22, 0x21, 0x17, 0x18, 0x00, 0x1, 0x1, 0x2, 0x2, 0xfc, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x4, 0x4, 0x4, 0x8, 0x8, 0x1e, 0x1, 0x00, 0xf0, 0xf, 0x00, 0xc0, 0x47, 0x65, 0x86, 0x00, 0x3, 0x3c, 0xc0, 0x00, 0x00, 0xf8, 0x7, 0x00, 0xc, 0x13, 0x20, 0x40, 0x20, 0x20, 0x20, 0x21, 0xa1, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x7f, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x1, 0xe, 0x30, 0x20, 0x20, 0x10, 0x11, 0x10, 0x10, 0x8, 0x4, 0x5, 0x2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x41, 0x40, 0x40, 0x78, 0x7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x13, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x7, 0x18, 0x10, 0x8, 0xb, 0xc, 0x00, 0x00, 0x1, 0x1, 0x2, 0x2, 0x4, 0x4, 0x4, 0x84, 0x82, 0x2, 0x3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x10, 0x8, 0x4, 0x4, 0x84, 0x84, 0x84, 0x4, 0x8, 0x10, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x88, 0x8, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x10, 0x10, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x4, 0x4, 0x2, 0xea, 0x11, 0xa1, 0x41, 0x1, 0x2, 0x6, 0x98, 0x60, 0x00, 0x00, 0x00, 0x1, 0x3f, 0xc1, 0x1, 0x1, 0x1, 0xff, 0x00, 0x2, 0xe, 0x11, 0x61, 0x81, 0x1, 0x00, 0x1, 0x6, 0x18, 0x60, 0x80, 0x60, 0x18, 0x4, 0x3, 0x00, 0x00, 0x80, 0x40, 0x31, 0x9, 0x7, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x38, 0x47, 0x81, 0x00, 0x00, 0x00, 0x3, 0x4, 0x8, 0x8, 0x4, 0x2, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x1, 0x3e, 0x40, 0x40, 0x80, 0x40, 0x3f, 0x00, 0x00, 0x00, 0xf8, 0x7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x3, 0x1, 0x00, 0x00, 0x10, 0x2c, 0x42, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x1f, 0x10, 0x20, 0x20, 0x40, 0xc0, 0x1, 0x2, 0xc, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xc, 0x2, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3, 0xc, 0x30, 0x40, 0x40, 0x40, 0x80, 0x81, 0x82, 0x82, 0x82, 0x82, 0x2, 0x2, 0x82, 0x62, 0x1a, 0x6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7, 0x78, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x20, 0x10, 0x8, 0x8, 0x7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3, 0x7c, 0x40, 0x20, 0x38, 0x7, 0x6, 0x18, 0x10, 0x10, 0x11, 0x12, 0x14, 0x18, 0x10, 0x00, 0x00, 0x00, 0x3, 0x2, 0x2, 0x4, 0x4, 0x4, 0x4, 0x8, 0xf, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x1, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2, 0x3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

void setup() {
  ab.begin();
  ab.setFrameRate(1);
  ab.initRandomSeed();
  ab.clear(); 
  
}
void loop() {
  if (!(ab.nextFrame()))
    return;
    ab.clear();
    
  if (gamestate >= 3) {
  gamestate = 1;
  }
  if (gamestate == 0) {
       ab.drawBitmap((0), (0), titles, 128, 54, WHITE);
       ab.setCursor((0), (55)); 
      ab.print("VERSION 1.1 PRESS A");
      if (ab.pressed(A_BUTTON)) {
        ab.clear();
        gamestate += 1;
      }
    } 
  if (gamestate == 1) { 
      ab.setCursor((23), (0)); 
      ab.print("How Many Players?");
ab.setCursor((5), (10)); 
      ab.print("LEFT or RIGHT select");
      ab.setCursor((35), (25)); 
      ab.print("B to PLAY");
          if(ab.pressed(RIGHT_BUTTON) && (players == 0)) { 
              players += 1;
    } 
          if(ab.pressed(LEFT_BUTTON) && (players == 1)) { 
            players -= 1;
    } 
          if(ab.pressed(B_BUTTON)) { 
           
           gamestate = 2;
          } 
          if (players == 0) { 
            ab.setCursor((29), (49)); 
            ab.print("1 Player");
      } 
          else if (players == 1) { 
            ab.setCursor((29), (49)); 
            ab.print("2 Players");
      } 
          else if (players >= 2) { 
          players = 0;
      } 
  } 
   if (gamestate == 2) {
            ab.clear();
           if(ab.pressed(B_BUTTON) && (players == 0)) { 
            turn = 0;
            emove = 0;
            a1 = 0;
            a2 = 0;
            a3 = 0;
            b1 = 0;
            b2 = 0;
            b3 = 0;
            c1 = 0;
            c2 = 0;
            c3 = 0;
           }
      //make enemy move and stuff
 if ((players == 0) && (turn == 2)) {
    //removed delay 
    emove = rand() % 8 + 1;
  }
    if ((emove == 1) && (a1 == 0)) {
     emove = 0;
     turn += 1;
     a1 = 2;
      
  }
    else if ((emove == 2) && (a2 == 0)) {
     emove = 0;
     turn += 1;
     a2 = 2; 
     
  }
    else if ((emove == 3) && (a3 == 0)) {
     emove = 0;
     turn += 1;
     a3 = 2;
      
  }
    else if ((emove == 4) && (b1 == 0)) {
     emove = 0;
     turn += 1;
     b1 = 2;
     
  }
    else if ((emove == 5) && (b2 == 0)) {
     emove = 0;
     turn += 1;
     b2 = 2; 
     
  }
    else if ((emove == 6) && (b3 == 0)) {
     emove = 0;
     turn += 1;
     b3 = 2; 
     
  }
    else if ((emove == 7) && (c1 == 0)) {
     emove = 0;
     turn += 1;
     c1 = 2; 
     
  }
     else if ((emove == 8) && (c2 == 0)) {
     emove = 0;
     turn += 1;
     c2 = 2; 
     
  }
     else if ((emove == 9) && (c3 == 0)) {
     emove = 0;
     turn += 1;
     b2 = 2; 
     
  }
    
    // pulled one out 
 // test stuff get rid of eventualy
 ab.setCursor((70), (0)); 
  ab.print("X WINS");
  ab.setCursor((110), (0)); 
  ab.print(xwins);
   ab.setCursor((70), (15)); 
  ab.print("O WINS");
  ab.setCursor((110), (15)); 
  ab.print(owins);
  
  ab.setCursor((70), (30));
  ab.print("TIES");
  ab.setCursor((110), (30)); 
  ab.print(ties);
  ab.setCursor((70), (40));
  ab.print("Turn");
  ab.setCursor((110), (40)); 
  if (turn == 1) {
  ab.print("X");
  }
  if (turn == 2) {
    ab.print("O");
  }
 // end test stuff
 ab.drawBitmap((xloc - 2), (yloc - 1), player, 10, 10, WHITE);
   if (turn >= 3){
    turn = 1;
   }
   
   if ((xloc == 7) && (yloc == 7) && (ab.pressed(A_BUTTON)) && (a1 == 0)) {
    a1 = turn;
    turn += 1;
   }
   if ((xloc == 28) && (yloc == 7) && (ab.pressed(A_BUTTON)) && (a2 == 0)) {
    a2 = turn;
    turn += 1;
   }
   if ((xloc == 49) && (yloc == 7) && (ab.pressed(A_BUTTON)) && (a3 == 0)) {
    a3 = turn;
    turn += 1;
   }
   if ((xloc == 7) && (yloc == 28) && (ab.pressed(A_BUTTON)) && (b1 == 0)) {
    b1 = turn;
    turn += 1;
   }
   if ((xloc == 28) && (yloc == 28) && (ab.pressed(A_BUTTON)) && (b2 == 0)) {
    b2 = turn;
    turn += 1;
   }
   if ((xloc == 49) && (yloc == 28) && (ab.pressed(A_BUTTON)) && (b3 == 0)) {
    b3 = turn;
    turn += 1;
   }
   if ((xloc == 7) && (yloc == 49) && (ab.pressed(A_BUTTON)) && (c1 == 0)) {
    c1 = turn;
    turn += 1;
   }
   if ((xloc == 28) && (yloc == 49) && (ab.pressed(A_BUTTON)) && (c2 == 0)) {
    c2 = turn;
    turn += 1;
   }
   if ((xloc == 49) && (yloc == 49) && (ab.pressed(A_BUTTON)) && (c3 == 0)) {
    c3 = turn;
    turn += 1;
   }
  
    if(ab.pressed(LEFT_BUTTON) && (xloc >= 21)) {
      xloc -= 21;
    }
    if(ab.pressed(RIGHT_BUTTON) && (xloc <= 42)) {
      xloc += 21;
    }
    if(ab.pressed(UP_BUTTON) && (yloc >= 21)) {
      yloc -= 21;
    }
    if(ab.pressed(DOWN_BUTTON) && (yloc <= 42)) {
      yloc += 21;
    }
  
  
ab.drawFastVLine(21,0,63,WHITE);   //LEFT line
ab.drawFastVLine(42,0,63,WHITE);  //RIGHT line
ab.drawFastHLine(0,21,63,WHITE);   //TOP line
ab.drawFastHLine(0,42,63,WHITE);  //BOTTOM line
if (a1 >= 1) {
 if (a1 == 1) {
    ab.setCursor((7), (7)); 
  ab.print("X");
  }
 if (a1 == 2) {
    ab.setCursor((7), (7)); 
  ab.print("O");
  }
}
if (a2 >= 1) {
 if (a2 == 1) {
    ab.setCursor((28), (7)); 
  ab.print("X");
  }
 if (a2 == 2) {
    ab.setCursor((28), (7)); 
  ab.print("O");
  }
}
if (a3 >= 1) {
  if (a3 == 1) {
    ab.setCursor((49), (7)); 
  ab.print("X");
  }
 if (a3 == 2) {
    ab.setCursor((49), (7)); 
  ab.print("O");
  }
}
if (b1 >= 1) {
 if (b1 == 1) {
    ab.setCursor((7), (28)); 
  ab.print("X");
  }
 if (b1 == 2) {
    ab.setCursor((7), (28)); 
  ab.print("O");
  }
}
if (b2 >= 1) {
 if (b2 == 1) {
    ab.setCursor((28), (28)); 
  ab.print("X");
  }
 if (b2 == 2) {
    ab.setCursor((28), (28)); 
  ab.print("O");
  }
}
if (b3 >= 1) {
 if (b3 == 1) {
    ab.setCursor((49), (28)); 
  ab.print("X");
  }
 if (b3 == 2) {
    ab.setCursor((49), (28)); 
  ab.print("O");
  }
}
if (c1 >= 1) {
 if (c1 == 1) {
    ab.setCursor((7), (49)); 
  ab.print("X");
  }
 if (c1 == 2) {
    ab.setCursor((7), (49)); 
  ab.print("O");
  }
}
if (c2 >= 1) {
 if (c2 == 1) {
    ab.setCursor((28), (49)); 
  ab.print("X");
  }
 if (c2 == 2) {
    ab.setCursor((28), (49)); 
  ab.print("O");
  }
}
if (c3 >= 1) {
 if (c3 == 1) {
    ab.setCursor((49), (49)); 
  ab.print("X");
  }
 if (c3 == 2) {
    ab.setCursor((49), (49)); 
  ab.print("O");
  }
}


if ((a1 == 1) && (a2 == 1) && (a3 == 1) or (b1 == 1) && (b2 == 1) && (b3 == 1) or (c1 == 1) && (c2 == 1) && (c3 == 1) or (a1 == 1) && (b1 == 1) && (c1 == 1) or (a2 == 1) && (b2 == 1) && (c2 == 1) or (a3 == 1) && (b3 == 1) && (c3 == 1) or (a1 == 1) && (b2 == 1) && (c3 == 1) or (a3 == 1) && (b2 == 1) && (c1 == 1)) {
  xwins += 1;
  emove = 0;
  a1 = 0;
  a2 = 0;
  a3 = 0;
  b1 = 0;
  b2 = 0;
  b3 = 0;
  c1 = 0;
  c2 = 0;
  c3 = 0;
}
if ((a1 == 2) && (a2 == 2) && (a3 == 2) or (b1 == 2) && (b2 == 2) && (b3 == 2) or (c1 == 2) && (c2 == 2) && (c3 == 2) or (a1 == 2) && (b1 == 2) && (c1 == 2) or (a2 == 2) && (b2 == 2) && (c2 == 2) or (a3 == 2) && (b3 == 2) && (c3 == 2) or (a1 == 2) && (b2 == 2) && (c3 == 2) or (a3 == 2) && (b2 == 2) && (c1 == 2)) {
  owins += 1;
  emove = 0;
  a1 = 0;
  a2 = 0;
  a3 = 0;
  b1 = 0;
  b2 = 0;
  b3 = 0;
  c1 = 0;
  c2 = 0;
  c3 = 0;
}
if ((a1 >=1) && (a2 >=1) &&( a3 >=1) && (b1 >=1) && (b2 >=1) && (b3 >=1) && (c1 >=1) && (c2 >=1) && (c3 >=1)){
  ties += 1;
  emove = 0;
  a1 = 0;
  a2 = 0;
  a3 = 0;
  b1 = 0;
  b2 = 0;
  b3 = 0;
  c1 = 0;
  c2 = 0;
  c3 = 0;
}

    
   }  
  ab.display();
}
