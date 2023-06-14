/*
* Ű���� : �� ����, string
*/

#include <string>
#include <vector>
#include <algorithm>

/*  ���� ����
    ���ڿ� s���� �������� ���е� ���ڵ��� ����Ǿ� �ֽ��ϴ�. 
    str�� ��Ÿ���� ���� �� �ּҰ��� �ִ밪�� ã�� �̸� "(�ּҰ�) (�ִ밪)"������ ���ڿ��� ��ȯ�ϴ� �Լ�, solution�� �ϼ��ϼ���.
    ������� s�� "1 2 3 4"��� "1 4"�� �����ϰ�, "-1 -2 -3 -4"��� "-4 -1"�� �����ϸ� �˴ϴ�.

���� ����
s���� �� �̻��� ������ �������� ���еǾ� �ֽ��ϴ�.
*/

/*  ��Ʈ

    1 2 3 4 ������ 1 4 ���
    ���Ⱑ ������ ������ ���� ������
*/

using namespace std;
/*
       Partition
       1. �ǹ��� ���ϰ�
       2. �� ��, �� �� �ݺ��ڸ� ���
       3. �� �� �ݺ��ڷκ���, ���� �ڽ��� �ǹ����� ũ�ų� ������������ �ݺ��� Ž��
       4. �� �� �ݺ��ڷκ���, ���� �ڽ��� �ǹ����� �۾��������� �ݺ��� Ž��
       5. 3�� 4�� ����� �ٸ��� �ش� ���ҵ��� ��ġ�� �ٲ��ְ�, ������ ������ �״�� ��ȯ

       Quicksort
       1. ������ ���Ϳ� ���Ұ� �ϳ��� ���� ��� partition�� ����� ���� ���͸� �������� ����
       2. �� ���ʹ� �Է¹��� ù �ݺ��ڷκ��� partition �ݺ��� -1
       3. �� ���ʹ� partition �ݺ��ڷκ��� ������ �ݺ���
       4. ���Ұ� �ϳ��� �� ������ �ݺ�
*/

template<typename T>
auto Partition(typename vector<T>::iterator Begin, typename vector<T>::iterator Last)
{
    auto Pivot_Ptr = *Begin;            // ���� ��, ���� ������ ���� ����
    auto Left_Iter = Begin + 1;         // ���� �� ������ ��
    auto Right_Iter = Last;             // ���� �� �������� ��

    while (true)    // ���� �Ϻ��� ������ �� ���� �ݺ�
    {
        // distance(Left_Iter, Right_Iter) > 0 ���ǹ��� �ݺ��� �ȿ� ���� �ִ��� �������� ���� ����ó����

        while (*Left_Iter <= Pivot_Ptr && distance(Left_Iter, Right_Iter) > 0)  // ���� �ݺ��ڷκ��� ���� ���� ���� ������ �۰ų� ������ �ݺ��� +��ȸ, �� ���� ������ ū ���� ���� ������ �ݺ��Ͽ� Ž��
            ++Left_Iter;

        while (*Right_Iter > Pivot_Ptr && distance(Left_Iter, Right_Iter) > 0)  // ���� �ݺ��ڷκ��� ���� ���� ���� ������ ũ�� �ݺ��� -��ȸ, �� ���� ������ ���� ���� ���� ������ �ݺ��Ͽ� Ž��
            --Right_Iter;

        if (Left_Iter == Right_Iter)            // ��/���� �ݺ��ڰ� ���� ���� ����Ű�� �ȴٸ� �� �̻� ������ ������ ���ٴ� �ǹ�, Ż��
            break;
        else
            iter_swap(Left_Iter, Right_Iter);   // �ǹ����� ū ��(��)�� ���� ��(��)�� �߰������Ƿ� ���� ��ġ�� swap�Ͽ� ����
    }

    if (Pivot_Ptr > *Right_Iter)                // ��ȯ�� ������ �ǹ��� ���� �� ũ�� �ǹ��� ��ġ�� swap�Ͽ� ����
        iter_swap(Begin, Right_Iter);

    return Right_Iter;                          // ���������� Left_Iter == Right_Iter�̹Ƿ� ���� �ϳ� ��ȯ�Ͽ� �ش� ���� �������� ������ ������ �̾����.
}

template<typename T>
void QuickSort(typename vector<T>::iterator Begin, typename vector<T>::iterator Last)
{
    if (distance(Begin, Last) >= 1)                         // �Է¹��� �ݺ��� ������ ��, �� ������ ���Ұ� 1�� �̻� ������ ���
    {
        auto Partition_Iter = Partition<T>(Begin, Last);    // �Է¹��� �ݺ��ڵ��� Partition�Լ��� �Ѱ���

        QuickSort<T>(Begin, Partition_Iter - 1);            // ����� ���� Partition �ݺ��ڸ� �������� �º��Ϳ� �캤�ͷ� ������ �ٽ� ������ ����
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

    // ���1. algorithm ���̺귯���� sort���
    //sort(vecNum.begin(), vecNum.end());

    // ���2. �� ���� ���� ����
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