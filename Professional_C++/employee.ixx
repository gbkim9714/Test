// 모듈 인터페이스 파일 .ixx

export module employee;		// 모듈 선언문, 해당 모듈을 정의한다는 의미, 모듈은 명시적으로 export해야함
import <string>;
namespace Records
{
	const int DefaultStartingSalary{ 30000 };						// 기본 급여
	export const int DefaultRaiseAndDemeritAmount{ 1000 };			// 급여 인상액

	export class Employee
	{
	public:
		Employee(const std::string& firstname, const std::string& lastname);

		void promote(int raiseAmount = Records::DefaultRaiseAndDemeritAmount);
		void demote(int demeritMount = Records::DefaultRaiseAndDemeritAmount);
		void hire();
		void fire();
		void display() const;

		void setFirstName(const std::string& firstname);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastname);
		const std::string& getLastName() const;

		void setEmployeeNumber(int employeeNum);
		int getEmployeeNumber() const;

		void setSalary(int newSalary);
		int getSalary() const;

		bool isHired() const;

	private:
		std::string m_FirstName;
		std::string m_LastName;
		int m_employeeNumber{ -1 };
		int m_Salary{ Records::DefaultStartingSalary };
		bool m_Hired{ false };
	};

}


export void MyFunc() {}

export struct Employee
{
	// 구조체 내의 값을 필드라고 하며, 필드에 접근 시에는 Employee.iSalary 같은 방식으로 접근한다.

	char cFirstInitial;
	char cLastInitial;
	int iEmployeeNumber;
	int iSalary;
};