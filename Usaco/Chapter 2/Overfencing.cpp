/*
ID: shakil1
PROG: maze1
LANG: C++
*/
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


#define print1(a) cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define PI (2*acos(0))
#define ERR 1e-5
#define ll long long
#define VI vector<int>
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define MAX 220
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second

int rrr[]={1,0,-1,0};
int ccc[]={0,1,0,-1};

int rrr2[]={2,0,-2,0};
int ccc2[]={0,2,0,-2};

///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

int dist[MAX][80];
int dist3[MAX][80];
int dist4[MAX][80];

vector<string>v;
vector<paii>pt;

paii ex1,ex2;

void bfs(paii cord)
{
    dist[cord.fs][cord.sc]=0;
    map<paii,int>M;
    queue<int>Q;
    Q.push(cord.fs);Q.push(cord.sc);
    int r,c,p,q,blck_p,blck_q;
    bool clr;
//    int mx_d=0;
    while(!Q.empty())
    {
        r=Q.front();Q.pop();
        c=Q.front();Q.pop();
        if(M.find(mp(r,c))!=M.end() ) continue;
        M[mp(r,c)]=1;

        for(int i=0;i<4;i++)
        {
            blck_p=r+rrr[i];
            blck_q=c+ccc[i];

            p=r+rrr2[i];
            q=c+ccc2[i];
            clr=0;
            if( blck_p>=0 && blck_p<SZ(v) && blck_q>=0 && blck_q<SZ(v[0]) )
            {
                if(v[blck_p][blck_q]!='+' && v[blck_p][blck_q]!='-' && v[blck_p][blck_q]!='|'  ) clr=1;
            }
            if(p>=0 && p<SZ(v) && q>=0 && q<SZ(v[0]) && M.find(mp(p,q))==M.end() && clr)
            {
                Q.push(p);Q.push(q);
                dist[p][q]=dist[r][c]+1;
            }
        }
    }
    return ;

}
void bfs_exit(paii cord)
{
    dist[cord.fs][cord.sc]=0;
    map<paii,int>M;
    queue<int>Q;
    Q.push(cord.fs);Q.push(cord.sc);
    int r,c,p,q,blck_p,blck_q;
    bool clr;
    while(!Q.empty())
    {
        r=Q.front();Q.pop();
        c=Q.front();Q.pop();
        if(M.find(mp(r,c))!=M.end() ) continue;
        M[mp(r,c)]=1;

        for(int i=0;i<4;i++)
        {
            blck_p=r+rrr[i];
            blck_q=c+ccc[i];

            p=r+rrr2[i];
            q=c+ccc2[i];
            clr=0;
            if( blck_p>=0 && blck_p<SZ(v) && blck_q>=0 && blck_q<SZ(v[0]) )
            {
                if(v[blck_p][blck_q]!='+' && v[blck_p][blck_q]!='-' && v[blck_p][blck_q]!='|'  ) clr=1;
                if(ex1.fs==blck_p && ex1.sc==blck_q)
                {
                    dist[ex1.fs][ex1.sc]=dist[r][c]+1;
                }
                if(ex2.fs==blck_p && ex2.sc==blck_q)
                {
                    dist[ex2.fs][ex2.sc]=dist[r][c]+1;
                }
            }
            if(p>=0 && p<SZ(v) && q>=0 && q<SZ(v[0]) && M.find(mp(p,q))==M.end() && clr)
            {
                Q.push(p);Q.push(q);
                dist[p][q]=dist[r][c]+1;
            }
        }
    }
    return ;
}
int main(void)
{
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);
    string str;
    int w,h;
    scanf("%d %d\n",&w,&h);
    char txt[MAX];

    for(int i=0;i<2*h+1;i++)
    {
        getline(cin,str);
        v.pb(str);
    }

    paii node1,node2;
    int mx_dst;
    bool fl1=0,fl2=0;
    for(int i=1;i<2*h+1;i+=2)
    {
        if(v[i][0]==' ')
        {
            if(!fl1) {ex1.fs=i;ex1.sc=0;fl1=1;continue;}
            if(!fl2) {ex2.fs=i;ex2.sc=0;fl2=1;continue;}
        }
    }
    for(int i=1;i<2*h+1;i+=2)
    {
        if(v[i][2*w]==' ')
        {
            if(!fl1) {ex1.fs=i;ex1.sc=2*w;fl1=1;continue;}
            if(!fl2) {ex2.fs=i;ex2.sc=2*w;fl2=1;continue;}
        }
    }

    for(int j=1;j<2*w+1;j+=2)
    {
        if(v[0][j]==' ')
        {
            if(!fl1) {ex1.fs=0;ex1.sc=j;fl1=1;continue;}
            if(!fl2) {ex2.fs=0;ex2.sc=j;fl2=1;continue;}
        }
    }

    for(int j=1;j<2*w+1;j+=2)
    {
        if(v[2*h][j]==' ')
        {
            if(!fl1) {ex1.fs=2*h;ex1.sc=j;fl1=1;continue;}
            if(!fl2) {ex2.fs=2*h;ex2.sc=j;fl2=1;continue;}
        }
    }

    for(int i=0;i<4;i++)
    {
        int j=ex1.fs+rrr[i];
        int q=ex1.sc+ccc[i];

        if(j>=0 && j<SZ(v) && q>=0 && q<SZ(v[0]) )
        {
            if(v[j][q]==' ')
            {
                mem(dist,0);
                bfs(mp(j,q));
                for(int m=1;m<2*h+1;m+=2)
                    for(int n=1;n<2*w+1;n+=2)
                    {
                        dist3[m][n]=dist[m][n];
                    }
            }
        }
    }
    int far=0;
    for(int i=0;i<4;i++)
    {
        int j=ex2.fs+rrr[i];
        int q=ex2.sc+ccc[i];
        if(j>=0 && j<SZ(v) && q>=0 && q<SZ(v[0]) )
        {
            if(v[j][q]==' ')
            {
                mem(dist,0);
                bfs(mp(j,q));
                for(int m=1;m<2*h+1;m+=2)
                    for(int n=1;n<2*w+1;n+=2)
                    {
                        dist4[m][n]=dist[m][n];
                        if(min(dist3[m][n],dist4[m][n]) >far ) far=min(dist3[m][n],dist4[m][n]);
                    }
            }
        }
    }

    for(int m=1;m<2*h+1;m+=2)
       for(int n=1;n<2*w+1;n+=2)
       {
            if( min( dist3[m][n],dist4[m][n] )==far  ) {pt.pb(mp(m,n));}
       }

    mx_dst=0;
    int dst;


    for(int i=0;i<SZ(pt);i++)
        {
            mem(dist,0);
            bfs_exit(pt[i]);
            dst=min(dist[ex1.fs][ex1.sc],dist[ex2.fs][ex2.sc]);

            mx_dst=max(mx_dst,dst);
        }
     print1(mx_dst);

    return 0;
}

