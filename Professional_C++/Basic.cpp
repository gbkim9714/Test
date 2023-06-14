#pragma once
import "HeaderUnits.h";
import employee;

#pragma region NameSapce_Declaration

using namespace std;

namespace BasicTest
{
	void NameSpaceFunc()
	{
		std::cout << "This is NameSpace\n";
	}
}

namespace BasicTest::NestedNameSpace
{
	void NameSpaceFunc()
	{
		cout << "This Is NestedNameSpace\n";
	}
}

namespace NameSpaceAlies = BasicTest::NestedNameSpace;

#pragma endregion NameSpace_Declaration

#pragma region EnumClass_Declaration

enum class EnumTest : unsigned int
{
	One,
	Two,
	Three,
	Eleven = 11
};

using enum EnumTest;

#pragma endregion EnumClass_Declaration

#pragma region Function

void FunctionTest(int iLeft, int iRight);	// 정의

void FunctionTest(int iLeft, int iRight)	// 선언
{
	cout << iLeft << " " << iRight << "\n";
}

auto AutoFuncTest(int iLeft, int iRight)
{
	return iLeft + iRight;	// auto 사용시 함수 내부의 반환타입 일치 필요

	// 만일 재귀 타입으로 이용할 경우 재귀 반환뿐이 아닌 일반적인 반환타입도 필요로 한다.
}

void FuncNameTest(void)
{
	// __func__ : 현재 함수의 이름 반환
	cout << "This Func's Name is " << __func__ << "\n";
}

// 오버로딩
int Overloading(int iLeft, int iRight)
{
	return iLeft + iRight;
}
double Overloading(double fLeft, double fRight)
{
	return fLeft + fRight;
}


#pragma endregion Function

#pragma region Optional

	/*std::optional : 특정 값을 가질 수도, 가지지 않을 수도 있음
	* 함수 매개변수가 있거나 없을 때 사용이 가능함
	* return -1; 대신 사용하는 키워드
	*/

optional<int> OptionalFunc(bool bOptional)
{
	if (bOptional) return 42;

	return nullopt;
}

#pragma endregion Optional

#pragma region Attribute_Declaration

// [[nodiscard]] : 반환 타입에 아무런 행위를 하지 않을 경우 warning 반환
[[nodiscard]] int NoDiscardFunc()
{
	return 42;
}

// nodiscard 키워드 동작 시 해당 string값을 에러창에 출력함
[[nodiscard("NoDiscard is Activate")]] int NoDiscardStringFunc()
{
	return 42;
}

// [[maybe_unused]] : 특정 값을 사용하지 않았을 때 컴파일러가 생성하는 에러메시지를 없애는 키워드
// 클래스, 구조체, 비static 데이터 멤버, 유니온, typedef, 타입 앨리어스, 변수, 함수, 열거타입 등에 사용 가능
int Maybe_unusedFunc(int iLeft, [[maybe_unused]]int iRight)
{
	return 42;
}

// [[noreturn]] : 호출 지점으로 다시 돌아가게 하지 않는 함수, 뭔가의 종료나 익셉션을 던지는 함수에 사용
// 반환타입으로써 무언가를 반환하지 않고도 바로 프로그램을 종료하거나 다른 무언가를 호출하도록 할 때 사용
[[noreturn]]void forceProgramTerminationg()
{
	std::exit(1);
}
bool isDongleAvailable()
{
	bool isAvailable{ false };
	return isAvailable;
}
bool isFeatureLicensed(int featureID)
{
	if (!isDongleAvailable())	
		forceProgramTerminationg();	// warning C4715: 'isFeatureLicensed': 모든 제어 경로에서 값을 반환하지는 않습니다.
	else
	{
		bool isLicensed{ featureID == 42 };
		return isLicensed;
	}
}

// [[deprecated]] : 지원 중단된 대상임을 가르키며, 오류 목록에 출력이 가능
[[deprecated("지원이 중단된 함수")]] int deprecatedFunc()
{
	return 42;
}

#pragma endregion Attribute_Declaration

#pragma region 초기자 리스트 함수

// 해당 방식으로 타입이 같은 여러 개의 매개변수를 받을 수 있다.
// 초기자 리스트는 타입에 안전하다.(다른 타입의 매개변수가 들어오면 에러 반환)
int InitList_Func(initializer_list<int> values)
{
	int iResult{ 0 };
	for (auto iter : values)
	{
		iResult += iter;
	}
	return iResult;
}

#pragma endregion 초기자 리스트 함수

#pragma region 스코프 연산자

class ScopeClass
{
public:
	void Scope_Get() { cout << "10\n"; }
}; 

void Scope_Get() { cout << "20\n"; }

namespace ScopeNamespace
{
	void Scope_Get() { cout << "30\n"; }
}

#pragma endregion 스코프 연산자

#pragma region const

// const를 통해 매개변수를 넘겨받은 함수는 지역 내에서 매개변수에 대해 변경할 수 없다.
void ConstParmFunc_ptr(const string* strString)
{
	cout << *strString << endl;
}
void ConstParmFunc_ref(const string& strString)
{
//	strString = "Hello";	// error C2678: 이항 '=': 왼쪽 피연산자로 'const std::string' 형식을 사용하는 연산자가 없거나 허용되는 변환이 없습니다.
	cout << strString << endl;
}
void ConstParmFunc_Norm(const int iConst)
{
	cout << iConst << endl;
}

class Constclass
{
public:
	int GetConstNum() const { return iConstNum; }	// 반환되는 멤버 값이 상수화됨
	const string GetConstString() const { return strConstString; }

private:
	const int iInspector{ 0 };	// 클래스 내의 변하지 않는 const멤버 : 인스펙터
	int iMutator{ 0 };			// 클래스 내의 변하는 비const멤버 : 뮤테이터

	int iConstNum{ 0 };
	string strConstString{ "ConstMan" };
};

#pragma endregion const

#pragma region constexpr

constexpr int GetArrSize() { return 32;}

int ConstExprArr[GetArrSize()]{};
/*배열의 인덱스로 변수값을 전달받을 수는 없지만, 상수 표현식을 사용하면 가능하다.
* 제한사항 : constexpr함수는 일반 함수를 호출할 수 없다.
*/

#pragma endregion constexpr

#pragma region consteval

consteval double inchToMm(double fInch) { return fInch * 25.4; }
//constexpr double inchToMm(double fInch) { return fInch * 25.4; }

constexpr double fConstInch{ 6.0 };
constexpr double fMm{ inchToMm(fConstInch) };

//double fInch{ 8.0 };
//double fMm_2{ inchToMm(fInch) };	// consteval 키워드 사용 시 컴파일 시간에 평가되지 않으면 에러 발생

#pragma endregion consteval

#pragma region const_cast

void constcastFunc(const char* str)
{
	cout << str << endl;
}

#pragma endregion const_cast

const string message{ "Message" };
const string& GetMsg() { return message; }

/***********************************************************************************/

int main()
{
	std::cout << "Hello World!\n";

#pragma region  NameSpace

	BasicTest::NameSpaceFunc();

	BasicTest::NestedNameSpace::NameSpaceFunc();

	NameSpaceAlies::NameSpaceFunc();

#pragma endregion NameSpace_Definition

#pragma region EnumClass_Declaration

	EnumTest::One;

	EnumTest eUsingEnum{ Three };

	if (EnumTest::Three == eUsingEnum)
	{
		cout << "eUsingEnum is Three\n";
	}

	enum ePreEnum { One, Two, Three, };
	/*
	* 이전 방식의 enum의 열거 타입은 강타입이 아니기에 안전하지 않음 -> 값이 정수로 해석되기에 정수와의 비교가 가능해짐
	*/

#pragma endregion EnumClass_Definition

#pragma region Initialize

	// Literal(상수) : 코드에 표시한 숫자나 스트링과 같은 값

	int Initalize = 0;
	int Uniform_Initialize{ 0 };
	/*
	* 유니폼 초기화 : C++11 이후 도입
	*/

	byte InitByte{ 42 };
	/*
	* Byte : C++17 이후 도입, 이전에는 1바이트를 표현하기 위헤 Char를 사용했지만, 확실한 표기를 위해 추가됨
	*/

	int Zero_Initialize{};

#pragma endregion Initizlize

#pragma region Limits

	cout << numeric_limits<int>::max() << "\n";
	cout << numeric_limits<double>::min() << "\n";
	cout << numeric_limits<float>::lowest() << "\n";
	/*
	* 최소값과 최저값의 차이
	* 정수에서의 최소값과 최저값은 동일하지만, 부동소수점에서 최소값은 표현 가능한 가장 작은 양수, 최저값은 표현 가능한 가장 작은 음수
	*/

#pragma endregion Limits

#pragma region Casting

	float fCast = 3.1415f;
	int Cast_A{ (int)fCast };
	int Cast_B{ int(fCast) };
	int Cast_C{ static_cast<int>(fCast) };

	// 강제 형변환
	short ShortCoerce{ 0 };
	long LongCoerce{ ShortCoerce };

	// 실수를 정수로 캐스팅할 때에는 소수점 아래의 데이터가 사라진다. 대이터 손실에 유의해야 함

#pragma endregion Casting

#pragma region 부동소수점

	/* 사용시 유의사항
	* 부동소수점은 소수점 자리가 다른 부동소수끼리의 연산에서 에러가 발생할 수 있다.
	* 부동소수점은 거의 동일한 부동소수끼리 뺄셈 연산을 할 때에도 정밀도 손실이 발생할 수 있다.
	*/

	// 0 / 0 연산이 발생할 경우 Nan을 반환
	float fNanTest{ 0.f };
	fNanTest /= 0.f;			// warning C4723: 0의 나누기 연산이 발생할 수 있습니다.
	if (std::isnan(fNanTest))
	{
		cout << "fNanTest is Nan\n";
	}

	// 0이 아닌 수를 0으로 나눌 경우 Inf를 반환
	float fInfTest{ -1.f };
	fInfTest /= 0.f;			// warning C4723: 0의 나누기 연산이 발생할 수 있습니다.
	if (std::isinf(fInfTest))
	{
		cout << "fNanTest is Infinite\n";
	}

	cout << numeric_limits<double>::infinity() << "\n";

#pragma endregion 부동소수점

#pragma region 연산자

	int iA{ 1 };
	int iB;
	iB = iA;

	bool bTrue = true;
	bool bFalse = !bTrue;

	int iSum = iA + iB;
	int iSub = iA - iB;
	int iMul = iA * iB;
	int iDiv = iA / iB;
	int iMod = iA % iB;

	iA++;
	iB--;
	--iA;
	++iB;

	iA += iB;
	iA -= iB;
	iA *= iB;
	iA /= iB;
	iA %= iB;

	int iBitA{ 3 };
	int iBitB{ 1 };

	int iBit_AND = iBitA & iBitB;		// 비트AND연산
	int iBit_OR = iBitA | iBitB;		// 비트OR연산
	int iBit_XOR = iBitA ^ iBitB;		// 비트XOR연산
	int iBit_ShiftPlus = iBitA << 1;	// 비트수를 왼쪽으로 밂 ( 1 -> 2 )
	int iBit_ShiftMinus = iBitA >> 1;	// 비트수를 오른쪽으로 밂 ( 2 -> 1 )

	/* 연산자는 우선순위에 따라 연산 순서를 결정함
	* 후위 ++, --
	* 전위 ++, --, !
	* * , %
	* +, -
	* <<, >>
	* &
	* *
	* |
	* =, +=, -= 등등
	*/

#pragma endregion 연산자

#pragma region Module & Struct

	Employee tEmployee;
	tEmployee.cFirstInitial = 'A';
	tEmployee.cLastInitial = 'B';
	tEmployee.iEmployeeNumber = 0;
	tEmployee.iSalary = 0;

	Employee ttEmployee
	{
		'C',
		'D',
		1,
		1
	};

#pragma endregion Module & Struct

#pragma region 조건문

	if (bTrue)
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}

	// if문의 초기자
	if (Employee ifEmployee{ tEmployee }; 'A' == ifEmployee.cFirstInitial)
	{
		cout << "ifEmployee.cFirstInitial is A\n";
	}

	// switch에 지정할 수 있는 값은 정수 또는 열거타입이어야 함
	EnumTest eSwitchEnum{ EnumTest::Two };
	switch (eSwitchEnum)
	{
	case EnumTest::One:

	case EnumTest::Two:
		cout << "eSwitchEnum is EnumTest::Two\n";
		[[fallthrough]];	// 의도적인 fallthrough의 경우 명시할 것
	case EnumTest::Three:
		break;
	default:
		break;
	}
	/*
	* 표현식의 만족 여부보단 표현식의 다양한 결과값에 따라 수행할 동작을 결정하는데 사용
	* Break문이 나올 때까지 다음 Case문도 조사한다(fallthrough).
	*/

	// switch문의 초기자
	switch (EnumTest eSwitchInit{ EnumTest::One }; eSwitchInit)
	{
	case EnumTest::One:
		cout << "eSwitchInit is EnumTest::One\n";
		[[fallthrough]];
	case EnumTest::Two:
		cout << "This is FallThrough\n";
		break;
	case EnumTest::Three:
		break;
	default:
		break;
	}

	// 조건 연산자(삼항 연산자)
	int iTurnery{ 10 };
	bool bTunery = (iTurnery > 5) ? true : false;
	if (bTunery) { cout << "iTunery is More Then 5\n"; }

#pragma endregion 조건문

#pragma region 논리연산자

	int iLogical_Left = 0;
	int iLogical_Right = 1;

	// 논리 연산자 사용 중 True가 반환되면 단락 논리가 발생하며, 이후의 연산은 진행하지 않는다.

	/* 3방향 비교 연산자 -> 비교 작업이 복잡한 객체에 대해서 유용
	* <정수, 강한 순서>
	* strong_ordering::less		-> left < right
	* strong_ordering::greater	-> left > right
	* strong_ordering;:equal	-> left == right
	* <실수, 부분 순서>
	* partical_ordering::less
	* partical_ordering::greater
	* partical_ordering::equivalent
	* partical_ordering::unordered	-> 둘 중 하나는 숫자가 아님
	* <재정의, 약한 순서>
	* weak_ordering::less
	* weak_ordering::greater
	* weak_ordering::equivalent
	*/


#pragma endregion 논리연산자

#pragma region 함수 사용

	FuncNameTest();

	cout << Overloading(1, 2) << "\n";
	cout << Overloading(3.1, 0.04) << "\n";

#pragma endregion 함수 사용

#pragma region Attribute_Definition

	// [[Attribute]] 형식으로 사용함

	NoDiscardFunc();		// warning C4834: 'nodiscard' 특성이 포함된 함수의 반환 값을 버리는 중
	int iNoDiscardReturn = NoDiscardFunc();

	NoDiscardStringFunc();	// warning C4858: 반환 값을 삭제하는 중: NoDiscard is Activate

	Maybe_unusedFunc(1, 2);

	//	isFeatureLicensed(42);

	//	deprecatedFunc();		// error C4996: 'deprecatedFunc': 지원이 중단된 함수


	//	[[likely]], [[unlikely ]] : 조건문에서 수행될 가능성이 높은 브렌치에 대한 명시 가능
	int iLikelyTest{ 5 };

	if (10 > iLikelyTest) [[unlikely ]] {/* 자주 사용되지 않는 부분 */ };

	switch (iLikelyTest)
	{
	[[likely]] case 5:
		/* 자주 사용되는 부분 */
		break;

	default:
		break;
	}

#pragma endregion Attribute_Definition

#pragma region 배열

	// 기존 스타일의 배열
	int iArrayTest[3]{};
	int iArrayTest_NoIndex[]{ 1,2,3,4 };
	int iArray_NoIndex_Size = size(iArrayTest_NoIndex);

	/*std::array
	* 기존 배열에 비하여...
	* 1. 항상 크기를 정확히 알 수 있음
	* 2. 동적 형변환을 하지 않기에 특정 종류의 버그를 방지할 수 있음
	* 3. Iterator를 사용하여 배열에 반복문 적용 가능
	*/
	array<int, 3>	iStdArrayTest{ 11,12,13 };
	array			iStdArray_CTAD{ 21,22,23 };	// 클래스 템플릿 인수 추론
	int iStdArrayTest_Size = iStdArrayTest.size();
	iStdArrayTest.at(0);
	iStdArrayTest[2];
	iStdArray_CTAD.at(1);

	// std::vector
	vector<int>		vecStdVectorTest{ 31,32,33 };
	vector			vecStdVectorTest_CTAD{ 41, 42, 43 };
	vecStdVectorTest.push_back(34);

	// std::pair
	pair<int, double>	TestPair{ 1, 3.14 };

#pragma endregion 배열

#pragma region Optional

	optional<int> iOptionalResult_True = OptionalFunc(true);
	optional<int> iOptionalResult_False = OptionalFunc(false);

	iOptionalResult_True.has_value();		// 42
	iOptionalResult_False.has_value();		// nullopt;

	iOptionalResult_True.value();			// 42
//	iOptionalResult_False.value();			// 처리되지 않은 예외 발생(0x75B079D2, Professional_C++.exe): Microsoft C++ 예외: std::bad_optional_access, 메모리 위치 
	iOptionalResult_False.value_or(0);		// nullopt이면 매개변수 반환

#pragma endregion Optional

#pragma region 구조적 바인딩

	// 여러 변수를 한번에 초기화하는 방식

	// 구조체, 배열 등에 담긴 값을 여러 개의 변수에 한번에 초기화 가능하다.
	struct Point { double m_x, m_y, m_z; };
	Point tPoint;
	tPoint.m_x = 1.0; tPoint.m_y = 2.0; tPoint.m_z = 3.0;
	auto [x, y, z] {tPoint};

	// 이는 레퍼런스로도 접근이 가능하다.
	auto& [xx, yy, zz] {tPoint};

	x;
	y;
	z = 4.0;;

	xx = 4.0;	// 주소값에 접근하여 원본 값의 변경도 가능

#pragma endregion 구조적 바인딩

#pragma region 반복문

	int iWhile{ 0 };
	while (5 > iWhile)
	{
		cout << "While_" << iWhile << "\t";
		++iWhile;
	}cout << endl;

	int iDoWhile{ 0 };
	do
	{
		cout << "DoWhile_" << iDoWhile << "\t";
		++iDoWhile;
	} while (5 > iDoWhile);
	cout << endl;

	for (int iFor = 0; iFor < 5; ++iFor)
	{
		cout << "For_" << iFor << "\t";
	}cout << endl;

	array<int, 5> forArray{ 1,2,3,4,5 };
	for (auto iter : forArray)
	{
		cout << "iterFor_" << iter << "\t";
	}cout << endl;

	for (auto& iter : forArray)
	{
		iter += 1;
		cout << "refIterFor_" << iter << "\t";
	}cout << endl;

	// 초기자 활용
	for (vector<int> vecInit{ 1, 2, 3, 4, 5 }; auto iter : vecInit)
	{
		cout << "vecInit_" << iter << "\t";
	}cout << endl;

#pragma endregion 반복문

#pragma region 초기자 리스트

	// 클래스 템플릿임
	int iInitListFunc_Result{ InitList_Func({ 10, 20, 30, 40, 50 }) };

#pragma endregion 초기자 리스트

#pragma region string

	string mystring{ "Hello World!" };
	cout << "string is " << mystring << endl;
	cout << "First string is " << mystring[0] << endl;

#pragma endregion string

#pragma region 스코프 연산자

	ScopeClass scClass;

	scClass.Scope_Get();
	Scope_Get();
	ScopeNamespace::Scope_Get();
	::Scope_Get();

#pragma endregion 스코프 연산자

#pragma region 유니폼 초기화

	Employee Uniform_Employee{ 'U', 'N', 100, 200 };

	int* pArray_Uniform = new int[] { 0, 1, 2, 3 };
	delete[] pArray_Uniform;
	pArray_Uniform = nullptr;

#pragma endregion 유니폼 초기화

#pragma region 지정초기자

	/*	지정초기자 : 묶음 타입의 데이터 멤버를 초기화하는데 사용
	* 묶음 타입의 조건
	* 1. public 멤버 데이터만 가짐
	* 2. 사용자 정의 생성자 및 상속된 생성자가 없음
	* 3. virtual 함수 없음
	* 4. virtual, private, protected가 없음
	* -> 해당 조건을 만족하는 배열 타입의 객체, 구조체, 클래스 객체를 의미함
	*/

	// 어떤 것에 대해 초기화를 진행하는지 명시적으로 나타냄
	// 근데 순서는 지켜야되며, 여기에서 초기화하지 않으면 클래스 내 생성자에서 초기화한 값이 들어감
	Employee DesignatedEmployee{
		.cFirstInitial = 'D',
		.cLastInitial = 'S',
		.iEmployeeNumber = 100,
		.iSalary = 200
	};

#pragma endregion 지정초기자

#pragma region 포인터, 동적 메모리

	/* 용어 설명
	* 스택 프레임 : 함수가 호출되는 순서, 현재 호출되는 함수의 값은 최상단의 스택 프레임에 쌓임
	* 새로운 함수가 호출되어 해당 함수로 매개변수를 전달하는 경우, 호출하는 함수의 스택프레임에서 새로운 함수의 스택프레임으로 복사가 일어난다.
	* 프리스토어 : 포인터 개념
	*/

	int* iPtr = nullptr;	// 포인터 null초기화
	iPtr = new int;			// 메모리 할당

	*iPtr = 8;				// 값 할당
	delete iPtr;			// 할당 해제
	iPtr = nullptr;

	Employee* pEmployee = new Employee;
	(*pEmployee).cFirstInitial = 'P';
	pEmployee->cLastInitial = 'T';
	pEmployee->iEmployeeNumber = 100;
	pEmployee->iSalary = 300;

	bool bEmployee{ pEmployee && (pEmployee->iSalary > 100) ? true : false };
	delete pEmployee;
	pEmployee = nullptr;

	int* iPtrArray = new int[5]{ 0, 1, 2, 3, 4 };
	delete[] iPtrArray;
	iPtrArray = nullptr;

#pragma endregion 포인터, 동적 메모리

#pragma region const

	const int iConstInt{ 0 };
	//iConstInt{ 12 }; // error C2064: 항은 1개의 인수를 받아들이는 함수로 계산되지 않습니다.

	/*
	const 키워드로 지정한 값을 변경하려 할 경우 컴파일러는 에러를 발생시킴
	const 키워드로 지정한 대상을 최적화할 때 효율 증가 가능
	define매크로보다 const상수를 쓰는 것이 좋음 -> define은 단순히 텍스트 매칭 작업만 진행하지만,
	const는 컴파일러에서 판단하므로 정의 대상에 타입이나 스코프 정의가 가능
	*/

	// 포인터에서의const -> 바로 왼쪽에 있는 값을 const화한다!
	// 1. 포인터가 가리키고 있는 값(실제 내부 값)을 const화
	const int* pConstInt_Value_0 = nullptr;
	int const* pconstInt_Value_1 = nullptr;
	// 2. 포인터 자체(주소값)를 const화 -> 변경이 불가능해지므로 선언과 동시에 초기화 필요
	int* const pConstInt_Addr{ nullptr };

	string strConstFuncString{ "I'm Const String" };
	int iConstFuncInt{ 10 };
	ConstParmFunc_ptr(&strConstFuncString);
	ConstParmFunc_ref(strConstFuncString);
	ConstParmFunc_Norm(iConstFuncInt);


#pragma endregion const

#pragma region Reference

	// 레퍼런스 = 변수에 대한 앨리어스, 레퍼런스에서 수정한 값은 해당 변수에 똑같이 적용, 역참조 연산
	// 레퍼런스의 대상은 변경할 수 없다.
	int iNonRef{ 10 };
	int& iRef{ iNonRef };
	iRef = 12;

	// const는 기본적으로 const의 성격을 가짐
	const int& iConstRef{ iNonRef };	// 이렇게 하면 해당 레퍼런스를 통해 값을 변경할 수 없다. 기존 변수를 통한 변경은 가능

	// const 레퍼런스는 상수로 바로 초기화가 가능하다 -> 상수처럼 사용이 가능함
	const int& iImdConstRef{ 5 };

	int* iNonRef_ptr{ nullptr };
	int*& iRef_ptr{ iNonRef_ptr };	// 결국 그냥 변수처럼 되어버림, 하지만 레퍼런스의 성격은 가진다
	iRef_ptr = new int;
	*iRef_ptr = 6;
	delete iNonRef_ptr;
	iNonRef_ptr = nullptr;

	// 레퍼런스의 주소는 해당 값에 대한 주소와 같다.
	// int* = &int
	// + 레퍼런스 타입에 대한 레퍼런스는 불가능하다!

	/* 정리
	* int iPointer; 에 대하여
	* int* iPointer -> 포인터, iPointer = 주소값, *iPointer = 값
	* int& iPointer -> 레퍼런스, iPointer = 값, &iPointer = 주소값
	*/

	/*
	* 레퍼런스 전달 방식은 객체를 복사하지 않고 레퍼런스에 대한 참조만 발생하므로 효율이 증가한다.
	* 또한 값 전달 방식을 지원하지 않는 클래스도 존재하기 때문에 해당 방식이 더 효율적이다.
	*/

	/*레퍼런스 vs 포인터
	* 레퍼런스의 값은 null이 될 수 없으며, 명시적으로 역참조하는 행위는 불가능함 -> 보다 안전
	* 하지만 반드시 포인터를 사용해야 하는 상황?
	* 1. 가리키는 위치, 즉 주소값을 변경해야 하는 상황 -> 레퍼런스는 가리키는 주소를 바꿀 수 없다
	* 2. 주소값이 nullptr이 될 수 있는 값은 포인터를 사용해야 한다.
	* 3. 컨테이너에 다형성 타입을 저장할 때 포인터를 사용해야 한다.
	*/

	/* 함수의 매개변수를 이용하여 값을 반환하는 방식보다는 return을 사용하여 값을 반환하는 방식이 좋다.
	* 반환값이 로컬 변수, 함수에 대한 매개변수, 임시값일 경우 '리턴값 최적화'(RVO)가 일어난다.
	* 반환값이 오컬 변수일 경우 '이름 있는 리턴값 최적화'(NRVO)도 일어난다.
	* 두 방식(복제 생략)이 발생할 경우 컴파일러는 리턴하는 값을 복제하지 않는다 -> 복제 없는 값 전달 방식
	*/

#pragma endregion Reference

#pragma region const_cast

	// const_cast<type>(), as_const()는 const키워드를 잠시 제거해주는 역할을 한다.
	// const의 역할 상 제거하면 안되지만 외부 라이브러리를 사용하는 등 특수한 경우에 사용

	char* strName = new char[256];
	strcpy_s(strName, 256, "ConstCastTest");

	constcastFunc(const_cast<char*>(strName));
	constcastFunc(as_const(strName));

	delete[] strName;
	strName = nullptr;

#pragma endregion const_cast

#pragma region auto

	auto autoMessage_1{ GetMsg() };				// 복제 발생
	const auto& autoMessage_2{ GetMsg() };		// 레퍼런스 주소 전달
	// auto 방식은 const, 레퍼런스가 제거된다. 따라서 복사된 값을 받지 않으려면 따로 지정해야 한다.
	// 포인터에 대해 const를 지정하기 위헤서는 auto* 형식으로 작성해야 한다.

	int iAutoConstPtr = 1;

	auto* p1{ &iAutoConstPtr };
	const auto p2{ &iAutoConstPtr };	// int* const p2
	auto const p3{ &iAutoConstPtr };	// int* const p3
	const auto* p4{ &iAutoConstPtr };	// const int* p4
	auto* const p5{ &iAutoConstPtr };	// int* const p5

#pragma endregion auto

#pragma region 복제/직접 리스트 초기화

	auto copyList_1 = { 1 };
	auto copyList_2 = { 1, 2 };

	auto directList_1{ 1 };
	//auto directList_2{ 1, 2 };

#pragma endregion 복제/직접 리스트 초기화

	return 0;
}

