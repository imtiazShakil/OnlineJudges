#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>

#define mem(a,b) memset(a,b,sizeof a)
#define MAX 120

using namespace std;

char mat[MAX][MAX];
bool cl[MAX][MAX];
int mxr,mxc;

int go_horizontal(int indx,int row)
{
    int obstacle=1;

    for(int i=indx-1;i>=0;i--)
    {
        if(mat[row][i]=='.') break;
//        if(mat[row][i]=='*')  obstacle++;
        else obstacle++;
    }

    for(int i=indx+1;i<mxc;i++)
    {
        if(mat[row][i]=='.') break;
//        if(cl[row][i]==0)  obstacle++;
        else obstacle++;
    }
    return obstacle;

}
void box_horz(int indx,int row)
{
    cl[row][indx]=1;
    for(int i=indx-1;i>=0;i--)
    {
        if(mat[row][i]=='.') break;
        cl[row][i]=1;
    }

    for(int i=indx+1;i<mxc;i++)
    {
        if(mat[row][i]=='.') break;
        cl[row][i]=1;
    }
}
int go_vertical(int indx,int col)
{
    int obstacle=1;

    for(int i=indx-1;i>=0;i--)
    {
        if(mat[i][col]=='.') break;
//        if(cl[i][col]==0)  obstacle++;
        else obstacle++;
    }

    for(int i=indx+1;i<mxr;i++)
    {
        if(mat[i][col]=='.') break;
//        if(cl[i][col]==0)  obstacle++;
        else obstacle++;
    }
    return obstacle;
}

void box_vert(int indx,int col)
{
    cl[indx][col]=1;
    for(int i=indx-1;i>=0;i--)
    {
        if(mat[i][col]=='.') break;
        cl[i][col]=1;
    }

    for(int i=indx+1;i<mxr;i++)
    {
        if(mat[i][col]=='.') break;
        cl[i][col]=1;
    }
}


int main(void)
{
    int r,c,i,j,count,val1,val2,k,l;
    while(scanf("%d %d",&r,&c)==2)
    {
        for(i=0;i<r;i++) scanf("%s",mat[i]);
        mem(cl,0);

        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                if(mat[i][j]=='.') cl[i][j]=1;
                else cl[i][j]=0;
            }

        mxr=r;mxc=c;

        count=0;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                if(cl[i][j]==0)
                {
                    count++;
                    val1=go_horizontal(j ,i);
                    val2=go_vertical( i,j);
//                    printf("chk %d %d horz %d vert %d \n",i,j,val1,val2);

                    if(val1>val2)    box_horz(j,i);
                    else box_vert(i,j);

//                    for(k=0;k<r;k++,puts(""))
//                        for(l=0;l<c;l++) printf("%d",cl[k][l]);
//
//                    puts("");


                }
            }

        printf("%d\n",count);

    }
    return 0;
}
