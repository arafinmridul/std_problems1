#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1848B the bridge

const int N = 2e5+12;
vector<int> idx[N];

void solve(){
    int n,k; cin>>n>>k;
    for(int i=1; i<=k; ++i){
        idx[i].clear();
    }
    int lastIdx[k+1]; memset(lastIdx,-1,sizeof lastIdx);
    for(int i=0; i<n; ++i){
        int x; cin>>x;
        idx[x].push_back(i-(lastIdx[x]+1));
        lastIdx[x] = i;
    }
    int mn = 1e9;
    for(int i=1; i<=k; ++i){
        if(idx[i].empty() == false){
            idx[i].push_back(n-1-lastIdx[i]);
            sort(idx[i].begin(),idx[i].end());
            int sz = idx[i].size();
            int mx = max((idx[i][sz-1])/2,idx[i][sz-2]);
            mn = min(mn,mx);
        }
    }
    cout << mn << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}