#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        
        int maxi = max(cost1, cost2);
        int mini = min(cost1, cost2);
        
        long long res = 1;
        
        for(int i=0; i<(total/mini); i++){
            res += (((total - (mini*i))/maxi)+1);
        }
        
        return res;
    }
};



int main(){

    return 0;
}