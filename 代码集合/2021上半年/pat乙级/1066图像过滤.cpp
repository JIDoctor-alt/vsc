#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int M,N,A,B,fl;
int main()
{
    vector<vector<int> > pio;
    cin>>M>>N>>A>>B>>fl;
    pio.resize(M);
    for(int i = 0;i < M;++i)
    {
        for(int j = 0;j < N;++j)
        {
            int id;
            cin>>id;
            pio[i].push_back(id);
        }
    }
    for(int k = 0;k < M;++k)
    {
        for(int i = 0;i < N;++i)
        {
            if(i != 0)
                cout<<" ";
            if(pio[k][i] >= A && pio[k][i] <= B)
                    pio[k][i] = fl;
           
               cout<<fixed<<setw(3)<<setfill('0')<<pio[k][i];
        }
        cout<<endl;
    }
    return 0;
}