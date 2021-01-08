#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int N;
    cin>>N;
    vector<int> talk(N + 1,0);
    for(int i = 1;i <= N;++i)
        cin>>talk[i];
    for(int i = 1;i <= N;++i)
    {
        for(int j = i + 1;j <= N;++j)
        {
            //1不是两人，-1是两人
            vector<int> a(N+1,1);
            a[i] = a[j] = -1;
            vector<int> lying;
            for(int k = 1;k <= N;++k)
            {
                //判断说话的人是否说谎
                int id = abs(talk[k]);
                //如果说谎则异号
                if(a[id]*talk[k] < 0)
                    lying.push_back(k);
            }
            //有两个人说谎，并且一个是狼人，一个不是狼人
            if(lying.size() == 2 && a[lying[0]] + a[lying[1]] == 0)
            {
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }
    cout<<"No Solution\n";
    return 0;
}