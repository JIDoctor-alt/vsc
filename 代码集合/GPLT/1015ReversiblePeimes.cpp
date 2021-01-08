#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
bool judge(int x){
    if(x == 1)
        return false;
    for(int i = 2;i <= sqrt(x);++i){
        if(x % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n,d;
    while(cin>>n&&n > 0){
        cin>>d;

        string c;
        while(n > 0){

            c = c + to_string(n%d);
            n /= d;
        }
        int sum  = 0;
        int cnt = 0;

        for(int i = c.size()-1;i >= 0;--i){
                sum += pow(d,cnt)*(c[i] - '0');
                cnt++;
        }
        
        if(judge(n)&&judge(sum))
        {
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    return 0;
}
