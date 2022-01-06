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
#define MAX 10500
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
int prime[1300];
int arr_m[11000];
int arr_n[11000];

void seive()
{
    int j,k=0;
    prime[0]=2;num[1]=1;
    for(int i=4;i<MAX;i+=2) num[i]=1;
    for(int i=3;i<MAX;i+=2)
    {
        if(!num[i])
        {
            prime[++k]=i;
//            print2(k,i);
            if(i<MAX/i) for(j=i*i;j<MAX;j+=i) num[j]=1;
        }
    }
//    print2(k,prime[k]);
}
int get_factor(int m,int n)
{
    mem(arr_m,0);mem(arr_n,0);
    vector<int>p1;

    int sq=sqrt(m)+1,val;
    for(int i=0;prime[i]<sq;i++)
    {
        if(m%prime[i]==0)
        {
            p1.pb(prime[i]);
//            print1(prime[i]);
            while(m%prime[i]==0)
            {
                arr_m[prime[i]]++;
                m/=prime[i];
            }
        }
        sq=sqrt(m)+1;
    }
    if(m>1)
    {
        if(arr_m[m]==0) p1.pb(m);
        arr_m[m]++;
    }

//    for(int i=0;i<SZ(p1);i++) print2(p1[i],arr_m[p1[i]]);


    for(int i=n;i>1;i--)
    {
        if(!num[i]) {arr_n[i]++;continue;}
        val=i;
        sq=sqrt(val)+1;
        for(int j=0;prime[j]<sq;j++)
        {
            if(val%prime[j]==0)
            {
//                p1.pb(prime[i]);
                while(val%prime[j]==0)
                {
                    arr_n[prime[j]]++;
                    val/=prime[j];
                }
            }
            sq=sqrt(val)+1;
        }
        if(val>1) arr_n[val]++;
    }

    int ans=oo,chk;
    for(int i=0;i<SZ(p1);i++)
    {
        chk=arr_n[p1[i]]/arr_m[p1[i]];
        ans=min(ans,chk);
    }
    return ans;

}
int main(void)
{
    seive();
    int n,m,ans;
    int t=0,cas;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d %d",&m,&n);
        ans=get_factor(m,n);

        printf("Case %d:\n",++t);
        if(ans==0)
        {
            puts("Impossible to divide");
        }
        else print1(ans);
    }
    return 0;
}

