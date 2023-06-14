// ��� �������̽� ���� .ixx

export module employee;		// ��� ����, �ش� ����� �����Ѵٴ� �ǹ�, ����� ��������� export�ؾ���
import <string>;
namespace Records
{
	const int DefaultStartingSalary{ 30000 };						// �⺻ �޿�
	export const int DefaultRaiseAndDemeritAmount{ 1000 };			// �޿� �λ��

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
	// ����ü ���� ���� �ʵ��� �ϸ�, �ʵ忡 ���� �ÿ��� Employee.iSalary ���� ������� �����Ѵ�.

	char cFirstInitial;
	char cLastInitial;
	int iEmployeeNumber;
	int iSalary;
};