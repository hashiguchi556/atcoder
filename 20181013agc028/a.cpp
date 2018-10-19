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

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)

using namespace std;

int i,j,k,l,m,n;
/////////////////////////////////////////////////////


ll a;
ll N,M;
char S[101010],T[101010];
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int main(){
    
    scanf("%lld%lld%s%s",&N,&M,S,T);
    ll g=gcd(N,M);
    ll l=N*M/g;
    ll n=l/N,m=l/M;
    ll ni=0,mi=0;
    ll ans=0;
    while(true){
        while(ni*n<mi*m)ni++;
        while(mi*m<ni*n)mi++;
        if(mi*m==ni*n){
            if(ni==N)
                break;
            if(S[ni]!=T[mi]){
                printf("-1\n");
                return 0;
            }
            mi++;
        }
    }
    printf("%lld\n",l);
    return 0;
}