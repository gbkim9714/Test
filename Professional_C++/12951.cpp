#include <string>
#include <vector>

using namespace std;

/*

JadenCase�� ��� �ܾ��� ù ���ڰ� �빮���̰�, �� ���� ���ĺ��� �ҹ����� ���ڿ��Դϴ�. 
��, ù ���ڰ� ���ĺ��� �ƴ� ������ �̾����� ���ĺ��� �ҹ��ڷ� ���� �˴ϴ�. (ù ��° ����� �� ����)
���ڿ� s�� �־����� ��, s�� JadenCase�� �ٲ� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ����ּ���.

���� ����
s�� ���� 1 �̻� 200 ������ ���ڿ��Դϴ�.
s�� ���ĺ��� ����, ���鹮��(" ")�� �̷���� �ֽ��ϴ�.
���ڴ� �ܾ��� ù ���ڷθ� ���ɴϴ�.
���ڷθ� �̷���� �ܾ�� �����ϴ�.
���鹮�ڰ� �����ؼ� ���� �� �ֽ��ϴ�.

*/

/* NotePad
   
   �Է¹��� String���� �������� �Ǵ��ؼ� ���� �־�� ��
   �빮�� : 65 ~ 90, �ҹ��� 97 ~ 122

   ���۹��ڰ� �ҹ����� ��� �빮�ڷ� �����ؾ� �ϰ�, ���� ���ڰ� �빮���� ��� �ҹ��ڷ� �����ؾ� �Ѵ�.
*/

string solution(string s) {

    bool bUpper{ true };     // ���� �� �ܾ�� ������ �빮��

    for (auto& iter : s)
    {
        int iCurAscii = static_cast<int>(iter);

        if (bUpper)
        {
            if (97 <= iCurAscii && 122 >= iCurAscii)
            {
                iCurAscii -= 32;
                iter = static_cast<char>(iCurAscii);
            }

            bUpper = false;
        }
        else
        {
            if (65 <= iCurAscii && 90 >= iCurAscii)
            {
                iCurAscii += 32;
                iter = static_cast<char>(iCurAscii);
            }
        }

        if (iter == ' ')
        {
            bUpper = true;
        }
    }

    string answer{ s };

    return answer;
}

int main()
{
    solution("3people unFollowed me");

    return 0;
}