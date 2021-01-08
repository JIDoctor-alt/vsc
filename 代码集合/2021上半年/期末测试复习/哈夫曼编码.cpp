#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
    string str;
    while(cin>>str && str != "END")
    {
        sort(str.begin(),str.end());
        int len = str.length();
        int j;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 0;i < len;++i)
        {
            j = i;
            while(str[j] == str[j + 1] && j < len - 1)
                ++j;
            pq.push(j - i + 1);
            i = j;
        }
        int ans = (pq.size() == 1 ? pq.top() : 0);
        while(pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            ans += (a + b);
            pq.push(a+b);
        }
        cout<<8 * len<<" "<<ans<<" ";
        cout<<fixed<<setprecision(1)<<(8 * len)/(ans * 1.0)<<endl;
    }
    return 0;
}