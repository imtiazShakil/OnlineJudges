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
#define paii pair<int,int>
#define mp make_pair

int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
vector<string>v;

int bfs(int x,int y)
{
    map<paii,int>M;
    queue<int>Q;
    Q.push(x);Q.push(y);
    int ans=0;
    int p,q,r,c;
    while(!Q.empty())
    {
        r=Q.front();Q.pop();
        c=Q.front();Q.pop();
//        print3("queeu  ",r,c);
//        if(M.find(mp()))
        M[mp(r,c)]=1;
        ans++;
        for(int i=0;i<4;i++)
        {
            p=r+rrr[i];
            q=c+ccc[i];

            if(p>=0 && q>=0 && p<SZ(v) && q<SZ(v[0]) && M.find( mp(p,q) )==M.end() )
            {
                if(v[p][q]=='#') continue;
                Q.push(p);Q.push(q);
                M[mp(p,q)]=1;
//                print2(p,q);
            }
        }
    }
    return ans;
}

int main(void)
{
    int s_x,s_y,ans;
    int r,c,cas;
    string str;
    scanf("%d",&cas);
    for(int i=0;i<cas;i++)
    {
        v.clear();
        scanf("%d %d",&c,&r);
        for(int p=0;p<r;p++) {cin>>str;v.pb(str);}

        for(int p=0;p<SZ(v);p++)
            for(int q=0;q<SZ(v[p]);q++)
            {
                if(v[p][q]=='@')
                {
                    s_x=p;s_y=q;
                }
            }
        ans=bfs(s_x,s_y);
        printf("Case %d: %d\n",i+1,ans);

    }
    return 0;
}

