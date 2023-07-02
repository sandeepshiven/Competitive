/*

Given a number N. Count the number of digits in N which evenly divides N.

Note :- Evenly divides means whether N is divisible by a digit i.e. leaves a remainder 0 when divided.
 

Example 1:

Input:
N = 12
Output:
2
Explanation:
1, 2 both divide 12 evenly

Example 2:

Input:
N = 23
Output
0
Explanation:
2 and 3, none of them
divide 23 evenly

https://practice.geeksforgeeks.org/problems/count-digits5716/1

*/

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int n){
        int res = 0;
        int dup = n;
        while(dup){
            int rem = dup%10;
            dup /= 10;
            if(rem == 0){
                continue;
            }
            if(n%rem == 0){
                res++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
