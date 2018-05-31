//
//  main.cpp
//  
//
//  Created by 이정은  on 2018. 5. 28..
//  Copyright © 2018년 이정은. All rights reserved.
//


#include<stdio.h>


int main()
{
    int a, b, c, m;
    char i, d;
    while (1)
    {
        printf("식을 입력해주세요 \n");
        scanf_s("%d %c %d", &a, &i, &b);
        m = i;
        switch (m)
        {
            case 43:
                printf("%d %c %d=%d", a, i, b, a + b);
                c = a + b;
            case 45:
                printf("%d %c %d=%d", a, i, b, a - b);
                c = a - b;
            case 42:
                printf("%d %c %d=%d", a, i, b, a *b);
                c = a * b;
            case 47:
                printf("%d %c %d=%d", a, i, b, a / b);
                c = a / b;
                
            default:
                printf("질못된연산자 입력 다시 실행해 주세요");
                break;
                
        }

