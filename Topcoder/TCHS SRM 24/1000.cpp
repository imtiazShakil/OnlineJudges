#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define MAX 1000
#define mem(a,b) memset(a,b,sizeof a)

using namespace std;

struct rect
{
    int x1,x2,y1,y2;
} ;

vector<rect>rt;

vector<int>x;
vector<int>y;
map<int,int>row;
map<int,int>col;
int grid[MAX][MAX];
int rrr[]={-1,0,1,0};
int ccc[]={0,1,0,-1};

void bfs(int row,int col)
{
//    map< pair<int,int>,int>M;
//    M[mp(row,col)]=1;
    if(grid[row][col]) return ;
    grid[row][col]=1;
    queue<int>Q;
    Q.push(row);Q.push(col);
    int p,q,r,c;
    while(!Q.empty())
    {
        r=Q.front();Q.pop();c=Q.front();Q.pop();
        for(int i=0;i<4;i++)
        {
            p=r+rrr[i];q=c+ccc[i];
            if(p>=0 && q>=0 && p<(int)y.size() && q<(int)x.size() )
            {
                if( grid[p][q]==0 ) {grid[p][q]=1;Q.push(p);Q.push(q);}
            }
        }
    }

}

class SwampyLands
{
public:
	int surroundedArea(vector <string> swampy)
	{
	    rt.clear();rect tmp;row.clear();col.clear();x.clear();y.clear();
	    mem(grid,0);
	    stringstream ss;
        int val1,val2,val3,val4,len,wid;
        for(int i=0;i<(int)swampy.size();i++)
        {
            ss.clear();
            ss<<swampy[i];
            ss>>val1>>val2>>val3>>val4;
            tmp.x1=val1;
            tmp.y1=val2;
            tmp.x2=val3;
            tmp.y2=val4;

            row[val1]=1;row[val3]=1;col[val2]=1;col[val4]=1;
            rt.pb(tmp);
        }
        for(map<int,int>::iterator I=row.begin();I!=row.end();I++)  x.pb(I->first);
        for(map<int,int>::iterator I=col.begin();I!=col.end();I++) y.pb(I->first);
        row.clear();col.clear();
        for(int i=0;i<(int)x.size();i++) row[x[i]]=i;
        for(int i=0;i<(int)y.size();i++) col[y[i]]=i;

        for(int i=0;i<(int)rt.size();i++)
        {
            for(int j=col[rt[i].y1];j<col[rt[i].y2];j++ )
                for(int k=row[rt[i].x1];k<row[rt[i].x2];k++ )
                    grid[j][k]++;
        }

//        bfs(0,0);bfs(0,(int)x.size()-1);bfs((int)y.size()-1,0);bfs((int)y.size()-1,(int)x.size()-1);

        for(int i=0;i<(int)x.size();i++) {bfs(0,i);bfs((int)y.size()-1,i);}
        for(int i=0;i<(int)y.size();i++) {bfs(i,0);bfs(i,(int)x.size()-1); }

//        for(int i=0;i<(int)y.size();i++,puts(""))
//            for(int j=0;j<(int)x.size();j++)
//                cout<<grid[i][j];

        int farm=0;
        for(int i=0;i<(int)y.size();i++)
            for(int j=0;j<(int)x.size();j++)
            {
                if(grid[i][j]==0)
                {
                    wid=abs(x[j+1]-x[j]);
                    len=abs(y[i+1]-y[i]);
                    farm+= wid*len;
                }
            }
        return farm;
	}
};


template<typename T> void print( T a ) {
    cerr << a;
}

void print( long long a ) {
    cerr << a << "L";
}

void print( string a ) {
    cerr << '"' << a << '"';
}

template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}

template<typename T> void assert_eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

template<typename T> void assert_eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
void assert_eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

int main( int argc, char* argv[] )
{

	SwampyLands objectSwampyLands;

////////	//test case0
	vector <string> param00;
	param00.push_back("1 4 3 9");
	param00.push_back("1 2 9 4");
	param00.push_back("7 4 9 9");
	param00.push_back("3 9 9 11");
	int ret0 = objectSwampyLands.surroundedArea(param00);
	int need0 = 20;
	assert_eq(0,ret0,need0);

////////////	//test case1
	vector <string> param10;
	param10.push_back("5 12 16 14");
	param10.push_back("4 5 7 13");
	param10.push_back("2 3 22 7");
	param10.push_back("3 9 22 10");
	param10.push_back("11 4 13 17");
	param10.push_back("16 2 20 14");
	int ret1 = objectSwampyLands.surroundedArea(param10);
	int need1 = 28;
	assert_eq(1,ret1,need1);

////////////	//test case2
	vector <string> param20;
	param20.push_back("8 7 11 14");
	param20.push_back("7 12 10 19");
	param20.push_back("2 14 9 17");
	param20.push_back("9 18 21 21");
	param20.push_back("6 11 18 13");
	param20.push_back("18 6 20 18");
	param20.push_back("9 4 21 7");
	int ret2 = objectSwampyLands.surroundedArea(param20);
	int need2 = 67;
	assert_eq(2,ret2,need2);

//////////////	//test case3
	vector <string> param30;
	param30.push_back("1 4 3 9");
	param30.push_back("1 2 9 4");
	param30.push_back("7 4 9 9");
	param30.push_back("4 9 9 11");
	int ret3 = objectSwampyLands.surroundedArea(param30);
	int need3 = 0;
	assert_eq(3,ret3,need3);

////////////	//test case4
	vector <string> param40;
	param40.push_back("2 1 3 2");
	param40.push_back("1 2 2 3");
	param40.push_back("2 3 3 4");
	param40.push_back("3 2 4 3");
	param40.push_back("5 2 6 3");
	param40.push_back("6 1 7 2");
	param40.push_back("6 3 7 4");
	param40.push_back("7 2 8 3");
	int ret4 = objectSwampyLands.surroundedArea(param40);
	int need4 = 2;
	assert_eq(4,ret4,need4);

}

