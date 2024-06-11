class ReverseWordsInAString {

};
/*
 *
 *
 *
 * Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.



Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

https://leetcode.com/problems/reverse-words-in-a-string/description/
 */
#include<bits/stdc++.h>
using namespace std;

int main() {



    return 0;
}

class Solution {
public:
    string reverseWords(string s) {

        int n = s.length();
        string res = "";
        for (int i = 0; i < n; ) {
            int j = i;
            string word = "";
            while (j < n && s[j] != ' ') {
                word.push_back(s[j]);
                j++;
            }
            reverse(word.begin(), word.end());
            res.append(word);

            if (i == j) {
                i++;
            }
            else {
                i = j;
                if (i < n)
                    res.append(" ");
            }
        }
        if (res.back() == ' ') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());

        return res;
    }


    string reverseWords2(string s) {

        s += " "; // to ensure last word is processed
        string ans, t;
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' '){
                if(t != ""){
                    ans = t + " " + ans;
                }
                t = "";
            }
            else{
                t += s[i];
            }
        }
        ans.pop_back();
        return ans;

    }

    string reverseWords2(string s) {

        int left=0, right=0;
        int n = s.size();

        reverse(s.begin(), s.end());
        
        for(int i=0; i<n;){
            
            while(i<n && s[i]==' ') i++; //skip the spaces until we hit a word
            if(i == n) break;

            // shifting the letters
            while(i<n && s[i] != ' '){
                s[right] = s[i];
                right++, i++;
            }
            // reversing the word which makes it correct
            reverse(s.begin()+left, s.begin()+right);

            // adding the space after word
            s[right] = ' ';
            right++;
            // now the left will point to the begining of new word
            left = right;
            i++;

        }
        s.resize(right-1); // to eliminate the extra spaces
       
        return s;

    }

};