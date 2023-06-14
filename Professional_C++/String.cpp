#pragma once
#include <iostream>
#include <cstring>
#include <charconv>
#include <format>
#include <vector>
using namespace std;

#pragma region 로우 레벨 숫자 변환

//int main()
//{
//	/*	
//		하이 레벨 변환과의 차이점
//		1. 메모리 할당 작업이 일어나지 않고, std::string도 다루지 않아 버퍼를 할당하는 방식으로 사용
//		2. 고성능과 로케일 독립성에 최적화 -> 하이레벨에 비해 연산속도 매우 우수
//		3. 퍼펙트 라운드 트리핑 방식으로 설계 -> 숫자값을 string형태로 직렬화한 후 해당 결과를 다시 역직렬 시 원본 string값이 나옴
//	
//		to_chars_result 
//		{
//			char* ptr;	// string에 들어갈 문자열
//			errc ec;	// 에러 발생 시 채워짐, 비정상 동작 시 errc::value_to_large 반환
//		})
//
//		from_chars_result
//		{
//			const char* ptr;	// 변환 실패시 (string)first의 포인터, 성공시 last의 포인터
//			errc ec;			// 에러 발생 시 채워짐, 비정상 동작 시 errc::result_out_of_range 반환
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

#pragma endregion 로우 레벨 숫자 변환

#pragma region string_view

///*
//	리터럴 스트링 사용 시 값이 복사되어 메모리 공간이 할당되는 문제를 해결하기 위해 생겨난 문법
//	string_view를 사용하면 메모리가 할당되지 않는다.
//	string_view에 임시string을 넣으면 댕글링 포인터가 발생한다!
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

#pragma region 연습문제 2-1

/*
	string 2개를 입력받아서 알파벳 순서로 정렬, 3방향 연산자 사용
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

#pragma endregion 연습문제 2-1

#pragma region 연습문제 2-2

/*
	1. 사용자로부터 원본 스트링과 그 안에서 찾을 스트링, 대체할 스트링을 입력받는 프로그램
	2. 1의 입력들을 매개변수를 이용하는 함수를 만들고, 교체한 스트링을 return하게 하기
	3. string_view 사용 X
*/

//string StringReplacer(string& _strOrigin, const string& _strFind, const string& _strChange)
//{
//	// _strOrigin은 변경되어야 하므로 const가 붙으면 안된다
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

#pragma endregion 연습문제 2-2

#pragma region 연습문제 2-3

/*
	위의 문제를 string_view를 사용하여 풀어보기
	string_view는 문자열을 입력받는 역할이 아님
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

#pragma endregion 연습문제 2-3