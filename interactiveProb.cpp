#include<bits/stdc++.h>
using namespace std;
#define ll long long

//1807E
//Interactive Problem

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n; vector<ll>v(n+1);
        for(int i=1; i<=n; ++i) cin>>v[i];

        int special;
        int lo=1,hi=n;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(lo==hi){
                special = mid; break;
            }
            int len = mid-lo+1;
            cout<<"? "<<len<<' ';

            ll sum = 0;
            for(int i=lo; i<=mid; ++i){
                cout<<i<<' ';
                sum += v[i];
            } cout<<'\n';

            fflush(stdout);

            ll response; cin>>response;
            if(response>sum)
                hi = mid;
            else lo = mid+1;
        }
        cout<<"! "<<special<<'\n';
        fflush(stdout);
    }
}