#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <stdlib.h>

#define pb push_back
#define mp make_pair
#define oo (1<<25)
#define MAX 10

using namespace std;

vector<int>tm;
vector< pair<int,int> >vp[120];
int tim_e[120][MAX]; ///pair<flor,lift>

struct data
{
    int flor;
    int  tm;
    int lift;
    bool operator<(const data & x)const
	{
		return tm>x.tm;                    ///for minimum_priority queue
	}
};

bool relax(int u,int v,int diff,int lift1,int lift2)
{
    if( tim_e[v][lift2] > tim_e[u][lift1] + abs(u-v)*tm[lift1] +diff*60 )
    {
        tim_e[v][lift2]=tim_e[u][lift1] + abs(u-v)*tm[lift1] +diff*60;
        return true;
    }
    return false;
}

void dikstra(int flor,int lift)
{
    int i,j;
    for(i=0;i<120;i++) {tim_e[i][0]=oo;tim_e[i][1]=oo;tim_e[i][2]=oo;tim_e[i][3]=oo;tim_e[i][4]=oo;}
    tim_e[flor][lift]=0;
    data tmp,tmp2;
    priority_queue<data>Q;
    tmp.flor=flor;tmp.tm=0;tmp.lift=lift;
    Q.push(tmp);
    map< pair<int,int> ,int >M; ///pair< flor,lift >
    int flag=0;
    while(!Q.empty())
    {
        tmp=Q.top();Q.pop();
        if(M.find(mp( tmp.flor,tmp.lift ) )==M.end())
        {
            cout<<"floor "<<tmp.flor<<" lift "<<tmp.lift<<" tm "<<tmp.tm<<endl;
            M[mp( tmp.flor,tmp.lift )]=1;
            for(i=0;i<(int)vp[tmp.flor].size();i++ )
            {
                if( vp[tmp.flor][i].first==tmp.flor &&  vp[tmp.flor][i].second==tmp.lift ) continue;
                flag=0;
                if(tmp.lift!= vp[tmp.flor][i].second ) flag=1;
                if( relax(tmp.flor,vp[tmp.flor][i].first,flag,tmp.lift,vp[tmp.flor][i].second ) )
                {
                    tmp2.flor=vp[tmp.flor][i].first;
                    tmp2.lift=vp[tmp.flor][i].second;
                    tmp2.tm=tim_e[ vp[tmp.flor][i].first ][ vp[tmp.flor][i].second ];
                    Q.push(tmp2);
                }
            }
        }
    }
}
int main(void)
{
    int n,k,i,j,val,p,min_tm;
    vector<int>v[MAX];
    map<int,int>M[MAX];
    string str;
    stringstream ss;

    while(scanf("%d %d",&n,&k)==2)
    {
        tm.clear();
        for(i=0;i<n;i++) {scanf("%d ",&val);tm.pb(val);v[i].clear();M[i].clear();}

        for(i=0;i<n;i++)
        {
            getline(cin,str);
            ss.clear();
            ss<<str;
            while( ss>>val )     { v[i].pb(val);M[i][val]=1; }
        }
        for(i=0;i<120;i++) vp[i].clear();

        for(i=0;i<n;i++)
        {
            for(j=0;j<(int)v[i].size();j++)
            {

                if( j-1>=0 )   vp[v[i][j]].pb( mp( v[i][j-1],i ) );
                if( j+1<(int)v[i].size() )   vp[v[i][j]].pb( mp(v[i][j+1],i ) );
                for(int q=i+1;q<n;q++)
                    if( M[q].find(v[i][j])!=M[q].end() ) vp[v[i][j]].pb( mp( v[i][j] , q ) );

                for(int q=i-1;q>=0;q--)
                    if( M[q].find(v[i][j])!=M[q].end() ) vp[v[i][j]].pb( mp( v[i][j] , q ) );

            }

        }
        for(i=0;i<=30;i++)
        {
            for(j=0;j<(int)vp[i].size();j++) cout<<"floor "<<i<<" to "<<vp[i][j].first<<" using lift "<<vp[i][j].second<<endl;
        }

        for(i=0,min_tm=oo;i<n;i++)
        {
            if( v[i][0] ==0 )
            {
                dikstra(0,i);
                for(j=0;j<n;j++)
                {
                    min_tm=min(min_tm,tim_e[k][j]);
                }
            }
        }
        cout<<min_tm<<endl;
    }
    return 0;
}
