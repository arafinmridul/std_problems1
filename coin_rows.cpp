#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1555C coin rows
//minimum of the maximums

void solve(){
    int n; cin>>n;
    vector<vector<int>> v(2,vector<int>(n));
    for(int i=0; i<2; ++i){
        for(int j=0; j<n; ++j){
            cin >> v[i][j];
        }
    }
    int sum_ff = 0;
    int sum_ss = 0;
    for(int i=0; i<n; ++i){
        sum_ff += v[0][i];
    }
    int ans = LONG_LONG_MAX;
    for(int i=0; i<n; ++i){
        sum_ff -= v[0][i];
        ans = min(ans, max(sum_ff,sum_ss));
        sum_ss += v[1][i];
    }
    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}