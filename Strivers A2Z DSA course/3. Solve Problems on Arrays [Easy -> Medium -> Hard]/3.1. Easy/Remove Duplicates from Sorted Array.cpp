#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n) {
	int count=1;
	for(int i=0; i<n-1; i++){
		if(arr[i] != arr[i+1]){
			count++;
		}
	}

	return count;
}

int main(){
  
    

    return 0;
}