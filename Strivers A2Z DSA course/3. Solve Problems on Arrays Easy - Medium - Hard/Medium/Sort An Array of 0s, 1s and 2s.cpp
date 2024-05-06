#include<bits/stdc++.h>
using namespace std;

int main() {



    return 0;
}

/*

You have been given an array/list 'arr' consisting of 'n' elements.



Each element in the array is either 0, 1 or 2.



Sort this array/list in increasing order.



Do not make a new array/list. Make changes in the given array/list.



Example :
Input: 'arr' = [2, 2, 2, 2, 0, 0, 1, 0]

Output: Final 'arr' = [0, 0, 0, 1, 2, 2, 2, 2]

Explanation: The array is sorted in increasing order.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
8
2 2 2 2 0 0 1 0


Sample Output 1:
0 0 0 1 2 2 2 2


Explanation of sample input 1 :
The initial array 'arr' is [2, 2, 2, 2, 0, 0, 1, 0].

After sorting the array in increasing order, 'arr' is equal to:
[0, 0, 0, 1, 2, 2, 2, 2]


Sample Input 2:
5
1 1 1 1 1


Sample Output 2:
1 1 1 1 1

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]



https://leetcode.com/problems/sort-colors/description/


*/


class Solution {
public:

    // counting
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        int zero = 0, one = 0, two = 0;

        for (auto i : nums) {
            if (i == 0) {
                zero++;
            }
            else if (i == 1) {
                one++;
            }
            else {
                two++;
            }
        }
        int i = 0;
        while (i < n && zero--) {
            nums[i] = 0;
            i++;
        }
        while (i < n && one--) {
            nums[i] = 1;
            i++;
        }
        while (i < n && two--) {
            nums[i] = 2;
            i++;
        }

    }

    // dutch national flag

    void sortColors(vector<int>& nums) {

        int n = nums.size();

        int zero = 0, one = 0, two = n-1;

        while(one < two){
            if(nums[one] == 1){
                one++;
            }
            else if(nums[one] == 0){
                swap(nums[zero], nums[one]);
                one++, zero++;
            }
            else{
                swap(nums[two], nums[one]);
                two--;
            }
        }

    }

};