#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using lll = long long;

//Append for OR CodeChef
//OR with the smallest number with the OR of array numbers to get the target number

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        lll n,y; cin>>n>>y; lll a[n];
        lll orr=0;
        for(auto &e:a){
            cin>>e;
            orr |= e;
        }
        if(y<orr){
            cout << -1 << endl;
            continue;
        }
        lll x=0;
        vector<int>v;
        while(y>0){
            if(!(y&1) and (orr&1)){
                cout << -1 << endl;
                goto tf;
            }
            else if((y&1) and (orr&1))
                v.push_back(0);
            else if(!(y&1) and !(orr&1))
                v.push_back(0);
            else if((y&1) and !(orr&1))
                v.push_back(1);
            y >>= 1; orr >>= 1;
        }
        x = 0;
        for(int i=v.size()-1; i>=0; --i){
            if(v[i]) x |= 1;
            if(i) x <<= 1;
        }
        cout << x << endl; tf:;
    }
}