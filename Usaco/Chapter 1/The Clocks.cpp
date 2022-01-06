/*
ID: shakil1
PROG: clocks
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
#define MAX 100000
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,n) for(int i=1;i<=n;i++)

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

vector<int>move[9];
vector<int>org_clck;
vector<string>v;
string ans;

vector<int> op(int mov,vector<int>clk)
{
    for(int i=0;i<SZ(move[mov]);i++)
    {
        if(clk[move[mov][i]]<12) clk[move[mov][i]]+=3;
        else clk[move[mov][i]]=3;
    }
    return clk;
}
bool chk(vector<int>clk)
{
    for(int i=0;i<9;i++)  if(clk[i]!=12) return false;
    return true;
}

int main(void)
{
    int indx,i,j,k,l,m,n,o,p,q,val;
    move[0].pb(0);move[0].pb(1);move[0].pb(3);move[0].pb(4);
    move[1].pb(0);move[1].pb(1);move[1].pb(2);
    move[2].pb(1);move[2].pb(2);move[2].pb(4);move[2].pb(5);
    move[3].pb(0);move[3].pb(3);move[3].pb(6);
    move[4].pb(1);move[4].pb(3);move[4].pb(4);move[4].pb(5);move[4].pb(7);
    move[5].pb(2);move[5].pb(5);move[5].pb(8);
    move[6].pb(3);move[6].pb(4);move[6].pb(6);move[6].pb(7);
    move[7].pb(6);move[7].pb(7);move[7].pb(8);
    move[8].pb(4);move[8].pb(5);move[8].pb(7);move[8].pb(8);

    freopen("clocks.in","r",stdin);
    freopen("clocks.out","w+",stdout);
    rep(i,9) {scanf("%d",&val);org_clck.pb(val);}

    string str[9];
    vector<int>tmp_clk[9];
    tmp_clk[0]=org_clck;

    for(i=0,indx=0;i<4;i++,indx=0)
    {
        str[indx].clear();
        tmp_clk[indx]=org_clck;
        rep2(t,i)
        {
            str[indx]+=indx+1+'0';
            tmp_clk[indx]=op(indx,tmp_clk[indx]);
        }

        for(j=0,indx=1;j<4;j++,indx=1)
        {
            str[indx].clear();tmp_clk[indx]=tmp_clk[indx-1];
            rep2(t,j)
            {
                str[indx]+=indx+1+'0';
                tmp_clk[indx]=op(indx,tmp_clk[indx]);
            }
            for(k=0,indx=2;k<4;k++,indx=2)
            {
                str[indx].clear();tmp_clk[indx]=tmp_clk[indx-1];
                rep2(t,k)
                {
                    str[indx]+=indx+1+'0';
                    tmp_clk[indx]=op(indx,tmp_clk[indx]);
                }
                for(l=0,indx=3;l<4;l++,indx=3)
                {
                    str[indx].clear();tmp_clk[indx]=tmp_clk[indx-1];
                    rep2(t,l)
                    {
                        str[indx]+=indx+1+'0';
                        tmp_clk[indx]=op(indx,tmp_clk[indx]);
                    }
                    for(m=0,indx=4;m<4;m++,indx=4)
                    {
                        str[indx].clear();tmp_clk[indx]=tmp_clk[indx-1];
                        rep2(t,m)
                        {
                            str[indx]+=indx+1+'0';
                            tmp_clk[indx]=op(indx,tmp_clk[indx]);
                        }
                        for(n=0,indx=5;n<4;n++,indx=5)
                        {
                            str[indx].clear();tmp_clk[indx]=tmp_clk[indx-1];
                            rep2(t,n)
                            {
                                str[indx]+=indx+1+'0';
                                tmp_clk[indx]=op(indx,tmp_clk[indx]);
                            }
                            for(o=0,indx=6;o<4;o++,indx=6)
                            {
                                str[indx].clear();tmp_clk[indx]=tmp_clk[indx-1];
                                rep2(t,o)
                                {
                                    str[indx]+=indx+1+'0';
                                    tmp_clk[indx]=op(indx,tmp_clk[indx]);
                                }
                                for(p=0,indx=7;p<4;p++,indx=7)
                                {
                                    str[indx].clear();tmp_clk[indx]=tmp_clk[indx-1];
                                    rep2(t,p)
                                    {
                                        str[indx]+=indx+1+'0';
                                        tmp_clk[indx]=op(indx,tmp_clk[indx]);
                                    }
                                    for(q=0,indx=8;q<4;q++,indx=8)
                                    {
                                        str[indx].clear();tmp_clk[indx]=tmp_clk[indx-1];
                                        rep2(t,q)
                                        {
                                            str[indx]+=indx+1+'0';
                                            tmp_clk[indx]=op(indx,tmp_clk[indx]);
                                        }
                                        ans.clear();
//                                        rep(xx,9) ans+=str[xx];
//                                        print1(ans);
                                        if( chk(tmp_clk[indx]) )
                                        {
//                                            puts("found 1");
                                            ans.clear();
                                            rep(xx,9) ans+=str[xx];
                                            v.pb(ans);
                                        }

                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    sort(all(v));
//    print1(SZ(v));
    if(SZ(v))
    {
        for(i=0;i<SZ(v[0]);i++)
        {
            if(i) printf(" %c",v[0][i]);
            else printf("%c",v[0][i]);
        }
        puts("");
    }

    return 0;
}


