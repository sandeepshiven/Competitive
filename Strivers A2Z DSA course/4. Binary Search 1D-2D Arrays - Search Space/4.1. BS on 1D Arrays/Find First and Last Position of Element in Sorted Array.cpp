#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                int startIndex = mid, endIndex = mid;
                while(startIndex > 0 && nums[startIndex - 1] == target){
                    startIndex--;
                }
                while(endIndex < n-1 && nums[endIndex + 1] == target){
                    endIndex++;
                }
                return {startIndex, endIndex};
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid-1;
            }
        }
        return {-1, -1};

    }

    // using lower bound and upper bound

    int lower_bound(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0, high = n-1, index = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] >= target){
                index = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }

        }

        return index == -1? n: index;
    }

    int upper_bound(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0, high = n-1, index = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > target){
                index = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }

        }

        return index == -1? n: index;
    }

    vector<int> searchRange1(vector<int>& nums, int target) {

        int n = nums.size();
        int firstIndex = lower_bound(nums, target);
        if(firstIndex == n || nums[firstIndex] != target){
            return {-1, -1};
        }
        else{
            return {firstIndex, upper_bound(nums, target) - 1};
        }
    }


    // using two binary searches
    int first_occur(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0, high = n-1, index = -1;

        // first occurance will be on left
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] >= target){
                if(nums[mid] == target){
                    index = mid;
                }                
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }

        }

        return index ;
    }

    int last_occur(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0, high = n-1, index = -1;

        // last occurance will be on right
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] <= target){
                if(nums[mid] == target){
                    index = mid;
                } 
                low = mid + 1;
                
            }
            else{
                high = mid - 1;
            }

        }

        return index;
    }

    vector<int> searchRange2(vector<int>& nums, int target) {

        int n = nums.size();
        int firstIndex = first_occur(nums, target);
        if(firstIndex == -1){
            return {-1, -1};
        }
        else{
            return {firstIndex, last_occur(nums, target) };
        }
    }

    
};