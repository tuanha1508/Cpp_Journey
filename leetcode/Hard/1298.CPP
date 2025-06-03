//1298. Maximum Candies You Can Get from Boxes
/*
    Time Complexity: O(n)
    Space Complexity: O(n)
    
    Problem Overview: 
    - Given n boxes, each box has a status (open or closed), a number of candies.
    - Some boxes require keys to open, and containedBoxes may contain other boxes.
    - You can open boxes that are open or you have keys for, and you can get candies from them.
    - Return the maximum number of candies you can get.

    Approach: BFS, Graph
    - Use a queue to perform BFS on the boxes.
    - Call ownBox to track which boxes you own.
    - Call ownKey to track which keys you have.
    - Call checkBox to track which boxes have been checked.
    - Iterate and check boxes, keys, and candies to create initial queue.
    - In queue, check the box :
        1. If the box has been checked, continue.
        2. Add candies to the result.
        3. Mark the box as checked.
        4. Add contained boxes to ownBox.
        5. Add keys to ownKey.
        6. Check all boxes and add them to the queue if they are not checked, you have keys, and you own them.
    - Return the total candies collected.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        int res = 0;
        queue<int> q;
        vector<int> ownBox(n, 0);
        vector<int> ownKey(n, 0);
        vector<int> checkBox(n, 0);

        for(int i = 0 ; i < n ; i++) ownKey[i] = (status[i]);
        for(auto i : initialBoxes) {
            ownBox[i] = 1;
            if(ownKey[i]) q.push(i);
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(checkBox[u] == 1) continue;

            res += candies[u];
            checkBox[u] = 1;

            for(auto v : containedBoxes[u])
                ownBox[v] = 1;

            for(auto v : keys[u])
                ownKey[v] = 1;

            for(int i = 0 ; i < ownBox.size() ; i++) {
                if(!checkBox[i] && ownKey[i] && ownBox[i]) q.push(i);
            }
        }
        return res;
    }
};