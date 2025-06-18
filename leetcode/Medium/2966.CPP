//2966. Divide Array Into Arrays With Max Difference 
/*
    Time Complexity: O(n log n)
    Space Complexity: O(n)
    
    Problem Overview: Divide array into n / 3 arrays such that maximum difference between any two elements in each array is at most k.

    Approach: Sort, Array
    - To minimize the maximum difference, sort the array and group elements in triplets.
    - If the difference between the first and last element of each triplet exceeds k, it is impossible in any ways to divide the array as required.
    - Return the triplets if all conditions are satisfied.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for(int i = 0 ; i <= n - 1 ; i += 3) {
            if(nums[i + 2] - nums[i] > k) return {};
            res.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return res;
    }
};