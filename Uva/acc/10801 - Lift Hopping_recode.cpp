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
struct path
{
    int src_lft,to,dest_lft;
};

vector< path >vp[120];

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
//            cout<<"floor "<<tmp.flor<<" lift "<<tmp.lift<<" tm "<<tmp.tm<<endl;
            M[mp( tmp.flor,tmp.lift )]=1;
            for(i=0;i<(int)vp[tmp.flor].size();i++ )
            {
                if( vp[tmp.flor][i].to==tmp.flor &&  vp[tmp.flor][i].dest_lft==tmp.lift ) continue;
                flag=0;
                if(tmp.lift!= vp[tmp.flor][i].dest_lft ) flag=1;
                if( relax(tmp.flor,vp[tmp.flor][i].to,flag,vp[tmp.flor][i].src_lft,vp[tmp.flor][i].dest_lft ) )
                {
                    tmp2.flor=vp[tmp.flor][i].to;
                    tmp2.lift=vp[tmp.flor][i].dest_lft;
                    tmp2.tm=tim_e[ vp[tmp.flor][i].to ][ vp[tmp.flor][i].dest_lft ];
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
    path tmp;
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

                if( j-1>=0 )
                {
                    tmp.src_lft=i;tmp.dest_lft=i;tmp.to=v[i][j-1];
                    vp[v[i][j]].pb(tmp);
                }
                if( j+1<(int)v[i].size() )
                {
                    tmp.src_lft=i;tmp.dest_lft=i;tmp.to=v[i][j+1];
                    vp[v[i][j]].pb(tmp);
//                       vp[v[i][j]].pb( mp(v[i][j+1],i ) );
                }
                for(int q=i+1;q<n;q++)
                    if( M[q].find(v[i][j])!=M[q].end() )
                    {
                        tmp.src_lft=i;tmp.dest_lft=q;tmp.to=v[i][j];
//                        vp[v[i][j]].pb( mp( v[i][j] , q ) );
                        vp[v[i][j]].pb(tmp);
                    }

                for(int q=i-1;q>=0;q--)
                    if( M[q].find(v[i][j])!=M[q].end() )
                    {
                        tmp.src_lft=i;tmp.dest_lft=q;tmp.to=v[i][j];
                        vp[v[i][j]].pb(tmp);
                    }

            }

        }
//        for(i=0;i<=30;i++)
//        {
//            for(j=0;j<(int)vp[i].size();j++) cout<<"floor "<<i<<" in "<<vp[i][j].src_lft<<" to "<<vp[i][j].to<<" using lift "<<vp[i][j].dest_lft<<endl;
//        }

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
        if(min_tm>=oo) puts("IMPOSSIBLE");
        else printf("%d\n",min_tm);
//        cout<<min_tm<<endl;
    }
    return 0;
}

