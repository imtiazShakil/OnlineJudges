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

//int range;
int rrr[]={-1,1,1,-1};int ccc[]={1,1,-1,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;
int x,y;
bool chk(int u,int v,int range)
{
    int p,q;
    ll d1,d2;


    for(int i=0;i<4;i++)
    {

        p=u+rrr[i]*range;
        q=v+ccc[i]*range;
//        if(u==5 && v==5 )
//        {
//            print2(p,q);
//        }
        if( min(p,u)<=x && max(p,u)>=x && min(q,v)<=y && max(q,v)>=y  ) return true;

    }
    return false;
}
class MagicalGirlLevelOneDivTwo
 {
public:
double theMinDistance(int d, int x1, int y1)
{
//    range=d;
//    bool fl1=1,fl2=0;
    double mn_dist;
//    int move_x=0,move_y=0;
    x=x1;y=y1;
    int dst=oo;
    for(int i=-500;i<=500;i++)
        for(int j=-500;j<=500;j++)
        {

            if(chk(i,j,d))
            {
//                if(i==5 && j==5 ) puts("aaa");
                dst=min(dst, (i*i + j*j) );
            }
        }
        return sqrt(double(dst));
//    while( chk(x,y,move_x,move_y,d)==0 )
//    {
////        puts("aa");
//        if(fl1)
//        {
//            if(x>=0) move_x++;
//            else move_x--;
//            fl1=0;fl2=1;
//        }
//        else
//        {
//            if(y>=0) move_y++;
//            else move_y--;
//
//            fl1=1;fl2=0;
//        }
////        print2(move_x,move_y);
//    }
//    print2(move_x,move_y);
//    return sqrt( (double)move_x*move_x + (double)move_y*move_y );
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
		cout << "Testing MagicalGirlLevelOneDivTwo (250.0 points)" << endl << endl;
		for (int i = 0; i < 6; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1312938138;
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
		MagicalGirlLevelOneDivTwo _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int d = 5;
				int x = 10;
				int y = 10;
				_expected = 7.0710678118654755;
				_received = _obj.theMinDistance(d, x, y); break;
			}
			case 1:
			{
				int d = 5;
				int x = 10;
				int y = 3;
				_expected = 5.0;
				_received = _obj.theMinDistance(d, x, y); break;
			}
			case 2:
			{
				int d = 5;
				int x = -8;
				int y = -6;
				_expected = 3.1622776601683795;
				_received = _obj.theMinDistance(d, x, y); break;
			}
			case 3:
			{
				int d = 5;
				int x = 3;
				int y = 2;
				_expected = 0.0;
				_received = _obj.theMinDistance(d, x, y); break;
			}
			case 4:
			{
				int d = 24;
				int x = 24;
				int y = -24;
				_expected = 0.0;
				_received = _obj.theMinDistance(d, x, y); break;
			}
			case 5:
			{
				int d = 345;
				int x = -471;
				int y = 333;
				_expected = 126.0;
				_received = _obj.theMinDistance(d, x, y); break;
			}
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

    // END CUT HERE

