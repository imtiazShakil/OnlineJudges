#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>

#define mem(a,b) memset(a,b,sizeof a)
#define MAX 1200

using namespace std;

int rrr[]={-1,-1,-1,0,1,1,1,0};
int ccc[]={-1,0,1,1,1,0,-1,-1};

int maxc,maxr;
int mat[MAX][MAX];
int cl[MAX][MAX];

void bfs(int row,int col)
{
    queue<int>Q;
    cl[row][col]=0;
    Q.push(row);Q.push(col);
    int r,c,p,q,i;
    while(!Q.empty())
    {
        r=Q.front();Q.pop();
        c=Q.front();Q.pop();
        for(i=0;i<8;i++)
        {
            p=r+rrr[i];
            q=c+ccc[i];
            if(p>=0 && p<maxr && q>=0 && q<maxc && mat[p][q]!=0 && cl[p][q] )
            {
                cl[p][q]=0;
                Q.push(p);Q.push(q);
            }
        }
    }

}
int main(void)
{
    int r,c,i,j,count;
    while(scanf("%d %d",&r,&c)==2)
    {
        for(i=0;i<r;i++) for(j=0;j<c;j++) cl[i][j]=1;

        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                scanf("%d",&mat[i][j] );
            }
//        mem(cl,1);

        maxr=r;maxc=c;
        count=0;

       for(i=0;i<r;i++)
       {
           for(j=0;j<c;j++)
           {
               if(cl[i][j] && mat[i][j])
               {
                   count++;
                   bfs(i,j);
//                   for(i=0;i<r;i++,putchar('\n'))
//                    for(j=0;j<c;j++) printf("%d",cl[i][j]);
               }
           }
       }
       printf("%d\n",count);
    }

    return 0;
}
