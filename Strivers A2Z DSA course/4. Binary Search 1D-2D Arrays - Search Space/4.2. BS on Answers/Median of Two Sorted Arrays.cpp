#include<bits/stdc++.h>
using namespace std;

int main() {



    return 0;
}

/*

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

https://leetcode.com/problems/median-of-two-sorted-arrays/description/

*/
class Solution {
public:

    // brute force solution - similar to merge function of merge sort
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        vector<int>nums3;

        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                nums3.push_back(nums1[i]);
                i++;
            }
            else {
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        while (i < n) {
            nums3.push_back(nums1[i]);
            i++;
        }
        while (j < m) {
            nums3.push_back(nums2[j]);
            j++;
        }

        int k = nums3.size();
        if (k % 2 == 0) {
            return (double)(nums3[k / 2] + nums3[(k / 2) - 1]) / (double)2;
        }
        else {
            return nums3[k / 2];
        }

    }

    // space optimized - brute force solution - similar to merge function of merge sort
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        vector<int>nums3;
        int median = (n + m) / 2;
        int ele1, ele2, count = 0;

        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                count++;
                if ((n + m) % 2 == 0) {
                    if (count == median - 1) {
                        ele1 = nums1[i];
                    }
                    if (count == median) {
                        ele2 = nums1[i];
                        break;
                    }

                }
                else {
                    if (count == median) {
                        return nums1[i];
                    }
                }
                i++;
            }
            else {
                count++;
                if ((n + m) % 2 == 0) {
                    if (count == median - 1) {
                        ele1 = nums2[j];
                    }
                    if (count == median) {
                        ele2 = nums2[j];
                        break;
                    }

                }
                else {
                    if (count == median) {
                        return nums2[j];
                    }
                }

                j++;
            }
        }
        while (i < n) {
            count++;
            if ((n + m) % 2 == 0) {
                if (count == median - 1) {
                    ele1 = nums1[i];
                }
                if (count == median) {
                    ele2 = nums1[i];
                    break;
                }

            }
            else {
                if (count == median) {
                    return nums1[i];
                }
            }

            i++;
        }
        while (j < m) {
            count++;
            if ((n + m) % 2 == 0) {
                if (count == median - 1) {
                    ele1 = nums2[j];
                }
                if (count == median) {
                    ele2 = nums2[j];
                    break;
                }

            }
            else {
                if (count == median) {
                    return nums2[j];
                }
            }

            j++;
        }

        return (ele1+ele2)/2;

    }

    /*
    using binary search - the idea is to pick some elements from from both and divide into 2
    halves and determine if the division will yield correct sorted array or not  
    
    */

     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        // logic for swapping the arrays as we want to do binary search on shorter array
        if(n > m){
            return findMedianSortedArrays(nums2, nums1);
        }

        // minimum elements that can be taken is 0 and maximum is all elements in array1
        int low = 0, high = n;
        // determines how many elements will be in left half - basically median position
        int left = (n+m+1)/2;
        
        while(low <= high){
            int mid1 = low + (high - low)/2; // elements to be taken from array1
            int mid2 = left - mid1; // remaining elements are taken from array2
            
            // l1 and l2 are max elements from left half and r1,r2 are min elements from right half
            int l1 = INT_MIN, r1 = INT_MAX;
            int l2 = INT_MIN, r2 = INT_MAX;
            
            if(mid1 < n) r1 = nums1[mid1];
            if(mid2 < m) r2 = nums2[mid2];
            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            /*
            the split is only valid if greatest element from left of arr1 is smaller than least element of right of arr2
            AND
            the split is only valid if greatest element from left of arr2 is smaller than least element of right of arr1
            (imaging a X)
            
            */
            if(l1 <= r2 && l2 <= r1){
                // if the final array length is odd
                if((n+m) % 2 == 1) return max(l1, l2);
                else{
                    return (double)(max(l1, l2) + min(r1, r2))/2.0;
                }
            }
            // this means there should be lesss elements in left half from arr1
            else if(l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }
        

        return 0;

    }
};

