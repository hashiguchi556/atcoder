#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <string>
#include <map>
#include <set>
#include <list>
#include <stdio.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)

using namespace std;
////////////////////////////
#define pll pair<ll,ll>
#define mkp make_pair

ll N,A[101010],B[101010];
ll i;

vector<pll> vAB;
bool ck[101010];
ll ans=0;

int main(){
    scanf("%lld",&N);
    //ll mina=LLONG_MAX,minb=0,minc=-1;
    fornum(i,0,N){
        scanf("%lld%lld",&A[i],&B[i]);
    }

    fornum(i,0,N){
        vAB.push_back(mkp(A[i],i));
        vAB.push_back(mkp(B[i],i));
    }
    sort(vAB.begin(),vAB.end());
    
    ll rslt=0;
    fornum(i,0,N)
        ans+=A[i];
    fornum(i,0,N)
        rslt+=B[i];
    if(rslt<ans)ans=rslt;

    bool fg=false;
    rslt=0;
    fornum(i,0,N){
        auto s=vAB[i];
        rslt+=s.first;
        if(ck[s.second])
            fg=true;
        else
            ck[s.second]=true;
    }
    if(fg){
        if(rslt<ans)ans=rslt;
    }else{
        ll Nrslt=rslt;
        auto ns=vAB[N];
        fornum(i,0,N){
            auto s=vAB[i];
            if(ns.second!=s.second){
                rslt=Nrslt-s.first+ns.first;
            }else{
                rslt=Nrslt-s.first+vAB[N+1].first;
            }
            if(rslt<ans)ans=rslt;
        }
    }
    

    printf("%lld\n",ans);

    return 0;
}



