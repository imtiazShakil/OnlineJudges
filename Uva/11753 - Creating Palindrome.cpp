#include <stdio.h>
#include <iostream>
#include <vector>
#define oo (1<<15)
using namespace std;
int n;
vector<int>v;
int rec(int i,int j)
{
    int ret,val;
    if(i==((int)v.size())/2 &&  j==((int)v.size())/2 -1  ) return 0;
    if(i>((int)v.size())/2 || j<((int)v.size())/2 -1 ) return oo;

    ret=oo;
    if(v[i]==v[j] && i!=j ) ret=min(ret,rec(i+1,j-1) );
    else
    {
        val=min(rec(i+1,j) + 1, rec(i,j-1) +1);
        ret=min(ret,val);
    }

    return ret;
}
int main(void)
{
    int loop,k,i,val,ans,cas=0;
    scanf("%d",&loop);
    while(loop--)
    {
        v.clear();
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++) {scanf("%d",&val);v.push_back(val);}
        ans=rec(0,(int)v.size()-1);

//        cout<<"org_ans "<<ans<<endl;
        if(ans) ans--;

        if(ans==0) {printf("Case %d: Too easy\n",++cas);continue;}
        else if(ans>k) {printf("Case %d: Too difficult\n",++cas);continue;}
        else {printf("Case %d: %d\n",++cas,ans);continue;}


    }

    return 0;
}
