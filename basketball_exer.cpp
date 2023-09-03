#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1195C basketball_exercise

int n;
const int N = 2e5+7;
int a[2][N];
int dp[2][N];

int traverse(int side,int idx){
    if(dp[side][idx] != -1){
        return dp[side][idx];
    }
    int sd = side^1;
    int res = 0;
    if(idx+1 < n)
        res = max(res, traverse(sd,idx+1));
    if(idx+2 < n)
        res = max(res, traverse(sd,idx+2));
    res += a[side][idx];
    return dp[side][idx]=res;
}

void solve(){
    cin >> n;
    for(int i=0; i<2; ++i){
        for(int j=0; j<n; ++j){
            cin >> a[i][j];
            dp[i][j] = -1;
        }
    }
    int ans = max(traverse(0,0),traverse(1,0));
    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}