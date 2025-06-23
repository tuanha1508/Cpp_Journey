//180B. Shrinking Array
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
        vector<long long>a(n);
        for(int i = 0; i < n; i++) 
            cin >> a[i];

        bool zero = false;
        for(int i = 0; i + 1 < n; i++){
            if (llabs(a[i] - a[i+1]) <= 1) {
                zero = true;
                break;
            }
        }
        if(zero){
            cout << 0 << "\n";
            continue;
        }

        bool one = false;
        for(int i = 0; i + 1 < n && !one; i++){
            long long L = min(a[i], a[i+1]);
            long long R = max(a[i], a[i+1]);
            if(i > 0){
                long long lo = a[i-1] - 1;
                long long hi = a[i-1] + 1;
                if(max(lo, L) <= min(hi, R)){
                    one = true;
                    break;
                }
            }

            if(i + 2 < n){
                long long lo = a[i+2] - 1;
                long long hi = a[i+2] + 1;
                if(max(lo, L) <= min(hi, R)){
                    one = true;
                    break;
                }
            }
        }

        if(one){
            cout << 1 << "\n";
            continue;
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(llabs(a[i] - a[j]) <= 1){
                    ans = min(ans, j - i - 1);
                }
            }
        }
        cout << (ans==INT_MAX ? -1 : ans) << "\n";
    }   
    return 0;
}
