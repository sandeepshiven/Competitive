#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

https://leetcode.com/problems/kth-missing-positive-number/description/

*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
        int low = 0, high = n-1, ans = -1, mid;
        while(low <= high){
            mid = low + (high-low)/2;
            // this is the number of missing items, so if it is greater than k then it should
            // be present here
            /*
                the answer would be (arr[mid] - (missing - k + 1)) -> (mssing - k + 1) will give how many places we should go back
                missing = arr[mid]-(mid+1)
                on putting this value in equation - arr[mid] - ((arr[mid]-(mid+1)) - k + 1)
                                                -> arr[mid]- arr[mid] + (mid+1) + k - 1
                                                ->  mid + k  

            
            */
            if(arr[mid] - (mid+1) >= k){
                ans = mid+k;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        // if the anwer lies after the last element
        if(ans == -1){
            return (mid+1)+k;
        }
        return ans;

    }
};