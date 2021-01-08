#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>


using namespace std;
using pii = pair<string,double>;
bool cmp(pii & a1,pii & a2){
    if(a1.second != a2.second)return a1.second > a2.second;
    else return a1.first < a2.first;
}
int main(){
    int N,M;
     cin>>N>>M;
    vector<set<string> > peo;
    map<string,int> sex;
    for(int i = 0;i < M;i++){
        int num;
        cin>>num;
        set<string> stu;
        for(int j = 0;j < num;j++){
            string id;
            cin>>id;
            
            if(id[0] == '-')sex[id] = 0;
            else sex[id] = 1;
            stu.insert(id);
        }
        peo.push_back(stu);//存放每个照片
    }

    vector<vector<pii> > resul;
    resul.resize(2);
    string p[2];
    cin>>p[0]>>p[1];
    for(int i = 0;i < 2;i++){
      string idn = p[i];
       
        map<string,double> re;
        for(int j = 0;j < M;j++){
            if(peo[j].count(idn)){
                int si = peo[j].size();
                double m = 1.0/si;
                for(auto w : peo[j]){
                    if(sex[w]+sex[idn]==1){
                        re[w] += m;
                        //resul[i].push_back({w,m});
                    }
                }
            }
        }
        for(auto q : re){
            resul[i].push_back({q.first,q.second});
        }

        sort(resul[i].begin(),resul[i].end(),cmp);
    }double maxre[2];
     maxre[0] = resul[0][0].second;
     maxre[1] = resul[1][0].second;
    // set<string> t1,t2;
    vector<set<string>> t;
    t.resize(2);
    for(int i = 0;i < 2;i++){
        for(auto o : resul[i]){
            if(o.second == maxre[i]){
                t[i].insert(o.first);
            }
        }
    }

    if(t[0].count(p[1]) && maxre[0] == maxre[1])cout<<p[0]<<" "<<p[1]<<endl;
    else{for(int u = 0;u < 2;u++)
        for(auto r : t[u]){
            cout<<p[u]<<" "<<r<<endl;
        }
    }

    return 0;
}