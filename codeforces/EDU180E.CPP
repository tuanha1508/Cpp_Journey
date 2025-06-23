//180E. Tree Colorings
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
    vector<int> ms;
    ms.reserve(t);
    while(t--) {
        int m;
        cin >> m;
        ms.push_back(m);
    }

    int maxm = 1;
    for(int x : ms) if(x > maxm) maxm = x;

    const int INF = 1e9;

    vector<int> dp(maxm+1, INF), A(maxm+1, INF);
    dp[1] = 0;

    for(int f = 3; f <= maxm; f += 2) {
        A[f] = 1 + dp[f-2];
        dp[f] = A[f];
        int sq = sqrt(f);
        for(int d = 3; d <= sq; d += 2) {
            if(f % d == 0) {
                int od = f / d;
                if(od >= 3) {
                    dp[f] = min(dp[f], A[d] + dp[od]);
                }
            }
        }
    }

    for(int m : ms) {
        if(m == 1) {
            cout << 1 << "\n";
        }
        else if((m & 1) == 0 || dp[m] >= INF/2) {
            cout << -1 << "\n";
        }
        else {
            cout << (1 + dp[m]) << "\n";
        }
    }

    return 0;
}
