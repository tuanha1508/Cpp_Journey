//3403. Find the Lexicographically Largest String From the Box I
/*
    Time Complexity: O(n^2)
    Space Complexity: O(n)
    
    Problem Overview: find the lexicographically larget string from the original string by split k string.

    Approach: String
    1. If numFriends is 1, return the original string.
    2. Compare all possible substrings of the original string as long as it the rest part still can split (k - 1) substrings.
    3. Return the largest substring found.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        string res = "";
        for(int i = 0 ; i <= word.size() - 1 ; i++) {
            res = max(res, word.substr(i, min(word.size() - numFriends + 1, word.size() - i)));
        }
        return res;
    }
};