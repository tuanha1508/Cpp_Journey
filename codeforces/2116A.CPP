//2116A. Gellyfish and Tricolor Pansy
/*
    Time Complexity: O(1)
    Space Complexity: O(1)
    
    Problem Overview: 
    - Give 4 variables a, b, c, d
    - For k = 1, 2, 3, 4 :
        + k odd : if c > 0 -> b -= 1, d -= 1 
        + k even : if d > 0 -> a -= 1, c -= 1
    - Find which variable go to 0 first
    - If b or d go to 0 first, print "Gellyfish"
    - Otherwise, print "Flower"

    Approach: 
    - Find min variable in a, b, c, d
    - a && c go first -> check if mn == b or mn == d -> Gellyfish win
    - Otherwise, Flower win
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll t;
signed main() {
    #ifndef ONLINE_JUDGE
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    cin >> t;
    while(t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll mn = min({a, b, c, d});
        if(mn == b || mn == d) cout << "Gellyfish \n";
        else cout << "Flower \n";
    }
}
