#include "Print.h"
#include "Ds.h"
#include <stdio.h>
#include <windows.h>
#include <time.h>
extern Stack S1;
extern int flag;
Stack S2;

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int gameover()
{
	if (flag == 1)
		return 1;
	else
		return 0;
}

void print()
{
	while (!StackEmpty(S1))
	{
		Stacknode front;
		StackPop(&S1,&front);
		gotoxy(front.x, front.y);
		printf("%c", front.c);
		StackPush(&S2, front);
	}
}
void print_begin()
{
	FILE* fp;
	fp = fopen("begin.in", "r");
	int i = 0, cnt = 0;
	char c[2000];
	while (fgets(c,2000,fp) != NULL)
	{
		printf("%s\r",c);
	}
	fclose(fp);
}

void print_rules()
{
	FILE* fp;
	fp = fopen("rules.in", "r");
	int i = 0, cnt = 0;
	char c[2000];
	while (fgets(c, 2000, fp) != NULL)
	{
		printf("%s", c);
	}
	fclose(fp);
}

void print_end2()
{
	FILE* fp;
	fp = fopen("end2.in", "r");
	int i = 0, cnt = 0;
	char c[2000];
	while (fgets(c, 2000, fp) != NULL)
	{
		printf("%s", c);
	}
	fclose(fp);
}

void print_now()
{
	FILE* fp;
	fp = fopen("1.in", "r");
	int i = 0, cnt = 0;
	char c[2000];
	while (fgets(c, 2000, fp) != NULL)
	{
		printf("%s", c);
	}
	fclose(fp);
}

void print_end1()
{
	FILE* fp;
	fp = fopen("end1.in", "r");
	int i = 0, cnt = 0;
	char c[2000];
	while (fgets(c, 2000, fp) != NULL)
	{
		printf("%s", c);
	}
	fclose(fp);
}
void print_end3()
{
	FILE* fp;
	fp = fopen("end3.in", "r");
	int i = 0, cnt = 0;
	char c[2000];
	while (fgets(c, 2000, fp) != NULL)
	{
		printf("%s", c);
	}
	fclose(fp);
}
void print_clear()
{
	while (!StackEmpty(S2))
	{
		Stacknode front;
		StackPop(&S2,&front);
		gotoxy(front.x, front.y);
		printf(" ");
	}
}
void print_final()
{
	FILE* fp;
	fp = fopen("his.in", "a+");
	int i = 0, cnt = 0;
	char c[2000];
	while (fgets(c, 2000, fp) != NULL)
	{
		printf("%s", c);
	}

	fclose(fp);
}
void print_recode(int ply1,int ply2)
{
	FILE* fp;
	char s[20];
	time_t timep;
	time(&timep);
	struct tm* p;
	p = gmtime(&timep);
	snprintf(s, 20, "%d-%d-%d %d:%d:%d", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min, p->tm_sec);
	fp = fopen("his.in", "a+");
	fprintf(fp, "%s  ****** plyer1 vs player2 -> %d vs %d ******\n", s, ply1, ply2);
	fclose(fp);
}