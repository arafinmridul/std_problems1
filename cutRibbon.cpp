#include<bits/stdc++.h>
using namespace std;

//189A
//O(n3) solution to O(n2) solution by using ax+by+cz=n

int main(){
    int n,a[3]; cin>>n>>a[0]>>a[1]>>a[2];
    sort(a,a+3,greater<int>());
    int i=0,j=0,ct=0;
    int x=n/a[0],y=n/a[1];
    for(i=0; i<=x; ++i){
        for(j=0; j<=y; ++j){
            if(!((n-(a[0]*i)-(a[1]*j))%a[2]))
                ct = max(ct,i+j+((n-(a[0]*i)-(a[1]*j))/a[2]));
        }
    } cout<<ct<<'\n';
}