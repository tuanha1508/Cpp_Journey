//Problem_Number
/*
    Time Complexity: 
    Space Complexity: 
    
    Problem Overview:

    Approach:
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 200005;

signed main()  
{
    #ifndef ONLINE_JUDGE
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];

        if (n == 1) {
            cout << "YES\n";
            continue;
        }

        ll d = a[1] - a[0];
        bool ok = true;
        for (int i = 2; i < n; i++) {
            if (a[i] - a[i - 1] != d) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }

        ll c = a[0] - d;
        ll sum = n + 1;
        if (c < 0 || c % sum != 0) {
            cout << "NO\n";
            continue;
        }

        ll y = c / sum;
        ll x = y + d;
        cout << (x < 0 ? "NO\n" : "YES\n");
    }

    return 0;
}
