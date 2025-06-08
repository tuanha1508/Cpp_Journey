//1029A. False Alarm
/*
    Time Complexity: O(n)
    Space Complexity: O(1)
    
    Problem Overview: 
    - Given n integers with 0 or 1 :
        0 means : User can pass this position
        1 means : User cannot pass this position
    - Given x : the maximum number of positions the user can pass
    - Return if user can go to last position with 1 times use operation pass <= X position 1 at the same time.

    Approach: Math, Array
    - We consider adjacent positions of 1s so that we only care the last and first position of 1s.
    - If the distance between the first and last position of 1s is less than or equal to x, then we can say that the user can pass.
    - Otherwise, the user cannot pass.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t, a[15], n, x;
int main()  
{
    #ifndef ONLINE_JUDGE
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    #endif

    cin >> t;
    while(t--) {
        cin >> n >> x;
        ll cnt = 0, fi = -1, se = -1;
        for(int i = 1 ; i <= n ; i++) {
            cin >> a[i];
            if(a[i] % 2 != 0 && fi == -1) fi = i;
            else if (a[i] & 1) se = i;
        }
        if(se - fi + 1 <= x) cout << "YES\n";
        else cout << "NO\n";
    }   
}
