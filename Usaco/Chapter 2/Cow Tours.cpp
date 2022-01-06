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
double djk_dt[MAX];

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
    int dst;
};

vector<path>lnks;

bool relax(int u,int v,double w)
{
    if(djk_dt[v]>djk_dt[u] + w )  {djk_dt[v]=djk_dt[u] + w;return true;}
    return false;
}

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

void  find_conn(void)
{
//    double cost=0.;

//    for(int i=0;i<=n;i++) make_set(i);

    int mn_d=lnks[0].dst;

    for(int i=0;i<SZ(lnks);i++)
    {
        if(lnks[i].dst==mn_d)
        {
            valid_connc.pb( mp( lnks[i].frm,lnks[i].to) );
        }
        else break;

//        if(find_set( lnks[i].frm )!=find_set(lnks[i].to) )
//        {
//            u_nion(lnks[i].frm,lnks[i].to);
//            mat[lnks[i].frm][lnks[i].to]='1';
//            mat[lnks[i].to][lnks[i].frm]='1';
//            print3("made connection ",lnks[i].frm,lnks[i].to);
//            break;
////            cost+=v[i].dst;
//        }
    }
//    return cost;
}

void dijkstra(int source)
{
    map<int,bool>M;
    priority_queue<vertice>Q;

    vertice tmp,tmp2;
    tmp.node=source;
    tmp.dist=0.;

    for(int i=0;i<n;i++) djk_dt[i]=oo;
    djk_dt[source]=0.0;

    Q.push(tmp);
    double ddd;
    while(!Q.empty())
    {
        tmp=Q.top();Q.pop();
        if(M.find(tmp.node)!=M.end()) continue;
        M[tmp.node]=1;
//        print3("popped ",tmp.node,tmp.dist);
        for(int i=0;i<n;i++)
        {
            if(mat[tmp.node][i]=='1' && tmp.node!=i )
            {
                ddd=sqrt_dst(pt[tmp.node],pt[i]);
                if(relax(tmp.node,i,ddd ) )
                {
                    tmp2.node=i;
                    tmp2.dist=djk_dt[i] ;
                    Q.push(tmp2);
//                    djk_dt[i]=ddd;
                }
            }
        }
    }

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
        for(int j=0;j<n;j++)
        {
            if(i!=j && find_set(i)!=find_set(j) )
            {
                tmp.frm=i;tmp.to=j;tmp.dst=dist( pt[i],pt[j]);
                lnks.pb(tmp);
            }
        }

    sort(all(lnks),com);

    double mx_ddd=0.;
    double tot_mx_dd=(double)oo;
    int furthest_nd;

    find_conn();

    for(int i=0;i<SZ( valid_connc );i++ )
    {
        mat[ valid_connc[i].fs ][ valid_connc[i].sc ]='1';
        mat[ valid_connc[i].sc ][ valid_connc[i].fs ]='1';



//        dijkstra(0);
        dijkstra(valid_connc[i].fs);

//    for(int i=0;i<n;i++) print3(i,pt[i].fs,pt[i].sc);
        mx_ddd=0.;
        for(int i=0;i<n;i++)
        {
            if( djk_dt[i]>mx_ddd && djk_dt[i]<(double)oo )
            {
                mx_ddd=djk_dt[i];
                furthest_nd=i;
            }
        }

    //    print3("furthet node ",furthest_nd,mx_ddd);

        dijkstra(furthest_nd);

        mx_ddd=0.;

        for(int i=0;i<n;i++)
        {
            if( mx_ddd<djk_dt[i] && djk_dt[i]<(double)oo ) mx_ddd=djk_dt[i];
//            mx_ddd=max(mx_ddd,djk_dt[i]);
        }

        tot_mx_dd=min(tot_mx_dd,mx_ddd);


        mat[ valid_connc[i].fs ][ valid_connc[i].sc ]='0';
        mat[ valid_connc[i].sc ][ valid_connc[i].fs ]='0';
    }

    printf("%.6lf\n",tot_mx_dd);



    return 0;
}
