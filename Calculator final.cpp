//
//  Calcuator final.cpp
//  계산기 최종
//
//  Created by 박서현이정은이한별 on 2018. 6. 1..
//  Copyright © 2018년 박서현이정은이한별. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>


#define SIZE 200


char input[SIZE] = { 0 };


int length = 0;


void print () {
    for (int i = 0; i < length; i++) {
        printf("%c", input[i]);
    }
    printf("\n");
}


int oper(char value[SIZE], int count) {
    int  s[SIZE] = { 0 };
    int  num_s = 0;
    char c[SIZE] = { 0 };
    int num_c= 0;
    int  cnt = 0;

    bool divormul = false ;
    for (int j = 0; j < count; j++) {
        if ('0' <= value[j] && value[j] <= '9') {
            cnt *= 10;
            cnt += value[j] - '0';
        }
        else if (value[j] == '-' || value[j] == '+') {
            s[num_s] = cnt;
            cnt = 0;
            num_s++;
            
            if (divormul) {
                int tmp = 0;
                if (c[num_c - 1] == '*') {
                    tmp = s[num_s - 2] * s[num_s - 1];
                }
                else if (c[num_c - 1] == '/') {
                    tmp = s[num_s - 2] / s[num_s - 1];
                }
                divormul = false;
                c[num_c - 1] = 0;
                num_c--;
                
                s[num_s - 1] = 0;
                s[num_s - 2] = 0;
                num_s -= 2;
                
                s[num_s] = tmp;
                num_s++;
            }
            
            c[num_c] = value[j];
            num_c++;
            
        }
        else if (value[j] == '*' || value[j] == '/') {
            s[num_s] = cnt;
            cnt = 0;
            num_s++;
            
            if (divormul) {
                int tmp = 0;
                if (c[num_c - 1] == '*') {
                    tmp = s[num_s - 2] * s[num_s - 1];
                }
                else if (c[num_c - 1] == '/') {
                    tmp = s[num_s - 2] / s[num_s - 1];
                }
                c[num_c - 1] = 0;
                num_c--;
                
                s[num_s - 1] = 0;
                s[num_s - 2] = 0;
                num_s -= 2;
                
                s[num_s] = tmp;
                num_s++;
            }
            
            c[num_c] = value[j];
            num_c++;
            
            divormul = true;
        }
        if (j == count - 1) {
            s[num_s] = cnt;
            cnt = 0;
            num_s++;
            
            if (divormul) {
                int tmp = 0;
                if (c[num_c - 1] == '*') {
                    tmp = s[num_s - 2] * s[num_s - 1];
                }
                else if (c[num_c - 1] == '/') {
                    tmp = s[num_s - 2] / s[num_s - 1];
                }
                divormul = false;
                c[num_c - 1] = 0;
                num_c--;
                
                s[num_s - 1] = 0;
                s[num_s - 2] = 0;
                num_s -= 2;
                
                s[num_s] = tmp;
                num_s++;
            }
        }
    }
    
    int result = s[0];
    for (int i = 0; i < num_c; i++) {
        if (c[i] == '+') {
            result += s[i + 1];
        }
        else if (c[i] == '-') {
            result -= s[i + 1];
        }
    }
    return result;
}


void solve() {

    // 1순위 : 괄호
    // 2순위 : 곱셈나눗셈
    // 3순위 : 덧셈뺄셈
    int arr[SIZE] = { 0 };
    int num_arr = 0;
    char value[SIZE] = { 0 };
    int count = 0;
    int start = 0;
    int end = 0;
    int result = 0;
    for (int i = 0; i < length; i++) {
        if (input[i] == '(') {
            memset(&value[0], 0, sizeof(value));
            count = 0;
            start = i;
        }
        else if (input[i] == ')') {
            result = oper(value, count);
            end = i;
            for (int j = 0; j < SIZE; j++) {
                if (j < start) {
                    arr[num_arr] = input[j];
                    num_arr++;
                }
                else if (j == start) {
                    char resultArr[11] = { 0 };
                    sprintf(resultArr,"%d", result);
                    for (int k = 0; k < 11; k++) {
                        if (resultArr[k] != 0) {
                            arr[num_arr] = resultArr[k];
                            num_arr++;
                        }
                        else {
                            break;
                        }
                    }
                }
                else if (j > end && input[j] != 0) {
                    arr[num_arr] = input[j];
                    num_arr++;
                }
            }
            break;
        }
        else {
            value[count] = input[i];
            count++;
        }
    }
    memset(&input[0], 0, sizeof(input));
    length = 0;
    
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == 0) {
            break;
        }
        else {
            input[i] = arr[i];
            length++;
        }
    }
}

int main(int argc, const char * args[]) {
    while (1) {
        printf("수식을 입력하세요. 종료를 원하시면 exit를 입력하세요.\n");
        printf("입력 : ");
        scanf("%s", input);
        if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't') {
            break;
        }
        else {
            for (int i = 0; i < SIZE; i++) {
                if (input[i] == 0) {
                    length = i;
                    break;
                }
            }

            print();
            bool unknown = false;
            for (int i = 0; i < length; i++) {
                if (!('0' <= input[i] && input[i] <= '9') &&
                    input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' &&
                    input[i] != '(' && input[i] != ')') {
                    unknown = true;
                }
            }
            if (unknown) {
                printf("잘못된 입력 값이 있습니다.\n");
            }
            else {
                while (1) {
                    bool brac = false;
                    for (int i = 0; i < length; i++) {
                        if (input[i] == '(') {
                            brac = true;
                            break;
                        }
                    }
                    if (brac) {
                        solve();
                        print();
                    }
                    else {
                        break;
                    }
                }
                int result = oper(input, length);
                printf("결과는 %d입니다.\n", result);
            }
        }
        memset(&input[0], 0, sizeof(input));
        length = 0;
    }
    printf("종료합니다.\n");
    
    
    return 0;
}
