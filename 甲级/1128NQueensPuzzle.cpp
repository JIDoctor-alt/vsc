#include<iostream>
#include<cmath>
using namespace std;
int  k,n;
int row[1005];
int main()
{
    cin>>k;
    for(int i = 0;i < k;++i)
    {
        cin>>n;
        bool result  = true;
        for(int j = 0;j < n;++j)
        {
            cin>>row[j];
            for(int t = 0;t < j;++t)
            {
                if(row[t] == row[j] || abs(row[t] - row[j]) == (j - t))
                {
                    result = false;
                    break;
                }
            }
        }
        cout<<(result ? "YES\n" : "NO\n");
    }
    return 0;
}