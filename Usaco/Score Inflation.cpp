/*
ID: shakil1
PROG: inflate
LANG: C++
*/
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
#define MAX 1002
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

int tm,n;
vector<paii>v;

int dp[MAX][MAX];

int rec(int indx,int tme_av)
{
    if(indx==n) return 0;

    int &ret=dp[indx][tme_av];
    if(ret!=-1) return ret;

    ret=0;
    int tt=v[indx].sc;
    int pt=v[indx].fs;
    int c=0;
    while( tme_av>= c*tt )
    {
        ret=max(ret,c*pt+rec(indx+1,tme_av-c*tt) );
        c++;
    }
    return ret;
}
int main(void)
{
    freopen("inflate.in","r",stdin);
    freopen("inflate.out","w+",stdout);
    int va1,va2;
    mem(dp,-1);
    scanf("%d %d",&tm ,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&va1,&va2);
        v.pb(mp(va1,va2));
    }
    int ans=rec(0,tm);
    print1(ans);

    return 0;
}

