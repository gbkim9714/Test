#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<pair<int, int>, int> mapMemorize;

int Memorize(int iLeft, int iRight)
{
	int iResult = 0;

	pair<int, int> KeyPair = { iLeft, iRight };
	const auto iter = mapMemorize.find(KeyPair);
	if (iter != mapMemorize.end())
	{
		return iter->second;
	}

	pair<int, int> KeyPair_Rev = { iRight, iLeft };
	const auto iter_Rev = mapMemorize.find(KeyPair_Rev);
	if (iter_Rev != mapMemorize.end())
	{
		return iResult;
	}
	else
	{
		iResult = iLeft + iRight;
		mapMemorize.emplace(pair(iLeft, iRight), iResult);
		return iResult;
	}
}

int solution(vector<vector<int>> triangle) {

	vector<vector<int>> vecMemorize;

	int answer = 0;

	vecMemorize = triangle;

	for (int i = 0; i < triangle.size() - 1; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			int iSelf = vecMemorize.at(i).at(j);
			int iLeft = triangle.at(i + 1).at(j);
			int iRight = triangle.at(i + 1).at(j + 1);

			int iMemLeft = vecMemorize.at(i + 1).at(j);
			int iMemRight = vecMemorize.at(i + 1).at(j + 1);

			int iSumWithLeft = Memorize(iSelf, iLeft);
			if (iMemLeft < iSumWithLeft)
				vecMemorize.at(i + 1).at(j) = iSumWithLeft;
			if (answer < iSumWithLeft)
				answer = iSumWithLeft;

			int iSumWithRight = Memorize(iSelf, iRight);
			if (iMemRight < iSumWithRight)
				vecMemorize.at(i + 1).at(j + 1) = iSumWithRight;
			if (answer < iSumWithRight)
				answer = iSumWithRight;
		}
	}

	return answer;
}

int main()
{
	vector<int> vec_0{ 7 };
	vector<int> vec_1{ 3, 8 };
	vector<int> vec_2{ 8, 1, 0 };
	vector<int> vec_3{ 2, 7, 4, 4 };
	vector<int> vec_4{ 4, 5, 2, 6, 5 };

	vector<vector<int>> vecTriangle;

	vecTriangle.push_back(vec_0);
	vecTriangle.push_back(vec_1);
	vecTriangle.push_back(vec_2);
	vecTriangle.push_back(vec_3);
	vecTriangle.push_back(vec_4);

	cout << solution(vecTriangle) << endl;
}


//
//int main()
//{
//    int iLayerSize{ 0 };    // ³ôÀÌ
//    cout << "Layer Size :";
//    cin >> iLayerSize;
//
//    for (int i = 0; i < iLayerSize; ++i)
//    {
//        cout << i << " : ";
//        
//        vector<int> vecInput;
//
//        for (int j = 0; j <= i; ++j)
//        {
//            int iInput = 0;
//            cin >> iInput;
//            vecInput.push_back(iInput);
//        }
//
//        vecTriangle.push_back(vecInput);
//    }
//
//    vecMemorize = vecTriangle;
//
//    int iMax = 0;
//
//    for (int i = 0; i < iLayerSize - 1; ++i)
//    {
//        for (int j = 0; j <= i; ++j)
//        {
//            int iSumWithLeft = Memorize(vecMemorize.at(i).at(j), vecTriangle.at(i + 1).at(j));
//            if (vecMemorize.at(i + 1).at(j) < iSumWithLeft)
//                vecMemorize.at(i + 1).at(j) = iSumWithLeft;
//            if (iMax < iSumWithLeft)
//                iMax = iSumWithLeft;
//
//            int iSumWithRight = Memorize(vecMemorize.at(i).at(j), vecTriangle.at(i + 1).at(j + 1));
//            if (vecMemorize.at(i + 1).at(j + 1) < iSumWithRight)
//                vecMemorize.at(i + 1).at(j + 1) = iSumWithRight;
//            if (iMax < iSumWithRight)
//                iMax = iSumWithRight;
//        }
//    }
//
//    cout << iMax << endl;
//
//}