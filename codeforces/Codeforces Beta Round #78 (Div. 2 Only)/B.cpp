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
map<paii,int>M;
map<int,int>M2;
int main(void)
{

    int n,val,indx=1,itm;
    scanf("%d",&n);itm=n;
    int sum=0;
    while(n--)
    {
        scanf("%d",&val);
        M[mp(val,indx)]++;
        M2[val]++;
        indx++;
        sum+=val;
    }
    if(SZ(M2)==1) puts("Exemplary pages.");
    else if(SZ(M2)>3) puts("Unrecoverable configuration.");
    else
    {
        sum/=itm;
        int from,to ,diff,val2,val3;

        for(map<paii,int>::iterator i=M.begin();i!=M.end();i++)
        {
            if(i->first.first>sum) {to=i->first.second;val2=i->first.first;}
            else if(i->first.first<sum) {from=i->first.second;val3=i->first.first;}
//            print2(i->first.first,i->first.second);
        }
        printf("%d ml. from cup #%d to cup #%d.\n",val2-sum,from,to);
    }
    return 0;
}

