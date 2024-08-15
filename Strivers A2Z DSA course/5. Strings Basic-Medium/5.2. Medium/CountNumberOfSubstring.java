import java.util.HashMap;

public class CountNumberOfSubstring{

}

/*Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 

Example 1:

Input:
S = "aba", K = 2
Output:
3
Explanation:
The substrings are: "ab", "ba" and "aba".
Example 2:

Input: 
S = "abaaca", K = 1
Output:
7
Explanation:
The substrings are: "a", "b", "a", "aa", "a", "c", "a". 
Your Task:
You don't need to read input or print anything. Your task is to complete the function substrCount() which takes the string S and an integer K as inputs and returns the number of substrings having exactly K distinct characters.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ |S| ≤ 106
1 ≤ K ≤ 26 */


class Solution
{
    // O(n*n)
    long substrCount (String s, int k) {
        
        long res = 0;
        int n = s.length();
        
        for(int i=0; i<n; i++){
            HashMap<Character, Integer> mp = new HashMap<>();
            int j = i;
            while(j<n && mp.size() <= k){
                mp.put(s.charAt(j), mp.getOrDefault(s.charAt(j), 0)+1);
                if(mp.size() == k){
                    res++;
                }
                j++;
            }
        }
        return res;
    }
    
    //O(n) -- count the number of substrings having atmost k distinct characters and subtract from 
    // number of substring having at most k-1 characters which will leave us number of substrings
    // with k characters
    long substrCount1 (String s, int k) {
        
        return helper(s, k) - helper(s, k-1);
    }

    long helper(String s, int k){
        long res = 0;
        int n = s.length();
        int j=0;

        HashMap<Character, Integer> mp = new HashMap<>();
        
        for(int i=0; i<n; i++){
            mp.put(s.charAt(i), mp.getOrDefault(s.charAt(i), 0)+1);
            while(mp.size() > k){
                mp.put(s.charAt(j), mp.getOrDefault(s.charAt(j), 0)-1);
                if(mp.get(s.charAt(j)) <= 0){
                    mp.remove(s.charAt(j));
                }
                j++;               
            }
            res += (i-j+1);
        }
        return res;
    }
}