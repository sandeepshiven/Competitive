#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1

https://leetcode.com/problems/search-in-rotated-sorted-array/description/

*/

class Solution {
public:

// finding pivot and then applying binary search - not good solution O(n)


    int find_pivot(vector<int>&nums, int n){
        
        
        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                return i;
            }
        }
        return -1;

    }

    int binarySearch(vector<int> &nums, int low, int high, int target){
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int pivot = find_pivot(nums, n);
        if(pivot == -1){
            return binarySearch(nums, 0, n-1, target);
        }
        else{
            int idx = binarySearch(nums, 0, pivot, target);
            if(idx != -1){
                return idx;
            }
            return binarySearch(nums, pivot+1, n-1, target);

        }
        
    }

 // using binary search
    int search2(vector<int>& nums, int target) {
        
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                return mid;
            }
            else{
                // checking if the right side is sorted one or not
                if(nums[mid] <= nums[high]){
                    // proceed only if the target is within the range of this sorted part
                    if(nums[mid] <= target && nums[high] >= target){
                        low = mid + 1;
                    }
                    else{
                        high = mid - 1;
                    }
                }
                else{
                    // above logic
                    if(nums[low] <= target && nums[mid] >= target){
                        
                        high = mid - 1;
                    }
                    else{
                        low = mid + 1;
                    }
                }
            }
        } 

        return -1;
    }

};