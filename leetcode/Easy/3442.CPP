//3442. Maximum Difference Between Even and Odd Frequency I
/*
    Time Complexity: O(s.size())
    Space Complexity: O(26)
    
    Problem Overview: Find the max odd frequency and min even frequency of characters in the string.

    Approach: Array, String
    - Count the frequency of each character in the string.
    - Track the maximum odd frequency and minimum even frequency.
    - Return the difference between the maximum odd frequency and minimum even frequency.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> m;
        int odd = 1;
        int even = 102;
        for(int i = 0 ; i < s.size() ; i++) {
            m[s[i]]++;
        }
        for(char i = 'a' ; i <= 'z' ; i++) {
            if(m[i] & 1) odd = max(odd, m[i]);
            else if(m[i] != 0) even = min(even, m[i]);
        }
        return odd - even;
    }
};