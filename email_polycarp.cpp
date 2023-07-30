#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1185B

void modify(vector<pair<char,int>>&v, string str){
    for(int i=0; i<str.size(); ++i){
        if(i==0){
            v.push_back({str[i],1});
            continue;
        }
        if(str[i] == str[i-1]){
            v.back().second++;
        }
        else{
            v.push_back({str[i],1});
        }
    }
}

void solve(){
    string s,p; cin>>s>>p;
    vector<pair<char,int>>ff,ss;
    modify(ff,s);
    modify(ss,p);
    if(ff.size() != ss.size()){
        cout << "NO" << nl;
        return;
    }
    for(int i=0; i<ff.size(); ++i){
        if(ff[i].first != ss[i].first or ff[i].second>ss[i].second){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}