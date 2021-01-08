#include<iostream>
#include<vector>
#include<string>
using namespace std;
int N,M;
int deep[1010];

int size = 0;
void Creatdeep(int x)
{
    size++;
    deep[size] = x;
    int i = size;
    while(deep[i/2] > x)
    {
        deep[i] = deep[i/2];
        i /= 2;
    }
    deep[i] = x;
}
int main()
{
    deep[0] = -10100;
    cin>>N>>M;
    for(int i = 0;i < N;++i)
    {
        int num;
        cin>>num;
        Creatdeep(num);
    }
    for(int i = 0;i < M;++i)
    {
        int n1;
        cin>>n1;
        int j;
        for( j = 1;j <= N;++j)
            if(deep[j] == n1)break;

        string str;
        cin>>str;
        if(str[0] == 'a')
        {
            
            int n2;
            cin>>n2;
            string a1,b1;
            cin>>a1>>b1;
            int k;
            for(k = 1;k <= N;++k)
                if(deep[k] == n2)break;
            if(j/2 == k/2)
                cout<<"T"<<endl;
            else 
                cout<<"F"<<endl;
            
        }
        else
        {
            string str3;
            cin>>str3;
            if(str3[0] =='a')
            {
                string a,b;
                cin>>a>>b;
                int n2;
                cin>>n2;
                int k;
                for(k = 1;k <= N;++k)
                    if(deep[k] == n2)break;
                if(k == j/2)
                    cout<<"T"<<endl;
                else 
                    cout<<"F"<<endl;
            }
            else
            {
                string str4;
                cin>>str4;
                if(str4[0] == 'r')
                {
                    if(j == 1)
                        cout<<"T"<<endl;
                    else 
                        cout<<"F"<<endl;
                }
                else 
                {
                    string a;
                    int b;
                    cin>>a>>b;
                    int k;
                    for(k = 1;k <= N;++k)
                        if(deep[k] == b)break;
                    if(j == k/2)
                        cout<<"T"<<endl;
                    else 
                        cout<<"F"<<endl;
                }
            }
            
        }
        

    }
    return 0;
}