/*
ID: shakil1
PROG: checker
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
#define MAX 15
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define fs      first
#define sc      second

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;
int n,sol=0;
//int arr[MAX][MAX];
int rrr[MAX];
int up[MAX][MAX];
//int down[MAX][MAX];
int lft[MAX][MAX];
//int rght[MAX][MAX];
int d1[MAX][MAX];
//int d2[MAX][MAX];
int d3[MAX][MAX];
//int d4[MAX][MAX];

void mark(int row,int col)
{
    lft[row][0]++;
//    rght[row][n-1]++;
    up[0][col]++;
//    down[n-1][col]++;

    int mn=min(row,col);
//    int mx=max(row,col);
    d1[row-mn][col-mn]++;
//    d2[ row+(n-1-mx) ][col+ (n-1-mx)]++;


    int mn2=min( n-1-row,col);
    d3[row+mn2][col-mn2]++;///down-left

    mn2=min(row,n-1-col);
//    d4[row-mn2][col+mn2]++;///up-right


    return ;
}

void un_mark(int row,int col)
{
    lft[row][0]--;
//    rght[row][n-1]--;
    up[0][col]--;
//    down[n-1][col]--;

    int mn=min(row,col);
//    int mx=max(row,col);
    d1[row-mn][col-mn]--; ///up-left
//    d2[ row+(n-1-mx) ][col+ (n-1-mx)]--;///down-right

    int mn2=min( n-1-row,col);
    d3[row+mn2][col-mn2]--;///down-left
//    mn2=min(row,n-1-col);
//    d4[row-mn2][col+mn2]--;///up-right

    return ;
}
int chk(int row,int col)
{
    if(lft[row][0]) return 0;
//    if(rght[row][n-1]) return 0;
    if(up[0][col]) return 0;
//    if(down[n-1][col]) return 0;

    int mn=min(row,col);
//    int mx=max(row,col);
    int mn2=min( n-1-row,col);

    if(d1[row-mn][col-mn]) return 0;
//    if(d2[ row+(n-1-mx) ][col+ (n-1-mx)] ) return 0;

    if(d3[row+mn2][col-mn2]) return 0;
//    mn2=min(row,n-1-col);
//    if(d4[row-mn2][col+mn2]) return 0;

    return 1;

}

void rec(int row)
{
    if(row==n)
    {
        if(sol<3)
        {
            for(int i=0;i<n;i++)
            {
                if(i) printf(" %d",rrr[i]);
                else printf("%d",rrr[i]);
            }
            puts("");
        }
        sol++;
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(chk(row,i))
        {
            mark(row,i);
            rrr[row]=i+1;
            rec(row+1);
            un_mark(row,i);
        }
    }
    return ;

}
int main(void)
{
    freopen("checker.in","r",stdin);
    freopen("checker.out","w+",stdout);


    scanf("%d",&n);
    rec(0);


    printf("%d\n",sol);

    return 0;
}



