#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


#define print1(a) cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define PI (2*acos(0))
#define ERR 1e-5
#define ll long long
#define VI vector<int>
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define MAX 60
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

map<int,int>all_y;
map<int,int>all_x;
vector<int>X[60];
vector<int>Y[60];

string get_dir(paii a)
{
    bool fl=1;
    for(int i=0;i<SZ( X[ all_x[ a.fs ] ] ) ;i++ )
    {
        if(a.sc>X[ all_x[a.fs] ][i] ) {fl=0;break;}
    }
    if(fl) return "D";

    fl=1;
    for(int i=0;i<SZ( Y[ all_y[ a.sc ] ] ) ;i++ )
    {
        if(a.fs>Y[ all_y[a.sc] ][i] ) {fl=0;break;}
    }
    if(fl) return "L";


    fl=1;
    for(int i=0;i<SZ( Y[ all_y[ a.sc ] ] ) ;i++ )
    {
        if(a.fs<Y[ all_y[a.sc] ][i] ) {fl=0;break;}
    }
    if(fl) return "R";


    fl=1;
    for(int i=0;i<SZ( X[ all_x[ a.fs ] ] ) ;i++ )
    {
        if(a.sc<X[ all_x[a.fs] ][i] ) {fl=0;break;}
    }
    if(fl) return "U";

    return "";
}
class Cannons
 {
public:
string getDirections(vector <int> x, vector <int> y)
{

    string ans;
    int xx=0,yy=0;
    for(int i=0;i<SZ(x);i++)
    {
        if(all_y.find(y[i])==all_y.end()  )
        {
                all_y[y[i]]=yy++;
        }
        if( all_x.find( x[i] )==all_x.end() )
        {
                all_x[x[i]]=xx++;
        }
    }

    for(int i=0;i<SZ(x);i++)
    {
        X[ all_x[ x[i] ] ].pb( y[i] );
        Y[ all_y[ y[i] ] ].pb( x[i] );
    }

    string tmp;
    for(int i=0;i<SZ(x);i++)
    {
        tmp=get_dir(mp( x[i],y[i] ));
        if(tmp=="") return tmp;
        else ans+=tmp;
    }
    return ans;
}
};
// BEGIN CUT HERE
    #include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		cout << "Testing Cannons (500.0 points)" << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1317725172;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Cannons _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1,2,2,4};
				int y[] = {2,1,3,2};
				_expected = "DDLD";
				_received = _obj.getDirections(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0};
				int y[] = {0};
				_expected = "D";
				_received = _obj.getDirections(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {-3,0,9,0,0};
				int y[] = {0,0,0,7,-4};
				_expected = "";
				_received = _obj.getDirections(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {0,-4,0,5,0,-4};
				int y[] = {0,0,-7,3,3,3};
				_expected = "RDDDUL";
				_received = _obj.getDirections(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {-761813,348943,749420,-444982,993810,-548742,-444982,-761813,993810,
				          363833,728226,28752,461997,544181,776052,-761813,776052,993810,789745,
				          75502,348943,449038,158889,-548742,-659628,75502,363833,917729,993810,
				          158889,776052,728226,367390,-689680,917729,748629,367390,917729,859379,
				          728226};
				int y[] = {393728,835962,-593971,-593971,-36149,-922640,376562,-368880,-368880,
				          -212107,-368880,-595655,-786227,393728,-463260,763742,790220,63191,
				          -212107,-786227,-805377,-912205,-368880,883897,-912205,803745,63191,
				          803745,790220,-212107,-593971,939489,-912205,939489,-291544,790220,
				          795389,835962,795389,763742};
				_expected = "LLDDLDLDDDDDDDLLURDDDDDLDLLRRLDRDDDDLRDR";
				_received = _obj.getDirections(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

    // END CUT HERE

