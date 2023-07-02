/*

Palindrome Number
Easy

Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        
        int a = x, b=0;
        if(x<0){
            return false;
        }
        while(a){
            long long rem = a%10;
            a /= 10;
            // for checking overflow
            if(b > INT_MAX/10 || (b == INT_MAX/10 && rem > 7)){
                return false;
            }
            b = (b*10) + rem;
        }

        return x == b;

    }
};

class Solution2 {
public:
    bool isPalindrome(int x) {
        
        int a = x, reversed=0;

        // when x < 0, x is not a palindrome.
        // Also if the last digit of the number is 0, in order to be a palindrome,
        // the first digit of the number also needs to be 0.
        // Only 0 satisfy this property.
        if(x<0 || (x%10 == 0 && x != 0)){
            return false;
        }
        while(a > reversed){
            long long rem = a%10;
            a /= 10;            
            reversed = (reversed*10) + rem;
        }
        // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
        // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
        // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
        return a == reversed || a == reversed/10;

    }
};