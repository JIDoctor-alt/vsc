#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;
int a[10000];
int N;
int k,m;
int Partiton(int l, int r)
{
int v = a[r], i = l - 1;

for (int j = l; j < r; j++)
{
    if (a[j] < v)
    {
    ++i;
    swap(a[i], a[j]);
    }
}
swap(a[i + 1], a[r]);
    return i + 1;
}
int qksort(int l, int r)
{
    if (l == r && l == k - 1)
    return l;
    m = Partiton(l,r);
    if (m == k - 1)
    return m;

    if (m < k - 1)
    {
    return qksort(m + 1, r);

/* code */
    }
    else
return qksort(l, m - 1);
}
int main()
{
cin >> N;
//输入的k为第几大的数
for (int i = 0; i < N; i++)
{
cin >> a[i];
}
cin >> k;
//转换为求第几小的数
// k=N-k+1;
qksort(0, N - 1);

//输出第几小的数
for(int i = m; i < N; i++)
{
cout << a[i]<<endl;
}
return 0;
}