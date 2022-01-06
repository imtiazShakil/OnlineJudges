#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define MAX 1000
#define mem(a,b) memset(a,b,sizeof a)

using namespace std;


vector<int>x;
vector<int>y;
map<int,int>row;
map<int,int>col;
int grid[10][10];

struct rectangle
{
    int x1,y1,x2,y2;
} ;


int main(void)
{
    int loop,i,j,sec,wk_sec,un_sec,len,width,cas=0;
    scanf("%d",&loop);
    rectangle r1,r2;
    while(loop--)
    {
        x.clear();y.clear();sec=0;wk_sec=0;un_sec=0;
        row.clear();col.clear();mem(grid,0);

        scanf("%d %d %d %d",&r1.x1,&r1.y1,&r1.x2,&r1.y2);
        x.pb(r1.x1);x.pb(r1.x2);y.pb(r1.y1);y.pb(r1.y2);
        scanf("%d %d %d %d",&r2.x1,&r2.y1,&r2.x2,&r2.y2);
        x.pb(r2.x1);x.pb(r2.x2);y.pb(r2.y1);y.pb(r2.y2);

        sort(all(x));sort(all(y));

        for(i=0;i<(int)x.size();i++)
            row[x[i]]=i;
        for(i=0;i<(int)y.size();i++)
            col[y[i]]=i;

        for(i=col[r1.y1];i<col[r1.y2];i++)
        {
            for(j=row[r1.x1];j<row[r1.x2] ;j++ )
            {
                grid[i][j]++;
            }
        }

        for(i=col[r2.y1];i<col[r2.y2];i++)
        {
            for(j=row[r2.x1];j<row[r2.x2] ;j++ )
            {
                grid[i][j]++;
            }
        }
//        for(i=0;i<4;i++,puts(""))
//            for(j=0;j<4;j++) cout<<grid[i][j];


        for(i=0;i<(int)y.size();i++)
            for(j=0;j<(int)x.size();j++)
            {
                if( grid[i][j]==1 )
                {
                    width=x[j+1]-x[j];
                    len=y[i+1]-y[i];
                    wk_sec+= (width*len);
                }
                if( grid[i][j]==2 )
                {
                    width=x[j+1]-x[j];
                    len=y[i+1]-y[i];
                    sec+= (width*len);
                }
            }
        un_sec=10000-sec-wk_sec;
        printf("Night %d: %d %d %d\n",++cas,sec,wk_sec,un_sec);
    }
    return 0;
}
