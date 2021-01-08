#include<iostream>
using namespace std;
//22:56-00:08
int a[100000];
int b[100000];
 
int binarySerch(int k, int n)
{
	//应该在这里就把小于首或大于尾的情况掐掉的
	int mid;
	int L = 0;
	int R = n - 1;
	while (L <= R)
	{
		mid = L + (R - L) / 2;
		if (a[mid]>k)
			R = mid - 1;
		else if (a[mid]<k)
			L = mid + 1;
		else
			return a[mid];
	}
	//bug3 这里L可能已经越界了 案例： 2 5 8 查找10
	//bug4 R也可能是小于0的，既然L能等于n,那R也能小于0啊。PS：无论如何都通不过，最后就是这里忘写了！！！
	if (R<0) return a[L];
	if (L >= n) return a[R];
	//bu2 因为退出条件，此时是L>R的，并不是思维惯性L<R!!
	if (abs(a[R] - k) <= abs(a[L] - k))
		return a[R];
	else
		return a[L];
	return 0;
}
//总结：通过此题，明白了二分法的边界问题会出现在查找首尾元素的时候，且像我这样写，最后的跳出条件一定是R=L-1
int main()
{
	int n, m;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	//bug1 这里m写成n了
	for (int i = 0; i<m; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i<m; i++)
	{
		cout << binarySerch(b[i], n) << endl;
	}
 
	return 0;
 

}