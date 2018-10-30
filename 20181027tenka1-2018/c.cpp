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
vector<ll> A;

ll i;

int main(){
    scanf("%lld",&N);
    fornum(i,0,N){
        ll a;
        scanf("%lld",&a);
        A.push_back(a);
    }
    
    sort(A.begin(),A.end());
    ll ans=0;
    fornum(i,0,N/2)
        ans-=A[i]*2;
    fornum(i,N/2,N)
        ans+=A[i]*2;
    if(N%2){
        ans=ans-(A[N/2+1]+A[N/2]-A[N/2-1])*2;
        ll a=A[N/2+1]*2-A[N/2]-A[N/2-1];
        ll b=A[N/2+1]+A[N/2]-A[N/2-1]*2;
        ans+=a>b?a:b;
    }else{
        ans=ans+A[N/2-1]-A[N/2];
    }
    printf("%lld",ans);
    
    
    return 0;
}