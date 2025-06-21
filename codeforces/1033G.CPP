//1033G. Eulerian Line Graph
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
        ll n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> adj(n+1);
        vector<int> deg(n+1, 0);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        vector<int> odd;
        for (int i = 1; i <= n; i++) {
            if (deg[i] & 1) odd.push_back(i);
        }
        if (odd.empty()) {
            cout << "YES\n";
            continue;
        }
        int u = odd[0], v = odd[1];
        bool uv_edge = false;
        if (adj[u].size() < adj[v].size()) {
            for (int x : adj[u]) if (x == v) { uv_edge = true; break; }
        } else {
            for (int x : adj[v]) if (x == u) { uv_edge = true; break; }
        }
        bool is_pow2 = (k > 0 && (k & (k - 1)) == 0);
        if (is_pow2) {
            ll cnt = deg[u] + deg[v] - (uv_edge ? 2 : 0);
            cout << (cnt <= 2 ? "YES\n" : "NO\n");
        } else {
            if (deg[u] == 1 && deg[v] == 1) {
                int nu = adj[u][0], nv = adj[v][0];
                cout << (nu != nv ? "YES\n" : "NO\n");
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
