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

#define mem(a,b) memset(a,b,sizeof a)
#define MAX 1005
#define mp make_pair
#define pb push_back


using namespace std;

class CuttingGlass
{
public:
	int pieces(int W, int H, int startx, int starty, vector <string> program)
	{
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

	CuttingGlass objectCuttingGlass;

	//test case0
	int param00 = 100;
	int param01 = 100;
	int param02 = 50;
	int param03 = 50;
	vector <string> param04;
	param04.push_back("ULDR");
	int ret0 = objectCuttingGlass.pieces(param00,param01,param02,param03,param04);
	int need0 = 2;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 10;
	int param11 = 10;
	int param12 = 3;
	int param13 = 4;
	vector <string> param14;
	param14.push_back("UDUDUDUDUDU");
	int ret1 = objectCuttingGlass.pieces(param10,param11,param12,param13,param14);
	int need1 = 1;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 3;
	int param21 = 3;
	int param22 = 0;
	int param23 = 0;
	vector <string> param24;
	param24.push_back("RDDDUUU");
	param24.push_back("RDDDUUU");
	param24.push_back("R");
	param24.push_back("DLLLRRR");
	param24.push_back("DLLL");
	int ret2 = objectCuttingGlass.pieces(param20,param21,param22,param23,param24);
	int need2 = 9;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 5;
	int param31 = 3;
	int param32 = 5;
	int param33 = 3;
	vector <string> param34;
	param34.push_back("LULLULLU");
	int ret3 = objectCuttingGlass.pieces(param30,param31,param32,param33,param34);
	int need3 = 2;
	assert_eq(3,ret3,need3);

}

