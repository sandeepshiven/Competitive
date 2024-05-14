#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*

You have been given a sorted array/list of integers 'arr' of size 'n' and an integer 'x'.



Find the total number of occurrences of 'x' in the array/list.



Example:
Input: 'n' = 7, 'x' = 3
'arr' = [1, 1, 1, 2, 2, 3, 3]

Output: 2

Explanation: Total occurrences of '3' in the array 'arr' is 2.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
7 3
1 1 1 2 2 3 3


Sample Output 1:
2


Explanation For Sample Input 1:
In the given list, there are 2 occurrences of integer 3.


Sample Input 2:
 5 6
 1 2 4 4 5


Sample Output 2:
 0


Explanation For Sample Input 2:
In the given list, there are 0 occurrences of integer 6.

https://www.naukri.com/code360/problems/occurrence-of-x-in-a-sorted-array_630456?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

*/

int first_occur(vector<int>&arr, int n, int x){

    int low = 0, high = n-1, index = -1;
    while(low <= high){
        int mid = low + (high-low)/2;

        // first occurance will always be on left side
        if(arr[mid] >= x){
            // update if index
            if(arr[mid] == x){
                index = mid;
            }
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return index;

}

int last_occur(vector<int>&arr, int n, int x){

    int low = 0, high = n-1, index = -1;
    while(low <= high){
        int mid = low + (high-low)/2;

        // last occurance will always be on right side
        if(arr[mid] <= x){
            if(arr[mid] == x){
                index = mid;
            }
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return index;

}

int count(vector<int>& arr, int n, int x) {
	
    int firstOccur = first_occur(arr, n, x);
    if(firstOccur == -1){
        return 0;
    }
    else{
        return last_occur(arr, n, x) - firstOccur + 1;
    }

}


