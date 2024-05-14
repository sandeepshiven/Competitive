#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*

You are given an array 'arr' sorted in non-decreasing order and a number 'x'.



You must return the index of lower bound of 'x'.



Note:
For a sorted array 'arr', 'lower_bound' of a number 'x' is defined as the smallest index 'idx' such that the value 'arr[idx]' is not less than 'x'

If all numbers are smaller than 'x', then 'n' should be the 'lower_bound' of 'x', where 'n' is the size of array.

Consider 0-based indexing.


Example:
Input: ‘arr’ = [1, 2, 2, 3] and 'x' = 0

Output: 0

Explanation: Index '0' is the smallest index such that 'arr[0]' is not less than 'x'.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
6
1 2 2 3 3 5
0


Sample Output 1:
0


Explanation Of Sample Input 1 :
Index '0' is the smallest index such that 'arr[0]' is not less than 'x'.


Sample Input 2:
6
1 2 2 3 3 5
2


Sample Output 2:
1


Sample Input 3:
6
1 2 2 3 3 5
7


Sample Output 3:
6

https://www.naukri.com/code360/problems/lower-bound_8165382?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

*/

int lowerBound(vector<int> arr, int n, int x) {
	
    int low = 0, high= n-1, index = -1;
    while(low <= high){
       int mid = low + (high-low)/2;
        if(arr[mid] >= x){
            index = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
            
        }
		// cout << arr[mid] << " " << index << '\n';
    }

	return index == -1? n: index;
}
