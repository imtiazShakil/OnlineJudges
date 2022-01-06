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

char mat[1005][1005];
int row_l[1005][1005],col_u[1005][1005];
int row_r[1005][1005],col_d[1005][1005];

int n,m;
vector< paii >v;
vector<string>dir;

bool bfs(int row,int col)
{
    int node,p,q,r,c;

    r=row;c=col;

    int lft,rght,up,dwn;

    for(int i=0;i<SZ(v);i++)
    {
//        print3("aa",r,c);

        lft=row_l[r][c];
        rght=row_r[r][c];
        up=col_u[r][c];
        dwn=col_d[r][c];

        if(dir[i]=="N" )
        {
            if( up+v[i].fs<=0 ) {return false;}
        }
        if(dir[i]=="S" )
        {
            if( dwn-v[i].fs<=0 ) {return false;}
        }
        if(dir[i]=="E" )
        {
            if( lft+v[i].sc<=0 ) {return false;}
        }
        if(dir[i]=="W" )
        {
            if( rght-v[i].sc<=0 ) { return false;}
        }

        p=r+v[i].fs;
        q=c+v[i].sc;

        if(mat[p][q]=='#' || p<0 || q<0 || p>n || q>m ) return false;

        r=p;
        c=q;

    }
    return true;
}
void gen()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]=='#') continue;
            row_l[i][j]=row_l[i][j-1]+ 1;
        }
//    puts("a");
    for(int i=0;i<n;i++)
        for(int j=m-1;j>=0;j--)
        {
            if(mat[i][j]=='#') continue;
            row_r[i][j]=row_r[i][j+1]+ 1;
        }
//    puts("b");

    for(int j=0;j<m;j++)
        for(int i=0;i<n;i++)
        {
            if(mat[i][j]=='#') continue;
            col_u[i][j]=col_u[i-1][j]+ 1;
        }
//    puts("c");
    for(int j=0;j<m;j++)
        for(int i=n-1;i>=0;i--)
        {
            if(mat[i][j]=='#') continue;
            col_d[i][j]=col_d[i+1][j]+ 1;
        }
    return ;
}
int main(void)
{
    int val1,val2,k;
    string str;
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++)
        scanf("%s",mat[i]);

    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        cin>>str>>val2;

//        scanf("%d %d",&val1,&val2);
//        for(int p=0;p<val2;p++)
        {
            dir.pb(str);
            if(str=="N") v.pb(mp(  -1*val2 ,0 ) );
            if(str=="S") v.pb (mp(  1*val2, 0 ) );
            if(str=="E") v.pb( mp(0,1*val2 ) );
            if(str=="W") v.pb( mp( 0 ,-1*val2 ) );
        }
    }

    str.clear();
    gen();

//    puts("completed");
//    if(bfs(2,6)) puts("shitt");

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(isalpha(mat[i][j]))
            {
                if( bfs(i,j) )
                {
//                    print3("  asdsad  ",i,j);
//                    print2("asdasd   ",mat[i][j]);
                    str+=mat[i][j];
//                    break;

                }
            }
        }
    sort(all(str));
    if( SZ(str) )print1(str);
    else puts("no solution");
    return 0;
}

