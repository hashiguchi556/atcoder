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

ll A,B,K;

int main(){
    scanf("%lld%lld%lld",&A,&B,&K);
    
    for(int i=0;i<K;i++){
        A=A%2?A-1:A;
        B+=A/2;
        A/=2;
        i++;
        if(K==i)
            break;
        B=B%2?B-1:B;
        A+=B/2;
        B/=2;
    }
    printf("%lld %lld",A,B);
    
    return 0;
}