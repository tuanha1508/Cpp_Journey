//3445. Maximum Difference Between Even and Odd Frequency II
/*
    Time Complexity: O(n * Sigma^2)
    Space Complexity: O(1)
    
    Problem Overview: find the maximum difference between the odd frequency and even frequency in substrings have size of at least 'k'

    Approach :

    - Enumerate all pairs of characters `a` and `b` (digits 0-4) where `a` ≠ `b` to find optimal odd/even frequency combination
    - Use two-pointer technique with `left` and `right` pointers to explore all valid substrings of length ≥ `k`
    - Track counts `cnt_a`, `cnt_b` for current substring and `prev_a`, `prev_b` for prefix up to `left` pointer
    - Encode parity states as 2-bit numbers: `(count_a % 2) << 1 | (count_b % 2)` for efficient state management
    - Maintain `best[]` array storing minimum `prev_a - prev_b` values for each of the 4 possible parity states
    - Advance `left` pointer only when substring length ≥ `k` and `b` appears even times (≥ 2 occurrences)
    - Update `best[left_status]` with current `prev_a - prev_b` before moving `left` pointer forward
    - For each `right` position, calculate answer using target state `10` (odd `a`, even `b`) via XOR operation
    - Compute difference `(cnt_a - cnt_b) - best[right_status ^ 0b10]` to maximize odd-even frequency difference
    - Return maximum difference found across all character pairs and valid substring positions
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s, int k) {
        auto getStatus = [](int cnt_a, int cnt_b) -> int {
            return ((cnt_a & 1) << 1) | (cnt_b & 1);
        };

        int n = s.size();
        int ans = INT_MIN;
        for (char a = '0'; a <= '4'; ++a) {
            for (char b = '0'; b <= '4'; ++b) {
                if (a == b) {
                    continue;
                }
                int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
                int cnt_a = 0, cnt_b = 0;
                int prev_a = 0, prev_b = 0;
                int left = -1;
                for (int right = 0; right < n; ++right) {
                    cnt_a += (s[right] == a);
                    cnt_b += (s[right] == b);
                    while (right - left >= k && cnt_b - prev_b >= 2) {
                        int left_status = getStatus(prev_a, prev_b);
                        best[left_status] =
                            min(best[left_status], prev_a - prev_b);
                        ++left;
                        prev_a += (s[left] == a);
                        prev_b += (s[left] == b);
                    }
                    int right_status = getStatus(cnt_a, cnt_b);
                    if (best[right_status ^ 0b10] != INT_MAX) {
                        ans =
                            max(ans, cnt_a - cnt_b - best[right_status ^ 0b10]);
                    }
                }
            }
        }
        return ans;
    }
};