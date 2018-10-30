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

ll N;
ll k;
ll S[500][500];

ll i,j;

int main(){
    scanf("%lld",&N);
    ll n=0;
    for(k=1;n<N;k++)n+=k;
    if(N!=n){
        printf("No\n");
        return 0;
    }
    
    printf("Yes\n");
    printf("%lld\n",k);
    ll sc=1;
    fornum(i,0,k){
        printf("%lld ",k-1);
        fornum(j,0,i){
            S[i][j]=S[j][i-1];
            printf("%lld ",S[i][j]);
        }
        fornum(j,i,k-1){
           S[i][j]=sc;
           sc+=1;
           printf("%lld ",S[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}