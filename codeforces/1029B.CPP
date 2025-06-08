//Problem_Number
/*
    Time Complexity: 
    Space Complexity: 
    
    Problem Overview:

    Approach:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 200005;
ll t, a[N], n, pos[N];
int main()  
{
    #ifndef ONLINE_JUDGE
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        cout << 1 << ' ';
        for(int i = n ; i >= 2 ; i--) cout << i << ' ';
        cout << '\n';
    } 
    
}
