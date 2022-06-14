#include "Print.h"
#include "Ds.h"
#include <stdio.h>
#include <windows.h>
#include "Calc.h"

extern int flag;
Stack S1;
extern Sqlist L;
extern int dir;

void PushBasket(int x, int y)
{
	Stacknode now;
	int i = 0;
	for (i = x - 1; i <= x + 2; i++)
	{
		now.x = i;
		now.y = y+1;
		now.c = '-';
		StackPush(&S1,now);
	}
	now.x = x - 1;
	now.y = y;
	now.c = '|';
	StackPush(&S1,now);
	now.x = x + 2;
	now.y = y;
	now.c = '|';
	StackPush(&S1,now);
	for (i = x - 1; i <= x + 2; i++)
	{
		now.x = i;
		now.y = y - 1;
		now.c = '-';
		StackPush(&S1,now);
	}
}

void Calc_Ball(int lastx, int lasty)//参数为上一个结点的坐标
{
	Stacknode now;//定义新的输出单元
	int nowy = lasty -L.v[lasty];//获取新的篮球位置
	lasty -= L.v[lasty];
	now.x = lastx;//对输出单元进行赋值
	now.y = nowy;
	now.c= '*';
	StackPush(&S1,now);//压入输出栈
}

void Calc_Shot(int lastx)
{
	Stacknode now;
	now.x = lastx;
	now.y = Shoty;
	now.c = '^';
	StackPush(&S1,now);
}

void Calc_Defender(int lastx)
{
	Stacknode now;
	now.x = lastx;
	now.y = Defendery;
	now.c = '-';
	StackPush(&S1,now);
}

void Calc_Basket(int lastx)
{
	Stacknode now;
	now.x = lastx;
	now.y = Baskety;
	PushBasket(now.x, now.y);
}
