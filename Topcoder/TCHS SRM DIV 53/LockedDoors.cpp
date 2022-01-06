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

int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

vector<string>brd;

struct node
{
    int x,y,mask;
    node(int _x,int _y,int _mask)
    {
        x=_x;
        y=_y;
        mask=_mask;
    }
} ;

int vis[60][60][1<<7];

int bfs(int x,int y)
{
    int dist;
    queue<node>Q;

    Q.push(node(x,y,0));
    int r,c,msk;
    vis[x][y][0]=0;

    while(!Q.empty())
    {
        r=Q.front().x;
        c=Q.front().y;
        msk=Q.front().mask;
        Q.pop();

        if(brd[r][c]=='1') return vis[r][c][msk];

        for(int i=0;i<4;i++)
        {
            int row=r+rrr[i];
            int col=c+ccc[i];

            if(row>=0 && row<SZ(brd) && col>=0 && col<SZ(brd[0]) )
            {
                if(brd[row][col]=='#') continue;
                if(brd[row][col]=='1' || brd[row][col]=='0' || brd[row][col]=='.' )
                {
                    if( vis[row][col][msk]==-1 )
                    {
//                        vis[row][col][msk]=0;
                        vis[row][col][msk]=vis[r][c][msk]+1;
                        Q.push(node(row,col,msk));
                    }
                }
                else if( islower(brd[row][col] ) )
                {
                    int n_msk=msk|(1<<( brd[row][col] -'a') );
                    if( vis[row][col][n_msk]==-1 )
                    {
//                        vis[row][col][n_msk]=0;
                        vis[row][col][n_msk]=vis[r][c][msk]+1;
                        Q.push(node(row,col,n_msk));
                    }
                }
                else if( isupper(brd[row][col] ) )
                {
                    if( ( msk&(1<< (brd[row][col] - 'A') ) ) && (vis[row][col][msk]==-1 ) )
                    {
//                        vis[row][col][msk]=0;
                        vis[row][col][msk]=vis[r][c][msk]+1;
                        Q.push(node(row,col,msk));
                    }
                }

            }
        }
    }
    return -1;
}
class LockedDoors
 {
public:
int pathOutside(vector <string> maze)
{
    brd=maze;
    mem(vis,-1);
    int ans;

    for(int i=0;i<SZ(brd);i++)
        for(int j=0;j<SZ(brd[i]);j++)
        {
            if(brd[i][j]=='0')
            {
                ans=bfs(i,j);
                return ans;
            }
        }


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
		cout << "Testing LockedDoors (1000.0 points)" << endl << endl;
		for (int i = 0; i < 8; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1317278610;
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
		LockedDoors _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string maze[] = {"1..0",
				                 "###.",
				                 "1..."};
				_expected = 3;
				_received = _obj.pathOutside(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 1:
			{
				string maze[] = {"..0..",
				                 ".###.",
				                 "..1.A"};
				_expected = 6;
				_received = _obj.pathOutside(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 2:
			{
				string maze[] = {"f0.F..1"};
				_expected = 7;
				_received = _obj.pathOutside(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 3:
			{
				string maze[] = {"0....",
				                 ".#B#A",
				                 ".#.#.",
				                 "b#a#1"};
				_expected = 19;
				_received = _obj.pathOutside(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 4:
			{
				string maze[] = {"c.0.C.C.C.1"};
				_expected = 12;
				_received = _obj.pathOutside(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 5:
			{
				string maze[] = {"###...",
				                 "#0A.1a",
				                 "###..."};
				_expected = -1;
				_received = _obj.pathOutside(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 6:
			{
				string maze[] = {"a#c#eF.1",
				                 ".#.#.#..",
				                 ".#B#D###",
				                 "0....F.1",
				                 "C#E#A###",
				                 ".#.#.#..",
				                 "d#f#bF.1"};
				_expected = 55;
				_received = _obj.pathOutside(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 7:
			{
				string maze[] = {"0abcdef.FEDCBA1"};
				_expected = 14;
				_received = _obj.pathOutside(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
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

