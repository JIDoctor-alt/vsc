#include<iostream>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
int a[10005];
int main()
{
    int N;
    cin>>N;
    set<int> st;
    for(int i = 1;i <= N;++i)
    {
        int num;
        cin>>num;
        ++a[abs(num - i)];
        st.insert(abs(num - i));
    }
    set<int>::reverse_iterator w;
    for(w = st.rbegin();w != st.rend();++w)
    {
        int x = *w;
        if(a[x] == 1)
        {
            continue;
        }
        cout<<x<<" "<<a[x]<<endl;
    }
    return 0;
}