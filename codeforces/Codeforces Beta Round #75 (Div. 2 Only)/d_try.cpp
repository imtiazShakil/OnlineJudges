#include <iostream>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

#define mp make_pair
#define pb push_back

using namespace std;

struct data
{
    int indx;
    int val;
};
vector<data>v;

bool com(data    a,data b)
{
    {if(a.val<b.val) return true;else return false;}
}

int main(void)
{
    int n,i,j,val,mx_indx;
    data tmp;v.clear();
    vector<int>ques;ques.clear();
    vector<int>sol;sol.clear();

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&val);
        ques.pb(val);
        tmp.indx=i;tmp.val=val;
        v.pb(tmp);
    }
    sort(v.begin(),v.end(),com);
//    for(i=0;i<v.size();i++) cout<<v[i].indx<<" "<<v[i].val<<endl;

    for(i=0;i<n;i++)
    {
        mx_indx=-1;
        for(j=0;j<n;j++)
        {
            if(ques[i]>v[j].val)
            {
                mx_indx=max(mx_indx,v[j].indx-i-1);
            }
            else break;
        }
        sol.pb(mx_indx);
    }

    for(int i=0;i<n;i++)
    {
        if(i)cout<<" "<<sol[i];
        else cout<<sol[i];
    }
    puts("");


    return 0;
}
