//1029B. Shrink
/*
    Time Complexity: O(n)
    Space Complexity: O(1)
    
    Problem Overview: 
    - Given n, we can take any permutation n integers :
        if a[i] > a[i + 1] and a[i] > a[i - 1] then we can remove a[i] and get one score
    - Return the maximum score we can get with the permutation

    Approach: Math, Greedy
    - We can always remove any other a[i] > 2
    - So just keep the 1 in position 1 and 2 in last position, then the middle is the array decreasing from n to 3
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
