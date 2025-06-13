//2616. Minimize the Maximum Difference of Pairs
/*
    Time Complexity: O(nlogn)
    Space Complexity: O(1)
    
    Problem Overview: Minimize the maximum difference between p pairs of numbers in an array.

    Approach: Binary Search
    - Aware that two adjacent numbers after sorting result in the smaallest difference --> Sort the array.
    - Use the binary search with each mid value, compare and count how many pairs have a difference less than or equal to mid -> meaning that the maximum difference is mid.
    - If the number of pairs is greater than or equal to p, then we can try to minimize the maximum difference further by adjusting the right boundary.
    - If the number of pairs is less than p, we need to increase the minimum difference by adjusting the left boundary.
    - The process continues until the left boundary meets the right boundary, which will be the minimum maximum difference possible.
    - Return the left boundary as the result.
*/  

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = nums[n - 1] - nums[0];

        while (left < right) {
            int mid = left + (right - left) / 2, pairs = 0;
            for (int i = 1; i < n; ++i) {
                if (mid >= nums[i] - nums[i - 1]) {
                    ++pairs, ++i;
                }
            }
            if (pairs >= p) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};