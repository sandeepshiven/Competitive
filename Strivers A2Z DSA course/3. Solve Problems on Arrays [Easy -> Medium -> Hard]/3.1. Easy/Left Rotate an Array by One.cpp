#include<bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int>& arr, int n) {
    int x = arr[0];
    for(int i=0; i<n-1; i++){
        arr[i] = arr[i+1]; // shifting every element by 1 place
    }
    arr[n-1] = x; // copying the first element to the last place
    return arr;
}

int main(){
  
    

    return 0;
}