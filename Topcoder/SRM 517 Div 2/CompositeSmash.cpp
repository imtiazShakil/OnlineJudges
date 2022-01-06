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

int dp[100005];
int trg;

int rec(int n)
{
    print1(n);
    if(n==trg) return 1;
    if( n<trg ) return 0;

    int &ret=dp[n];
    if(ret!=-1) return ret;

    ret=0;
    int val=sqrt(n) + 1;
    bool fl=0;
    for(int i=2;i<=val;i++)
    {
        if(n%i==0)
        {
            fl=1;
            ret= rec(n/i) + rec(i);
            if(ret==0) return 0;
        }
    }
    if(fl) return 1;
    else  return 0;
}
class CompositeSmash
 {
public:
string thePossible(int N, int target)
{
    trg=target;
    mem(dp,-1);

    int ans=rec(N);
    if(ans) return "Yes";
    else return "No";
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
		cout << "Testing CompositeSmash (500.0 points)" << endl << endl;
		for (int i = 0; i < 8; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1315672757;
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
		CompositeSmash _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			//case 0:
			{
				int N = 517;
				int target = 47;
				_expected = "Yes";
				_received = _obj.thePossible(N, target); break;
			}
			//case 1:
			{
				int N = 8;
				int target = 4;
				_expected = "Yes";
				_received = _obj.thePossible(N, target); break;
			}
			//case 2:
			{
				int N = 12;
				int target = 6;
				_expected = "No";
				_received = _obj.thePossible(N, target); break;
			}
			//case 3:
			{
				int N = 5;
				int target = 8;
				_expected = "No";
				_received = _obj.thePossible(N, target); break;
			}
			//case 4:
			{
				int N = 100000;
				int target = 100000;
				_expected = "Yes";
				_received = _obj.thePossible(N, target); break;
			}
			//case 5:
			{
				int N = 5858;
				int target = 2;
				_expected = "Yes";
				_received = _obj.thePossible(N, target); break;
			}
			//case 6:
			{
				int N = 81461;
				int target = 2809;
				_expected = "No";
				_received = _obj.thePossible(N, target); break;
			}
			case 7:
			{
				int N = 101;
				int target = 101;
				_expected = "Yes";
				_received = _obj.thePossible(N, target); break;
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

