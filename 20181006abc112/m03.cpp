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

int i,j,k,l,m,n;
/////////////////////////////////////////////////////


ll N;
ll h[111][111];
int x[111],y[111];

int sub(int &x1,int &y1,int &x2,int &y2){
    return (x1>x2?x1-x2:x2-x1)+(y1>y2?y1-y2:y2-y1);
}

int main(){
    scanf("%lld",&N);
    fornum(i,0,111){
        fornum(j,0,111){
            h[i][j]=-1;
        }
    }
    fornum(i,0,N){
        scanf("%d%d",&x[i],&y[i]);
        scanf("%lld",&h[x[i]][y[i]]);
    }
    /*
    fornum(i,0,6){
        fornum(j,0,6){
            printf("%lld ",h[i][j]);
        }
        printf("\n");
    }
    */
    fornum(i,0,101){
        fornum(j,0,101){
            int flag=1;
            ll checkh=0;
            fornum(k,0,N){
                if(h[x[k]][y[k]]==0)
                    continue;
                checkh=h[x[k]][y[k]]+sub(i,j,x[k],y[k]);
                break;

            }

            fornum(k,0,N){
                if(h[x[k]][y[k]]==0&&checkh<sub(i,j,x[k],y[k]))
                    continue;
                if(checkh!=h[x[k]][y[k]]+sub(i,j,x[k],y[k])){
                    
                    flag=0;
                    break;
                }

            }
            /*
            fornum(k,0,101){
                fornum(l,0,101){
                    if(checkh==-1){
                        if(h[k][l]==-1)
                            continue;
                        else
                            checkh=h[k][l]+sub(i,j,k,l);
                    }
                    if(h[k][l]!=-1&&checkh!=h[k][l]+sub(i,j,k,l)){
                        flag=0;
                        break;
                    }
                }
                if(flag==0)
                    break;
            }
            */
            if(flag==1){
                printf("%d %d %lld",i,j,checkh);
                return 0;
            }
        }
    }

    return 0;
}