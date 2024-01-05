#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    for(int i=0;i<n-1;i++){
        int count=1;
        int Max=arr[i+1];
        for(int j=i+2;j<n;j++){
            if(min(arr[i],arr[j])>Max){
                count++;
                Max=max(Max,arr[j]);
            }
        }
        cout<<count<<" ";

    }
    cout<<"0\n";


}