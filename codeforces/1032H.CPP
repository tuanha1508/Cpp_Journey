//1032H. Ice Baby
/*
    
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n;
string s;

struct Fenwick {
    int n, LOG;
    vector<int> f;
    Fenwick(int _n): n(_n), f(n+1, 0) {
        LOG = 1;
        while ((1 << LOG) <= n) LOG++;
    }
    void add(int i, int v) {
        for (; i <= n; i += i & -i) f[i] += v;
    }
    int sum(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) s += f[i];
        return s;
    }
    int kth(int k) {
        int idx = 0;
        for (int d = 1 << LOG; d > 0; d >>= 1) {
            if (idx + d <= n && f[idx + d] < k) {
                k -= f[idx + d];
                idx += d;
            }
        }
        return idx + 1;
    }
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
        cin >> n;
        vector<ll> l(n), r(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
        }
        vector<ll> vs = l;
        sort(vs.begin(), vs.end());
        vs.erase(unique(vs.begin(), vs.end()), vs.end());
        int m = vs.size();
        Fenwick bit(m);
        ll dp_size = 0;
        for (int i = 0; i < n; i++) {
            ll L = l[i], R = r[i];
            int cR = upper_bound(vs.begin(), vs.end(), R) - vs.begin();
            int U = bit.sum(cR);
            if (U < dp_size) {
                int idxDel = bit.kth(U + 1);
                bit.add(idxDel, -1);
            }
            int cL = lower_bound(vs.begin(), vs.end(), L) - vs.begin() + 1;
            bit.add(cL, 1);
            if (U == dp_size) dp_size++;
            cout << dp_size << " ";
        }
        cout << "\n";
    }
    return 0;
}
