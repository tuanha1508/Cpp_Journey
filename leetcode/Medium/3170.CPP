//3170. Lexicographically Minimum String After Removing Stars
/*
    Time Complexity: O(n * 26)
    Space Complexity: O(n)
    
    Problem Overview:
    Given string s:
    - Remove all characters that are stars '*'.
    - For each character '*' removed, remove the smallest character on the left of the start. 
    - Return the lexicographically smallest string possible after all removals.

    Approach: Stack, String
    - We use a stack to keep track of the indices of characters in the string.
    - For each character in the string:
        - If it is not a star, we push its index onto the stack.
        - If it is a star, we pop the top of the stack (which gives us the index of the smallest character) and mark that position as a star.
    - Finally, we construct the result string by skipping all the stars.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearStars(string s) {
        string res = "";
        unordered_map<char, stack<int>> m;
        
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] != '*') {
                m[s[i]].push(i);
            }
            else {
                for(char j = 'a' ; j <= 'z' ; j++) {
                    if(!m[j].empty()) {
                        s[m[j].top()] = '*';
                        m[j].pop();
                        break;
                    }
                }
            }
        }

        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] != '*') res.push_back(s[i]);
        }

        return res;
    }
};