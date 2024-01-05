#pragma warning( disable : 4996 )
#include<iostream> 
#include <stdio.h>
#include <string.h>
#include<math.h>

//DP 背包問題

int max(int a, int b) { return (a > b) ? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
	// Making and initializing dp array
	int dp[W + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i < n + 1; i++) {
		for (int w = W; w >= 0; w--) {

			if (wt[i - 1] <= w)

				// Finding the maximum value
				dp[w] = max(dp[w],
					dp[w - wt[i - 1]] + val[i - 1]);
		}
	}
	// Returning the maximum value of knapsack
	return dp[W];
}


using namespace std;
int main() {
	int n;
	cin >> n;
	int len,m;
	for (int i = 0; i < n; i++) {
		cin >> len >> m;
		int val[m];//m
		for (int j = 0; j < m; j++) {
			cin >> val[j];
		}
		if (len == knapSack(len, val, val, m)) {
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}