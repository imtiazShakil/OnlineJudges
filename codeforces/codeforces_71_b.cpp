#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>

#define mem(a,b) memset(a,b,sizeof a)
#define MAX 40020
using namespace std;


//int  mat[MAX][MAX];

vector< pair<int,int> >v;
int main(void)
{
    int n,m,k,t,a,b;
    while(scanf("%d %d %d %d",&n,&m,&k,&t)==4)
    {
//        mem(mat,0);
        v.clear();
       for(int i=0;i<k;i++)
       {
           scanf("%d %d",&a,&b);
//           puts("inp_1");
            v.push_back(make_pair(a,b));
       }

        int total,cnt;
        for(int i=0;i<t;i++)
        {
            scanf("%d %d",&a,&b);
//            puts("inp_2");
            total=((a-1)*m) + b;
//            printf("tot %d   ",total);
            cnt=0;
            bool flag=0;

            for(int p=0;p<(int)v.size();p++)
            {
                   if(v[p].first==a && v[p].second==b)
                   {
                       printf("Waste\n");flag=1;break;
                   }
                    else if(v[p].first<=a)
                    {
                        if(v[p].first==a)
                        {
                            if(v[p].second <b ) cnt++;
                        }
                        else cnt++;
                    }
            }
//            printf("cnt %d  \n",cnt);
            if(flag) continue;
            total-=cnt;

            if((total%3 )==0 ) printf("Grapes\n");
            else if((total%3 )==1 ) printf("Carrots\n");
            else if((total%3 )==2 ) printf("Kiwis\n");


        }
    }

    return 0;
}
