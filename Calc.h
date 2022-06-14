#pragma once
#include <stdio.h>
#define Shoty 27
#define Baskety 3
#define Defendery 14
//规定篮筐、防守方、射手的固定高度，定义常亮
int dir;
int flag;

void Calc_Ball(int lastx, int lasty);//根据上一次的球的坐标，计算下次位置
void Calc_Shot(int lastx);//根据上一次的射手的坐标，计算下次位置
void Calc_Defender(int lastx);//根据上一次的防守方的坐标，计算下次位置
void PushBasket(int x, int y);//根据篮筐的中心，计算整个篮筐的位置