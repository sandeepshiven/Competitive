#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 
 leetcode.com/problems/split-array-largest-sum/description/

*/

class Solution {
public:

    int divide(vector<int>& nums, int maxSum){
        int sum = 0, parts = 1;
        for(auto i: nums){
            if(sum + i <= maxSum){
                sum += i;
            }
            else{
                parts++;
                sum = i;
            }
        }
        return parts;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans;
        while(low <= high){
            int mid = low + (high-low)/2;
            int subArrays = divide(nums, mid);
            if(subArrays == k){
                ans = mid;
                high = mid - 1;
            }
            else if(subArrays > k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        // explanation similar to book allocation problem
        return low;
    }
};