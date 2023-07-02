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

    for(int i=0; i<n-1; i++){
        
        int mini = i;

        for(int j=i; j<n; j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
    }
    cout << "Sorted array: ";
    for(auto x: arr){
        cout << x << ", ";
    }
    cout << "\n";
    return 0;
}