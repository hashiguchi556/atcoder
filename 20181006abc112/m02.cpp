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


int N,T;
int c[1010],t[1010];
int ans=9999;

int main(){
    scanf("%d%d",&N,&T);
    fornum(i,0,N){
        scanf("%d%d",&c[i],&t[i]);
    }
    fornum(i,0,N){
        if(t[i]<=T){
            ans=ans<c[i]?ans:c[i];
        }
    }
    if(ans!=9999)
        printf("%d\n",ans);
    else
        printf("TLE\n");
    return 0;
}