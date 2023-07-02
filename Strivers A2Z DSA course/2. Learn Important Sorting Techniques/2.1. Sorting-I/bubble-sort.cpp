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
        bool flag = true;
        for(int j=0; j<n-i-1; j++){
            if(arr[j+1] < arr[j]){
                flag = false;
                swap(arr[j+1], arr[j]);
            }
        }
        if(flag){
            break;
        }
    }
    cout << "Sorted array: ";
    for(auto x: arr){
        cout << x << ", ";
    }
    cout << "\n";
    return 0;
}