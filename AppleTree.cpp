#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1843D

//Yet to be optimized

const int N = 2e5+7;
vector<int> g[N];
bool vis[N];
int dp[N];

int dfs(int ver){
    vis[ver] = true;
    int ans = 0;
    int f = 0;
    for(int child:g[ver]){
        if(vis[child]) continue;
        f = 1;
        ans += dfs(child);
    }
    return (!f) ? dp[ver] = 1 : dp[ver] = ans;
}

void solve(){
    int n; cin>>n;
    for(int i=1; i<=n; ++i){
        vis[i] = false;
        g[i].clear();
        dp[i] = 0;
    }
    for(int i=0; i<n-1; ++i){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    int q; cin>>q;
    while(q--){
        int x,y; cin>>x>>y;
        cout << dp[x]*dp[y] << nl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}