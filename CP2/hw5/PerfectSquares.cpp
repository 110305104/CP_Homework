#pragma warning( disable : 4996 )
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

int coins[1001];//k

int coinChange(int n, int amount) {
    int  i, j;
    vector<int> dp(amount + 1);
    for (i = 1; i <= amount; i++) {
        dp[i] = 1e5;
        for (j = 1; j <= n; j++) {
            if (i >= coins[j - 1]) {
                dp[i] = min(dp[i], dp[i - coins[j - 1]] + 1);
            }
        }
    }
    // for(auto &i: dp)cout<<i<<" ";
    if (dp[amount] >= 1e5)return -1;
    return dp[amount];
}




int main() {
	int n;
	cin >> n;
    //ASK
    // if (n >= 600000) {
    //     cout << 4;
    //     return;
    // }
    //
    
	int k = sqrt(n);

    for (int i = 0; i < k; i++) {
        coins[i] = pow(i + 1, 2);
    }
   /* for (int i = 0; i < k; i++) {
        cout<<coins[i]<<" ";
    }*/
    cout << coinChange( k, n)<<endl;

}