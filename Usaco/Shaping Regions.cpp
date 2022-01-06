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
#define MAX 2005
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

map<int,int>M_r;
map<int,int>M_c;
char mat[MAX][MAX];

map<int,bool>M1;
map<int,bool>M2;
int a,b;
int color[2505];

struct rct
{
    paii cord;
    paii cord2;
    int col;
};
vector<rct>pt;

void do_col(int r1,int r2,int c1,int c2,int col)
{

    for(int i=M_c[c1];i<M_c[c2];i++ )
        for(int j=M_r[r1];j<M_r[r2];j++ )
        {
            mat[i][j]=col;
        }
    return ;
}

void grid_compress(void)
{
    vector<int>row;
    vector<int>col;

    int indx=0;
    for(map<int,bool>::iterator it=M1.begin();it!=M1.end();it++)
    {
        M_r[it->fs]=indx++;
        row.pb(it->fs);
    }
    indx=0;
    for(map<int,bool>::iterator it=M2.begin();it!=M2.end();it++)
    {
        M_c[it->fs]=indx++;
        col.pb(it->fs);
    }

//    for(map<int,int>::iterator it=M_r.begin();it!=M_r.end();it++) print2(it->fs,it->sc);
//    for(map<int,int>::iterator it=M_c.begin();it!=M_c.end();it++) print2(it->fs,it->sc);

    for(int i=0;i<=M_c[b];i++)
        for(int j=0;j<=M_r[a];j++) mat[i][j]=1;

    for(int i=0;i<SZ(pt);i++)
    {
        do_col(pt[i].cord.fs,pt[i].cord2.fs,pt[i].cord.sc,pt[i].cord2.sc,pt[i].col);
    }

//    for(int i=0;i<=M_c[b];i++,puts(""))
//        for(int j=0;j<=M_r[a];j++) printf("%d",mat[i][j]);
//        puts("");

//    for(int i=0;i<SZ(col);i++) print2("row ",col[i]);
//    for(int i=0;i<SZ(row);i++) print2("col ",row[i]);

    for(int i=0;i<SZ(col)-1;i++)
        for(int j=0;j<SZ(row)-1;j++)
        {
            color[ mat[M_c[col[i]] ][ M_r[row[j]] ] ] += ( (row[j+1]-row[j]) * (col[i+1]-col[i]) ) ;
        }



     return ;
}
int main(void)
{
    freopen("rect1.in","r",stdin);
    freopen("rect1.out","w+",stdout);
    int n,mx=1;
    rct tmp;
    scanf("%d %d %d",&a,&b,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d %d",&tmp.cord.fs,&tmp.cord.sc,&tmp.cord2.fs,&tmp.cord2.sc,&tmp.col);
        M1[tmp.cord.fs]=1;M1[tmp.cord2.fs]=1;M2[tmp.cord.sc]=1;M2[tmp.cord2.sc]=1;
        pt.pb(tmp);
        mx=max(mx,tmp.col);
    }
    M1[a]=1;M1[0]=1;M2[b]=1;M2[0]=1;
//    M1[a+1]=1;M2[b+1]=1;


//    print1(SZ(M1));
//    print1(SZ(M2));


    grid_compress();

    for(int i=1;i<=mx;i++)
    {
        if(color[i]) print2(i,color[i]);
    }
    return 0;
}

