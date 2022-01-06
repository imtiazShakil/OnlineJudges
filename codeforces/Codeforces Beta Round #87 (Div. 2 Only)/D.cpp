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

vector<string>v;

int dp[155][155][2];
int tot;

int rec(int row,int col,bool dir,int weed,int par_r,int par_col)
{
//    cout<<"call "<<row<<" "<<col<<" dir "<<dir<<" "<<" weed "<<weed<<endl;

    if(row==SZ(v) && weed==tot) return 0;
    if(row<0 || row>=SZ(v) || col<0 || col >=SZ(v[0]) ) return oo;
    if(row>=SZ(v) && weed!=tot) return oo;


    int &ret=dp[row][col][dir];
    if(ret!=-1) return ret;

    int fl=0;
    if(v[row][col]=='W') fl=1;

    ret=oo;
    if(dir==0)
    {
        if( col+1<SZ(v[row]) )
        {
            ret=min(ret,rec(row,col+1,dir,weed+fl) + 1);
        }
        if(row+1 <= SZ(v) )
        {
            ret=min(ret,rec(row+1,col,!dir,weed+fl) + 1);
        }
    }
    else if(dir)
    {
        if( col-1>=0 )
        {
            ret=min(ret,rec(row,col-1,dir,weed+fl) + 1);
        }
        if(row+1 <= SZ(v) )
        {
            ret=min(ret,rec(row+1,col,!dir,weed+fl) + 1);
        }
    }
//    cout<<row<<" "<<col<<" dir "<<dir<<" "<<" ret "<<ret<<endl;

    return ret;
}

int main(void)
{
    int n,m;
    scanf("%d %d",&n,&m);
    string str;
    for(int i=0;i<n;i++) {cin>>str;v.pb(str);}

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(v[i][j]=='W') tot++;
        }
    print2("weed ",tot);

    mem(dp,-1);
    int ans=rec(0,0,0,0);
    print1(ans);

    return 0;
}

