#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_V = 110;
struct edge
{
    int answer,score;
};
edge stu[MAX_V];
int main()
{
    int N,M;
    cin>>N>>M;
    for(int i = 0;i < M;++i)
    {
        cin>>stu[i].score;
    }
    for(int i = 0;i < M;++i)
    {
        cin>>stu[i].answer;
    }

    for(int i = 0;i < N;++i)
    {
        int sum = 0;
        for(int j = 0;j < M;++j)
        {
            int search;
            cin>>search;
            if(search == stu[j].answer)
                sum += stu[j].score;
        }
        cout<<sum<<endl;
    }
    return 0;
}