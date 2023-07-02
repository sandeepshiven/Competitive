/*

Geek is very fond of patterns. Once, his teacher gave him a square pattern to solve. He gave Geek an integer n and asked him to build a pattern.

Help Geek to build the pattern.

 

Example 1:

Input: 4

Output:
4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4

https://practice.geeksforgeeks.org/problems/square-pattern-1662666141/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=pattern_22

*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:

    void fillSquare(vector<vector<int>>&arr, int n, int x){

        for(int i = (n-x); i < n+x-1; i++){
            for(int j=(n-x); j < n+x-1; j++){
                if(i==(n-x) || i==(n+x-2) || j==(n-x) || j==(n+x-2)){
                    arr[i][j] = x;
                }
            }
        }

    }

    void printSquare(int n) {
        
        // matrix filling approach n^3

        // vector<vector<int>>arr(2*n - 1 , vector<int>(2*n - 1));
        // for(int i = n; i>=1; i--){
        //     fillSquare(arr, n, i);
        // }
        // for(auto x: arr){
        //     for(auto y: x){
        //         cout << y;
        //     }
        //     cout << '\n';
        // }

        // least distance appraoch n^2

        for(int i=0; i< 2*n-1; i++){
            for(int j=0; j< 2*n-1; j++){
                int dist = min({i, 2*n-i-2, j, 2*n-j-2});
                cout << n-dist;
            }
            cout << '\n';
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printSquare(n);
    }
    return 0;
}