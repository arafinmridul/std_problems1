#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1560D

vector<string> v;
void expos_2(){
    const int N = 2e18;
    int num = 1;
    while(num <= N){
        v.push_back(to_string(num));
        num *= 2;
    }
}

void solve(){
    int n = v.size();
    string s; cin>>s; int sz = s.size();
    int mn = INT64_MAX;
    for(int i=0; i<n; ++i){
        int temp = v[i].size();
        int mxSimilar = 0;
        for(int j=0,k=0; j<sz and k<temp; ++j){
            if(s[j] == v[i][k]){
                ++mxSimilar;
                ++k;
            }
        }
        int ans = sz - mxSimilar + temp - mxSimilar;
        mn = min(mn,ans);
    }
    cout << mn << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    expos_2(); //exponents of 2
    while(t--){
        solve();
    }
}