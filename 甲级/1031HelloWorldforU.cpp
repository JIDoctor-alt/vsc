#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    getline(cin,str);

    int l = int(str.size());
    int n = (l + 2)/3;

  //  cout<<"n--------"<<n<<endl;

    int bm = l - 2*n;
    int i;
   // cout<<"bm--------"<<bm<<endl;
    for(i = 0;i < n - 1;++i)
    {
        cout<<str[i];
        for(int j = 0;j < bm;++j)
            cout<<" ";
        cout<<str[l - i - 1]<<endl;
    }
    
    for(;i <= n + bm;++i)
        cout<<str[i];
    //cout<<"-------i"<<i<<endl;


    return 0;
}