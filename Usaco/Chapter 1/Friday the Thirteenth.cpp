#include <stdio.h>
#include <iostream>
#include <string.h>

#define mem(a,b) memset(a,b,sizeof a)

using namespace std;
int dys_mon[]={31,28,31,30,31,30,31,31,30,31,30,31};
int freq[10];

bool chk_lp_yr(int year)
{
    if(year%4==0)
    {
        if(year%100==0)
        {
            if(year%400==0) return true;
            else return false;
        }
        else return true;
    }
    else return false;
}

void gv_week_nam(int year)
{
    int days=0;
    bool leap;
    for(int i=1990;i<=year;i++)
    {
        if(chk_lp_yr(i)) leap=1;
        else leap=0;
        printf("i %d leap %d\n",i,leap);
        for(int j=0;j<12;j++)
        {
             freq[ ( (days+13)%7 + 2) %7 ]++;

             if(j==1 && leap==1) {days+=(dys_mon[j] +1);puts("www");}
             else days+=dys_mon[j];

             days%=7;
        }
//        if(chk_lp_yr(i)) days+=366;
//        else days+=365;
    }

//    for(int i=0;i<month;i++) days+=dys_mon[i];

//    days+=13;
//    if(chk_lp_yr(year) && month>1) days++;
//
//    return days%7;
    return ;
}
int main(void)
{
    int n,day;
    while(scanf("%d",&n)==1)
    {
        mem(freq,0);
        gv_week_nam(1990+n-1);
        for(int i=1;i<=6;i++)
        {
            if(i==1) printf("%d",freq[i]);
            else printf(" %d",freq[i]);
        }
        printf(" %d\n",freq[0]);

    }

    return 0;
}
