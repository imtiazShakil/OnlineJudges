#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

#define mem(a,b) memset(a,b,sizeof a)
#define MAX 2010
#define mp make_pair
#define pb push_back

using namespace std;

int mat[MAX][MAX],mx_r,mx_c;
string op;
int rrr[]={-1,0,1,0};
int ccc[]={0,1,0,-1};




void bfs(int row,int col)
{
    mat[row][col]=1;
    queue<int>Q;
    Q.push(row);Q.push(col);
    int p,q,r,c;
    while(!Q.empty())
    {
        r=Q.front();Q.pop();c=Q.front();Q.pop();
        for(int i=0;i<4;i++)
        {
            p=r+rrr[i];
            q=c+ccc[i];
            if(p>=0 && q>=0 && p<=mx_r && q<=mx_c )
            {
                if( mat[p][q]==0 )
                {
                    Q.push(p);Q.push(q);
                    mat[p][q]=1;
                }
            }
        }
    }
    return ;
}


class CuttingGlass
{
public:
	int pieces(int W, int H, int startx, int starty, vector <string> program)
	{
        int row=starty*2,col=startx*2;mem(mat,0);mx_c=W*2;mx_r=H*2;

        op.clear();
        for(int i=0;i<(int)program.size();i++) op+=program[i];

        for(int i=0;i<=W*2;i++) {mat[0][i]=1;mat[H*2][i]=1; }
        for(int i=0;i<=H*2;i++) {mat[i][0]=1;mat[i][W*2]=1; }

        for(int i=0;i<(int)op.size();i++)
        {
            if(op[i]=='U')
            {
                row--;mat[row][col]++;row--;mat[row][col]++;
            }
            else if(op[i]=='D')
            {
                row++;mat[row][col]++;row++;mat[row][col]++;
            }
            else if(op[i]=='L')
            {
                col--;mat[row][col]++;col--;mat[row][col]++;
            }
            else if(op[i]=='R')
            {
                col++;mat[row][col]++;col++;mat[row][col]++;
            }

        }

        int count=0;
//        for(int i=0;i<=H*2;i++,puts(""))
//            for(int j=0;j<=W*2;j++) cout<<mat[i][j];

        for(int i=0;i<=H*2;i++)
        {
            for(int j=0;j<=W*2;j++)
            {
                if( mat[i][j]==0 )
                {
                    bfs(i,j);
                    count++;
                }
            }
        }
        return count;
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

	CuttingGlass objectCuttingGlass;

////////	//test case0
	int param00 = 100;
	int param01 = 100;
	int param02 = 50;
	int param03 = 50;
	vector <string> param04;
	param04.push_back("ULDR");
	int ret0 = objectCuttingGlass.pieces(param00,param01,param02,param03,param04);
	int need0 = 2;
	assert_eq(0,ret0,need0);

////////	//test case1
	int param10 = 10;
	int param11 = 10;
	int param12 = 3;
	int param13 = 4;
	vector <string> param14;
	param14.push_back("UDUDUDUDUDU");
	int ret1 = objectCuttingGlass.pieces(param10,param11,param12,param13,param14);
	int need1 = 1;
	assert_eq(1,ret1,need1);

//////////	//test case2
	int param20 = 3;
	int param21 = 3;
	int param22 = 0;
	int param23 = 0;
	vector <string> param24;
	param24.push_back("RDDDUUU");
	param24.push_back("RDDDUUU");
	param24.push_back("R");
	param24.push_back("DLLLRRR");
	param24.push_back("DLLL");
	int ret2 = objectCuttingGlass.pieces(param20,param21,param22,param23,param24);
	int need2 = 9;
	assert_eq(2,ret2,need2);

////////	//test case3
	int param30 = 5;
	int param31 = 3;
	int param32 = 5;
	int param33 = 3;
	vector <string> param34;
	param34.push_back("LULLULLU");
	int ret3 = objectCuttingGlass.pieces(param30,param31,param32,param33,param34);
	int need3 = 2;
	assert_eq(3,ret3,need3);

}

