//1033A. Squares of Rectangles
/*
    
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n;
int main()  
{
    #ifndef ONLINE_JUDGE
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    #endif

    cin >> t;
    while(t--) {
        ll l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        ll area = l1*b1 + l2*b2 + l3*b3;
        ll S = sqrt(area);
        if (S *S  != area) {
            cout << "NO\n";
            continue;
        }
        bool ok = false;
        ll L[3] = {l1, l2, l3};
        ll B[3] = {b1, b2, b3};
        int p[3] = {0, 1, 2};
        do {
            int i = p[0], j = p[1], k = p[2];
            ll x1 = L[i], y1 = B[i];
            ll x2 = L[j], y2 = B[j];
            ll x3 = L[k], y3 = B[k];
            if (x1 == S && x2 == S && x3 == S && y1 + y2 + y3 == S) ok = true;
            else if (y1 == S && y2 == S && y3 == S && x1 + x2 + x3 == S) ok = true;
            else if (x1 == S) {
                ll h = S - y1;
                if (h > 0 && y2 == h && y3 == h && x2 + x3 == S) ok = true;
            }
            else if (y1 == S) {
                ll w = S - x1;
                if (w > 0 && x2 == w && x3 == w && y2 + y3 == S) ok = true;
            }
            if (ok) break;
        } while (next_permutation(p, p+3));
        cout << (ok ? "YES\n" : "NO\n");
    }    

    return 0;
}
