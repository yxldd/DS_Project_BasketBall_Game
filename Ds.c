#include "Ds.h"
#include <stdio.h>
#include <math.h>

extern Sqlist L;

Status visit(Stacknode s)
{
    printf("%c\n", s.c);
    return 1;
}

Status StackTraverse(Stack S)
{
    int i;
    i = 0;
    while (S.top>-1)
    {
        visit(S.data[S.top--]);
    }
    return 1;
}
Status StackInit(Stack *S)
{
   // S.data = (Stacknode*)malloc(stack_maxsize * (sizeof(Stacknode)));
    S->top = -1;
    return 1;
}

Status StackClear(Stack *S)
{
    S->top = -1;
    return 1;
}

Status StackEmpty(Stack S)
{
    if (S.top == -1)
        return 1;
    else
        return 0;
}

Status StackPush(Stack *S,Stacknode e)
{
    if (S->top == stack_maxsize - 1) return 0;
    S->data[++S->top].x = e.x;
    S->data[S->top].y = e.y;
    S->data[S->top].c = e.c;
    return 1;
}

Status StackPop(Stack *S,Stacknode *e)
{
    if (S->top == -1) return 0;
    *e = S->data[S->top];
    S->top--;
    return 1;
}

Status   ListInsert(int e, int pos)
{
    int j = 0;
    if (pos < 1 || pos > L.len + 1)  //无效的参数i
        return 0;
    for (j = L.len; j > pos; j--) //将位置为i的节点及之后的节点后移
        L.v[j] = L.v[j - 1];
    L.v[pos - 1] = e;
    L.len++;
    return 1;
}

Status  ListEmpty()
{
    if (L.len == 0)

        return 1;
    else
        return 0;
}

Status ListInit1()
{
    int i;
    for (i = 0; i < 40; i++)
    {
        L.v[i] = 3;//将顺序表的每一个值赋0
    }
    L.len = 40;
}
Status ListInit2()
{
    int i;
    for (i = 0; i < 40; i++)
    {
        L.v[i] = sqrt(i)+1;//将顺序表的每一个值赋0
    }
    L.len = 40;
}

Status ListGetElem(int i, int *e)
{
    if (i < 0 || i > L.len)
        return 0;
    else
    {
        *e = L.v[i - 1];
        return 1;
    }
}

Status ListDelete(int i)
{
    int j = 0;
    if (i<1 || i>L.len)
        return 0;
    for (j = i; j < L.len; j++)
        L.v[j - 1] = L.v[j];
    L.len--;
    return 1;
}

Status ListTraverse()
{
    int i = 0;
    for (i = 0; i < L.len; i++)
        printf("%d", L.v[i]);
}