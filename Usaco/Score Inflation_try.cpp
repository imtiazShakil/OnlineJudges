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
#define MAX 10005
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

int dp[MAX];

//void gen(void)
//{
//    dp[0]=1;
//    for(int i=0;i<SZ(v);i++)
//    {
//        for(int j=tm;j>=0;j--)
//        {
//            if( dp[j] )
//            {
//                if(j+v[i].sc <=tm)
//                {
////                    if( dp[j+v[i].sc]<0 ) dp[j+v[i].sc]=0;
//                    if(j!=0) dp[j+v[i].sc]=max(dp[j+v[i].sc],dp[j]+v[i].fs);
//                    else dp[j+v[i].sc]=max(dp[j+v[i].sc],v[i].fs);
//                }
//            }
//        }
//    }
//    return ;
//}

int gen(void)
{
    dp[0]=0;
    for(int i=0;i<SZ(v);i++)
    {
        for(int j=0;j<=tm;j++)
        {
            if(dp[j]>=0)
            {
                if( j+v[i].sc<=tm )
                {
                    if(dp[j+v[i].sc]<0) dp[j+v[i].sc]=0;
                    dp[j+v[i].sc]=max(dp[j+v[i].sc],dp[j]+v[i].fs);
                }
            }
        }
    }
    int tot=0;
    for(int i=0;i<=tm;i++) tot=max(tot,dp[i]);
    return tot;
}
int main(void)
{
    freopen("inflate.in","r",stdin);
    freopen("inflate.out","w+",stdout);
    int va1,va2;
//    mem(dp,-1);
    scanf("%d %d",&tm ,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&va1,&va2);
        v.pb(mp(va1,va2));
//        for(int p=va2+va2;p<=tm;p+=va2) v.pb(mp(va1,va2));
    }
    mem(dp,-1);
    int ans=gen();
    print1(ans);


    return 0;
}


