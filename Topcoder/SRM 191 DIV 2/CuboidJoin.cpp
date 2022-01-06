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

struct cube
{
    int x1,y1,z1,x2,y2,z2;
    cube(int a,int b,int c,int d,int e,int f)
    {
        x1=a;y1=b;z1=c;x2=d;y2=e;z2=f;
    }
};

vector<cube>v;

set<int>x;
set<int>y;
set<int>z;

ll do_it(void)
{
    ll vol=0;
    bool fl;
    for(set<int>::iterator xi=x.begin() , xj=++x.begin();xj!=x.end();xi++,xj++ )
        for(set<int>::iterator yi=y.begin() ,yj=++y.begin() ;yj!=y.end();yi++,yj++ )
            for(set<int>::iterator zi=z.begin() ,zj=++z.begin() ;zj!=z.end();zi++,zj++ )
            {
                fl=0;
                for(int i=0;i<SZ(v);i++ )
                {
                    if(  v[i].x1<=*xi && v[i].y1<=*yi  && v[i].z1<=*zi  && v[i].x2>=*xj && v[i].y2>=*yj && v[i].z2>=*zj  )
                    {
                        fl=1;break;
                    }

                }
                if(fl) vol+=( (ll)( *xj-*xi )*(ll)( *yj-*yi )*(ll)(*zj-*zi) ) ;
            }


    return vol;
}
class CuboidJoin
 {
public:
long long totalVolume(vector <int> cuboids)
{

    for(int i=0;i<SZ( cuboids ) ;i+=6)
    {
        v.pb( cube(cuboids[i],cuboids[i+1],cuboids[i+2],cuboids[i+3],cuboids[i+4],cuboids[i+5] ) );

        x.insert(cuboids[i]); x.insert( cuboids[i+3] );
        y.insert(cuboids[i+1]);y.insert(cuboids[i+4]);
        z.insert(cuboids[i+2]);z.insert(cuboids[i+5]);
    }
    if(SZ(v)==0) return 0LL;
    ll ans=do_it();
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
		cout << "Testing CuboidJoin (1000.0 points)" << endl << endl;
		for (int i = 0; i < 7; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1317895215;
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
		CuboidJoin _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int cuboids[] = {0,0,0,1,1,1};
				_expected = 1LL;
				_received = _obj.totalVolume(vector <int>(cuboids, cuboids+sizeof(cuboids)/sizeof(int))); break;
			}
			case 1:
			{
				int cuboids[] = {0,0,0,1,1,1,1,1,1,2,2,2};
				_expected = 2LL;
				_received = _obj.totalVolume(vector <int>(cuboids, cuboids+sizeof(cuboids)/sizeof(int))); break;
			}
			case 2:
			{
				int cuboids[] = {0,0,0,4,4,4,0,0,0,1,1,1};
				_expected = 64LL;
				_received = _obj.totalVolume(vector <int>(cuboids, cuboids+sizeof(cuboids)/sizeof(int))); break;
			}
			case 3:
			{
				int cuboids[] = {-5000,-5000,-5000,5000,5000,5000};
				_expected = 1000000000000LL;
				_received = _obj.totalVolume(vector <int>(cuboids, cuboids+sizeof(cuboids)/sizeof(int))); break;
			}
			case 4:
			{
				int cuboids[] = {0,0,0,1,2,3,5,5,5,6,6,6};
				_expected = 7LL;
				_received = _obj.totalVolume(vector <int>(cuboids, cuboids+sizeof(cuboids)/sizeof(int))); break;
			}
			case 5:
			{
				int cuboids[] = {};
				_expected = 0LL;
				_received = _obj.totalVolume(vector <int>(cuboids, cuboids+sizeof(cuboids)/sizeof(int))); break;
			}
			case 6:
			{
				int cuboids[] = {0,0,0,1,1,0};
				_expected = 0LL;
				_received = _obj.totalVolume(vector <int>(cuboids, cuboids+sizeof(cuboids)/sizeof(int))); break;
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

