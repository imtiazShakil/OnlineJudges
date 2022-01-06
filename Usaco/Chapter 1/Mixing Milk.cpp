/*
ID: shakil1
PROG: milk
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
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<"c"<<endl
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

struct cow
{
    int per,gallon;
};
vector<cow>v;

bool com(cow a, cow b)
{
    return (a.per<b.per);
}

int main(void)
{
    freopen("milk.in","r",stdin);
    freopen("milk.out","w+",stdout);

    cow tmp;
    int milk,farmer;
    int sum=0,price=0;
    scanf("%d %d",&milk,&farmer);
//    cin>>milk>>farmer;
    while(farmer--)
    {
        cin>>tmp.per>>tmp.gallon;
//        scanf("%d %d",&tmp.per,&tmp.gallon);
        v.pb(tmp);
//        print2(tmp.per,tmp.gallon);
    }
//    sort(&v[0],&v[0]+(int)v.size(),com);
    sort(all(v),com);
//    print1(SZ(v));
//    for(int i=0;i<SZ(v);i++) print2(v[i].per,v[i].gallon);

    for(int i=0;i<SZ(v);i++)
    {
        if(sum<milk)
        {
            price+=(min(v[i].gallon,milk-sum)*v[i].per);
            sum+=(min(v[i].gallon,milk-sum));
        }
        else break;
    }
    print1(price);

    return 0;
}

