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
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<endl
#define PI (2*acos(0))
#define ERR 1e-5
#define ll long long
#define VI vector<int>
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back

using namespace std;


int main(void)
{
    int n,m,k,val,low,op;
    vector<int>v;
    vector<int>p;
    while(scanf("%d %d %d",&n,&m,&k)==3)
    {
        v.clear();//p.clear();

        for(int i=0;i<n;i++)
        {
            scanf("%d",&val);
            v.pb(val);
//            p.pb(val);
        }
        if(n==1 ) {cout<<v[0]<<endl;continue;}
        if(n%2 ==0 ) {cout<<0<<endl;continue;}


        op=n-n/2;
        if(op>m) {cout<<0<<endl;continue;}

//        sort(p.begin(),p.end());

        low=v[0];
        for(int i=0;i<n;i+=2)
        {
            low=min(low,v[i]);
        }

        low=min(k,low);
        cout<<low<<endl;


    }
    return 0;
}

