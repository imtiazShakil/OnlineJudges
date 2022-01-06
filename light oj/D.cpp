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

char grid[25][25];
int ans, w, h;
bool col[25][25];
int xx[] = {-1, 0, 1, 0};
int yy[] = {0, -1, 0, 1};

void bfs(int x, int y)
{
    int i, nowx, nowy, nx, ny;
    queue<int>Q;
    Q.push(x); Q.push(y);
    ans++;
    while(!Q.empty())
    {
        nowx = Q.front(); Q.pop();
        nowy = Q.front(); Q.pop();
        col[nowx][nowy] = 1;
//        cout<<nowx<<" "<<nowy<<endl;
        for(i=0;i<4;i++)
        {
            nx = nowx+xx[i];
            ny = nowy+yy[i];
            print2(nx,ny);
            if(nx>=0 && nx<h && ny>=0 && ny<w)
           {
               if(grid[nx][ny]=='.' && !col[nx][ny])
                {
                    Q.push(nx);
                    Q.push(ny);
                    ans++;
                }
            }
        }
    }
    return;
}

int main(void)
{
    int t, cas=1;
    cin>>t;
    while(t--)
    {
        int i, j, stx, sty;
        cin>>w>>h;
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]=='@')
                {
                    stx = i; sty = j;
                }
            }
        }
//        cout<<stx<<" "<<sty<<endl;
        memset(col, false, sizeof col);
        ans=0;
        bfs(stx, sty);
        cout<<"tot "<<ans<<endl;
        printf("Case %d: %d\n", cas++, ans);
    }

    return 0;
}


