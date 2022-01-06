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

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

int cost[100][3],n;
int dp[50][5];
int rec(int indx,int color)
{
    if(indx==n) return 0;
    int &ret=dp[indx][color];
    if(ret!=-1) return ret;
    ret=oo;
    for(int i=1;i<=3;i++)
    {
        if(color!=i) ret=min(ret,rec(indx+1,i) + cost[indx][i-1] );
    }
    return ret;
}
class RGBStreet
 {
public:
int estimateCost(vector <string> houses)
{
    stringstream ss;
    int val,j;
    n=SZ(houses);
    mem(dp,-1);
    for(int i=0;i<SZ(houses);i++)
    {
        ss.clear();j=0;
        ss<<houses[i];
        while(ss>>val)
        {
            cost[i][j++]=val;
        }
    }
    int ans=rec(0,0);
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
		cout << "Testing RGBStreet (500.0 points)" << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1311856347;
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
		RGBStreet _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string houses[] = {"1 100 100", "100 1 100", "100 100 1"};
				_expected = 3;
				_received = _obj.estimateCost(vector <string>(houses, houses+sizeof(houses)/sizeof(string))); break;
			}
			case 1:
			{
				string houses[] = {"1 100 100", "100 100 100", "1 100 100"};
				_expected = 102;
				_received = _obj.estimateCost(vector <string>(houses, houses+sizeof(houses)/sizeof(string))); break;
			}
			case 2:
			{
				string houses[] = {"26 40 83", "49 60 57", "13 89 99"};
				_expected = 96;
				_received = _obj.estimateCost(vector <string>(houses, houses+sizeof(houses)/sizeof(string))); break;
			}
			case 3:
			{
				string houses[] = {"30 19 5", "64 77 64", "15 19 97", "4 71 57", "90 86 84", "93 32 91"};
				_expected = 208;
				_received = _obj.estimateCost(vector <string>(houses, houses+sizeof(houses)/sizeof(string))); break;
			}
			case 4:
			{
				string houses[] = {"71 39 44", "32 83 55", "51 37 63", "89 29 100",
				                   "83 58 11", "65 13 15", "47 25 29", "60 66 19"};
				_expected = 253;
				_received = _obj.estimateCost(vector <string>(houses, houses+sizeof(houses)/sizeof(string))); break;
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

