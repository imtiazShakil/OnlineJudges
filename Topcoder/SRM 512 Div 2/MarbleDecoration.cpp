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

#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) x.begin(),x.end()
#define mp make_pair
#define MAX 100
#define SZ(x) (int)x.size()


using namespace std;

class MarbleDecoration
 {
public:
int maxLength(int R, int G, int B)
{
    vector<int>v;
    v.pb(R);v.pb(G);v.pb(B);
    sort(all(v));
    bool flag=0;int c=0;
    for(int i=0;i<3;i++)
    {
        if(v[i]==0) c++;
    }
    if(c>1)
    {
        if(v[2]) return 1;
        else return 0;
    }
    int mx=v[2];
    int md=v[1];
    int ans;
    ans=min(md+1,mx);
//    if(md+1<mx)
//    else if(md+1>mx) ans=min(md+1,mx);
    return md+ans;
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
		cout << "Testing MarbleDecoration (256.0 points)" << endl << endl;
		for (int i = 0; i < 6; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1310569328;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 256.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MarbleDecoration _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int R = 1;
				int G = 0;
				int B = 0;
				_expected = 1;
				_received = _obj.maxLength(R, G, B); break;
			}
			case 1:
			{
				int R = 1;
				int G = 4;
				int B = 2;
				_expected = 5;
				_received = _obj.maxLength(R, G, B); break;
			}
			case 2:
			{
				int R = 5;
				int G = 1;
				int B = 2;
				_expected = 5;
				_received = _obj.maxLength(R, G, B); break;
			}
			case 3:
			{
				int R = 7;
				int G = 7;
				int B = 4;
				_expected = 14;
				_received = _obj.maxLength(R, G, B); break;
			}
			case 4:
			{
				int R = 2;
				int G = 3;
				int B = 5;
				_expected = 7;
				_received = _obj.maxLength(R, G, B); break;
			}
			case 5:
			{
				int R = 13;
				int G = 13;
				int B = 13;
				_expected = 26;
				_received = _obj.maxLength(R, G, B); break;
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

