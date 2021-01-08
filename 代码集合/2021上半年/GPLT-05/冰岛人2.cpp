#include<iostream>
#include<set>
#include<string>
#include<map>

using namespace std;

struct node{
    int sex;
    string father_name;
};
map<string,node> stu;
set<string> s1,s2;
//其他人m为男性，f为女性 
//维京人n为男sson 4，r为女sdottir7
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string w1,w2;
    
    while(n--){
        cin>>w1>>w2;
        if(w2.back() =='m'){
            stu[w1].sex = 1;
        }else if(w2.back() == 'f'){
            stu[w1].sex = 0;
        }else {
            //维京人
            if(w2.back() == 'n'){
                stu[w1] = {1,w2.substr(0,w2.length()-4)};
            }else if(w2.back() == 'r'){
                stu[w1] = {0,w2.substr(0,w2.length()-7)};
            }
        }
    }
    int m;
    cin>>m;
    while(m--){
        string a1,a2,b1,b2;
        cin>>a1>>a2>>b1>>b2;
        //若为同行
        if(stu.find(a1) == stu.end()||stu.find(b1)==stu.end()){
            cout<<"NA"<<endl;
        //}else if(stu[a1] == stu.end() || stu[b1] == stu.end()){
        }else if(stu[a1].sex == stu[b1].sex){
            //不在名单
            cout<<"Whatever"<<endl;
        }else{
            s1.clear();
            s2.clear();
            string name = a1;
            int flag = 0;
            //s1放五代以内
            for(int i = 0;i < 4 && !name.empty();i++){
                s1.insert(name);
                name = stu[name].father_name;
            }
            //name分配空间
            while(!name.empty()){
                s2.insert(name);
                name = stu[name].father_name;//五代以及五代以外
            }

            name = b1;
            //判断五代以内是否在s1中或者（）
            for(int i = 0;i < 4 && !name.empty();i++){
                //五代以内 不在第一个五代以内 ，也不再第一个的五代以外
                if(s1.find(name) != s1.end() || s2.find(name)!= s2.end()){
                    flag = 1;//No
                    break;
                }
                //
                name = stu[name].father_name;
            }
          /*  if(!flag && !name.empty()){
                while(!name.empty()){
                    if(s2.find(name)!= s2.end()){
                        flag = 1;
                        break;
                    }
                    name = stu[name].father_name;
                }
            }*/
            //第一个人的五代以内 不在第二个的五代以外
            while(!flag && !name.empty()){
                if(s1.find(name) != s1.end()){
                    flag = 1;
                    break;
                }
                name = stu[name].father_name;
            }
            if(flag){
                cout<<"No"<<endl;
            }else{
                cout<<"Yes"<<endl;
            }

        }

    }
    return 0;
}