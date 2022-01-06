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
#define MAX 150
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

//int r[MAX];
//int c[MAX];
vector<string>brd;
struct cell
{
    int c;
    int r_indx;
    int c_indx;
};
vector<cell>v;

bool maze[MAX][MAX];

bool com(cell a ,cell b)
{
    return a.c>b.c;
}

bool ok()
{
    for(int i=0;i<SZ(brd);i++ )
    {
        for(int j=0;j<SZ(brd[i]);j++)
        {
            if(maze[i][j]==0 && brd[i][j]=='B') return false;
            if(maze[i][j]==1 && brd[i][j]=='W') return false;
        }
    }
    return true;
}

class MonochromaticBoard
 {
public:
int theMin(vector <string> board)
{
    brd=board;
    cell tmp;
    int ccc=SZ(board[0]);
    int rrr=SZ(board);
    for(int i=0;i<SZ( board );i++)
    {
        int cnt=0;
        for(int j=0;j<SZ( board[i] );j++)
        {
            if(board[i][j]=='B') cnt++;
        }
        tmp.c=cnt;
        tmp.r_indx=i;
        tmp.c_indx=-1;
        v.pb(tmp);
//        cll[i].indx=i;
//        r[i].c=cnt;
    }
//    puts("r done");

    for(int j=0;j<ccc ;j++)
    {
//        print2("col ",j);
        int cnt=0;
        for(int i=0;i<SZ( board );i++)
        {
//            print2("row ",i);
            if(board[i][j]=='B') cnt++;
        }
//        col[j].indx=j;
//        col[j].c=cnt;
        tmp.r_indx=-1;
        tmp.c=cnt;
        tmp.c_indx=j;
        v.pb(tmp);
    }

//    puts("c done ");
    sort(all(v),com );
//    puts("sorted");

    int pos=0;
//    print2("total ",SZ(v));
//    for(int i=0;i<SZ(v);i++)
//    {
//        print3(v[i].r_indx,v[i].c_indx,v[i].c);
//
//    }
//    print1("print done");

    int cnt=0;
    while(!ok())
    {
        tmp=v[pos];
        if(tmp.r_indx!=-1 && tmp.c==ccc )
        {
            print3(tmp.r_indx,tmp.c_indx,tmp.c);
            cnt++;
            for(int j=0;j<ccc;j++)
            {
                maze[tmp.r_indx][j]=1;
            }
        }
        else if(tmp.c_indx!=-1 && tmp.c ==rrr )
        {
            print3(tmp.r_indx,tmp.c_indx,tmp.c);
            cnt++;
            for(int j=0;j<SZ(board);j++)
            {
                maze[j][tmp.c_indx]=1;
            }
        }

        pos++;
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
		cout << "Testing MonochromaticBoard (250.0 points)" << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1315670543;
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
		MonochromaticBoard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"WBWBW",
				                  "BBBBB",
				                  "WBWBW",
				                  "WBWBW"};
				_expected = 3;
				_received = _obj.theMin(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"BBBB",
				                  "BBBB",
				                  "BBBB"};
				_expected = 3;
				_received = _obj.theMin(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"BBBBB",
				                  "BBBBB",
				                  "BBBBB",
				                  "BBBBB",
				                  "BBBBB",
				                  "BBBBB",
				                  "BBBBB",
				                  "BBBBB"};
				_expected = 5;
				_received = _obj.theMin(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"WW",
				                  "WW"};
				_expected = 0;
				_received = _obj.theMin(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"BBBBBBBB",
				                  "BBBBBBBB",
				                  "BBBBBBBB",
				                  "WBWBBBWB",
				                  "BBBBBBBB"};
				_expected = 9;
				_received = _obj.theMin(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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

