#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*

Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

https://leetcode.com/problems/maximum-product-subarray/description/

*/


class Solution {
public:
// observation based solution
// 1. all elements are +ve - ans will multiplication of all
// 2. even -ve elements - again ans will be multi all
// 3. odd -ve elements - ans will be either prefix or suffix
// 4. if zeros are present then treat as seperate arrays
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = INT_MIN, suffix = 1, prefix = 1;
        for(int i=0; i<n; i++){
            
            prefix *= nums[i];
            suffix *= nums[n-1-i];
            maxProduct = max(suffix, prefix);

            // reseting as 1 because it'll be start of a new array once we encounter a zero
            if(prefix == 0){
                prefix = 1;
            }
            else if(suffix == 0){
                suffix = 1;
            }
            
        }   

        return maxProduct;   
    }

    
};











