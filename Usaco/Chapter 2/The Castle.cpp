/*
ID: shakil1
PROG: castle
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
#define MAX 110
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define fs      first
#define sc      second

int rrr[]= {2,0,-2,0};
int ccc[]= {0,2,0,-2};
int rrr2[]= {1,0,-1,0};
int ccc2[]= {0,1,0,-1};
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;
int arr[MAX][MAX];
bool cl[MAX][MAX];
int mx_spc=0,mx_spc2=0;
int n,m;
vector< pair<paii,int> >v;

int bfs(int row,int col)
{
    queue<int>Q;
    Q.push(row);
    Q.push(col);

    int mx_dist=1;

    int p,q,r,c,w_p,w_q;

    while(!Q.empty())
    {
        r=Q.front();
        Q.pop();
        c=Q.front();
        Q.pop();
        cl[r][c]=1;
        for(int i=0; i<4; i++)
        {
            p=r + rrr[i];
            q=c + ccc[i];
            w_p=r + rrr2[i];
            w_q=c+ccc2[i];

            if(p>=0 && q>=0 && p<n*2 && q<m*2 && arr[w_p][w_q]==0 && cl[p][q]==0)
            {
                Q.push(p);
                Q.push(q);
                cl[p][q]=1;
                mx_dist++;
            }
        }
    }
    return mx_dist;

}
void make_wall(int row,int col,int val)
{
    for(int i=0; i<4; i++)
    {
        if((val&(1<<i)))
        {
            if(i==0)
            {
                arr[row][col-1]=1;
                arr[row-1][col-1]=1;
                arr[row+1][col-1]=1;
            }
            if(i==1)
            {
                arr[row-1][col]=1;
                arr[row-1][col-1]=1;
                arr[row-1][col+1]=1;
            }
            if(i==2)
            {
                arr[row][col+1]=1;
                arr[row-1][col+1]=1;
                arr[row+1][col+1]=1;
            }
            if(i==3)
            {
                arr[row+1][col]=1;
                arr[row+1][col-1]=1;
                arr[row+1][col+1]=1;
            }
        }
    }
}
void srch_wall()
{
    paii nd;
    int val,mx=0,row;
    bool flag,flag2=1,flag3=1;

    for(int j=1; j<m*2 /*&& (flag2 || flag3) */; j++)
        for(int i=n*2-1; i>0 /* && (flag2 || flag3) */; i--)
        {
            if(i%2 && j%2==0)
            {
                if(arr[i][j])
                {
//                    print3("wall ",i,j);
                    arr[i][j]=0;
                    mem(cl,0);
                    flag=0;
                    for(int p=1; p<n*2; p+=2)
                        for(int q=1; q<m*2; q+=2)
                        {
                            if(cl[p][q]==0)
                            {
                                val=bfs(p,q);
                                if(val>=mx)
                                {
                                    mx=val;
                                    nd=mp(i,j);
                                    flag=1;
                                }
                            }
                        }
//                    if(flag && flag3==0 && mx_spc+mx_spc2==mx  && i<row) {flag2=0;}
//                    else if( flag && flag2 && flag3 && mx_spc+mx_spc2==mx) {flag2=0;row=i;}

                    if(flag) v.pb(mp(nd,mx));
                    if(flag && mx_spc+mx_spc2==mx ) return ;
                    arr[i][j]=1;
//                    print3("flag2 ",flag2,row);
                }
//                print2(flag2,flag3);
//                if(i==97) return ;
            }
            else if(i%2==0 && j%2)
            {
                if(arr[i][j])
                {
//                    print3("wall ",i,j);
                    arr[i][j]=0;
                    mem(cl,0);
                    flag=0;
                    for(int p=1; p<n*2; p+=2)
                        for(int q=1; q<m*2; q+=2)
                        {
                            if(cl[p][q]==0)
                            {
                                val=bfs(p,q);
                                if(val>=mx)
                                {
                                    mx=val;
                                    nd=mp(i,j);
                                    flag=1;
                                }
                            }
                        }
//                    if(flag && flag2==0 && mx_spc+mx_spc2==mx  && i<row) {flag3=0;}
//                    else if( flag && flag3 &&  flag2&& mx_spc+mx_spc2==mx) {flag3=0;row=i;}

                    if(flag) v.pb(mp(nd,mx));
                    if(flag && mx_spc+mx_spc2==mx ) return ;
                    arr[i][j]=1;
                }
            }
        }

    return ;
}

bool com( pair<paii,int>a,pair<paii,int>b )
{
    if(a.sc!=b.sc) return a.sc>b.sc;
    if(a.fs.sc!=b.fs.sc) return a.fs.sc<b.fs.sc;
    if(a.fs.fs!=b.fs.fs) return a.fs.fs>b.fs.fs;

}
int main(void)
{
    freopen("castle.in","r",stdin);
    freopen("castle.out","w+",stdout);
    int val,house=0,nm;
    paii nd;
    scanf("%d %d",&m,&n);
    for(int i=1; i<n*2; i+=2)
        for(int j=1; j<m*2; j+=2)
        {
            scanf("%d",&val);
            make_wall(i,j,val);
        }
//    for(int i=0;i<=n*2;i++,puts(""))
//        for(int j=0;j<=m*2;j++) printf("%d ",arr[i][j]);

    for(int i=1; i<n*2; i+=2)
        for(int j=1; j<m*2; j+=2)
        {
            if(cl[i][j]==0)
            {
//                print3("calling bfs ",i,j);
                nm=bfs(i,j);
//                mx_spc=max(mx_spc,bfs(i,j) );
                if( nm> mx_spc) mx_spc=nm;
                else if(nm>=mx_spc2 && nm<=mx_spc) mx_spc2=nm;
                house++;
//                print2("num ",nm);print2("mxspc ",mx_spc);
            }
        }
    print1(house);
    print1(mx_spc);
//    print2("mx2",mx_spc2);
    srch_wall();
    sort(all(v),com);
    print1(v[0].sc);

//    for(int i=0;i<SZ(v);i++) print3(v[i].fs.fs,v[i].fs.sc,v[i].sc);

    if(v[0].fs.fs%2) print3(v[0].fs.fs/2 + 1,v[0].fs.sc/2,"E");
    else print3(v[0].fs.fs/2 + 1,v[0].fs.sc/2 + 1,"N");
    return 0;
}

