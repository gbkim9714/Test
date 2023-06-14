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

void FunctionTest(int iLeft, int iRight);	// ����

void FunctionTest(int iLeft, int iRight)	// ����
{
	cout << iLeft << " " << iRight << "\n";
}

auto AutoFuncTest(int iLeft, int iRight)
{
	return iLeft + iRight;	// auto ���� �Լ� ������ ��ȯŸ�� ��ġ �ʿ�

	// ���� ��� Ÿ������ �̿��� ��� ��� ��ȯ���� �ƴ� �Ϲ����� ��ȯŸ�Ե� �ʿ�� �Ѵ�.
}

void FuncNameTest(void)
{
	// __func__ : ���� �Լ��� �̸� ��ȯ
	cout << "This Func's Name is " << __func__ << "\n";
}

// �����ε�
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

	/*std::optional : Ư�� ���� ���� ����, ������ ���� ���� ����
	* �Լ� �Ű������� �ְų� ���� �� ����� ������
	* return -1; ��� ����ϴ� Ű����
	*/

optional<int> OptionalFunc(bool bOptional)
{
	if (bOptional) return 42;

	return nullopt;
}

#pragma endregion Optional

#pragma region Attribute_Declaration

// [[nodiscard]] : ��ȯ Ÿ�Կ� �ƹ��� ������ ���� ���� ��� warning ��ȯ
[[nodiscard]] int NoDiscardFunc()
{
	return 42;
}

// nodiscard Ű���� ���� �� �ش� string���� ����â�� �����
[[nodiscard("NoDiscard is Activate")]] int NoDiscardStringFunc()
{
	return 42;
}

// [[maybe_unused]] : Ư�� ���� ������� �ʾ��� �� �����Ϸ��� �����ϴ� �����޽����� ���ִ� Ű����
// Ŭ����, ����ü, ��static ������ ���, ���Ͽ�, typedef, Ÿ�� �ٸ��, ����, �Լ�, ����Ÿ�� � ��� ����
int Maybe_unusedFunc(int iLeft, [[maybe_unused]]int iRight)
{
	return 42;
}

// [[noreturn]] : ȣ�� �������� �ٽ� ���ư��� ���� �ʴ� �Լ�, ������ ���ᳪ �ͼ����� ������ �Լ��� ���
// ��ȯŸ�����ν� ���𰡸� ��ȯ���� �ʰ� �ٷ� ���α׷��� �����ϰų� �ٸ� ���𰡸� ȣ���ϵ��� �� �� ���
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
		forceProgramTerminationg();	// warning C4715: 'isFeatureLicensed': ��� ���� ��ο��� ���� ��ȯ������ �ʽ��ϴ�.
	else
	{
		bool isLicensed{ featureID == 42 };
		return isLicensed;
	}
}

// [[deprecated]] : ���� �ߴܵ� ������� ����Ű��, ���� ��Ͽ� ����� ����
[[deprecated("������ �ߴܵ� �Լ�")]] int deprecatedFunc()
{
	return 42;
}

#pragma endregion Attribute_Declaration

#pragma region �ʱ��� ����Ʈ �Լ�

// �ش� ������� Ÿ���� ���� ���� ���� �Ű������� ���� �� �ִ�.
// �ʱ��� ����Ʈ�� Ÿ�Կ� �����ϴ�.(�ٸ� Ÿ���� �Ű������� ������ ���� ��ȯ)
int InitList_Func(initializer_list<int> values)
{
	int iResult{ 0 };
	for (auto iter : values)
	{
		iResult += iter;
	}
	return iResult;
}

#pragma endregion �ʱ��� ����Ʈ �Լ�

#pragma region ������ ������

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

#pragma endregion ������ ������

#pragma region const

// const�� ���� �Ű������� �Ѱܹ��� �Լ��� ���� ������ �Ű������� ���� ������ �� ����.
void ConstParmFunc_ptr(const string* strString)
{
	cout << *strString << endl;
}
void ConstParmFunc_ref(const string& strString)
{
//	strString = "Hello";	// error C2678: ���� '=': ���� �ǿ����ڷ� 'const std::string' ������ ����ϴ� �����ڰ� ���ų� ���Ǵ� ��ȯ�� �����ϴ�.
	cout << strString << endl;
}
void ConstParmFunc_Norm(const int iConst)
{
	cout << iConst << endl;
}

class Constclass
{
public:
	int GetConstNum() const { return iConstNum; }	// ��ȯ�Ǵ� ��� ���� ���ȭ��
	const string GetConstString() const { return strConstString; }

private:
	const int iInspector{ 0 };	// Ŭ���� ���� ������ �ʴ� const��� : �ν�����
	int iMutator{ 0 };			// Ŭ���� ���� ���ϴ� ��const��� : ��������

	int iConstNum{ 0 };
	string strConstString{ "ConstMan" };
};

#pragma endregion const

#pragma region constexpr

constexpr int GetArrSize() { return 32;}

int ConstExprArr[GetArrSize()]{};
/*�迭�� �ε����� �������� ���޹��� ���� ������, ��� ǥ������ ����ϸ� �����ϴ�.
* ���ѻ��� : constexpr�Լ��� �Ϲ� �Լ��� ȣ���� �� ����.
*/

#pragma endregion constexpr

#pragma region consteval

consteval double inchToMm(double fInch) { return fInch * 25.4; }
//constexpr double inchToMm(double fInch) { return fInch * 25.4; }

constexpr double fConstInch{ 6.0 };
constexpr double fMm{ inchToMm(fConstInch) };

//double fInch{ 8.0 };
//double fMm_2{ inchToMm(fInch) };	// consteval Ű���� ��� �� ������ �ð��� �򰡵��� ������ ���� �߻�

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
	* ���� ����� enum�� ���� Ÿ���� ��Ÿ���� �ƴϱ⿡ �������� ���� -> ���� ������ �ؼ��Ǳ⿡ �������� �񱳰� ��������
	*/

#pragma endregion EnumClass_Definition

#pragma region Initialize

	// Literal(���) : �ڵ忡 ǥ���� ���ڳ� ��Ʈ���� ���� ��

	int Initalize = 0;
	int Uniform_Initialize{ 0 };
	/*
	* ������ �ʱ�ȭ : C++11 ���� ����
	*/

	byte InitByte{ 42 };
	/*
	* Byte : C++17 ���� ����, �������� 1����Ʈ�� ǥ���ϱ� ���� Char�� ���������, Ȯ���� ǥ�⸦ ���� �߰���
	*/

	int Zero_Initialize{};

#pragma endregion Initizlize

#pragma region Limits

	cout << numeric_limits<int>::max() << "\n";
	cout << numeric_limits<double>::min() << "\n";
	cout << numeric_limits<float>::lowest() << "\n";
	/*
	* �ּҰ��� �������� ����
	* ���������� �ּҰ��� �������� ����������, �ε��Ҽ������� �ּҰ��� ǥ�� ������ ���� ���� ���, �������� ǥ�� ������ ���� ���� ����
	*/

#pragma endregion Limits

#pragma region Casting

	float fCast = 3.1415f;
	int Cast_A{ (int)fCast };
	int Cast_B{ int(fCast) };
	int Cast_C{ static_cast<int>(fCast) };

	// ���� ����ȯ
	short ShortCoerce{ 0 };
	long LongCoerce{ ShortCoerce };

	// �Ǽ��� ������ ĳ������ ������ �Ҽ��� �Ʒ��� �����Ͱ� �������. ������ �սǿ� �����ؾ� ��

#pragma endregion Casting

#pragma region �ε��Ҽ���

	/* ���� ���ǻ���
	* �ε��Ҽ����� �Ҽ��� �ڸ��� �ٸ� �ε��Ҽ������� ���꿡�� ������ �߻��� �� �ִ�.
	* �ε��Ҽ����� ���� ������ �ε��Ҽ����� ���� ������ �� ������ ���е� �ս��� �߻��� �� �ִ�.
	*/

	// 0 / 0 ������ �߻��� ��� Nan�� ��ȯ
	float fNanTest{ 0.f };
	fNanTest /= 0.f;			// warning C4723: 0�� ������ ������ �߻��� �� �ֽ��ϴ�.
	if (std::isnan(fNanTest))
	{
		cout << "fNanTest is Nan\n";
	}

	// 0�� �ƴ� ���� 0���� ���� ��� Inf�� ��ȯ
	float fInfTest{ -1.f };
	fInfTest /= 0.f;			// warning C4723: 0�� ������ ������ �߻��� �� �ֽ��ϴ�.
	if (std::isinf(fInfTest))
	{
		cout << "fNanTest is Infinite\n";
	}

	cout << numeric_limits<double>::infinity() << "\n";

#pragma endregion �ε��Ҽ���

#pragma region ������

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

	int iBit_AND = iBitA & iBitB;		// ��ƮAND����
	int iBit_OR = iBitA | iBitB;		// ��ƮOR����
	int iBit_XOR = iBitA ^ iBitB;		// ��ƮXOR����
	int iBit_ShiftPlus = iBitA << 1;	// ��Ʈ���� �������� �� ( 1 -> 2 )
	int iBit_ShiftMinus = iBitA >> 1;	// ��Ʈ���� ���������� �� ( 2 -> 1 )

	/* �����ڴ� �켱������ ���� ���� ������ ������
	* ���� ++, --
	* ���� ++, --, !
	* * , %
	* +, -
	* <<, >>
	* &
	* *
	* |
	* =, +=, -= ���
	*/

#pragma endregion ������

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

#pragma region ���ǹ�

	if (bTrue)
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}

	// if���� �ʱ���
	if (Employee ifEmployee{ tEmployee }; 'A' == ifEmployee.cFirstInitial)
	{
		cout << "ifEmployee.cFirstInitial is A\n";
	}

	// switch�� ������ �� �ִ� ���� ���� �Ǵ� ����Ÿ���̾�� ��
	EnumTest eSwitchEnum{ EnumTest::Two };
	switch (eSwitchEnum)
	{
	case EnumTest::One:

	case EnumTest::Two:
		cout << "eSwitchEnum is EnumTest::Two\n";
		[[fallthrough]];	// �ǵ����� fallthrough�� ��� ����� ��
	case EnumTest::Three:
		break;
	default:
		break;
	}
	/*
	* ǥ������ ���� ���κ��� ǥ������ �پ��� ������� ���� ������ ������ �����ϴµ� ���
	* Break���� ���� ������ ���� Case���� �����Ѵ�(fallthrough).
	*/

	// switch���� �ʱ���
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

	// ���� ������(���� ������)
	int iTurnery{ 10 };
	bool bTunery = (iTurnery > 5) ? true : false;
	if (bTunery) { cout << "iTunery is More Then 5\n"; }

#pragma endregion ���ǹ�

#pragma region ��������

	int iLogical_Left = 0;
	int iLogical_Right = 1;

	// �� ������ ��� �� True�� ��ȯ�Ǹ� �ܶ� ���� �߻��ϸ�, ������ ������ �������� �ʴ´�.

	/* 3���� �� ������ -> �� �۾��� ������ ��ü�� ���ؼ� ����
	* <����, ���� ����>
	* strong_ordering::less		-> left < right
	* strong_ordering::greater	-> left > right
	* strong_ordering;:equal	-> left == right
	* <�Ǽ�, �κ� ����>
	* partical_ordering::less
	* partical_ordering::greater
	* partical_ordering::equivalent
	* partical_ordering::unordered	-> �� �� �ϳ��� ���ڰ� �ƴ�
	* <������, ���� ����>
	* weak_ordering::less
	* weak_ordering::greater
	* weak_ordering::equivalent
	*/


#pragma endregion ��������

#pragma region �Լ� ���

	FuncNameTest();

	cout << Overloading(1, 2) << "\n";
	cout << Overloading(3.1, 0.04) << "\n";

#pragma endregion �Լ� ���

#pragma region Attribute_Definition

	// [[Attribute]] �������� �����

	NoDiscardFunc();		// warning C4834: 'nodiscard' Ư���� ���Ե� �Լ��� ��ȯ ���� ������ ��
	int iNoDiscardReturn = NoDiscardFunc();

	NoDiscardStringFunc();	// warning C4858: ��ȯ ���� �����ϴ� ��: NoDiscard is Activate

	Maybe_unusedFunc(1, 2);

	//	isFeatureLicensed(42);

	//	deprecatedFunc();		// error C4996: 'deprecatedFunc': ������ �ߴܵ� �Լ�


	//	[[likely]], [[unlikely ]] : ���ǹ����� ����� ���ɼ��� ���� �귻ġ�� ���� ��� ����
	int iLikelyTest{ 5 };

	if (10 > iLikelyTest) [[unlikely ]] {/* ���� ������ �ʴ� �κ� */ };

	switch (iLikelyTest)
	{
	[[likely]] case 5:
		/* ���� ���Ǵ� �κ� */
		break;

	default:
		break;
	}

#pragma endregion Attribute_Definition

#pragma region �迭

	// ���� ��Ÿ���� �迭
	int iArrayTest[3]{};
	int iArrayTest_NoIndex[]{ 1,2,3,4 };
	int iArray_NoIndex_Size = size(iArrayTest_NoIndex);

	/*std::array
	* ���� �迭�� ���Ͽ�...
	* 1. �׻� ũ�⸦ ��Ȯ�� �� �� ����
	* 2. ���� ����ȯ�� ���� �ʱ⿡ Ư�� ������ ���׸� ������ �� ����
	* 3. Iterator�� ����Ͽ� �迭�� �ݺ��� ���� ����
	*/
	array<int, 3>	iStdArrayTest{ 11,12,13 };
	array			iStdArray_CTAD{ 21,22,23 };	// Ŭ���� ���ø� �μ� �߷�
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

#pragma endregion �迭

#pragma region Optional

	optional<int> iOptionalResult_True = OptionalFunc(true);
	optional<int> iOptionalResult_False = OptionalFunc(false);

	iOptionalResult_True.has_value();		// 42
	iOptionalResult_False.has_value();		// nullopt;

	iOptionalResult_True.value();			// 42
//	iOptionalResult_False.value();			// ó������ ���� ���� �߻�(0x75B079D2, Professional_C++.exe): Microsoft C++ ����: std::bad_optional_access, �޸� ��ġ 
	iOptionalResult_False.value_or(0);		// nullopt�̸� �Ű����� ��ȯ

#pragma endregion Optional

#pragma region ������ ���ε�

	// ���� ������ �ѹ��� �ʱ�ȭ�ϴ� ���

	// ����ü, �迭 � ��� ���� ���� ���� ������ �ѹ��� �ʱ�ȭ �����ϴ�.
	struct Point { double m_x, m_y, m_z; };
	Point tPoint;
	tPoint.m_x = 1.0; tPoint.m_y = 2.0; tPoint.m_z = 3.0;
	auto [x, y, z] {tPoint};

	// �̴� ���۷����ε� ������ �����ϴ�.
	auto& [xx, yy, zz] {tPoint};

	x;
	y;
	z = 4.0;;

	xx = 4.0;	// �ּҰ��� �����Ͽ� ���� ���� ���浵 ����

#pragma endregion ������ ���ε�

#pragma region �ݺ���

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

	// �ʱ��� Ȱ��
	for (vector<int> vecInit{ 1, 2, 3, 4, 5 }; auto iter : vecInit)
	{
		cout << "vecInit_" << iter << "\t";
	}cout << endl;

#pragma endregion �ݺ���

#pragma region �ʱ��� ����Ʈ

	// Ŭ���� ���ø���
	int iInitListFunc_Result{ InitList_Func({ 10, 20, 30, 40, 50 }) };

#pragma endregion �ʱ��� ����Ʈ

#pragma region string

	string mystring{ "Hello World!" };
	cout << "string is " << mystring << endl;
	cout << "First string is " << mystring[0] << endl;

#pragma endregion string

#pragma region ������ ������

	ScopeClass scClass;

	scClass.Scope_Get();
	Scope_Get();
	ScopeNamespace::Scope_Get();
	::Scope_Get();

#pragma endregion ������ ������

#pragma region ������ �ʱ�ȭ

	Employee Uniform_Employee{ 'U', 'N', 100, 200 };

	int* pArray_Uniform = new int[] { 0, 1, 2, 3 };
	delete[] pArray_Uniform;
	pArray_Uniform = nullptr;

#pragma endregion ������ �ʱ�ȭ

#pragma region �����ʱ���

	/*	�����ʱ��� : ���� Ÿ���� ������ ����� �ʱ�ȭ�ϴµ� ���
	* ���� Ÿ���� ����
	* 1. public ��� �����͸� ����
	* 2. ����� ���� ������ �� ��ӵ� �����ڰ� ����
	* 3. virtual �Լ� ����
	* 4. virtual, private, protected�� ����
	* -> �ش� ������ �����ϴ� �迭 Ÿ���� ��ü, ����ü, Ŭ���� ��ü�� �ǹ���
	*/

	// � �Ϳ� ���� �ʱ�ȭ�� �����ϴ��� ��������� ��Ÿ��
	// �ٵ� ������ ���ѾߵǸ�, ���⿡�� �ʱ�ȭ���� ������ Ŭ���� �� �����ڿ��� �ʱ�ȭ�� ���� ��
	Employee DesignatedEmployee{
		.cFirstInitial = 'D',
		.cLastInitial = 'S',
		.iEmployeeNumber = 100,
		.iSalary = 200
	};

#pragma endregion �����ʱ���

#pragma region ������, ���� �޸�

	/* ��� ����
	* ���� ������ : �Լ��� ȣ��Ǵ� ����, ���� ȣ��Ǵ� �Լ��� ���� �ֻ���� ���� �����ӿ� ����
	* ���ο� �Լ��� ȣ��Ǿ� �ش� �Լ��� �Ű������� �����ϴ� ���, ȣ���ϴ� �Լ��� ���������ӿ��� ���ο� �Լ��� �������������� ���簡 �Ͼ��.
	* ��������� : ������ ����
	*/

	int* iPtr = nullptr;	// ������ null�ʱ�ȭ
	iPtr = new int;			// �޸� �Ҵ�

	*iPtr = 8;				// �� �Ҵ�
	delete iPtr;			// �Ҵ� ����
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

#pragma endregion ������, ���� �޸�

#pragma region const

	const int iConstInt{ 0 };
	//iConstInt{ 12 }; // error C2064: ���� 1���� �μ��� �޾Ƶ��̴� �Լ��� ������ �ʽ��ϴ�.

	/*
	const Ű����� ������ ���� �����Ϸ� �� ��� �����Ϸ��� ������ �߻���Ŵ
	const Ű����� ������ ����� ����ȭ�� �� ȿ�� ���� ����
	define��ũ�κ��� const����� ���� ���� ���� -> define�� �ܼ��� �ؽ�Ʈ ��Ī �۾��� ����������,
	const�� �����Ϸ����� �Ǵ��ϹǷ� ���� ��� Ÿ���̳� ������ ���ǰ� ����
	*/

	// �����Ϳ�����const -> �ٷ� ���ʿ� �ִ� ���� constȭ�Ѵ�!
	// 1. �����Ͱ� ����Ű�� �ִ� ��(���� ���� ��)�� constȭ
	const int* pConstInt_Value_0 = nullptr;
	int const* pconstInt_Value_1 = nullptr;
	// 2. ������ ��ü(�ּҰ�)�� constȭ -> ������ �Ұ��������Ƿ� ����� ���ÿ� �ʱ�ȭ �ʿ�
	int* const pConstInt_Addr{ nullptr };

	string strConstFuncString{ "I'm Const String" };
	int iConstFuncInt{ 10 };
	ConstParmFunc_ptr(&strConstFuncString);
	ConstParmFunc_ref(strConstFuncString);
	ConstParmFunc_Norm(iConstFuncInt);


#pragma endregion const

#pragma region Reference

	// ���۷��� = ������ ���� �ٸ��, ���۷������� ������ ���� �ش� ������ �Ȱ��� ����, ������ ����
	// ���۷����� ����� ������ �� ����.
	int iNonRef{ 10 };
	int& iRef{ iNonRef };
	iRef = 12;

	// const�� �⺻������ const�� ������ ����
	const int& iConstRef{ iNonRef };	// �̷��� �ϸ� �ش� ���۷����� ���� ���� ������ �� ����. ���� ������ ���� ������ ����

	// const ���۷����� ����� �ٷ� �ʱ�ȭ�� �����ϴ� -> ���ó�� ����� ������
	const int& iImdConstRef{ 5 };

	int* iNonRef_ptr{ nullptr };
	int*& iRef_ptr{ iNonRef_ptr };	// �ᱹ �׳� ����ó�� �Ǿ����, ������ ���۷����� ������ ������
	iRef_ptr = new int;
	*iRef_ptr = 6;
	delete iNonRef_ptr;
	iNonRef_ptr = nullptr;

	// ���۷����� �ּҴ� �ش� ���� ���� �ּҿ� ����.
	// int* = &int
	// + ���۷��� Ÿ�Կ� ���� ���۷����� �Ұ����ϴ�!

	/* ����
	* int iPointer; �� ���Ͽ�
	* int* iPointer -> ������, iPointer = �ּҰ�, *iPointer = ��
	* int& iPointer -> ���۷���, iPointer = ��, &iPointer = �ּҰ�
	*/

	/*
	* ���۷��� ���� ����� ��ü�� �������� �ʰ� ���۷����� ���� ������ �߻��ϹǷ� ȿ���� �����Ѵ�.
	* ���� �� ���� ����� �������� �ʴ� Ŭ������ �����ϱ� ������ �ش� ����� �� ȿ�����̴�.
	*/

	/*���۷��� vs ������
	* ���۷����� ���� null�� �� �� ������, ��������� �������ϴ� ������ �Ұ����� -> ���� ����
	* ������ �ݵ�� �����͸� ����ؾ� �ϴ� ��Ȳ?
	* 1. ����Ű�� ��ġ, �� �ּҰ��� �����ؾ� �ϴ� ��Ȳ -> ���۷����� ����Ű�� �ּҸ� �ٲ� �� ����
	* 2. �ּҰ��� nullptr�� �� �� �ִ� ���� �����͸� ����ؾ� �Ѵ�.
	* 3. �����̳ʿ� ������ Ÿ���� ������ �� �����͸� ����ؾ� �Ѵ�.
	*/

	/* �Լ��� �Ű������� �̿��Ͽ� ���� ��ȯ�ϴ� ��ĺ��ٴ� return�� ����Ͽ� ���� ��ȯ�ϴ� ����� ����.
	* ��ȯ���� ���� ����, �Լ��� ���� �Ű�����, �ӽð��� ��� '���ϰ� ����ȭ'(RVO)�� �Ͼ��.
	* ��ȯ���� ���� ������ ��� '�̸� �ִ� ���ϰ� ����ȭ'(NRVO)�� �Ͼ��.
	* �� ���(���� ����)�� �߻��� ��� �����Ϸ��� �����ϴ� ���� �������� �ʴ´� -> ���� ���� �� ���� ���
	*/

#pragma endregion Reference

#pragma region const_cast

	// const_cast<type>(), as_const()�� constŰ���带 ��� �������ִ� ������ �Ѵ�.
	// const�� ���� �� �����ϸ� �ȵ����� �ܺ� ���̺귯���� ����ϴ� �� Ư���� ��쿡 ���

	char* strName = new char[256];
	strcpy_s(strName, 256, "ConstCastTest");

	constcastFunc(const_cast<char*>(strName));
	constcastFunc(as_const(strName));

	delete[] strName;
	strName = nullptr;

#pragma endregion const_cast

#pragma region auto

	auto autoMessage_1{ GetMsg() };				// ���� �߻�
	const auto& autoMessage_2{ GetMsg() };		// ���۷��� �ּ� ����
	// auto ����� const, ���۷����� ���ŵȴ�. ���� ����� ���� ���� �������� ���� �����ؾ� �Ѵ�.
	// �����Ϳ� ���� const�� �����ϱ� ���켭�� auto* �������� �ۼ��ؾ� �Ѵ�.

	int iAutoConstPtr = 1;

	auto* p1{ &iAutoConstPtr };
	const auto p2{ &iAutoConstPtr };	// int* const p2
	auto const p3{ &iAutoConstPtr };	// int* const p3
	const auto* p4{ &iAutoConstPtr };	// const int* p4
	auto* const p5{ &iAutoConstPtr };	// int* const p5

#pragma endregion auto

#pragma region ����/���� ����Ʈ �ʱ�ȭ

	auto copyList_1 = { 1 };
	auto copyList_2 = { 1, 2 };

	auto directList_1{ 1 };
	//auto directList_2{ 1, 2 };

#pragma endregion ����/���� ����Ʈ �ʱ�ȭ

	return 0;
}

