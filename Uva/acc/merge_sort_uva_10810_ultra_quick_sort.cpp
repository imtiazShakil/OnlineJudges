
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
#define MAX 500005
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
ll swp=0;
void merge(int a[],int b[],int c[],int l_a,int l_b)
{
    int k1=0,k2=0,p=0;


    while(k1<l_a || k2<l_b)
    {
        if( k1>=l_a ) {c[p++]=b[k2];k2++;continue;}
        else if(k2>=l_b)
        {
//            if(p>k1) swp+=p-k1;
            c[p++]=a[k1];k1++;
            continue;
        }

        if( a[k1]<=b[k2] )
        {
            c[p++]=a[k1];k1++;
//            if(p>k1) swp+=p-k1;
        }
        else if( a[k1]>b[k2] )
        {
            c[p++]=b[k2];k2++;
            swp+=(l_a-k1);
        }

    }

}
void partiton(int arr[],int sz)
{
    if(sz==1) return ;
    int len=sz/2;
    int lft[len],rght[sz-len];

    for(int i=0,p=0;i<len;i++,p++) lft[p]=arr[i];
    for(int i=len,p=0;i<sz;i++,p++) rght[p]=arr[i];
    partiton(lft,len);partiton(rght,sz-len);

    merge(lft,rght,arr,len,sz-len);

    return ;
}
int main(void)
{
//    freopen("sort3.in","r",stdin);
//    freopen("sort3.out","w+",stdout);

    int n;
    int arr[MAX];

    while(scanf("%d",&n)==1 && n)
    {
        swp=0;
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        partiton(arr,n);

//        for(int i=0;i<n;i++) printf(" %d",arr[i]);puts("");
        print1(swp);
    }
    return 0;
}
