/*


Geek is very fond of patterns. Once, his teacher gave him a pattern to solve. He gave Geek an integer n and asked him to build a pattern.

Help Geek to build a star pattern.

 

Example 1:

Input: 5

Output:
1 
0 1 
1 0 1
0 1 0 1 
1 0 1 0 1

https://practice.geeksforgeeks.org/problems/triangle-pattern-1661718455/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=pattern_11


*/


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        

        
        bool flag1 = true, flag2;

        for(int i=0; i<n; i++){
            flag2 = flag1;
            flag1 = !flag1;
            for(int j=0; j<=i; j++){
                cout << flag2 << " ";
                flag2 = !flag2;
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