#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*

You're given a sorted array 'a' of 'n' integers and an integer 'x'.



Find the floor and ceiling of 'x' in 'a[0..n-1]'.



Note:
Floor of 'x' is the largest element in the array which is smaller than or equal to 'x'.
Ceiling of 'x' is the smallest element in the array greater than or equal to 'x'.


Example:
Input: 
n=6, x=5, a=[3, 4, 7, 8, 8, 10]   

Output:
4

Explanation:
The floor and ceiling of 'x' = 5 are 4 and 7, respectively.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
6 8
3 4 4 7 8 10


Sample Output 1 :
8 8


Explanation of sample input 1 :
Since x = 8 is present in the array, it will be both floor and ceiling.


Sample Input 2 :
6 2
3 4 4 7 8 10


Sample Output 2 :
-1 3


Explanation of sample input 2 :
Since no number is less than or equal to x = 2 in the array, its floor does not exist. The ceiling will be 3.

https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

*/

pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
	// Write your code here.
    int low = 0, high = n-1, ceil = -1, floor = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == x){
            return make_pair(arr[mid], arr[mid]);
        }
        // if the element is smaller than target then it is a potential floor
        else if(arr[mid] < x){
            floor = arr[mid];
            low = mid + 1;
        }
        // above logic 
        else{
            ceil = arr[mid];
            high = mid - 1;
        }
    }
    // binary search will take care to find the immediate smaller and greater
    
    return make_pair(floor, ceil);
}