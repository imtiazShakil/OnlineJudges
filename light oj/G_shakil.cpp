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
#define MAX 250005
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
vector<int>itm;

int dp[55][MAX];

int rec(int indx,int sum)
{
//    if(sum>MAX) return -1*(oo);
//    print2(indx,sum);
//    if(indx && sum==0) return 0;
    if(indx==n && sum==0) return 0;  //{print1("ret 0");return 0;}
    if(indx==n && sum)   return -1*(oo); //{print1("ret -1oo");return -1*(oo);}

    int &ret=dp[indx][sum];
    if(ret!=-1) return ret;
    ret=0;
    ret= itm[indx]+ rec(indx+1,sum+ itm[indx] );
    ret=max(ret,rec(indx+1,sum));
    ret=max(ret,rec(indx+1,sum-itm[indx]) );

    return ret;
}
int main(void)
{
    int cas,val,ans;
    scanf("%d",&cas);
    for(int i=0;i<cas;i++)
    {
        itm.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&val);
            itm.pb(val);
        }


        mem(dp,-1);
        ans=rec(0,0);
        if(ans) printf("Case %d: %d\n",i+1,ans);
        else printf("Case %d: impossible\n",i+1);

    }
    return 0;
}

