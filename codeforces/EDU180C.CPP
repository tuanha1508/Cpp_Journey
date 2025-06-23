//180C. Coloring Game
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
        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        ll ans = 0;

        for(int k = 2; k < n; k++){
            for(int j = 1; j < k; j++){

                int M_out;
                if(k != n-1) {
                    M_out = a[n-1];
                } else if(j != n-2) {
                    M_out = a[n-2];
                } else {
                    M_out = a[n-3];
                }

                ll T = max((ll)M_out, 2LL * a[k]);
                ll X = T - a[j] - a[k];
                int idx = int(upper_bound(a.begin(), a.begin() + j, X) - a.begin());
                ans += (j - idx);
            }
        }

        cout << ans << "\n";
    }   
}
