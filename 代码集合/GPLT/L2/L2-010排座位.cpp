#include<iostream>
#include<numeric>
#include<cstring>
#include<algorithm>
using namespace std;
int pre[110],connect[110][110];
int N,M,K;
int find(int x){
    return pre[x] == x ? x : find(pre[x]);
}
void un(int x,int y){
    int nx = find(x), ny = find(y);
    if(nx  < ny){
        pre[ny] = nx;
    }else{
        pre[nx] = ny;
    }
}
int main()
{
    iota(pre,pre + 110,0);
    cin>>N>>M>>K;

    for(int i = 0;i < M;++i){
        int x,y,c;
        cin>>x>>y>>c;
        if(c != -1)
            un(x,y);
        connect[x][y] = connect[y][x] = c;
    }
    for(int i = 0;i < K;++i){
        int x,y;
        cin>>x>>y;
        if(find(x) == find(y) && connect[x][y] != -1){
            cout<<"No problem\n";
        }
        else if(find(x) != find(y) && connect[x][y] != -1)
        {
            cout<<"OK"<<endl;
        }
        else if(find(x) == find(y) && connect[x][y] == -1){
            cout<<"OK but..."<<endl;
        }
        else if(find(x) != find(y) && connect[x][y] == -1){
            cout<<"No way"<<endl;
        }
    }
    return 0;
}