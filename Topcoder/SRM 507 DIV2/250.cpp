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

using namespace std;

int sol(int pos)
{
    if(pos==0) return 0;
    if(pos==1) return 1;
    if(pos==2) return 2;
    if(pos==3) return 1;
    if(pos==4) return 1;
    if(pos==5) return 2;
    if(pos==6) return 3;
    if(pos==7) return 2;
}
class CubeAnts
{
public:
	int getMinimumSteps(vector <int> pos)
	{
	    int mx=0;
        for(int i=0;i<(int)pos.size();i++)
        {
            mx=max(mx,sol(pos[i]) );
        }
        return mx;
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

	CubeAnts objectCubeAnts;

	//test case0
	vector <int> param00;
	param00.push_back(0);
	param00.push_back(1);
	param00.push_back(1);
	int ret0 = objectCubeAnts.getMinimumSteps(param00);
	int need0 = 1;
	assert_eq(0,ret0,need0);

	//test case1
	vector <int> param10;
	param10.push_back(5);
	param10.push_back(4);
	int ret1 = objectCubeAnts.getMinimumSteps(param10);
	int need1 = 2;
	assert_eq(1,ret1,need1);

	//test case2
	vector <int> param20;
	param20.push_back(0);
	int ret2 = objectCubeAnts.getMinimumSteps(param20);
	int need2 = 0;
	assert_eq(2,ret2,need2);

	//test case3
	vector <int> param30;
	param30.push_back(6);
	param30.push_back(1);
	param30.push_back(6);
	int ret3 = objectCubeAnts.getMinimumSteps(param30);
	int need3 = 3;
	assert_eq(3,ret3,need3);

	//test case4
	vector <int> param40;
	param40.push_back(7);
	param40.push_back(7);
	param40.push_back(3);
	param40.push_back(3);
	param40.push_back(7);
	param40.push_back(7);
	param40.push_back(3);
	param40.push_back(3);
	int ret4 = objectCubeAnts.getMinimumSteps(param40);
	int need4 = 2;
	assert_eq(4,ret4,need4);

}

