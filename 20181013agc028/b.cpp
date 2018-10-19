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

#define MOD ((ll)1e9+7)

ll N;
ll A[101010];

ll P[202020];


ll moddiv(ll a,ll b){
    ll i=0;
    ll bb=b;
    
    while(true){
        if((MOD-2)&((ll)1<<i)){
            a=a*bb%MOD;
        }else if((MOD-2)<((ll)1<<i)){
            break;
        }
        bb=bb*bb%MOD;
        i++;
    }
    return a;
}

int main(){
    ll a,b;
    scanf("%lld",&N);
    for(i=0;i<N;i++){
        scanf("%lld",&A[i]);
    }
    
    ll fact=1;
    for(ll i=1;i<=N;i++){
        fact=(fact*i)%MOD;
    }
    
    for(ll i=N;i>0;i--){
        P[N-i]=P[N+i-2]=moddiv(fact,i);
    }

    ll Psum=0;

    for(ll i=0;i<N;i++){
        Psum=(Psum+P[i])%MOD;
    }
    
    ll ans=0;
    for(ll i=0;i<N;i++){
        
        ans=(ans+A[i]*Psum)%MOD;
        Psum=(Psum+MOD+P[i+N]-P[i])%MOD;
    }
    
    printf("%lld",ans);
    
    return 0;
}