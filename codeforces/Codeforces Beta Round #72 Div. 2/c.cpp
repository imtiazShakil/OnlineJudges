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

using namespace std;
int hits[10005];

struct circle
{

    double x,y,rad;
    int hit_id,org_indx;
} ;

struct point
{
    double x,y;
} ;


vector<circle>v;
vector<point>v_p;

double dist(circle a ,point b)
{
    double tmp;
    tmp=sqrt( (b.x-a.x)*(b.x-a.x)  + b.y*b.y) ;
    return tmp;
}
int com1(circle a,circle b)
{
    if(a.x<b.x) return true;
    else return false;
}

int com2(circle a,circle b)
{
    if(a.org_indx<b.org_indx) return true;
    else return false;
}

int sol(circle  a,point b)
{
//    cout<<"circle "<<a.org_indx<<" point "<<b.x<<"  "<<b.y<<endl;
    double dst=dist(a,b);

    if(dst<a.rad || (dst-a.rad)<0.001 ) return 0;
    else if(b.x> (a.x+a.rad) ) return 1;
    else if(b.x < a.x-a.rad ) return -1;
    else if(a.x-a.rad <= b.x && b.x <= a.x+a.rad ) return 0;
}

int bin_srch(int low,int high,point bullet)
{
    int mid=(low+high)/2;
    int val;
    while(high>=low)
    {
        val=sol(v[mid],bullet);
//        cout<<"val "<<val<<endl;
        if(val==0 ) break ;
        if(val>0) low=mid+1;
        if(val<0) high=mid-1;

        mid=(low+high)/2;
    }
//    cout<<"mid "<<mid<<endl;
    return mid;
}
int main(void)
{
    int n,i,j,m,indx,tot_hit;
    circle tmp;point tmp1;
    double dst;
//    tmp.y=0.0;tmp.hit_id=-1;

    while(scanf("%d",&n)==1)
    {
        v.clear();v_p.clear();
        tmp.y=0.0;tmp.hit_id=-1;
        for(i=0;i<n;i++)
        {
            tmp.org_indx=i;
//            cin>>tmp.x>>tmp.rad;
            scanf("%lf %lf",&tmp.x,&tmp.rad);
            v.pb(tmp);
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
//            cin>>tmp1.x>>tmp1.y;
            scanf("%lf %lf",&tmp1.x,&tmp1.y);
            v_p.pb(tmp1);
        }

        sort(v.begin(),v.end(),com1);

//        puts("sorted");
//        for(i=0;i<n;i++) print3(v[i].x,v[i].y,v[i].org_indx);


        tot_hit=0;
        for(i=0;i<m;i++)
        {
            indx=bin_srch(0,(int)v.size()-1,v_p[i]);
            dst=dist(v[indx],v_p[i]);
//            cout<<i<<" dst "<<dst<<endl;

            if(dst<v[indx].rad || (dst-v[indx].rad)<0.001 )
            {
                if(v[indx].hit_id== -1 ) {v[indx].hit_id=i+1;tot_hit++;}

                if( indx+1 < (int)v.size() )
                {
                    dst=dist(v[indx+1],v_p[i]);
                    if(dst<v[indx+1].rad || (dst-v[indx+1].rad)<0.001 )
                    {
                        if(v[indx+1].hit_id== -1 ) {v[indx+1].hit_id=i+1;tot_hit++;}
                    }
                }

                if(indx-1 >=0 )
                {
                    dst=dist(v[indx-1],v_p[i]);
                    if(dst<v[indx-1].rad || (dst-v[indx-1].rad)<0.001 )
                    {
                        if(v[indx-1].hit_id== -1 ) {v[indx-1].hit_id=i+1;tot_hit++;}
                    }
                }
            }
        }

//        for(i=0;i<n;i++) print3(v[i].x,v[i].y,v[i].hit_id);

//        sort(v.begin(),v.end(),com2);

//        puts("returned 2 normal");
//        for(i=0;i<n;i++) print3(v[i].x,v[i].y,v[i].hit_id);
        for(i=0;i<n;i++)
        {
            hits[v[i].org_indx]=v[i].hit_id;
        }


        print1(tot_hit);
        for(i=0;i<n;i++)
        {
            if(i) cout<<" "<<hits[i];
            else cout<<hits[i];
        }
        puts("");
    }
    return 0;
}

