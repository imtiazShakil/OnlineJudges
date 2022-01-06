#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>

#define MAX 10050
#define mem(a,b) memset(a,b,sizeof a)

using namespace std;

map<string,int>M;
int cut,len;
string org_str;

int dp[MAX];

//int dict(string str)
//{
//    if( M.find(str)==M.end() )
//}
int rec(int cur)
{
    if(cur==len) return 0;

    int &ret=dp[cur];
    if(ret!=-1) return ret;

    string tmp;
    int val;
    for(int i=cur;i<len;i++)
    {
        tmp.clear();
        for(int j=cur;j<=i;j++)
        {
            tmp+=org_str[j];
        }
//        tmp=org_str.substr(cur,i-cur+1);
        if( M.find(tmp)==M.end() ) val=rec(i+1) - (i-cur+1)*cut;
        else val=rec(i+1) + M[tmp];

        if(i==cur) ret=val;
        else ret=max(ret,val);
    }
    return ret;

}
int main(void)
{
    int loop,n,w,i,ans,cas=0;
    scanf("%d",&loop);
    char str[100000];
//    char org_str[100000];


    while(loop--)
    {
        M.clear();
        scanf("%d %d",&n,&cut);
        for(i=0;i<n;i++)
        {
            scanf("%s %d",str,&w);
            M[str]=w;
        }
//        scanf("%s",org_str);
        cin>>org_str;len=(int)org_str.size();
        for(i=0;i<=len;i++) dp[i]=-1;
//        mem(dp,-1);
        ans=rec(0);
        printf("Case %d: %d\n",++cas,ans);

    }

    return 0;
}
