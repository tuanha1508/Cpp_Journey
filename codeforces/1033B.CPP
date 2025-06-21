//1033B. Square Pool
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
        ll n, s;
        cin >> n >> s;
        ll ans = 0;
        for(ll i = 0; i < n; ++i) {
            ll dx, dy, x, y;
            cin >> dx >> dy >> x >> y;
            if ((dx == dy && x == y) || (dx != dy && x + y == s))
                ++ans;
        }
        cout << ans << "\n";
    }    

    return 0;
}
