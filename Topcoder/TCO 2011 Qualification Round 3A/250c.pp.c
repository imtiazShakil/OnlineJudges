
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
#include <string.h>

#define SZ 100000
using namespace std;

class AllButOneDivisor
{
public:
	int getMinimum(vector <int> divisors)
	{
	    int array[SZ];
	    memset(array,0,sizeof array);
        for(int i=0;i<(int)divisors.size();i++)
        {
            for(int j=divisors[i] ;j<SZ;j+=divisors[i])
            {
                array[j]++;
            }
        }
        for(int i=1;i<SZ;i++)
        {
            if(array[i]==(int)divisors.size()-1) return i;
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

	AllButOneDivisor objectAllButOneDivisor;

	//test case0
	vector <int> param00;
	param00.push_back(2);
	param00.push_back(3);
	param00.push_back(5);
	int ret0 = objectAllButOneDivisor.getMinimum(param00);
	int need0 = 6;
	assert_eq(0,ret0,need0);

	//test case1
	vector <int> param10;
	param10.push_back(2);
	param10.push_back(4);
	param10.push_back(3);
	param10.push_back(9);
	int ret1 = objectAllButOneDivisor.getMinimum(param10);
	int need1 = 12;
	assert_eq(1,ret1,need1);

	//test case2
	vector <int> param20;
	param20.push_back(3);
	param20.push_back(2);
	param20.push_back(6);
	int ret2 = objectAllButOneDivisor.getMinimum(param20);
	int need2 = -1;
	assert_eq(2,ret2,need2);

	//test case3
	vector <int> param30;
	param30.push_back(6);
	param30.push_back(7);
	param30.push_back(8);
	param30.push_back(9);
	param30.push_back(10);
	int ret3 = objectAllButOneDivisor.getMinimum(param30);
	int need3 = 360;
	assert_eq(3,ret3,need3);

	//test case4
	vector <int> param40;
	param40.push_back(10);
	param40.push_back(6);
	param40.push_back(15);
	int ret4 = objectAllButOneDivisor.getMinimum(param40);
	int need4 = -1;
	assert_eq(4,ret4,need4);

}
