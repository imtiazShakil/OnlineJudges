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

class SRMRoomAssignmentPhase
 {
public:
int countCompetitors(vector <int> ratings, int K)
{
    int my_rat=ratings[0];
    int my_room;

    vector<int>room[60];

    sort( ratings.rbegin(),ratings.rend() );


    for(int i=0;i<SZ( ratings );i++)
    {
        room[i%K].pb(ratings[i]);
        if( ratings[i]==my_rat )
        {
            my_room=i%K;
        }
    }
    int cnt=0;
    for(int i=0;i<SZ( room[  my_room] );i++  )
    {
        if( room[ my_room ][i]>my_rat ) cnt++;
    }
    return cnt;

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
		cout << "Testing SRMRoomAssignmentPhase (250.0 points)" << endl << endl;
		for (int i = 0; i < 6; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1317740536;
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
		SRMRoomAssignmentPhase _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int ratings[] = {491, 981, 1199, 763, 994, 879, 888};
				int K = 3;
				_expected = 2;
				_received = _obj.countCompetitors(vector <int>(ratings, ratings+sizeof(ratings)/sizeof(int)), K); break;
			}
			case 1:
			{
				int ratings[] = {1024, 1000, 600,1030};
				int K = 1;
				_expected = 1;
				_received = _obj.countCompetitors(vector <int>(ratings, ratings+sizeof(ratings)/sizeof(int)), K); break;
			}
			case 2:
			{
				int ratings[] = {505, 679, 900, 1022};
				int K = 2;
				_expected = 1;
				_received = _obj.countCompetitors(vector <int>(ratings, ratings+sizeof(ratings)/sizeof(int)), K); break;
			}
			case 3:
			{
				int ratings[] = {716, 58, 1000, 1004, 912, 822, 453, 1100, 558};
				int K = 3;
				_expected = 1;
				_received = _obj.countCompetitors(vector <int>(ratings, ratings+sizeof(ratings)/sizeof(int)), K); break;
			}
			case 4:
			{
				int ratings[] = {422, 623, 1023, 941, 882, 776, 852, 495, 803, 622, 618, 532, 751, 500};
				int K = 4;
				_expected = 3;
				_received = _obj.countCompetitors(vector <int>(ratings, ratings+sizeof(ratings)/sizeof(int)), K); break;
			}
			case 5:
			{
				int ratings[] = {1197, 1198, 1196, 1195, 1199};
				int K = 1;
				_expected = 2;
				_received = _obj.countCompetitors(vector <int>(ratings, ratings+sizeof(ratings)/sizeof(int)), K); break;
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

