#include<stdio.h>
#include<windows.h>



int main(){
	
	static char s1[200],s2[200];
	
	int max, sum, t , i , j, k, size_1, size_2;
	
	static int re[200],f1[200],f2[200];
	
	
	
	//버퍼오버플로우 취약점으로 gets->fgets로 변경 
	
	
	printf("First No : ");
	//gets(s1)
	fgets(s1, sizeof(s1)-1,stdin);
	
	printf("Second No : ");
	//gets(s2)
	fgets(s2,sizeof(s2)-1,stdin);
	
	
	
	//fgets는 엔터까지 입력받으므로 1을 뺀다
	//size_1 = strlen(s1);
	//size_2 = strlen(s2);
	
	size_1 = strlen(s1)-1;
	size_2 = strlen(s2)-1;
	
	
	
	printf("size 1 = %d, 2=%d\n", size_1, size_2);
	
	max = size_1 > size_2 ?  size_1-1:size_2-1;
	
	
	
	k=0;
	for (i=size_1-1 ; i>0 ; i--){
		f1[k]=s1[i]-'0';
		k++;
	}
	
	
	
	k=0;
	for(i=size_2-1 ; i>0 ; i--){
		f2[k]=s2[i]-'0';
		k++;
	}
	
	
	
	
	for (i=0 ; i<max ; i++){
		
		sum=f1[i] + f2[i];
		
		if(sum>9){
			re[i]+= sum%10;
			re[i+1]+= sum/10;
		}
		else re[i]+= sum;
	}
	
	
	
	for(i=max ; i>0; i--)
	{
	printf("%d",re[i]);
	}
	
	printf("\n");
	
	
	system("pause");
	return 0;


}
