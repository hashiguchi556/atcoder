#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include<climits>
#include <string>
#include <map>
#include <set>
#include <list>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)

using namespace std;

/////////////////////////////////////////////////////
#define pll pair<ll,ll>
#define mp make_pair
#define MOD 998244353l

ll N,A[606060];
ll lp[303030];
ll ct[303030];
ll ctrl;
ll ans;

ll i,j;

void zerort(){
    printf("0\n");
    exit(0);
}

int main(){
    scanf("%lld",&N);
    fornum(i,0,N){
        scanf("%lld",&A[i]);
        A[i+N]=A[i];
    }
    ll ast;
    ll Ac=A[0];
    for(ast=0;ast<N&&A[ast]==Ac;ast++);
    
    Ac=A[ast];
    lp[Ac]=ast;
    fornum(i,ast,ast+N){
        if(A[i]==Ac){
            ct[Ac]++;
            continue;   
        }
        if(ct[A[i]]!=0){
            zerort();
        }
        Ac=A[i];
        lp[Ac]=i;
        ct[Ac]++;
    }

    ctrl=ct[1]-1;
    if(ctrl==N-1){
        ans=1;
        fornum(i,1,N+1)
            ans=(ans*i)%MOD;
        printf("%lld\n",ans);
        return 0;
    }
    fornum(i,1,N+1)
        if(ctrl<ct[i]-1)
            zerort();
    
    ll space=0;
    ans=1;
    fornum(i,1,N+1){
        if(ct[i]==0){
            if(space==0)
                zerort();
            ans=(ans*space)%MOD;
            space--;
        }else{
            ll il=A[lp[i]-1];
            ll ir=A[lp[i]+ct[i]];
            if(il>i&&i<ir&&ct[i]-1<ctrl)
                zerort();
            if(il<i){
                if(i>ir){
                    ans=(ans*(ctrl-ct[i]+2<ct[il]?ctrl-ct[i]+2:ct[il]))%MOD;
                    ll ctiil=ct[il]+ct[i];
                    ct[il]=ctiil-ctrl-1>1?ctiil-ctrl-1:1;
                    ct[i]=ctiil-ct[il];
                }else{
                    ll ctiil=ct[il]+ct[i];
                    if(ctiil-ctrl-1<1)
                        zerort();
                    ct[i]=ctrl+1;
                    ct[il]=ctiil-ct[i];
                }
                space+=ct[il]-1;
            }
            if(i>ir){
                space+=ct[i]-1;
            }
        }
    }

    printf("%lld",ans);

    return 0;
}