#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1538C

void solve(){
    int n,l,r; cin>>n>>l>>r;
    vector<int>v(n);
    for(auto &e:v)cin>>e;
    sort(v.begin(),v.end());
    int ans = 0;
    for(int i=0; i<n; ++i){
        if(v[i] > r)
            break;
        int reqL = l-v[i];
        int reqR = r-v[i];
        int temp = upper_bound(v.begin()+i,v.end(),reqR)-lower_bound(v.begin()+i,v.end(),reqL);
        ans += temp;
        if(2*v[i]>=l and 2*v[i]<=r)
            ans--;
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