/*
ID: shakil1
PROG: packrec
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
struct rect
{
    int w,h;
};
struct ara
{
    int w,h,area;
};
rect inv;
vector<rect>v[20],org,test[400];
vector<ara>va;
map<paii,bool>M;

char ttt[5];
int indx=0;

void bt(int depth)
{
    if(depth==4)
    {
        for(int i=0;i<4;i++)
        {
            if(ttt[i]=='0')
                v[indx].pb(org[i]);
            else
            {
                inv.h=org[i].w;inv.w=org[i].h;
                v[indx].pb(inv);
            }
        }
//        print2(indx,ttt);
        indx++;
        return ;
    }

    for(int i=0;i<2;i++)
    {
        ttt[depth]=i+'0';
        bt(depth+1);
    }
    return ;
}

void min_area(int len)
{
    int w,h,area,ans_w,ans_h;
    ara tmp;
    for(int i=0;i<len;i++)
    {
        area=oo;
        ///way1
        w=test[i][0].w+test[i][1].w+test[i][2].w+test[i][3].w;
        h=max(test[i][0].h,test[i][1].h);h=max(h,test[i][2].h);h=max(h,test[i][3].h);
        if(w*h<=area)
        {
            ans_w=w;ans_h=h;area=w*h;
            //if(area==36) print1(1);
            tmp.w=min(ans_w,ans_h);
            tmp.h=max(ans_w,ans_h);
            if(M.find(mp(tmp.w,tmp.h)) ==M.end())
            {
                M[mp(tmp.w,tmp.h)]=1;
                tmp.area=area;
                va.pb(tmp);
            }
        }
        ///way2
        w=max(test[i][0].w+test[i][1].w+test[i][2].w,test[i][3].w);
        h=max(test[i][0].h,test[i][1].h);h=max(h,test[i][2].h);
        h+=test[i][3].h;
        if(w*h<=area)
        {
            ans_w=w;ans_h=h;area=w*h;//if(area==36) print1(2);
            tmp.w=min(ans_w,ans_h);
            tmp.h=max(ans_w,ans_h);
            if(M.find(mp(tmp.w,tmp.h)) ==M.end())
            {
                M[mp(tmp.w,tmp.h)]=1;
                tmp.area=area;
                va.pb(tmp);
            }
        }
        ///way3
        w=max(test[i][0].w+test[i][1].w+test[i][3].w,test[i][2].w+test[i][3].w);
        h=max(test[i][0].h,test[i][1].h) + test[i][2].h ; h=max(h,test[i][3].h);
        if(w*h<=area)
        {
            ans_w=w;ans_h=h;area=w*h;//if(area==36) print1(3);
            tmp.w=min(ans_w,ans_h);
            tmp.h=max(ans_w,ans_h);
            if(M.find(mp(tmp.w,tmp.h)) ==M.end())
            {
                M[mp(tmp.w,tmp.h)]=1;
                tmp.area=area;
                va.pb(tmp);
            }
        }
        ///way4
        w=test[i][0].w+max(test[i][1].w,test[i][2].w)+test[i][3].w;
        h=max(test[i][0].h,test[i][3].h);h=max(h,test[i][1].h+test[i][2].h);
        if(w*h<=area)
        {
            ans_w=w;ans_h=h;area=w*h;//if(area==36) print1(4);
            tmp.w=min(ans_w,ans_h);
            tmp.h=max(ans_w,ans_h);
            if(M.find(mp(tmp.w,tmp.h)) ==M.end())
            {
                M[mp(tmp.w,tmp.h)]=1;
                tmp.area=area;
                va.pb(tmp);
            }
        }
        ///way5
        w=max(test[i][0].w,test[i][1].w) + test[i][2].w+test[i][3].w;
        h=max(test[i][0].h+test[i][1].h,test[i][2].h);h=max(h,test[i][3].h);
        if(w*h<=area)
        {
            ans_w=w;ans_h=h;area=w*h;//if(area==36) print1(5);
            tmp.w=min(ans_w,ans_h);
            tmp.h=max(ans_w,ans_h);
            if(M.find(mp(tmp.w,tmp.h)) ==M.end())
            {
                M[mp(tmp.w,tmp.h)]=1;
                tmp.area=area;
                va.pb(tmp);
            }
        }
        ///way6
        if(test[i][0].w+test[i][3].w!=test[i][1].w + test[i][2].w )
        {
            w=max(test[i][0].w,test[i][1].w) + max(test[i][2].w , test[i][3].w) ;
        }
        else
        {
            if(test[i][3].w>test[i][0].w  && test[i][2].h>=test[i][1].h)
            {
                w=test[i][0].w+test[i][3].w;
            }
            else if(test[i][0].w>test[i][3].w && test[i][1].h>=test[i][2].h)
            {
                w=test[i][0].w+test[i][3].w;
            }
            else w=max(test[i][0].w,test[i][1].w) + max(test[i][2].w , test[i][3].w) ;

        }
        h=max(test[i][0].h+test[i][1].h,test[i][2].h+test[i][3].h);

        if(w*h<=area)
        {

            ans_w=w;ans_h=h;area=w*h;//if(area==36) {print1(6);print2(test[i][0].w,test[i][1].w);print2(test[i][2].w,test[i][3].w);print2(test[i][0].h,test[i][1].h);print2(test[i][2].h,test[i][3].h);}
            tmp.w=min(ans_w,ans_h);
            tmp.h=max(ans_w,ans_h);
            if(M.find(mp(tmp.w,tmp.h)) ==M.end())
            {
                M[mp(tmp.w,tmp.h)]=1;
                tmp.area=area;
                va.pb(tmp);
            }
        }


    }
}

bool com(ara a,ara b)
{
    if(a.area!=b.area) return a.area<b.area;
    if(a.w!=b.w) return a.w<b.w;
}

int main(void)
{
    freopen("packrec.in","r",stdin);
    freopen("packrec.out","w+",stdout);
    rect tmp;
    int inx[]={0,1,2,3},p=0;
    for(int i=0;i<4;i++)
    {
        scanf("%d %d",&tmp.w,&tmp.h);
        org.pb(tmp);
    }
    bt(0);

    for(int i=0;i<16;i++)
    {
        do
        {
            for(int q=0;q<4;q++)
            {
                test[p].pb(v[i][inx[q]]);
            }
            ++p;
        }while(next_permutation(inx,inx+4)) ;
    }
    min_area(p);
//    for(map<paii,bool>::iterator it=M.begin(); it!=M.end();it++) print3(it->first.first,it->first.second,(it->first.first)*(it->first.second) ) ;
    sort(all(va),com);
//    for(int i=0;i<SZ(va);i++) print3(va[i].w,va[i].h,va[i].area);
    int mn=va[0].area;
    print1(mn);
    for(int i=0;i<SZ(va);i++)
    {
        if(mn==va[i].area) print2(va[i].w,va[i].h);
        else break;
    }

    return 0;
}

