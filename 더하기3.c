

#include <stdio.h>
#include <string.h>



#define MAX 256 //�ִ� �ڸ��� <-why?


void main()
{
int count, len1, len2;
char *ptr1, *ptr2;
char num1[MAX+1], num2[MAX+1], sum[MAX+2];

  gets ( num1 );
  gets ( num2 );
  
  
  // ū���� ptr1 ���� �������� ptr2 �� ����
  if ( strlen(num1) < strlen(num2) ) { ptr1 = num2; ptr2 = num1; }
  else { ptr1 = num1; ptr2 = num2; }

  
  len1 = strlen ( ptr1 ); len2 = strlen ( ptr2 );
  
  
  // sum �迭�� �ø������� ����.. ū������ 1�ڸ� ũ�� ����
  sum[0] = '0'; sum[len1+1] = 0x00;
  
  
  
  //string ���¿��� ����, ptr2 - '0' ��.. ptr2�� ���ڸ� ��ġ�� ��ȯ.. �������� �������� ����
  for ( count = 0; count < len2; count++ )
    sum[len1-count] = ptr1[len1-count-1] + (ptr2[len2-count-1] - '0');
    
  for (count=0 ; count < len1; count++ ) 
  	sum[len1-count] = ptr1[len1-count-1];

  /* �ø��� ó���κ� */
  for ( count = len1; count > 0; count-- )
    if ( sum[count] > '9' ) { sum[count-1]++; sum[count] -= 10; }

	printf ( "%s + %s = %s\n", num1, num2, sum );
	printf ( "%s + %s = %s\n", num1, num2, (sum[0] == '0') ? &sum[1] : &sum[0] );
  
  system("pause"); 
}


