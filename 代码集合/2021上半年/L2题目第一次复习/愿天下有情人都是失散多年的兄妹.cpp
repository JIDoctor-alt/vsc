#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<cstring>

using namespace std;
bool exist[100000];
struct node{
    int mi_id;
    int fa_id;
    int sex;
}Peo[100000];
int level[100000];
int main(){
    int N;
    cin>>N;
    
    for(int i = 0;i < N;i++){
        int people,father_id,mother_id;
        char se;
        cin>>people>>se>>father_id>>mother_id;

        Peo[people].fa_id = father_id;
        Peo[people].mi_id = mother_id;
        if(se == 'M'){
            Peo[people].sex = 2;
        }else{
            Peo[people].sex = 1;
        }
        //父亲 母亲
        Peo[father_id].sex = 2;
        Peo[mother_id].sex = 1;
        //exist[people] = true;
    }
    int M;
    cin>>M;
    for(int i = 0;i < M;i++){
        int a,b;
        cin>>a>>b;
        if(Peo[a].sex == Peo[b].sex){
            cout<<"Never Mind"<<endl;
        }else{
            memset(level,0,sizeof(level));
            queue<int> pq;
            set<int> rong;
            pq.push(a);
            pq.push(b);
            level[a] = 1;
            level[b] = 1;
            int flag = 0;
            while (!pq.empty())
            {
                int v = pq.front();
                pq.pop();
                int si = rong.size();

                rong.insert(v);

                if(si == rong.size()){
                    cout<<"No"<<endl;
                    flag = 1;
                    break;
                } 
               // if(exist[v] == false)continue;
                if(level[v] <= 4){
                    int fa = Peo[v].fa_id;
                     int ma = Peo[v].mi_id;
                if( fa != -1){
                    pq.push(fa);
                    level[fa] = level[v] + 1;
                }                                    
                   
                 if(ma != -1){
                      pq.push(ma);
                    level[ma] = level[v] + 1;
                  }
                  
                }
               

            }
            if(flag == 0)cout<<"Yes"<<endl;
            


        }
    }
    return 0;
}