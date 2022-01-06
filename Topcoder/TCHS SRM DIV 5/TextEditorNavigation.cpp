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
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<endl
#define PI (2*acos(0))
#define ERR 1e-5
#define ll long long
#define VI vector<int>
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x.begin(),x.end())
#define mp make_pair

#define MAX 60
#define SZ(x) (int)x.size()
using namespace std;


int dist[MAX][MAX];
int  rrr[]={-1,0,1,0};
int  ccc[]={0,1,0,-1};

vector<string>v;

void bfs(int x,int y)
{
    map<pair<int,int>,int>M;
    M[mp(x,y)]=1;
    queue<int>Q;
    Q.push(x);Q.push(y);
    dist[x][y]=0;

    int row,col,p,t;
    while(!Q.empty())
    {
        row=Q.front();Q.pop();
        col=Q.front();Q.pop();
//        cout<<" row "<<row<<" col "<<col<<endl;
        for(int i=0;i<4;i++)
        {
            p=row+rrr[i];
            t=col+ccc[i];
            if(p>=0 && t>=0 && p<SZ(v) )
            {
                if(t<SZ(v[p])  && M.find(mp(p,t))==M.end() )
                {
                    dist[p][t]=dist[row][col]+1;
                    M[mp(p,t)]=1;
                    Q.push(p);Q.push(t);
                }
            }
        }
        if(M.find(mp(row,0))==M.end() )
        {
            dist[row][0]=dist[row][col]+1;M[mp(row,0)]=1;Q.push(row);Q.push(0);
        }
        if(M.find(mp(row,SZ(v[row]) -1 ) )==M.end() )
        {
            dist[row][SZ(v[row]) -1 ]=dist[row][col] +1;M[mp(row,SZ(v[row]) -1)]=1;Q.push(row);Q.push(SZ(v[row])-1);
        }
        if( SZ(v[0])>col )
        {
            if(M.find(mp(0,col))==M.end() )
            {
                dist[0][col]=dist[row][col]+1;M[mp(0,col)]=1;Q.push(0);Q.push(col);
            }
        }

        if( SZ(v[ SZ(v) -1]) >col )
        {
            if(M.find(mp(SZ(v) -1,col)) ==M.end())
            {
                dist[SZ(v)-1][col]=dist[row][col]+1;M[mp(SZ(v)-1,col)]=1;Q.push(SZ(v)-1);Q.push(col);
            }
        }
        int j,q;
        for(j=col-2;j>=0;j--)
        {
            if( !isalpha(v[row][j])  && isalpha(v[row][j+1]) )
            {
                if(M.find(mp(row,j+1))==M.end())
                {
                    dist[row][j+1]=dist[row][col]+1;
                    M[mp(row,j+1)]=1;Q.push(row);Q.push(j+1);

                }
                break;
            }
        }
          bool flag=0;
          for(j=col;j<=50;j++)
          {
              if(!isalpha(v[row][j]) && isalpha(v[row][j+1]) )
              {
                  if(M.find(mp(row,j+1))==M.end())
                    {
                        dist[row][j+1]=dist[row][col]+1;
                        M[mp(row,j+1)]=1;Q.push(row);Q.push(j+1);

                    }
                    flag=1;
                    break;
              }
          }
         if(flag==0)
         {
             for(j=col;j<=50;j++)
             {
                 if(isalpha(v[row][j]) && !isalpha(v[row][j+1])   )
                 {
                  if(M.find(mp(row,j))==M.end())
                    {
                        dist[row][j]=dist[row][col]+1;
                        M[mp(row,j)]=1;Q.push(row);Q.push(j);

                    }
//                    flag=1;
                    break;
                }
             }
         }
    }
    return ;
}






class TextEditorNavigation
 {
public:
int keystrokes(vector <string> source, vector <int> start, vector <int> finish)
{
      v=source;
    for(int i=0;i<SZ(v);i++)
    {
        while( SZ(v[i])<=50 ) v[i]+=" ";
    }
    bfs(start[0],start[1]);

    return dist[finish[0]][finish[1]];
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
		cout << "Testing TextEditorNavigation (1000.0 points)" << endl << endl;
		for (int i = 0; i < 8; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1309336103;
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
		TextEditorNavigation _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string source[] = {"AAAAA AAA AAAAAAAAAAAAA  AAAA",
				                   "AA   AAAAAAAAA AAAA     AAAA",
				                   "BBBBBBBBBBBBBBBBBBBBBBBBBBB",
				                   "BBBBBBB BBBBBBBBBB BBBBBBB",
				                   "CCC CCCC CCCCCC      CCCC",
				                   "DDDDDDDDDDDDDDDDDDD"};
				int start[] = {5, 7};
				int finish[] = {2, 2};
				_expected = 6;
				_received = _obj.keystrokes(vector <string>(source, source+sizeof(source)/sizeof(string)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(finish, finish+sizeof(finish)/sizeof(int))); break;
			}
			case 1:
			{
				string source[] = {"A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "BB BB BB BB BB BB BB BB BB BB BB BB BB BB BB BB BB",
				                   "CCC CCC CCC CCC CCC CCC CCC CCC CCC CCC CCC CCC CC",
				                   "DDDD DDDD DDDD DDDD DDDD DDDD DDDD DDDD DDDD DDDD ",
				                   "EEEEE EEEEE EEEEE EEEEE EEEEE EEEEE EEEEE EEEEE EE",
				                   "FFFF FFFF FFFF FFFF FFFF FFFF FFFF FFFF FFFF FFFF ",
				                   "GGG GGG GGG GGG GGG GGG GGG GGG GGG GGG GGG GGG GG",
				                   "HHHHHHHHHHH HHHHHHHHHH HHHHHHHHHH HHHHHHHHHH HHHHH",
				                   "IIIIIIIIIIIIIII IIIIIIIIIIIIIII IIIIIIIIIIIIIII   ",
				                   "JJJJJJJJ JJJJJJJJ JJJJJJJJ JJJJJJJJ JJJJJJJJ JJJJJ",
				                   "KKKKKKKKKKKKKKKKKKKKKKKKKK KKKKKKKKKKKKKKKKKKKKKKK",
				                   "LLLLLLLLLL LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL",
				                   "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
				                   "N N N N N N N N N N N N N N N N N N N N N N N N N ",
				                   "OOOOO OOOO OOO OO O O OO OOO OOOO OOOOO OOOOOO OOO",
				                   "PPPPPPP PPPPPP PPPPP PPPP PPP PP P P PP PPP PPPP P",
				                   "QQQQQQ QQQQQ QQQQ QQQ QQ Q Q QQ QQQ QQQQ QQQQQ QQQ",
				                   "ZZZZ ZZ ZZZ ZZ ZZZZ ZZ ZZZ ZZ ZZZZ ZZ ZZZ ZZ ZZZZ ",
				                   "SSS S SSS S SSS S SSS S SSS S SSS S SSS S SSS S SS",
				                   "TT TT TT TT TT TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT"};
				int start[] = {12, 20};
				int finish[] = {4, 36};
				_expected = 8;
				_received = _obj.keystrokes(vector <string>(source, source+sizeof(source)/sizeof(string)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(finish, finish+sizeof(finish)/sizeof(int))); break;
			}
			case 2:
			{
				string source[] = {"A A A A AAAAAAA A A A A A A A A A A",
				                   "B BBBBB B B B B BBBBB B B B B B B B B"};
				int start[] = {1, 0};
				int finish[] = {1, 22};
				_expected = 6;
				_received = _obj.keystrokes(vector <string>(source, source+sizeof(source)/sizeof(string)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(finish, finish+sizeof(finish)/sizeof(int))); break;
			}
			case 3:
			{
				string source[] = {"AAAAAAAAAAAAAA A A A A A A A A A A"};
				int start[] = {0, 2};
				int finish[] = {0, 15};
				_expected = 1;
				_received = _obj.keystrokes(vector <string>(source, source+sizeof(source)/sizeof(string)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(finish, finish+sizeof(finish)/sizeof(int))); break;
			}
			case 4:
			{
				string source[] = {"A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "N N N N N N N N N N N N N N N N N N N N N N N N N ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   "A A A A A A A A A A A A A A A A A A A A A A A A A ",
				                   " O O O O O O O O O O O O OO O O O O O O O O O O O ",
				                   " P P P P P P P P P P P P P PP P P P P P P P P P P ",
				                   " Q Q Q Q Q Q Q Q Q Q Q Q Q Q QQ Q Q Q Q Q Q Q Q Q ",
				                   " R R R R R R R R R R R R R R R RR R R R R R R R R ",
				                   " S S S S S S S S S S S S S S S S SS S S S S S S S ",
				                   " T T T T T T T T T T T T T T T T T TT T T T T T T ",
				                   " U U U U U U U U U U U U U U U U U U UU U U U U U ",
				                   " V V V V V V V V V V V V V V V V V V V VV V V V V ",
				                   " W W W W W W W W W W W W W W W W W W W W WW W W W ",
				                   " X X X X X X X X X X X X X X X X X X X X X XX X X ",
				                   " Y Y Y Y Y Y Y Y Y Y Y Y Y Y Y Y Y Y Y Y Y Y YY Y ",
				                   " Z Z Z Z Z Z Z Z Z Z Z Z Z Z Z Z Z Z Z Z Z Z Z ZZZ"};
				int start[] = {49, 49};
				int finish[] = {38, 26};
				_expected = 23;
				_received = _obj.keystrokes(vector <string>(source, source+sizeof(source)/sizeof(string)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(finish, finish+sizeof(finish)/sizeof(int))); break;
			}
			case 5:
			{
				string source[] = {"AAA", "BB", "CCC"};
				int start[] = {1, 1};
				int finish[] = {1, 1};
				_expected = 0;
				_received = _obj.keystrokes(vector <string>(source, source+sizeof(source)/sizeof(string)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(finish, finish+sizeof(finish)/sizeof(int))); break;
			}
			case 6:
			{
				string source[] = {"AAAAA AAA AAAAAAAAAAAAA  AAAA",
				                   "AA   AAAAAAAAA AAAA     AAAA",
				                   "BBBBBBBBBBBBBBBBBBBBBBBBBBB",
				                   "BBBBBBB BBBBBBBBBB BBBBBBB",
				                   "CCC CCCC CCCCCC      CCCC",
				                   "DDDDDDDDDDDDDDDDDDD"};
				int start[] = {2, 17};
				int finish[] = {1, 2};
				_expected = 4;
				_received = _obj.keystrokes(vector <string>(source, source+sizeof(source)/sizeof(string)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(finish, finish+sizeof(finish)/sizeof(int))); break;
			}
			case 7:
			{
				string source[] = {"A PC to do CAD huh  Sounds reasonable",
				                   "Aurthor go out and buy us five new PCs",
				                   "Dont you want to think about this for a minute",
				                   "No every second counts and we want to be ahead of",
				                   "the competition",
				                   "       OK Greate idea Please place lOOk worth of",
				                   "unmarked bills in my suitcase and Ill be on my way"};
				int start[] = {0, 11};
				int finish[] = {1, 15};
				_expected = 2;
				_received = _obj.keystrokes(vector <string>(source, source+sizeof(source)/sizeof(string)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(finish, finish+sizeof(finish)/sizeof(int))); break;
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

