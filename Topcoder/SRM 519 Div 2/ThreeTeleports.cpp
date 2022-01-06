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
int xe,ye;

struct point
{
    int xs,ys,xt,yt;
};

vector<point>ports;
//map<paii,int>M;

ll rec(int x,int y,int mask)
{
//    print2(x,y);
    if(x==xe && y==ye) return 0;
    ll ret;
//    if( M.find(mp(x,y)) !=M.end() )
//    {
//        ret=M[mp(x,y)];
//        return ret;
//    }
    ret=abs(x-xe) + abs(y-ye);

    for(int i=0;i<SZ(ports);i++)
    {
        if( (mask&(1<<i) )==0)
        {
            ret=min(ret, 10+abs(x-ports[i].xs )+abs(y-ports[i].ys) + rec( ports[i].xt,ports[i].yt ,mask|(1<<i) ) );
            ret=min(ret, 10+abs(x-ports[i].xt )+abs(y-ports[i].yt) + rec( ports[i].xs,ports[i].ys,mask|(1<<i) ) );
        }
    }
//    M[mp(x,y)]=ret;
    return ret;
}
class ThreeTeleports
 {
public:
int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports)
{
    xe=xHome;ye=yHome;
    stringstream ss;
    int a,b,c,d;
    point tmp;
    for(int i=0;i<SZ( teleports );i++)
    {
        ss.clear();
        ss<<teleports[i];
        ss>>a>>b>>c>>d;
        tmp.xs=a;tmp.ys=b;tmp.xt=c;tmp.yt=d;
        ports.pb(tmp);
    }
    int ans=rec(xMe,yMe,0);
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
		cout << "Testing ThreeTeleports (600.0 points)" << endl << endl;
		for (int i = 0; i < 6; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1316480941;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ThreeTeleports _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int xMe = 3;
				int yMe = 3;
				int xHome = 4;
				int yHome = 5;
				string teleports[] = {"1000 1001 1000 1002", "1000 1003 1000 1004", "1000 1005 1000 1006"};
				_expected = 3;
				_received = _obj.shortestDistance(xMe, yMe, xHome, yHome, vector <string>(teleports, teleports+sizeof(teleports)/sizeof(string))); break;
			}
			case 1:
			{
				int xMe = 0;
				int yMe = 0;
				int xHome = 20;
				int yHome = 20;
				string teleports[] = {"1 1 18 20", "1000 1003 1000 1004", "1000 1005 1000 1006"};
				_expected = 14;
				_received = _obj.shortestDistance(xMe, yMe, xHome, yHome, vector <string>(teleports, teleports+sizeof(teleports)/sizeof(string))); break;
			}
			case 2:
			{
				int xMe = 0;
				int yMe = 0;
				int xHome = 20;
				int yHome = 20;
				string teleports[] = {"1000 1003 1000 1004", "18 20 1 1", "1000 1005 1000 1006"};
				_expected = 14;
				_received = _obj.shortestDistance(xMe, yMe, xHome, yHome, vector <string>(teleports, teleports+sizeof(teleports)/sizeof(string))); break;
			}
			case 3:
			{
				int xMe = 10;
				int yMe = 10;
				int xHome = 10000;
				int yHome = 20000;
				string teleports[] = {"1000 1003 1000 1004", "3 3 10004 20002", "1000 1005 1000 1006"};
				_expected = 30;
				_received = _obj.shortestDistance(xMe, yMe, xHome, yHome, vector <string>(teleports, teleports+sizeof(teleports)/sizeof(string))); break;
			}
			case 4:
			{
				int xMe = 3;
				int yMe = 7;
				int xHome = 10000;
				int yHome = 30000;
				string teleports[] = {"3 10 5200 4900", "12212 8699 9999 30011", "12200 8701 5203 4845"};
				_expected = 117;
				_received = _obj.shortestDistance(xMe, yMe, xHome, yHome, vector <string>(teleports, teleports+sizeof(teleports)/sizeof(string))); break;
			}
			case 5:
			{
				int xMe = 0;
				int yMe = 0;
				int xHome = 1000000000;
				int yHome = 1000000000;
				string teleports[] = {"0 1 0 999999999", "1 1000000000 999999999 0", "1000000000 1 1000000000 999999999"};
				_expected = 36;
				_received = _obj.shortestDistance(xMe, yMe, xHome, yHome, vector <string>(teleports, teleports+sizeof(teleports)/sizeof(string))); break;
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

