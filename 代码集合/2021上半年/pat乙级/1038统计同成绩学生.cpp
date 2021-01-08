#include<iostream>
#include<cstring>
using namespace std;
int ms[101]={0};
int main()
{
    int N;
    scanf("%d",&N);
    for(int i = 0;i < N;++i)
    {
        int score;
        scanf("%d",&score);
        ++ms[score];
    }
    int k;
    scanf("%d",&k);
    for(int i = 0;i < k;++k)
    {
        int su;
        scanf("%d",&su);
        printf("%d",ms[su]);
        if(i != k-1)
        {
            printf(" ");
        }
        else 
        {
            printf("\n");
        }
    }
    return 0;
}