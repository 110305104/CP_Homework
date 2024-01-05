#pragma warning( disable : 4996 )
#include<iostream> 
#include<math.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;

	int U[1000], ZN[1000];

	long int Max_P = 0;

	for (int i = 0; i < n; i++) {
		cin >> U[i] >> ZN[i];
	}

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (j == k)	continue;
				else
				{
					long int num = min(U[j]/a,ZN[k]/b);
					Max_P = max( Max_P,num * (a * 92 + b * 30) * c);
				}
			}
		}
	}

	cout << Max_P;
	return 0;
}