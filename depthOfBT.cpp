#include<bits/stdc++.h>
using namespace std;
//115A
//concept of BT
//any two members of the same node can not be in the same group
//the answer is the maximum depth a node has
int main(){
    int n; cin>>n; int a[n+1];
    for(int i=1; i<=n; ++i)cin>>a[i];
    int teams=0;
    int nodes;
    for(int i=1; i<=n; ++i){
        int idx=i;
        nodes=0;
        while(idx!=-1){
            nodes++;
            idx=a[idx];
        }
        teams = max(teams,nodes);
    }
    cout<<teams<<'\n';
}