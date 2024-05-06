#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*

Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

 15
-7 -8 -16 -4 -8 -5 -7 -11 -10 -12 -4 -6 -4 -16 -10 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.


 https://leetcode.com/problems/maximum-subarray/description/

*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        

        int n = nums.size();
        int maxi = nums[0], currSum=0;
        for(int i=0; i<n; i++){
            currSum += nums[i];
            if(currSum <= 0){
                currSum = 0;
            }            
            maxi = max(maxi, currSum);            
        }

        return  currSum;

    }
};