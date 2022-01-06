#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
int vertical[6][3];

int main(void)
{
    int loop,cas=0,hr,mn,sec,i;
    scanf("%d",&loop);
    while(loop--)
    {
        memset(vertical,0,sizeof vertical);

        scanf("%d:%d:%d",&hr,&mn,&sec);
        for(i=0;i<6;i++)
        {
            if( ( hr&(1<<i) )>0 ) vertical[i][0]=1;
            else vertical[i][0]=0;
        }
        for(i=0;i<6;i++)
        {
            if( ( mn&(1<<i) )>0 ) vertical[i][1]=1;
            else vertical[i][1]=0;
        }
        for(i=0;i<6;i++)
        {
            if( ( sec&(1<<i) )>0 ) vertical[i][2]=1;
            else vertical[i][2]=0;
        }


        printf("%d ",++cas);
        for(i=5;i>=0;i--)
        {
            printf("%d%d%d",vertical[i][0],vertical[i][1],vertical[i][2] );
        }
        printf(" ");

        for(i=0;i<3;i++)
        {
            printf("%d%d%d%d%d%d",vertical[5][i],vertical[4][i],vertical[3][i],vertical[2][i],vertical[1][i],vertical[0][i]);
        }
        puts("");
    }
}
