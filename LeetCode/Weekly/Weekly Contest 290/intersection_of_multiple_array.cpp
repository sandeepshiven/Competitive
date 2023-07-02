#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        
        int n = nums.size();
        map<int, int>mp;
        for(auto x: nums){
            for(auto y: x){
                mp[y]++;
            }
        }
        vector<int>res;
        for(auto x: mp){
            if(x.second == n){
                res.push_back(x.first);
            }
        }
        
        
        
        return res;
        
    }
};

int main(){

    return 0;
}