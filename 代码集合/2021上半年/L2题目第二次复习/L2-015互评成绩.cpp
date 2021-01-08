#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
vector<double> stu;
int main()
{
    int N,K,M;
    cin>>N>>K>>M;
    for(int i = 0;i < N;++i)
    {
        double sum = 0,max_score = -1,min_score = 1<<30;

        for(int j = 0;j < K;++j)
        {
            double score;
            cin>>score;
            if(score > max_score)
                max_score = score;
            if(score < min_score)
                min_score = score;
            sum += score;
        }
        sum -= (min_score + max_score);
        sum /= (K-2);
        stu.push_back(sum);
    }
    sort(stu.begin(),stu.end(),[](double &e1,double &e2){return e1 < e2;});
    for(int i = stu.size() - M;i < stu.size();++i)
    {
        cout<<fixed<<setprecision(3)<<stu[i];
        if(i != stu.size() - 1)
            cout<<" ";
        else 
            cout<<"\n";

    }
    return 0;
}