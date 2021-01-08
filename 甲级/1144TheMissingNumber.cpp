#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int N;
int main()
{
    cin>>N;
    map<int,int> MarkArray;
    for(int i = 0;i < N;++i)
    {
        int num;
        cin>>num;
        MarkArray[num]++;
    }
    int i = 1;
    for(;i <= N;++i)
    {
        if(MarkArray[i] == 0)
            break;
    }
    cout<<i<<endl;
    return 0;
}