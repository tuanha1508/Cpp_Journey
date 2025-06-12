//3423. Maximum Difference Between Adjacent Elements in a Circular Array
/*
    Time Complexity: O(n)
    Space Complexity: O(1)
    
    Problem Overview: Consider array as a circular array, find the maximum absolute difference between adjacent elements.
    
    Approach: Array
    - Initialize the result with the absolute difference between the first and last elements.
    - Iterate through the array, calculating the absolute difference between each pair of adjacent elements.
    - Update the result with the maximum absolute difference found.
    - Return the result.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int res = abs(nums[n - 1] - nums[0]);
        for(int i = 1 ; i <= n - 1 ; i++)
            res = max(res, abs(nums[i] - nums[i - 1]));
        return res;
    }
};