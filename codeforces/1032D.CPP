//1032D. 1709
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
        cin >> n;
        vector<ll> arrA(n), arrB(n);
        for(int i = 0; i < n; i++) cin >> arrA[i];
        for(int i = 0; i < n; i++) cin >> arrB[i];

        vector<pair<int,int>> operations;

        for(int i = 0; i < n; i++){
            for(int j = 0; j + 1 < n - i; j++){
                if(arrA[j] > arrA[j+1]){
                    operations.emplace_back(1, j+1);
                    swap(arrA[j], arrA[j+1]);
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j + 1 < n - i; j++){
                if(arrB[j] > arrB[j+1]){
                    operations.emplace_back(2, j+1);
                    swap(arrB[j], arrB[j+1]);
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(arrA[i] > arrB[i]){
                operations.emplace_back(3, i+1);
                swap(arrA[i], arrB[i]);
            }
        }

        cout << operations.size() << "\n";
        for(auto &p : operations){
            cout << p.first << " " << p.second << "\n";
        }
    }    
}
