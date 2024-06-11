#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*Given a boolean 2D array of n x m dimensions, consisting of only 1's and 0's, where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).

Example 2:

Input: 
N = 2, M = 2
Arr[][] = {{0, 0}, {1, 1}}
Output: 1
Explanation: Row 1 contains 2 1's (0-based
indexing).

Your Task:  
You don't need to read input or print anything. Your task is to complete the function rowWithMax1s() which takes the array of booleans arr[][], n and m as input parameters and returns the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.
*/

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {

        int rowNum = -1, oneCnt=-1;
        
        for(int i=0; i<n; i++){

            int low =0, high = m-1, idx = -1;
            while(low <= high){
                int mid = low + (high-low)/2;
                if(arr[i][mid] >= 1){
                    idx = mid;
                    high = mid -1;
                }
                else{
                    low = mid + 1;
                }
            }
            if(idx > -1 && m-idx > oneCnt){
                rowNum = i;
                oneCnt = m - idx; 
            } 



        }

        return rowNum;
        
        

	}

};