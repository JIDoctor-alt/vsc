#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
#include<iomanip>
using namespace std;
int main()
{
    int a[11][11];
    bool flag = true;
    int n;
    cin>>n;
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            cin>>a[i][j];
        }
    }
    for(int i = 1;i < n;++i){
        for(int j = 0;j < i;++j){
            if(a[i][j] != 0)
            {
                flag = false;
                break;
            }
        }
    }
    cout<<(flag ? "YES\n" : "NO\n");
    return 0;
}