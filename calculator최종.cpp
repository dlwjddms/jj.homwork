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


