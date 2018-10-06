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


ll N,M;

int main(){
    scanf("%lld%lld",&N,&M);
    if(N==1){
        printf("%lld\n",M);
        return 0;
    }
    ll ans;
    for(ans=M/N;true;ans--){
        if(M%ans==0&&N<=M/ans){
            break;
        }
    }
    printf("%lld\n",ans);
    
    return 0;
}