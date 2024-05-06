#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

https://leetcode.com/problems/subarray-sum-equals-k/description/

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        long long currSum = 0;
        long long res = 0;
        // storing count to get the occrences of x-k in prefix sum as then there will be
        // more than 1 subrray with sum k until i
        unordered_map<long long, long long>mp;
        mp[0]++;
        for(int i=0; i<n; i++){
            currSum += nums[i];
            res += mp[currSum - k];
            mp[currSum]++;           
        } 
        return res;

    }
};