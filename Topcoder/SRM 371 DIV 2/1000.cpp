
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
#define mp make_pair

using namespace std;

vector<string>mat;
map<pair<int,int>,int>M;

int rrr[]={-1,0,1,0};
int ccc[]={0,1,0,-1};

void dfs(int row,int col)
{
    M[mp(row,col)]=1;
//    for(int i=row,j=col)
    int p,q;
    for(int i=0;i<4;i++)
    {
        p=row+rrr[i];q=col+ccc[i];
        if( p>=0 && q>=0 && p<(int)mat.size() && q<(int)mat[0].size() )
        {
            if(mat[p][q]>=mat[row][col] && M.find( mp(p ,q ))==M.end() )
                dfs(p,q);
        }
    }
    return ;
}

class FloodRelief
{
public:
	int minimumPumps(vector <string> heights)
	{
        mat.clear();mat=heights;
        M.clear();
        vector< pair<int,int> >s;
        s.clear();
        int count;
        for(int i=0;i<(int)heights.size();i++)
        {
            for(int j=0;j<(int)heights[i].size();j++)
            {
                if(M.find(mp(i,j))==M.end() )
                {
                    dfs(i,j);s.pb(mp(i,j));
                }
            }
        }
        count=0;M.clear();
        for(int i=(int)s.size()-1;i>=0;i--)
        {
            if( M.find(mp(s[i].first,s[i].second))==M.end() )
            {
                dfs(s[i].first,s[i].second);count++;
            }
        }
        return count;

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

	FloodRelief objectFloodRelief;

	//test case0
	vector <string> param00;
	param00.push_back("ccccc");
	param00.push_back("cbbbc");
	param00.push_back("cbabc");
	param00.push_back("cbbbc");
	param00.push_back("ccccc");
	int ret0 = objectFloodRelief.minimumPumps(param00);
	int need0 = 1;
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back("cbabcbabc");
	param10.push_back("cbabcbabc");
	param10.push_back("cbabcbabc");
	param10.push_back("cbabcbabc");
	int ret1 = objectFloodRelief.minimumPumps(param10);
	int need1 = 2;
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back("ccccccccccc");
	param20.push_back("caaaaaaaaac");
	param20.push_back("caaaaaaaaac");
	param20.push_back("caazpppzaac");
	param20.push_back("caapdddpaac");
	param20.push_back("caapdddpaac");
	param20.push_back("caapdddpaac");
	param20.push_back("caazpppzaac");
	param20.push_back("caaaaaaaaac");
	param20.push_back("caaaaaaaaac");
	param20.push_back("ccccccccccc");
	int ret2 = objectFloodRelief.minimumPumps(param20);
	int need2 = 2;
	assert_eq(2,ret2,need2);

	//test case3
	vector <string> param30;
	param30.push_back("ab");
	param30.push_back("ba");
	int ret3 = objectFloodRelief.minimumPumps(param30);
	int need3 = 2;
	assert_eq(3,ret3,need3);

}
