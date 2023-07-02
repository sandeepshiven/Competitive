/*

Geek is very fond of patterns. Once, his teacher gave him a pattern to solve. He gave Geek an integer n and asked him to build a pattern.

Help Geek to build the pattern.

Example 1:

Input: 4
Output:
   A
  ABA
 ABCBA
ABCDCBA


https://practice.geeksforgeeks.org/problems/triangle-pattern-1662285911/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=pattern_17

*/



//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        

        

        for(int i=1; i<=n; i++){
            char c = 'A';
            for(int j=1; j<=n+i-1; j++){
                if(j >= n-i+1 && j<n){
                    cout << c;
                    c++;
                }
                else if(j>=n){
                    cout << c;
                    c--;
                }
                else{
                    cout << " ";
                }
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