/*

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21

https://leetcode.com/problems/reverse-integer/description/

*/

#include <bits/stdc++.h>
using namespace std;
// my approach lengthy
class Solution
{
public:
    int reverse(int x) {
        int dup = x;
        int len = 0;
        while (dup) {
            dup /= 10;
            len++;
        }
        dup = x;
        if (len < 10) {
            int res = 0;
            while (dup) {
                int rem = dup % 10;
                res = res * 10 + rem;
                dup /= 10;
            }
            return res;
        }
        else {
            vector<int> arrX(10), maxArr(10), minArr(10);
            int mx = INT_MAX;
            int mi = INT_MIN;
            for (int i = 0; i < 10; i++) {
                arrX[i] = ::abs(dup % 10);
                maxArr[i] = mx % 10;
                minArr[i] = ::abs(mi % 10);
                dup /= 10;
                mx /= 10;
                mi /= 10;
            }
            dup = x;
            ::reverse(maxArr.begin(), maxArr.end());
            ::reverse(minArr.begin(), minArr.end());
            int res = 0;
            bool flag = true;
            for (int i = 0; i < 10; i++) {
                if (dup > 0) {
                    if (arrX[i] < maxArr[i]) {
                        flag = true;
                        break;
                    }
                    else if (arrX[i] > maxArr[i]) {
                        flag = false;
                        break;
                    }
                }
                else {
                    if (arrX[i] < minArr[i]) {
                        flag = true;
                        break;
                    }
                    else if (arrX[i] > minArr[i]) {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag) {
                for (int i = 0; i < 10; i++)
                {
                    res = res * 10 + arrX[i];
                }
            }
            else {
                return 0;
            }

            if (dup < 0) {
                res *= -1;
            }
            return res;
        }
    }
};

// better solution
class Solution2 {
public:
    int reverse(int x) {

        int temp = x;
        int res = 0;
        while (temp) {
            int rem = temp % 10;
            temp /= 10;
            // int max = 2147483647         
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && rem > 7)) {
                return 0;
            }
            // int min = -2147483648
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && rem < -8)) {
                return 0;
            }
            res = res * 10 + rem;
        }
        return res;
    }
};
