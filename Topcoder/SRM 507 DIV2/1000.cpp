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

class CubeRoll
{
public:
	int getMinimumSteps(int initPos, int goalPos, vector <int> holePos)
	{
	    for(int i=0;i<(int)holePos.size();i++)
	    {
	        if( min(initPos,goalPos)<=holePos[i] &&  max(initPos,goalPos)>=holePos[i] ) return -1;
	    }

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

	CubeRoll objectCubeRoll;

	//test case0
	int param00 = 5;
	int param01 = 1;
	vector <int> param02;
	param02.push_back(3);
	int ret0 = objectCubeRoll.getMinimumSteps(param00,param01,param02);
	int need0 = -1;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 36;
	int param11 = 72;
	vector <int> param12;
	param12.push_back(300);
	param12.push_back(100);
	param12.push_back(200);
	param12.push_back(400);
	int ret1 = objectCubeRoll.getMinimumSteps(param10,param11,param12);
	int need1 = 1;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 10;
	int param21 = 21;
	vector <int> param22;
	param22.push_back(38);
	param22.push_back(45);
	int ret2 = objectCubeRoll.getMinimumSteps(param20,param21,param22);
	int need2 = 2;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 98765;
	int param31 = 4963;
	vector <int> param32;
	param32.push_back(10);
	param32.push_back(20);
	param32.push_back(40);
	param32.push_back(30);
	int ret3 = objectCubeRoll.getMinimumSteps(param30,param31,param32);
	int need3 = 2;
	assert_eq(3,ret3,need3);

	//test case4
	int param40 = 68332;
	int param41 = 825;
	vector <int> param42;
	param42.push_back(99726);
	param42.push_back(371);
	param42.push_back(67);
	param42.push_back(89210);
	int ret4 = objectCubeRoll.getMinimumSteps(param40,param41,param42);
	int need4 = 2;
	assert_eq(4,ret4,need4);

}

