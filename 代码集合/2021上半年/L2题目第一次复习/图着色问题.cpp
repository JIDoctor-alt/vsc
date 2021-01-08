#include<iostream>
#include<set>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

vector<bool> visited;
vector<int> color;
vector<vector<int> >ves;
 int V,E,K;
int flag ;
bool bfs(){
    for(int i =1;i <= V;i++ )
        for(auto w : ves[i]){
            if(color[w] == color[i])return false;
        }
   return true;
    
}
int main(){
   
    cin>>V>>E>>K;
    
    ves.resize(V+1);
    visited.resize(V+1);
    color.resize(V+1);

    for(int i = 0;i < E;i++){
        int a,b;
        cin>>a>>b;

        ves[a].push_back(b);
        ves[b].push_back(a);
    }
    int N;
    cin>>N;

    for(int i = 0;i < N;i++){
        flag = 0;

        set<int> stu;
      //  memset(visited,false,sizeof(visited));
       /// memset(color,0,sizeof(color));
       fill(visited.begin(),visited.end(),false);
       fill(color.begin(),color.end(),0);

        for(int j = 1;j <= V;j++){
            
            int id;
            cin>>id;
            stu.insert(id);

            color[j] = id;
        }
        int colorNum = stu.size();
        //颜色数量不符合范围退出

        if(colorNum != K)
            cout<<"No"<<endl;
        else
        {
            if(bfs())cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        
       

    }
    return 0;
}