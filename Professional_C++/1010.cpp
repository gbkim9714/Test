#pragma once
#include <iostream>
using namespace std;

/*
	���� ����Ʈ N��, ���� ����Ʈ M��
	���� ����Ʈ���� ���� ����Ʈ�� �̾��� �� �ִ� �ٸ��� ���� ����� �� �Ǵ�
	�ٸ��� ��ĥ �� ���� -> ���� �ٸ��� ����� M���� ���� �ε������� ���� �Ұ�
*/

int main()
{
	unsigned int iTestCount{ 0 };
	cin >> iTestCount;

	unsigned int* iArr_N = new unsigned int[iTestCount];
	memset(iArr_N, 0, sizeof(iArr_N));
	unsigned int* iArr_M = new unsigned int[iTestCount];
	memset(iArr_M, 0, sizeof(iArr_M));

	for (unsigned int i = 0; i < iTestCount; ++i)
	{
		// �Է�

		unsigned int iLeftSite_N{ 0 };
		unsigned int iRightSite_M{ 0 };

		cin >> iLeftSite_N >> iRightSite_M;
		iArr_N[i] = iLeftSite_N;
		iArr_M[i] = iRightSite_M;
	}

	for (unsigned int i = 0; i < iTestCount; ++i)
	{
		// ���� ����

		/*for (unsigned int N = 0; N < iArr_N[i]; ++N)
		{
			bool bConnectable = true;

			for (unsigned int M = 0; M < iArr_M[i]; ++M)
			{
				if (M < N) bConnectable = false;
				break;
			}

			if (!bConnectable) break;
		}*/

		for (unsigned int N = 0; N < iArr_N[i]; ++N)
		{
			bool bConnectable = true;

			for (unsigned int M = 0; M < iArr_M[i]; ++M)
			{
				if (M < N) bConnectable = false;
				break;
			}

			if (!bConnectable) break;
		}
	}

	delete[] iArr_N;
	delete[] iArr_M;

	return 0;
}