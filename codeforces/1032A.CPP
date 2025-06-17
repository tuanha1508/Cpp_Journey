//1032A. Letter Home
/*
    
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, s, a[105];
int main()  
{
    #ifndef ONLINE_JUDGE
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    #endif

    cin >> t;
    while(t--) {
        cin >> n >> s;

        for(int i = 1 ; i <= n ; i++) cin >> a[i];

        ll mx = 0, mn = 105;

    	for(int i = 1 ; i <= n ; i++) {
    		if(a[i] <= s) mn = min(mn, a[i]);
    		if(a[i] > s) mx = max(mx, a[i]);
    	}

    	if(mx == 0) {
    		cout << s - mn << '\n';
    		continue;
    	}

    	if(mn == 105) {
    		cout << mx - s << '\n';
    		continue;
    	}

    	cout << 2 * min(s - mn, mx - s) + max(s - mn, mx - s) << '\n';

    }    
}
