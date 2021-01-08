#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;
bool cmp(double & a,double & b){
    return a < b;
}
int main(){
    int N,K,M;
    cin>>N>>K>>M;
    
    vector<double> stu;
    for(int i = 0;i < N;i++){
            int score,sum = 0;
            int maxScore = -1,minScore = 1 << 30;
          for(int j = 0;j < K;j++){
              cin>>score;
              sum += score;
              if(maxScore < score)
                 maxScore = score;
                if(minScore > score)
                minScore = score;
          }  
          double s = (sum-minScore-maxScore)/(1.0*(K-2));
          stu.push_back(s);
    }

    sort(stu.begin(),stu.end(),cmp);
    int flag = 0;
    for(int i = N-M;i < N;i++){
        if(flag)cout<<" ";
        cout<<fixed<<setprecision(3)<<stu[i];
        flag = 1;
    }
    return 0;
}