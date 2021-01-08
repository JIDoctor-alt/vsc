#include<iostream>
using namespace std;
int a[1005];
int main()
{
    int N;
    int maxid,maxSocre = -1;
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        string st;
        int score;
        cin>>st>>score;
        int id = stoi(st.substr(0,st.find('-')));
        a[id] += score;
        if(maxSocre < a[id])
        {
            maxSocre = a[id];
            maxid = id;
        }
    }
    cout<<maxid<<" "<<maxSocre<<endl;

    return 0;
}