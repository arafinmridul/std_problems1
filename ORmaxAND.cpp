#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1669H
//replacing an element a[i] to (a[i]|2^j)(1<=j<=30)
//counting that as an operation, in atmost k operations
//the maximum value of and operations of the elements

void solve(){
    int n,k; cin>>n>>k; int a[n];
    for(auto &e:a)cin>>e;

    vector<int>bits;
    for(int bitpos=30; bitpos>=0; --bitpos){
        int available = 0;
        for(int i=0; i<n; ++i){
            if(a[i] & (1<<bitpos))
                available++;
        }
        if(n-available <= k){
            k -= (n-available);
            bits.push_back(bitpos);
        }
    }
    for(int i=0; i<n; ++i){
        for(auto &e:bits){
            a[i] |= (1<<e);
        }
    }
    int ans = a[0];
    for(int i=1; i<n; ++i){
        ans &= a[i];
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