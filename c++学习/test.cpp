#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	int num[31];
	int res[2000];

	while (cin >> str)
	{
		for (int i = 0; i < str.size(); i++)
			num[i] = str[i] - '0';
		int index = 0;
		for (int i = 0; i < str.size(); )
		{
			int temp = 0, remain = 0;
			for (int j = i; j < str.size(); j++)
			{
				temp = (remain * 10 + num[j]) % 2;
				num[j] = (remain * 10 + num[j]) / 2;
				remain = temp;
			}
			res[index++] = remain;
			while (num[i] == 0)
				i++;
		}
		for (int i = index - 1; i >= 0; i--)
			cout << res[i];
		cout << endl;
	}
	return 0;
}