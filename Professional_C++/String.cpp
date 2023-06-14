#pragma once
#include <iostream>
#include <cstring>
#include <charconv>
#include <format>
#include <vector>
using namespace std;

#pragma region �ο� ���� ���� ��ȯ

//int main()
//{
//	/*	
//		���� ���� ��ȯ���� ������
//		1. �޸� �Ҵ� �۾��� �Ͼ�� �ʰ�, std::string�� �ٷ��� �ʾ� ���۸� �Ҵ��ϴ� ������� ���
//		2. ���ɰ� ������ �������� ����ȭ -> ���̷����� ���� ����ӵ� �ſ� ���
//		3. ����Ʈ ���� Ʈ���� ������� ���� -> ���ڰ��� string���·� ����ȭ�� �� �ش� ����� �ٽ� ������ �� ���� string���� ����
//	
//		to_chars_result 
//		{
//			char* ptr;	// string�� �� ���ڿ�
//			errc ec;	// ���� �߻� �� ä����, ������ ���� �� errc::value_to_large ��ȯ
//		})
//
//		from_chars_result
//		{
//			const char* ptr;	// ��ȯ ���н� (string)first�� ������, ������ last�� ������
//			errc ec;			// ���� �߻� �� ä����, ������ ���� �� errc::result_out_of_range ��ȯ
//		})
//	*/
//
//
//	const size_t strSize{ 50 };
//	string strTest(strSize, ' ');
//	to_chars_result tcResult = to_chars(strTest.data(), strTest.data() + strSize, 12345);
//	if (tcResult.ec == errc{}) { cout << strTest << endl; }
//
//	string strFloatConvTest(strSize, ' ');
//	to_chars_result tcFloatConvResult = to_chars(strFloatConvTest.data(), strFloatConvTest.data() + strSize, 123.45f);
//	to_chars_result toFloatcontResult_2 = to_chars(strFloatConvTest.data(), strFloatConvTest.data() + strSize, 1234.5f, chars_format::general);
//	if (tcFloatConvResult.ec == errc{}) { cout << strFloatConvTest << endl; }
//
//	int iValue_1{ 0 };
//	from_chars_result fcResult = from_chars(strTest.data(), strTest.data() + strSize, iValue_1);
//	if (fcResult.ec == errc{}) { cout << iValue_1 << endl; }
//	return 0;
//}

#pragma endregion �ο� ���� ���� ��ȯ

#pragma region string_view

///*
//	���ͷ� ��Ʈ�� ��� �� ���� ����Ǿ� �޸� ������ �Ҵ�Ǵ� ������ �ذ��ϱ� ���� ���ܳ� ����
//	string_view�� ����ϸ� �޸𸮰� �Ҵ���� �ʴ´�.
//	string_view�� �ӽ�string�� ������ ��۸� �����Ͱ� �߻��Ѵ�!
//*/
//
//void StringViewFunc(string_view sv)
//{
//	cout << format("{}", sv) << endl;
//}
//
//void StringFunc(const string& str)
//{
//	cout << str << endl;
//}
//
//int main()
//{
//	StringViewFunc("This is string_view test string");
//	StringFunc("This is string_view test string");
//}

#pragma endregion string_view

#pragma region format

//int main()
//{
//	cout << format("{:{}}", 42, 7) << endl;
//
//	cout << format("|{:#^ 8}|", 42) << endl;
//}

#pragma endregion format

#pragma region �������� 2-1

/*
	string 2���� �Է¹޾Ƽ� ���ĺ� ������ ����, 3���� ������ ���
*/

//int main()
//{
//	string strLeft{ "" };
//	string strRight{ "" };
//
//	cin >> strLeft >> strRight;
//
//	int iLeftResult{ static_cast<int>(strLeft.front()) };
//	int iRightResult{ static_cast<int>(strRight.front()) };
//
//	strong_ordering soResult{ iLeftResult <=> iRightResult };
//
//	if (soResult == strong_ordering::less)
//	{
//		cout << format("{}", strLeft) << endl;
//		cout << format("{}", strRight) << endl;
//	}
//	else if (is_gt(soResult))
//	{
//		cout << format("{}", strRight) << endl;
//		cout << format("{}", strLeft) << endl;
//	}
//	else if (soResult == strong_ordering::equal)
//	{
//		cout << format("{}", strLeft) << endl;
//		cout << format("{}", strRight) << endl;
//	}
//
//	return 0;
//}

#pragma endregion �������� 2-1

#pragma region �������� 2-2

/*
	1. ����ڷκ��� ���� ��Ʈ���� �� �ȿ��� ã�� ��Ʈ��, ��ü�� ��Ʈ���� �Է¹޴� ���α׷�
	2. 1�� �Էµ��� �Ű������� �̿��ϴ� �Լ��� �����, ��ü�� ��Ʈ���� return�ϰ� �ϱ�
	3. string_view ��� X
*/

//string StringReplacer(string& _strOrigin, const string& _strFind, const string& _strChange)
//{
//	// _strOrigin�� ����Ǿ�� �ϹǷ� const�� ������ �ȵȴ�
//
//	auto szFindPoint{ _strOrigin.find(_strFind) };
//
//	if (static_cast<size_t>(szFindPoint) == string::npos)
//	{
//		return "Cannot Find That String!";
//	}
//
//	string strReplace{ "" };
//	return _strOrigin.replace(_strOrigin.find(_strFind), _strChange.length(), _strChange);
//}
//
//int main()
//{
//	string strOrigin{""};
//	string strFind{""};
//	string strChange{""};
//
//	cout << "Origin : ";
//	cin >> strOrigin;
//	cout << endl;
//
//	cout << "Find : ";
//	cin >> strFind;
//	cout << endl;
//
//	cout << "Change : ";
//	cin >> strChange;
//	cout << endl;
//
//	string strResult = StringReplacer(strOrigin, strFind, strChange);
//	cout << format("{}", strResult) << endl;
//
//	return 0;
//}

#pragma endregion �������� 2-2

#pragma region �������� 2-3

/*
	���� ������ string_view�� ����Ͽ� Ǯ���
	string_view�� ���ڿ��� �Է¹޴� ������ �ƴ�
*/

//string StringViewReplacer(string& _strOrigin, string_view _strFind, string_view _strReplace)
//{
//	if (_strOrigin.find(_strFind) != string::npos)
//	{
//		return _strOrigin.replace(_strOrigin.find(_strFind), _strReplace.length(), _strReplace);
//	}
//	else
//	{
//		return "Cannot";
//	}
//}
//
//int main()
//{
//	string strOrigin{ "" };
//	string strFind{ "" };
//	string strReplace{ "" };
//
//	cout << "origin : ";
//	cin >> strOrigin;
//
//	cout << "find : ";
//	cin >> strFind;
//
//	cout << "replace : ";
//	cin >> strReplace;
//
//	cout << StringViewReplacer(strOrigin, strFind, strReplace) << endl;
//}

#pragma endregion �������� 2-3