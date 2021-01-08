#include<iostream>
using namespace std;
int Score[105],answers[105];
int M,N;
int main()
{
    cin>>N>>M;

    for(int i = 0;i < M;++i)
    {
        cin>>Score[i];
    }
    for(int i = 0;i < M;++i)
    {
        cin>>answers[i];
    }
    for(int i = 0;i < N;++i)
    {
        int sum  = 0;
        for(int j = 0;j < M;++j)
        {
            int choice;
            cin>>choice;
            if(choice == answers[j])
                sum += Score[j];
        }
        cout<<sum<<endl;
    }
    return 0;
}