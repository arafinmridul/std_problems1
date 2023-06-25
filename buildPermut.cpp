#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'
//some permutation building
void solve(){
    int n; cin>>n;
    vector<int> v(n,-1);
    unordered_set<int> s;
    for(int i=0; i<n; ++i)s.insert(i);
    auto sqr = [&](int num)->int{
        int r = 0;
        while(r*r <= num) r++;
        return r-1;
    };
    for(int i=n-1; i>=0; --i){
        int x = sqr(i);
        while(x*x - i <= n-1){
            if(s.find((x*x)-i) != s.end()){
                v[i] = x*x - i;
            }
            ++x;
        }
        if(v[i] == -1){
            cout << -1 << nl;
            return;
        }
        s.erase(v[i]);
    }
    for(auto &e:v) cout << e << ' ';
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