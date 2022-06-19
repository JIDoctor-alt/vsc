#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int k;
	cin >> k;
	getchar();
	string str;
	getline(cin, str);
	bool flag = false;
	string ans = "", cur = "";
	int cnt = 0, lower = 0, upper = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (flag) {
			if (str[i] != '-')
			{
				if (islower(str[i])) {
					++lower;
				}
				if (isupper(str[i])) {
					++upper;
				}
				//                 ans.push_back(str[i]);
				cur.push_back(str[i]);
				if (cur.size() == k) {
					if (lower > upper) {
						for (int k = 0; k < cur.size(); ++k) {
							if (isupper(cur[k]))
								cur[k] = tolower(cur[k]);
						}
					}
					else if (lower < upper) {
						for (int k = 0; k < cur.size(); ++k) {
							if (islower(cur[k]))
							{
								cur[k] = toupper(cur[k]);
							}
						}
					}
					lower = upper = 0;
					ans = ans + '-';
					ans = ans + cur;
					cur = "";
				}
			}
		}
		else {
			if (str[i] != '-')
				ans.push_back(str[i]);
		}
		if (str[i] == '-')
			flag = true;
	}
	if (cur != "")
	{
				if (lower > upper) {
					for (int k = 0; k < cur.size(); ++k) {
						if (isupper(cur[k]))
							cur[k] = tolower(cur[k]);
					}
				}
				else if (lower < upper) {
					for (int k = 0; k < cur.size(); ++k) {
						if (islower(cur[k]))
						{
							cur[k] = toupper(cur[k]);
						}
					}
				}

		ans = ans + "-" + cur;
	}
	cout << ans << endl;

	return 0;
}