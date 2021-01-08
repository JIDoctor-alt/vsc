#include<iostream>
#include<algorithm>
using namespace std;
char M[1005][1005];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int N,area,max_area = 0;
void f(int x,int y){

    for(int i = 0;i < 4;++i){

        int nx = x + dx[i], ny = y+ dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < N && M[nx][ny] == '.'){

            M[x][y] = 'c';
            return;
        }

    }
}

int dfs(int x,int y){

    int cnt = 0;
    if(M[x][y] == '#')
        ++cnt;
    ++area;
    M[x][y] = '.';

    for(int i = 0;i < 4;++i){

        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < N && M[nx][ny] != '.'){
            cnt += dfs(nx,ny);
        }
    }
    return cnt;
}
int main()
{
    cin>>N;
    for(int i = 0;i < N;++i){
        for(int j = 0;j < N;++j){
            cin>>M[i][j];
        }
    }
    for(int i = 0;i < N;++i){
        for(int j = 0;j < N;++j){
            if(M[i][j] == '#')
                f(i,j);
        }
    }

    int ans = 0;
    for(int i = 0;i < N;++i){

        for(int j = 0;j < N;++j){

            area  = 0;
            if(M[i][j] == 'c'){
                    int cnt = dfs(i,j);
                    if(cnt == 0)
                    {
                        ++ans;
                        max_area = max(max_area,area);
                    }
                     //++ans;
            }
        }
    }

    cout<<ans<<endl;
    if(ans)
    cout<<max_area<<endl;
    else 
    cout<<"-1\n";
    return 0;
}