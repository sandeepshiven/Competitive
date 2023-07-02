/*

ou are given a string s. You need to reverse the string.

Example 1:

Input:
s = Geeks
Output: skeeG

Example 2:

Input:
s = for
Output: rof

https://practice.geeksforgeeks.org/problems/reverse-a-string/1


*/



//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends


//User function Template for C++

void helper(int start, int end, string &str){
    if(start > end){
        return;
    }
    swap(str[start], str[end]);
    helper(start+1, end-1, str);
}

string reverseWord(string str){
    
    helper(0, str.length()-1, str);
    return str;
    
}


