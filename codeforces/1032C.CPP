//1032C. Those Who Are With Us
/*
    
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n;
string s;
int main()  
{
    #ifndef ONLINE_JUDGE
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    #endif

    cin >> t;
    while(t--) {
        ll m;
        cin >> n >> m;
        vector<ll> A(n * m);
        ll X = 0;
        for(ll i = 0; i < n * m; i++){
            cin >> A[i];
            X = max(X, A[i]);
        }
        vector<ll> rowCount(n, 0), rowSingleCol(n, -1);
        vector<bool> colHasX(m, false);
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                if(A[i * m + j] == X){
                    rowCount[i]++;
                    colHasX[j] = true;
                    if(rowCount[i] == 1) 
                        rowSingleCol[i] = j;
                }
            }
        }
        ll multiRow = 0, singleRow = 0;
        for(ll i = 0; i < n; i++){
            if(rowCount[i] > 1)       multiRow++;
            else if(rowCount[i] == 1) singleRow++;
        }
        vector<ll> singleInCol(m, 0);
        for(ll i = 0; i < n; i++){
            if(rowCount[i] == 1)
                singleInCol[rowSingleCol[i]]++;
        }
        bool canCover = false;
        for(ll j = 0; j < m; j++){
            if(!colHasX[j]) continue;
            ll outside = multiRow + (singleRow - singleInCol[j]);
            if(outside <= 1){
                canCover = true;
                break;
            }
        }
        cout << (X - (canCover ? 1 : 0)) << "\n";
    }    
}
