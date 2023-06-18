#include<bits/stdc++.h>
using namespace std;

//230B
//squares of prime numbers have exactly three divisors
//precomputing the primes and checking if it satisfies

#define int long long
const int N = 1e6+9;
int a[N]={0};
set<int>s;
void primes(){
    for(int i=2; i<N; ++i){
        if(!a[i]){
            s.insert(i);
            for(int j=i*i; j<N; j+=i)
                a[j]=1;
        }
    }
}
signed main(){
    primes();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int temp = sqrtl(n);
        if(s.find(temp)!=s.end() && temp*temp==n){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
}