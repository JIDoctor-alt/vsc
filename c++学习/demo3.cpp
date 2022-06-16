#include<iostream>
using namespace std;

#define DEBUG

#define MIN(a,b) (((a) < (b)) ? a : b)

int main()
{
	int i, j;
	i = 100;
	j = 30;

#ifdef DEBUG
	cerr << "Trace: Inside main function" << endl;
#endif // DEBUG

#if 0
	//这是注释部分
	cout << MKSTR(HELLO C++) << endl;
#endif // 0

	cout << "The minimum is" << MIN(i, j) << endl;

#ifdef DEBUG
	cerr << "Trace: Coming out of main function" << endl;
#endif // DEBUG
	return 0;

}