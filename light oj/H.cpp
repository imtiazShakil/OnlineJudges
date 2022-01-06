#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          2*acos(0)
#define ERR         1e-5
#define PRE         1e-8
#define SZ(a)       (int)a.size()
#define LL          long long
#define ISS         istringstream
#define OSS         ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fr(i,a,b)   for(i=a;i<=b;i++)
#define frn(i,a,b)  for(i=a;i>=b;i--)
#define fri(a,b)    for(i=a;i<=b;i++)
#define frin(a,b)   for(i=a;i>=b;i--)
#define frj(a,b)    for(j=a;j<=b;j++)
#define frjn(a,b)   for(j=a;j>=b;j--)
#define frk(a,b)    for(k=a;k<=b;k++)
#define frkn(a,b)   for(k=a;k>=b;k--)
#define frl(a,b)    for(l=a;l<=b;l++)
#define frln(a,b)   for(l=a;l>=b;l--)

#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
int dp[105][105][105][2][2];
int arr[105][105];

int main()
{
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        int m,n;
        mem(dp,0);
        cin>>m>>n;
        int i,j,k;
        for(i=1;i<=m;i++)
        fr(j,1,n)
            cin>>arr[i][j];
        dp[1][1][1][0][0]=arr[1][1];
        dp[1][1][1][0][1]=arr[1][1];
        dp[1][1][1][1][0]=arr[1][1];
        dp[1][1][1][1][1]=arr[1][1];

        fr(k,2,n)
        {
            //dp[1][1][k][0][0]=dp[1][1][k-1][0][0]+arr[1][k];
            dp[1][1][k][0][1]=dp[1][1][k-1][0][1]+arr[1][k];
            //dp[1][1][k][1][0]=dp[1][1][k-1][1][0]+arr[1][k];
            dp[1][1][k][1][1]=dp[1][1][k-1][1][1]+arr[1][k];
        }


        /*fr(k,1+1,n)
        {
           dp[2][1][k][0][0]=max(max(dp[2-1][1][k][0][0],dp[2-1][1][k][0][1]),max(dp[2-1][1][k][1][0],dp[2-1][1][k][1][1]))+arr[2][1]+arr[2][k]-arr[1][1];
           if(k>1+1)dp[2][1][k][0][1]=max(dp[2][1][k-1][0][0],dp[2][1][k-1][0][1])+arr[2][1]+arr[2][k]-arr[1][1];
           dp[2][1][k][1][0]=max(dp[2][1-1][k][0][0],dp[2][1-1][k][1][0])+arr[2][1]+arr[2][k]-arr[1][1];
           dp[2][1][k][1][1]=max(max(dp[2][1-1][k-1][0][0],dp[2][1-1][k-1][0][1]),max(dp[2][1-1][k-1][1][0],dp[2][1-1][k-1][1][1]))+arr[2][1]+arr[2][k]-arr[1][1];
        }*/

        fr(i,2,m)
        fr(j,1,n-1)
        fr(k,j+1,n)
        {
           dp[i][j][k][0][0]=max(max(dp[i-1][j][k][0][0],dp[i-1][j][k][0][1]),max(dp[i-1][j][k][1][0],dp[i-1][j][k][1][1]))+arr[i][j]+arr[i][k];
           dp[i][j][k][0][1]=max(dp[i][j][k-1][0][0],dp[i][j][k-1][0][1])+arr[i][j]+arr[i][k];
           dp[i][j][k][1][0]=max(dp[i][j-1][k][0][0],dp[i][j-1][k][1][0])+arr[i][j]+arr[i][k];
           dp[i][j][k][1][1]=max(max(dp[i][j-1][k-1][0][0],dp[i][j-1][k-1][0][1]),max(dp[i][j-1][k-1][1][0],dp[i][j-1][k-1][1][1]))+arr[i][j]+arr[i][k];
        }

        int ans=max(dp[m][m-1][m][0][0],dp[m][m-1][m][1][0]);
        print2(dp[m][m-1][m][0][0],dp[m][m-1][m][1][0]);
        printf("Case %d: ",++cas);
        print1(ans);

    }
    return 0;
}
