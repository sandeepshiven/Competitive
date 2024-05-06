/*

Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2


https://leetcode.com/problems/max-consecutive-ones/description/

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i<n; ){
            int j = i;
            while(j < n && nums[j] == 1){
                j++;
            }
            cnt = max(cnt, j-i);
            if(j == i) i++;
            else i = j;
        }
        return cnt;

    }

    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0, maxi = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == 1){
                cnt++;
                maxi = max(maxi, cnt);
            }
            else{
                cnt = 0;
            }
        }
        return maxi;

    }
};