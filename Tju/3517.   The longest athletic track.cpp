#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <map>

#define MAX 2500
#define pb push_back

using namespace std;

struct path
{
    int to;
    int weight;
};

map<int,int>M;
vector<path>v[MAX];
int dist[MAX],mx_nd,mx_dst;;

void dfs(int source)
{
    M[source]=1;
    for(int i=0;i<(int)v[source].size();i++)
    {
        if(M.find(v[source][i].to)==M.end() )
        {
            dist[v[source][i].to]=dist[source]+v[source][i].weight;
            if(mx_dst<dist[v[source][i].to])
            {
                mx_dst=dist[v[source][i].to];
                mx_nd=v[source][i].to;
            }
            dfs(v[source][i].to);
        }
    }
    return ;
}

int main(void)
{
    int loop,n,i,u,v1,w;
    path tmp;
    scanf("%d",&loop);
    while(loop--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++) v[i].clear();

        for(i=0;i<n-1;i++)
        {
            scanf("%d %d %d",&u,&v1,&w);
            tmp.weight=w;tmp.to=v1;
            v[u].pb(tmp);tmp.to=u;
            v[v1].pb(tmp);
        }
        M.clear();mx_dst=0;
        for(i=1;i<=n;i++) dist[i]=0;
        dfs(u);

        mx_dst=0;M.clear();
        for(i=1;i<=n;i++) dist[i]=0;
        dfs(mx_nd);
        printf("%d\n",mx_dst);

    }

    return 0;
}
