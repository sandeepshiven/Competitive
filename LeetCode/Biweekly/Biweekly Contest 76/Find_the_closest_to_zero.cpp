#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        
        int res = INT_MIN;
        int dist = INT_MAX;
        
        for(auto x: nums){
            if(abs(x) <= dist){
                dist = abs(x);
                res = max(res, x);
            }
        }
        
        return res;
        
    }
};
