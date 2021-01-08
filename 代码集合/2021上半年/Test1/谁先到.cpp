#include<iostream>

using namespace std;
struct edge{
    int jia_h,jia_s;
    int yi_h,yi_s;
}Tail[110];
int main(){
    int jia,yi;
    cin>>jia>>yi;
    int N;
    cin>>N;
    for(int i = 0;i < N;i++){
        cin>>Tail[i].jia_h>>Tail[i].jia_s>>Tail[i].yi_h>>Tail[i].yi_s;

    }
    int j_ans = 0,y_ans = 0;
    for(int i = 0;i < N;i++){
        int sum = Tail[i].jia_h + Tail[i].yi_h;
        if(Tail[i].jia_s == Tail[i].yi_s)
            continue;
        if(Tail[i].jia_s == sum){
            j_ans++;
            if(j_ans > jia){
                cout<<"A"<<endl;
                cout<<y_ans<<endl;
                break;
            }
        }

        if(Tail[i].yi_s == sum){
            y_ans++;
            if(y_ans > yi){
                cout<<"B"<<endl;
                cout<<j_ans<<endl;
                break;
            }
        }
    }
    return 0;
}