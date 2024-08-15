import java.util.HashMap;
import java.util.TreeMap;

public class SumOfBeautyOfAllSubstrings {
    
}

/*
 * The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

 

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
Example 2:

Input: s = "aabcbaa"
Output: 17

https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/
 */


 class Solution {

    int getMin(int [] arr){
        int res = Integer.MAX_VALUE;
        for(int i =0; i<26; i++){
            if(arr[i] != 0)
                res = Math.min(res, arr[i]);
        }
        return res;
    }

    int getMax(int [] arr){
        int res = Integer.MIN_VALUE;
        for(int i =0; i<26; i++){
            res = Math.max(res, arr[i]);
        }
        return res;
    }

    public int beautySum(String s) {
        
        int res = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            int [] mp = new int[26];
            for(int j=i; j<n; j++){
                int idx = s.charAt(j) - 'a';
                mp[idx]++;
                
                res += (getMax(mp) - getMin(mp));
                
            }
        }


        return res;
    }
}
