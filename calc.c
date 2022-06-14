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

void Calc_Ball(int lastx, int lasty)//����Ϊ��һ����������
{
	Stacknode now;//�����µ������Ԫ
	int nowy = lasty -L.v[lasty];//��ȡ�µ�����λ��
	lasty -= L.v[lasty];
	now.x = lastx;//�������Ԫ���и�ֵ
	now.y = nowy;
	now.c= '*';
	StackPush(&S1,now);//ѹ�����ջ
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
