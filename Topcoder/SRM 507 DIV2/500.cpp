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

map<string,int>M;

class CubeStickers
{
public:
	string isPossible(vector <string> sticker)
	{
        M.clear();
        for(int i=0;i<(int)sticker.size();i++)
        {
            if( M[sticker[i]]<2 ) M[sticker[i]]++;
        }
        int count=0;
        for(map<string,int>::iterator I=M.begin();I!=M.end();I++)
        {
            count=count + I->second;
        }
        if(count>=6) return "YES";
        else return "NO";

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

	CubeStickers objectCubeStickers;

	//test case0
	vector <string> param00;
	param00.push_back("cyan");
	param00.push_back("magenta");
	param00.push_back("yellow");
	param00.push_back("purple");
	param00.push_back("black");
	param00.push_back("white");
	param00.push_back("purple");
	string ret0 = objectCubeStickers.isPossible(param00);
	string need0 = "YES";
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back("blue");
	param10.push_back("blue");
	param10.push_back("blue");
	param10.push_back("blue");
	param10.push_back("blue");
	param10.push_back("blue");
	param10.push_back("blue");
	param10.push_back("blue");
	param10.push_back("blue");
	param10.push_back("blue");
	string ret1 = objectCubeStickers.isPossible(param10);
	string need1 = "NO";
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back("red");
	param20.push_back("yellow");
	param20.push_back("blue");
	param20.push_back("red");
	param20.push_back("yellow");
	param20.push_back("blue");
	param20.push_back("red");
	param20.push_back("yellow");
	param20.push_back("blue");
	string ret2 = objectCubeStickers.isPossible(param20);
	string need2 = "YES";
	assert_eq(2,ret2,need2);

	//test case3
	vector <string> param30;
	param30.push_back("purple");
	param30.push_back("orange");
	param30.push_back("orange");
	param30.push_back("purple");
	param30.push_back("black");
	param30.push_back("orange");
	param30.push_back("purple");
	string ret3 = objectCubeStickers.isPossible(param30);
	string need3 = "NO";
	assert_eq(3,ret3,need3);

	//test case4
	vector <string> param40;
	param40.push_back("white");
	param40.push_back("gray");
	param40.push_back("green");
	param40.push_back("blue");
	param40.push_back("yellow");
	param40.push_back("red");
	param40.push_back("target");
	param40.push_back("admin");
	string ret4 = objectCubeStickers.isPossible(param40);
	string need4 = "YES";
	assert_eq(4,ret4,need4);

}
