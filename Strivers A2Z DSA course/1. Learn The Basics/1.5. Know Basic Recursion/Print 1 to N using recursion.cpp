/*
Print numbers from 1 to N without the help of loops.

Example 1:

Input:
N = 10
Output: 1 2 3 4 5 6 7 8 9 10


Example 2:

Input:
N = 5
Output: 1 2 3 4 5

https://practice.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-1-to-n-without-using-loops


*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void helper(int x, int n){
        if(x > n){
            return;
        }
        cout << x << " ";
        x++;
        helper(x, n);
    }
    void printNos(int n)
    {
        helper(1, n);
    }

    void printNosUsingBacktracking(int n){
        if(n == 0){
            return;
        }
        printNosUsingBacktracking(n-1);
        cout << n << " ";
    }
};

//{ Driver Code Starts.
/* Driver program to test printNos */
int main()
{
    int T;
    
    //taking testcases
    cin>>T;
    
    while(T--)
    {
        int N;
        
        //input N
        cin>>N;
        Solution ob;
        //calling printNos() function
        ob.printNosUsingBacktracking(N);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends