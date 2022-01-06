
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

#include <stdio.h>

using namespace std;

double note(char a)
{
    switch (a)
    {
        case 'W' : return 1;break;
        case 'Q' : return .25;break;
        case 'E' : return 0.125;break;
        case 'S' : return 0.0625;break;
    }

}
class CompositionTimeSignature
{
public:
	string getTimeSignature(string duration)
	{
        int i;
        double tot=0;
        for(i=0;i<(int)duration.size();i++)
        {
             tot+=note(duration[i]);
        }
        cout<<tot<<endl;
        vector<string>v;
//        v.push_back("");
//        return "4/4";
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

	CompositionTimeSignature objectCompositionTimeSignature;

	//test case0
	string param00 = "QQEEQEEEQEQ";
	string ret0 = objectCompositionTimeSignature.getTimeSignature(param00);
	string need0 = "4/4";
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "S";
	string ret1 = objectCompositionTimeSignature.getTimeSignature(param10);
	string need1 = "?/?";
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "EEEEEEEEEEEEEEEEEEEEEEEE";
	string ret2 = objectCompositionTimeSignature.getTimeSignature(param20);
	string need2 = "3/8";
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "QQQQQQQQQQQQ";
	string ret3 = objectCompositionTimeSignature.getTimeSignature(param30);
	string need3 = "2/4";
	assert_eq(3,ret3,need3);

	//test case4
	string param40 = "EQHQQWEEHSEEQWQEHHEEQSQEQHESQSWQESQEWWSSHQWQHQWSQW";
	string ret4 = objectCompositionTimeSignature.getTimeSignature(param40);
	string need4 = "3/4";
	assert_eq(4,ret4,need4);

}
