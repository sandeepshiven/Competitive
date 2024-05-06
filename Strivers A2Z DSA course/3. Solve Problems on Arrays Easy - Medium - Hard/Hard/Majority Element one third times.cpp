#include<bits/stdc++.h>
using namespace std;

int main() {



    return 0;
}

/*

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.



Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]

https://leetcode.com/problems/majority-element-ii/

*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {


        // trying to use moores voting algo
        int n = nums.size();
        int ele1 = nums[0], cnt1 = 0;
        int ele2 = INT_MIN, cnt2 = 0;
        // if array is bigger than 1
        if (n > 1) {
            ele2 = nums[1];
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == ele1) {
                cnt1++;
            }
            else if (nums[i] == ele2) {
                cnt2++;
            }
            else if (cnt1 == 0 || cnt2 == 0) {
                // if both are zero at same time then have to assign new values to ele
                // and both should be different else it will endup counting same element
                if (cnt1 == 0 && cnt2 == 0) {
                    ele1 = nums[i];
                    cnt1 = 1;
                    // have to move i forward as already count is 1 and we are assiging ele2
                    // a new value with next element
                    if (i + 1 < n) {
                        ele2 = nums[i + 1];
                        cnt2 = 1;
                        i++;
                    }
                    else {
                        ele2 = INT_MIN;
                    }
                }
                if (cnt1 == 0) {
                    ele1 = nums[i];
                    cnt1 = 1;
                }
                if (cnt2 == 0) {
                    ele2 = nums[i];
                    cnt2 = 1;
                }

            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        if (ele2 == INT_MIN) {
            return { ele1 };
        }
        else {
            // have to check validity
            cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] == ele1) {
                    cnt1++;
                }
                else if (nums[i] == ele2) {
                    cnt2++;
                }
            }
            if (cnt1 > n / 3 && cnt2 > n / 3) {
                return { ele1, ele2 };
            }
            else if (cnt1 > n / 3) {
                return { ele1 };
            }
            else if (cnt2 > n / 3) {
                return { ele2 };
            }
            else {
                return {};
            }

        }

    }

    vector<int> majorityElement2(vector<int>& nums) {


        // trying to use moores voting algo
        int n = nums.size();
        int ele1 = 0, cnt1 = 0;
        int ele2 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && ele2 != nums[i]) {
                ele1 = nums[i];
                cnt1++;
            }
            else if (cnt2 == 0 && ele1 != nums[i] ) {
                ele2 = nums[i];
                cnt2++;
            }
            else if (ele1 == nums[i]) {
                cnt1++;
            }
            else if (ele2 == nums[i]) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }


        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == ele1) {
                cnt1++;
            }
            else if (nums[i] == ele2) {
                cnt2++;
            }
        }
        if (cnt1 > n / 3 && cnt2 > n / 3) {
            return sort({ ele1, ele2 });
        }
        else if (cnt1 > n / 3) {
            return { ele1 };
        }
        else if (cnt2 > n / 3) {
            return { ele2 };
        }
        else {
            return {};
        }



    }
};

