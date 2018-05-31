#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define __STACK_H__
#define TRUE 1
#define FALSE 0
#define MAX_STACK 100
#include <string.h>

int priority(int op){
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    else return 3;
}

void change(char *a, char *b){
   
    ;
}


int cal(char *p){
    int i;
    int stack();
    while (*p){
        if (*p >= '0' && *p <= '9'){
            i = 0;
            do{
                i = i * 10 + *p - '0';
                p++;
            } while (*p >= '0' && *p <= '9');
            push(i);
        }
        else if (*p == '+'){
            push(pop() + pop());
            p++;
        }
        else if (*p == '*'){
            push(pop() * pop());
            p++;
        }
        else if (*p == '-'){
            i = pop();
            push(pop() - i);
            p++;
        }
        else if (*p == '/'){
            i = pop();
            push(pop() / i);
            p++;
        }
        else{
            p++;
        }
    }
    return pop();
}
