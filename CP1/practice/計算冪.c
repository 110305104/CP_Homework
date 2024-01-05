#pragma warning( disable : 4996 )
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//遞迴快速冪
int rqpow(int a, int n) {
    if (n == 0)
        return 1;
    else if ((n & 1) == 1)
        return rqpow(a, n - 1) * a;
    else {
        int temp = rqpow(a, n / 2);
        return temp * temp;
    }
}

//非遞迴快速冪
int qpow(int a, int n) {
    int ans = 1;
    while (n > 0) {
        //如果n的當前末位為1
        if ((n & 1) == 1) {
            //ans乘上當前的a
            ans *= a;
        }
        //a自乘
        a *= a;
        //n往右移一位
        n >>= 1;
    }
    return ans;
}


int main(){

	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		printf("%d\n",qpow(n,k)%1007);	
	
	}
	return 0;

}

