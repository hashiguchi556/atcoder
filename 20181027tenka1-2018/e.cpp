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
#define isIn(A,B) (0<=A&&A<H&&0<=B&&B<W)

ll H,W,MAX;
int coin[3333][3333];
ll S[3333][3333],BS[3333][3333];
ll ans;
ll i,j,k;

int main(){
    scanf("%lld%lld",&H,&W);
    MAX=H>W?H:W;
    fornum(i,0,H){
        char str[333];
        scanf("%s",str);
        fornum(j,0,W){
            if(str[j]=='#'){
                coin[i+1000][j+1000]=1;   
            }
        }
    }
    
    fornum(i,1,2000){
        fornum(j,1,2000){
            BS[i][j]=BS[i-1][j-1]+(coin[i][j]?1:0);
            S[i][W-j+1999]=S[i-1][W-j+2000]+(coin[i][W-j+1999]?1:0);
        }
    }

    fornum(i,0,H){
        fornum(j,0,W){
            for(k=1;k<MAX*2;k++){
                if(coin[i+k+1000][j+1000]&&coin[i+1000][j+k+1000]){
                    ans+=S[i+1000][j-k+1000]-S[i-k+999][j+1001];
                }
                if(coin[i-k+1000][j+1000]&&coin[i+1000][j-k+1000]){
                     ans+=S[i+k+1000][j+1000]-S[i+999][j+k+1001];
                }
                if(coin[i-k+1000][j+1000]&&coin[i+1000][j+k+1000]){
                    ans+=BS[i+k+999][j+999]-BS[i+1000][j-k+1000];
                }
                if(coin[i+k+1000][j+1000]&&coin[i+1000][j-k+1000]){
                    ans+=BS[i+999][j+k+999]-BS[i-k+1000][j+1000];
                }
            }
        }
    }

    printf("%lld\n",ans);
    
    return 0;
}