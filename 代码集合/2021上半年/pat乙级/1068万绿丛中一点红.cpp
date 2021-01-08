#include<iostream>
#include<math.h>
#include<map>
using namespace std;
const int id = 1<<30;
const int MAX_V = 1005;
int color[MAX_V][MAX_V];
map<int,int> ms;
int M,N,TOL;
bool judge(int x,int y)
{
    int cnt = 0;
    for(int i = -1;i < 2;++i)
    {
        for(int j = -1;j < 2;++j)
        {
            int nx = x + i, ny = y + j;
            if(nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
              int w = abs(color[nx][ny] - color[x][y]);
            if(nx == x && ny == y)
            {
                continue;
            }
            if(w <= TOL)
            {
                return false;
            }
            }
           

        }
    }
    return true;
}
int main()
{
    cin>>M>>N>>TOL;
    for(int i = 0;i < N;++i)
    {
        for(int j = 0;j < M;++j)
        {
            cin>>color[i][j];
            ++ms[color[i][j]];
        }
    }
    int ans = 0;
    int wx,wy;
    for(int i = 1;i < N-1;++i)
    {
        for(int j = 1;j < M - 1;++j)
        {
            if(ms[color[i][j]] == 1&&judge(i,j))
            {
                wx = i;
                wy = j;
                ++ans;
             //   cout<<color[i][j]<<endl;
            }
        }
    }
    if(ans == 0)
    {
        cout<<"Not Exist"<<endl;
    }
    else if(ans > 1)
    {
        cout<<"Not Unique"<<endl;
    }
    else 
    {
        cout<<"("<<(wy + 1)<<", "<<(wx + 1)<<"): "<<color[wx][wy]<<endl;
    }
    return 0;
}