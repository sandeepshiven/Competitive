/*
Problem statement
Given two sorted arrays, ‘a’ and ‘b’, of size ‘n’ and ‘m’, respectively, return the union of the arrays.



The union of two sorted arrays can be defined as an array consisting of the common and the distinct elements of the two arrays. The final array should be sorted in ascending order.



Note: 'a' and 'b' may contain duplicate elements, but the union array must contain unique elements.



Example:
Input: ‘n’ = 5 ‘m’ = 3
‘a’ = [1, 2, 3, 4, 6]
‘b’ = [2, 3, 5]

Output: [1, 2, 3, 4, 5, 6]

Explanation: Common elements in ‘a’ and ‘b’ are: [2, 3]
Distinct elements in ‘a’ are: [1, 4, 6]
Distinct elements in ‘b’ are: [5]
Union of ‘a’ and ‘b’ is: [1, 2, 3, 4, 5, 6]
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
5 3
1 2 3 4 6
2 3 5
Sample Output 1 :
1 2 3 4 5 6
Explanation Of Sample Input 1 :
Input: ‘n’ = 5 ‘m’ = 3
‘a’ = [1, 2, 3, 4, 6]
‘b’ = [2, 3, 5]

Output: [1, 2, 3, 4, 5, 6]

Explanation: Common elements in ‘a’ and ‘b’ are: [2, 3]
Distinct elements in ‘a’ are: [1, 4, 6]
Distinct elements in ‘b’ are: [5]
Union of ‘a’ and ‘b’ is: [1, 2, 3, 4, 5, 6]
Sample Input 2:
4 3
1 2 3 3
2 2 4
Sample Output 2:
1 2 3 4
Explanation Of Sample Input 2 :
Input: ‘n’ = 5 ‘m’ = 3
‘a’ = [1, 2, 3, 3]
‘b’ = [2, 2, 4]

Output: [1, 2, 3, 4]

Explanation: Common elements in ‘a’ and ‘b’ are: [2]
Distinct elements in ‘a’ are: [1, 3]
Distinct elements in ‘b’ are: [4]
Union of ‘a’ and ‘b’ is: [1, 2, 3, 4]
Expected Time Complexity:
O(( N + M )), where 'N' and ‘M’ are the sizes of Array ‘A’ and ‘B’.
Constraints :
1 <= 'n', 'm' <= 10^5
-10^9 <= 'a'[i], 'b'[i] <= 10^9

https://www.naukri.com/code360/problems/sorted-array_6613259?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

*/


#include <bits/stdc++.h>
using namespace std;


vector < int > sortedArray(vector < int > a, vector < int > b) {

    vector<int>res;

    int i = 0, j = 0;

    if (a[i] < b[j]) {
        res.push_back(a[i]);
        i++;
    }
    else {
        res.push_back(b[j]);
        j++;
    }

    while (i < a.size() && j < b.size()) {

        if ((res.back() != a[i] || res.back() != b[j])) {
            if (a[i] < b[j]) {
                res.push_back(a[i]);
                i++;
            }
            else if (a[i] > b[j]) {
                res.push_back(b[j]);
                j++;
            }
            else if (a[i] == b[j]) {
                res.push_back(b[j]);
                j++;
                i++;
            }
        }
        else {
            if (res.back() == a[i]) i++;
            else if (res.back() == b[j]) j++;
        }

    }

    while (i < a.size()) {
        if (res.back() != a[i]) res.push_back(a[i]);
        i++;
    }

    while (j < b.size()) {
        if (res.back() != b[j]) res.push_back(b[j]);
        j++;
    }

    return res;


}
