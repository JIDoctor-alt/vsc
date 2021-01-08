#include<stdio.h>

long long int l = 0;
int main(){
    int n;
    scanf("%d",&n);
    l = 0.5*(1+n)*n;
    printf("%lld",l);
    return 0;
}