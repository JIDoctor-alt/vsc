#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int N;
vector<int> vs;
int main()
{
    int sum = 0,cur = 0;
    cin>>N;
    for(int i = 0;i < N;++i)
    {
       int num;
       cin>>num;
       if(num  > cur)
         sum += (num - cur)*6;
        else 
         sum += (cur - num)*4;
       cur = num;
    }

    sum += 5*N;
    cout<<sum<<endl;


    return 0;
}