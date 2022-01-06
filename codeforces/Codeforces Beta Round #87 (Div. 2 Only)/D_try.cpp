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

bool move(int row,int col,int dir)
{
    int weed=0;
    if(dir==0)
    {
        for(int i=row,j=col+1;j<SZ(v[row]) ;j++)
        {
            if(v[i][j]=='W') weed++;
        }
    }
    if(dir==1)
    {
        for(int i=row,j=col-1;j>=0;j--)
        {
            if(v[i][j]=='W') weed++;
        }
    }
    if(weed) return 1;
    else return 0;

}

int go(int row,int col)
{
    int dir=0;
    int stp=0;
    while(row<SZ(v))
    {
        cout<<row<<" "<<col<<" "<<stp<<endl;
        if( move(row,col,dir) )
        {
            if( dir==0) col++;
            if(dir==1) col--;
        }
        else
        {
            row++;dir=!dir;
        }
        stp++;
    }
    return stp;
}
int main(void)
{
    int n,m;
    string str;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        cin>>str;
        v.pb(str);
    }
    int ans=go(0,0);
    print1(ans);
    return 0;
}

