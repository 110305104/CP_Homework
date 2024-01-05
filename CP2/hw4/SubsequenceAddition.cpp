#pragma warning( disable : 4996 )
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int arr[1000];//n
		int cSum[1000];//n
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}


		sort(arr, arr + n);


		int flag = 1;
		if (arr[0] != 1)	flag = 0;


		cSum[0] = 1;
		for (int i = 1; i < n; i++) {
			cSum[i] = cSum[i - 1] + arr[i];
		}


		//cout << "\n=======\n";
		//for (int i = 0; i < n; i++) {
		//	cout << arr[i] << " ";
		//}
		//cout << endl;
		//for (int i = 0; i < n; i++) {
		//	cout << cSum[i] << " ";
		//}
		//cout << endl;
		
	
		for (int i = 1; i < n; i++) {
			
			if (arr[i] > cSum[i-1]) {
				flag = 0;
				break;
			}
		}
		if(flag==0)		cout << "NO\n";
		else cout << "YES\n";

		//cout << "\n=======\n";

	}
	return 0;
}