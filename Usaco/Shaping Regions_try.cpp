/*
ID: shakil1
PROG: rect1
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
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second
#define MAX 60

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

set<int>x;
set<int>y;
int mx_col;

struct rct
{
    int lx,ly,ux,uy,c;
    rct( int a,int b,int cc,int d,int e)
    {
        lx=a;ly=b;ux=cc;uy=d;c=e;
    }
};

vector<rct>v;

int col[2600];

void sol(void)
{

    for(set<int>::iterator i=x.begin(),p=++x.begin() ;p!=x.end();i++,p++)
    {
        for( set<int>::iterator j=y.begin(),q=++y.begin();q!=y.end();j++,q++ )
        {
            for(  int t=SZ(v)-1;t>=0;t-- )
            {
                if( v[t].lx<= *i && v[t].ly<=*j && v[t].ux>= *p && v[t].uy>=*q )
                {
                    col[ v[t].c]+= ( (*p - *i) * ( *q - *j) ) ;
//                    printf("%d %d %d %d col %d area %d \n",*i,*j,*p,*q ,v[t].c , ( (*p - *i) * ( *q - *j) ) );
                    break;
                }
            }
        }
    }

    for(int i=1;i<=mx_col;i++)
    {
        if(col[i]) print2(i,col[i]);
    }
}
int main(void)
{
    freopen("rect1.in","r",stdin);
    freopen("rect1.out","w+",stdout);
    int a,b,n;
    int lx,ly,ux,uy,c;
    mx_col=0;
    scanf("%d %d %d",&a,&b,&n);

    x.insert(0);x.insert(a);
    y.insert(0);y.insert(b);

    v.pb(rct(0,0,a,b,1) );

    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d %d",&lx,&ly,&ux,&uy,&c);
        v.pb( rct(lx,ly,ux,uy,c) );

        mx_col=max(mx_col,c);
        x.insert(lx);x.insert(ux);
        y.insert(ly);y.insert(uy);
    }

    sol();



    return 0;
}

