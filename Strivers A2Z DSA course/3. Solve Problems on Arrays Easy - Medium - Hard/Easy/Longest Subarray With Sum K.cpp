/*

Problem statement
You are given an array 'a' of size 'n' and an integer 'k'.



Find the length of the longest subarray of 'a' whose sum is equal to 'k'.



Example :
Input: ‘n’ = 7 ‘k’ = 3
‘a’ = [1, 2, 3, 1, 1, 1, 1]

Output: 3

Explanation: Subarrays whose sum = ‘3’ are:

[1, 2], [3], [1, 1, 1] and [1, 1, 1]

Here, the length of the longest subarray is 3, which is our final answer.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
7 3
1 2 3 1 1 1 1


Sample Output 1 :
3


Explanation Of Sample Input 1 :
Subarrays whose sum = ‘3’ are:
[1, 2], [3], [1, 1, 1] and [1, 1, 1]
Here, the length of the longest subarray is 3, which is our final answer.


Sample Input 2 :
4 2
1 2 1 3


Sample Output 2 :
1


Sample Input 3 :
5 2
2 2 4 1 2 


Sample Output 3 :
1

*/

#include<bits/stdc++.h>
using namespace std;

// using sliding window
int longestSubarrayWithSumK(vector<int> a, long long k) {
    
    int n = a.size();

    long long mx = 0, maxi = 0;;
    long long sum1 = 0;

    for(int i=0, j=0; i<n && j<n; ){
        if(sum1 + a[i] <= k){
            sum1 += a[i];
            mx++;
            i++;
            if(sum1 == k)
                maxi = max(mx, maxi);
        }
        else{
            mx--;
            sum1 -= a[j];
            j++;
        }
    }

    return maxi;

}

// using hashing
int longestSubarrayWithSumK1(vector<int> a, long long k) {
    
    int n = a.size();

    map<long long, long long> mp;
    long long sum1 = 0;
    long long maxi = 0;

    for(long long i=0; i<n; i++ ){
        sum1 += a[i];

        if(mp.find(sum1) == mp.end()){
            mp[sum1] = i;
        }

        if(sum1 == k){
            maxi = max(maxi, i+1);
        }

        if(mp.find(sum1-k) != mp.end()){
            maxi = max(maxi, i - mp[sum1-k]);
        }
    }

    return maxi;

}


int main(){
  
    

    return 0;
}