#define _CRT_SECURE_NO_WARNINGS
#include "Calc.h"
#include "Ds.h"
#include "Print.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>


extern Sqlist L;

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}

int ballx;
int bally;
int sx;
int baskx;
int dx;
int mod;
int x;
int dir;
int bflg;
int ddir;
int ply1,ply2;

void Init()
{
	ballx = 20;
	bally = 40;
	sx = 19;
	baskx = 0;
	dx = 19;
	x = 19;
	dir = 1;
	bflg = 0;
	ddir = 1;
}

void continues()
{
	Init();
	system("cls");
	print_now();
	system("cls");
	print_now();
}

int main()
{
	char c;
	print_begin();
	Init();
	c=_getch();
	switch (c)
	{
		case '1':
			mod = 1;
			break;
		case '2':
			mod = 2;
			break;
		case '3':
			mod = 3;
			break;
		case '4':
			system("cls");
			print_rules();
			system("cls");
			print_rules();
			c = _getch();
			break;
	}
	if (mod == 1)
	{
		ListInit1();
	}
	if (mod == 2)
	{
		ListInit2();
	}
	system("cls");
	print_now();
	system("cls");
	print_now();
	HideCursor();
	int endflg=0;
	while (1)
	{
		while (!_kbhit())
		{
			x += dir * 2;
			if (x > 100)dir = -1;
			if (x < 5)dir = 1;
			dx += ddir ;
			if (dx > 100)ddir = -1;
			if (dx < 5)ddir = 1;
			Calc_Shot(sx);
			PushBasket(x,Baskety);
			Calc_Defender(dx);
			if (bflg == 1)
			{
				Calc_Ball(ballx, bally);
				bally -=L.v[bally];
			}
			print();
			Sleep(500);
			
			if ((ballx == x || ballx == x + 1)&&bally==Baskety)
			{
				ply1++;
				
				Sleep(1000);
				system("cls");
				print_end1();
				if (ply1 + ply2 == 1)
				{
					endflg = 1;
					break;
				}
				c =_getch();
				continues();
				
				
			}
			if ((abs(ballx - dx) <= 1) && (abs(bally - Defendery) <= 2))
			{
				ply2++;
				Sleep(1000);
				system("cls");
				print_end2();
				if (ply1 + ply2 == 1)
				{
					endflg = 1;
					break;
				}
				c = _getch();
				continues();	
			}
			if (bally < Baskety)
			{
				Sleep(1000);
				system("cls");
				print_end3();
				c = _getch();
				continues();
				
			}
			print_clear();
			
		}
		if (endflg == 1)
			break;
		c = _getch();
		switch (c)
		{
		case 'a':
			sx -= 3;
			break;
		case 'd':
			sx += 3;
			break;
		case '1':
			if(mod == 1)
			dx -= 3;
			break;
		case '3':
			if (mod == 1)
			dx += 3;
			break;
		case 's':
			bflg = 1;
			ballx = sx;
			bally = Shoty;
			break;
		}
	
	}
	print_recode(ply1,ply2);
	system("cls");
	print_final();
}