#include<iostream>

using namespace std;

int main()
{
	double* pvalue = NULL;//��ʼ��Ϊnull��ָ��
	pvalue = new double;//Ϊ���������ڴ�

	*pvalue = 294949.99;//�ڷ���ĵ�ַ�洢ֵ
	cout << "Value of pvalue : " << *pvalue << endl;

	delete pvalue;//�ͷ��ڴ�
	return 0;
}