#include<iostream>
using namespace std;
int score[100100];
int main()
{
    int N;
    cin>>N;
    int maxid,maxScore = -1;
    for(int i = 0;i < N;++i)
    {
        int x,y;
        cin>>x>>y;
        score[x] += y;
        if(score[x] > maxScore)
        {
            maxid = x;
            maxScore = score[x];
        }
    }
    cout<<maxid<<" "<<maxScore<<endl;
    return 0;
}