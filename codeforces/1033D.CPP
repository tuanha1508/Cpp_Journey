//1033D. Matrix Game
/*
    
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXA = 100000 + 5;
const ll MOD = 1000000007;
ll fact[MAXA], invfact[MAXA];

ll modexp(ll a, ll e) {
    ll r = 1;
    while(e) {
        if(e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

ll t;
int main()  
{
    #ifndef ONLINE_JUDGE
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    #endif

    fact[0] = 1;
    for(int i = 1; i < MAXA; i++) fact[i] = fact[i-1] * i % MOD;
    invfact[MAXA-1] = modexp(fact[MAXA-1], MOD-2);
    for(int i = MAXA-2; i >= 0; i--) invfact[i] = invfact[i+1] * (i+1) % MOD;

    cin >> t;
    while(t--) {
        ll a, b, k;
        cin >> a >> b >> k;
   
        ll n = (k % MOD * ((a - 1) % MOD) % MOD + 1) % MOD;

        ll comb = 1, Nmod = n;
        for(ll i = 0; i < a; i++) {
            comb = comb * ((Nmod - i + MOD) % MOD) % MOD;
        }
        comb = comb * invfact[a] % MOD;
    
        ll m = ( (k % MOD) * comb % MOD * ((b - 1) % MOD) ) % MOD;
        m = (m + 1) % MOD;
        cout << n << " " << m << "\n";
    }

    return 0;
}
