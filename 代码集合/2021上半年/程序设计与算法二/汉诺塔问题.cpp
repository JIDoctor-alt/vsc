#include<iostream>

using namespace std;
void Hanoi(int n,char a,char b,char c)
{
    if(n == 1)
    {
        cout<<n<<":"<<a<<"->"<<c<<endl;
        return ;
    }
    Hanoi(n-1,a,c,b);
    cout<<n<<":"<<a<<"->"<<c<<endl;
    Hanoi(n-1,b,a,c);
}
int main(){
    int N;
    char t1,t2,t3;
    cin>>N>>t1>>t2>>t3;
    Hanoi(N,t1,t2,t3);
    return 0;
}