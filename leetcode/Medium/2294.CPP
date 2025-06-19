//2294. Partition Array Such That Maximum Difference Is K
/*
    Time Complexity: O(n log n)
    Space Complexity: O(1)
    
    Problem Overview: count how many partitions can be made such that the maximum difference in each partition is at most k, each partition must contain at least one element.

    Approach: sorting, greedy
    - Efficient to find if the difference between the smallest and largest element in a partition exceeds k is sorting the array first.
    - Iterate through the sorted array, and whenever the difference between the current element and the previous partition's maximum exceeds k, increment the partition count and update the previous partition's maximum to the current element.
    - This ensures that each partition contains elements that are within the allowed difference k.
    - The final count of partitions is returned.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int res = 1;
        sort(nums.begin(), nums.end());
        int cmp = nums[0];
        for(auto i : nums) {
            if(i - cmp <= k) continue;
            else res++;
            cmp = i;
        }
        return res;
    }
};