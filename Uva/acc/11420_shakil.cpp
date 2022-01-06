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
#define rep(x,n)        for(x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define fs      first
#define sc      second

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;
ll dp[70][70][2];

ll rec(int n,int s,int prv)
{
    if(n<0 || s<0 ) return 0;
    ll &ret=dp[n][s][prv];
    if(ret!=-1) return ret;
    ret=0;
    if(prv) ret=rec(n-1,s-1,prv) + rec(n-1,s,0);
    else ret=rec(n-1,s,1) + rec(n-1,s,0);
    return ret;
}

int main(void)
{
    mem(dp,-1);
    dp[1][0][0]=2;dp[1][0][1]=1;dp[1][1][0]=0;dp[1][1][1]=1;
    int n,s;
    ll ans;
//    while(cin>>n>>s)
    while(scanf("%d %d",&n,&s)==2 && (n>=0 && s>=0))
    {
        ans=rec(n,s,1);
//        print1(ans);
        printf("%lld\n",ans);
    }
    return 0;
}

