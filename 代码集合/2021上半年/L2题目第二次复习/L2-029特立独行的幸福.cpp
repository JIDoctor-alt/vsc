#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cmath>
using namespace std;
using pii = pair<int,int>;
int find(int x)
{
    if(x == 1)
        return 1;
    for(int i = 2;i <= sqrt(x);++i)
    {
        if(x%i == 0)
            return 1;
    }
    return 2;
}
int main()
{
    int A,B;
    cin>>A>>B;
    map<int,bool> ms;
    vector<pii> ps;
    for(int i = A; i<= B;++i)
    {
        bool flag = true;
        int su = i;
        set<int> st;
        int sum = 0;
        while (su != 1)
        {
            sum = 0;
            while(su)
            {
                sum += (su%10)*(su%10);
                su /= 10;
            }
            su = sum;
            ms[su] = true;
            if(st.count(su))
            {
                flag = false;
                break;
            }

            st.insert(su);
        }
        int stize = st.size() * find(i);  
        if(flag)
         {
                  ps.push_back({i,stize}); 
         }
    }
    int resFlag = 0;
    for(auto w : ps)
    {
        if(!ms[w.first])
        {
              cout<<w.first<<" "<<w.second<<endl;
              ++resFlag;
        }
      
    }
    if(!resFlag)
        cout<<"SAD"<<endl;
    return 0;
}