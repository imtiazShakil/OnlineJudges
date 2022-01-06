#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

#define mem(a,b) memset(a,b,sizeof a)
#define MAX 55
#define pb push_back
using namespace std;

int mat[MAX][MAX],n;
vector<int>v[MAX];


void reverse_floyd_warshall(void)
{
    int i,k,j;
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                mat[i][j]-=mat[i][k]*mat[k][j];
            }


    return ;
}

int main(void)
{
    int loop,m,i,j,u,v1,w,cas=0,edge,sz;
    scanf("%d",&loop);
    while(loop--)
    {
        mem(mat,0);edge=0;
        scanf("%d %d",&n,&m);
        for(i=0;i<=n;i++) v[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v1,&w);
            mat[u][v1]=w;
        }
        reverse_floyd_warshall();
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(mat[i][j])
                    {v[i].pb(j);edge++;}
            }
        printf("Case %d: %d %d\n",++cas,n,edge);
        for(i=0;i<n;i++)
        {
            sz=(int)v[i].size();
            printf("%d",sz);
//            cout<<sz;
            for(j=0;j<(int)v[i].size();j++) printf(" %d",v[i][j]);
            puts("");
        }
    }
    return 0;
}


