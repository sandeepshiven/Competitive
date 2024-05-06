#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}


/*

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

https://leetcode.com/problems/majority-element/description/

*/

// moore's voting algo
// uses the fact that the majority element will never be canceled out by other elements
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();

        int ele = nums[0], count = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == ele){
                count++;
            }
            else if(count == 0){
                ele = nums[i];
                count++;
            }
            else{
                count--;
            }
        }

        return ele;


    }
};