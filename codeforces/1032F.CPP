//1032F. Yamakasi
/*
    
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n;
string s;

struct Fenwick {
    int N;
    vector<ll> f;
    Fenwick(int n): N(n), f(n+1) {}
    void update(int i, ll v) { for (; i <= N; i += i & -i) f[i] += v; }
    ll query(int i) { ll s = 0; for (; i > 0; i -= i & -i) s += f[i]; return s; }
};

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
        ll S, X;
        cin >> n >> S >> X;
        vector<ll> a(n), P(n+1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            P[i+1] = P[i] + a[i];
        }

        ll ansLE = 0, ansLT = 0;
        for (int pass = 0; pass < 2; ++pass) {
            ll bound = (pass == 0 ? X : X - 1);
            ll total = 0;
            int i = 0;
            while (i < n) {
                if (a[i] > bound) { ++i; continue; }
                int j = i;
                while (j < n && a[j] <= bound) ++j;
                int len = j - i;
                vector<ll> segP(len+1);
                for (int k = 0; k <= len; ++k) segP[k] = P[i + k];
                auto V = segP;
                sort(V.begin(), V.end());
                V.erase(unique(V.begin(), V.end()), V.end());
                Fenwick fw(V.size());
                fw.update(int(lower_bound(V.begin(), V.end(), segP[0]) - V.begin()) + 1, 1);

                for (int k = 1; k <= len; ++k) {
                    ll cur = segP[k];
                    ll need = cur - S;
                    auto it = lower_bound(V.begin(), V.end(), need);
                    if (it != V.end() && *it == need)
                        total += fw.query(int(it - V.begin()) + 1) - fw.query(int(it - V.begin()));
                    fw.update(int(lower_bound(V.begin(), V.end(), cur) - V.begin()) + 1, 1);
                }

                i = j;
            }
            if (pass == 0) ansLE = total;
            else ansLT = total;
        }

        cout << (ansLE - ansLT) << "\n";
    }
    return 0;
}
