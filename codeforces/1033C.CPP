//1033C. Divine Tree
/*
    
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t;
int main()  
{
    #ifndef ONLINE_JUDGE
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    #endif

    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;

        if (m < n || m > n*(n+1)/2) {
            cout << -1 << "\n";
            continue;
        }

        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
 
        ll k = m - (n - 1);
        if (k < 1) k = 1;
        if (k > n) k = n;

        ll rem = m - (k + (n - 1));

        vector<ll> parent(n+1, 1);
        if (k != 1) parent[1] = k;
        else parent[1] = 0;
        parent[k] = 0;  

        for (ll i = n; i >= 2 && rem > 0; --i) {
            if (i == k) continue;
            ll gain = min(i, k) - 1;
            if (rem >= gain) {
                parent[i] = k;
                rem -= gain;
            }
        }

        cout << k << "\n";
        for (ll i = 1; i <= n; ++i) {
            if (i == k) continue;
            cout << parent[i] << " " << i << "\n";
        }
    }

    return 0;
}
