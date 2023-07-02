#include<bits/stdc++.h>
using namespace std;

int main(){
  
    int n;
    cout << "Enter array size: ";
    cin >> n;
    cout << "Enter array: ";
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        int j = i;
        while(j>0 && (arr[j-1] > arr[j])){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
    cout << "Sorted array: ";
    for(auto x: arr){
        cout << x << ", ";
    }
    cout << "\n";
    return 0;
}