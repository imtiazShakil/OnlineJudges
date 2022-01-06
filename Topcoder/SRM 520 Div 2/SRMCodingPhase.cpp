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

vector <int> points;
vector <int> skills;
int luck;

int dp[4][120][80];

int get_point(int t,int indx)
{
    if(indx==0) return  points[indx]-2*t;
    if(indx==1) return  points[indx]-4*t;
    if(indx==2) return  points[indx]-8*t;
}
int rec(int indx,int luck,int tm)
{
    if(indx==3) return 0;

    int &ret=dp[indx][luck][tm];
    if(ret!=-1000000) return ret;

    ret=rec(indx+1,luck,tm);
    int l=0;
    for(int i=skills[indx];i>=max( skills[indx]-luck,1 ) ;i--,l++ )
    {
        if( i<1 ) break;
        if( skills[indx]-l + tm <=75 )  ret=max(ret,rec(indx+1,luck-l,tm+skills[indx]-l) + get_point( skills[indx]-l,indx ) );
//        else break;
    }
    return ret;

}
class SRMCodingPhase
 {
public:
int countScore(vector <int> pts, vector <int> sklls, int lck)
{
    for(int i=0;i<3;i++)
        for(int j=0;j<120;j++)
            for(int k=0;k<80;k++) dp[i][j][k]=-1000000;

    points=pts;
    skills=sklls;
    luck=lck;

    int ans=rec(0,lck,0);
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
		cout << "Testing SRMCodingPhase (500.0 points)" << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1317741064;
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
		SRMCodingPhase _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int points[] = {250, 500, 1000};
				int skills[] = {80, 80, 80};
				int luck = 5;
				_expected = 400;
				_received = _obj.countScore(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <int>(skills, skills+sizeof(skills)/sizeof(int)), luck); break;
			}
			case 1:
			{
				int points[] = {300, 600, 900};
				int skills[] = {30, 65, 90};
				int luck = 25;
				_expected = 680;
				_received = _obj.countScore(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <int>(skills, skills+sizeof(skills)/sizeof(int)), luck); break;
			}
			case 2:
			{
				int points[] = {250, 550, 950};
				int skills[] = {10, 25, 40};
				int luck = 75;
				_expected = 1736;
				_received = _obj.countScore(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <int>(skills, skills+sizeof(skills)/sizeof(int)), luck); break;
			}
			case 3:
			{
				int points[] = {256, 512, 1024};
				int skills[] = {35, 30, 25};
				int luck = 0;
				_expected = 1216;
				_received = _obj.countScore(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <int>(skills, skills+sizeof(skills)/sizeof(int)), luck); break;
			}
			case 4:
			{
				int points[] = {300, 600, 1100};
				int skills[] = {80, 90, 100};
				int luck = 4;
				_expected = 0;
				_received = _obj.countScore(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <int>(skills, skills+sizeof(skills)/sizeof(int)), luck); break;
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

