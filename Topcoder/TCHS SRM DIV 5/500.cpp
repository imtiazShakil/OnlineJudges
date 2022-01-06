
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define pb push_back

using namespace std;

class SuperSort
{
public:
	string wordSort(string sentence)
	{
	    vector<string>p;p.clear();string str;
        vector<string>v;v.clear();
        for( int i=0;i<(int)sentence.size();i++ )
        {

            if(ispunct(sentence[i]) || isspace(sentence[i]) )
            {
                str.clear();int j;
                for(j=i;j<(int)sentence.size();j++)
                {
                    if(ispunct(sentence[j]) || isspace(sentence[j]) )
                    {
                        str+=sentence[j];
                    }
                    else break;

                }
                p.pb(str);
                i=j-1;
            }
        }
        string sentence2;sentence2.clear();
        for(int i=0;i<(int)sentence.size();i++)
        {
            if(ispunct(sentence[i]))
            {
                sentence2+=' ';
            }
            else sentence2+=sentence[i];
        }
        string test;test.clear();
        stringstream ss;
        ss<<sentence2;
        while(ss>>test)
        {
//            string str;
//            for(int i=0;i<(int)test.size();i++)
//            {
//                if(ispunct(test[i]) || isspace(test[i]) )
//                {
//                }
//                else str+=test[i];
//            }
//            v.pb(str);
              v.pb(test);
        }
        sort(v.begin(),v.end());
//        for(int i=0;i<(int)v.size();i++) cout<<v[i]<<endl;
        string ans;ans.clear();
        int mx_indx;

        if(ispunct(sentence[0]) || isspace(sentence[0]))
        {
            mx_indx=1;
            if((int)p.size()> 0 )ans+=p[0];

        }
        else
        {
            mx_indx=0;
        }

        for(int i=0;i<(int)v.size();i++)
        {
            ans+=v[i];
            if(mx_indx<(int)p.size())
            {
                ans+=p[mx_indx];
                mx_indx++;
            }
        }
        for(int k=mx_indx;k<(int)p.size();k++) ans+=p[k];

        return ans;
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

	SuperSort objectSuperSort;

	//test case0
	string param00 = " The big,  brown   dog    ran   down  the street!";
	string ret0 = objectSuperSort.wordSort(param00);
	string need0 = " The big,  brown   dog    down   ran  street the!";
	assert_eq(0,ret0,need0);

//////////	//test case1
	string param10 = "This is the first sentence of the paragraph.";
	string ret1 = objectSuperSort.wordSort(param10);
	string need1 = "This first is of paragraph sentence the the.";
	assert_eq(1,ret1,need1);

//////	test case2
	string param20 = "t.d,a!f?g.b,q!i?p.h,s!u?m.l,e!v?y.c,j!w?k.n,x!o?r.";
	string ret2 = objectSuperSort.wordSort(param20);
	string need2 = "a.b,c!d?e.f,g!h?i.j,k!l?m.n,o!p?q.r,s!t?u.v,w!x?y.";
	assert_eq(2,ret2,need2);

//	//test case3
	string param30 = "What is this?";
	string ret3 = objectSuperSort.wordSort(param30);
	string need3 = "What is this?";
	assert_eq(3,ret3,need3);

	//test case4
	string param40 = "?   .   ,   !   ";
	string ret4 = objectSuperSort.wordSort(param40);
	string need4 = "?   .   ,   !   ";
	assert_eq(4,ret4,need4);

	//test case5
	string param50 = "                    ";
	string ret5 = objectSuperSort.wordSort(param50);
	string need5 = "                    ";
	assert_eq(5,ret5,need5);

//////	//test case6
	string param60 = "faecdb";
	string ret6 = objectSuperSort.wordSort(param60);
	string need6 = "faecdb";
	assert_eq(6,ret6,need6);

//	//test case7
	string param70 = "a A b B c C d D e E";
	string ret7 = objectSuperSort.wordSort(param70);
	string need7 = "A B C D E a b c d e";
	assert_eq(7,ret7,need7);

}
