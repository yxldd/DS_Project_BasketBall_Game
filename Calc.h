#pragma once
#include <stdio.h>
#define Shoty 27
#define Baskety 3
#define Defendery 14
//�涨���𡢷��ط������ֵĹ̶��߶ȣ����峣��
int dir;
int flag;

void Calc_Ball(int lastx, int lasty);//������һ�ε�������꣬�����´�λ��
void Calc_Shot(int lastx);//������һ�ε����ֵ����꣬�����´�λ��
void Calc_Defender(int lastx);//������һ�εķ��ط������꣬�����´�λ��
void PushBasket(int x, int y);//������������ģ��������������λ��