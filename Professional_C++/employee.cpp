module employee;
import <iostream>;
using namespace std;

namespace Records
{
	Employee::Employee(const string& firstname, const string& lastname)
		:m_FirstName{ firstname }, m_LastName{ lastname }{}

	void Employee::promote(int raiseAmount)
	{
		setSalary(getSalary() + raiseAmount);
	}

	void Employee::demote(int demeritMount)
	{
		setSalary(getSalary() - demeritMount);
	}

	void Employee::hire() { m_Hired = true; }
	void Employee::fire() { m_Hired = false; }

	void Employee::display() const
	{
		cout << "Employee : " << getLastName() << getFirstName() << endl;
		cout << "------------------------------------------" << endl;
		cout << (isHired() ? "Current Employee" : "Former Employee") << endl;
		cout << "Employee Number : " << getEmployeeNumber() << endl;
		cout << "Salary : " << getSalary() << endl;
		cout << endl;
	}

	void Employee::setFirstName(const std::string& firstname)
	{
		m_FirstName = firstname;
	}
	const string& Employee::getFirstName() const
	{
		return m_FirstName;
	}

	void Employee::setLastName(const std::string& lastname)
	{
		m_LastName = lastname;
	}
	const string& Employee::getLastName() const
	{
		return m_LastName;
	}

	void Employee::setEmployeeNumber(int employeeNum)
	{
		m_employeeNumber = employeeNum;
	}
	int Employee::getEmployeeNumber() const
	{
		return m_employeeNumber;
	}

	void Employee::setSalary(int newSalary) 
	{
		m_Salary = newSalary;
	}
	int Employee::getSalary() const
	{
		return m_Salary;
	}

	bool Employee::isHired() const
	{
		return m_Hired;
	}
}