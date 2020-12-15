#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef struct
{
    int *base;
    int top;
}Opnd;

typedef struct
{
    int *base;
    int top;
}Optr;

void InitOpnd(Opnd *S)
{
    S->base = (int *)malloc(MAX_STACK_SIZE * sizeof(int));

    if (!S->base)
    {
        exit(0);
    }
    S->top = -1;
}

void InitOptr(Optr *S)
{
    S->base = (char *)malloc(MAX_STACK_SIZE * sizeof(char));

    if (!S->base)
    {
        exit(0);
    }
    S->top = -1;
}



void DestroyOpnd(Opnd *S)
{
    if (!S)
    {
        free(S->base);
        free(S);
    }
}

void DestroyOptr(Optr *S)
{
    if (!S)
    {
        free(S->base);
        free(S);
    }
}


int GetOpndTop(Opnd S)
{
    if (S.top > -1)
    {
        return S.base[S.top];
    }
    else
    {
        printf("stack empty, get top error!\n");
        return 0;
    }
}

char GetOptrTop(Optr S)
{
    if (S.top > -1)
    {
        return S.base[S.top];
    }
    else
    {
        printf("stack empty, get top error!\n");
        return 0;
    }
}

void PushOpnd(Opnd *S, int e)
{
    if (S->top < MAX_STACK_SIZE - 1)
    {
        S->top++;
        S->base[S->top] = e;
    }
    else
    {
        printf("stack full, push error!\n");
    }
}

void PushOptr(Optr *S, char e)
{
    if (S->top < MAX_STACK_SIZE - 1)
    {
        S->top++;
        S->base[S->top] = e;
    }
    else
    {
        printf("stack full, push error!\n");
    }
}

void PopOpnd(Opnd *S)
{
    if (S->top > -1)
    {
        S->top--;
    }
    else
    {
        printf("stack empty, pop error!\n");
    }
}

void PopOptr(Optr *S)
{
    if (S->top > -1)
    {
        S->top--;
    }
    else
    {
        printf("stack empty, pop error!\n");
    }
}

void PrintOpnd(Opnd S)
{
    int i;

    if (S.top == -1)
    {
        printf("empty stack!\n");
    }
    else
    {
        for (i = 0; i <= S.top; i++)
        {
            printf("%d ", S.base[i]);
        }
        printf("\n");
    }
}

void PrintOptr(Optr S)
{
    int i;

    if (S.top == -1)
    {
        printf("empty stack!\n");
    }
    else
    {
        for (i = 0; i <= S.top; i++)
        {
            printf("%c ", S.base[i]);
        }
        printf("\n");
    }
}

int OperateNum(int m, int n, char ch)
{
    int result;

    switch(ch)
    {
        case '+':
            result = m + n;
            break;
        case '-':
            result = m - n;
            break;
        case '*':
            result = m * n;
            break;
        case '/':
            result = m / n;
            break;
    }

    return result;
}

int IsNum(char ch)
{
    if (ch > '0' && ch < '9')
        return 1;
    return 0;
}

int GetIndex(char c)
{
    int index = 0;

    switch (c)
    {
        case '+':
            index = 0;
            break;
        case '-':
            index = 1;
            break;
        case '*':
            index = 2;
            break;
        case '/':
            index = 3;
            break;
        case '(':
            index = 4;
            break;
        case ')':
            index = 5;
            break;
        case '#':
            index = 6;
        default:
            break;
    }
    return index;
}
char GetPriority(char c1, char c2)
{
    int m, n;
    const char priority[][7] =
        {
            { '>','>','<','<','<','>','>' },
            { '>','>','<','<','<','>','>' },
            { '>','>','>','>','<','>','>' },
            { '>','>','>','>','<','>','>' },
            { '<','<','<','<','<','=','0' },
            { '>','>','>','>','0','>','>' },
            { '<','<','<','<','<','0','=' },
        };

    m = GetIndex(c1);
    n = GetIndex(c2);

    return priority[m][n];
}

int main()
{
    char s[100];
    char ch;
    int temp, i, n = 0;
    int a, b;
    Opnd OPND;
    Optr OPTR;
    InitOpnd(&OPND);
    InitOptr(&OPTR);
    gets(s);
    for (i = 0; i < strlen(s); i++)
    {
        if (IsNum(s[i]))
        {
            n = n * 10 + (s[i] - '0');
            if (!IsNum(s[i+1]))
            {
                PushOpnd(&OPND, n);
                n = 0;
            }
        }
        else
        {
            if (s[i] == ')')
            {
                while(GetOptrTop(OPTR) != '(')
                {
                    a = GetOpndTop(OPND);
                    PopOpnd(&OPND);
                    b = GetOpndTop(OPND);
                    PopOpnd(&OPND);
                    PushOpnd(&OPND, OperateNum(b, a, GetOptrTop(OPTR)));
                    PopOptr(&OPTR);
                }
                PopOptr(&OPTR);
                continue;
            }

            if (s[i] == '#' && n != 0)
            {
                PushOpnd(&OPND, n);
                n = 0;
            }

            if (OPTR.top >= 1 && OPND.top >= 1 && GetPriority(GetOptrTop(OPTR), s[i]) == '>')
            {
                a = GetOpndTop(OPND);
                PopOpnd(&OPND);
                b = GetOpndTop(OPND);
                PopOpnd(&OPND);
                PushOpnd(&OPND, OperateNum(b, a, GetOptrTop(OPTR)));
                PopOptr(&OPTR);

                if (s[i] == '#' && OPTR.top > -1)
                {
                    while( GetOptrTop(OPTR) != '#')
                    {
                        a = GetOpndTop(OPND);
                        PopOpnd(&OPND);
                        b = GetOpndTop(OPND);
                        PopOpnd(&OPND);
                        PushOpnd(&OPND, OperateNum(b, a, GetOptrTop(OPTR)));
                        PopOptr(&OPTR);
                    }
                }
                else
                    PushOptr(&OPTR, s[i]);
            }
            else
            {

                PushOptr(&OPTR, s[i]);
            }
        }

    }
    printf("result:");
    PrintOpnd(OPND);
    DestroyOpnd(&OPND);
    DestroyOptr(&OPTR);

    return 0;
}
