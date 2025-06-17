//1032G. Gangsta
/*
    
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n;
string s;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> s;
        vector<ll> bal(n + 1);
        bal[0] = 0;
        for (ll i = 1; i <= n; ++i) {
            bal[i] = bal[i - 1] + (s[i - 1] == '1' ? 1 : -1);
        }
        vector<ll> sb = bal;
        sort(sb.begin(), sb.end());
        ll acc = 0, dif = 0;
        for (ll i = 0; i <= n; ++i) {
            dif += sb[i] * i - acc;
            acc += sb[i];
        }
        ll tot = n * (n + 1) * (n + 2) / 6;
        ll res = (tot + dif) / 2;
        cout << res << '\n';
    }
    return 0;
}
