/*

Given two numbers A and B. The task is to find out their LCM and GCD.

 

Example 1:

Input:
A = 5 , B = 10
Output:
10 5
Explanation:
LCM of 5 and 10 is 10, while
thier GCD is 5.

Example 1:

Input:
A = 14 , B = 8
Output:
56 2
Explanation:
LCM of 14 and 8 is 56, while
thier GCD is 2.

https://practice.geeksforgeeks.org/problems/lcm-and-gcd4516/1

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    // long long gcd(long long a, long long b){
    //     if(b == 0){
    //         return a;
    //     }
    //     return gcd(b, a%b);
    // }
    
    vector<long long> lcmAndGcd(long long a , long long b) {

        
        // recursive gcd
        // auto gcd = [](long long x, long long y, auto &&gcd) -> long long{
            
        //     if(y == 0){
        //         return x;
        //     }
        //     return gcd(y, x%y, gcd);
        // };

        auto gcd = [](long long x, long long y) -> long long{
            
            while(x>0 && y>0){
                if(x>y){
                    x = x%y; 
                }
                else{
                    y = y%x;
                }
              
            }
              return x==0? y: x;
            
        };
        long long hcf = gcd(a, b); 
        long long lcm = (a*b)/hcf;
        return vector<long long>{lcm, hcf};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends