#include<iostream>
#include<set>
using namespace std;
int main()
{
    int N;
    cin>>N;
    set<int> st;
    int num;
    for(int i = 0;i < N;++i)
    {
        cin>>num;
        int sum = 0;
        while(num)
        {
            sum += (num%10);
            num /= 10;
        }
        st.insert(sum);
    }
    cout<<st.size()<<endl;
    int x = 0;
    for(auto i :st)
    {
        ++x;
        if(x != 1)
        {
            cout<<" ";
        }
        cout<<i;
    }
    return 0;

}