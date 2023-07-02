/*

Print GFG n times without the loop.

Example:

Input:
5
Output:
GFG GFG GFG GFG GFG


https://practice.geeksforgeeks.org/problems/print-gfg-n-times/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-gfg-n-times

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void printGfg(int n) {
        if(n == 0){
            return;
        }
        cout << "GFG ";
        printGfg(--n);
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
        ob.printGfg(N);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends