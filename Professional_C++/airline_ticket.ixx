export module airline_ticket;

import "HeaderUnits.h";
import <string>;

export class AirlineTicket
{
public:
	AirlineTicket() {}	// 생성자, 객체 생성시 자동 호출
	~AirlineTicket() {}	// 소멸자, 객체 소멸시 자동 호출

	double calculatePriceindollars()
	{
		if (hasEliteSuperRewardStatus())
			return 0;
		else
			return static_cast<double>(GetNumberOfMiles()) * 0.9;
	}

	std::string GetPassengerName() { return m_strPassengerName; }	// Getter함수
	void SetPassengerName(std::string strPassengerName) { m_strPassengerName = strPassengerName; }	// Setter함수

	int GetNumberOfMiles() { return m_iNumberOfMiles; }
	void SetNumberOfMiles(int iMiles) { m_iNumberOfMiles = iMiles; }

	bool hasEliteSuperRewardStatus() { return m_bHasEliteSuperRewardStatus; }
	void SetEliteSuperRewardStatus(bool bStatus) { m_bHasEliteSuperRewardStatus = bStatus; }

private:
	std::string m_strPassengerName{};
	int m_iNumberOfMiles{};
	bool m_bHasEliteSuperRewardStatus{ false };
	
};