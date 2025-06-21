//1033F. Superb Graphs
/*
    
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TwoSAT {
    int N;
    vector<vector<int>> g, gr;
    vector<int> comp, order;
    vector<bool> used;
    TwoSAT(int vars)
      : N(vars), g(2*vars), gr(2*vars),
        comp(2*vars, -1), used(2*vars, false) {}
    // add implication a → b
    void imply(int a, int b) {
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    void either(int i, bool vali, int j, bool valj) {
        int A  = 2*i + (vali ? 1 : 0);
        int nA = 2*i + (vali ? 0 : 1);
        int B  = 2*j + (valj ? 1 : 0);
        int nB = 2*j + (valj ? 0 : 1);
        imply(nA, B);
        imply(nB, A);
    }
    void dfs1(int u) {
        used[u] = true;
        for (int v : g[u])
            if (!used[v]) dfs1(v);
        order.push_back(u);
    }
    void dfs2(int u, int cl) {
        comp[u] = cl;
        for (int v : gr[u])
            if (comp[v] == -1) dfs2(v, cl);
    }
    bool solve() {
        int M = 2 * N;
        for (int i = 0; i < M; i++)
            if (!used[i]) dfs1(i);
        int cid = 0;
        for (int i = M - 1; i >= 0; i--) {
            int u = order[i];
            if (comp[u] == -1) dfs2(u, cid++);
        }
        for (int i = 0; i < N; i++)
            if (comp[2*i] == comp[2*i+1]) return false;
        return true;
    }
};

ll t;
int main()  
{
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif

    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<bool> needs(n, false);
        vector<vector<int>> allGroups;
        vector<bool> isClique;

        for (int gi = 0; gi < k; gi++) {
            int m;
            cin >> m;
            vector<vector<char>> adj(n, vector<char>(n, 0));
            for (int i = 0; i < m; i++) {
                int u, v;
                cin >> u >> v;
                --u; --v;
                adj[u][v] = adj[v][u] = 1;
            }
            map<string, vector<int>> mp;
            for (int u = 0; u < n; u++) {
                string pat;
                pat.reserve(n);
                for (int w = 0; w < n; w++)
                    pat.push_back(adj[u][w] ? '1' : '0');
                mp[pat].push_back(u);
            }
            for (auto &kv : mp) {
                auto &W = kv.second;
                if (W.size() > 1) {
                    for (int v : W) needs[v] = true;
                    allGroups.push_back(W);
                    isClique.push_back(false);
                }
            }

            map<string, vector<int>> mp2;
            for (int u = 0; u < n; u++) {
                string pat;
                pat.reserve(n);
                for (int w = 0; w < n; w++) {
                    if (u == w) pat.push_back('0');
                    else        pat.push_back(adj[u][w] ? '0' : '1');
                }
                mp2[pat].push_back(u);
            }
            for (auto &kv : mp2) {
                auto &W = kv.second;
                if (W.size() > 1) {
                    for (int v : W) needs[v] = true;
                    allGroups.push_back(W);
                    isClique.push_back(true);
                }
            }
        }

        vector<int> idx(n, -1);
        int V = 0;
        for (int v = 0; v < n; v++)
            if (needs[v]) idx[v] = V++;

        TwoSAT solver(V);

        int Gcnt = allGroups.size();
        for (int gid = 0; gid < Gcnt; gid++) {
            auto &W = allGroups[gid];
            bool cl = isClique[gid];
            int sz = W.size();
            for (int i = 0; i < sz; i++) {
                for (int j = i + 1; j < sz; j++) {
                    int u = W[i], v = W[j];
                    int iu = idx[u], iv = idx[v];
                    if (cl)     solver.either(iu, false, iv, false);
                    else        solver.either(iu, true, iv, true);
                }
            }
        }

        cout << (solver.solve() ? "Yes\n" : "No\n");
    }

    return 0;
}
