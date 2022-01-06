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
#define MAX 1000005
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;


bool num[MAX];
//int prime[80000];
paii dp[MAX];
//pair<int,int>val[MAX];
map<int,bool>M;

void seive()
{
	int i,j=0,k;
//	prime[0]=2;
    num[1]=1;
	for(int i=4;i<MAX;i+=2) num[i]=1;

	for(i=3;i<MAX;i+=2)
	{
		if(!num[i])
		{
//			prime[++j]=i;
			if(i<MAX/i) for(k=i*i;k<MAX;k+=i) num[k]=true;
		}
	}
//	printf("total prime %d %d\n",j+1,prime[j]);
}

bool chk(int val)
{
    if( num[val] ) return false;
    else return true;
}

paii rec(int n,bool turn)
{
//    print2(n,turn);

    if(n==0) return mp(0,0);
    if(n==1 && turn==0) return mp(1,0);
    if(n==1 && turn) return mp(0,1);

    paii &ret=dp[n];
    if(ret.fs!=-1 && ret.sc!=-1) return ret;

    ret.fs=0;ret.sc=0;
    paii val;

    if(chk(n))
    {
//        puts("called");
        val=rec(n-1,!turn);
//        print2(val.fs,val.sc);
        if(turn==0) {ret.fs+=(val.fs +1);ret.sc+=val.sc;}
        else {ret.fs+=val.fs; ret.sc+=(val.sc +1);}
    }
    else
    {
        int other,indx1,indx2;
//        vector<paii>ans;
        paii a=mp(0,0),b=mp(0,0),c=mp(0,0),d=mp(0,0);

        for(int i=2;i<=n/i;i++)
        {
            if(n%i==0)
            {
                other=n/i;
                val=rec(i,!turn);
                if(val.fs>a.fs)
                {
                    a.fs=val.fs;a.sc=val.sc;
                }
                else if(val.sc>b.sc)
                {
                    b.fs=val.fs;b.sc=val.sc;
                }

                val=rec(other,!turn);


                if(val.fs>c.fs)
                {
                    c.fs=val.fs;c.sc=val.sc;
                }
                else if(val.sc>d.sc)
                {
                    d.fs=val.fs;d.sc=val.sc;
                }

//                printf("now %d turn %d   %d - %d\n",n,turn,n/i,other );
//                print3("a  ",a.fs,a.sc);
//                print3("b  ",b.fs,b.sc);
//                print3("c  ",c.fs,c.sc);
//                print3("d  ",d.fs,d.sc);

            }
        }
        if(turn==0)
        {
            ret.fs+=(a.fs+c.fs);ret.sc+=(a.sc+c.sc);
        }
        else {ret.fs+=(b.fs+d.fs);ret.sc+=(b.sc+d.sc);}
    }
    return ret;

}

int main(void)
{

    int loop,val;
    paii ans;
    seive();
    scanf("%d",&loop);
    for(int i=0;i<MAX;i++) dp[i]=mp(-1,-1);

    while(loop--)
    {
        scanf("%d",&val);
//        for(int i=0;i<MAX;i++) dp[i]=mp(-1,-1);
        ans=rec(val,0);
        print2(ans.fs,ans.sc);
    }

    return 0;
}
