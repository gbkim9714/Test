export module airline_ticket;

import "HeaderUnits.h";
import <string>;

export class AirlineTicket
{
public:
	AirlineTicket() {}	// ������, ��ü ������ �ڵ� ȣ��
	~AirlineTicket() {}	// �Ҹ���, ��ü �Ҹ�� �ڵ� ȣ��

	double calculatePriceindollars()
	{
		if (hasEliteSuperRewardStatus())
			return 0;
		else
			return static_cast<double>(GetNumberOfMiles()) * 0.9;
	}

	std::string GetPassengerName() { return m_strPassengerName; }	// Getter�Լ�
	void SetPassengerName(std::string strPassengerName) { m_strPassengerName = strPassengerName; }	// Setter�Լ�

	int GetNumberOfMiles() { return m_iNumberOfMiles; }
	void SetNumberOfMiles(int iMiles) { m_iNumberOfMiles = iMiles; }

	bool hasEliteSuperRewardStatus() { return m_bHasEliteSuperRewardStatus; }
	void SetEliteSuperRewardStatus(bool bStatus) { m_bHasEliteSuperRewardStatus = bStatus; }

private:
	std::string m_strPassengerName{};
	int m_iNumberOfMiles{};
	bool m_bHasEliteSuperRewardStatus{ false };
	
};