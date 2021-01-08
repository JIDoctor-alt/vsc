#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int sum = 0,cur = 0;
    int up = 6,down = 4,ti = 5;
    int n;
    cin>>n;
    for(int i = 0;i < n;++i){
        int x;
        cin>>x;
        if(cur - x < 0){
            sum += up*(abs(x - cur));
            sum += ti;
        }else{
            sum += down*(abs(x - cur));
            sum += ti;
        }
        cur = x;
    }
    cout<<sum<<endl;
    return 0;
}