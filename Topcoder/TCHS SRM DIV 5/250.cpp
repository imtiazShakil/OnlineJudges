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

#define ll long long
using namespace std;

class TVSize
{
public:
	vector <int> calcSize(int diagonal, int height, int width)
	{
	    ll W,H,val1,val2,val3,d1,h1,w1;
	    d1=diagonal*diagonal;
	    h1=height*height;
        w1=width*width;
	    val1=d1*h1;
//	    cout<<val1<<endl;
	    //H/=(height*height + width*width);
	    val2=(h1 + w1);

        H=val1/val2;

	    W=d1-H;

	    H=sqrt((double)H);//H=floor(H);
        W=sqrt((double)W);//W=floor(W);

//        cout<<H<<" "<<W<<endl;
        vector<int>v;v.push_back(H);v.push_back(W);
        return v;
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

	TVSize objectTVSize;

//	//test case0
//	int param00 = 52;
//	int param01 = 9;
//	int param02 = 16;
//	vector <int> ret0 = objectTVSize.calcSize(param00,param01,param02);
//	vector <int> need0;
//	need0.push_back(25);
//	need0.push_back(45);
//	assert_eq(0,ret0,need0);
//
//	//test case1
//	int param10 = 7;
//	int param11 = 2;
//	int param12 = 3;
//	vector <int> ret1 = objectTVSize.calcSize(param10,param11,param12);
//	vector <int> need1;
//	need1.push_back(3);
//	need1.push_back(5);
//	assert_eq(1,ret1,need1);
//
//	//test case2
//	int param20 = 13;
//	int param21 = 7;
//	int param22 = 10;
//	vector <int> ret2 = objectTVSize.calcSize(param20,param21,param22);
//	vector <int> need2;
//	need2.push_back(7);
//	need2.push_back(10);
//	assert_eq(2,ret2,need2);
//
//	//test case3
//	int param30 = 7;
//	int param31 = 32;
//	int param32 = 47;
//	vector <int> ret3 = objectTVSize.calcSize(param30,param31,param32);
//	vector <int> need3;
//	need3.push_back(3);
//	need3.push_back(5);
//	assert_eq(3,ret3,need3);

	//test case4
	int param40 = 1000;
	int param41 = 99;
	int param42 = 100;
	vector <int> ret4 = objectTVSize.calcSize(param40,param41,param42);
	vector <int> need4;
	need4.push_back(703);
	need4.push_back(710);
	assert_eq(4,ret4,need4);

}

