//1033E. Lanes of Cars
/*
    
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll t;
int main()  
{
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif

    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        ll M = 0, maxa = 0;
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            M += a[i];
            maxa = max(maxa, a[i]);
        }

        ll C = k * M;
        auto count_le = [&](ll mid) {
            __int128 cnt = 0;
            for (ll i = 0; i < n; i++) {
                if (mid < a[i] - k) 
                    cnt += mid + k;
                else if (mid <= a[i])      
                    cnt += a[i];
                else                       
                    cnt += mid;
                if (cnt >= M) break;
            }
            return (ll)cnt;
        };

        ll lo = 1 - k, hi = maxa;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (count_le(mid) >= M) hi = mid;
            else lo = mid + 1;
        }
        ll T = lo, t0 = T - 1;

        __int128 S_cnt = 0, S_sum = 0;
        for (ll i = 0; i < n; i++) {
            if (t0 < a[i] - k) {
                ll p = t0 + k;
                if (p > 0) {
                    S_cnt += p;
                    S_sum += (__int128)p * (p + 1) / 2 - (__int128)k * p;
                }
            }
            else if (t0 <= a[i]) {
                ll p = a[i];
                S_cnt += p;
                S_sum += (__int128)p * (p + 1) / 2 - (__int128)k * p;
            }
            else {
                S_cnt += t0;
                S_sum += (__int128)t0 * (t0 + 1) / 2 - (__int128)k * a[i];
            }
        }

        ll rem = M - (ll)S_cnt;
        __int128 sumCost = S_sum + (__int128)rem * T;
        __int128 ans128  = sumCost + C;
        ll ans = (ll)ans128;
        cout << ans << "\n";
    }

    return 0;
}
