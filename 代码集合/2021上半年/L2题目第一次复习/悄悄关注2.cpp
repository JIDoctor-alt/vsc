#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main(){
    int N,M;
    string name;
    set<string> stu;
    cin>>N;
    for(int i = 0;i < N;i++)
    {
        cin>>name;
        stu.insert(name);
    }
    cin>>M;
    map<string,double> mu;
    double avesum = 0;
    for(int i = 0;i < M;i++)
    {
        double num;

        cin>>name>>num;
        mu[name] = num;
        avesum += num;
    }
    avesum /= M;
    int flag = 0;
    map<string,double>::iterator o;
    for(o = mu.begin();o!= mu.end();o++){
        if(o->second > avesum && !stu.count(o->first)){
            flag = 1;
            cout<<o->first<<endl;
        }
    }

    if(!flag)
        cout<<"Bing Mei You"<<endl;
    return 0;
}