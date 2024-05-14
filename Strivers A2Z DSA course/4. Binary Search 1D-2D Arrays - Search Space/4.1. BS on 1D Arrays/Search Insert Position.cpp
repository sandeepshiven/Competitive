#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

https://leetcode.com/problems/search-insert-position/description/

*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        int low =0, high = n-1, index = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                return mid;
            }
            // we need to find the immediate greater element
            else if(nums[mid] > target){
                index = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }

        return index == -1? n: index;
    }
};
