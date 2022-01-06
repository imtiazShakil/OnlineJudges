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
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<endl
#define PI (2*acos(0))
#define ERR 1e-5
#define ll long long
#define VI vector<int>
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x.begin(),x.end())
#define mp make_pair
#define MAX 1010
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1LL<<50)


using namespace std;

ll dist[MAX],n,cost[MAX];

struct vertice
{
    ll node;
    ll dist;

    bool operator<(const vertice & x)const
    {
        return dist>x.dist;
    }
} ;

struct edge
{
    ll v;
    ll weight;
} ;
vector<edge>road[MAX];

bool relax(ll u,ll v,ll w)
{
    if(dist[v]>dist[u] + w)  {dist[v]=dist[u] + w;return true;}
    return false;
}

bool relax_cost(ll u,ll v,ll w)
{
    if(cost[v]>cost[u] + w)  {cost[v]=cost[u] + w;return true;}
    return false;
}


void dijkstra_short_path(ll source)
{
    priority_queue<vertice>Q;
    map<ll,bool>M;
    for(int i=1;i<=n;i++) dist[i]=oo;
    dist[source]=0;

    vertice tmp,tmp2;tmp.node=source;tmp.dist=0;
    Q.push(tmp);
    while(!Q.empty())
    {
        tmp=Q.top();Q.pop();
        if(M.find(tmp.node)==M.end())
        {
            M[tmp.node]=1;
            for(int i=0;i<SZ(road[tmp.node]);i++)
            {
                if(relax(tmp.node,road[tmp.node][i].v,road[tmp.node][i].weight ))
                {
                    tmp2.node=road[tmp.node][i].v;
                    tmp2.dist=dist[road[tmp.node][i].v];
                    Q.push(tmp2);
                }
            }
        }
    }


}

struct taxy
{
    ll tm, cost;
};
vector<taxy>drv;

struct pt4taxy
{
    ll v, cost;
};
vector<pt4taxy>cab[MAX];

struct junc_cost
{
    ll node, cost;

    bool operator<(const junc_cost & x)const
    {
        return cost>x.cost;
    }
} ;

void dijkstra_short_cost(ll source)
{
    priority_queue<junc_cost>Q;
    map<ll,bool>M;
    junc_cost tmp,tmp2;
    for(int i=1;i<=n;i++) cost[i]=oo;
    cost[source]=0;
    tmp.cost=0;tmp.node=source;Q.push(tmp);
    while(!Q.empty())
    {
        tmp=Q.top();Q.pop();
        if(M.find(tmp.node)==M.end())
        {
            M[tmp.node]=1;
            for(int i=0;i<SZ(cab[tmp.node]);i++ )
            {
                if(relax_cost(tmp.node,cab[tmp.node][i].v,cab[tmp.node][i].cost ))
                {
                    tmp2.cost=cost[cab[tmp.node][i].v];
                    tmp2.node=cab[tmp.node][i].v;
                    Q.push(tmp2);
                }
            }
        }
    }

}

int main(void)
{
    ll m,x,y,u,v,w;
    edge tmp;
    taxy tmp2;

//    scanf("%d %d",&n,&m);
//    scanf("%d %d",&x,&y);
    cin>>n>>m>>x>>y;
    for(int i=0;i<m;i++) {/*scanf("%d %d %d",&u,&v,&w);*/cin>>u>>v>>w;tmp.v=v;tmp.weight=w;road[u].pb(tmp); tmp.v=u;road[v].pb(tmp);}

    for(int i=0;i<n;i++)
    {
//        scanf("%d %d",&u,&v);
        cin>>u>>v;
        tmp2.tm=u;tmp2.cost=v;
        drv.pb(tmp2);
    }


    dijkstra_short_path(x);
    if(dist[y]>=oo) {puts("-1");return 0;}

    pt4taxy tmp3;
    for(int i=1;i<=n;i++)
    {
        dijkstra_short_path(i);
        for(int j=1;j<=n;j++)
        {
            if(i!=j && dist[j]<=drv[i-1].tm )
            {
                tmp3.cost=drv[i-1].cost;
                tmp3.v=j;cab[i].pb(tmp3);
//                tmp3.v=i;cab[j].pb(tmp3);
            }
        }
    }
    dijkstra_short_cost(x);
    if(cost[y]>=oo) {puts("-1");return 0;}
    else cout<<cost[y]<<endl;
    return 0;
}

