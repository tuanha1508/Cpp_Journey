//2138. Divide a String Into Groups of Size k
/*
    Time Complexity: O(n)
    Space Complexity: O(1)
    
    Problem Overview: Distribute string into groups of size k, if the last group is not full, fill it with a given character.

    Approach: String
    - Calculate to know if the last group is full or not.
    - Add the fill character into initial string until the size if a multiple of k
    - Use substr to get each group of size k.
    - Return the result.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        int rem = max((n + 1) % k, k);
        vector<string> res;
        if(rem != 0) {
            while(rem != 0) {
                s += fill;
                rem--;
            }
        }  

        for(int i = 0 ; i < n ; i += k) {
            string curr = s.substr(i, k);
            res.push_back(curr);
        }

        return res;
    }
};