#include<iostream>
using namespace std;
int main()
{
    int  N,M;
    cin>>N>>M;
    for(int i = 0;i < N;++i)
    {
        int sum = 0  , cnt = 0;
        int teacher ;
        cin>>teacher;

        int max_score = -1, min_score = 1 << 30;
        for(int j = 1 ;j < N;++j)
        {
            int num;
            cin>>num;
            if(num >= 0 && num <= M)
            {
                if(max_score < num)
                {
                    max_score = num;
                }
                if(min_score > num)
                {
                    min_score = num;
                }
                sum += num;
                ++cnt;
            }
        }
        cnt -= 2;
        int res = (teacher + (sum - max_score - min_score) /(cnt * 1.0))/2 + 0.5;
        cout<<res<<endl;
    }
    return 0;
}