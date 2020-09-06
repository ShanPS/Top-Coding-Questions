/*
Problem: Given an input string, reverse the string word by word.

link: https://leetcode.com/problems/reverse-words-in-a-string/
*/

class Solution {
public:
    string reverseWords(string s) {
        string w = "";
        vector<string> words;

        for(auto c : s) {
            if(c == ' ') {
                if(w != "") words.push_back(w);
                w = "";
            }
            else {
                w += c;
            }
        }
        if(w != "") words.push_back(w);
        if(words.size() == 0) return "";
        
        reverse(words.begin(), words.end());
        string reversedString = words[0];
        for(int i=1; i<words.size(); i++) 
            reversedString += (' ' + words[i]);

        return reversedString;
    }
};