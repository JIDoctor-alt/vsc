#include <iostream>
using namespace std;
const int MAXN = 100010;
int a[MAXN];
 
void swap(int &a,int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
 
void arrangeRight(int a[],int s,int e,int m){
	int key = a[s];
	int i = s,j = e;
	while(i != j){
		while(i < j && a[j] >= key)
			j--;
		swap(a[i],a[j]);
		while(i < j && a[i] <= key)
			i++;
		swap(a[i],a[j]);
	}
	//此时a[i]即为key，key左边的数都比他小，右边的数都比他大
	int now = e - i + 1;
    //如果右边刚好是m个就直接返回
	if(now == m)
		return;
        //大于m个就在右区间找m个
	if(now > m) 
		arrangeRight(a,i+1,e,m);
	else//小于m就在左边再找m-now个数
		arrangeRight(a,s,i-1,m - now);
}
 
void QuickSort(int a[],int s,int e){
	if(s >= e)
		return;
	int k = a[s];
	int i = s,j = e;
	while(i != j){
		while(i < j && a[j] >= k)
			j--;
		swap(a[i],a[j]);
		while(i < j && a[i] <= k)
			i++;
		swap(a[i],a[j]);
	}
	
	QuickSort(a,s,i-1);
    //i不变
	QuickSort(a,i+1,e); 
}
 
int main(){
	int n,m;
	cin >> n;
	for(int i = 0;i<n;i++) cin >> a[i];
	cin >> m;
	arrangeRight(a,0,n-1,m);
    //将m大的数放在右边，对右边这m大的数进行快速排序
	QuickSort(a,n-m,n-1);
	for(int i = n-1;i>=(n-m);i--)
		cout << a[i] <<endl;
	return 0;
}

