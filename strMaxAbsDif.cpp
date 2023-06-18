#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1834B
//Had to look up on its solution

void solve(){
    string s,p; cin>>s>>p;
    int x = s.size(), y = p.size();
    if(x<y){
        reverse(s.begin(),s.end());
        while(x<y){
            s+='0'; x++;
        }
        reverse(s.begin(),s.end());
    }
    int f = 0;
    for(int i=0; i<x; ++i){
        if(f){
            s[i] = '9';
            p[i] = '0';
        }
        if(s[i] != p[i])
            f = 1;
    }
    int ans = 0;
    for(int i=0; i<x; ++i){
        ans += abs(s[i]-p[i]);
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