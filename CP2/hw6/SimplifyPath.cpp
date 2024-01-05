#pragma warning( disable : 4996 )
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack> 
using namespace std;

int main() {
	stack<string> mySTK;

	string tmp;
	cin >> tmp;
	int  j = 0;
	int len = tmp.length();
	for (int i = 0; i < len;) {
        if (tmp[i] == '/') { i++; continue; }
        string temp = "";
        j = i;
        while (j < len && tmp[j] != '/') {
            temp.push_back(tmp[j]);
            j++;
        }
        i = j;
        if (temp == ".") continue;
        else if (temp == ".." && mySTK.empty())   continue;
        else if (temp == ".." && !mySTK.empty())   mySTK.pop();
        else mySTK.push(temp);
	}
    if (mySTK.size() == 0) {
        cout << "/";
        return 0;
    }
    else
    {
        string ans;
        while (!mySTK.empty()) {
            ans = "/" + mySTK.top() + ans;
            mySTK.pop();
        }
        cout << ans;
        return 0;
    }

    
}