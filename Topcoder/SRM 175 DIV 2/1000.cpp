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

class Books
{
public:
	int sortMoves(vector <string> titles)
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

	Books objectBooks;

	//test case0
	vector <string> param00;
	param00.push_back("Algorithms");
	param00.push_back("Purely Functional Data Structures");
	param00.push_back("Intro to C");
	param00.push_back("Automata and Computability");
	int ret0 = objectBooks.sortMoves(param00);
	int need0 = 2;
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back("the fellowship of the ring");
	param10.push_back("the return of the king");
	param10.push_back("The two towers");
	int ret1 = objectBooks.sortMoves(param10);
	int need1 = 1;
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back("Basic Engineering Circuit Analysis");
	param20.push_back("A Course in Combinatorics");
	param20.push_back("Artificial Intelligence");
	param20.push_back("Asimovs Guide to Shakespeare");
	param20.push_back("The Nature of Space and Time");
	param20.push_back("A Time for Trumpets");
	param20.push_back("Essentials of Artificial Intelligence");
	param20.push_back("Life by the Numbers");
	param20.push_back("Cognitive Psychology");
	param20.push_back("ColdFusion");
	int ret2 = objectBooks.sortMoves(param20);
	int need2 = 5;
	assert_eq(2,ret2,need2);

	//test case3
	vector <string> param30;
	param30.push_back("A");
	param30.push_back("B");
	param30.push_back("A");
	param30.push_back("A");
	param30.push_back("B");
	int ret3 = objectBooks.sortMoves(param30);
	int need3 = 1;
	assert_eq(3,ret3,need3);

	//test case4
	vector <string> param40;
	param40.push_back("This Book Has No Title");
	param40.push_back(" This Book Does Have A Title");
	int ret4 = objectBooks.sortMoves(param40);
	int need4 = 1;
	assert_eq(4,ret4,need4);

	//test case5
	vector <string> param50;
	param50.push_back("What Is The");
	param50.push_back("What Is The ");
	param50.push_back("What Is The Title Of This Book");
	int ret5 = objectBooks.sortMoves(param50);
	int need5 = 0;
	assert_eq(5,ret5,need5);

}

