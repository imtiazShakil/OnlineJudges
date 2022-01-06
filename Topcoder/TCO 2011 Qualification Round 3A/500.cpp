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
#include <stdlib.h>

using namespace std;

struct machine
{
    int need;
    int give;
};
vector<machine>v;

bool com(machine a ,machine b)
{
    int loss1=a.need-a.give;
    int loss2=b.need-b.give;

    if(loss1==loss2)
    {
        if(a.need<b.need) return true;
        else return false;
    }
    if(loss1<loss2) return true;
    else return false;
}
int  sol(int coin)
{
    for(int i=0;i<(int)v.size();i++)
    {
        if(coin>=v[i].need) return i;
    }
    return -1;
}

class CoinMachinesGame
{
public:
	int maxGames(int coins, vector <int> need, vector <int> give)
	{
	    int n,g,val;
	    machine tmp;
	    v.clear();
        for(int i=0;i<(int)need.size();i++)
        {
            tmp.need=need[i];tmp.give=give[i];
            v.push_back(tmp);
        }
        sort(v.begin(),v.end(),com);
        for(int i=0;i<(int)need.size();i++)
        {
            cout<<"loss "<<v[i].need-v[i].give<<"  need  "<<v[i].need<<"  give  "<<v[i].give<<endl;

        }
        int turns=0,itm,loss,new_coin;
        double db;
        while(1)
        {
            val=sol(coins);
            if(val==-1) break;

            loss=v[val].need-v[val].give;

//            coins=coins-loss;

//            itm= floor( (double)(coins-v[val].need)/(double)loss )  + 1;

            db=floor( (double)(coins-v[val].need)/(double)loss )  + 1.0;
            cout<<db<<endl;
            itm=db;

            new_coin=coins + (itm)*(-1*loss) ;
            cout<<"itm "<<itm<<endl;
            cout<<"new coins "<<new_coin<<endl;

//            if(itm==1)
//            {
//                new_coin=coins-loss;
//            }

            if(new_coin>=v[val].need)
            {
                itm++;
                new_coin=new_coin-loss;
            }
//            else
//            {
                turns+=itm;
                coins=new_coin;
                cout<<"itm "<<itm<<endl;
                cout<<"coins "<<coins<<endl;
//            }

//            turns++;
        }
//        --turns;
//        cout<<"turns "<<turns<<endl;
        return turns;
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

	CoinMachinesGame objectCoinMachinesGame;

	//test case0
	int param00 = 10;
	vector <int> param01;
	param01.push_back(5);
	param01.push_back(3);
	vector <int> param02;
	param02.push_back(4);
	param02.push_back(1);
	int ret0 = objectCoinMachinesGame.maxGames(param00,param01,param02);
	int need0 = 7;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 1000;
	vector <int> param11;
	param11.push_back(16);
	param11.push_back(14);
	param11.push_back(11);
	param11.push_back(7);
	vector <int> param12;
	param12.push_back(15);
	param12.push_back(12);
	param12.push_back(8);
	param12.push_back(3);
	int ret1 = objectCoinMachinesGame.maxGames(param10,param11,param12);
	int need1 = 988;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 1000000000;
	vector <int> param21;
	param21.push_back(1000);
	param21.push_back(900);
	param21.push_back(800);
	param21.push_back(700);
	param21.push_back(600);
	param21.push_back(500);
	param21.push_back(400);
	param21.push_back(300);
	param21.push_back(200);
	param21.push_back(100);
	vector <int> param22;
	param22.push_back(701);
	param22.push_back(802);
	param22.push_back(503);
	param22.push_back(604);
	param22.push_back(405);
	param22.push_back(306);
	param22.push_back(107);
	param22.push_back(208);
	param22.push_back(1);
	param22.push_back(1);
	int ret2 = objectCoinMachinesGame.maxGames(param20,param21,param22);
	int need2 = 10869564;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 12345678;
	vector <int> param31;
	param31.push_back(342);
	param31.push_back(234);
	param31.push_back(65);
	param31.push_back(76);
	param31.push_back(85);
	param31.push_back(734);
	param31.push_back(67);
	param31.push_back(345);
	param31.push_back(70);
	param31.push_back(234);
	vector <int> param32;
	param32.push_back(45);
	param32.push_back(78);
	param32.push_back(3);
	param32.push_back(10);
	param32.push_back(45);
	param32.push_back(12);
	param32.push_back(45);
	param32.push_back(57);
	param32.push_back(1);
	param32.push_back(230);
	int ret3 = objectCoinMachinesGame.maxGames(param30,param31,param32);
	int need3 = 3086370;
	assert_eq(3,ret3,need3);

}

