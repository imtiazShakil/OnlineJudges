#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>


#define pb push_back
#define MAX 10500

using namespace std;

int n;
map<int,int>M;
vector<int>v[MAX];
vector<int>S;

void dfs(int source)
{
//    if(M.find(source)!=M.end()) return ;
    M[source]=1;
    for(int i=0;i<(int)v[source].size();i++)
    {
        if(M.find(v[source][i] )==M.end() )
        {
            dfs(v[source][i]);
        }
    }
    return ;
}
int main(void)
{
    int loop,i,j,n,m,u,v1,count,cas=0;

    scanf("%d",&loop);
    while(loop--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<=n;i++) v[i].clear();
        M.clear();
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v1);
            v[u].pb(v1);
        }
        S.clear();

        for(i=1;i<=n;i++)
        {
            if(M.find(i)==M.end())
            {
                dfs(i);
                S.pb(i);
            }
        }
        M.clear();count=0;
        for(i=(int)S.size()-1;i>=0;i--)
        {
            if( M.find(S[i])==M.end() )
            {
                dfs(S[i]);count++;
            }
//            S.pop();
        }
        printf("Case %d: %d\n",++cas,count);
    }

    return 0;
}

