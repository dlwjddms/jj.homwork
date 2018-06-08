

#include <stdio.h>
#include <string.h>
#define MAX 256 //최대 자릿수(gets 가 받을수 있는 최대한의 자릿수) 
#define stod(X)(X=='0'?0:X-'0')

void main()
{
int i, len1, len2;

char ptr1[MAX+1], ptr2[MAX+1], sub[MAX+2];//덧셈꺼 안고침 

	printf("큰 수를 먼저 쳐주세요. A : ");
	gets ( ptr1 );//num1=A
	printf("작은 수를 쳐주세요. B : ");
	gets ( ptr2 );//num2=B
	
  
  
  len1 = strlen ( ptr1 ); 
  len2 = strlen ( ptr2 );
  
  
  

  
  
  // string 상태에서 뺌, ptr2 - '0' 은.. ptr2만 문자를 수치로 변환.. 이중으로 빼짐을 방지.
for ( i = 0; i < len2; i++ )
   {
	 sub[len1-i] =stod( ptr1[len1-i-1] )-stod (ptr2[len2-i-1]-'0' );
	 }
 
 for (; i < len1; i++ ){
  sub[len1-i] = ptr1[len1-i-1];}
  


  // 내림값 처리부

  for ( i = len1; i > 0; i-- )
   {
	 if ( sub[i] < '0' ) { sub[i-1]--; sub[i] += 10; }
  }
  printf ( "%s - %s = %s\n", ptr1, ptr2, sub );

 
}
