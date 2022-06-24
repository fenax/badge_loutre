/*

  XBM.ino
  
  This will display a XBM image (generated by GIMP).
  The .xbm file was pasted directly into the .ino file and moved to 
  flash (PROGMEM) area.

  Universal 8bit Graphics Library (https://github.com/olikraus/u8g2/)

  Copyright (c) 2016, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  

*/

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#include "badge_meoxie.h"
#include "badge_kosse.h"
#include "badge_tifur.h"
#include "badge_beaver.h"

#include "tiles.h"
#include "animated_f0.h"
#include "animated_f1.h"
#include "animated_f2.h"
#include "animated_f3.h"
#include "animated_f4.h"
#include "animated_f5.h"
#include "animated_f6.h"
#include "animated_f7.h"
#include "animated_f8.h"
#include "animated_ff.h"

#include "Dog_Idle_D_white.h"
#include "Dog_Idle_D.h"
#include "Dog_Idle_U_white.h"
#include "Dog_Idle_U.h"
#include "Dog_Idle_L_white.h"
#include "Dog_Idle_L.h"
#include "Dog_Idle_R_white.h"
#include "Dog_Idle_R.h"

#include "Dog_walk_D_white.h"
#include "Dog_walk_D.h"
#include "Dog_walk_U_white.h"
#include "Dog_walk_U.h"
#include "Dog_walk_L_white.h"
#include "Dog_walk_L.h"
#include "Dog_walk_R_white.h"
#include "Dog_walk_R.h"

#include "lynx.h"
#include "lynx_white.h"
typedef signed char int8_t;
U8G2_SH1107_PIMORONI_128X128_F_4W_HW_SPI u8g2(U8G2_R0,D8, /* dc=*/ D2);

static const unsigned char* animated[]={
  animated_f0_bits,
  animated_f1_bits,
  animated_f2_bits,
  animated_f3_bits,
  animated_f4_bits,
  animated_f5_bits,
  animated_f6_bits,
  animated_f7_bits,
  animated_f8_bits
};
static const unsigned char* animated2[]={
  animated_ff_bits,
  animated_ff_bits,
  animated_ff_bits
};



//0 passable floor
//1 wall
//2 nothing ? forgot about 2
//3 floor door
//4 closed door
//5 open door
static const byte tiles_collision[]={
  0,0,0,0,0,0,1,1,  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,1,1,  0,0,0,0,0,0,3,0,
  0,0,0,0,0,0,1,1,  1,1,1,1,1,0,0,0,
  0,1,0,1,1,1,1,1,  1,1,1,1,1,1,1,1,
  0,0,0,0,1,1,1,1,  1,4,1,0,0,1,1,1,
  0,1,1,0,1,1,1,1,  1,1,1,1,1,1,1,1,
  0,1,1,0,1,1,1,1,  1,3,1,1,1,1,1,1,
  0,0,0,0,1,1,1,1,  1,1,1,1,1,1,4,1,
  1,1,1,1,1,1,1,1,  1,1,1,1,1,0,1,1,
  1,1,1,1,1,1,1,1,  1,1,1,1,1,0,5,4,
  1,1,0,1,0,0,0,1,  1,1,1,1,1,0,5,5,
  1,1,0,1,0,1,0,1,  1,3,1,1,1,1,1,1,
  1,1,1,1,0,0,0,1,  1,1,1,1,1,0,0,1,
  1,1,1,1,0,0,0,0,  1,1,1,1,1,1,1,0,
  1,1,1,1,0,0,0,0,  1,1,1,1,1,1,1,1,
  1,0,1,1,1,1,1,1,  1,1,1,1,1,1,1,1
  };


struct teleporter{
  byte target_map;
  
 
      byte source_dir;
      int8_t source_x;
      int8_t source_y;
      
      byte target_dir;
      int8_t target_x;
      int8_t target_y;
      bool target_move;
};


struct dialog{
  byte type;
  
  void * next;
  char * line1;
  char * line2;
  char * line3;
};

static const byte MAP_HOUSE = 0;
static const byte MAP_BEACH = 1;
static const byte MAP_VILLAGE = 2;
static const byte game_maps[][64]={
    {88,89,89,190,190,89,207,90,
    104,1,238,205,205,222,223,106,
    245,1,227,1,1,227,1,243,
    104,1,1,1,1,1,1,106,
    104,1,1,50,154,50,1,106,
    104,1,1,1,1,1,1,106,
    104,193,1,1,1,1,1,106,
    120,121,121,137,10,136,121,122},
    {139,94,44,36,37,59,94,140,
    79,32,130,32,32,32,32,77,
    79,32,32,32,32,32,130,77,
    79,32,130,32,32,32,32,77,
    79,32,32,32,32,32,32,77,
    79,32,32,32,32,32,32,93,
    79,248,248,248,248,248,248,125,
    79,246,246,246,246,246,246,246},
    {40,41,42,2,4,40,41,42,
    56,57,58,2,4,56,57,58,
    72,73,74,2,4,72,73,74,
    1,1,1,1,1,18,1,1,
    1,255,11,46,46,12,1,48,
    1,1,31,241,241,29,1,1,
    1,21,27,14,14,28,255,1,
    1,1,1,1,21,1,1,1}};
static byte current_map = MAP_VILLAGE;

struct character_pose{
  const unsigned char * black[4];
  const unsigned char * white[4];
  char frames;
};

static const byte DIR_NONE = 0xff;
static const byte DIR_UP = 2;
static const byte DIR_DOWN = 0;
static const byte DIR_LEFT = 1;
static const byte DIR_RIGHT = 3; 

static const byte ACT_IDLE = 0;
static const byte ACT_WALK = 1;

struct character{
  byte dir; // 0:down , 1:left, 2: top, 3:right
  byte progress; // 0 to 15; 
  byte action;//0:idle,1:walk,2,3
  byte frame;
  int8_t x;
  int8_t y;
  struct character_pose * idle;
  struct character_pose * walk;
};

static struct character_pose hero_idle = {
  .black = { Dog_Idle_D_bits, Dog_Idle_L_bits, Dog_Idle_U_bits,  Dog_Idle_R_bits},
  .white = { Dog_Idle_D_white_bits, Dog_Idle_L_white_bits, Dog_Idle_U_white_bits, Dog_Idle_R_white_bits},
  .frames = 1
};
static struct character_pose hero_walk = {
  .black = { Dog_walk_D_bits, Dog_walk_L_bits, Dog_walk_U_bits,  Dog_walk_R_bits},
  .white = { Dog_walk_D_white_bits, Dog_walk_L_white_bits, Dog_walk_U_white_bits, Dog_walk_R_white_bits},
  .frames = 4
};

static struct character hero = {
  .dir = 0,
  .progress = 0,
  .action = 0,
  .frame = 0,
  .x = 4,
  .y = 4,
  .idle = &hero_idle,
  .walk = &hero_walk
};

struct character_pose * get_chara_pose(struct character * c){
  switch (c->action){
    case 3:
    case 2:
    case 1:if (c->walk) return c->walk;
    case 0:return c->idle;
  }
  
}

bool can_go(byte tile){
  switch(tiles_collision[tile]){
    case 0:case 3:case 5:case 4: return true;
    default: return false;
  }
}
/*bool can_go(byte dir, unsigned char tile){
  switch(dir){
    case DIR_UP:switch(tile){
      case 1: case 2: case 3: case 9: case 0xc: case 0xd: case 0xe: case 0xf: return false;
      default: return true;
      }
    case DIR_DOWN:switch(tile){
      case 6: case 7: case 8: case 0xb: case 0xc: case 0xd: case 0xe: case 0xf: return false;
      default: return true;
    }
    case DIR_LEFT:switch(tile){
      case 1: case 4: case 6: case 9: case 0xa: case 0xb: case 0xc: case 0xf: return false;
      default: return true;
    }
    case DIR_RIGHT:switch(tile){
      case 3: case 5: case 8: case 9: case 0xa:case 0xb: case 0xe: case 0xf: return false;
      default: return true;
    }
  }
}*/

static const struct teleporter teleporter_beach_to_village = {
  .target_map = MAP_VILLAGE,
  
    .source_dir = DIR_UP,
    .source_x = -1,
    .source_y = -1,
    .target_dir = DIR_DOWN,
    .target_x = -1,
    .target_y = -1,
    .target_move = true
};

static const struct teleporter teleporter_village_to_beach = {
  .target_map = MAP_BEACH,
  .source_dir = DIR_DOWN,
  .source_x = -1,
  .source_y = -1,
  .target_dir = DIR_DOWN,
  .target_x = 4,
  .target_y = -1,
  .target_move = true
};

static const struct teleporter teleporter_village_right = {
  .target_map = MAP_VILLAGE,
  .source_dir = DIR_RIGHT,
  .source_x = -1,
  .source_y = -1,
  .target_dir = DIR_RIGHT,
  .target_x = -1,
  .target_y = -1,
  .target_move = true
};
static const struct teleporter teleporter_village_left = {
  .target_map = MAP_VILLAGE,
  .source_dir = DIR_LEFT,
  .source_x = -1,
  .source_y = -1,
  .target_dir = DIR_LEFT,
  .target_x = -1,
  .target_y = -1,
  .target_move = true
};

static const struct teleporter teleporter_village_to_house1 = {
  .target_map = MAP_HOUSE,
  .source_dir = DIR_UP,
  .source_x = 6,
  .source_y = 2,
  .target_dir = DIR_UP,
  .target_x = 4,
  .target_y = 7,
  .target_move = true
};

static const struct teleporter teleporter_house1_to_village = {
  .target_map = MAP_VILLAGE,
  .source_dir = DIR_DOWN,
  .source_x = 4,
  .source_y = 7,
  .target_dir = DIR_DOWN,
  .target_x = 6,
  .target_y = 2,
  .target_move = true
};

static const struct teleporter * teleporter_from_house[] = {&teleporter_house1_to_village,NULL};
static const struct teleporter * teleporter_from_beach[] = {&teleporter_beach_to_village, NULL};
static const struct teleporter * teleporter_from_village[] = {&teleporter_village_to_house1,&teleporter_village_right,&teleporter_village_left,&teleporter_village_to_beach,NULL};

static const struct teleporter ** teleporters[3] = {
  teleporter_from_house,teleporter_from_beach,teleporter_from_village
  };

byte reverse_dir(byte dir){
  switch (dir){
    case DIR_UP: return DIR_DOWN;
    case DIR_DOWN: return DIR_UP;
    case DIR_LEFT: return DIR_RIGHT;
    case DIR_RIGHT: return DIR_LEFT;
  }
}

void chara_change_action(struct character* c, byte act){
  if (act!=c->action){
    c->frame = 0;
    c->action = act;
  }
}

void chara_advance_frame(struct character * c){
  struct character_pose* p = get_chara_pose(c);
  c->frame++;
  if (c->frame >= p->frames) c->frame = 0;  
}

byte target_tile(byte x, byte y, byte dir){
      switch(dir){
        case DIR_LEFT: x = x-1;break;
        case DIR_RIGHT: x= x+1;break;
        case DIR_UP: y = y-1;break;
        case DIR_DOWN: y = y+1;break;
      }
      if (x>15 || y >15) return 0;
      return game_maps[current_map][x+y*8];
}

void chara_move(struct character * c,byte dir){
  bool moving = !(dir == DIR_NONE);
  if (c->progress == 0)
  {
    /*if (moving ){//collision detection
      if((dir == DIR_LEFT && c->x == 0)||
         (dir == DIR_RIGHT && c->x >= 7)||
         (dir == DIR_UP && c->y == 0)||
         (dir == DIR_DOWN && c->y >= 7)){
          moving = false;
         }
    }*/
    /*if (moving == true){
      if (!(can_go(dir,game_collision_map[hero.y][hero.x]))){
        moving = false;
      }
    }*/
    if (moving == true){


      if(!(can_go(target_tile(c->x,c->y,dir)))){
        moving = false;
      }
    }
    if (moving == true){
      if (c->dir == dir){
        c->progress = 1;
      }else{
        c->dir = dir;
      }
      chara_change_action(&hero,ACT_WALK);
    }else{
      chara_change_action(&hero,ACT_IDLE);
      if (dir != DIR_NONE){
        c->dir = dir;
      }
    }
  }else{
    if(c->progress == 15){
      switch(c->dir){
        case DIR_UP: c->y--;break;
        case DIR_DOWN: c->y++;break;
        case DIR_LEFT:c->x--;break;
        case DIR_RIGHT:c->x++;break;
      }
      c->progress=0;
    }else{
      c->progress++;
    }
  }
}

void draw_chara(struct character * c){
  char x = c->x*16;
  char y = c->y*16;
  char* white;
  char* black;
  struct character_pose* p = get_chara_pose(c);

  switch (c->dir){
      case 0:  y+=c->progress;
        break;
      case 1: x-=c->progress;break;
      case 2: y-=c->progress;break;
      case 3: x+=c->progress;break;
  }
  u8g2.setBitmapMode(1);
  u8g2.setDrawColor(0);
  u8g2.drawXBM(x,y,16,16,p->black[c->dir]+c->frame*32);
  u8g2.setDrawColor(1);
  u8g2.drawXBM(x,y,16,16,p->white[c->dir]+c->frame*32);
}

struct buttons{
  bool up;
  bool down;
  bool right;
  bool left;
  bool x;
  bool y;
  bool a;
  bool b;
} buttons;

void init_buttons(){
  pinMode(3,OUTPUT);
  pinMode(D6,OUTPUT);
  digitalWrite(3,HIGH);
  digitalWrite(D6,HIGH);
  pinMode(D0,INPUT);
  pinMode(D1,INPUT);
  pinMode(D3,INPUT);
  pinMode(D4,INPUT);
  digitalWrite(D0,HIGH);
  digitalWrite(D1,HIGH);
  digitalWrite(D3,HIGH);
  digitalWrite(D4,HIGH);
}



void setup(void) {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output

  /* U8g2 Project: SSD1306 Test Board */
  //pinMode(10, OUTPUT);
  //pinMode(9, OUTPUT);
  //digitalWrite(10, 0);
  //digitalWrite(9, 0);		

  /* U8g2 Project: T6963 Test Board */
  //pinMode(18, OUTPUT);
  //digitalWrite(18, 1);	
  //u8g2.setBusClock(8000000);
  u8g2.setBusClock(1000000);
  u8g2.begin();  
  init_buttons();
}

void read_buttons_bread(){
  digitalWrite(3,LOW);
  auto enabled = LOW;
  buttons.down = (enabled == digitalRead(D0));
  buttons.a = (enabled == digitalRead(D1));
  buttons.right = (enabled == digitalRead(D3));
  buttons.b = (enabled == digitalRead(D4));
  digitalWrite(3,HIGH);
  digitalWrite(D6,LOW);
  buttons.left = (enabled == digitalRead(D0));
  buttons.x = (enabled == digitalRead(D1));
  buttons.up = (enabled == digitalRead(D3));
  buttons.y = (enabled == digitalRead(D4));
  digitalWrite(D6,HIGH);
}

void read_buttons(){
  digitalWrite(3,LOW);
  auto enabled = LOW;
    delayMicroseconds(50);      // pauses for 50 microseconds
/*  buttons.y = (enabled == digitalRead(D1));
buttons.x =   (enabled == digitalRead(D3));
buttons.b =    (enabled == digitalRead(D4));
buttons.a =  (enabled == digitalRead(D0));
 */
  buttons.down = (enabled == digitalRead(D0));
  buttons.a = (enabled == digitalRead(D1));
  buttons.right = (enabled == digitalRead(D3));
  buttons.b = (enabled == digitalRead(D4));
  digitalWrite(3,HIGH);
  digitalWrite(D6,LOW);
    delayMicroseconds(50);      // pauses for 50 microseconds
  buttons.left = (enabled == digitalRead(D0));
  buttons.x = (enabled == digitalRead(D1));
  buttons.up = (enabled == digitalRead(D3));
  buttons.y = (enabled == digitalRead(D4));
/*buttons.down =   (enabled == digitalRead(D1));
buttons.up =    (enabled == digitalRead(D3));
buttons.right =  (enabled == digitalRead(D4));
buttons.left = (enabled == digitalRead(D0));*/
  digitalWrite(D6,HIGH);
}
//                     012234566789901233456778901123455
static char text[] =  " o\no o\n o\nX o\nY o\nA o\nB o\n";

void print_buttons(){
  if (buttons.up) text[1] = 'x'; else text[1] = 'o'; 
  if (buttons.down) text[8] = 'x'; else text[8] = 'o'; 
  if (buttons.left) text[3] = 'x'; else text[3] = 'o'; 
  if (buttons.right) text[5] = 'x'; else text[5] = 'o';
  if (buttons.x) text[12] = 'x'; else text[12] = 'o'; 
  if (buttons.y) text[16] = 'x'; else text[16] = 'o'; 
  if (buttons.a) text[20] = 'x'; else text[20] = 'o'; 
  if (buttons.b) text[24] = 'x'; else text[24] = 'o'; 
}
 
static bool need_redraw = true;

void draw_dialog(bool top,char* line1, char* line2, char* line3){
  u8g2.setFontMode(0);
  u8g2.setDrawColor(0);

  byte y = top? 2:82;
  u8g2.drawRBox(2,y,124,44,7);

  
  u8g2.setDrawColor(1);
  u8g2.drawRFrame(2,y,124,44,7);
  
  u8g2.setFont(u8g2_font_crox1h_tr);
  u8g2.drawStr(5,y+13,line1);
  u8g2.drawStr(5,y+13+13,line2);
  u8g2.drawStr(5,y+13+13+13,line3);

}

void step_text_test(){
  u8g2.clearBuffer();          // clear the internal memory
  draw_dialog(true,"Hello voyager.","Have you seen","my ducks?");
  draw_dialog(false,"I can not find them.","They ran away.","help me please");
  u8g2.sendBuffer();
}

void step_badge(){
  static const byte BADGE_MEO    = 0;
  static const byte BADGE_KOSSE  = 1;
  static const byte BADGE_TIFUR  = 2;
  static const byte BADGE_BEAVER = 3;
  static const byte BADGE_MAX_N  = 4;
  static int badge = 2;
  static bool pressed = false;
  
  if (buttons.y){
    pressed = true;
  }else{
    if (pressed == true){
      need_redraw = true;
      pressed = false;
      badge++;
      if (badge >= BADGE_MAX_N) badge = 0;
    }
  }
  if (need_redraw){
  const unsigned char * img;
  switch(badge){
    case BADGE_MEO: img = kasil_stone_bits;break;
    case BADGE_KOSSE : img = kasil_bits;break;
    case BADGE_TIFUR : img = badge_tifur_bits;break;
    case BADGE_BEAVER : img = beaver_bits;break;
  }
    u8g2.clearBuffer();        
    u8g2.setBitmapMode(0);
    u8g2.setDrawColor(0);
    u8g2.drawXBMP(0,0, kasil_stone_width, kasil_stone_height, img);
    u8g2.sendBuffer();
    need_redraw = false;
  }
}




void step_game(){
  static char frame = 0;
  byte dir = DIR_NONE;
  bool teleport = false;
  bool dialog = true;

  chara_advance_frame(&hero);

    //standing on teleport tile 
    for(byte i = 0; teleporters[current_map][i]!=NULL; i++){
      const struct teleporter * cur = teleporters[current_map][i];
      byte edge_pos = 0;
      if(cur->source_x==-1&&cur->source_y==-1){
        //teleportation on full edge
        if (cur->source_dir == hero.dir){
        switch(cur->source_dir){
          case DIR_UP:  if (hero.y == -1) {teleport = true; edge_pos = hero.x;} break; 
          case DIR_DOWN:if (hero.y == 8) {teleport = true; edge_pos = 8 - hero.x;} break;
          case DIR_LEFT:if (hero.x == -1) {teleport = true; edge_pos = 8 - hero.y;} break;
          case DIR_RIGHT:if(hero.x == 8) {teleport = true; edge_pos = hero.y;} break;
        }
        }
      }else{
        if(cur->source_x == hero.x && cur->source_y == hero.y && ( cur->source_dir == DIR_NONE || cur->source_dir == hero.dir)){
          teleport = true;
        }
      }
      if (teleport){
        if(cur->target_x == -1 && cur->target_y == -1){
          switch (cur->target_dir){
            case DIR_UP: hero.dir = DIR_DOWN;hero.x = edge_pos; if (cur->target_move){hero.y = -1;hero.progress = 1;}else{hero.y = 0;}break;
            case DIR_DOWN: hero.dir = DIR_UP;hero.x = 8-edge_pos; if (cur->target_move){hero.y = 8; hero.progress = 1;}else{hero.y = 7;}break;
            case DIR_LEFT: hero.dir = DIR_RIGHT; hero.y = 8-edge_pos; if (cur->target_move){hero.x = -1;hero.progress = 1;}else{hero.x = 0;}break;
            case DIR_RIGHT: hero.dir = DIR_LEFT; hero.y = edge_pos; if (cur->target_move){hero.x = 8; hero.progress = 1;}else{hero.x = 7;}break;
            default: hero.dir = DIR_DOWN; hero.x = 4; hero.y = 4;break;
          }
        }else{
          hero.dir = cur->target_dir;
          hero.x = cur->target_x;
          hero.y = cur->target_y;
          hero.progress = cur->target_move?1:0;
        }
        current_map = cur->target_map;
        break;
      }
    }


if (teleport){
    u8g2.clearBuffer();          // clear the internal memory

    u8g2.setDrawColor(0);

    u8g2.setBitmapMode(0);
    u8g2.drawBox(0,0,128,128);
}else{
    if (buttons.up != buttons.down){
      if (buttons.up) dir = DIR_UP;
      else dir = DIR_DOWN;
    }else if(buttons.left != buttons.right){
      if (buttons.left) dir = DIR_LEFT;
      else dir = DIR_RIGHT;
    }
    chara_move(&hero,dir);
    u8g2.clearBuffer();          // clear the internal memory

    u8g2.setDrawColor(0);

    u8g2.setBitmapMode(0);

    u8g2.setFontMode(0);
    for (char i = 0;i<8;i++){
      for (char j = 0;j<8;j++){
        const unsigned char*img;
        byte tile = game_maps[current_map][j*8+i];
        if (tile>=0xfd){
          img = animated2[tile-0xfd]+(frame/8%2)*32;
        }else if (tile>=0xf0){
          img = animated[tile-0xf0]+(frame/4%4)*32;
        }else{
          img = tiles[tile];
        }
        u8g2.drawXBM(i*16,j*16,16,16,img);
      }
    }
    draw_chara(&hero);
    
}
  if(false){
  char buf[40];
  sprintf(buf,"x=%d y=%d d=%d\0",hero.x,hero.y,hero.dir);
  u8g2.setDrawColor(1);
  u8g2.setFontMode(0);
  u8g2.setFont(u8g2_font_crox1h_tr);
  u8g2.drawStr(0,120,buf);
  }
  
  u8g2.sendBuffer();          // transfer internal memory to the display
  frame++;
}

static const byte MODE_BADGE=0;
static const byte MODE_GAME =1;
static const byte MODE_TEXT =2;
static const byte MODE_MAX_N=3;
static const byte MODE_DEBUG = 4;
void step_debug(){
      u8g2.clearBuffer();          // clear the internal memory
  u8g2.setDrawColor(0);
      u8g2.setFontMode(0);
    u8g2.setFont(u8g2_font_crox1h_tr);
  print_buttons();
    u8g2.drawStr(0,14,text);
    u8g2.drawStr(0,28,text+3);
    u8g2.drawStr(0,42,text+7);
    u8g2.drawStr(0,56,text+10);
    u8g2.drawStr(0,70,text+14);
    u8g2.drawStr(0,84,text+18);
    u8g2.drawStr(0,98,text+22);
  u8g2.setDrawColor(1);
  
  u8g2.setFont(u8g2_font_crox1h_tr);
    char text2[] = "000000";
    text2[0]+= sizeof(char);
    text2[1]+= sizeof(int); 
    text2[3]+= sizeof(int*);
    u8g2.drawStr(45,14,text2);

  u8g2.sendBuffer();          // transfer internal memory to the display
}

void loop(void) {
  static byte m = MODE_DEBUG;
  static bool pressed = false;
  read_buttons();
  
  if (buttons.x){
    pressed = true;
  }else{
    if (pressed == true){
      need_redraw= true;
      pressed = false;
      m++;
      if (m >= MODE_MAX_N) m = 0;
    }
  }
  switch(m){
    case MODE_BADGE: step_badge();break;
    case MODE_GAME : step_game();break;
    case MODE_TEXT : step_text_test();break;
    case MODE_DEBUG:
    default: step_debug();
  }
}