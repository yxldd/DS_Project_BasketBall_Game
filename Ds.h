#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define  stack_maxsize 100
typedef int Status;
typedef struct node1//ջ��Ԫ��
{
	int x;
	int y;
	char c;
}Stacknode;
typedef struct node2//ջ
{
	int top;
	Stacknode data[100];
}Stack;
typedef struct node3//˳���
{
	int len;
	int v[40];
}Sqlist;

Stack S;
Sqlist L;

int flag;
Status visit(Stacknode s);//���Ԫ��s���ַ�ֵ
Status StackTraverse(Stack S);//�����������ջ
Status StackInit(Stack *S);//��ʼ��
Status StackClear(Stack *S);//����
Status StackEmpty(Stack S);//���ջ�Ƿ�Ϊ��
Status StackPush(Stack *S,Stacknode e);//��Ԫ��eѹ��ջ��
Status StackPop(Stack *S,Stacknode* e);//��ջ��Ԫ�ص������浽e��
Status ListInsert(int e, int pos);//˳�����posλ�ò���e
Status ListEmpty();//���˳����Ƿ�Ϊ��
Status ListInit1();//��ͬ�ٶ�ģʽ�µĳ�ʼ��
Status ListInit2();
Status ListGetElem(int i, int* e);//��ȡiλ�õ�ֵ���浽e��
Status ListDelete(int i);//ɾ��iλ�õ�Ԫ��
Status ListTraverse();//�����������˳���
