/*
ID: shakil1
PROG: cowtour
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

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

vector<paii>pt;

char mat[MAX][MAX];
int par[MAX],n;
int rank[MAX];

int dt[MAX][MAX];
//double djk_dt[MAX];
double flyd_dt[MAX][MAX];
double set_d[MAX];
double mx_dt[MAX];

vector<paii>valid_connc;

struct vertice
{
    int node;
    double dist;
    bool operator<(const vertice & x)const
    {
        return dist>x.dist;
    }
} ;

struct path
{
    int frm,to;
    double dst;
};

vector<path>lnks;

//bool relax(int u,int v,double w)
//{
//    if(djk_dt[v]>djk_dt[u] + w )  {djk_dt[v]=djk_dt[u] + w;return true;}
//    return false;
//}

double sqrt_dst(paii a, paii b)
{
    return  sqrt((double)((a.fs-b.fs)*(a.fs-b.fs)) + (double)( (a.sc-b.sc)*(a.sc-b.sc) ) );
}
int dist(paii a, paii b)
{
    return ( (a.fs-b.fs)*(a.fs-b.fs) + (a.sc-b.sc)*(a.sc-b.sc) );
}
bool com(path a , path b)
{
    return a.dst<b.dst;
}
double min_d(double a,double b)
{
    if(a<b) return a;
    else return b;
}
double max_d(double a, double b)
{
    if(a>b) return a;
    else return b;
}
void make_set(int x)
{
    par[x]=x;
    rank[x]=0;
    return ;
}
int find_set(int x)
{
    if(x!=par[x]) par[x]=find_set(par[x]);
    return par[x];
}
void link(int x,int y)
{
    if(rank[x]>rank[y])
        par[y]=x;
    else par[x]=y;

    if(rank[x]==rank[y])
        rank[y]++;
    return ;
}
void u_nion(int x,int y)
{
    link(find_set(x),find_set(y));
    return ;
}

void  set_conn(void)
{
    int p;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if( find_set(i)==find_set(j) )
            {
                p=find_set(i);
                set_d[p]=max_d(set_d[p],flyd_dt[i][j]);
                mx_dt[i]=max(mx_dt[i],flyd_dt[i][j]);
            }
        }

}

//void dijkstra(int source)
//{
//    map<int,bool>M;
//    priority_queue<vertice>Q;
//
//    vertice tmp,tmp2;
//    tmp.node=source;
//    tmp.dist=0.;
//
//    for(int i=0;i<n;i++) djk_dt[i]=oo;
//    djk_dt[source]=0.0;
//
//    Q.push(tmp);
//    double ddd;
//    while(!Q.empty())
//    {
//        tmp=Q.top();Q.pop();
//        if(M.find(tmp.node)!=M.end()) continue;
//        M[tmp.node]=1;
////        print3("popped ",tmp.node,tmp.dist);
//        for(int i=0;i<n;i++)
//        {
//            if(mat[tmp.node][i]=='1' && tmp.node!=i )
//            {
//                ddd=sqrt_dst(pt[tmp.node],pt[i]);
//                if(relax(tmp.node,i,ddd ) )
//                {
//                    tmp2.node=i;
//                    tmp2.dist=djk_dt[i] ;
//                    Q.push(tmp2);
////                    djk_dt[i]=ddd;
//                }
//            }
//        }
//    }
//
//}

void floyd_warshall()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i==j) flyd_dt[i][j]=0.0;
            else if(mat[i][j]=='1')
            {
                flyd_dt[i][j]=sqrt_dst(pt[i],pt[j]);
            }
            else flyd_dt[i][j]=(double)oo;
        }

    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                flyd_dt[i][j]=min_d(flyd_dt[i][k] + flyd_dt[k][j] , flyd_dt[i][j] );
            }
        }

     return ;
}
int main(void)
{
    freopen("cowtour.in","r",stdin);
    freopen("cowtour.out","w+",stdout);

    string str;
    int p1,p2,d;
    path tmp;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {scanf("%d %d",&p1,&p2);pt.pb(mp(p1,p2)); }

    for(int i=0;i<n;i++) make_set(i);

    for(int i=0;i<n;i++)
    {
        scanf("%s",mat[i]);
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]=='1') u_nion( i,j);
        }
    }

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            if(i!=j && find_set(i)!=find_set(j) )
            {
                tmp.frm=i;tmp.to=j;tmp.dst=sqrt_dst( pt[i],pt[j]);
                lnks.pb(tmp);
            }
        }

    floyd_warshall();
    set_conn();

    double tot_d=(double)oo;
    double ddd;

    for(int i=0;i<SZ(lnks);i++)
    {
        ddd=0.0;
        ddd=max(set_d[ find_set( lnks[i].to) ] ,set_d[ find_set(lnks[i].frm) ] );
        ddd=max(ddd,mx_dt[ lnks[i].frm ] + mx_dt[ lnks[i].to ] + lnks[i].dst);
        tot_d=min_d( tot_d,ddd );
    }

    printf("%.6lf\n",tot_d);

    return 0;
}
