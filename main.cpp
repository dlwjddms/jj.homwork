//
//  main.cpp
//  계산기06
//
//  Created by 박서현 on 2018. 5. 31..
//  Copyright © 2018년 박서현. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define __STACK_H__
#define TRUE 1
#define FALSE 0
#define MAX_STACK 100
#include <string.h>
#define CRT
#define MAX_LEN 100

int priority(int op){
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    else return 3;
}



int Calculator(char *sent)
{
    Stack mstack;
    Stack ostack;
    InitStack(&mstack);
    InitStack(&ostack);
    
    for (int i = 0; i < strlen(sent); i++)
    {
        if (sent[i] > 47 && sent[i] < 58)
        {
            if (sent[i - 1] > 47 && sent[i - 1] < 58)
            {
                int temp = Peek(&mstack);
                Pop(&mstack);
                Push(&mstack, temp * 10 + sent[i] - 48);
            }
            else Push(&mstack, sent[i] - 48);
        }
        else
        {
            if (IsEmpty(&ostack)) Push(&ostack, sent[i]);
            else {
                if (sent[i] == '(') Push(&ostack, sent[i]);
                else if (sent[i] == ')') parenthesis(&mstack, &ostack);
                else if (sent[i] == '*' || sent[i] == '/' )
                {
                    
                    if (Peek(&ostack) == '*')
                    {
                        multiple(&mstack, &ostack);
                        Push(&ostack, sent[i]);
                    }
                    else if (Peek(&ostack) == '/')
                    {
                        division(&mstack, &ostack);
                        Push(&ostack, sent[i]);
                    }
                
                    else Push(&ostack, sent[i]);
                }
            }
        }
    }
    
    cal(&mstack, &ostack);
    return Peek(&mstack);
    
}

void Primecheck(Stack* ms, Stack* os)
{
    int n = Peek(ms);
    Pop(ms);
    for (int i = 2; i * i <= n; i++)
        if (n%i == 0) { Pop(os); Push(ms, 2); return; }
    Pop(os);
    Push(ms, 1);
}

void multiple(Stack* ms, Stack* os)
{
    int i, j;
    i = Peek(ms);
    Pop(ms);
    j = Peek(ms);
    Pop(ms);
    Push(ms, i*j);
    Pop(os);
}

void division(Stack* ms, Stack* os)
{
    int i, j;
    i = Peek(ms);
    Pop(ms);
    j = Peek(ms);
    Pop(ms);
    Push(ms, j / i);
    Pop(os);
}

void remainder(Stack* ms, Stack* os)
{
    int i, j;
    i = Peek(ms);
    Pop(ms);
    j = Peek(ms);
    Pop(ms);
    Push(ms, j % i);
    Pop(os);
}

void concatenation(Stack* ms, Stack* os)
{
    int i, j, temp;
    i = Peek(ms);
    Pop(ms);
    j = Peek(ms);
    Pop(ms);
    temp = i;
    do
    {
        j *= 10;
        temp /= 10;
    } while (temp > 0);
    Push(ms, j + i);
    Pop(os);
}

void plus(Stack* ms, Stack* os)
{
    int i, j;
    i = Peek(ms);
    Pop(ms);
    j = Peek(ms);
    Pop(ms);
    Push(ms, j + i);
    Pop(os);
}

void minus(Stack* ms, Stack* os)
{
    int i, j;
    i = Peek(ms);
    Pop(ms);
    j = Peek(ms);
    Pop(ms);
    Push(ms, j - i);
    Pop(os);
}

void par(Stack* ms, Stack* os)
{
    while (Peek(os) != '(')
    {
        char c = Peek(os);
        if (c == '*') multiple(ms, os);
        else if (c == '/') division(ms, os);
        else if (c == '+') plus(ms, os);
        else if (c == '-') minus(ms, os);
    }
    Pop(os);
}

void cal(Stack* ms, Stack* os)
{
    while (!IsEmpty(os))
    {
        char c = Peek(os);
        if (c == '*') multiple(ms, os);
        else if (c == '/') division(ms, os);
        else if (c == '+') plus(ms, os);
        else if (c == '-') minus(ms, os);
    }
}
