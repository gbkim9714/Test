#pragma once
#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
    해당 피보나치 수열의 결과값을 알아야 함
    해당 피보나치 수열이 어떤 수 2가지로 나눠지는지 알아야 함
    0번부터 타고 올라가며 재귀를 할 게 아니라 해당 값의 결과를 계속 얻어내어 연산하면 됨

    피보나치 수열은 앞자리 두 개의 값을 더한 값이다.
    1 1 2 3 5 8 13 21 ...

    피보나치 연산 결과값이 없으면 while문을 돌며 자식의 값에 대해 연산하고 map에 저장, 있으면 해당 값을 가져온다.
    해당 수열을 계산할 때 해당 값이 가지는 0의 갯수와 1의 갯수를 저장해 두었다가 그 갯수를 합치면?

    필요한 것 : 해당 인덱스의 피보나치 연산 시 0과 1이 나오는 횟수를 저장하는 컨테이너
*/

vector<unsigned int> vecInput;
map<unsigned int, vector<unsigned int>> mapOutput;

map<unsigned int, pair<unsigned int, unsigned int>> mapChild;       // 자식으로 가지는 수열
map<unsigned int, pair<unsigned int, unsigned int>> mapResult;      // 해당 수열 연산 시 발생하는 0과 1의 갯수, 이전 횟수를 저장함


int fibonacci(unsigned int n, int iIndex)
{
    if (n == 0)
    {
        mapOutput.at(iIndex).push_back(0);

        return 0;
    }
    else if (n == 1)
    {
        mapOutput.at(iIndex).push_back(1);

        return 1;
    }
    else
    {
        mapOutput.at()

        mapChild.insert({ n, {n - 1, n - 2} });



        //return iResult;
    }
}

int main()
{
    // 테스트 케이스 갯수 입력
    unsigned int iMsxTestCase{ 0 };
    cin >> iMsxTestCase;

    // 테스트 케이스 수 만큼 입력 받음
    for (unsigned int iTestCase{ 0 }; iTestCase < iMsxTestCase; ++iTestCase)
    {
        unsigned int iInput{ 0 };
        cin >> iInput;
        vecInput.push_back(iInput);

        vector<unsigned int> InitVector;
        mapOutput.emplace(iTestCase, InitVector);
    }

    // 입력값에 대해 iterator를 돌며 함수 실행하여 결과값을 저장
    unsigned int iCurIndex{ 0 };
    for (auto iter : vecInput)
    {
        for (unsigned int i = 0; i < iter; ++i)
        {
            fibonacci(i, iCurIndex);
        }

       unsigned int iResult = fibonacci(iter, iCurIndex);

       iCurIndex++;
    }

    if (vecInput.size() != mapOutput.size())
        cout << "error!\n";

    for (auto map : mapOutput)
    {
        unsigned int iResult_Zero{ 0 };
        unsigned int iResult_One{ 0 };

        for (auto iResult : map.second)
        {
            if (0 == iResult)
            {
                ++iResult_Zero;
            }
            else if (1 == iResult)
            {
                ++iResult_One;
            }
        }
        cout << iResult_Zero << " " << iResult_One << "\n";
    }

    return 0;
}