//2434. Using a Robot to Print the Lexicographically Smallest String
/*
    Time Complexity: O(n * 26)
    Space Complexity: O(n)
    
    Problem Overview: 
    - Given two operations:
        1. Move the first character from string 's' to string 't'.
        2. Move the last character from string 't' to the result.
    - Find the lexicographically smallest result string.

    Approach: Stack, Greedy
    - First In Last Out (FILO) -> Stack Pattern
    - Use a stack representing the characters moved from 's' to 't'
    - With each step, check the top of the stack with the smallest character in the rest of 's'
    - Keep adding the top of the stack to the result string until the top of the stack is not smaller than the smallest character in the rest of 's'.
    - Return the result string.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {

        unordered_map<char, int> ch;
        stack<char> t;
        string res = "";

        for(auto i : s) ch[i]++;
        
        char mn = 'a';

        for(auto i : s) {
            t.push(i);
            ch[i]--;
            while(mn != 'z' && ch[mn] == 0) mn++;
            while(!t.empty() && t.top() <= mn) {
                res += t.top();
                t.pop();
            }
        }

        return res;
    }
};

