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

stack<ll>S;

ll chk(ll count)
{
    ll sum=count*(count-1);
    sum/=2;
    return sum;
}
int main(void)
{
    ll n,i,val,count,sum,prv;
    while(cin>>n)
    {
        while(!S.empty()) S.pop();
        count=0;
        prv=0;
        sum=0;
        for(i=0;i<n;i++)
        {
            cin>>val;

            if(S.empty()) S.push(val);
            else if(S.top()==val)
            {
                S.push(val);
            }
            else
            {
                if((int)S.size()>1) count+=chk((int)S.size());
                while(!S.empty()) S.pop();
                S.push(val);
            }

        }

        if((int)S.size()>1) count+=chk((int)S.size());

        count+=n;
        print1(count);
    }
    return 0;
}

