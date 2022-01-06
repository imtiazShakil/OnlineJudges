#include <iostream>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <map>

#define mp make_pair
#define pb push_back

using namespace std;

struct data
{
    int indx;
    int val;

    bool operator<(const data & x)const
	{
		return val>x.val;                    ///for minimum_priority queue
	}
};
priority_queue<data>Q;


int main(void)
{
    int n,val;
    data tmp;
    vector<int>v;v.clear();
    while(!Q.empty() ) Q.pop();
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        tmp.indx=i;
        scanf("%d",&val);
        v.push_back(val);
        tmp.val=val;
        Q.push(tmp);
    }
    map<pair<int,int>,int>M;M.clear();
    vector<int>sol;sol.clear();

    for(int i=0;i<n;i++)
    {
        tmp=Q.top();
        while( M.find( mp(tmp.val,tmp.indx) ) !=M.end())
        {
            Q.pop();
            tmp=Q.top();
        }
//        cout<<"tmp val "<<tmp.val<<" indx "<<tmp.indx<<endl;
        sol.pb(tmp.indx-i-1);
        M[ mp(v[i],i) ] =1;
    }
    for(int i=0;i<n;i++)
    {
        if(i)cout<<" "<<sol[i];
        else cout<<sol[i];
    }
    puts("");
    return 0;
}
