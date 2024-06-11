import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Map.Entry;
import java.util.stream.Stream;

public class SortCharactersByFrequency {

}

/*
 * Given a string s, sort it in decreasing order based on the frequency of the
 * characters. The frequency of a character is the number of times it appears in
 * the string.
 * 
 * Return the sorted string. If there are multiple answers, return any of them.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: s = "tree"
 * Output: "eert"
 * Explanation: 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
 * answer.
 * Example 2:
 * 
 * Input: s = "cccaaa"
 * Output: "aaaccc"
 * Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and
 * "aaaccc" are valid answers.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * Example 3:
 * 
 * Input: s = "Aabb"
 * Output: "bbAa"
 * Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 * 
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 */

class Solution {

    // using map and sorting O(n*log(n)) space O(2n)
    public String frequencySort(String s) {

        StringBuilder res = new StringBuilder("");

        HashMap<Character, Integer> mp = new HashMap();

        int n = s.length();

        for (int i = 0; i < n; i++) {
            mp.put(s.charAt(i), mp.getOrDefault(s.charAt(i), 0) + 1);
        }

        mp.entrySet().stream()
                .sorted(Collections.reverseOrder(Map.Entry.comparingByValue())).forEach(e -> {
                    for (int i = 0; i < e.getValue(); i++) {
                        res.append(e.getKey());
                    }
                });

        return res.toString();

    }


    // using bucket sort O(n) space O(2n)
    public String frequencySort1(String s) {

        StringBuilder res = new StringBuilder("");

        HashMap<Character, Integer> mp = new HashMap();

        int n = s.length();

        for (char c: s.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }

        // the number of highest frequency character will be atmost equal to the length of string
        List<Character> bucket[] = new List[n + 1];

        // putting all character who have same count in same bucket
        for(Map.Entry entry: mp.entrySet()){
            int count = (int)entry.getValue();
            if(bucket[count] == null){
                bucket[count] = new ArrayList<>();
            }
            bucket[count].add((char)entry.getKey());
        }

        // iterating from back to get highest frequency char and appending in res
        for(int i = n; i>= 0; i--){
            if(bucket[i] != null){
                for(Character c: bucket[i]){
                    for(int j=0; j<i; j++){
                        res.append(c);
                    }
                }
            }
        }

        return res.toString();

    }

    // using priority queue O(n) space O(n) for the map only
    public String frequencySort2(String s) {

        StringBuilder res = new StringBuilder("");

        HashMap<Character, Integer> mp = new HashMap();

        int n = s.length();

        for (char c: s.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }

        // creating priority queue in decsending order of the count
        // space for this will be constant as there are atmost 26 elements
        PriorityQueue<Map.Entry<Character, Integer>> pq = new PriorityQueue<>((a, b) -> b.getValue() - a.getValue());

        pq.addAll(mp.entrySet());

        while(!pq.isEmpty()){
            Map.Entry entry = pq.poll();
            for(int i=0; i<(int)entry.getValue(); i++){
                res.append((char)entry.getKey());
            }
        }

        return res.toString();

    }



}
