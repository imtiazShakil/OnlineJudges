#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


#define print1(a) cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define PI (2*acos(0))
#define ERR 1e-5
#define ll long long
#define VI vector<int>
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define MAX 100005
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

int n;
char str[MAX];
bool flag=0;

//vector<int>ch[300];

bool ok(int len,char c)
{
    bool fl=1;
    int prv=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]==c)
        {
            if(prv==0)
            {
                prv=i+1;
                continue;
            }
            if(abs(i+1 - prv ) !=4 && abs(i+1 - prv ) !=7) {fl=0;break;}
            prv=i+1;
        }
    }
    if(prv!=0) if(abs(len+1 - prv ) !=4 && abs(len+1 - prv ) !=7) fl=0;

    return fl;
}

void rec(int depth)
{
    if(depth==n) {flag=1;print1(str);return ; }

    for(int i='a';i<='z';i++)
    {
        if( ok( depth, i)  )
        {
            str[depth]=i;
            rec(depth+1);
            if(flag) return ;
        }
        if(flag) return ;
    }
    return ;
}
int main(void)
{
    scanf("%d",&n);
    rec(0);

    return 0;
}

