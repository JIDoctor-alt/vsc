#include<iostream>
#include<cstring>
#include<vector>
/*
利用assign()函数（清空并深复制）
vector<int> array{3, 5, 2, 6, 4};
vector<int> outArray{ 1,2,3 };
outArray.assign(array.begin(),array.end());//清空原数据，赋予新数据={3,5,2,6,4}
outArray.assign(5, 0);//5个0，清空原数据={0,0,0,0,0,}

*/
using namespace std;
vector<int> Indgree,testV;
int N,M,K,Np;
vector<vector<int> > ves;
bool Valid(vector<int> test){
    for(int i = 1;i <= N;++i)
        if(test[i])return false;
    return true;
}
int main()
{
    cin>>N>>M;
    ves.resize(N+1);
    Indgree.resize(N+1);
    testV.resize(N+1);
    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        ves[x].push_back(y);
        ves[y].push_back(x);

        Indgree[x]++;
        Indgree[y]++;
    }
    cin>>K;
    
    while (K--)
    {
      //  memcpy(testV[0],Indgree[0],sizeof(Indgree));错误
        testV.assign(Indgree.begin(),Indgree.end());
        cin>>Np;
        while(Np--)
        {
            int num;
            cin>>num;
            testV[num] = 0;
            for(auto w : ves[num])
            {
                if(testV[w] != 0)
                    testV[w]--;
            }
        }
       
        cout<<(Valid(testV) ? "YES" : "NO")<<endl;

    }
    
    return 0;
}
