#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

bool color[100];
char str[100];

vector<string>num;
vector<string>op;
char oprnd[]={'+','-','*'};
int arr[5];

void bt(int depth)
{
    if(depth==5)
    {
        num.push_back(str);
//        printf("%s\n",str);
        return ;
    }
    for(int i=0;i<5;i++)
    {
        if(color[i]==0)
        {
            str[depth]=i;
            color[i]=1;
            bt(depth+1);
            color[i]=0;
        }
    }
    return ;
}
void bt_pow(int depth)
{
    if(depth==4)
    {
        op.push_back(str);
        return ;
    }
    for(int i=0;i<3;i++)
    {
        str[depth]=i;
        bt_pow(depth+1);
    }
    return ;
}

int sol(int indx_num,int indx_op)
{
    int i,sum=0;
    if( oprnd[ op[indx_op][0] ]=='+' ) sum= arr[num[indx_num][0]] + arr[num[indx_num][1]] ;
    if( oprnd[ op[indx_op][0] ]=='-' ) sum= arr[num[indx_num][0]] - arr[num[indx_num][1]] ;
    if( oprnd[ op[indx_op][0] ]=='*' ) sum= arr[num[indx_num][0]] * arr[num[indx_num][1]] ;

    if( oprnd[ op[indx_op][1] ]=='+' ) sum=sum+arr[num[indx_num][2]];
    if( oprnd[ op[indx_op][1] ]=='-' ) sum=sum-arr[num[indx_num][2]];
    if( oprnd[ op[indx_op][1] ]=='*' ) sum=sum*arr[num[indx_num][2]];

    if( oprnd[ op[indx_op][2] ]=='+' ) sum=sum+arr[num[indx_num][3]];
    if( oprnd[ op[indx_op][2] ]=='-' ) sum=sum-arr[num[indx_num][3]];
    if( oprnd[ op[indx_op][2] ]=='*' ) sum=sum*arr[num[indx_num][3]];

    if( oprnd[ op[indx_op][3] ]=='+' ) sum=sum+arr[num[indx_num][4]];
    if( oprnd[ op[indx_op][3] ]=='-' ) sum=sum-arr[num[indx_num][4]];
    if( oprnd[ op[indx_op][3] ]=='*' ) sum=sum*arr[num[indx_num][4]];

    return sum;

}

int main(void)
{
    num.clear();
    bt(0);
    memset(str,0,sizeof str);
    op.clear();
    bt_pow(0);
    int i,j,ans;bool flag;
    int count=0;

//    for(int i=0;i<(int)num.size();i++) cout<<i<<" "<<num[i]<<endl;
//    for(int i=0;i<(int)op.size();i++) cout<<i<<" "<<op[i]<<endl;

    while(scanf("%d %d %d %d %d",&arr[0],&arr[1],&arr[2],&arr[3],&arr[4])==5 && (arr[0] || arr[1] ||arr[2] ||arr[3] || arr[4]  ) )
    {
        for( i=0,flag=0;i<(int)num.size();i++)
        {
            for( j=0;j<(int)op.size();j++)
            {
                ans=sol(i,j);
//                count++;
                if(ans==23) {flag=1;break;}
            }
            if(flag) break;
        }
        cout<<count<<endl;

        if(flag) puts("Possible");
        else puts("Impossible");
    }
    return 0;
}
