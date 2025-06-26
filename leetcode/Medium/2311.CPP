//2311. Longest Binary Subsequence Less Than or Equal to K
/*
    Time Complexity: O(n)
    Space Complexity: O(1)
    
    Problem Overview:

    Approach: Greedy
*/
/* For normal CPP
#include<bits/stdc++.h>
using namespace std;
int main()  
{
    #ifndef ONLINE_JUDGE
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    #endif
}
*/


/* For Leetcode
#include<bits/stdc++.h>
using namespace std;

*/
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sm = 0;
        int cnt = 0;
        int bits = 32 - __builtin_clz(k);
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[s.size() - 1 - i];
            if (ch == '1') {
                if (i < bits && sm + (1 << i) <= k) {
                    sm += 1 << i;
                    cnt++;
                }
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};