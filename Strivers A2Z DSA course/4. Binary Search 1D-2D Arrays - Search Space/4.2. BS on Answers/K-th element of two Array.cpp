#include<bits/stdc++.h>
using namespace std;

int main() {



    return 0;
}

/*

Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the kth position of the final sorted array.


Example 1:

Input:
arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
Output:
6
Explanation:
The final sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6.
Example 2:
Input:
arr1[] = {100, 112, 256, 349, 770}
arr2[] = {72, 86, 113, 119, 265, 445, 892}
k = 7
Output:
256
Explanation:
Final sorted array is - 72, 86, 100, 112,
113, 119, 256, 265, 349, 445, 770, 892
7th element of this array is 256.

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthElement() which takes the arrays arr1[], arr2[], its size N and M respectively and an integer K as inputs and returns the element at the Kth position.


Expected Time Complexity: O(Log(N) + Log(M))
Expected Auxiliary Space: O(Log (N))



https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-element-of-two-sorted-array

*/


// my complex solution - similar to median of two sorted array 
// but I am splitting in two equal halves and then linearly checking for the 
// kth element
class Solution {
public:

    int findKth(int arr1[], int arr2[], int s1, int s2, int e1, int e2, int k) {
        int cnt = 0;

        while (s1 < e1 && s2 < e2) {
            if (arr1[s1] <= arr2[s2]) {
                cnt++;
                if (cnt == k) {
                    return arr1[s1];
                }
                s1++;
            }
            else {
                cnt++;
                if (cnt == k) {
                    return arr2[s2];
                }
                s2++;
            }
        }
        while (s1 < e1) {
            cnt++;
            if (cnt == k) {
                return arr1[s1];
            }
            s1++;
        }
        while (s2 < e2) {
            cnt++;
            if (cnt == k) {
                return arr2[s2];
            }
            s2++;
        }
        return 0;
    }


    int kthElement(int arr1[], int arr2[], int n, int m, int k) {

        if (n > m) {
            return kthElement(arr2, arr1, m, n, k);
        }

        int left = k;
        int low = 0, high = n;

        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = left - mid1;

            int l1 = INT_MIN, r1 = INT_MAX;
            int l2 = INT_MIN, r2 = INT_MAX;

            if (mid1 < n) r1 = arr1[mid1];
            if (mid2 < m) r2 = arr2[mid2];
            if (mid1 - 1 >= 0) l1 = arr1[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = arr2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1) {
                // find kth;
                if (k <= left) {
                    return findKth(arr1, arr2, 0, 0, mid1, mid2, k);
                }
                else {
                    return findKth(arr1, arr2, mid1, mid2, n, m, k - left);
                }
                // return max(l1, l2);
            }
            else if (l1 > r2) {
                high = mid1 - 1;
            }
            else {
                low = mid1 + 1;
            }
        }

        return 0;

    }
};

// efficient solution - concept is same as median of two sorted arrays
// but the partions is k and (n+m) - k
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k) {

        if (n > m) {
            return kthElement(arr2, arr1, m, n, k);
        }

        int left = k;
        /*
           low = max(0, k-m) 
           this is because if k is greater than 'm' we can't pick up all the elements from arr2 
           if we take low=0  it would mean no elements from arr1 and all elements from arr2
           which is not possible because k>m 
           so we would need pick up atleast k-m from arr1
           eg n = 4, m=5, k = 7
           so if we take all 5 from arr2 then rest 2 have to be taken from arr1
           low = min(0, 7-5) = 2; so this is the minimum elements we need to pick from arr1



           high = min(n, k);
           this is because if k is greater than n then we can atmost pick up n elements
           from arr1 and if k is less than n then we can pick up only k elements from
           arr1.
        */
        int low = max(0, k-m), high = min(n, k);

        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = left - mid1;

            int l1 = INT_MIN, r1 = INT_MAX;
            int l2 = INT_MIN, r2 = INT_MAX;

            if (mid1 < n) r1 = arr1[mid1];
            if (mid2 < m) r2 = arr2[mid2];
            if (mid1 - 1 >= 0) l1 = arr1[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = arr2[mid2 - 1];
            // cout << "mid1 - " << mid1 << '\n';
            // cout << "mid2 - " << mid2 << '\n';
            // cout << "l1 - " << l1 << '\n';
            // cout << "l2 - " << l2 << '\n';
            // cout << "r1 - " << r1 << '\n';
            // cout << "r2 - " << r2 << '\n';
            
            // cout << "\n\n";

            if (l1 <= r2 && l2 <= r1) {
                //find kth;
                // if (k <= left) {
                //     return findKth(arr1, arr2, 0, 0, mid1, mid2, k);
                // }
                // else {
                //     return findKth(arr1, arr2, mid1, mid2, n, m, k - left);
                // }
                
                return max(l1, l2);
            }
            else if (l1 > r2) {
                high = mid1 - 1;
            }
            else {
                low = mid1 + 1;
            }
        }

        return 0;

    }
};