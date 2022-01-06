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
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second
#define MAX 60
#define mod 100000000
///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

int k1,k2;

ll dp1[110][110];
ll dp2[110][110];

ll rec1(int foot,int horse)
{
    if(foot+horse==0) return 1LL;
    if( foot==0  || horse ==0 )
    {
        if( horse ) return 0LL;
        if(foot && foot <=k1 ) return 1LL;
        else return 0LL;
    }

    ll &ret=dp1[foot][horse];
    if(ret!=-1) return ret;

    ret=0;

    for(int f=1;f<=min(foot,k1);f++ )
    {
        for(int h=1;h<=min(horse,k2);h++ )
        {
            ret+=(rec1( foot-f,horse-h )%mod) ;
        }
    }
    ret=ret%mod;
    return ret;
}


ll rec2(int horse,int foot)
{
    if(foot+horse==0) return 1LL;
    if( foot==0  || horse ==0 )
    {
        if( horse && horse<=k2 ) return 1LL;
        if(foot) return 0LL;
        else return 0LL;
    }

    ll &ret=dp2[horse][foot];
    if(ret!=-1) return ret;

    ret=0;

    for(int h=1;h<=min(horse,k2);h++ )
    {
        for(int f=1;f<=min(foot,k1);f++ )
        {
            ret+=(rec2( horse-h,foot-f )%mod) ;
        }
    }
    ret=ret%mod;
    return ret;
}


int main(void)
{
    int n1,n2;
    scanf("%d %d %d %d",&n1,&n2,&k1,&k2);

    mem(dp1,-1);
    mem(dp2,-1);

    ll ans=rec1(n1,n2);
    ans=ans%mod;

//    print2("f h ",ans);

    ans+=rec2(n2,n1);
    ans=ans%mod;

//    print2("h f ",);
    print1(ans);

    return 0;
}

