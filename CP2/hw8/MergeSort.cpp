#include <iostream>
#include <algorithm>

using namespace std;


void mergeSort(int arr1[],int arr2[],int n,int m){

    int i=0;
    int j=0;

    while(i<n&&j<m){
        if(arr1[i]<arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
        }else{
            cout<<arr2[j]<<" ";
            j++;
        }
    }

    if(i<n){
        for(;i<n;i++){
            cout<<arr1[i]<<" ";
        }
    }else{
        for(;j<m;j++){
            cout<<arr2[j]<<" ";
        }
    }



}


int main(){
    int n,m;
    
    cin>>n;
    int arr1[n];
   
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }

    cin>>m;
    int arr2[m];
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }

    mergeSort(arr1,arr2,n,m);

    return 0;


}