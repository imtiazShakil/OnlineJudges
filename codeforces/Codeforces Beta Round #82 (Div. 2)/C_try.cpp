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
#define MAX 60
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second
#define left lftttt
///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

struct stuff
{
    int s_lft;
    int req_s,req_d;
    int lav;
};
int m,co,d_o;

vector<stuff>v;

int dp[1100][20];


int rec(int dough,int indx)
{
    if(indx==m+1) return 0;

    int &ret=dp[dough][indx];
    if(ret!=-1) return ret;
    int mn;
    ret=0;

    for(int i=0;i<=dough;i++)
    {
        mn=min( v[indx].s_lft/v[indx].req_s, i/v[indx].req_d ) ;

        ret=max(ret,rec(dough-mn*v[indx].req_d ,indx+1) + v[indx].lav*mn  )  ;
    }
    return ret;
}
int main(void)
{
    int n,ans;
    stuff tmp;

    scanf("%d %d %d %d",&n,&m,&co,&d_o);

    tmp.s_lft=100000;tmp.req_s=1;tmp.req_d=co;tmp.lav=d_o;
    v.pb(tmp);

    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d %d",&tmp.s_lft,&tmp.req_s,&tmp.req_d,&tmp.lav);
        v.pb(tmp);
    }
    mem(dp,-1);
    ans=rec(n,0);
    print1(ans);



    return 0;
}
