#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1607D

void solve(){
    int n; cin>>n; int a[n];
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    string s; cin>>s;
    multiset<int>blue,red;
    for(int i=0; i<n; ++i){
        if(s[i]=='B'){
            blue.insert(a[i]);
        }
        else{
            red.insert(a[i]);
        }
    }
    for(int i=n; i>=1; --i){
        auto it = red.upper_bound(i);
        if(it != red.begin() and red.empty()==0){
            it--;
            red.erase(it);
            continue;
        }
        it = blue.lower_bound(i);
        if(it != blue.end() and blue.empty()==0){
            blue.erase(it);
            continue;
        }
        cout << "NO\n"; return;
    }
    cout << "YES\n"; return;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}