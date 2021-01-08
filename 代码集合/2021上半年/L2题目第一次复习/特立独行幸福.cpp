#include<iostream>
#include<set>
#include<vector>
#include<cmath>
/*

*/
using namespace std;
using pii = pair<int,int>;
int Valid(int nu){
    for(int i = 2;i <= sqrt(nu);i++){
        if(nu%i == 0)return 1;
    }
    return 2;
}
int main(){
    int A,B;
    cin>>A>>B;
    set<int> st;
    vector<pii> result;
    for(int i  = A;i <= B;i++){

        int n = i,ans= 0;
        //如果是前面或者 （68依附于19） 后面数字的幸福数跳过
        if(st.count(i))continue;
        set<int> cnt;
        while(n!=1){
            
            int sum = 0;
            while(n){
                sum += (n%10)*(n%10);
                n /= 10;
            }
            //依附于其他数的数字(或者已经存在其他数的幸福书)
        //    if(st.count(sum))break;//错误 只用一个st存放集合也可能会死循环
            //break防止陷入死循环（又不在开始几个数所产生的幸福数集合中）
            if(cnt.count(sum))break;
            cnt.insert(sum);
            //依附于其他数的幸福数集合
            st.insert(sum);
            ans++;

            n = sum;
        }
        if(n == 1)result.push_back({i,ans*Valid(i)});
    }

    int number = result.size();
    if(number){
        for(int i = 0;i < number;i++){
            if(st.count(result[i].first)==0)
            cout<<result[i].first<<" "<<result[i].second<<endl;
        }
    }else{
        cout<<"SAD"<<endl;
    }
    return 0;
}