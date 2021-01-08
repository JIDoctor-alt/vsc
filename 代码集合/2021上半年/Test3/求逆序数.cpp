#include <iostream>
#include <cstring>

using namespace std;

int N;
int a[100100], t[100100];
long long  count = 0;
void msort(int l, int r)
{
 if (l >= r)
    return;
int mid = (l + r) / 2;
    msort(l, mid);
    msort(mid + 1, r);
int i = l, j = mid + 1;
int k = 0;
while (i <= mid && j <= r)
{
if (a[i] <= a[j])
{
t[k++] = a[i++];
}
else
{
t[k++] = a[j++];
count += (mid - i + 1);
}
}
while (i <= mid)
t[k++] = a[i++];

while (j <= r)
t[k++] = a[j++];

for (int i = l, k = 0; i <= r; i++, k++)
{

/* code */
a[i] = t[k];
}
}
int main()
{
cin >> N;
int i;
for (i = 0; i < N; i++)
{
cin >> a[i];
}

msort(0, N - 1);


cout << count << endl;
return 0;
}