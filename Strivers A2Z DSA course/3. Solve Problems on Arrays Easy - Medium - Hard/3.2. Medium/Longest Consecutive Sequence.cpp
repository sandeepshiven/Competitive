#include<bits/stdc++.h>
using namespace std;

int main() {



    return 0;
}

/*

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.



Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

https://leetcode.com/problems/longest-consecutive-sequence/description/

*/

class Solution {
public:

// using hashing
    int longestConsecutive(vector<int>& arr) {

        int n = arr.size();
        int maxi = 0;
        unordered_set<int>st;
        for (auto i : arr) {
            st.insert(i);
        }
        for (auto i : arr) {
            if (st.find(i - 1) == st.end()) {
                int ele = i;
                int cnt = 1;
                while (st.find(ele + 1) != st.end()) {
                    ele++;
                    cnt++;
                }
                maxi = max(maxi, cnt);
            }
        }
        return maxi;
    }

    // using sorting
    int longestSuccessiveElements(vector<int>&arr) {
    
    int n = arr.size();
    int longestSeq = 0, lastSmall = INT_MIN, cnt, maxi = 0;

    sort(arr.begin(), arr.end());
    for(auto i: arr){
        if(i-1 == lastSmall){
            cnt++;
            lastSmall = i;            
        }
        else if(i != lastSmall){
            cnt = 1;
            lastSmall = i;
        }
        maxi = max(maxi, cnt);
    }
    return maxi;


}
};