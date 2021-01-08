#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int N,p;
    cin>>N>>p;
    vector<int> stu;
    for(int i = 0;i < N;++i)
    {
        int num;
        cin>>num;
        stu.push_back(num);
    }
    sort(stu.begin(),stu.end());
    int max_le = -1;
    for(int i = 0;i < N;++i)
    {
        for(int j = i;j < N;++j)
        {
            int a = stu[i],b = stu[j];
            if(b <= a * p)
            {
                if(max_le < j - i + 1)
                {
                    max_le = j - i + 1;
                }
            }
            
        }
    }
    cout<<max_le<<endl;
    return 0;
}