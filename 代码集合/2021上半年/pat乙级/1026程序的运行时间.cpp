#include<iostream>
#include<iomanip>
using namespace std;
const int CLK_TCKS = 100;
//注意输出格式
int main()
{
    double c1,c2;
    cin>>c1>>c2;
    double sum  = c2 - c1;
    int hh = sum/(60*60)/CLK_TCKS;
    int mm = (sum - hh * 60 *60 * CLK_TCKS)/60/CLK_TCKS;
    int ss = (sum - hh * 60 * 60 * CLK_TCKS - mm * 60 * CLK_TCKS)/CLK_TCKS + 0.5;
    //cout<<fixed<<setw(2)<<setfill('0')<<hh<<":"<<mm<<":"<<ss<<endl;
    printf("%02d:%02d:%02d",hh,mm,ss);
    return 0;
}