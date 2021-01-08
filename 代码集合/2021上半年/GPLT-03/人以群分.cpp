#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int N;
    cin>>N;
    vector<int> stu;
    int sum1  = 0;
    for(int i = 0;i < N;i++)
    {
        int num;
        cin>>num;
        sum1 += num;
        stu.push_back(num);
    }
    sort(stu.begin(),stu.end());
    int sum = 0;
    for(int i = 0;i < N/2;i++)
        sum += stu[i];
    cout<<"Outgoing #: "<<(N - N/2)<<endl;
    cout<<"Introverted #: "<<(N/2)<<endl;
    cout<<"Diff = "<<sum1 - 2*sum<<endl;
    return 0;
}