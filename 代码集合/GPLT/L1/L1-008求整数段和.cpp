#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int A,B;
    cin>>A>>B;
    int sum = 0,cnt = 1;
    for(int i = A ;i <= B;++i)
    {
        printf("%5d",i);
        if(cnt++ % 5 == 0)
            printf("\n");
        sum += i;
    }
    --cnt;
    if(cnt % 5)
        cout<<endl;
    cout<<"Sum = "<<sum<<endl;
    return 0;
}