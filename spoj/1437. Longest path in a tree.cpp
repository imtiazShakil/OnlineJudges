#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <map>

#define MAX 10500
#define pb push_back

using namespace std;

vector<int>v[MAX];
int n,mx_nd,mx_dst;

int dist[MAX];
map<int,int>M;

void dfs(int source)
{
//    cout<<source<<endl;
    M[source]=1;
    for(int i=0;i<(int)v[source].size();i++)
    {
        if( M.find(v[source][i])==M.end() )
        {
//                M[v[source][i]]=1;
            dist[v[source][i]]=dist[source] + 1;
            if( mx_dst<dist[v[source][i]] )
            {
                mx_dst=dist[v[source][i]];
                mx_nd=v[source][i];
            }
            dfs(v[source][i]);
        }
    }

    return ;
}
int main(void)
{
    int i,j,u,v1;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<=n;i++) v[i].clear();
        M.clear();

        for(i=0;i<n-1;i++)
        {
            scanf("%d %d",&u,&v1);
            v[u].pb(v1);
            v[v1].pb(u);
        }
//        puts("paissi");
        for(i=0;i<=n;i++) dist[i]=0;
        mx_dst=0;
        dfs(u);

        M.clear();
        for(i=0;i<=n;i++) dist[i]=0;
        dfs(mx_nd);
        printf("%d\n",mx_dst);
    }
    return 0;
}
