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
#define MAX 120
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
int row,col;
//vector<string>v;
int v[MAX][MAX];

int dp[MAX][MAX][MAX*2];

int rec(int r1,int r2,int stp)
{
    int c1=abs(r1-stp),c2=abs(r2-stp);
//    if(stp==(row-1)+(col-1) + 1) return 0;
    if(  ( (r1==row && c1==col-1) || (r1==row-1 && c1==col) ) &&  ( (r2==row && c2==col-1) || (r2==row-1 && c2==col) )  ) return 0;
    if( (r1>=row && c1<col-1 ) || (r2>=row && c2<col-1) || (r1<row-1 && c1>=col) || (r2<row-1 && c2>=col) ) return -1*(oo);

    int &ret=dp[r1][r2][stp];
    if(ret!=-1) return ret;
    ret=0;
    int cnt=0;

    cnt=v[r1][c1];
    if(r1!=r2 || c1!=c2) cnt+=v[r2][c2];

//    if(v[r2][c2]==1) cnt++;
//    if( r1==r2 && c1==c2 && cnt ) cnt--;

    ret=max( ret,rec(r1,r2,stp+1) + cnt );
    ret=max( ret,rec(r1,r2+1,stp+1) + cnt );
    ret=max( ret,rec(r1+1,r2,stp+1) + cnt );
    ret=max( ret,rec(r1+1,r2+1,stp+1) + cnt );

    return ret;
}
int main(void)
{
//    string str;
    int cas,ans;
    scanf("%d",&cas);
    for(int i=0;i<cas;i++)
    {
//        v.clear();
        scanf("%d %d",&row,&col);
        for(int p=0;p<row;p++)
            for(int q=0;q<col;q++) scanf("%d",&v[p][q]);
//        {
//            cin>>str;
//            v.pb(str);
//        }
        mem(dp,-1);
        ans=rec(0,0,0);
        printf("Case %d: %d\n",i+1,ans);

    }
    return 0;
}

