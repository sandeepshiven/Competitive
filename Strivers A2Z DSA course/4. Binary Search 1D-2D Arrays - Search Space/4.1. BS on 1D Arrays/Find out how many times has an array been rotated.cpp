#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*

Given an ascending sorted rotated array arr of distinct integers of size n. The array is right-rotated k times. Find the value of k.

Example 1:

Input:
n = 5
arr[] = {5, 1, 2, 3, 4}
Output: 1
Explanation: The given array is 5 1 2 3 4. 
The original sorted array is 1 2 3 4 5. 
We can see that the array was rotated 
1 times to the right.
Example 2:

Input:
n = 5
arr[] = {1, 2, 3, 4, 5}
Output: 0
Explanation: The given array is not rotated.
Your Task:
Complete the function findKRotation() which takes array arr and size n, as input parameters and returns an integer representing the answer. You don't have to print answers or take inputs.

https://www.geeksforgeeks.org/problems/rotation4723/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotation

*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
        
        int low = 0, high = n-1, idx = 0;

        // similar to find minimum if minimum index is found then it is the answer
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(arr[mid] >= arr[low]){
                if(arr[low] < arr[idx]){
                    idx = low;
                }
                low = mid + 1;
            }
            else{
                if(arr[mid] < arr[idx]){
                    idx = mid;
                }
                high = mid - 1;
            }
        }
        return idx;

	}

};