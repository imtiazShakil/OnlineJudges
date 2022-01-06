/*
ID: shakil1
PROG: milk2
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>

#define pb push_back
#define MAX 5005
#define mem(a,b) memset(a,b,sizeof a)
#define oo (1<<25)
#define SZ(x) ( (int)x.size() )
using namespace std;

struct _tm
{
    int str,end;
};
vector<_tm>v;

bool com(_tm a,_tm b)
{
    if(a.str>b.str) return false;
    else return true;
}
int dur[MAX];
bool work[1000005];
int chk[1000005];

int main(void)
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w+",stdout);

    _tm tmp;
    int n,begin=oo,end=0,mx_tm=0,mx_tm1=0,sum;scanf("%d",&n);
    mem(dur,0);
    while(n--)
    {
        scanf("%d %d",&tmp.str,&tmp.end);
        begin=min(begin,tmp.str);end=max(end,tmp.end);
        v.pb(tmp);
    }
    sort(v.begin(),v.end(),com);

    for(int i=0;i<SZ(v);i++)
    {
        int tail=v[i].end;
        sum=v[i].end-v[i].str;
        for(int j=i+1;j<SZ(v);j++)
        {
            if(tail>=v[j].str && v[j].end>tail) {sum+= ( v[j].end-v[j].str -(tail-v[j].str) );tail=max(tail,v[j].end);}
            if(v[j].str>tail) break;
        }
        mx_tm=max(mx_tm,sum);

    }
    mem(work,0);

    int tail=0;
    for(int i=0;i<SZ(v);i++)
    {
        if(v[i].end>tail)
        {
            for(int j=max(tail,v[i].str);j<v[i].end;j++) work[j]=1;
        }
        tail=max(tail,v[i].end);
    }
    mem(chk,0);
    for(int i=begin;i<end;i++)
    {
        if(!work[i]) chk[i]=chk[i-1]+1;
        mx_tm1=max(mx_tm1,chk[i]);
    }
    printf("%d %d\n",mx_tm,mx_tm1);

    return 0;
}
