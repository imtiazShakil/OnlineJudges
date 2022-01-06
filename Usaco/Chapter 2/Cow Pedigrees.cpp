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
#define mod 9901
///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

int dp[MAX][MAX];
int h;

int rec(int node,int height)
{
//    print2(node,height);

    if(node>1 && height>=h ) return -1;//{puts("ret -1");return -1;}
//    if(node & height>h) {puts("ret -1");return -1;}
    if(node==0) return -1;//{puts("ret -1");return -1;}
    if(node==1 && height==h ) return 1;//{puts("ret 1");return 1;}
    if(node==1 && height<h) return 0;//{puts("ret 0");return 0;}

    int &ret=dp[node][height];
    if(ret!=-2) return ret;

    ret=0;
    int val,val2;
    bool flag=0;
    for(int i=1;i<node-1;i++)
    {
//        if(i==node-1-i) val=rec(i,height+1);
//        else  val=rec(i,height+1) + rec(node-1 - i,height+1);

        val=rec(i,height+1) ;
        val2=rec(node-1 - i,height+1);

        if( val>0 & val2>0 ) {ret+= (val*val2);flag=1;}
        else if(val>=0  && val2>=0 )
        {
            ret+=( val +  val2 ) ;
            flag=1;
        }

        ret%=mod;
    }

    if(!flag) ret=-1;
//    print3(node,height,ret);

    if(!flag) return -1;
    return ret%mod;

}
int main(void)
{
    freopen("nocows.in","r",stdin);
    freopen("nocows.out","w+",stdout);
    int n;
    scanf("%d %d",&n,&h);
//    mem(dp,-2);

    for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) dp[i][j]=-2;

    int ans=rec(n,1);
    print1(ans);

    return 0;
}
