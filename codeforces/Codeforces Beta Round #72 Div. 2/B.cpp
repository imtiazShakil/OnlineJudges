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

//vector<int>v;
map<ll,ll>M;


int main(void)
{
    ll n,i,val,count,sum;
    while(cin>>n)
    {
//        v.clear();
        M.clear();
        for(i=0;i<n;i++)  {cin>>val; M[val]++;}
        count=0;
        for(map<ll,ll>::iterator it=M.begin();it!=M.end();it++)
        {
            if(it->second >1)
            {
                sum=(it->second)*(it->second -1 );
                sum/=2;
                count+=sum;
            }
        }
        count+=n;
        print1(count);
    }
    return 0;
}

