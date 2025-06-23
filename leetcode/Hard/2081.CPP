//2081. Sum of k-Mirror Numbers
/*
    Time Complexity: O(sqrt(10^10))
    Space Complexity: O(1)
    
    Problem Overview: Sum all the number from 1 to n, that the number should be a palindrome when converted to base k. 

    Approach: Math, Enumerator
    - Instead of check all the number from 1 to n, we can generate half of the palindrome and then mirror it to get the full palindrome.
    - Then check if the number is a palindrome in base k.
    - Return the sum of all the k-mirror numbers. 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dig[100];

public:
    long long kMirror(int k, int n) {
        auto isPalindrome = [&](long long x) -> bool {
            int siz = -1;
            while (x) {
                siz++;
                dig[siz] = x % k;
                x /= k;
            }
            for (int i = 0, j = siz; i < j; ++i, --j) {
                if (dig[i] != dig[j]) {
                    return false;
                }
            }
            return true;
        };

        int l = 1, res = 0;
        long long ans = 0;
        while (res < n) {
            int r = l * 10;

            for (int op = 0; op < 2; ++op) {
                for (int i = l; i < r && res < n; i++) {
                    long long combined = i;
                    int x = (op == 0 ? i / 10 : i);
                    while (x) {
                        combined = combined * 10 + x % 10;
                        x /= 10;
                    }
                    if (isPalindrome(combined)) {
                        res++;
                        ans += combined;
                    }
                }
            }
            l = r;
        }
        return ans;
    }
};