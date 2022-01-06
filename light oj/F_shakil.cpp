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
int n;
struct vertice
{
    int node;
    int cost,fuel;

    bool operator<(const vertice & x)const
    {
        return cost>x.cost;
    }
} ;

struct path
{
    int to,dst;
} ;

vector<path>v[MAX];
int fuel_cost[MAX];
int cost[MAX][MAX];

bool relax(int u,int f,int v1,int w)
{
    if(cost[u][f] < cost[v1][ f-w] )
    {
        cost[v1][f-w]=cost[u][f];
        return true;
    }
    return false;
}

void dijkstra(int source,int cap)
{
    priority_queue<vertice>Q;
    vertice tmp,tmp2;
    for(int i=0;i<n;i++)
        for(int j=0;j<=cap;j++) cost[i][j]=oo;
    for(int i=0;i<=cap;i++) cost[source][i]=i*fuel_cost[source];
//    cost[source]=0;
    tmp.node=source;
    tmp.fuel=0;
    tmp2.node=source;
//    Q.push(tmp);
    int mn;
    for(int i=0;i<SZ( v[ source] );i++ )
    {
        mn=max(v[source][i].dst-tmp.fuel,0);
        for(int j=mn;j+tmp.fuel <=cap;j++)
        {
            tmp2.fuel=tmp.fuel+ j;
            tmp2.cost=j*fuel_cost[source];
            Q.push(tmp2);
        }
    }
    map<paii,int>M;
    map<int,int>M2;

    int u,f;
    while(!Q.empty())
    {
        tmp=Q.top();Q.pop();
        u=tmp.node;f=tmp.fuel;
//        if(M2.find(u)!=M2.end()) continue;
        if(M.find(mp(u,f))!=M.end()) continue;
        M[ mp(u,f) ]=1;
        M2[u]=1;

        print3(u,f,tmp.cost);

        for(int i=0;i<SZ(v[u]);i++ )
        {
//            if( M2.find(v[u][i].to)!=M2.end() ) continue;
            if(M2.find( v[u][i].to )!=M2.end() ) continue;
            if(f>=v[u][i].dst )
            {
                print3("go to ",v[u][i].to,v[u][i].dst);
                if( relax(u,f,v[u][i].to,v[u][i].dst  ) )
                {
                    tmp2.cost=cost[ v[u][i].to ][ f-v[u][i].dst  ];
                    tmp2.node=v[u][i].to;
                    tmp2.fuel=f-v[u][i].dst;
                    if( M.find( mp(tmp2.node,tmp2.fuel)  )==M.end() ) {Q.push(tmp2);printf("insert1 ");print3(tmp2.node,tmp2.fuel,tmp2.cost);}
//                    M[mp(tmp2.node,tmp2.fuel)]=1;
                }
            }
            else
            {
                mn=max(v[u][i].dst-f,0);
                print3("couldn't go to",v[u][i].to,v[u][i].dst);
                for(int i=mn;f+i<=cap && M.find(mp(u,f+i))==M.end() ;i++)
                {
                    tmp2.node=u;
                    tmp2.cost=tmp.cost+i*fuel_cost[u];
                    tmp2.fuel=f+i;
                    Q.push(tmp2);
//                    M[mp(u,f+i)]=1;
                    printf("insert2 ");print3(tmp2.node,tmp2.fuel,tmp2.cost);
                }
            }
        }
    }

}
int main(void)
{
    path tmp;
    int cas,m,v1,v2,query,cap,ans;
    scanf("%d",&cas);
    for(int i=1;i<=cas;i++)
    {
        scanf("%d %d",&n,&m);
//        fuel_cost.clear();
        for(int j=0;j<n;j++) scanf("%d",&fuel_cost[j]);
        for(int j=0;j<n;j++) v[j].clear();
        for(int j=0;j<m;j++)
        {
            scanf("%d %d %d",&v1,&v2,&tmp.dst);
            tmp.to=v2;
            v[v1].pb(tmp);
            tmp.to=v1;
            v[v2].pb(tmp);
        }
        scanf("%d",&query);
        for(int j=0;j<query;j++)
        {
            scanf("%d %d %d",&cap,&v1,&v2);
            dijkstra(v1,cap);
            ans=cost[v2][0];
            if(ans>=oo) print1("inf ");
            else print1(ans);
        }
    }
    return 0;
}

