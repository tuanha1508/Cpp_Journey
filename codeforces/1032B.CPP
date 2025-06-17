//1032B. Above the Clouds
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
        cin >> n >> s;
        unordered_map<char, ll> cnt;

        for(auto i : s) cnt[i]++;

        bool check = false;

        cnt[s[s.size() - 1]]--;
        cnt[s[0]]--;

        for(int i = 1 ; i < n - 1 ; i++) {

            if(s[i] == s[0] || s[i] == s[n - 1]) {
                if(cnt[s[i]] > 0) {
                    check = true;
                    break;
                }
            }
            else {
                if(cnt[s[i]] > 1) {
                    check = true;
                    break;
                }
            }
        }

        if(check == true) cout << "YES \n";
        else cout << "NO \n";
    }    
}
