import java.util.HashMap;

public class IsomorphicStrings {
    
}

/*Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true

https://leetcode.com/problems/isomorphic-strings/description/

*/
import java.util.*;

class Solution {
    public boolean isIsomorphic(String s, String t) {
        
        Map<Character, Character> mp1 = new HashMap<>();
        Map<Character, Character> mp2 = new HashMap<>();
        

        for(int i =0; i<s.length(); i++){
            boolean flag = false;
            // if char a is mappedt to char b then both of them cannot be mapped to any other
            if(mp1.containsKey(s.charAt(i))){
                if(mp1.get(s.charAt(i)) != t.charAt(i)){
                    flag = true;
                }
            }
            if(mp2.containsKey(t.charAt(i))){
                if(mp2.get(t.charAt(i)) != s.charAt(i)){
                    flag = true;
                }
            }    
            
            mp1.putIfAbsent(s.charAt(i), t.charAt(i));
            mp2.putIfAbsent(t.charAt(i), s.charAt(i));
            if(flag){
                return false;
            }
        }    


        return true;    
    }

}
