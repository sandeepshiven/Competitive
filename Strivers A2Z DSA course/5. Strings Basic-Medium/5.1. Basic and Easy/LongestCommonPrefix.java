import java.util.Arrays;

public class LongestCommonPrefix {
    
}

/*
 * 
 * Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

https://leetcode.com/problems/longest-common-prefix/description/
 */


 class Solution {

    // complexity = O(m*n)  m is length of the string
    public String longestCommonPrefix(String[] strs) {
        
        StringBuilder res = new StringBuilder("");

        int n = strs.length;
        int charIdx = 0;
        while(charIdx < strs[0].length()){
            int i = 0;
            char c = strs[0].charAt(charIdx);
            boolean flag = true;
            while (i < n) {
                if(strs[i].length() <= charIdx || strs[i].charAt(charIdx) != c){
                    flag = false;
                }
                i++;
            }
            if(flag){
                res.append(c);
            }
            else{
                break;
            }
            charIdx++;
            
        }

        return res.toString();
    }

    // complexity = O(m*n*log(n))  m is length of the string
    /*
     * n*log(n) will be the complexity of sorting algo but at each comparison we have to
     * compare each and every character of both the string
     */
    public String longestCommonPrefix2(String[] strs) {
        
        StringBuilder res = new StringBuilder("");

        int n = strs.length;

        /*
         * sorting because if array has common prefix then it will be lexicographically 
         * sorted and we would need to compare first and last only
         */

        Arrays.sort(strs);

        /* 
        common prefix length can be utmost the smallest string of the first and last
        an
        */
        int m = Math.min(strs[0].length(), strs[n - 1].length());
    
        int i = 0;
        while(i<m && (strs[0].charAt(i) == strs[n-1].charAt(i))){
            res.append(strs[0].charAt(i));
            i++;
        }

        return res.toString();
    }
}


