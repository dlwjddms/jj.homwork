

#include <stdio.h>
#include <string.h>
#define MAX 256 //�ִ� �ڸ���(gets �� ������ �ִ� �ִ����� �ڸ���) 
#define stod(X)(X=='0'?0:X-'0')

void main()
{
int i, len1, len2;

char ptr1[MAX+1], ptr2[MAX+1], sub[MAX+2];//������ �Ȱ�ħ 

	printf("ū ���� ���� ���ּ���. A : ");
	gets ( ptr1 );//num1=A
	printf("���� ���� ���ּ���. B : ");
	gets ( ptr2 );//num2=B
	
  
  
  len1 = strlen ( ptr1 ); 
  len2 = strlen ( ptr2 );
  
  
  

  
  
  // string ���¿��� ��, ptr2 - '0' ��.. ptr2�� ���ڸ� ��ġ�� ��ȯ.. �������� ������ ����.
for ( i = 0; i < len2; i++ )
   {
	 sub[len1-i] =stod( ptr1[len1-i-1] )-stod (ptr2[len2-i-1]-'0' );
	 }
 
 for (; i < len1; i++ ){
  sub[len1-i] = ptr1[len1-i-1];}
  


  // ������ ó����

  for ( i = len1; i > 0; i-- )
   {
	 if ( sub[i] < '0' ) { sub[i-1]--; sub[i] += 10; }
  }
  printf ( "%s - %s = %s\n", ptr1, ptr2, sub );

 
}
