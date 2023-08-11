#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1487B cat cycle

void solve(){
    int n,k; cin>>n>>k;
    k--;
    int x = n / 2;
    int steps = k + (n&1) * (k / x);
    cout << (steps % n) + 1 << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}