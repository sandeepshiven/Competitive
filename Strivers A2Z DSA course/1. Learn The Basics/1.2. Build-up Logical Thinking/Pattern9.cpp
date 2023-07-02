/*

Geek is very fond of patterns. Once, his teacher gave him a star pattern to solve. He gave Geek an integer n and asked him to build a pattern.

Help Geek to build a star pattern.

 

Example 1:
For Input: 
5
Expected Output: 
    *
   * *
  * * *
 * * * *
* * * * *
* * * * *
 * * * *
  * * *
   * *
    *

https://practice.geeksforgeeks.org/problems/pattern/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=pattern_9

*/


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printDiamond(int n) {
        
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<(n)-i; j++){
                cout << " ";
            }
            for(int j=0; j<i; j++){
                cout << "* ";
            }
            
            cout << '\n';
        }
        
        for(int i=n; i>0; i--){
	        for(int j=0; j<n-i; j++){
	            cout << " ";
	        }
	        for(int j=0; j<i; j++){
	            cout << "* ";
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
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends

