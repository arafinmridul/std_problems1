#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 912B new year's eve

void solve(){
    int n,k; cin>>n>>k;
    //if k==1, then we have only option to pick a single number;
    //And the optimal choice would be taking the maximum number, which is n;
    /*now, if by any chance, k is equal to 2, then there exists a number which has
    set bits in the positions where n doesn't have.
    For example, n = 16 (10000); 15's bin representation is 1111;
    xor of 16 and 15 is 11111 (binary representation);
    */
    if(k == 1){
        cout << n << nl;
        return;
    }
    int bit_pos = 64 - __builtin_clzll(n) - 1; // num of bits after the leftmost set bit
    int pow_of_2 = (1LL << bit_pos); // 2^n takes (n+1) bits
    int ans = pow_of_2 | (pow_of_2 - 1); // filling every unset bit
    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}