#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>

#define pb push_back
#define MAX 100010
#define mem(a,b) memset(a,b,sizeof a)

using namespace std;

int n;
bool col[MAX];
//map<int,int>M;
vector<int>v[MAX];
vector<int>S;

void dfs(int source)
{
//    if(M.find(source)!=M.end()) return ;
//    col[source]=1;
    for(int i=0;i<(int)v[source].size();i++)
    {
//        if(M.find(v[source][i] )==M.end() )
        if(col[v[source][i]]==0 )
        {
            col[v[source][i]]=1;
            dfs(v[source][i]);
        }
    }
    return ;
}

int main(void)
{
    int loop,i,j,n,m,u,v1,count;

    scanf("%d",&loop);
    while(loop--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<=n;i++) v[i].clear();
//        M.clear();
//        for(i=0;i<=n;i++) col[i]=0;
        memset(col, false, sizeof col);

        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v1);
            v[u].pb(v1);
        }
        S.clear();

        for(i=1;i<=n;i++)
        {
//            if(M.find(i)==M.end())
            if(col[i]==0)
            {
                col[i]=1;
                dfs(i);
                S.pb(i);
            }
        }
//        M.clear();
//        for(i=0;i<=n;i++) col[i]=0;
        memset(col, false, sizeof col);
        count=0;
        for(i=(int)S.size()-1;i>=0;i--)
        {
//            if( M.find(S[i])==M.end() )
            if(col[S[i]]==0)
            {
                col[S[i]]=1;
                dfs(S[i]);count++;
            }
//            S.pop();
        }
        printf("%d\n",count);
    }

    return 0;
}
