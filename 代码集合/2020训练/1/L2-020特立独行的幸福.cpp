#include<iostream>
#include<set>
#include<vector>
#include<math.h>
using namespace std;
using pii = pair<int,int>;
int judge(int x)
{
    if(x == 1)
        return 2;
    for(int i = 2;i <= sqrt(x);++i)
    {
        if(x % i == 0)
            return 1;
    }
    return 2;
}
int  main()
{
    int a,b;
    cin>>a>>b;
    set<int> st;
    vector<pii> answer;

    for(int i = a;i <= b;++i)
    {
      
        if(st.count(i))
            continue;
        
        int y = i;
        
        set<int> cnt;

        while(y != 1)
        {
            int sum = 0;
        
            while(y)
            {
                sum += (y%10)*(y%10);
                y /= 10;
            }

            if(cnt.count(sum))
                break;

            cnt.insert(sum);

            st.insert(sum);
            y = sum;
        }

        if(y == 1)
        {
            int num = cnt.size() * judge(i);
            answer.push_back({i,num});
        }
    }
    int ans = 0;
    for(auto &c : answer)
    {
       if(!st.count(c.first))
        {
            ++ans;
            cout<<c.first<<" "<<c.second<<endl;
        }
    }
    
    if(ans == 0)
        cout<<"SAD\n";
    return 0;
}