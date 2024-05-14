#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 


https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0, high = n -1, res = INT_MAX;

        while(low <= high){
            int mid = low + (high - low)/2;

            // the sorted part of the arrray may or may not contain the smallest
            // so we take smallet from the sorted part and discard it as it is already sorted
            // and we got the minimum  from that part
            if(nums[mid] >= nums[low]){
                res = min(res, nums[low]);
                low = mid + 1;
            }
            else{
                res = min(nums[mid], res);
                high = mid - 1;
            }
        }
        return res;


    }
};


