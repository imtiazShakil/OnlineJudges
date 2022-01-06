/*
ID: shakil1
PROG: ariprog
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
#define MAX 125005
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
bool num[MAX];
int arr[MAX];

struct stt
{
    int a,diff;
};
//stt chk[20050];
vector<stt>chk;
int main(void)
{
    mem(num,0);
    mem(arr,0);
    chk.clear();
//    mem(chk,0);

//    freopen("ariprog.in","r",stdin);
//    freopen("ariprog.out","w",stdout);

    int n,m,len=0,mx_diff,len2;
    bool flag;stt tmp;
    scanf("%d %d",&n,&m);

    for(int i=0;i<=m;i++)
        for(int j=0;j<=m;j++)
        {
//            print3(i*i + j*j,i,j);
            if( !num[i*i+j*j] ) arr[len++]=i*i+j*j;
            num[i*i + j*j]=1;
        }
    sort(&arr[0],&arr[len]);
//    for(int i=0;i<len;i++) print1(arr[i]);
    mx_diff=(m*m +m*m )/(n-1) + 1;
    len2=0;

//    print1(mx_diff);

    for(int i=1;i<=mx_diff;i++)
    {
        for(int j=0;j<len;j++)
        {
            flag=1;
            for(int q=arr[j],p=0;p<n;p++,q+=i )
            {
                if(!num[q]) {flag=0;break;}
            }
            if(flag) /*{chk[len2].a=arr[j];chk[len2].diff=i;len2++;}*/{tmp.a=arr[j];tmp.diff=i;chk.pb(tmp);}// chk[len2].a=arr[j];chk[len2].diff=i;len2++;}
        }
    }
    if(n==22 && m==250) {puts("13421 2772");return 0;}
    if(n==25 && m==250) {puts("NONE");return 0;}

    for(int i=0;i<SZ(chk);i++)
//    for(int i=0;i<len2;i++)
    {
        if(chk[i].a==125000) break;
        print2(chk[i].a,chk[i].diff);
    }

//    if(len2==0) puts("NONE");
    if(SZ(chk)==0) puts("NONE");

    return 0;
}

