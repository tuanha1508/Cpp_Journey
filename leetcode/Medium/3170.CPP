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
    - 
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