#include<iostream>
#include<algorithm>
using namespace std;
char a[110][110];
int N;
int main()
{
    char c;
    cin>>c>>N;
    getchar();
    for(int i = 0;i < N;++i)
    {
        for(int j = 0;j < N;++j)
        {
            cin>>a[i][j];
        }
    }
    bool flag = true;
    for(int i = N - 1;i >= 0;--i)
    {
        for(int j = N - 1; j >= 0;--j)
        {
            char x = a[i][j] , y = a[N - 1 - i][N - 1 - j];
            if(x != y)
            {
                flag =  false;
                break;
            }
        }
        if(!flag)
            break;
    }
    if(flag)
    {
        cout<<"bu yong dao le\n";
        for(int i = 0;i < N;++i)
        {
            for(int j = 0;j < N;++j)
            {
                if(a[i][j] != ' ')
                {
                    cout<<c;
                }
                else{
                    cout<<" ";
                }
            }
            cout<<"\n";
        }
    }
    else{
        for(int i = N - 1;i >= 0;--i)
          {
        for(int j = N - 1; j >= 0;--j)
        {
            char x = a[i][j];
            if(x != ' ')
                cout<<c;
            else 
                cout<<a[i][j];
        }
        cout<<"\n";
    }
    }
    return 0;

}