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
#define MOD (ll)(1e9+7)
#define OC(A,B,C) (C!=-1&&A+B<(C-A+N2)%N2+A)

int N,N2,K,A[666],B[666];
int mk[666];

int i,j,k;

ll f[666][666],g[666][666];
ll dp[666][666];

int main(){
    scanf("%d%d",&N,&K);
    N2=N*2;
    fornum(i,0,N2){
        mk[i]=-1;
    }
    fornum(i,0,K){
        scanf("%d%d",&A[i],&B[i]);
        mk[A[i]-1]=B[i]-1;
        mk[B[i]-1]=A[i]-1;
    }

    //点i~j%N2までの空いている点の数を求める
    fornum(i,0,N2){
        f[i][i]=mk[i]==-1?1:0;
        fornum(j,i+1,N2+i){
            int J=j%N2;
            f[i][J]=f[i][(j-1)%N2];
            if(mk[J]==-1){
                f[i][J]++;
            }
        }
    }

    //空いている点から線のパターンを求める
    fornum(i,0,N2){
        fornum(j,0,N2){
            
            int J=(i+j)%N2;
             if(f[i][J]%2){
                dp[i][J]=0;
                continue;
            }
            fornum(k,0,j+1){
                if(OC(i,j,mk[(i+k)%N2])){
                    dp[i][J]=0;
                    J=-1;
                    break;
                }
            }
            if(J==-1)
                continue;
            g[i][J]=1;
            for(k=f[i][J]-1;k>0;k-=2){
                g[i][J]=(g[i][J]*k)%MOD;
            }
            dp[i][J]=g[i][J];
        }
    }

    //動的計画法から
    ll ans=0;
    fornum(i,0,N2){
        fornum(j,i,N2){
            if(dp[i][j]==0)continue;
            fornum(k,i,j){
                dp[i][j]=(dp[i][j]+MOD-(dp[i][k]*g[k+1][j]%MOD))%MOD;
            }
            ans=(ans+dp[i][j]*(j-i!=N2-1?g[(j+1)%N2][(i+N2-1)%N2]:1))%MOD;
        }
    }
    printf("%lld\n",ans);
    return 0;
}



