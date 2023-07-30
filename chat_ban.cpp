#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1612C chat_ban

int go(int n){
    return (n*(n+1))/2;
}

void solve(){
    int k,x; cin>>k>>x;

    int ans = 0;
    int total = go(k) + go(k-1);
    int l = 1, r = 2*k-1;
    while(l <= r){
        int mid = (l+r) >> 1;
        int emos = 0;
        if(mid > k){
            emos = total - go(2*k - mid);
        }
        else{
            emos = go(mid-1);
        }
        if(emos < x){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
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