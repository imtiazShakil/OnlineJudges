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

double  dp[105][105];

double rec(int cube,int sum)
{
//    print2(cube,sum);
    if(cube && sum<=0) return 0.0;
    if(cube==0 && sum==0) return 1.0;
    if(cube==0 && sum ) return 0.0;

    double &ret=dp[cube][sum];
    if(ret!=-1.0) return ret;
    ret=0.0;
    for(int i=1;i<=6;i++) ret+=rec(cube-1,sum-i);
    ret=ret/6.0;
    return ret;

}
int main(void)
{
    int cas,n,m;
    double ans;
    scanf("%d",&cas);
    while(cas--)
    {
        for(int i=0;i<105;i++)
            for(int j=0;j<105;j++) dp[i][j]=-1.0;

        scanf("%d %d",&n,&m);
        ans=rec(n,m);
        printf("%.2lf\n",ans);
    }

    return 0;
}

