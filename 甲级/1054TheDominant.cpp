#include<iostream>
#include<map>
#include<string>
using namespace std;
string answer;
map<string,int> ms;
int M,N,max_cnt = 0;
int main()
{
    cin>>M>>N;
    for(int i = 0;i < M;++i)
    {
        for(int j = 0;j < N;++j)
        {
            string color;
            cin>>color;
            ms[color]++;
            if(max_cnt < ms[color])
            {
                max_cnt = ms[color];
                answer = color;
            }
        }
    }
    cout<<answer<<endl;
    return 0;;
}