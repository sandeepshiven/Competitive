/*

Given and integer N.Calculate the sum of series 13 + 23 + 33 + 43 + … till N-th term.

Example 1:

Input:
N=5
Output:
225
Explanation:
13+23+33+43+53=225

Example 2:

Input:
N=7
Output:
784
Explanation:
13+23+33+43+53+63+73=784


*/


//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
     
    long long sumOfSeries(long long n) {
        if(n == 1){
            return 1;
        }
        return (n*n*n) + sumOfSeries(n-1);
    }

    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.sumOfSeries(N) << "\n";
    }
}
// } Driver Code Ends
