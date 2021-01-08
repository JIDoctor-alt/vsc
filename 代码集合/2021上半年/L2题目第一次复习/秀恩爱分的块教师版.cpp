#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<cmath>
using namespace std;
vector<set<int> >lst;
vector<int> gender;
int N,M;
//设置性别返回绝对值x
int setGender(const string &x){
    int ret;
    if(x[0] == '-'){
        ret = stoi(x.substr(1));
        gender[ret] = 0;//女性
    }else{
        ret = stoi(x);
        gender[ret] = 1;//男性
    }
    return ret;
}
auto mostInti(int x){
    set<int> ret;
    vector<double> f(N,0.0);
    //遍历照片
    for(auto &i : lst){
        //如果在照片中，找出异性的亲密度
        if(i.count(x)){
            int K = i.size();
            for(auto &y : i){
                //遍历每个编号
                if(gender[x] != gender[y]){
                    f[y] += 1.0/K;//这个人的亲密度加上之前的
                }
            }
        }
    }
    double maxI  = *max_element(f.begin(),f.end());
    for(int i = 0;i < N;i++)
        if(abs(maxI - f[i]) < 1e-7)
            ret.insert(i);
    return ret;//返回这个人的去亲密度最大的
}
string prt(int x){
    string ret = "";
    //如果这个人为女性编号前面加-
    if(gender[x] == 0)
        ret += "-";
    ret += to_string(x);
    return ret;
}
int main(){
    cin>>N>>M;
    //存取照片的数组 用set存取照片中的人
    lst.resize(N);
    gender.resize(N);//性别
    for(int i = 0;i  < M;i++){
        int K;
        cin>>K;
        while(K--){
            string x;
            cin>>x;
            lst[i].insert(setGender(x));
        }
    }
    string A,B;
    cin>>A>>B;
    int va = setGender(A),vb = setGender(B);
    ///得到每个人对应的异性的亲密度
    auto sa = mostInti(va);
    auto sb = mostInti(vb);

    //如果最大亲密度正好彼此都存在只输出一对
    if(sa.count(vb) && sb.count(va)){
        cout<<prt(va)<<" "<<prt(vb)<<endl;
    }else{
        for(auto &i : sa){
            cout<<prt(va)<<" "<<prt(i)<<endl;
        }
        for(auto &i : sb)
            cout<<prt(vb)<<" "<<prt(i)<<endl;
    }
}