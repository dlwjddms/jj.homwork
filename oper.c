oper>
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

