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
#define MAX 1005
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second

using namespace std;

paii dim[MAX];
int n,mx;
int dp[MAX][6005];

int rec(int i,int carry)
{
//    print2(indx,carry);
    if(i==n) return 0;
//    if(carry==0) return 0;

    int &ret=dp[i][carry];
    if(ret!=-1) return ret;

    ret=0;
//    for(int i=indx; i<n; i++)
//    {
//        if(carry>=dim[i].fs)
//        {
//            ret=max(ret,rec(i+1,min(carry-dim[i].fs,dim[i].sc) ) + 1 );
//        }
//    }
    if(carry>=dim[i].fs)
    {
        ret=max(rec(i+1,carry) ,rec(i+1,min(carry-dim[i].fs,dim[i].sc)) + 1);
    }
    else ret=rec(i+1,carry);

    return ret;


}
int main(void)
{
    int val1,val2,ans;
    while(scanf("%d",&n)==1 && n)
    {
        mx=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&val1,&val2);
            dim[i]=mp(val1,val2);
            mx=max(mx,val2);
        }
//        mem(dp,-1);
        for(int i=0; i<=n; i++)
            for(int j=0; j<=mx*2; j++) dp[i][j]=-1;

        ans=rec(0,mx*2);

//        if(n==1) print1(1);
         print1(ans);

    }
    return 0;
}

