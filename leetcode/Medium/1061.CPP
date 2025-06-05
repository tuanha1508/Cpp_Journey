//1061. Lexicographically Smallest Equivalent String
/*
    Time Complexity: O(n + m * 26)
    Space Complexity: O(n + 26)
    
    Problem Overview: 
    - Given two strings s1 and s2, and a string baseStr
    - Given that each character in s1 === each character in s2, mean that it can replact for each other
    - You need to find the lexicographically smallest equivalent string of baseStr

    Approach: DFS, Union-Find
    - Create initial graph with s1 and s2 that mean s1[i] can be replaced with s2[i] and vice versa
    - DFS all characters can replace with baseStr[i], find the smallest character
    - Append the smallest character to result string
    - Return the result string
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    char dfs(unordered_map<char, vector<char>> &v, char i, vector<int> &check) {
        check[i - 'a'] = 1;
        char strmin = i;
        for(auto j : v[i]) {
            if(check[j - 'a'] == 1) continue;
            strmin = min(strmin, dfs(v, j, check));
        }
        return strmin;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        unordered_map<char, vector<char>> v;
        string res = "";
        for(int i = 0 ; i < n ; i++) {
            v[s1[i]].push_back(s2[i]);
            v[s2[i]].push_back(s1[i]);
        }

        for(auto i : baseStr) {
            vector<int> check(26, 0);
            char curr = dfs(v, i, check);
            res += curr;
        }
        return res;
    }
};