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

paii org;

bool ok(int min,int hr)
{
    double rat=(double)min/360.0;
    int ch_hr=hr/30;
    ch_hr=ch_hr*30;
    double exact_hr=(double)ch_hr + 30*rat;

//    print1(exact_hr);

    if(hr==(int)(exact_hr +1e-7 )) {puts("okk");return true;}
    return false;

}

string con_str(int exact_hr,int exact_mn)
{
    print3("aaa  ",exact_hr,exact_mn);
    string str,ans;
    str.clear();ans.clear();

    stringstream ss;
    ss<<exact_hr;
    ss>>str;

    if(SZ(str)==1) ans+="0";
    ans+=str;

    ans+=":";

    ss.clear();
    ss<<exact_mn;
    ss>>str;

    if(SZ(str)==1) ans+="0";
    ans+=str;

    print2("ans ", ans);
    return ans;
}
bool com(paii a, paii b)
{
    if(a.fs!=b.fs) return a.fs<b.fs;
    if(a.sc!=b.sc) return a.sc<b.sc;
}
class RotatedClock
 {
public:
string getEarliest(int hourHand, int minuteHand)
{
    int exact_hr,exact_mn;
//    ok(120,250);
    vector<string>v;
    vector<paii>vv;

    string mn,tmp;
    mn="99:99";
    tmp="";
    for(int i=0;i<=180;i++)
    {

        if( ok( (minuteHand + i )%360 , (hourHand +i )%360 ) )
        {
//            print2("iii ",i);
//            print2((minuteHand - i)%360, (hourHand - i)%360 );

            exact_hr=((hourHand + i )%360)/30;
            exact_mn=( (minuteHand + i )%360 )/30 ;
            exact_mn=exact_mn*5;

            vv.pb( mp( (hourHand - i + 360 )%360, (minuteHand - i + 360 )%360  ) );
            tmp=con_str( exact_hr,exact_mn );

//            if(tmp<mn) mn=tmp;
//            v.pb( con_str( exact_hr,exact_mn ) );
//            break;
//            v.pb(tmp);
        }
        if( ok( (minuteHand -i+360 )%360 , (hourHand - i + 360 )%360 ) )
        {

        }
    }
//    sort(all(vv),com);C,vv[i].sc);
//    sort(all(v));
//    for(int i=0;i<SZ(v);i++) print1(v[i]);
//    print2(exact_hr,exact_mn);
//    sort(all(v));
        return tmp;


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
		cout << "Testing RotatedClock (500.0 points)" << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1313856497;
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
		RotatedClock _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			//case 0:
			{
				int hourHand = 70;
				int minuteHand = 300;
				_expected = "08:20";
				_received = _obj.getEarliest(hourHand, minuteHand); break;
			}
			//case 1:
			{
				int hourHand = 90;
				int minuteHand = 120;
				_expected = "11:00";
				_received = _obj.getEarliest(hourHand, minuteHand); break;
			}
			case 2:
			{
				int hourHand = 240;
				int minuteHand = 36;
				_expected = "";
				_received = _obj.getEarliest(hourHand, minuteHand); break;
			}
			//case 3:
			{
				int hourHand = 19;
				int minuteHand = 19;
				_expected = "";
				_received = _obj.getEarliest(hourHand, minuteHand); break;
			}
			//case 4:
			{
				int hourHand = 1;
				int minuteHand = 12;
				_expected = "00:02";
				_received = _obj.getEarliest(hourHand, minuteHand); break;
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

