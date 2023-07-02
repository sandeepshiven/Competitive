/*

iven a string S, check if it is palindrome or not.

Example 1:

Input: S = "abba"
Output: 1
Explanation: S is a palindrome

Example 2:

Input: S = "abc" 
Output: 0
Explanation: S is not a palindrome

https://practice.geeksforgeeks.org/problems/palindrome-string0817/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=palindrome-string

*/



//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int helper(int start, int end, string s){
	    
	    if(start > end){
	        return 1;
	    }
	    if(s[start] != s[end]){
	        return 0;
	    }
	    return helper(start+1, end-1, s);
	    
	}
	
	int isPalindrome(string s)
	{
	    return helper(0, s.length()-1, s); // time limit exceeds
	   // int start = 0, end = s.length()-1;
	   // while(start < end){
	   //     if(s[start] != s[end]){
	   //         return 0;
	   //     }
	   //     start++;
	   //     end--;
	   // }
	   // return 1;
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends






