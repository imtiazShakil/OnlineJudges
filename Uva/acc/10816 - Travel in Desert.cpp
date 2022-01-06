#include  <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include  <stdlib.h>
#include <math.h>

#define MAX 120
#define oo 9999999.0
#define pb push_back

using namespace std;

int n,e;

double temp[MAX];
double dst[MAX];
int parent[MAX];
double max_temp;

struct data1
{
    int node;
    double  temp;

    bool operator<(const data1 & x)const
	{
//	    if(temp!=x.temp) return temp>x.temp;
//		else
		return temp>x.temp;                    ///for minimum_priority queue
	}
};


struct data2
{
    int node;
    double  dist;
    bool operator<(const data2 & x)const
	{
		return dist>x.dist;                    ///for minimum_priority queue
	}
};

struct path
{
    int to;
    double temp,dist;
};

vector<path>v[MAX];
vector<int>pt;
bool relax_temp(int u,int v1,double tmpp)
{
    if(temp[v1]>max(temp[u],tmpp) )
    {
        temp[v1]=max(temp[u],tmpp);
        return true;
    }
    return false;
}
bool relax_dist(int u,int v1,double tmpp,double dstt)
{
//        if( (max_temp-tmpp)>=0.0000001 )
        if(max_temp-tmpp>0.0 || fabs(max_temp-tmpp)<=0.0000001 )
        {
            if( dst[u]+dstt<dst[v1] )
            {
                dst[v1]=dst[u]+dstt;
                parent[v1]=u;
    //            temp[v1]=max(temp[u],tmpp);///not needed
                return true;
            }
            else return false;
        }
        return false;

}
void dijkstra_dist(int source)
{
    int i,j;
    for(i=1;i<=n;i++) {dst[i]=oo;parent[i]=0;}
    dst[source]=0.0;
    data2 tmp,tmp2;
    map<int,int>M;
    priority_queue<data2>Q;
    tmp.dist=0.0;tmp.node=source;
    Q.push(tmp);
    while(!Q.empty())
    {
        tmp=Q.top();Q.pop();
        if(M.find(tmp.node)==M.end())
        {
            M[tmp.node]=1;
            for(int i=0;i<(int)v[tmp.node].size();i++)
            {
                if( relax_dist(tmp.node,v[tmp.node][i].to,v[tmp.node][i].temp,v[tmp.node][i].dist ) )
                {
                    tmp2.node=v[tmp.node][i].to;
                    tmp2.dist=dst[ v[tmp.node][i].to ];
//                    tmp2.temp=temp[ v[tmp.node][i].to ];
                    Q.push(tmp2);
//                    cout<<"dist "<<v[tmp.node][i].to<<endl;
                }
            }
        }
    }
}



double dijkstra_min_temp(int source,int end)
{
    int i,j;
    for(i=1;i<=n;i++) temp[i]=oo;
    temp[source]=0.0;
    data1 tmp,tmp2;
    map<int,int>M;
    priority_queue<data1>Q;
    tmp.node=source;tmp.temp=0.0;
    Q.push(tmp);
    while(!Q.empty())
    {
        tmp=Q.top();Q.pop();
        if( M.find(tmp.node)==M.end() )
        {
            M[tmp.node]=1;
            for(i=0;i<(int)v[tmp.node].size();i++)
            {
                if(relax_temp(tmp.node,v[tmp.node][i].to,v[tmp.node][i].temp ) )
                {
                    tmp2.node=v[tmp.node][i].to;
                    tmp2.temp=temp[v[tmp.node][i].to];
                    Q.push(tmp2);
                }
            }
        }
    }
    return temp[end];
}
void path_finder(int end)
{
    int node=end;pt.clear();pt.pb(end);
    while( parent[node]!=0 )
    {
        node=parent[node];
        pt.pb(node);
    }
    return ;
}
int main(void)
{
    int i,k,j,u,v1,start,end;
    path tmp;
    while(scanf("%d %d",&n,&e)==2)
    {
        scanf("%d %d",&start,&end);
        for(i=1;i<=n;i++) v[i].clear();
        for(i=0;i<e;i++)
        {
            scanf("%d %d %lf %lf",&u,&v1,&tmp.temp,&tmp.dist);
            tmp.to=v1;v[u].pb(tmp);
            tmp.to=u;v[v1].pb(tmp);
        }
        max_temp=dijkstra_min_temp(start,end);
//        cout<<max_temp<<endl;

        dijkstra_dist(start);


        path_finder(end);
        for(i=(int)pt.size()-1;i>=0;i--)
        {
            if(i== (int)pt.size()-1 ) cout<<pt[i];
            else cout<<" "<<pt[i];
        }
//        cout<<"\ntmp "<<temp[end]<<" dst "<< dst[end]<<endl;

        printf("\n%.1lf %.1lf\n",dst[end],max_temp);
//        cout<<"\n"<<dst[end]<<" "<<max_temp<<endl;
    }

    return 0;
}
