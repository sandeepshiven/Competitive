/*

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]

https://leetcode.com/problems/move-zeroes/description/

*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();

        
        int i = 0, j=-1;

        while(i<n && j<n){
            // stop at first zero
            if(nums[i] == 0){
                
                // assign j to i's value as we want to traverse further to find non-zero
                // this is only for first time as after that we'll be going forward only.
                if(j == -1) j = i;
                
                // stop at the non-zero index
                while(j<n && nums[j] == 0) j++;

                // array is traversed to end and all last elements are zero
                if(j == n) break;

                // swapping zero with non-zero
                swap(nums[j], nums[i]);
            }
            i++;
        }

    }
};