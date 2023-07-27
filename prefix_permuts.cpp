#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1851D

void solve(){
    int n; cin>>n; int a[n-1];
    for(auto &e:a)cin>>e;
    vector<int> real(n-1);
    real[0] = a[0];
    for(int i=1; i<n-1; ++i){
        real[i] = a[i]-a[i-1];
    }
    sort(real.begin(),real.end());
    multiset<int> real2;
    for(auto e:real){
        real2.insert(e);
    }
    vector<int> missing;
    for(int i=1; i<=n; ++i){
        if(real2.find(i) == real2.end())
            missing.push_back(i);
    }
    if(missing.size() < 2){
        cout << "YES\n"; return;
    }
    int fix = 0;
    for(int i=0; i<n-1; ++i){
        if(real[i]>n or (i and real[i]==real[i-1])){
            fix = real[i];
            break;
        }
    }
    if(missing.size()==2 and missing[0]+missing[1]==fix)
        cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}