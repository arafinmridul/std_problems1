#include<bits/stdc++.h>
using namespace std;
#define int long long

//295A
//Range update using the Inclusion Exclusion Formula
/*The Formula -
taking a helper array, let's suppose the range is [l,r]
the size of the array must be = (max value of r + 1)
then increasing the value in idx (l) and
decreasing the value in idx (r+1)
*/

signed main(){
    int n,m,k; cin>>n>>m>>k;
    int a[n];
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    vector<pair<int,int>>v(m); int d[m];
    int x,y;
    for(int i=0; i<m; ++i){
        cin>>x>>y>>d[i];
        --x,--y;
        v[i] = {x,y};
    }
    //counting operations for m after queries
    int q[m+1]; memset(q,0,sizeof(q));
    for(int i=0; i<k; ++i){
        cin>>x>>y;
        x--,y--;
        q[x]++; q[y+1]--;
    }
    for(int i=1; i<m; ++i){
        q[i]+=q[i-1];
    }
    //values to be added after operations
    int opera[n+1]; memset(opera,0,sizeof(opera));
    for(int i=0; i<m; ++i){
        opera[v[i].first]+=(q[i]*d[i]);
        opera[v[i].second+1]-=(q[i]*d[i]);
    }
    for(int i=1; i<n; ++i){
        opera[i]+=opera[i-1];
    }
    //updated array
    for(int i=0; i<n; ++i){
        cout<<(a[i]+opera[i])<<' ';
    } cout<<'\n';
}