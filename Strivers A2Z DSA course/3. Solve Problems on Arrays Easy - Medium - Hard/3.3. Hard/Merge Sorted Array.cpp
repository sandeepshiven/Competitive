#include<bits/stdc++.h>
using namespace std;

int main() {



    return 0;
}

/*

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.



Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

https://leetcode.com/problems/merge-sorted-array/description/

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = 0, j = 0;
        vector<int>temp;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            }
            else {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        while (i < m) {
            temp.push_back(nums1[i]);
            i++;
        }
        while (j < n) {
            temp.push_back(nums2[j]);
            j++;
        }

        nums1.clear();
        copy(temp.begin(), temp.end(), back_inserter(nums1));
    }

    // for inplace and array size is exactly m and n
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m-1, j = 0;
        
        while (i > 0 && j < n) {
            // all smaller elements are in nums1
            if (nums1[i] > nums2[j]) {
                
                swap(nums1[i], nums2[j]);
                i--, j++;
            }
            // breaking because rest will be in order
            else {
                break;
            }
        }
       sort(nums1.begin(), nums1.end());
       sort(nums2.begin(), nums2.end());
    }
};