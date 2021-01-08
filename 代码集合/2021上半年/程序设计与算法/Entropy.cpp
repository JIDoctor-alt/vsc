#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<iomanip>
using namespace std;
int main()
{
    string str;
    while(cin>>str,str!= "END")
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(str.begin(),str.end());
        for(int i = 0;i < str.length();)
        {
            int j = i;
            while(j + 1 < str.length() && str[j] == str[j+1])
                ++j;
            //字母个数
            pq.push(j-i+1);
            i = ++j;
        }
        int ans = pq.size() == 1 ? pq.top() : 0;
        while(pq.size() > 1)
        {
            int a  = pq.top();
            pq.pop();
            int b = pq.top();
            cout<<a<<" "<<b<<endl;
            pq.pop();
            ans += (a+b);
            pq.push(a+b);
        }
        cout<<8 * str.length()<<" "<<ans<<" ";
        cout<<fixed<<setprecision(1)<<8.0 * str.length()/ans<<endl;
    }
    return 0;
}