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
int arr[MAX][MAX];
int rrr[MAX];
int up[MAX][MAX];
int down[MAX][MAX];
int d1[MAX][MAX],d2[MAX][MAX],d3[MAX][MAX],d4[MAX][MAX];

void mark(int row,int col)
{
    for(int i=0;i<n;i++) {arr[i][col]++;arr[row][i]++;}
    int lft_r=row,lft_c=col;
    int mx=max(abs(row+1-n) ,abs(col+1-n) );
    for(int i=1;i<=mx;i++)
    {
        if(row+i<n && col+i<n ) arr[row+i][col+i]++;
        if(row-i>=0 && col-i>=0 ) arr[row-i][col-i]++;
        if(row+i<n && col-i>=0 ) arr[row+i][col-i]++;
        if(row-i>=0 && col+i<n ) arr[row-i][col+i]++;
    }
    return ;
}

void un_mark(int row,int col)
{
    for(int i=0;i<n;i++) {arr[i][col]--;arr[row][i]--;}
    int lft_r=row,lft_c=col;
    int mx=max(abs(row+1-n) ,abs(col+1-n) );
    for(int i=1;i<=mx;i++)
    {
        if(row+i<n && col+i<n ) arr[row+i][col+i]--;
        if(row-i>=0 && col-i>=0 ) arr[row-i][col-i]--;
        if(row+i<n && col-i>=0 ) arr[row+i][col-i]--;
        if(row-i>=0 && col+i<n ) arr[row-i][col+i]--;
    }
    return ;
}

void rec(int row)
{
    if(row==n)
    {
        if(sol<3)
        {
            for(int i=0;i<n;i++)
            {
//                v[sol][i]=rrr[i];
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
        if(arr[row][i]==0)
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
//    freopen("checker.in","r",stdin);
//    freopen("checker.out","w+",stdout);

//    n=5;
//    mark(2,2);
//    for(int i=0;i<n;i++,puts(""))
//        for(int j=0;j<n;j++) printf("%d ",arr[i][j]);
//
//    un_mark(2,2);
//    for(int i=0;i<n;i++,puts(""))
//        for(int j=0;j<n;j++) printf("%d ",arr[i][j]);

    scanf("%d",&n);
    rec(0);


    printf("%d\n",sol);

    return 0;
}


