#include<bits/stdc++.h>
using namespace std;

int main() {



    return 0;
}


/*

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.


https://leetcode.com/problems/3sum/description/

*/


class Solution {
public:
    // slow solution n*n*log(n)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>resSet;
        unordered_map<int, int>mp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (mp.find(-(nums[i] + nums[j])) != mp.end()) {
                    vector<int> temp{ nums[i], nums[j], nums[mp[-(nums[i] + nums[j])]] };
                    sort(temp.begin(), temp.end());
                    resSet.insert(temp);

                }
            }
            mp[nums[i]] = i;
        }
        vector<vector<int>>res;
        for (auto i : resSet) {
            res.push_back(i);
        }


        return res;
    }

    vector<vector<int>> threeSum1(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ) {
            int n = nums.size();
            vector<vector<int>>res;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < n; ) {
                int currI = nums[i];
                int j = i + 1, k = n - 1;
                while (j < k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        res.push_back({ nums[i], nums[j], nums[k] });
                        while (j < n && j < k && nums[j] == res.back()[1]) {
                            j++;
                        }
                        while (k >= 0 && j < k && nums[k] == res.back()[2]) {
                            k--;
                        }
                    }
                    else if (nums[i] + nums[j] + nums[k] < 0) {
                        j++;
                    }
                    else {
                        k--;
                    }
                }
                while (i < n && nums[i] == currI) {
                    i++;
                }
            }
            return res;
        }
    }
};