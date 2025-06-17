//1032E. Sponsor of Your Problems
/*
    
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n;
string s;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif

    cin >> t;
    while (t--) {
        string leftStr, rightStr;
        cin >> leftStr >> rightStr;
        int len = leftStr.size();

        static ll dpMatches[12][2][2];
        const ll INF = LLONG_MAX / 4;

        for (int pos = 0; pos <= len; ++pos)
            for (int tightLow = 0; tightLow < 2; ++tightLow)
                for (int tightHigh = 0; tightHigh < 2; ++tightHigh)
                    dpMatches[pos][tightLow][tightHigh] = INF;

        for (int tightLow = 0; tightLow < 2; ++tightLow)
            for (int tightHigh = 0; tightHigh < 2; ++tightHigh)
                dpMatches[len][tightLow][tightHigh] = 0;

        for (int pos = len - 1; pos >= 0; --pos) {
            for (int tightLow = 0; tightLow < 2; ++tightLow) {
                for (int tightHigh = 0; tightHigh < 2; ++tightHigh) {
                    ll minCost = INF;
                    for (char digit = '0'; digit <= '9'; ++digit) {
                        if (tightLow  && digit <  leftStr[pos]) continue;
                        if (tightHigh && digit > rightStr[pos]) continue;

                        int nextTightLow  = tightLow  && (digit == leftStr[pos]);
                        int nextTightHigh = tightHigh && (digit == rightStr[pos]);
                        ll digitContribution = (digit == leftStr[pos]) + (digit == rightStr[pos]);
                        ll candidate = digitContribution
                                     + dpMatches[pos + 1][nextTightLow][nextTightHigh];

                        minCost = min(minCost, candidate);
                    }
                    dpMatches[pos][tightLow][tightHigh] = minCost;
                }
            }
        }

        cout << dpMatches[0][1][1] << '\n';
    }

    return 0;
}
