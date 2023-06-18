#include<bits/stdc++.h>
using namespace std;

//476B
//Combinatorics and Probability

int expo(int a,int b){
    int temp = 1;
    while(b--){
        temp*=a;
    }
    return temp;
}
int facto(int a){
    int ans = 1;
    while(a>0){
        ans*=a--;
    }
    return ans;
}
int main(){
    string s,p; cin>>s>>p;
    int plusS=0,minusS=0;
    for(int i=0; i<s.size(); ++i){
        if(s[i]=='+')plusS++;
        else minusS++;
    }
    int plusP=0,minusP=0,quesP=0;
    for(int i=0; i<p.size(); ++i){
        if(p[i]=='+')plusP++;
        else if(p[i]=='-')minusP++;
        else quesP++;
    }

    int plus=plusS-plusP,minus=minusS-minusP;
    double res=0;
    cout<<fixed<<setprecision(13);

    if(plus<0 || minus<0){
        res=0;
        cout<<res<<'\n';
        return 0;
    }
    if(!plus && !minus){
        res=1;
        cout<<res<<'\n';
        return 0;
    }

    int allPermute = expo(2,quesP);
    int needPermute = facto(quesP)/(facto(plus)*facto(minus));
    res = ((double)needPermute)/((double)allPermute);
    cout<<res<<'\n';
    return 0;
}