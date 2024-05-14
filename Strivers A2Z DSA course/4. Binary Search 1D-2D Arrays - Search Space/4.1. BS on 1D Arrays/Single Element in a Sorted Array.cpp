#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10

https://leetcode.com/problems/single-element-in-a-sorted-array/description/

*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int low  = 0, high = n-1;

        // return if single element
        if(n == 1){
            return nums[0];
        }
        // first should be equal to second
        else if(nums[0] != nums[1]){
            return nums[0];
        }
        // last should be equal to last second
        else if(nums[n-1] != nums[n-2]){
            return nums[n-1];
        }

        while(low <= high){

            int mid = low + (high - low)/2;
            // cout << nums[mid] << " " << mid << "\n";

            // if the prevouis element is same
            if(mid > 0 && nums[mid] == nums[mid - 1]){
                // check which half has odd no. of elements as only that will contain
                // the single element
                if((mid-1-low)%2 != 0){
                    high = mid - 2; 
                }
                else{
                    low = mid + 1;
                }
            }
            else if(mid < n-1 && nums[mid] == nums[mid+1]){
                if((high - (mid+1))%2 != 0){
                    low = mid + 2;
                }
                else{
                    high = mid - 1;
                }
            }
            // if neither of the sides are equal then it is the single element
            else{
                return nums[mid];
            }

        }

        return -1;


    }

 
    // using index logic,
    // 1, if same element on (even, odd) position then single element will be on right
    // 2. if same element on (odd, even) position then single element will on left
    int singleNonDuplicate2(vector<int>& nums) {
        
        int n = nums.size();
        // as edge casses are covered in below if conditions we can reduce search space
        int low  = 1, high = n-2;

        // return if single element
        if(n == 1){
            return nums[0];
        }
        // first should be equal to second
        else if(nums[0] != nums[1]){
            return nums[0];
        }
        // last should be equal to last second
        else if(nums[n-1] != nums[n-2]){
            return nums[n-1];
        }

        while(low <= high){

            int mid = low + (high - low)/2;
            // cout << nums[mid] << " " << mid << "\n";

            // this would be single
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
                return nums[mid];
            }
            //  we are stading on even pos and checking next odd          we are standing on odd pos and checking previou even
            else if((mid%2 == 0 && nums[mid] == nums[mid+1]) || (mid%2 == 1 && nums[mid] == nums[mid-1])){
                // eleminate left half
                low = mid + 1;
            }
            else{
                // eliminate right half
                high = mid -1;
            }

        }

        return -1;


    }


};
