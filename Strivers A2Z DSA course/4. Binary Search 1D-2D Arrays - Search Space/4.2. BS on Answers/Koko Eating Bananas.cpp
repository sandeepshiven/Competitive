#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23

https://leetcode.com/problems/koko-eating-bananas/description/

*/

class Solution {
public:

    // brute force
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int ans = piles.size();
        int maxVal = *max_element(piles.begin(), piles.end());

        for(int i=piles.size(); i <= maxVal; i++){
            int valSum = 0;
            for(auto j: piles){
                valSum = ceil((double)j/(double)i);
            }
            if(valSum == h){
                return i;
            }
        }

        return -1;
    }

    // using binary search

    int minEatingSpeed(vector<int>& piles, int h) {
        
    
        long long int low = 1,  high = *max_element(piles.begin(), piles.end()), ans;

        while(low <= high){
            long long mid = low + (high - low)/2;
            long long valSum = 0;
            for(auto i: piles){
                valSum += i/mid;
                if(i%mid != 0){
                    valSum++;
                }
            }
            
            if(valSum > h){
                
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;

        
    }
};