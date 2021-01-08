#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
using pii = pair<string,double>;
map<string,int> sex;
map<string,bool> visited;

bool cmp(pii & a,pii & b ){
    //优先按照亲密度排序，亲密度相同的，按照编号排序
    return a.second == b.second ? a.first < b.first : a.second > b.second;
}
int Valid(string s){
    if(s == "0"||s == "-0")
        return 0;
    int le = s.length();
    int sum = 0;
    for(int i = 0;i < le;i++)
        sum += sum*10 + (s[i]-'0');
    return sum;
}
int main(){
    int N,M,K;
    cin>>N>>M;
    vector<vector<string> > ves;
    ves.resize(M);//M个照片
    
    for(int i = 0;i < M;i++){
        
        cin>>K;//K个人在照片中

        for(int j = 0;j < K;j++){
            string numid;
            cin>>numid;
            if(numid[0] == '-')//有负号表示女性
                sex[numid] = 1;
            else //没有负号表示男性
                sex[numid] = 2;//男性
           // int num = Valid(numid);
            ves[i].push_back(numid);//照片中人的编号
        }
    }
    string nameA,nameB;
   cin>>nameA>>nameB;

    map<string,double> stu1,stu2;
    double maxSum1 = 0,maxSum2 = 0;//亲密度最大值
    //
        for(int i = 0;i < M;i++){
         //   int len = ves[i].size();
            double t = 1.0/ves[i].size();
            //如果name在这个照片中，计算这个照片中的与所有异性的亲密度
            if(find(ves[i].begin(),ves[i].end(),nameA)!= ves[i].end())
             for(auto w : ves[i]){
            //这张照片
                if((sex[nameA]*sex[w] == 2)){//是异性
                    //异性
                    stu1[w] += t;
                    if(stu1[w] > maxSum1){
                        maxSum1 = stu1[w];
                    }
                }
            }

            //如果name在这个照片中，计算这个照片中的与所有异性的亲密度
            if(find(ves[i].begin(),ves[i].end(),nameB)!= ves[i].end())
             for(auto w : ves[i]){
            //这张照片
                if((sex[nameB]*sex[w] == 2)){//是异性
                    //异性
                    stu2[w] += t;
                    if(stu2[w] > maxSum2){
                        maxSum2 = stu2[w];
                    }
                }
            }
          }
          vector<pii> va,vb;
          if(stu1.empty() && stu2.empty()){
              cout<<nameA<<" "<<nameB<<endl;
              return 0;
          }else{
              for(auto it : stu1){
                  if(it.second == maxSum1)
                  va.push_back(it);
              } 
              for(auto it : stu2) {
                  if(it.second == maxSum2)
                  vb.push_back(it);
              }
              sort(va.begin(),va.end(),cmp);
              sort(vb.begin(),vb.end(),cmp);
             map<string,double>:: iterator ii;

             if(stu1[nameB] == maxSum1 && stu2[nameA] == maxSum2){
                 cout<<nameA<<" "<<nameB<<endl;
             }else{
                 for(auto it : va)cout<<nameA<<" "<<it.first<<endl;
                 for(auto it : vb)cout<<nameB<<" "<<it.first<<endl;
             }
              
          }
         // map<string,double>::iterator ii;
          //map<string,double>::iterator jj;

    return 0;
}