#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;
int N;
map<int,int> ms;
set<int> st;
int main()
{
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        int k;
        cin>>k;
        for(int j = 0;j < k;++j)
        {
            int id;
            cin>>id;
            if(ms[id] < k)
                ms[id] = k;
        }
    }

    int m,cnt = 0;
    cin>>m;
    while (m--)
    {
        int xid;
        cin>>xid;
        if(!st.count(xid)&&ms[xid]<= 1){
                if(cnt != 0)
                    cout<<" ";
                printf("%05d",xid);
                ++cnt;
        }
        st.insert(xid);
        
    }
    if(!cnt)
        cout<<"No one is handsome"<<endl;
    

    return 0;
}