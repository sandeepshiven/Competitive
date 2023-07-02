/*

Print numbers from N to 1 (space separated) without the help of loops.

Example 1:

Input:
N = 10
Output: 10 9 8 7 6 5 4 3 2 1

https://practice.geeksforgeeks.org/problems/print-n-to-1-without-loop/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-n-to-1-without-loop

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void printNos(int n) {
        if(n==0){
            return;
        }
        cout << n << " ";
        printNos(--n);
    }
    void helper(int i, int n){
        if(i > n){
            return;
        }

        helper(i+1, n);
        cout << i << " ";
    }
    void printNosUsingBacktracking(int n){
        helper(1, n);
    }
};

//{ Driver Code Starts.
/* Driver program to test printNos */
int main() {
    int T;

    // taking testcases
    cin >> T;

    while (T--) {
        int N;

        // input N
        cin >> N;
        Solution ob;
        // calling printNos() function
        ob.printNosUsingBacktracking(N);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends