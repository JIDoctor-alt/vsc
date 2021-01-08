#include<iostream>
#include<vector>
#include<set>
#include<cmath>
using namespace std;
using pii = pair<int,int>;
int judge(int x)
{
    if(x == 1)
        return 1;
    for(int i = 2;i <= sqrt(x);++i)
    {
        if(x % 2 == 0)
            return 1;
    }
    return 2;
}
int main()
{
    int a,b;
    cin>>a>>b;
    set<int> stu;
    vector<pii> res;
    for(int i = a;i <= b;++i)
    {
        int sum;
        int y = i;
        set<int> ans;
        bool flag = true;
        while(y != 1)
        {
            sum = 0;
            while(y)
            {
                sum += (y%10)*(y%10);
                y /= 10;
            }
            
            y = sum;
            stu.insert(y);

            if(ans.count(y))
            {
                flag = false;
                break;
            }

            ans.insert(y);//计算依附他的数的个数
        }
        int x = ans.size() * judge(i);
        if(flag)
        {
            res.push_back({i,x});
        }
    }

    int cnt = 0;
    for(auto &e : res)
    {
        if(!stu.count(e.first))
        {
            cout<<e.first<<" "<<e.second<<endl;
            ++cnt;
        }
    }

    if(cnt == 0)
    {
        cout<<"SAD\n";
    }
    return 0;
}