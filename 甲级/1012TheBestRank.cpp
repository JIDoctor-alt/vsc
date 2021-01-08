#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int flag = 0;
struct node
{
    int id;
    double score[4];
    int rank[4];
    int best;;
    bool operator<(const node &e)const
    {
        return score[flag] > e.score[flag];
    }
};
int N,M;
vector<node> vs;
int exitid[1000005];
int main()
{
    cin>>N>>M;
    vs.resize(N);
    for(int i = 0;i < N;++i)
    {
        int id;
        cin>>id;
//注意这里
        vs[i].id = id;

  //      exitid[id] = i + 1;

        
        double x = 0;
        for(int j = 1;j <= 3;++j)
        {
            cin>>vs[i].score[j];
            x += vs[i].score[j];
        }

        vs[i].score[0] = x/3;
    }

    for(flag = 0;flag < 4;++flag)
    {
        //成绩排名
        sort(vs.begin(),vs.end());

        vs[0].rank[flag] = 1;

        //这个排名不涉及id编号
        for(int i = 1;i < N;++i)
        {
            vs[i].rank[flag] = i + 1;

            if(vs[i].score[flag] == vs[i - 1].score[flag])
                vs[i].rank[flag] = vs[i-1].rank[flag];
        }
    }

    for(int i = 0;i < N;++i)
    {

        //排序结束 下标固定不变了

//因此，可以设置 每个人id对应的数组下标  若不存在这对应的数组下标为0
         exitid[vs[i].id] = i + 1;
        
        int minRank = 1<<30;
        int fr = 0;


        for(int j = 0;j < 4;++j)
        {
            //遍历每科成绩的排名‘

            int xr = vs[i].rank[j];
            if(minRank > xr)
            {
                minRank = xr;
                //fr最佳排名的下标

                fr = j;
            }
        }


        vs[i].best = fr;
    }
    char level[4] = {'A','C','M','E'};

    for(int i = 0;i < M;++i)
    {
        int id;
        cin>>id;
         
        int fid = exitid[id];
 //       cout<<"id :::::::::::::::<<"<<fid<<" \n";
        if(fid)
        {
        
            int bestid = vs[fid-1].best;
            printf("%d %c\n",vs[fid-1].rank[bestid],level[bestid]);
        }
        else 
        {
            cout<<"N/A\n";
        }
    }

}