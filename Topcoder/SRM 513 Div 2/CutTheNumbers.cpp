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
#define rep(x,n)        for(x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define fs      first
#define sc      second


using namespace std;

int dp[1<<17],val;
vector<string>brd;
vector<int>go[12][7];

int rec(int mask)
{

    if(__builtin_popcount(mask)==val) return 0;

    int &ret=dp[mask];
    if(ret!=-1) return ret;
    ret=0;
    int val;
    for(int i=0;i<val*val;i++)
    {
        if((mask&(1<<i)) ==0)
        {
            for(int p=0;p<7;p++)
            {
                bool flag=0;val=0;
                int m=mask;
                for(int q=0;q<SZ(go[i][p]);q++)
                {
                    if((mask&go[i][p][q])==1) flag=1;
                    val=val*10+brd[ go[i][p][q]/val ][go[i][p][q]%val] -'0';
                    m=m|(1<<go[i][p][q]);
                }
                if(!flag) ret=max(ret,rec(m)+val);
            }
        }
    }
    return ret;
}
class CutTheNumbers
 {
public:
int maximumSum(vector <string> board)
{
    go[0][0].pb(0);
    go[0][1].pb(0);go[0][1].pb(4);
    go[0][2].pb(0);go[0][2].pb(4);go[0][2].pb(8);
    go[0][3].pb(0);go[0][3].pb(4);go[0][3].pb(8);go[0][3].pb(12);
    go[0][4].pb(0);go[0][4].pb(1);
    go[0][5].pb(0);go[0][5].pb(1);go[0][5].pb(2);
    go[0][6].pb(0);go[0][6].pb(1);go[0][6].pb(2);go[0][6].pb(3);


    go[1][0].pb(1);
    go[1][1].pb(1);go[1][1].pb(0);
    go[1][2].pb(1);go[1][2].pb(2);
    go[1][3].pb(1);go[1][3].pb(2);go[1][3].pb(3);
    go[1][4].pb(1);go[1][4].pb(5);
    go[1][5].pb(1);go[1][5].pb(5);go[1][5].pb(9);
    go[1][6].pb(1);go[1][6].pb(5);go[1][6].pb(9);go[1][6].pb(13);








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
		cout << "Testing CutTheNumbers (1000.0 points)" << endl << endl;
		for (int i = 0; i < 4; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1311679458;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CutTheNumbers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"123",
				                  "312"};
				_expected = 435;
				_received = _obj.maximumSum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"99",
				                  "11"};
				_expected = 182;
				_received = _obj.maximumSum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"001",
				                  "010",
				                  "111",
				                  "100"};
				_expected = 1131;
				_received = _obj.maximumSum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"8"};
				_expected = 8;
				_received = _obj.maximumSum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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

