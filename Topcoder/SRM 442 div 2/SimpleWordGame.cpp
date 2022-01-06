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

class SimpleWordGame
 {
public:
int points(vector <string> player, vector <string> dictionary)
{
    map<string,int>M;
    for(int i=0;i<SZ( player );i++)
    {
        M[player[i]]=1;
    }
    int ans=0;
    for(int i=0;i<SZ(dictionary);i++)
    {
        if(M.find(dictionary[i])!=M.end())
        {
            ans+=  ( SZ( dictionary[i] ) * SZ( dictionary[i] ) );
        }
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
		cout << "Testing SimpleWordGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 4; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1316597415;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SimpleWordGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string player[] = { "apple", "orange", "strawberry" };
				string dictionary[] = { "strawberry", "orange", "grapefruit", "watermelon" };
				_expected = 136;
				_received = _obj.points(vector <string>(player, player+sizeof(player)/sizeof(string)), vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			case 1:
			{
				string player[] = { "apple" };
				string dictionary[] = { "strawberry", "orange", "grapefruit", "watermelon" };
				_expected = 0;
				_received = _obj.points(vector <string>(player, player+sizeof(player)/sizeof(string)), vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			case 2:
			{
				string player[] = { "orange", "orange" };
				string dictionary[] = { "strawberry", "orange", "grapefruit", "watermelon" };
				_expected = 36;
				_received = _obj.points(vector <string>(player, player+sizeof(player)/sizeof(string)), vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			case 3:
			{
				string player[] = { "lidi", "o", "lidi", "gnbewjzb", "kten",
				                    "ebnelff", "gptsvqx", "rkauxq", "rkauxq", "kfkcdn"};
				string dictionary[] = { "nava", "wk", "kfkcdn", "lidi", "gptsvqx",
				                        "ebnelff", "hgsppdezet", "ulf", "rkauxq", "wcicx"};
				_expected = 186;
				_received = _obj.points(vector <string>(player, player+sizeof(player)/sizeof(string)), vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

    // END CUT HERE

