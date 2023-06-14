/*
* 키워드 : 퀵 정렬, string
*/

#include <string>
#include <vector>
#include <algorithm>

/*  문제 설명
    문자열 s에는 공백으로 구분된 숫자들이 저장되어 있습니다. 
    str에 나타나는 숫자 중 최소값과 최대값을 찾아 이를 "(최소값) (최대값)"형태의 문자열을 반환하는 함수, solution을 완성하세요.
    예를들어 s가 "1 2 3 4"라면 "1 4"를 리턴하고, "-1 -2 -3 -4"라면 "-4 -1"을 리턴하면 됩니다.

제한 조건
s에는 둘 이상의 정수가 공백으로 구분되어 있습니다.
*/

/*  노트

    1 2 3 4 넣으면 1 4 출력
    띄어쓰기가 나오기 전까지 숫자 모으기
*/

using namespace std;
/*
       Partition
       1. 피벗을 정하고
       2. 맨 앞, 맨 뒤 반복자를 잡고
       3. 맨 앞 반복자로부터, 현재 자신이 피벗보다 크거나 같아질때까지 반복자 탐색
       4. 맨 뒤 반복자로부터, 현재 자신이 피벗보다 작아질때까지 반복자 탐색
       5. 3과 4의 결과가 다르면 해당 원소들의 위치를 바꿔주고, 같으면 같은거 그대로 반환

       Quicksort
       1. 정렬할 벡터에 원소가 하나라도 있을 경우 partition의 결과로 나온 벡터를 기준으로 나눔
       2. 좌 벡터는 입력받은 첫 반복자로부터 partition 반복자 -1
       3. 우 벡터는 partition 반복자로부터 마지막 반복자
       4. 원소가 하나가 될 때까지 반복
*/

template<typename T>
auto Partition(typename vector<T>::iterator Begin, typename vector<T>::iterator Last)
{
    auto Pivot_Ptr = *Begin;            // 기준 값, 가장 앞쪽의 값을 잡음
    auto Left_Iter = Begin + 1;         // 벡터 맨 왼쪽의 값
    auto Right_Iter = Last;             // 벡터 맨 오른쪽의 값

    while (true)    // 값을 완벽히 정렬할 때 까지 반복
    {
        // distance(Left_Iter, Right_Iter) > 0 조건문은 반복자 안에 값이 있는지 없는지에 대한 예외처리임

        while (*Left_Iter <= Pivot_Ptr && distance(Left_Iter, Right_Iter) > 0)  // 좌측 반복자로부터 현재 값이 기준 값보다 작거나 같으면 반복자 +순회, 즉 기준 값보다 큰 값이 나올 때까지 반복하여 탐색
            ++Left_Iter;

        while (*Right_Iter > Pivot_Ptr && distance(Left_Iter, Right_Iter) > 0)  // 우측 반복자로부터 현재 값이 기준 값보다 크면 반복자 -순회, 즉 기준 값보다 작은 값이 나올 때까지 반복하여 탐색
            --Right_Iter;

        if (Left_Iter == Right_Iter)            // 좌/우측 반복자가 같은 값을 가리키게 된다면 더 이상 정렬할 정보가 없다는 의미, 탈출
            break;
        else
            iter_swap(Left_Iter, Right_Iter);   // 피벗보다 큰 값(좌)과 작은 값(우)를 발견했으므로 서로 위치를 swap하여 정렬
    }

    if (Pivot_Ptr > *Right_Iter)                // 반환할 값보다 피벗의 값이 더 크면 피벗과 위치를 swap하여 정렬
        iter_swap(Begin, Right_Iter);

    return Right_Iter;                          // 최종적으로 Left_Iter == Right_Iter이므로 둘중 하나 반환하여 해당 값을 기준으로 나누고 연산을 이어나간다.
}

template<typename T>
void QuickSort(typename vector<T>::iterator Begin, typename vector<T>::iterator Last)
{
    if (distance(Begin, Last) >= 1)                         // 입력받은 반복자 사이의 값, 즉 벡터의 원소가 1개 이상 존재할 경우
    {
        auto Partition_Iter = Partition<T>(Begin, Last);    // 입력받은 반복자들을 Partition함수에 넘겨줌

        QuickSort<T>(Begin, Partition_Iter - 1);            // 결과로 받은 Partition 반복자를 기준으로 좌벡터와 우벡터로 나누어 다시 퀵정렬 실행
        QuickSort<T>(Partition_Iter, Last);
    }
}

string solution(string s) {

    string strCatchNum{ "" };
    vector<int> vecNum;
    for (int raw = 0; raw < s.length(); ++raw)
    {
        char pszCurSpell = s.at(raw);

        if (raw != (s.length()) && pszCurSpell != ' ')
        {
            strCatchNum.push_back(pszCurSpell);
        }

        if (raw == s.length() - 1 || pszCurSpell == ' ')
        {
            int iCatchNum{ stoi(strCatchNum) };
            vecNum.push_back(iCatchNum);
            strCatchNum = "";
        }
    }

    // 방법1. algorithm 라이브러리의 sort사용
    //sort(vecNum.begin(), vecNum.end());

    // 방법2. 퀵 정렬 직접 구현
    QuickSort<int>(vecNum.begin(), vecNum.end() - 1);

    string strMax{ to_string(vecNum.back()) };
    string strMin{ to_string(vecNum.front()) };

    string answer = strMin + " " + strMax;
    return answer;
}

int main()
{
    string strInput{ "-4 -3 -2 -1" };

    solution(strInput);

    return 0;
}