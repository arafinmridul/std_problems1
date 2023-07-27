#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'
#define INF 1e10

//CF 1851E

const int N = 2e5+7;
vector<int> adj[N];
vector<bool> vis;
vector<int> cost;

void dfs(int curr){
    int res = 0;
    vis[curr] = true;
    bool hasChi = false;
    for(auto e:adj[curr]){
        hasChi = true;
        if(vis[e] == false){
            dfs(e);
        }
        res += cost[e];
    }
    if(hasChi == false){
        res = INF;
    }
    cost[curr] = min(cost[curr],res);
}

void solve(){
    int n,k; cin>>n>>k;

    vis.assign(n+1,false);    
    cost.assign(n+1,INF);
    for(int i=0; i<=n; ++i)
        adj[i].clear();

    for(int i=1; i<=n; ++i){
        cin >> cost[i];
    }
    for(int i=0; i<k; ++i){
        int p; cin>>p;
        cost[p] = 0;
    }
    for(int i=1; i<=n; ++i){
        int m; cin>>m;
        for(int j=0; j<m; ++j){
            int x; cin>>x;
            adj[i].push_back(x);
        }
    }

    for(int i=1; i<=n; ++i){
        if(vis[i] == false){
            dfs(i);
        }
    }

    for(int i=1; i<=n; ++i){
        cout << cost[i] << ' ';
    }
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}