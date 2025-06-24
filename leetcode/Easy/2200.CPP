//2200. Find All K-Distant Indices in an Array
/*
    Time Complexity: O(n)
    Space Complexity: O(1)
    
    Problem Overview: find index that satisfy that |i - j| <= k where nums[j] == key, return all such indices.

    Approach: Array, Twopointer.
    - Iterate through the array, for each index i where nums[i] == key, calculate the range of indices that are k distant from i.
    - Use a variable to track the last added index to avoid duplicates.
    - Push all valid indices into the result vector.
    - Return the result vector.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(nums[i] == key) {
                int curr = ans.empty() ? max(0, i - k): max(ans.back() + 1, i - k), end = i + k;
                for(int j = curr; j <= min(end, n - 1); j++) ans.push_back(j);
            }
        }
        return ans;
    }
};