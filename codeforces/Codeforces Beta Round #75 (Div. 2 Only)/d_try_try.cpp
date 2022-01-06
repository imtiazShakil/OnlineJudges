#include <iostream>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define MAX 100000

using namespace std;

struct data
{
    int indx;
    int val;
};

bool com(data a,data b)
{
    if(a.val!=b.val) {if(a.val<b.val) return true;else return false;}
    if(a.indx<b.indx) return true;
    else return false;
}
vector<data>v;
int sol[MAX];

int main(void)
{
    int n,i,j,k,val;
    data tmp;v.clear();


    scanf("%d",&n);
    for(int i=0;i<n;i++) {scanf("%d",&val);tmp.indx=i;tmp.val=val;v.pb(tmp); }

    sort(v.begin(),v.end(),com);

    int mx_indx=-1;
    for(int i=0;i<n;i++)
    {
        if(mx_indx>v[i].indx)
        {
            sol[v[i].indx]=mx_indx-v[i].indx-1;
        }
        else sol[v[i].indx]=-1;
        mx_indx=max(mx_indx,v[i].indx);
    }

    for(int i=0;i<n;i++)
    {
        if(i)cout<<" "<<sol[i];
        else cout<<sol[i];
    }
    puts("");


    return 0;
}
