/*

Geek is very fond of patterns. Once, his teacher gave him a pattern to solve. He gave Geek an integer n and asked him to build a pattern.

Help Geek to build the pattern.

 

Example 1:

Input: 4

Output:
****
*  *
*  *
****

https://practice.geeksforgeeks.org/problems/square-pattern-1662287714/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=pattern_21

*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printSquare(int n) {
        

        for(int i=0; i<n; i++){
            cout << "*";
        }
        cout << "\n";
        for(int i=0; i<n-2; i++){
            for(int j=0; j<n; j++){
                if(j==0 || j==n-1){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
            }
            cout << "\n";
        }
        for(int i=0; i<n; i++){
            cout << "*";
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
// } Driver Code Ends
