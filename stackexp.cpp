//
//  main.cpp
//  계산기04
//
//  Created by 박서현 on 2018. 5. 29..
//  Copyright © 2018년 박서현. All rights reserved.
//
// stack 사용

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack.h>
#include "stack.h"
#define __STACK_H__

#define TRUE 1
#define FALSE 0
#define MAX_STACK 100

typedef int Data;
typedef struct {
    Data items[MAX_STACK];
    int top;
}Stack;

// Make stack empty.
void InitStack(Stack *pstack);

// Check whether stack is full.
int IsFull(Stack *pstack);

// Check whether stack is empty
int IsEmpty(Stack *pstack);

// Read the item at the top.
Data Peek(Stack *pstack);

// Insert an item at the top.
void Push(Stack *pstack, Data item);

// Remove the item at the top.
void Pop(Stack *pstack);


#endif



void InitStack(Stack *pstack)
{
    pstack->top = -1;
}


int IsFull(Stack *pstack)
{
    if (pstack->top == MAX_STACK - 1) return TRUE;
    else return FALSE;
}


int IsEmpty(Stack *pstack)
{
    if (pstack->top == -1) return TRUE;
    else return FALSE;
}


Data Peek(Stack *pstack)
{
    if (IsEmpty(pstack)) exit(-1);
    return pstack->items[pstack->top];
}


void Push(Stack *pstack, Data item)
{
    if (IsFull(pstack)) exit(-1);
    pstack->items[++(pstack->top)] = item;
}



void Pop(Stack *pstack)
{
    if (IsEmpty(pstack)) exit(-1);
    --(pstack->top);
}


