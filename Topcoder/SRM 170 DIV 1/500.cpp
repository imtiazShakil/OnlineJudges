#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define pb push_back
#define MAX 10000
using namespace std;

struct edge
{
    int u;
    int v;
    int weight;
};

vector<edge>v;
int parent[MAX];
int rank[MAX];

void make_set(int x)
{
    rank[x]=0;
    parent[x]=x;
    return ;
}
int find_set(int x)
{
    if(parent[x]!=x) parent[x]=find_set(parent[x]);
//    parent[x]=x;
    return parent[x];
}
void link(int x,int y)
{
    if(rank[x]>rank[y])
        parent[y]=x;
    else parent[x]=y;

    if(rank[x]==rank[y])
        rank[y]++;
}
void u_nion(int x,int y)
{
    link(find_set(x),find_set(y));
    return ;
}
bool com(edge a,edge b)
{
    if(a.weight<b.weight) return true;
    else return false;
}

class CityLink
{
public:
	int timeTaken(vector <int> x, vector <int> y)
	{
        v.clear();
        edge tmp;
        int dist;
        for(int i=0;i<(int)x.size();i++)
            for(int j=i+1;j<(int)x.size();j++)
            {
                tmp.u=i;
                tmp.v=j;
                dist=max(abs(x[i]-x[j]),abs(y[i]-y[j] )  );
                if(x[i]==x[j] || y[i]==y[j] )
                {
                    if(dist%2) dist++;
                    dist/=2;
                }
                tmp.weight=dist;
                v.pb(tmp);
            }
        sort(v.begin(),v.end(),com);
        int mx_tm=0;
        for(int i=0;i<=(int)x.size();i++) make_set(i);

        for(int i=0;i<(int)v.size();i++)
        {
            if(find_set(v[i].u)!=find_set(v[i].v))
            {
                u_nion(v[i].u,v[i].v);
                mx_tm=max(mx_tm,v[i].weight );
            }
        }
        return mx_tm;
	}
};


template<typename T> void print( T a ) {
    cerr << a;
}

void print( long long a ) {
    cerr << a << "L";
}

void print( string a ) {
    cerr << '"' << a << '"';
}

template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}

template<typename T> void assert_eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

template<typename T> void assert_eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
void assert_eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

int main( int argc, char* argv[] )
{

//	CityLink objectCityLink;
//
//	//test case0
//	vector <int> param00;
//	param00.push_back(0);
//	param00.push_back(5);
//	vector <int> param01;
//	param01.push_back(0);
//	param01.push_back(5);
//	param01.push_back();
//	param01.push_back(Returns:);
//	param01.push_back(5);
//	param01.push_back(The);
//	param01.push_back(road);
//	param01.push_back(north);
//	param01.push_back(from);
//	param01.push_back((0);
//	param01.push_back(0));
//	param01.push_back(will);
//	param01.push_back(intersect);
//	param01.push_back(the);
//	param01.push_back(road);
//	param01.push_back(west);
//	param01.push_back(from);
//	param01.push_back((5);
//	param01.push_back(5));
//	param01.push_back(at);
//	param01.push_back(t);
//	param01.push_back(=);
//	param01.push_back(5.);
//	param01.push_back(1));
//	param01.push_back(    );
//	param01.push_back(0);
//	param01.push_back(0);
//	int ret0 = objectCityLink.timeTaken(param00,param01);
//	int need0 = 5;
//	assert_eq(0,ret0,need0);

}

