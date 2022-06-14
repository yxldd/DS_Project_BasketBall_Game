#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define  stack_maxsize 100
typedef int Status;
typedef struct node1//栈的元素
{
	int x;
	int y;
	char c;
}Stacknode;
typedef struct node2//栈
{
	int top;
	Stacknode data[100];
}Stack;
typedef struct node3//顺序表
{
	int len;
	int v[40];
}Sqlist;

Stack S;
Sqlist L;

int flag;
Status visit(Stacknode s);//输出元素s的字符值
Status StackTraverse(Stack S);//遍历输出整个栈
Status StackInit(Stack *S);//初始化
Status StackClear(Stack *S);//清零
Status StackEmpty(Stack S);//检查栈是否为空
Status StackPush(Stack *S,Stacknode e);//将元素e压入栈顶
Status StackPop(Stack *S,Stacknode* e);//将栈顶元素弹出并存到e中
Status ListInsert(int e, int pos);//顺序表在pos位置插入e
Status ListEmpty();//检查顺序表是否为空
Status ListInit1();//不同速度模式下的初始化
Status ListInit2();
Status ListGetElem(int i, int* e);//获取i位置的值，存到e中
Status ListDelete(int i);//删除i位置的元素
Status ListTraverse();//遍历输出整个顺序表
