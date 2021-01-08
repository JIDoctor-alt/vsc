#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
vector<double> st;
int N,K,M;
int main()
{
    cin>>N>>K>>M;
    for(int i = 0;i < N;++i)
    {
        double minScore = 1<<30,maxScore = -1;
        double sumScore = 0;
        for(int j = 0;j < K;++j)
        {
            double score;
            cin>>score;
            if(score > maxScore)
                maxScore = score;
            if(score < minScore)
                minScore = score;
            sumScore += score;
        }
        sumScore -= (maxScore + minScore);
        sumScore = sumScore / (K-2);
        st.push_back(sumScore);
    }
    sort(st.begin(),st.end());
    for(int i = N - M  ; i < N;++i)
    {
        if(i != N - M)
            cout<<" ";
        cout<<fixed<<setprecision(3)<<st[i];
    }
    return 0;
}