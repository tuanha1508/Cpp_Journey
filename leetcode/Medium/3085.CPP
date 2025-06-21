//3085. Minimum Deletions to Make String K-Special
/*
    Time Complexity: O(n + C^2)
    Space Complexity: O(n)
    
    Problem Overview: Make the difference between every pair of characters in the string at most k.

    Approach: Map, Count, Array, Brute Force
    - Try for each unique character in the string, calculate the number need to deletion if we choose frequency for this character is the minimum.
    - Find the minimum each trial.
    - Return the minimum result.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> cnt;

        int res = INT_MAX;
        
        for(auto i : word) cnt[i]++;

        for(auto i : cnt) {
            int curr = 0;
            for(auto j : cnt) {
                if(i.second > j.second) curr += j.second;
                else if(j.second > i.second + k) curr += j.second - (i.second + k);
            }
            res = min(res, curr);
        }

        return res;
    }
};