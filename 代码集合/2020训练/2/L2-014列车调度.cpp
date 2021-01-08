#include<iostream>
#include<set>
using namespace std;
int N;
int main()
{
    cin>>N;
    set<int> st;
    for(int i = 0;i < N;++i)
    {
        int x;
        cin>>x;
        
        if(st.upper_bound(x) != st.end())
        {
            int delNUm = *st.upper_bound(x);
            st.erase(delNUm);
        }
        st.insert(x);
    }
    cout<<st.size()<<endl;
    return 0;
}