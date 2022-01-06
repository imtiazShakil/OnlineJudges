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

class WinningTrick
{
public:
	double minimumSpeed(vector <int> speed, int yourSpeed)
	{
	    sort(speed.begin(),speed.end());
	    int mx_spd=speed[(int)speed.size() -1 ];
        if(yourSpeed>=mx_spd) return 0.0;
        int wind=0;
        while(yourSpeed<mx_spd)
        {
            wind+=1;
            if(yourSpeed+wind >= mx_spd-wind) break;
        }
        return wind;
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

	WinningTrick objectWinningTrick;

	//test case0
	vector <int> param00;
	param00.push_back(4);
	param00.push_back(3);
	param00.push_back(2);
	param00.push_back(1);
	int param01 = 5;
	double ret0 = objectWinningTrick.minimumSpeed(param00,param01);
	double need0 = 0.0;
	assert_eq(0,ret0,need0);

	//test case1
	vector <int> param10;
	param10.push_back(3);
	param10.push_back(3);
	int param11 = 3;
	double ret1 = objectWinningTrick.minimumSpeed(param10,param11);
	double need1 = 0.0;
	assert_eq(1,ret1,need1);

	//test case2
	vector <int> param20;
	param20.push_back(2);
	param20.push_back(3);
	param20.push_back(4);
	param20.push_back(5);
	int param21 = 1;
	double ret2 = objectWinningTrick.minimumSpeed(param20,param21);
	double need2 = 2.0;
	assert_eq(2,ret2,need2);

	//test case3
	vector <int> param30;
	param30.push_back(9);
	int param31 = 1;
	double ret3 = objectWinningTrick.minimumSpeed(param30,param31);
	double need3 = 4.0;
	assert_eq(3,ret3,need3);

	//test case4
	vector <int> param40;
	param40.push_back(1);
	param40.push_back(1);
	param40.push_back(2);
	param40.push_back(2);
	param40.push_back(5);
	param40.push_back(2);
	int param41 = 3;
	double ret4 = objectWinningTrick.minimumSpeed(param40,param41);
	double need4 = 1.0;
	assert_eq(4,ret4,need4);

}

