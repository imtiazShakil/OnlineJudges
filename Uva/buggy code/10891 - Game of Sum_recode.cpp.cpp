#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stdlib.h>
#include <string.h>

#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
#define oo (1LL<<25)
#define mp make_pair

using namespace std;

vector<int>arr;
ll tot;
//ll dp[120][120][2];
map< pair<pair<ll,ll>,int> , ll >M;


ll rec(int start,int end,ll sum_a,ll sum_b,int turn)
{
//    cout<<"st "<<start <<" end "<<end<<" sum_a "<<sum_a<<" turn "<<turn<<endl;
    if( start>end )
    {
//        cout<<"st "<<start <<" end "<<end<<" sum_a "<<sum_a<<" sum_b "<<(tot-sum_a)<<" turn "<<turn<<" ret "<<(sum_a- (tot-sum_a))<<endl;
        return (sum_a- (tot-sum_a));
    }
    int i;
    if( M.find( mp( mp(sum_a,sum_b)   ,turn)  )  !=M.end() ) return M[mp( mp(sum_a,sum_b)   ,turn) ];
//    ll ret=dp[start][end][turn];

//    if(ret!=-1) return ret;
    ll ret;

    if(turn==0) ret=0;
    else ret=oo;

    ll sum=0;
    for(i=start;i<=end;i++)
    {
        sum+=arr[i];
        if(turn==0)
        {
            ret=max(ret,rec(i+1,end,sum+sum_a,sum_b, !turn));
        }
        else ret=min(ret,rec(i+1,end,sum_a,sum_b+sum,!turn));
    }
    sum=0;
    for(i=end;i>start;i--)
    {
        sum+=arr[i];
        if(turn==0)
        {
            ret=max(ret,rec(start,i-1,sum+sum_a,sum_b,!turn));
        }
        else ret=min(ret,rec(start,i-1,sum_a, sum+sum_b, !turn));
    }
//    cout<<" returned "<<ret<<endl;
//    cout<<"st "<<start <<" end "<<end<<" sum_a "<<sum_a<<" sum_b "<<(tot-sum_a)<<" turn "<<turn<<" ret "<<(sum_a- (tot-sum_a))<<endl;
    M[mp( mp(sum_a,sum_b)   ,turn) ]=ret;
    return ret;
}
int main(void)
{
    int n,i,val;
    ll  ans;
    while(scanf("%d",&n)==1 && n)
    {
        arr.clear();tot=0;
        for(i=0;i<n;i++) {scanf("%d",&val);tot+=val;arr.push_back(val);}
//        mem(dp,-1);
        M.clear();
        ans=rec(0,n-1,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}

