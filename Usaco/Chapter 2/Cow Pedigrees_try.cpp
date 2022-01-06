/*
ID: shakil1
PROG: nocows
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
#define MAX 200
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

int dp[MAX][MAX];
const int md=9901;

int rec(int n,int k)
{
    int &ret=dp[n][k];
    if(ret!=-1) return ret;

    if(n%2==0) return ret=0;
    if(n < 2*k-1 ) return ret=0;
    if(n==1 & k==1) return ret=1;
    if(n && k==1 ) return ret=0;

    int sol;
    int n1,n2;
    ret=0;
    for(int i=1;i<=n/2;i+=2 )
    {
        n1=i;n2=n-i-1;
        sol=0;
        for(int j=1; j < k-1 ;j++ )
        {
            sol+=rec(n1,j) * rec(n2,k-1);
            sol+=rec(n1,k-1) * rec(n2,j);
            sol%=md;
        }
        sol+=rec(n1,k-1)* rec(n2,k-1);

        if(n1!=n2) ret+=(sol*2);
        else ret+=sol;

        ret%=md;
    }
    ret%=md;
    return ret%md;
}

int main(void)
{
    freopen("nocows.in","r",stdin);
    freopen("nocows.out","w+",stdout);

    int n,k;
    scanf("%d %d",&n,&k);
    mem(dp,-1);

    int ans=rec(n,k);
    print1(ans);


    return 0;
}

