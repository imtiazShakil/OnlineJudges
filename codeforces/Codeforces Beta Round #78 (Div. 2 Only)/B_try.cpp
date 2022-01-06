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
#define MAX 60
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;
struct beer
{
    int amount,indx;
};
map<int,bool>M;
vector<beer>v;
bool com(beer a,beer b)
{
    if(a.amount!=b.amount) return a.amount<b.amount;
    else return a.indx<b.indx;
}
int main(void)
{
    int n,val;beer tmp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&val);
        tmp.amount=val;tmp.indx=i;
        v.pb(tmp);
        M[val]=1;
    }
    if(SZ(M)==1) puts("Exemplary pages.");
    else if(SZ(M)>3) puts("Unrecoverable configuration.");
    else
    {
        sort(all(v),com);
        int sum=0,mid;
        for(int i=0;i<SZ(v);i++) sum+=v[i].amount;
        if(sum%SZ(v) || (SZ(M)==2 && SZ(v)>2) ) {puts("Unrecoverable configuration.");return 0;}
        mid=sum/SZ(v);
        if(SZ(v)==2)
        {
            printf("%d ml. from cup #%d to cup #%d.",v[1].amount-mid,v[0].indx,v[1].indx);
        }
        else if(SZ(v)>2)
        {
            if(v[1].amount!=mid) {puts("Unrecoverable configuration.");return 0;}
            else printf("%d ml. from cup #%d to cup #%d.",v[SZ(v)-1].amount-mid,v[0].indx,v[SZ(v)-1].indx);
        }
    }
    return 0;
}

