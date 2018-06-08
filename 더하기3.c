

#include <stdio.h>
#include <string.h>



#define MAX 256 //최대 자릿수 <-why?


void main()
{
int count, len1, len2;
char *ptr1, *ptr2;
char num1[MAX+1], num2[MAX+1], sum[MAX+2];

  gets ( num1 );
  gets ( num2 );
  
  
  // 큰수를 ptr1 으로 작은수를 ptr2 로 설정
  if ( strlen(num1) < strlen(num2) ) { ptr1 = num2; ptr2 = num1; }
  else { ptr1 = num1; ptr2 = num2; }

  
  len1 = strlen ( ptr1 ); len2 = strlen ( ptr2 );
  
  
  // sum 배열은 올림값으로 인해.. 큰수보다 1자리 크게 설정
  sum[0] = '0'; sum[len1+1] = 0x00;
  
  
  
  //string 상태에서 더함, ptr2 - '0' 은.. ptr2만 문자를 수치로 변환.. 이중으로 더해짐을 방지
  for ( count = 0; count < len2; count++ )
    sum[len1-count] = ptr1[len1-count-1] + (ptr2[len2-count-1] - '0');
    
  for (count=0 ; count < len1; count++ ) 
  	sum[len1-count] = ptr1[len1-count-1];

  /* 올림값 처리부분 */
  for ( count = len1; count > 0; count-- )
    if ( sum[count] > '9' ) { sum[count-1]++; sum[count] -= 10; }

	printf ( "%s + %s = %s\n", num1, num2, sum );
	printf ( "%s + %s = %s\n", num1, num2, (sum[0] == '0') ? &sum[1] : &sum[0] );
  
  system("pause"); 
}


