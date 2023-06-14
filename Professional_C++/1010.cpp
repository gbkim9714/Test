#pragma once
#include <iostream>
using namespace std;

/*
	서쪽 사이트 N개, 동쪽 사이트 M개
	서쪽 사이트에서 동쪽 사이트로 이어질 수 있는 다리를 놓는 경우의 수 판단
	다리는 겹칠 수 없음 -> 이전 다리가 연결된 M보다 작은 인덱스에는 접근 불가
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
		// 입력

		unsigned int iLeftSite_N{ 0 };
		unsigned int iRightSite_M{ 0 };

		cin >> iLeftSite_N >> iRightSite_M;
		iArr_N[i] = iLeftSite_N;
		iArr_M[i] = iRightSite_M;
	}

	for (unsigned int i = 0; i < iTestCount; ++i)
	{
		// 실제 연산

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