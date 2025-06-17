//3405. Count the Number of Arrays with K Matching Adjacent Elements
/*
    Time Complexity: O(k * log MOD
    Space Complexity: O(1)
    
    Problem Overview: Given n, m, and k :
    - find number of arrays of length n with elements from 1 to m that :
      + have exactly k pairs of adjacent elements that are equal.
    Approach: Approach: Math, Combinatorics, Inverse Modulo
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

class Solution {
public:
    ll Inverse(ll a, ll mod){
        ll res = 1;
        ll power = mod - 2;

        while (power){
            if (power & 1)
                res = res * a % mod;
            a = a * a % mod;
            power >>= 1;
        }

        return res;
    }

    int nCr(int n, int r){
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;

        ll res = 1;

        for (int i = 1; i <= r; i++){
            res = res * (n - r + i) % MOD;
            res = res * Inverse(i, MOD) % MOD;
        }

        return (int) res;
    }


    ll Expo(ll a, ll b)
    {
        ll result = 1;
        while (b) {
            if (b & 1)
                result = (result * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return result;
    }

    int countGoodArrays(int n, int m, int k) {
        int base = (m * 1ll * Expo(m - 1, n - (k + 1))) % MOD;

        int res = (base * 1ll * nCr(n-1, k)) % MOD; 

        return res;
    }
};