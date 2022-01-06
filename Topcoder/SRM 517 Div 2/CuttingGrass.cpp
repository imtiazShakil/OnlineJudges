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

class CuttingGrass
 {
public:
int theMin(vector <int> init, vector <int> grow, int H)
{		
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
		cout << "Testing CuttingGrass (1000.0 points)" << endl << endl;
		for (int i = 0; i < 6; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1315673981;
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
		CuttingGrass _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int init[] = {5, 8, 58};
				int grow[] = {2, 1, 1};
				int H = 16;
				_expected = 1;
				_received = _obj.theMin(vector <int>(init, init+sizeof(init)/sizeof(int)), vector <int>(grow, grow+sizeof(grow)/sizeof(int)), H); break;
			}
			case 1:
			{
				int init[] = {5, 8};
				int grow[] = {2, 1};
				int H = 58;
				_expected = 0;
				_received = _obj.theMin(vector <int>(init, init+sizeof(init)/sizeof(int)), vector <int>(grow, grow+sizeof(grow)/sizeof(int)), H); break;
			}
			case 2:
			{
				int init[] = {5, 8};
				int grow[] = {2, 1};
				int H = 0;
				_expected = -1;
				_received = _obj.theMin(vector <int>(init, init+sizeof(init)/sizeof(int)), vector <int>(grow, grow+sizeof(grow)/sizeof(int)), H); break;
			}
			case 3:
			{
				int init[] = {5, 1, 6, 5, 8, 4, 7};
				int grow[] = {2, 1, 1, 1, 4, 3, 2};
				int H = 33;
				_expected = 5;
				_received = _obj.theMin(vector <int>(init, init+sizeof(init)/sizeof(int)), vector <int>(grow, grow+sizeof(grow)/sizeof(int)), H); break;
			}
			case 4:
			{
				int init[] = {49, 13, 62, 95, 69, 75, 62, 96, 97, 22, 69, 69, 52};
				int grow[] = {7, 2, 4, 3, 6, 5, 7, 6, 5, 4, 7, 7, 4};
				int H = 517;
				_expected = 8;
				_received = _obj.theMin(vector <int>(init, init+sizeof(init)/sizeof(int)), vector <int>(grow, grow+sizeof(grow)/sizeof(int)), H); break;
			}
			case 5:
			{
				int init[] = {1231, 1536, 1519, 1940, 1539, 1385, 1599, 1613, 1394, 1803,
				              1763, 1706, 1863, 1452, 1818, 1914, 1386, 1954, 1496, 1722,
				              1616, 1862, 1755, 1215, 1233, 1078, 1448, 1241, 1732, 1561,
				              1633, 1307, 1844, 1911, 1371, 1338, 1989, 1789, 1656, 1413,
				              1929, 1182, 1815, 1474, 1540, 1797, 1586, 1427, 1996, 1202};
				int grow[] = {86, 55, 2, 86, 96, 71, 81, 53, 79, 22,
				              23, 8, 69, 32, 35, 39, 30, 18, 92, 64,
				              88, 1, 48, 81, 91, 75, 44, 77, 3, 33,
				              9, 52, 56, 4, 19, 73, 52, 18, 8, 77,
				              91, 59, 50, 62, 42, 87, 89, 24, 71, 67};
				int H = 63601;
				_expected = 36;
				_received = _obj.theMin(vector <int>(init, init+sizeof(init)/sizeof(int)), vector <int>(grow, grow+sizeof(grow)/sizeof(int)), H); break;
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

