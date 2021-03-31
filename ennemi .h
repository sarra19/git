#ifndef ENEMY_H_
#define ENEMY_H_
#include "move.h"
#include "input.h"
#include "Health_System.h"
#include "elements.h" 
typedef struct ENEMY {
  MOVE idle; MOVE run; //MOVE jump;
  MOVE CurrentMove; 
  SDL_Rect PositionRect;
  int w,h,speed,IsJumping,grav,WalkingZoneLength,direction,steps;
  HEALTH health; EVENTS events; }ENEMY;
void Enemy_Initialize(int Yground,ENEMY *enemy, float size);
void Init_Enemies_Positions(float size, ENEMY enemies[]);
void Enemy_Auto_Moving(ENEMY *enemy, ALL_ELEMENTS elements, float size);

void Enemy_Fight(HERO *Hero, ENEMY enemies[], int *EnemiesNumber, ALL_ELEMENTS elements);
#endif
