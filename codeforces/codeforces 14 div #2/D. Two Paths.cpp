#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

#define MAX 300
#define pb push_back
#define mp make_pair
using namespace std;

vector<int>v[MAX];

struct path
{
    int u,v;
};
vector<path>pt;
map<int,int>M;
int dist[MAX],mx_nd,mx_dst;
map<pair<int,int>,int>M_p;

void dfs(int source)
{
    M[source]=1;
    for(int i=0;i<(int)v[source].size();i++)
    {
        if( M.find(v[source][i])==M.end()  && M_p.find(  mp( min(source,v[source][i]) , max(source,v[source][i]) ) )==M_p.end()   )
        {
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
    int n,i,u,v1,tot,l1,l2;
    path tmp;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<=n;i++) v[i].clear();
        pt.clear();

        for(i=0;i<n-1;i++)
        {
            scanf("%d %d",&u,&v1);
            v[u].pb(v1);
            v[v1].pb(u);
            tmp.u=u;
            tmp.v=v1;
            pt.pb(tmp);
        }
        for(i=0,tot=0;i<n-1;i++)
        {
            M_p.clear();
            M_p[ mp( min(pt[i].u,pt[i].v), max( pt[i].u,pt[i].v )  ) ]=1;

            pair<int,int>p=mp( min(pt[i].u,pt[i].v), max( pt[i].u,pt[i].v ) );
//            cout<<p.first<<" <-> "<<p.second<<endl;


            for(int p=0;p<=n;p++) dist[p]=0;
            M.clear();mx_dst=0;mx_nd=0;
            dfs(pt[i].u);

//            puts("paisis");

            for(int p=0;p<=n;p++) dist[p]=0;
            M.clear();mx_dst=0;
            dfs(mx_nd);
            l1=mx_dst;
//            cout<<"l1 "<<l1<<endl;
//            puts("paisis2");

            mx_dst=0;for(int p=0;p<=n;p++) dist[p]=0;M.clear();mx_nd=0;
            dfs(pt[i].v);

//            puts("paisis3");

            for(int p=0;p<=n;p++) dist[p]=0;
            M.clear();mx_dst=0;
            dfs(mx_nd);
            l2=mx_dst;
//            cout<<"l2 "<<l2<<endl;

//            puts("paisis4");

            tot=max(tot,l1*l2);
        }
        cout<<tot<<endl;
    }

    return 0;
}
