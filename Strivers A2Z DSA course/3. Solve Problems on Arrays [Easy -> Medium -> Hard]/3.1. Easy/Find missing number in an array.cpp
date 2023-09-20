#include<bits/stdc++.h>
using namespace std;


int missingNumber(vector<int>& nums) {
    // int sum = accumulate(nums.begin(), nums.end(), 0);
    // int n = nums.size();
    // int nSum = n*(n+1)/2;
    // return nSum - sum;

    int n = nums.size();
    int xor1 = 0;
    for (int i = 0; i < n; i++) {
        xor1 ^= (i ^ nums[i]);
    }
    xor1 ^= n;
    return xor1;
}

int missingNumber2(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int nSum = n*(n+1)/2;
        return nSum - sum;
    }



int main() {



    return 0;
}