#include<iostream>
#include<string>
#include<vector>
using namespace std;
char Z[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
vector<string> result;
int d[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int N;
int main()
{
    cin>>N;
    string str;
    getchar();
    while(N--)
    {
        getline(cin,str);
        int len = str.length();
        int sum = 0;
        bool isflag = true;
        for(int i = 0;i < len - 1; ++i)
        {
            if(!isdigit(str[i]))
            {
                isflag = false;
                break;
            }
            sum += (str[i] - '0')*d[i];
        }
        if(!isflag)
            result.push_back(str);
        else 
        {
            if(str[len -1] != Z[sum % 11])
                result.push_back(str);
        }
    }
    if(result.size() == 0)
        cout<<"All passed"<<endl;
    else 
    {
        for(auto i : result)
            cout<<i<<endl;
    }
  
    return 0;
}