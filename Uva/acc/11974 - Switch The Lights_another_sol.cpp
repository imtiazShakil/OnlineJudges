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
#define MAX 110
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
int n,m;
int swtch[MAX];
int dp[ (1<<15) ];

int rec(int lights)
{
//    if( popc(lights) ==0) return 0;
    if(lights==0) return 0;
    int &ret=dp[lights];
//    if(ret!=-1 && ret==-2 ) return oo;
//    if(ret!=-1 && ret>=0 ) return ret;

//    ret=-2;
    if(ret!=-1) return ret;
    ret=oo;
//    int val=oo;

    for(int i=0;i<m;i++)
    {
        ret=min(ret,rec(lights^swtch[i]) +1 ) ;
    }
//    ret=val;
    return ret;
}
int main(void)
{
    int loop,val,ans;
    scanf("%d",&loop);
    for(int i=0;i<loop;i++)
    {
        scanf("%d %d",&n,&m);
        mem(swtch,0);
        for(int j=0;j<m;j++)
        {
//            swtch[j]=0;
            for(int k=0;k<n;k++)
            {
                scanf("%d",&val);
                swtch[j]= swtch[j]|(val<<k);
//                swtch[j]=swtch[j]*10+ val;
//                scanf("%d",&swtch[j][k]);
            }
        }
        mem(dp,-1);
        ans=rec( (1<<n) -1);
//        cout<<ans<<endl;
        if(ans>=oo) printf("Case %d: IMPOSSIBLE\n",i+1);
        else printf("Case %d: %d\n",i+1,ans);
    }


    return 0;
}


