/*


Ram is very fond of patterns. Once, his teacher gave him a pattern to solve. He gave Ram an integer n and asked him to build a pattern.

Help Ram build a  pattern.

 

Example 1:

Input: 5

Output:
*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *

https://practice.geeksforgeeks.org/problems/double-triangle-pattern-1662287416/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=pattern_20

*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here

        for(int i=1; i<=n-1; i++){
            for(int j=1; j<=n*2; j++){
                if(j <= i ){
                    cout << "*";
                }
                else if(j> (2*n) - i){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
            }
            cout << '\n';
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n*2; j++){
                if(j<=n-i+1){
                    cout << "*";
                }
                else if(j>=n+i){
                    cout << "*";
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