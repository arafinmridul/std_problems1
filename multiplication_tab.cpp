#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1850F We were both children

void solve(){
    int n; cin>>n;
    vector<int> occ(n+1,0), mx(n+1,0);
    for(int i=0; i<n; ++i){
        int x; cin>>x;
        if(x<=n)
            occ[x]++;
    }
    //multiplication table type operation
    int num_of_ops = 0; // to check if it can run
    for(int i=1; i<=n; ++i){
        for(int j=i; j<=n; j+=i){
            mx[j] += occ[i];
            num_of_ops++;
        }
    }
    // cout << num_of_ops << nl;
    cout << *max_element(mx.begin(),mx.end()) << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}