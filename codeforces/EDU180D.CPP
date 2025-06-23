//180D. Reachability and Tree
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
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1);
        vector<pair<int,int>> edges;
        edges.reserve(n-1);

        for(int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges.emplace_back(u, v);
        }

        int centre = -1;
        for(int i = 1; i <= n; i++){
            if((int)adj[i].size() == 2){
                centre = i;
                break;
            }
        }

        if(centre < 0){
            cout << "NO\n";
            continue;
        }

        int v1 = adj[centre][0];
        int v2 = adj[centre][1];

        vector<int> vis(n+1, 0), color(n+1, 0);
        queue<int> q;

        vis[centre] = 1;
        vis[v1] = vis[v2] = 1;
        color[v1] = 0;
        color[v2] = 1;
        q.push(v1);
        q.push(v2);

        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int w: adj[u]){
                if(vis[w]) continue;
                vis[w] = 1;
                color[w] = color[u] ^ 1;
                q.push(w);
            }
        }

        vector<pair<int,int>> ans;
        ans.reserve(n-1);
        ans.emplace_back(v1, centre);
        ans.emplace_back(centre, v2);

        for(auto &e: edges){
            int x = e.first, y = e.second;
            if(x == centre || y == centre) continue;
            if(color[x] == 0 && color[y] == 1)
                ans.emplace_back(x, y);
            else
                ans.emplace_back(y, x);
        }

        cout << "YES\n";
        for(auto &p: ans)
            cout << p.first << " " << p.second << "\n";
    }   
    return 0;
}
