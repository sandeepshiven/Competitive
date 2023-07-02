/*

Given a non-empty array of integers, find the top k elements which have the highest frequency in the array. If two numbers have the same frequency then the larger number should be given preference. 

Note: Print the elements according to the frequency count (from highest to lowest) and if the frequency is equal then larger number will be given preference.

Example 1:

Input:
N = 6
nums = {1,1,1,2,2,3}
k = 2
Output: {1, 2}

Example 2:

Input:
N = 8
nums = {1,1,2,2,3,3,3,4}
k = 2
Output: {3, 2}
Explanation: Elements 1 and 2 have the
same frequency ie. 2. Therefore, in this
case, the answer includes the element 2
as 2 > 1.


https://practice.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1


*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(int x: nums){
            mp[x]++;
        }
        vector<pair<int, int>>arr; 
        for(auto x: mp){
            arr.push_back(make_pair(x.second, x.first));
        }
        sort(arr.begin(), arr.end(), [](pair<int, int>p1, pair<int, int>p2) -> bool{
            if(p1.first == p2.first){
                return p1.second > p2.second;
            }
            else{
                return p1.first > p2.first; 
            }
        });
        
        vector<int>res;
        for(int i=0; i<k; i++){
            res.push_back(arr[i].second);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}


