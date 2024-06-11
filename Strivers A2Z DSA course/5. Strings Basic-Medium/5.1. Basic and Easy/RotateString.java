public class RotateString {
    
}



/* 
 * Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false

https://leetcode.com/problems/rotate-string/description/
*/


class Solution {
    public boolean rotateString(String s, String goal) {
        
        int n = s.length();
        int m = goal.length();

        // if length is not same then these are different strings
        if(n != m){
            return false;
        }

        int rotatedTillIdx = -1;
        int j = 0;
        int rotStartIdx = -1;

        // iterating the goal to find out the point of rotation
        while(j < m){
            int temp = 0;
            int tempJ = j;
            if(s.charAt(temp) == goal.charAt(j)){
                // storing the start of potential rotation point
                rotStartIdx = j;
                while(temp < n && j < m && s.charAt(temp) == goal.charAt(j)){
                    temp++;
                    j++;
                }
            }
            // not found the first common char so go ahead with next one
            if(rotStartIdx == -1){
                j++;
            }
            else if(j != m){
                // some characters were matching but it should till the end of goal string
                // if not then rested the values
                rotStartIdx = -1;
                j = tempJ + 1;
            }
            else{
                // storing the point at which rotation stopped
                rotatedTillIdx = temp;
                break;
            }
        }

        if(rotStartIdx == -1){
            return false;
        }
        // whole string is rotated s.length times
        if(rotStartIdx == 0) return true;

        j = 0;

        while(rotatedTillIdx < n && j < rotStartIdx && s.charAt(rotatedTillIdx) == goal.charAt(j)){
            rotatedTillIdx++;
            j++;
        }
        // should go through the end of s string;
        return rotatedTillIdx == n;
    }

    public boolean rotateString1(String s, String goal) {
        
        int n = s.length();
        int m = goal.length();

        // if length is not same then these are different strings
        if(n != m){
            return false;
        }
        // the rotating operation can be converted into sliding operation
        // so s+s will contain goal
        return (s+s).contains(goal);
    }
}

