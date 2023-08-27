#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1176C

void solve(){
    int n; cin>>n;
    map<int,int> mp;
    mp[4] = mp[8] = mp[15] = mp[16] = mp[23] = mp[42] = 0;
    int seq = 0;
    for(int i=0; i<n; ++i){
        int x; cin>>x;
        bool ok = true;
        auto it = mp.find(x);
        if(it != mp.begin()){
            it--;
            if(mp[x] == it->second)
                ok = false;
        }
        if(ok)mp[x]++;
        if(ok and x==42){
            ++seq;
            for(auto &[p,q]:mp)
                q--;
        }
    }
    cout << n - seq*6 << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}