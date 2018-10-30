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

char S[10];
int main(){
    scanf("%s",&S);
    int Sn=0;
    for(Sn=0;S[Sn]!='\0';Sn++);
    if(Sn==3){
        char s=S[0];
        S[0]=S[2];
        S[2]=s;
    }
    printf("%s",S);
    
    return 0;
}