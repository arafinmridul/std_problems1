#include<bits/stdc++.h>
using namespace std;
#define int long long

//1797C CF
//Interactive Problem

signed main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        int currDist;
        cout << "? 1 1" << '\n' << flush;
        cin>>currDist;
        int temp = currDist+1;
        if(temp>m){
            cout<<"? "<<temp<<' '<<m<<'\n'<<flush;
            cin>>currDist;
            cout<<"! "<<temp<<' '<<m-currDist<<'\n';
        }
        else if(temp>n){
            cout<<"? "<<n<<' '<<temp<<'\n'<<flush;
            cin>>currDist;
            cout<<"! "<<n-currDist<<' '<<temp<<'\n';
        }
        else{
            cout<<"? "<<temp<<' '<<temp<<'\n'<<flush;
            cin>>currDist;
            cout<<"? "<<temp-currDist<<' '<<temp<<'\n'<<flush;
            int fin; cin>>fin;
            if(!fin)
                cout<<"! "<<temp-currDist<<' '<<temp<<'\n';
            else
                cout<<"! "<<temp<<' '<<temp-currDist<<'\n';
        }
        fflush(stdout);
    }
}