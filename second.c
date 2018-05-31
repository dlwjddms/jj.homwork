/
//  main.cpp
//  
//
//  Created by 이정은  on 2018. 5. 29..
//  Copyright © 2018년 이정은. All rights reserved.
//


#include<stdio.h>
#include<math.h>

int main()
{
    int a, b, c, m;
    char i, d;
    printf("식을 입력해주세요 \n");
    scanf_s("%d %c %d", &a, &i, &b);
    switch (i)
    {
        case ‘+’:
            printf("%d %c %d=%d", a, i, b, a + b);
            c = a + b;
        case ‘-’:
            printf("%d %c %d=%d", a, i, b, a - b);
            c = a - b;
        case ‘*’:
            printf("%d %c %d=%d", a, i, b, a *b);
            c = a * b;
        case ‘/’:
            printf("%d %c %d=%d", a, i, b, a / b);
            c = a / b;
            
        default:
            printf("질못된연산자 입력 다시 실행해 주세요");
            break;
            
    }
    while (1)
    {
        printf("%d", c);
        scanf_s("%c %d", &i, &a);
        
        switch (i)
        {
            case ‘+’:
                printf("%d %c %d=%d", c, i, a, c + a);
                c = c + a;
            case ‘-’:
                printf("%d %c %d=%d", c, i, a, c - a);
                c = c - a;
            case ‘*’:
                printf("%d %c %d=%d", c, i, a, c *a);
                c = c * a;
            case ‘/’:
                printf("%d %c %d=%d", c, i, a, c / a);
                c = c / a;
                
            default:
                printf("질못된연산자 입력 다시 실행해 주세요");
                break;
        }
        printf("계속 하시겠습니끼? \n y/n");
        scanf_s("%c", &d);
        
        if (d == 'y')
        {
            continue;
            
        }
        else
        {
            break;
        }
        
    }
    
    break;
    
    system("pause");
}
