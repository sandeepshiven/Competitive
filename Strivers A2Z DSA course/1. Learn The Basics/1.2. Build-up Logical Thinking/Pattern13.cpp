/*

Geek is very fond of patterns. Once, his teacher gave him a pattern to solve. He gave Geek an integer n and asked him to build a pattern.

Help Geek to build the pattern.

 

Example 1:

Input: 5

Output:
1 
2 3 
4 5 6 
7 8 9 10 
11 12 13 14 15


https://practice.geeksforgeeks.org/problems/triangle-pattern-1661718712/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=pattern_13
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        
        int x = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                cout << x << " ";
                x++;
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
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends