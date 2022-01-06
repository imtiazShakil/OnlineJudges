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
#define MAX 250500
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

int dp[55][MAX];
vector<int>itm;
int n;
int rec(int indx,int sum)
{
    if(indx==n && sum==0) return 0;
    if(indx==n && sum) return -1*(oo);
    if(sum>250000) return -1*(oo);

    int &ret=dp[indx][sum];
    if(ret!=-1) return ret;

    ret=0;
    ret=rec(indx+1,sum+itm[indx]) + itm[indx] ;
    ret=max(ret,rec(indx+1,sum));
    if(sum>itm[indx]) ret=max(ret,rec(indx+1,sum-itm[indx]) );
    else ret=max(ret,rec(indx+1,itm[indx]-sum)+itm[indx]-sum ) ;

    return ret;

}

class EqualTowers
 {
public:
int height(vector <int> bricks)
{
    n=SZ(bricks);
    itm=bricks;
    mem(dp,-1);
    int ans=rec(0,0);
    if(ans) return ans;
    else return -1;
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
		cout << "Testing EqualTowers (1000.0 points)" << endl << endl;
		for (int i = 0; i < 4; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1316591152;
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
		EqualTowers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int bricks[] = { 2, 3, 5 };
				_expected = 5;
				_received = _obj.height(vector <int>(bricks, bricks+sizeof(bricks)/sizeof(int))); break;
			}
			case 1:
			{
				int bricks[] = { 10, 9, 2 };
				_expected = -1;
				_received = _obj.height(vector <int>(bricks, bricks+sizeof(bricks)/sizeof(int))); break;
			}
			case 2:
			{
				int bricks[] = {90000, 60000, 60001, 60000, 60001};
				_expected =120001;
				_received = _obj.height(vector <int>(bricks, bricks+sizeof(bricks)/sizeof(int))); break;
			}
			case 3:
			{
				int bricks[] ={27, 260, 98825, 25182, 153, 2653, 70154, 13, 892, 1142, 51590, 2018, 144, 501, 246446};
				_expected = 249870;
				_received = _obj.height(vector <int>(bricks, bricks+sizeof(bricks)/sizeof(int))); break;
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

