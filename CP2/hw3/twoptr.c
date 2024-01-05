#include <stdio.h>
#include<math.h>

int main(){
	int arr[1000000],i=0;
  while(scanf("%d",&arr[i])!=EOF){
    i++;
  }
  
  int l=0,r=1;
  int maxP=0;
  while(r<i){
  	if(arr[l]<arr[r]){
    	int cP=arr[r]-arr[l];
      	if(maxP<cP)	maxP=cP;
    }
    else	l=r;
  
  	r++;
  
  }
  
  printf("%d",maxP);
  
  
  
  
  
}
