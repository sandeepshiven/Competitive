/*

Given a number N, find the first N Fibonacci numbers. The first two number of the series are 1 and 1.

Example 1:

Input:
N = 5
Output: 1 1 2 3 5

Example 2:

Input:
N = 7
Output: 1 1 2 3 5 8 13

https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers1002/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-first-n-fibonacci-numbers

*/



//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    
    void helper(vector<long long> &arr, int n){
        if(arr.size() == n){
            return;
        }
        arr.push_back(arr.back() + *(arr.end()-2));
        helper(arr, n);
    }
    
    
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        vector<long long>arr;
        arr.push_back(1);
        if(n == 1){
            return arr;
        }
        arr.push_back(1);
        if(n == 2){
            return arr;
        }
        
        helper(arr, n);
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends