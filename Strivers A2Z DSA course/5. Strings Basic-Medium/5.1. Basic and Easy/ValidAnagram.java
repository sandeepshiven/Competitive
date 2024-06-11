import java.util.Map;

public class ValidAnagram {
    
}
/*
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 
https://leetcode.com/problems/valid-anagram/description/
 */

 class Solution {
    public boolean isAnagram(String s, String t) {
        
        Map<Character, Integer> mp1 = new HashMap<>();
        Map<Character, Integer> mp2 = new HashMap<>();

        int l1 = s.length();
        int l2 = t.length();

        if(l1 != l2){
            return false;
        }

        for(char c: s.toCharArray()){
            mp1.computeIfPresent(c, (k, v) -> v+1);
            mp1.putIfAbsent(c, 1);
        }
        for(char c: t.toCharArray()){
            mp2.computeIfPresent(c, (k, v) -> v+1);
            mp2.putIfAbsent(c, 1);
        }

        if(mp1.size() != mp2.size()){
            return false;
        }

        for(Map.Entry value: mp1.entrySet()){
            char c = (char)value.getKey();
            int cnt = (int)value.getValue();
            if(mp2.containsKey(c) == false){
                return false;
            }
            else{
                if(mp2.get(c) != cnt){
                    return false;
                }
            }
        }   

        return true;
    }

    // using only one map
    public boolean isAnagram2(String s, String t) {
        
        Map<Character, Integer> mp1 = new HashMap<>();
        

        int l1 = s.length();
        int l2 = t.length();

        if(l1 != l2){
            return false;
        }

        for(char c: s.toCharArray()){
            mp1.computeIfPresent(c, (k, v) -> v+1);
            mp1.putIfAbsent(c, 1);
        }
        for(char c: t.toCharArray()){
            mp1.computeIfPresent(c, (k, v) -> v-1);
        }

        for(Map.Entry value: mp1.entrySet()){
            char c = (char)value.getKey();
            int cnt = (int)value.getValue();
            if(cnt != 0){
                return false;
            }
        }   

        return true;
    }
}
