
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

using namespace std;

class TheAlmostLuckyNumbersDivTwo
{
public:
	int find(int a, int b)
	{
	    int count=0;
	    int digit[10];

	    int num,sum;
	    for(int i=a;i<=b;i++)
	    {
            num=i;
            memset(digit,0,sizeof digit);
            while(num)
            {
                digit[num%10]++;
                num/=10;
            }
            sum=0;
            for(int k=0;k<=9;k++)
            {
                if(k!=4 && k!=7)
                {
                    sum+=digit[k];
                }
            }
            if(sum<=1) count++;
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

	TheAlmostLuckyNumbersDivTwo objectTheAlmostLuckyNumbersDivTwo;

	//test case0
	int param00 = 4;
	int param01 = 7;
	int ret0 = objectTheAlmostLuckyNumbersDivTwo.find(param00,param01);
	int need0 = 4;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 8;
	int param11 = 19;
	int ret1 = objectTheAlmostLuckyNumbersDivTwo.find(param10,param11);
	int need1 = 4;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 28;
	int param21 = 33;
	int ret2 = objectTheAlmostLuckyNumbersDivTwo.find(param20,param21);
	int need2 = 0;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 1234;
	int param31 = 4321;
	int ret3 = objectTheAlmostLuckyNumbersDivTwo.find(param30,param31);
	int need3 = 36;
	assert_eq(3,ret3,need3);

}
