#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
vector<string> st(54);
int start[55],ed[55],scan[55];
int main()
{
    char M[5] = {'S','H','C','D','J'};
    for(int i = 0;i < 54;++i)
    {
        int index = (i % 13) + 1;
        int ic = (i / 13);
        char c = M[ic];
        st[i].push_back(c);

        st[i] = st[i] + to_string(index);
    }
   /* for(int i = 0;i < 54;++i)
        cout<<" "<<st[i];
    cout<<endl;*/
    int n;
    cin>>n;
    vector<int> order;
    for(int i = 0;i < 54;++i)
    {
        int x;
        cin>>x;
        //i移动到 x
        scan[i] = x-1;
        //结束的位置
        ed[i] = i;
    }
    for(int j = 0;j < n;++j)
    {
        for(int i = 0;i < 54;++i)
        {
            start[i] = ed[i];//开始的位置
        }
        for(int i = 0;i < 54;++i)
        {
           ed[scan[i]] = start[i];//结束的位置
        }
    }
    for(int i = 0;i < 54;++i)
    {
        cout<<(i != 0 ? " " : "")<<st[ed[i]];
    }
    cout<<endl;
    return 0;
}
//S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 D2 D3 D4 H6 H3 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5
/*
1
36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
*/