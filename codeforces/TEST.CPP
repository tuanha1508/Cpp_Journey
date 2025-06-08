#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll N = 200005;
int t, n;
signed main(){
    #ifndef ONLINE_JUDGE
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        vector<int> r0A, r0B, r1A, r1B;
        int dp0=0, dp1=LLONG_MIN;
        for(int idx=n-1;idx>=0;--idx){
            int old0=dp0;
            auto oldA=r0A, oldB=r0B;
            vector<int> newA, newB;
            newA.reserve(10); newB.reserve(10);
            newA.push_back(a[idx]);
            for(int v:oldB) if(newA.size()<10){
                bool f=0; for(int x:newA) if(x==v){f=1;break;}
                if(!f) newA.push_back(v);
            }
            newB.push_back(b[idx]);
            for(int v:oldA) if(newB.size()<10){
                bool f=0; for(int x:newB) if(x==v){f=1;break;}
                if(!f) newB.push_back(v);
            }
            bool ok0=0;
            for(int x:newA) for(int y:newB) if(x==y){ok0=1;break;}
            int new0=old0+(ok0?1:0);
            int best1=LLONG_MIN; vector<int> bestA, bestB;
            if(dp1!=LLONG_MIN){
                vector<int> tA,tB;
                tA.reserve(10); tB.reserve(10);
                tA.push_back(a[idx]);
                for(int v:r1B) if(tA.size()<10){
                    bool f=0; for(int x:tA) if(x==v){f=1;break;}
                    if(!f) tA.push_back(v);
                }
                tB.push_back(b[idx]);
                for(int v:r1A) if(tB.size()<10){
                    bool f=0; for(int x:tB) if(x==v){f=1;break;}
                    if(!f) tB.push_back(v);
                }
                bool ok1=0;
                for(int x:tA) for(int y:tB) if(x==y){ok1=1;break;}
                int c1=dp1+(ok1?1:0);
                best1=c1; bestA=tA; bestB=tB;
            }
            int c2=old0;
            if(c2>=best1){
                best1=c2; bestA=oldA; bestB=oldB;
            }
            dp0=new0; r0A.swap(newA); r0B.swap(newB);
            dp1=best1; r1A.swap(bestA); r1B.swap(bestB);
        }
        cout<<max(dp0,dp1)<<"\n";
    }
    return 0;
}
