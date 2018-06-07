//
//  main.cpp
//  calculate
//
//  Created by 박서현 on 2018. 6. 8..
//  Copyright © 2018년 박서현. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>


const int NMAX = 1024;
void input(char* inputA, char* inputB)
{
    printf("첫 번째 숫자 입력 : ");
    scanf("%s", inputA);
    printf("두 번째 숫자 입력 : ");
    scanf("%s", inputB);
}



void big_mul(char* inputA, char* inputB)
{
    char mul[NMAX+NMAX+2];
    int len1, len2, mul_len, i,j,k;
    len1 = strlen(inputA);
    len2 = strlen(inputB);
    mul_len=len1+len2;
    memset(mul,0x00,mul_len+2);
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)
        {
            k=mul_len-i-j;
            mul[k]+=(inputA[len1-i-1]-'0')*(inputB[len2-j-1]-'0');
            if(mul[k]>9)
            {
                mul[k-1]+=(mul[k]/10); mul[k]%=10;
            }
        }
    }
    for(i=0;i<=mul_len;i++)
        mul[i]+='0';
    printf("계산값 : ");
    for(i=0;mul[i]=='0';)
    {
        i++;
    }
    printf("%s\n", &mul[i]);
}

int main(void)
{
    char inputA[NMAX+10];
    char inputB[NMAX+10];
    input(inputA, inputB);
    
    printf("\n");
    
    big_mul(inputA,inputB);
    
    return 0;
}
