#pragma warning( disable : 4996 )
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void move(int n,char A,char B,char C){
	if(n==1){
		printf("move %d from %c to %c\n",n,A,C);
	}else{
		move(n-1,A,C,B);
		printf("move %d from %c to %c\n",n,A,C);
		move(n-1,B,A,C);	
	}
}

int main(){
	int n;
	scanf("%d",&n);
	move(n,'A','B','C');
	return 0;
}
