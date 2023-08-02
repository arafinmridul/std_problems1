#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 474B worms

void solve(){
    int n; cin>>n;
    vector<pair<int,int>>v(n);
    int prev = 0;
    for(int i=0; i<n; ++i){
        int x; cin>>x;
        v[i] = {prev+1,prev+x};
        prev += x;
    }
    int m; cin>>m;
    while(m--){
        int target; cin>>target;
        int l=0,r=n;
        while(l <= r){
            int mid = (l+r) >> 1;
            if(v[mid].first <= target and v[mid].second >=target){
                cout << mid+1 << nl;
                break;
            }
            else if(v[mid].first < target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}