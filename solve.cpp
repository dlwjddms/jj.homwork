//
//  main.cpp
//  solve
//
//  Created by 박서현 on 2018. 6. 1..
//  Copyright © 2018년 박서현. All rights reserved.
//


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
