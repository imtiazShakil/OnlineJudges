#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
bool maz_chk[][4]={ {0,1,0,1},{1,0,1,0},{0,1,0,1},{1,0,1,0} };

bool chk(vector<string>maze)
{
    int sum=0,i,j,p,q;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(maze[i][j]=='0') continue;
            for(p=i;p<4;p++)
            {
                if(p==i) q=j+1;
                else q=0;
                for(;q<4;q++)
                {
                    if(maze[i][j]> maze[p][q] && maze[p][q]!='0' ) sum++;
                }
            }
        }
    }
}
void dfs(vector<string>maze)
{

}
int main(void)
{
    int loop,i,j,val;
    vector<string>v;
    string str;

    scanf("%d",&loop);
    while(loop--)
    {
        v.clear();
        for(i=0;i<4;i++)
        {
            str.clear();
            for(j=0;j<4;j++)
            {
                scanf("%d",&val);
                str+=val+'0';
            }
            v.push_back(str);
        }
    }
}
