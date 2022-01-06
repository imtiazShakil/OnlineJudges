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

//string msg;
//string ans;
//bool flag=0;
//
//bool ok()
//{
//    int c1,c2;
//    for(int i=0;i<SZ(msg);i++)
//    {
////        print2("i ",i);
//        for(int j=2;j+i<=SZ(msg);j+=2)
//        {
////            print2("j  ",j);
//            c1=0;c2=0;
//            for(int p=i;p<j+i;p++)
//            {
//                if(msg[p]=='o') c1++;
//                else c2++;
//            }
////            printf("i  j ");
////            print2(i,j);
////            printf("c1 c2 ");
////            print2(c1,c2);
//            if(c1!=c2) return false;
//        }
//    }
//    print1(msg);
//
//    return true;
//}
//void rec(int depth)
//{
//    if(depth==SZ(msg))
//    {
////        print2("msg  ",msg);
//        if( ok() ) {flag=1;puts("found");print1(msg);ans=msg; }
//        return ;
//    }
//
//    if( msg[depth]=='?' )
//    {
//        msg[depth]='o';
//        rec(depth+1);
//        if(flag) return ;
//
//        msg[depth]='x';
//        rec(depth+1);
//
//        msg[depth]='?';
//        if(flag) return ;
//    }
//    else
//    {
//        rec(depth+1);
//        if(flag) return ;
//    }
//
//    return ;
//}

class NetworkXZeroOne
 {
public:
string reconstruct(string message)
{
//    msg.clear();
//    msg=message;
//    ans.clear();
//    flag=0;
//    rec(0);

    string ans1,ans2;
    for(int i=0;i<SZ( message) /2;i++ )
    {
        ans1+="ox";
        ans2+="xo";
    }
    if( SZ(ans1)<SZ( message ) )
    {
        ans1+="o";
        ans2+="x";
    }

    bool fl1=1,fl2=1;

    for(int i=0;i<SZ( message ) ;i++)
    {
        if( message[i]!='?'  )
        {
            if(ans1[i]!=message[i] ) fl1=0;
        }
    }

    if(fl1 ) return ans1;
    else return ans2;

//    return ans;
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
		cout << "Testing NetworkXZeroOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1314716535;
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
		NetworkXZeroOne _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string message = "x?x?";
				_expected = "xoxo";
				_received = _obj.reconstruct(message); break;
			}
			case 1:
			{
				string message = "?xo?";
				_expected = "oxox";
				_received = _obj.reconstruct(message); break;
			}
			case 2:
			{
				string message = "xo";
				_expected = "xo";
				_received = _obj.reconstruct(message); break;
			}
			case 3:
			{
				string message = "o??x??o";
				_expected = "oxoxoxo";
				_received = _obj.reconstruct(message); break;
			}
			case 4:
			{
				string message = "???????x";
				_expected = "oxoxoxox";
				_received = _obj.reconstruct(message); break;
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

